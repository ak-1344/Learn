#include <iostream>
using namespace std;

template<class t>
class numbers{
    public:
        numbers(){}
        numbers(t u){
            number=u;
        }
        t number;
};

template<class d>
void average(d a[5]){
    int n = 5;
    d avg=0;
    for(int i=0;i<n;i++){
        avg+=a[i];
    }    
    cout<<avg/n<<endl<<endl;
}

int main(){
    int arr[] = {1,2,3,4,5};
    double arr1[]= {1.1,1.2,1.3,1.4,1.5};
    int arr2[] = {'a','b','c','d','e'};
    int arr3[5];
    for(int i=0;i<5;i++){
        numbers<int> obj(i+1);
        arr3[i]=obj.number;
    }

    average(arr);
    average(arr1);
    average(arr2);
    average(arr3);
}