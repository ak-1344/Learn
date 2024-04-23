#include <iostream>
using namespace std;

template <typename A>
A *sum(int n){
    A *arr = new A[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    return arr;
}

template<typename B>
void display(B *arr,int n){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
}


int main(){
    int n; cin>>n;
    display(sum <int>(n),n);
}