#include <iostream>
using namespace std;

class base{
    public:
        base(){}
        int a;
        void input(){
            cout<<"Function of base class";
            cin>>a;
        }
};

class derived: public base{
    public:
        int a;
        void input(){
            cout<<"Function of derived class.";
            cin>>a;
        }
};

int main(){
    derived obj;
    base *obj1 = &obj;
    obj1->input();
}