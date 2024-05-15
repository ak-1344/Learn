#include <iostream>
#include <cmath>
using namespace std;

class Point{
    private:
        double x,y;
    public:
        Point(){} //Default constructor

        void setter(){
            cout<<"Enter the value of x and y respectively: ";
            cin>>x>>y;
        }
        void getter(){
            cout<<"x: "<<x<<"\ty: "<<y<<endl;
        }

        double operator -(Point a){
            double l;
            l= sqrt( (a.x - this->x)*(a.x - this->x) + (a.y - this->y)*(a.y - this->y) );
            return l;
        }
};

int main(){
    Point P1,P2,P3,P4;
    P1.setter();
    P2.setter();
    P3.setter();
    P4.setter();
    
    P1.getter();
    P2.getter();
    P3.getter();
    P4.getter();

    double slP1P2, slP2P3, slP3P4, slP4P1;
    slP1P2= P1-P2;
    slP2P3= P2-P3;
    slP3P4= P3-P4;
    slP4P1= P4-P1;

    double perimeter = slP1P2 + slP2P3 + slP3P4 + slP4P1;
    cout<<"Perimeter: "<<perimeter;
    return 0; 
}