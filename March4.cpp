/*
Create a structure to store the following details of a student.
Rollno,name,mark1,mark2,mark3,total,result and grade.
Write a C program to read and store Rollno,name,mark1,mark2, and mark3 of 10 students and calculate total and grade as follows.
Total is the sum of 3 subjects
Result is pass if all subject marks are greater than or equal to 50 otherwise “Fail”
Grade will be awarded if result is “Pass” . Grade is “S” if average mark is greater than 89. Grade is “A” if average lies between 70 and 89 (both inclusive). Grade is “B” if average lies between 50 and 69(both inclusive).
Print the details of all student one by one. Pass structure as function arguments.
*/
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

string Grade(int avg, string result)
{
    string grade;
    if (result == "Pass")
    {
        if (avg > 89)
        {
            grade = "S";
        }
        else if (avg > 69)
        {
            grade = "A";
        }
        else if (avg > 49)
        {
            grade = "B";
        }
    }
    else
    {
        grade = "The student have failed in one or more of the subjects.";
    }
    return grade;
}
string res(int a, int b, int c)
{
    string result;
    if (a < 50 || b < 50 || c < 50)
    {
        result = "Fail";
    }
    else
    {
        result = "Pass";
    }
    return result;
}

class student
{
private:
    int roll;
    string name;
    int mark1, mark2, mark3;
    int total;
    double avg;
    string result, grade;

public:
    student()
    {
        cout << "Please enter the name, roll no, and marks in three subjects:";
        cout << "\nName:";
        cin >> name;
        cout << "Roll No.";
        cin >> roll;
        cout << "Enter marks in three subject continously:";
        cin >> mark1 >> mark2 >> mark3;
        total = mark1 + mark2 + mark3;
        avg = total / 3.0;
        result = res(mark1, mark2, mark3);
        grade = Grade(avg, result);
    }
    void print()
    {
        cout << "Name:" << name << endl;
        cout << "Roll No." << roll << endl;
        cout << "Mark 1 " << mark1 << endl;
        cout << "Mark 2 " << mark2 << endl;
        cout << "Mark 3 " << mark3 << endl;
        cout << "Total " << total << endl;
        cout << "Average " << avg << endl;
        cout << "Result " << result << endl;
        cout << "Grade " << grade << endl;
        cout << endl;
    }
};

int main()
{
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    student arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].print();
    }
}