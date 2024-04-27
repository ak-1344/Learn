#include <iostream>
using namespace std;

class baseA{
    private:
        int x;
        int y;
    public:
        virtual inline void getdata(){}
        virtual inline void display(){};
};

class derivedB : public baseA{
    private:
        long int roll_no;
        string name;
    public:
        void getdata(){
            cout<<"Enter the roll no.: ";
            cin>>roll_no;
            cout<<"Enter the name of the student: ";
            getchar();
            getline(cin,name);
        }
        void display(){
            cout<<"\nRoll No: "<<roll_no<<endl;
            cout<<"Name: "<<name<<endl;
        }
};

class derivedC : public derivedB{
    private:
        double height;
        double weight;
    public:
        void getdata(){
            cout<<"Enter the height: ";
            cin>>height;
            cout<<"Enter the weight: ";
            cin>>weight;
        }
        void display(){
            cout<<"Height: "<<height<<endl;
            cout<<"Weight: "<<weight<<endl;
        }
};

int main(){
    baseA *ptr[2];
    derivedB objB;
    derivedC objC;
    ptr[0] = &objB;
    ptr[1] = &objC;

    ptr[0]->getdata();
    ptr[1]->getdata();

    ptr[0]->display();
    ptr[1]->display();
    return 0;
}