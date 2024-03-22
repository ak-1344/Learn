/*
13.   Write a program by creating an 'Employee' class having the following functions and print the final salary.
1 - 'getInfo()' which takes the salary, number of hours of work per day of employee as parameters
2 - 'AddSal()' which adds $10 to the salary of the employee if it is less than $500.
3 - 'AddWork()' which adds $5 to the salary for each hr of the employee if the number of hours of work per day is more than 6 hours.
*/
#include <iostream>
using namespace std;

typedef class  Employee{
    private:
        int salary;
        int hrs;
    public:
        void getInfo(){
            cout<<"Enter salary and number if work done by employee respectively: ";
            cin>>salary>>hrs;
        }
        void AddWork(){
            if(hrs>6){
                salary+= 5;
            }
        }
        void AddSal(){
            if(salary<500){
                salary+=10;
            }
        }
        void print(){
            cout<<salary<<" "<<hrs;
        }
}emp;

int main(){
    emp a;
    a.getInfo();
    a.AddSal();
    a.AddWork();
    a.print();
    return 0;
}