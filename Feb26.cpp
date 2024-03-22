#include <iostream>
#include <string.h>
using namespace std;

int main(){
    string sum;
    cin>>sum;
    int n= sum.size();
    int i=0;
    while(i<n-2){
        if(sum[i]>sum[i+2]){
            char temp=sum[i+2];
            sum[i+2]=sum[i];
            sum[i]=temp;
            i=-2;
        }
        i+=2;
    }
    cout<<sum;
}