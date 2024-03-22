/*
    *
     *
      *
     *
    *
     *  
print n lines of this pattern (take n as input)  
*/
#include <bits/stdc++.h>
using namespace std;

void space(int n){
    for(int i=0;i<n;i++){
        cout<<" ";
    }
}
void pattern(int count){
    static int n=1;
    cout<<"*\n";
    while(n!=count){
        for(int i=1;i<3;i++){
            space(i);
            cout<<"*\n";
            n++;
            if(n==count){
                break;
            }
        }
        for(int i=1;i>=0;i--){
            if(n==count){
                break;
            }
            space(i);
            cout<<"*\n";
            n++;
        }
    }
}

int main(){
    int n;
    cout<<"Enter the number of lines of pattern you want to print: ";
    cin>>n;
    int count;
    pattern(n);
}