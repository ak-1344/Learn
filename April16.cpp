/*
Develop a c++ program using operator overloading to determine:
1. Area of a cirle
2. Circumference of a circle
3. Area of a rectangle
4. Area of a triangle
5. perimeter of a square
6. Area of a square
*/

#include <iostream>
#include <cmath>
using namespace std;

class circle{
    public: 
        double radius;
        double circumference;
        double area;
        circle(){
            cout<<"\nEnter the radius of the circle: ";
            cin>>radius;
        }

        void operator &(){
            area = 3.14*radius*radius;
            circumference= 2*3.14*radius;
            cout<<"\nArea of the circle : "<<area<<endl;
            cout<<"Circumference of the circle: "<<circumference<<endl;
        }
};

class rectangle{
    public:
        double length, bredth, area;

        rectangle(){
            cout<<"Enter the length and breadth respectively: ";
            cin>>length>>bredth;
        }

        void operator &(){
            area = length*bredth;
            cout<<"\nArea of the rectangle: "<<area<<endl;
        }
};

class triangle{
    public:
        double s1,s2,s3,area;

        triangle(){
            cout<<"Enter the sides of the triangle respectively: ";
            cin>>s1>>s2>>s3;
        }

        void operator &(){
            double s= (s1+s2+s3)/2;
            area= pow( s*(s-s1)*(s-s2)*(s-s3)  ,0.5);
            cout<<"\nArea of the triangle: "<<area<<endl;
        }
};

class square{
    public: 
        double s,area,perimeter;

        square(){
            cout<<"Enter the side of the square: ";
            cin>>s;
        }

        void operator &(){
            perimeter= 4*s;
            area= s*s;
            cout<<"\nArea of the square: "<<area<<endl;
            cout<<"Perimeter of the square: "<<perimeter<<endl;
        }
};


int main(){
    circle a;
    rectangle b;
    triangle c;
    square d;
    &a;&b;&c;&d;
    return 0;
}