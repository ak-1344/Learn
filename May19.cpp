#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Employee{
    public:
        string id, name;
        int age;
        double basic_salary,gross_salary;

        void getDetails(){
            cout<<"Enter the name: ";
            cin>>name;
            cout<<"Enter ID of the employee: ";
            cin>>id;
            cout<<"Enter age: ";
            cin>>age;
            cout<<"Enter the Basic salary: ";
            cin>>basic_salary;
            cout<<"Employee added...!!"<<endl<<endl;
        }

        void calcGross(){
            double da,hra,ta;
            if(basic_salary<10000){
                da=50; hra=10; ta=10;
            }else if(basic_salary<15000){
                da=60; hra=20; ta=20;
            }else if(basic_salary<20000){
                da=70; hra=20; ta=20;
            }else{
                da=80; hra=20; ta=20;
            }
            gross_salary = basic_salary * (1 + (da+hra+ta)/100);
        }

        void display(){
            cout<<"Name: "<<name<<endl;
            cout<<"ID: "<<id<<endl;
            cout<<"Age: "<<age<<" Years"<<endl;
            cout<<"Basic salary: "<<basic_salary<<endl;
            cout<<"Gross salary: "<<gross_salary<<endl;
        }
};

int main(){
    int n;
    cout<<"Enter the number of employee you have presently: ";
    cin>>n;
    Employee *arr;
    arr = (Employee*)malloc(n*sizeof(Employee));
    for(int i=0;i<n;i++){
        arr[i].getDetails();
        arr[i].calcGross();
    }
    cout<<n<<" number of employee added!";

    char temp;
    cout<<"Do you want to add a new employee?? y/n";
    cin>>temp;
    while(temp=='y'){
        n=n+1;
        arr= (Employee*)realloc(arr,n*sizeof(Employee));
        arr[n-1].getDetails();
        arr[n-1].calcGross();
        cout<<"Do you want another employee?? y/n";
        cin>>temp;
    }
    cout<<"Total number of employees: "<<n;
    cout<<endl<<"Do you want to print all the employees: y/n";
    cin>>temp;
    if(temp=='y'){
        for(int i=0;i<n;i++){
            arr[i].display();
        }
    }
    cout<<endl<<"All the employees are displayed !!";
    free(arr);
    return 0;
}