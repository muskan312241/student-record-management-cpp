#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int roll;
    string name;
    float marks;

    void input() {
        cout << "Enter Roll Number: ";
        cin >> roll;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "Roll: " << roll 
             << " Name: " << name 
             << " Marks: " << marks << endl;
    }
};

void addStudent() {
    Student s;
    ofstream file("students.txt", ios::app);

    s.input();
    file << s.roll << " " << s.name << " " << s.marks << endl;

    file.close();
    cout << "Student Record Added Successfully!\n";
}

void displayStudents() {
    ifstream file("students.txt");
    Student s;

    while (file >> s.roll >> s.name >> s.marks) {
        s.display();
    }

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Exit\n";
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
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}