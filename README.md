# Library Management System in C++

##  Overview
This project is a simple **Library Management System** implemented in C++.  
It allows adding books and members, issuing books, returning books, and calculating fines for late returns.  
The system uses unordered_map for fast lookups and maintains issue records with timestamps.

---

##  Features
- **Add Books** → Store book details (ID, name, price, copies).
- **Add Members** → Register library members with ID, name, and phone number.
- **Issue Books** → Issue a book to a member if available.
- **Return Books** → Return a book, calculate days kept, and apply fines if overdue.
- **Fine Calculation** → ₹1 per day after 45 days.

---

## 🧩 Data Structures
- **Member** → Holds member ID, name, and phone number.
- **Book** → Holds book ID, name, price, total copies, and available copies.
- **issueRecord** → Tracks issued books with member ID, book ID, and issue time.
- **Library Class** → Manages members, books, and issue records.

---

## 📊 Example Run
```text
Good morning!
Welcome to the Shivang's Library:

Choose from the options:
1. Add Books
2. Add Members
3. Issue Books
4. Return Books
5. Exit

Enter choice: 1
Enter name of book: CppBasics
Enter price of book: 500
Enter available copies: 3
Book added successfully
Book_id= 1

Enter choice: 2
Enter name: Devang
Enter phone number: 9876543210
Member added successfully
Member_id= 1

Enter choice: 3
Enter Member id: 1
Enter the book Id: 1
Book issued successfully

Enter choice: 4
Enter Member id: 1
Enter book id: 1
Book kept for 10 days
Book returned successfully
