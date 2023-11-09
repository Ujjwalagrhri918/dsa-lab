/*
Program to calculate the Grade of multiple students
Author: Ujjwal Agrahari (RA2211003012075)
*/
#include <iostream>
#include<string>
using namespace std;
// a structure to represent a student 
struct Student {
    string name;
    int rollNo, sub1, sub2, sub3;
    float avg_marks;
};
// Function to get details (name, roll number, marks) of 'n' students
void getDetails(struct Student *bptr, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Enter the name of student " << i + 1 << ": " << endl;
        cin.ignore(); // Ignore any remaining characters from the previous input
        getline(cin, (bptr + i)->name); //  getline() to read the whole line as the name
        cout << "Enter his Roll no:" << endl;
        cin >> (bptr + i)->rollNo;//Read the Roll no
        cout << "Enter his marks in subject 1 :" << endl;
        cin >> (bptr + i)->sub1;//Reads the mark for subject1
        cout << "Enter his marks in subject 2 :" << endl;
        cin >> (bptr + i)->sub2;//Reads the mark for subject2
        cout << "Enter his marks in subject 3 :" << endl;
        cin >> (bptr + i)->sub3;//Reads the mark for subject3
    }
}
// Function to calculate the average marks of 'n' students
void calcAverage(struct Student *bptr, int n) {
    for (int i = 0; i < n; i++) {
        // Calculate the average marks for each student
        (bptr + i)->avg_marks = ((bptr + i)->sub1 + (bptr + i)->sub2 + (bptr + i)->sub3) / 3.0;
    }
}
// Function to check and display the grade based on average marks
void checkGrade(float avg_marks) {
    if (avg_marks < 50) {
        cout << "FAIL";
    } else if (avg_marks >= 50 && avg_marks < 60) {
        cout << "Second Class";
    } else if (avg_marks >= 60 && avg_marks < 75) {
        cout << "First Class";
    } else {
        cout << "Distinction";
    }
}
// Function to display details and grade of 'n' students
void Display(struct Student *bptr, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Name: " << (bptr + i)->name << endl;
        cout << "Roll no: " << (bptr + i)->rollNo << endl;
        cout << "subject 1: " << (bptr + i)->sub1 << endl;
        cout << "subject 2: " << (bptr + i)->sub2 << endl;
        cout << "subject 3: " << (bptr + i)->sub3 << endl;
        cout << "Total: " << (bptr + i)->sub1 + (bptr + i)->sub2 + (bptr + i)->sub3 << endl;
        cout << "Avg: "<<(bptr + i)->avg_marks<< endl;
        cout<<  "Result: ";
        checkGrade((bptr + i)->avg_marks);
        cout << endl;
    }
}
int main() {
    struct Student *bptr;// structure pointer 
    int n;
    cout << "Enter the number of students: ";
    cin >> n;// Read the number of student
    bptr = new Student[n]; // 'new' to allocate memory dynamically for an array of students
    getDetails(bptr, n);//call the getDetails function
    calcAverage(bptr, n);//call the calcAverage function
    Display(bptr, n);//call the Display function
    delete[] bptr; //  'delete[]' to free the memory allocated with 'new'
    return 0;
    }
