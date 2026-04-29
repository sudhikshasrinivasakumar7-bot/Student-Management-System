#  Student Management System (C++)

A console-based Student Management System developed in C++ using file handling to manage student records efficiently.

##  Features

* Add new student records
*  Display all students
*  Search student by ID
*  Update student details
*  Delete student record
* Persistent storage using file handling

---

##  Technologies Used

* C++
* File Handling (`fstream`)
* Object-Oriented Programming (OOP)

---

##  File Structure

```
Student-Management-System/
│── main.cpp
│── students.dat
│── README.md
```

---

##  How to Run

### Step 1: Compile

```bash
g++ main.cpp -o sms
```

### Step 2: Execute

```bash
./sms
```

---

##  Sample Input & Output

###  Menu

```
===== Student Management System =====
1. Add Student
2. Display All Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit
Enter choice: 1
```

###  Add Student

```
Enter ID: 101
Enter Name: Rahul
Enter Age: 20
Enter Course: CSE
Student added successfully!
```

###  Display Students

```
ID: 101
Name: Rahul
Age: 20
Course: CSE
----------------------
```

###  Search Student

```
Enter ID to search: 101

ID: 101
Name: Rahul
Age: 20
Course: CSE
```

###  Update Student

```
Enter ID to update: 101
Enter new details:
Enter ID: 101
Enter Name: Rahul Kumar
Enter Age: 21
Enter Course: IT
```

###  Delete Student

```
Enter ID to delete: 101
Student deleted successfully!
```

---

##  Expected Output

A fully functional system that allows users to:

* Manage student records
* Store data permanently
* Perform CRUD operations efficiently

---

##  Future Improvements

* Add validation for inputs
* Convert to GUI application
* Use database (MySQL) instead of file handling
* Add login/authentication system

---

##  Author

Developed as part of internship project at **Thiranex**.
