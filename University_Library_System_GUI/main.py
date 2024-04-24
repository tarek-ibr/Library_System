import tkinter as tk
from tkinter import ttk
import json
import subprocess
import threading


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
        self.search_books_frame = ttk.LabelFrame(self.member_tab, text="Search Books")
        self.search_books_frame.grid(row=0, column=0, padx=10, pady=5, sticky="w")
        self.create_search_books_frame()

        self.request_loan_frame = ttk.LabelFrame(self.member_tab, text="Request Loan")
        self.request_loan_frame.grid(row=1, column=0, padx=10, pady=5, sticky="w")
        self.create_request_loan_frame()

        self.return_loan_frame = ttk.LabelFrame(self.member_tab, text="Return Loan")
        self.return_loan_frame.grid(row=2, column=0, padx=10, pady=5, sticky="w")
        self.create_return_loan_frame()

        self.check_due_dates_frame = ttk.LabelFrame(self.member_tab, text="Check Due Dates")
        self.check_due_dates_frame.grid(row=3, column=0, padx=10, pady=5, sticky="w")
        self.create_check_due_dates_frame()

        self.manage_account_frame = ttk.LabelFrame(self.member_tab, text="Manage Account")
        self.manage_account_frame.grid(row=4, column=0, padx=10, pady=5, sticky="w")
        self.create_manage_account_frame()

    def create_search_books_frame(self):
        self.search_entry = tk.Entry(self.search_books_frame)
        self.search_entry.grid(row=0, column=0, padx=5, pady=5)
        self.search_button = tk.Button(self.search_books_frame, text="Search", command=self.search_books)
        self.search_button.grid(row=0, column=1, padx=5, pady=5)

    def create_request_loan_frame(self):
        self.request_isbn_entry = tk.Entry(self.request_loan_frame)
        self.request_isbn_entry.grid(row=0, column=0, padx=5, pady=5)
        self.request_loan_button = tk.Button(self.request_loan_frame, text="Request Loan", command=self.request_loan)
        self.request_loan_button.grid(row=0, column=1, padx=5, pady=5)

    def create_return_loan_frame(self):
        self.return_isbn_entry = tk.Entry(self.return_loan_frame)
        self.return_isbn_entry.grid(row=0, column=0, padx=5, pady=5)
        self.return_loan_button = tk.Button(self.return_loan_frame, text="Return Loan", command=self.return_loan)
        self.return_loan_button.grid(row=0, column=1, padx=5, pady=5)

    def create_check_due_dates_frame(self):
        self.check_due_dates_button = tk.Button(self.check_due_dates_frame, text="Check Due Dates",
                                                command=self.check_due_dates)
        self.check_due_dates_button.grid(row=0, column=0, padx=5, pady=5)

    def create_manage_account_frame(self):
        self.manage_account_button = tk.Button(self.manage_account_frame, text="Manage Account",
                                               command=self.manage_account)
        self.manage_account_button.grid(row=0, column=0, padx=5, pady=5)

    def search_books(self):
        search_query = self.search_entry.get()
        print("Searching books for:", search_query)

    def request_loan(self):
        isbn = self.request_isbn_entry.get()
        print("Requesting loan for book with ISBN:", isbn)

    def return_loan(self):
        isbn = self.return_isbn_entry.get()
        print("Returning loan for book with ISBN:", isbn)

    def check_due_dates(self):
        print("Checking due dates")

    def manage_account(self):
        print("Managing account")

    def create_librarian_tab(self):
        add_book_frame = ttk.LabelFrame(self.librarian_tab, text="Add Book")
        add_book_frame.grid(row=0, column=0, padx=20, pady=20, sticky="w")

        self.title_label = tk.Label(add_book_frame, text="Title:")
        self.title_label.grid(row=0, column=0, sticky="w")
        self.title_entry = tk.Entry(add_book_frame)
        self.title_entry.grid(row=0, column=1, padx=5, pady=5)

        self.isbn_label = tk.Label(add_book_frame, text="ISBN:")
        self.isbn_label.grid(row=1, column=0, sticky="w")
        self.isbn_entry = tk.Entry(add_book_frame)
        self.isbn_entry.grid(row=1, column=1, padx=5, pady=5)

        self.author_label = tk.Label(add_book_frame, text="Author:")
        self.author_label.grid(row=2, column=0, sticky="w")
        self.author_entry = tk.Entry(add_book_frame)
        self.author_entry.grid(row=2, column=1, padx=5, pady=5)

        self.genre_label = tk.Label(add_book_frame, text="Genre:")
        self.genre_label.grid(row=3, column=0, sticky="w")
        self.genre_entry = tk.Entry(add_book_frame)
        self.genre_entry.grid(row=3, column=1, padx=5, pady=5)

        self.pub_year_label = tk.Label(add_book_frame, text="Publication Year:")
        self.pub_year_label.grid(row=4, column=0, sticky="w")
        self.pub_year_entry = tk.Entry(add_book_frame)
        self.pub_year_entry.grid(row=4, column=1, padx=5, pady=5)

        self.quantity_label = tk.Label(add_book_frame, text="Quantity:")
        self.quantity_label.grid(row=5, column=0, sticky="w")
        self.quantity_entry = tk.Entry(add_book_frame)
        self.quantity_entry.grid(row=5, column=1, padx=5, pady=5)

        self.add_book_button = tk.Button(add_book_frame, text="Add Book", command=self.add_book)
        self.add_book_button.grid(row=6, columnspan=2, pady=10)

        edit_book_frame = ttk.LabelFrame(self.librarian_tab, text="Edit Book")
        edit_book_frame.grid(row=0, column=1, padx=20, pady=20, sticky="w")

        self.edit_isbn_label = tk.Label(edit_book_frame, text="ISBN:")
        self.edit_isbn_label.grid(row=0, column=0, sticky="w")
        self.edit_isbn_entry = tk.Entry(edit_book_frame)
        self.edit_isbn_entry.grid(row=0, column=1, padx=5, pady=5)

        self.edit_title_label = tk.Label(edit_book_frame, text="Title:")
        self.edit_title_label.grid(row=1, column=0, sticky="w")
        self.edit_title_entry = tk.Entry(edit_book_frame)
        self.edit_title_entry.grid(row=1, column=1, padx=5, pady=5)

        self.edit_book_button = tk.Button(edit_book_frame, text="Edit Book", command=self.edit_book)
        self.edit_book_button.grid(row=2, columnspan=2, pady=10)

        remove_book_frame = ttk.LabelFrame(self.librarian_tab, text="Remove Book")
        remove_book_frame.grid(row=1, column=0, padx=20, pady=20, sticky="w")

        self.remove_isbn_label = tk.Label(remove_book_frame, text="ISBN:")
        self.remove_isbn_label.grid(row=0, column=0, sticky="w")
        self.remove_isbn_entry = tk.Entry(remove_book_frame)
        self.remove_isbn_entry.grid(row=0, column=1, padx=5, pady=5)

        self.remove_book_button = tk.Button(remove_book_frame, text="Remove Book", command=self.remove_book)
        self.remove_book_button.grid(row=1, columnspan=2, pady=10)

        self.manage_members_button = tk.Button(self.librarian_tab, text="Manage Members",
                                               command=self.open_manage_members_window)
        self.manage_members_button.grid(row=2, column=0, columnspan=2, pady=10)

    def add_book(self):
        title = self.title_entry.get()
        isbn = self.isbn_entry.get()
        author = self.author_entry.get()
        genre = self.genre_entry.get()
        pub_year = self.pub_year_entry.get()
        quantity = self.quantity_entry.get()

        subprocess.run(["./main.exe", title, isbn, author, genre, pub_year, quantity], shell=True)

        print("Adding Book:")
        print("Title:", title)
        print("ISBN:", isbn)
        print("Author:", author)
        print("Genre:", genre)
        print("Publication Year:", pub_year)
        print("Quantity:", quantity)

        self.title_entry.delete(0, tk.END)
        self.isbn_entry.delete(0, tk.END)
        self.author_entry.delete(0, tk.END)
        self.genre_entry.delete(0, tk.END)
        self.pub_year_entry.delete(0, tk.END)
        self.quantity_entry.delete(0, tk.END)

    def edit_book(self):
        isbn = self.edit_isbn_entry.get()
        title = self.edit_title_entry.get()

        print("Editing Book:")
        print("ISBN:", isbn)
        print("Title:", title)

        self.edit_isbn_entry.delete(0, tk.END)
        self.edit_title_entry.delete(0, tk.END)

    def remove_book(self):
        isbn = self.remove_isbn_entry.get()

        print("Removing Book:")
        print("ISBN:", isbn)

        self.remove_isbn_entry.delete(0, tk.END)

    def open_register_member_window(self):
        register_member_window = tk.Toplevel(self.root)
        register_member_window.title("Register New Member")
        register_member_window.geometry("400x200")

        input_frame = ttk.LabelFrame(register_member_window, text="Register New Member")
        input_frame.pack(padx=20, pady=20, fill=tk.BOTH, expand=True)

        self.name_label = tk.Label(input_frame, text="Name:")
        self.name_label.grid(row=0, column=0, sticky="w")

        self.name_entry = tk.Entry(input_frame)
        self.name_entry.grid(row=0, column=1, padx=5, pady=5)

        self.id_label = tk.Label(input_frame, text="ID:")
        self.id_label.grid(row=1, column=0, sticky="w")

        self.id_entry = tk.Entry(input_frame)
        self.id_entry.grid(row=1, column=1, padx=5, pady=5)

        self.type_label = tk.Label(input_frame, text="Type:")
        self.type_label.grid(row=2, column=0, sticky="w")

        self.type_entry = tk.Entry(input_frame)
        self.type_entry.grid(row=2, column=1, padx=5, pady=5)

        self.register_member_button = tk.Button(input_frame, text="Register Member", command=self.register_member)
        self.register_member_button.grid(row=3, columnspan=2, pady=10)

    def open_remove_member_window(self):
        remove_member_window = tk.Toplevel(self.root)
        remove_member_window.title("Remove Member")
        remove_member_window.geometry("300x150")

        input_frame = ttk.LabelFrame(remove_member_window, text="Remove Member")
        input_frame.pack(padx=20, pady=20, fill=tk.BOTH, expand=True)

        self.id_to_remove_label = tk.Label(input_frame, text="Member ID to remove:")
        self.id_to_remove_label.grid(row=0, column=0, sticky="w")

        self.id_to_remove_entry = tk.Entry(input_frame)
        self.id_to_remove_entry.grid(row=0, column=1, padx=5, pady=5)

        self.remove_member_button = tk.Button(input_frame, text="Remove Member", command=self.remove_member)
        self.remove_member_button.grid(row=1, columnspan=2, pady=10)

    def register_member(self):
        name = self.name_entry.get()
        id = self.id_entry.get()
        type = self.type_entry.get()

        print("Registering New Member:")
        print("Name:", name)
        print("ID:", id)
        print("Type:", type)

        self.name_entry.delete(0, tk.END)
        self.id_entry.delete(0, tk.END)
        self.type_entry.delete(0, tk.END)

    def remove_member(self):
        id_to_remove = self.id_to_remove_entry.get()

        print("Removing Member:")
        print("Member ID to remove:", id_to_remove)

        self.id_to_remove_entry.delete(0, tk.END)

    def open_manage_members_window(self):
        manage_members_window = tk.Toplevel(self.root)
        manage_members_window.title("Manage Members")
        manage_members_window.geometry("600x400")

        input_frame = ttk.LabelFrame(manage_members_window, text="Manage Members")
        input_frame.pack(padx=20, pady=20, fill=tk.BOTH, expand=True)

        self.choice_label = tk.Label(input_frame, text="Enter your choice:")
        self.choice_label.grid(row=0, column=0, sticky="w")

        self.choice_entry = tk.Entry(input_frame)
        self.choice_entry.grid(row=0, column=1, padx=5, pady=5)

        self.instructions_label = tk.Label(input_frame,
                                           text="1: Register new member\n2: Remove member\n3: Display all members\n0: Exit")
        self.instructions_label.grid(row=1, column=0, columnspan=2, pady=(10, 0), sticky="w")

        output_frame = ttk.LabelFrame(manage_members_window, text="Member List")
        output_frame.pack(padx=20, pady=20, fill=tk.BOTH, expand=True)

        self.output_text = tk.Text(output_frame, height=10, width=50)
        self.output_text.grid(row=0, column=0, padx=5, pady=5)

        self.manage_members_button = tk.Button(input_frame, text="Submit", command=self.process_member_operation)
        self.manage_members_button.grid(row=2, columnspan=2, pady=10)

    def process_member_operation(self):
        choice = self.choice_entry.get()

        if choice == "1":
            self.open_register_member_window()
        elif choice == "2":
            self.open_remove_member_window()
        elif choice == "3":
            pass
        elif choice == "0":
            pass
        else:
            tk.messagebox.showerror("Error", "Invalid choice. Please enter a valid option.")


if __name__ == "__main__":
    root = tk.Tk()
    app = LibraryApp(root)
    root.mainloop()
