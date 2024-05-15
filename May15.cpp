#include <iostream>
using namespace std;

template<typename T>
double average(T arr[],int size){
    if(size){
        double sum=0;
        for(int i=0;i<size;i++){
            sum+= double(arr[i]);
        }
        return sum/size;
    }
}

class Employee {
public:
    double salary;
    Employee(double s){
        salary=s;
    }
    double getSalary(){
        return salary;
    }
};
template <>
double average<Employee>(Employee arr[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i].getSalary();
    }
    return sum/size;
}
int main() {
    int a[]={1,2,3,4,5};
    double b[]={3.5,4.7,6.2,8.9,9.1};
    char c[]={'a','b','c','d','e'};
    Employee empArr[]={Employee(2500.0),Employee(3500.0),Employee(4500.0),Employee(5500.0),Employee(6500.0)};

    cout<<average(a,5)<<endl;
    cout<<average(b,5)<<endl;
    cout<<average(c,5)<<endl;
    cout<<average(empArr, 5)<<endl;
    return 0;
}