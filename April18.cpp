#include <iostream>
using namespace std;

class timez{
    public: 
        int h,m,s;
    
    void operator ++(){
        s++;
        if(s>=60){
            s=s-60;
            m++;
        }
        if(m>=60){
            m=m-60;
            h++;
        }
        if(h>12){
            h=h-12;
        }
    }
    
    void operator --(){
        s--;
        if(s== -1){
            s=59;
            m--;
        }
        if(m==-1){
            m=59;
            h--;
        }
        if(h==0){
            h=12;
        }
    }
    
    
    friend istream & operator >>(istream &input, timez &t){
        input>>t.h>>t.m>>t.s;
        return input;
    }
    friend ostream & operator <<(ostream &output, timez &t){
        output<<t.h<<":"<<t.m<<":"<<t.s<<endl;
        return output;
    }
};

int main(){
    timez tm;
    cin>>tm;
    cout<<tm;
    ++tm;
    cout<<tm;
    --tm;
    cout<<tm;
    return 0;
}