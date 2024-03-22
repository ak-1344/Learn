/*
Solving a quadratic equation using OOP technique
*/
#include <iostream>
#include <cmath>

typedef class quadratic{
    private:
        double a,b,c,d,sol1,sol2;
    public:
        quadratic(double a,double b,double c){
            std::cout<< "\nThe given equation is: "<<a<<"x^2 + "<<b<<"x + "<<c<<" = 0 .";
            double d= (b*b) - (4*a*c);
            sol1= (-b + sqrt(d))/2*a;
            sol2= (-b - sqrt(d))/2*a;
        }
        quadratic(){
            std::cout<<"\nEnter the value of a,b,c respectively.";
            std::cin>>a>>b>>c;
            std::cout<< "\nThe given equation is: "<<a<<"x^2 + "<<b<<"x + "<<c<<" = 0 .";
            double d= (b*b) - (4*a*c);
            sol1= (-b + sqrt(d))/2*a;
            sol2= (-b - sqrt(d))/2*a;
        }
        void print(){
            std::cout<<"\nThe first solution is: "<<sol1<<" and the second solution is: "<<sol2;
        }
}q;

int main(){
    q a(1,2,1);
    a.print();
    q b;
    b.print();
}