#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Student {
public:
    int id;
    char name[50];
    int age;
    char course[50];

    void input() {
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Name: ";
        cin.getline(name, 50);
        cout << "Enter Age: ";
        cin >> age;
        cin.ignore();
        cout << "Enter Course: ";
        cin.getline(course, 50);
    }

    void display() {
        cout << "\nID: " << id;
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nCourse: " << course << endl;
    }
};


void addStudent() {
    Student s;
    ofstream file("students.dat", ios::binary | ios::app);

    s.input();
    file.write((char*)&s, sizeof(s));

    file.close();
    cout << "Student added successfully!\n";
}


void displayStudents() {
    Student s;
    ifstream file("students.dat", ios::binary);

    if (!file) {
        cout << "No records found!\n";
        return;
    }

    while (file.read((char*)&s, sizeof(s))) {
        s.display();
        cout << "----------------------";
    }

    file.close();
}


void searchStudent(int id) {
    Student s;
    ifstream file("students.dat", ios::binary);
    bool found = false;

    while (file.read((char*)&s, sizeof(s))) {
        if (s.id == id) {
            s.display();
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Student not found!\n";

    file.close();
}


void updateStudent(int id) {
    Student s;
    fstream file("students.dat", ios::binary | ios::in | ios::out);
    bool found = false;

    while (file.read((char*)&s, sizeof(s))) {
        if (s.id == id) {
            cout << "Enter new details:\n";
            s.input();

            file.seekp(-sizeof(s), ios::cur);
            file.write((char*)&s, sizeof(s));
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Student not found!\n";

    file.close();
}

void deleteStudent(int id) {
    Student s;
    ifstream file("students.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);
    bool found = false;

    while (file.read((char*)&s, sizeof(s))) {
        if (s.id != id) {
            temp.write((char*)&s, sizeof(s));
        } else {
            found = true;
        }
    }

    file.close();
    temp.close();

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        cout << "Student deleted successfully!\n";
    else
        cout << "Student not found!\n";
}

int main() {
    int choice, id;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                cout << "Enter ID to search: ";
                cin >> id;
                searchStudent(id);
                break;
            case 4:
                cout << "Enter ID to update: ";
                cin >> id;
                updateStudent(id);
                break;
            case 5:
                cout << "Enter ID to delete: ";
                cin >> id;
                deleteStudent(id);
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
