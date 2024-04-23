#include <iostream>
#include <string>
using namespace std;

class Person{
    protected:
        string name;
        int age;
        string adress;
        void input(){
            getchar();
            cout<<"Enter the name: ";
            getline(cin,name);
            cout<<"Enter age: ";
            cin>>age;
            cout<<"Enter address: ";
            getchar();
            getline(cin, adress);
        }
        void display(){
            cout<<endl<<endl<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Age: "<<age<<endl;
            cout<<"Address: "<<adress<<endl;
        }
};

class Faculty: protected Person{
    public:
        string dept;
        Faculty(){
            cout<<"\n\nEnter the details of the faculty: "<<endl;
            Person::input();
            cout<<"Enter the department: ";
            cin>>dept;
        }
        int get_age(){
            return age;
        }
        void display(){
            Person::display();
            cout<<"Department: "<<dept<<endl;
        }
};

class Staff: protected Person{
    public:
        string desgn;
        Staff(){
            cout<<"\n\nEnter the details of the staff: "<<endl;
            Person::input();
            cout<<"Enter the designation: ";
            cin>>desgn;
        }
        int get_age(){
            return age;
        }
        void display(){
            Person::display();
            cout<<"Designation: "<<desgn<<endl;
        }
};

class Student: protected Person{
    public: 
        string field;
        string ID;
        Student(){
            cout<<"\n\nEnter the details of the student: "<<endl;
            Person::input();
            cout<<"Enter the field of study of the student: ";
            cin>>field;
            cout<<"Enter the school ID: ";
            cin>>ID;
        }
        int get_age(){
            return age;
        }
        void display(){
            Person::display();
            cout<<"Study field: "<<field<<endl;
            cout<<"Student ID: "<<ID<<endl;
        }
};

int main(){
    
    Faculty f[2];
    Staff s[2];
    Student st[2];
    int faculty_avg_age,staff_avg_age,student_avg_age;
    for(int i=0;i<2;i++){
        faculty_avg_age+= f[i].get_age();
        staff_avg_age+= s[i].get_age();
        student_avg_age+= st[i].get_age();
    }
    faculty_avg_age/=2;
    staff_avg_age/=2;
    student_avg_age/=2;

    cout<<"Average age of the faculty: "<<faculty_avg_age<<endl;
    cout<<"Average age of the staff: "<<staff_avg_age<<endl;
    cout<<"Average age of the student: "<<student_avg_age<<endl;


    cout<<"Enter the department to show its employees: ";
    string temp_dept;
    cin>>temp_dept;
    for(int i=0;i<2;i++){
        if(f[i].dept.compare(temp_dept)==0){
            f[i].display();
        }
    }

    cout<<"Enter the field of student to search for the students: ";
    string temp_field;
    cin>>temp_field;
    for(int i=0;i<2;i++){
        if(st[i].field.compare(temp_field)==0){
            st[i].display();
        }
    }
    return 0;
}