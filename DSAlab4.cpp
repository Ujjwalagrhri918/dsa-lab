#include <iostream>
using namespace std;

// Structure to represent a student node in the linked list
struct node {
    string name;     // Student's name
    int regNo;       // Registration number
    node* next;      // Pointer to the next student node
};

// Class representing a Linked List of students
class Linkedlist {
private:
    node* head;       // Pointer to the first student node in the list

public:
    // Constructor to initialize an empty linked list
    Linkedlist() {
        head = NULL;
    }

    // Method to insert a new student into the linked list
    void insertStudent(int regNo, string name) {
        // Creating a new student node
        node* newStudent = new node;
        newStudent->name = name;
        newStudent->regNo = regNo;
        newStudent->next = NULL;

        if (!head || regNo < head->regNo) {
            newStudent->next = head;
            head = newStudent;
        } else {
            node* current = head;
            while (current->next && regNo > current->next->regNo) {
                current = current->next;
            }
            newStudent->next = current->next;
            current->next = newStudent;
        }
    }

    // Method to delete a student from the linked list based on regNo
    void deleteStudent(int regNo) {
        if (!head) {
            cout << "Empty list" << endl;
        }

        if (regNo == head->regNo) {
            node* temp = head;
            head = head->next;
            delete temp;
        } else {
            node* current = head;
            while (current->next && regNo != current->next->regNo) {
                current = current->next;
            }
            if (current->next) {
                node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                cout << "Student with register number " << regNo << " not found." << endl;
            }
        }
    }

    // Method to display the list of students
    void displayList() {
        cout << "_______The list of Students is:________" << endl;
        node* current = head;
        while (current) {
            cout << "Reg No: " << current->regNo << " Name: " << current->name << endl;
            current = current->next;
        }
    }
};

// Main function
int main() {
    // Creating an instance of Linkedlist
    Linkedlist student;

    // Inserting students into the linked list
    
    student.insertStudent(2074, "Utsav Jaiswal");
    student.insertStudent(2073, "Bijendra Yadav");
    student.insertStudent(2075, "Ujjwal Agrahari");
    student.insertStudent(2077, "Madan Raj");

    // Displaying the list of students
    student.displayList();

    // Deleting students from the list
    student.deleteStudent(2073);
    student.deleteStudent(2074);

    // Displaying the list after deletions
    student.displayList();

    // Deleting a student who is not in the list
    student.deleteStudent(2076);

    return 0;
}