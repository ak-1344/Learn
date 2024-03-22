#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int prime(int a){
    int count =0;
    for(int i=2;i<a/2;i++){
        if(a%i==0){
            count++;
        }
    }
    if(count ==0) return 1;
    else return 0;
}
class solution{
    private:
        int left, right;
        int p[2]={0,0};
    public:
        solution(){
            cout<<"\nEnter the left and right values respetively: ";
            int a,b;
            cin>>a>>b;
            left=a;
            right = b;
        }
        solution(int a, int b){
            left=a;
            right = b;
        }

        void print(){
            int n= right-left;
            int count=0;
            int arr[n]={0};
            for(int i=left+1; i< right; i++){
                if(prime(i)==1){
                    arr[count]=i;
                    count ++;
                }
            }
            if(count>1){
                int min=arr[count-1]-arr[0];
                for(int i=0;i<count-1;i++){
                    if(arr[i+1]-arr[i]<min){
                        min=arr[i+1]-arr[i];
                    }
                }
                for(int i=0;i<count-1;i++){
                    if(arr[i+1]-arr[i]==min){
                        p[0]=arr[i];
                        p[1]=arr[i+1];
                        break;
                    }
                }
            }  
            else{
                p[0]=-1;
                p[1]=-1;
            }         
            cout<<"The answer is "<<p[0]<<" and "<<p[1]<<endl;
        }
};

int main(){
    solution a(10,100);
    a.print();
    solution b;
    b.print();
    
}