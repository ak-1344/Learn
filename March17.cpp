/*
15.  Write a program to print the name, salary and date of joining of 10 employees in a company. Use array of objects.
*/


#include <iostream>
#include <string>
using namespace std;
string month[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
struct date{
    int day;
    string month;
    int year;
};
date input_date(){
    date a;
    int m;
    cout<<"Enter day, month and year of joining respectively: ";
    cin>>a.day;
    cin>>m;
    cin>>a.year;
    a.month=month[m-1];
    return a;
}
void print_date(date a){
    cout<<a.month<<" "<<a.day<<","<<a.year<<endl;
}

typedef class Employee{
    private:
        string name;
        int salary;
        date joining;
    public:
        Employee(){
            cout<< "Enter the details as follows: "<<endl;
            cout<<"Enter the name: ";
            cin>>name;
            cout<<"Enter the salary of the employee: ";
            cin>>salary;
            joining=input_date();
        }

        void print(){
            cout<<"Name: "<<name<<endl;
            cout<<"Salary: "<<salary<<endl;
            cout<<"Date: ";
            print_date(joining);
        }
}emp;

int main(){
    int n;
    cout<<"Enter the number of employes: ";
    cin>>n;
    emp employee[n];
    for(int i=0;i<n;i++){
        employee[i].print();
    }
    return 0;
}