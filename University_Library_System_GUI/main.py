import tkinter as tk
from tkinter import ttk
import json
import subprocess
import threading
import ctypes

# Define Custom_String_Class structure
class Custom_String_Class(ctypes.Structure):
    _fields_ = [("str", ctypes.c_char_p)]

# Define the function prototype for executeGUIOption
executeGUIOption = None  # Placeholder for the function pointer

# Load the DLL
lib = ctypes.CDLL(r'D:\engineering\Year2\semester 2\oop\project_oop\University_Library_System\University_Library_System_GUI\libproject.dll')

# Define the argument and return types for executeGUIOption
lib.executeGUIOption.argtypes = [ctypes.POINTER(Custom_String_Class), ctypes.c_size_t]
lib.executeGUIOption.restype = ctypes.POINTER(Custom_String_Class)

# Define a helper function to convert Python list of strings to Custom_String_Class array
def list_to_custom_string_array(lst):
    custom_strings = (Custom_String_Class * len(lst))()
    for i, s in enumerate(lst):
        custom_strings[i].str = s.encode('utf-8')  # Assuming strings are UTF-8 encoded
    return custom_strings

# Define a helper function to convert Custom_String_Class array to Python list of strings
def custom_string_array_to_list(array, length):
    return [array[i].str.decode('utf-8') for i in range(length)]



# Define Custom_String_Class structure for ctypes
class Custom_String_Class(ctypes.Structure):
    _fields_ = [("str", ctypes.c_char_p)]

class LibraryApp:
    def __init__(self, root):
        self.root = root
        self.login_window()

        # Load the C++ library
        self.library = ctypes.CDLL("library.dll")  # Update with your library name

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
        # Load the list of librarian IDs from the JSON file
        with open("members.json", "r") as file:
            members = json.load(file)

        # Get the entered ID
        entered_id = int(self.id_entry.get())

        # Check if the entered ID belongs to a librarian
        is_librarian = any(member["ID"] == entered_id and member["Type"] == "Librarian" for member in members)

        if is_librarian:
            self.show_librarian_interface()
        else:
            self.show_member_interface()

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
        self.member_tab = ttk.Frame(self.tabControl)
        self.tabControl.add(self.member_tab, text="Member")

        self.tabControl.pack(expand=1, fill="both")

        self.request_book_button = tk.Button(self.member_tab, text="Request Book", command=self.request_book)
        self.request_book_button.pack(padx=20, pady=20)

    def create_librarian_tab(self):
        self.librarian_tab = ttk.Frame(self.tabControl)
        self.tabControl.add(self.librarian_tab, text="Librarian")

        self.tabControl.pack(expand=1, fill="both")

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
        # Convert Python list of strings to Custom_String_Class array
        options_array = (Custom_String_Class * len(options))()
        options_array[:] = [Custom_String_Class(ctypes.c_char_p(option.encode())) for option in options]

        # Call the C++ function
        self.library.executeGUIOption.argtypes = [ctypes.POINTER(Custom_String_Class), ctypes.c_size_t]
        self.library.executeGUIOption.restype = ctypes.POINTER(Custom_String_Class)
        response_array = self.library.executeGUIOption(options_array, len(options))

        # Convert the response array to a list of strings
        response = [response_array[i].str.decode() for i in range(len(options))]

        return response

    def add_book(self):
        title = self.title_entry.get()
        isbn = self.isbn_entry.get()
        author = self.author_entry.get()
        genre = self.genre_entry.get()
        pub_year = self.pub_year_entry.get()
        quantity = self.quantity_entry.get()

        # Call the C++ function with appropriate options
        response = self.execute_cpp_function([title, isbn, author, genre, pub_year, quantity])

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
