import tkinter as tk
from tkinter import ttk
import ctypes


# Define the function prototype for executeGUIOption
#executeGUIOption = None  # Placeholder for the function pointer

# Load the DLL
lib = ctypes.CDLL(r"D:\engineering\Year2\semester 2\oop\project_oop\University_Library_System\University_Library_System_GUI\Project3.dll")

# Define the function prototype for executeGUIOption
executeGUIOption = lib.executeGUIOption
executeGUIOption.argtypes = [ctypes.POINTER(ctypes.c_char_p), ctypes.c_size_t]
executeGUIOption.restype = ctypes.POINTER(ctypes.c_char_p)

# Define a helper function to convert Python list of strings to array of c_char_p
def list_to_c_char_p_array(lst):
    return (ctypes.c_char_p * len(lst))(*lst)

# Define a helper function to convert the returned array to a Python list of strings
def c_char_p_array_to_list(array, length):
    return [array[i].decode() for i in range(length)]

class LibraryApp:
    def __init__(self, root):
        self.root = root
        self.login_window()

    def login_window(self):
        self.login_window = tk.Toplevel(self.root)
        self.login_window.title("Login")
        self.login_window.geometry("300x150")

        self.id_label = tk.Label(self.login_window, text="ID:")
        self.id_label.grid(row=0, column=0, padx=5, pady=5)
        self.id_entry = tk.Entry(self.login_window)
        self.id_entry.grid(row=0, column=1, padx=5, pady=5)

        self.login_button = tk.Button(self.login_window, text="Login", command=self.authenticate)
        self.login_button.grid(row=1, columnspan=2, pady=10)

    def authenticate(self):
        # Get the entered ID
        entered_id = self.id_entry.get()

        # Example usage
        options = ["1", entered_id ]  # Example options

        # Convert Python list of strings to array of c_char_p
        options_array = list_to_c_char_p_array(options)

        # Call the executeGUIOption function
        response_array = executeGUIOption(options_array, len(options))

        # Convert the returned array to a Python list of strings
        response = c_char_p_array_to_list(response_array, len(options))

        if response[0] == "librarian":
            self.show_librarian_interface()
        else:
            self.show_member_interface()

        # Free the memory allocated for the returned array
        lib.free(response_array)

        self.login_window.destroy()

    def show_member_interface(self):
        self.root.title("Library Management System - Member")
        self.tabControl = ttk.Notebook(self.root)

        self.member_tab = ttk.Frame(self.tabControl)
        self.tabControl.add(self.member_tab, text="Member")

        self.tabControl.pack(expand=1, fill="both")

        self.create_member_tab()

    def show_librarian_interface(self):
        self.root.title("Library Management System - Librarian")
        self.tabControl = ttk.Notebook(self.root)

        self.librarian_tab = ttk.Frame(self.tabControl)
        self.tabControl.add(self.librarian_tab, text="Librarian")

        self.tabControl.pack(expand=1, fill="both")

        self.create_librarian_tab()

    def create_member_tab(self):
        self.request_book_button = tk.Button(self.member_tab, text="Request Book", command=self.request_book)
        self.request_book_button.pack(padx=20, pady=20)

    def create_librarian_tab(self):
        self.add_book_button = tk.Button(self.librarian_tab, text="Add Book", command=self.add_book)
        self.add_book_button.grid(row=0, column=0, padx=10, pady=10)

        self.remove_book_button = tk.Button(self.librarian_tab, text="Remove Book", command=self.remove_book)
        self.remove_book_button.grid(row=0, column=1, padx=10, pady=10)

        self.register_member_button = tk.Button(self.librarian_tab, text="Register New Member",
                                                command=self.open_register_member_window)
        self.register_member_button.grid(row=1, column=0, padx=10, pady=10)

        self.remove_member_button = tk.Button(self.librarian_tab, text="Remove Member",
                                              command=self.open_remove_member_window)
        self.remove_member_button.grid(row=1, column=1, padx=10, pady=10)

    def execute_cpp_function(self, options):
        # Convert Python list of strings to array of c_char_p
        options_array = list_to_c_char_p_array(options)

        # Call the C++ function
        response_array = executeGUIOption(options_array, len(options))

        # Convert the response array to a Python list of strings
        response = c_char_p_array_to_list(response_array, len(options))

        return response

    def add_book(self):
        title = self.title_entry.get()
        isbn = self.isbn_entry.get()
        author = self.author_entry.get()
        genre = self.genre_entry.get()
        pub_year = self.pub_year_entry.get()
        quantity = self.quantity_entry.get()

        # Call the C++ function with appropriate options
        response = self.execute_cpp_function(["2", title, isbn, author, genre, pub_year, quantity])

        # Process the response
        print("Response from C++ function:", response)

        # Clear entry fields
        self.title_entry.delete(0, tk.END)
        self.isbn_entry.delete(0, tk.END)
        self.author_entry.delete(0, tk.END)
        self.genre_entry.delete(0, tk.END)
        self.pub_year_entry.delete(0, tk.END)
        self.quantity_entry.delete(0, tk.END)

    # Define other methods to interact with C++ function as needed

# Create and run the tkinter application
if __name__ == "__main__":
    root = tk.Tk()
    app = LibraryApp(root)
    root.mainloop()
