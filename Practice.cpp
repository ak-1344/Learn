#include <iostream>
#include <string>
using namespace std;

class person
{
public:
    string name;
    int age;
    string address;
    void inputinfo()
    {
        cout << "Enter the name: ";
        getchar();
        getline(cin, name);
        cout << "Enter the age: ";
        cin >> age;
        cout << "Enter the address: ";
        getchar();
        getline(cin, address);
    }
    void displayinfo()
    {
        cout << "\n\nThe name: " << name << endl;
        cout << "The age: " << age << endl;
        cout << "The address: " << address << endl;
    }
};
class student : public person
{
public:
    string id;
    string branch;
    void input()
    {
        inputinfo();
        cout << "Enter your branch: ";
        cin >> branch;
        cout << "Enter the uid: ";
        cin >> id;
    }
    void display()
    {
        displayinfo();
        cout << "The branch: " << branch << endl;
        cout << "The uid: " << id << endl;
    }

};
class faculty : public person
{
public:
    string department;
    void input()
    {
        inputinfo();
        cout << "Enter you department: ";
        cin >> department;
    }
    void display()
    {
        displayinfo();
        cout << "Your department: " << department << endl;
    }
};
class staff : public person
{
public:
    string desg;
    void input()
    {
        inputinfo();
        cout << "Enter your designation: ";
        cin >> desg;
    }
    void display()
    {
        displayinfo();
        cout << "Your designation: " << desg << endl;
    }

};

int main()
{

    int s_n, f_n, staff_n;
    cout << "Enter the number of students: ";
    cin >> s_n;
    cout << "Enter the number of faculty: ";
    cin >> f_n;
    cout << "Enter the number of staff: ";
    cin >> staff_n;

    student bchcha[s_n];
    faculty master[f_n];
    staff chota_master[staff_n];

    for (int i = 0; i < s_n; i++)
    {
        cout << "\n\nEnter the details of student: \n";
        bchcha[i].input();
    }
    for (int i = 0; i < f_n; i++)
    {
        cout << "\n\nEnter the details of faculty: \n";
        master[i].input();
    }
    for (int i = 0; i < staff_n; i++)
    {
        cout << "\n\nEnter the details of staff: \n";
        chota_master[i].input();
    }

    for (int i = 0; i < s_n; i++)
    {
        cout << "\n\nStudent details: \n";
        bchcha[i].display();
    }

    for (int i = 0; i < f_n; i++)
    {
        cout << "\n\nFaculty details: \n";
        master[i].display();
    }

    for (int i = 0; i < staff_n; i++)
    {
        cout << "\n\nStaff details: \n";
        chota_master[i].display();
    }

    return 0;
}
