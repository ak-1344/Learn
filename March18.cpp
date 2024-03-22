/*
16.  Write a program to print the roll number and average marks of 8 students in three subjects (each out of 100). The marks are entered by the user and the roll numbers are automatically assigned.
*/
#include <iostream>
using namespace std;

typedef class student_marks{
    public:
        int Roll_No;
        int mark1,mark2,mark3;
        double average;
        int avg(){
            average= (mark1+mark2+mark3)/3;
            return average;
        }
}marks;

int main(){
    int n;
    cout<<"Enter the numbre of students: ";
    cin>>n;
    marks student[n];
    
    for(int i=0;i<n;i++){
        student[i].Roll_No = i+1;
        cout<<"Enter the marks in 3 subjects of students respectively: ";
        cin>> student[i].mark1 >> student[i].mark2 >> student[i].mark3;
        student[i].average = student[i].avg();
    }

    for(int i=0;i<n;i++){
        cout<< "Roll No. : " << student[i].Roll_No <<endl << "Marks: " << student[i].mark1 << " ";
        cout<< student[i].mark2   <<" "  << student[i].mark3 << endl;
        cout<< "Average: " << student[i].average <<endl << endl;
    }
    return 0;
}