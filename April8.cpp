/*
n=6
Pattern:
1 2 3 4 5 6
 7 8 9 0 9
  0 9 0 9
   0 9 0
    9 0
     9
    0 9
   0 9 0 
  9 0 9 0
 9 0 9 8 7
6 5 4 3 2 1
*/


#include <iostream>
using namespace std;


void space(int n){
    for(int i=0;i<n;i++){
        cout<<' ';
    }
}
int main(){
    int n;
    cin>>n;
    int len = (n*(n+1))/2;
    int arr[len];
    for(int i=0;i<9;i++){
        arr[i]=i+1;
    }
    for(int i=9;i<len;i++){
        if(i%2==0){
            arr[i]=9;
        }else{
            arr[i]=0;
        }
    }


// forward printing
    int counter=n;
    int count=n;
    for(int i=0;i<len-1;i++){
        // cout<<"("<<i<<","<<count<<","<<counter<<")"<<endl;
        if(i==counter){
            cout<<endl;
            space(n-count+1);
            count--;
            counter= i+count;
        }
        cout<<arr[i]<<" ";
    }


// Backward printing

    int counter2 = 0;
    int count2 = 0;
    for(int i=0;i<len;i++){
        if(i==counter2){
            cout<<endl;
            space(n-count2-1);
            count2++;
            counter2= i+count2;
        }
        cout<<arr[len-1-i]<<" ";

    }

}