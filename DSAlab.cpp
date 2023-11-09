/*
Program to calculate the salary of multiple employees
Author: Ujjwal Agrahari (RA2211003012075)
*/
#include <iostream>
using namespace std;

// structure to store employee details and salary information
struct CalcSalary{ 
    string name,id,dept;  // string variables to store Employee's Name, Id and Dept 
    int basicSal;         // Integer variable to store basic salary
    float totalSal,hra_amount,da_amount,pf_amount,allow_amount; // Float variables to store salary information
     };  

int main() {
    int num; // Number of employees
    float hra=0.1,da=0.1,pf=0.2,allow=0.1; // Constants for calculating various allowances
    // Read the number of employees from the user
    cout<<"Enter the number of employee:\n";
    cin>>num;

    //array of structure variables to store employee information
    struct CalcSalary employee[num];

    // Input employee details
    for(int i=0;i<num;i++){
        cin.ignore(1,'\n');
        cout<<"Enter The name of Employee:"<<i+1<<endl;
        getline(cin,employee[i].name);
        cout<<"Enter his Id:\n";
        getline(cin,employee[i].id);
        cout<<"Enter his dept:\n";
        getline(cin,employee[i].dept);
        cout<<"Enter his basic salary:\n";
        cin>>employee[i].basicSal;

        // Calculate various allowances and total salary
        employee[i].hra_amount=employee[i].basicSal*hra;
        employee[i].da_amount=employee[i].basicSal*da;
        employee[i].pf_amount=employee[i].basicSal*pf;
        employee[i].allow_amount=employee[i].basicSal*allow;
        employee[i].totalSal=employee[i].basicSal+employee[i].hra_amount+employee[i].da_amount+employee[i].allow_amount-employee[i].pf_amount;     
    }
    // Output employee details and total salary
    for(int i=0;i<num;i++){
      cout<<"_________THE DETAILS OF EMPLOYEE: "<< i+1<<" ARE_________:\n";
        cout<<"NAME: "<<employee[i].name<<endl;
        cout<<"ID: "<<employee[i].id<<endl;
        cout<<"DEPT: "<<employee[i].dept<<endl;
        cout<<"BASIC SALARY: "<<employee[i].basicSal<<endl;
        cout<<"TOTAL SALARY: "<<employee[i].totalSal<<endl;
     
    };
    return 0;}