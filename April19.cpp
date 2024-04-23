#include <iostream>
using namespace std;

template <class T>
class Calculator {
    private:
        T num1, num2;

    public:
        Calculator(T n1, T n2) {
            num1 = n1;
            num2 = n2;
        }

        void displayResult() {
            cout << "Numbers: " << num1 << " and " << num2 << "." << endl;
            cout << num1 << " + " << num2 << " = " << add() << endl;
            cout << num1 << " - " << num2 << " = " << subtract() << endl;
            cout << num1 << " * " << num2 << " = " << multiply() << endl;
            cout << num1 << " / " << num2 << " = " << divide() << endl;
        }

        T add(){
            return num1 + num2;
        }   
        T subtract(){
            return num1 - num2;
        }   
        T multiply(){
            return num1 * num2;
        }   
        T divide(){
            return num1 / num2;
        }   
};

int main() {
    int a,b;
    double c,d;
    cout<<"Enter two integers: ";
    cin>>a>>b;
    cout<<"Enter two float numbers: ";
    cin>>c>>d;

    Calculator<int> intCalc(a,b);
    Calculator<double> floatCalc(c,d);

    cout << "Int results:" << endl;
    intCalc.displayResult();

    cout << endl;
    cout<< "Float results:" << endl;
    floatCalc.displayResult();

    return 0;
}