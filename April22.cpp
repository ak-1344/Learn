#include <iostream>
using namespace std;

template <class T, class U, class V>
class templateClass{
    private:
        T a;
        U b;
        V c;
    public:
        templateClass(T v1, U v2, V v3): a(v1), b(v2), c(v3) {}

        void display(){
            cout<<a<<endl;
            cout<<b<<endl;
            cout<<c<<endl<<endl;
        }
};

int main(){
    templateClass<int , double, char> a(5,6.34,'f');
    templateClass<char,char,double> b ('l','o',3.3);
    templateClass<int, int, int> c(9,3,6);
    a.display();
    b.display();
    c.display();
}