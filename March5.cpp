#include <iostream>
using namespace std;
int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};

typedef struct Date{
    int day;
    int month;
    int year;
}d;
d input(){
    d a;
    cin>>a.day>>a.month>>a.year;
    return a;
}
//counting days of of the year till date
int days_in_year(d a){
    int days=0;
    days+=a.day;
    for(int i=0;i<a.month;i++){
        days+=month[i];
    }
    return days;
}
////////////////////////////////////////////////////////
int main(){
    d a1,a2;
    a1=input();
    a2=input();
// calculating all days
    int days= (365- days_in_year(a1)) + days_in_year(a2);
    if(a2.year==a1.year){
        days+= (a2.year-a1.year)*365;
    }else{
        days+= (a2.year-a1.year-1)*365;
    }

// counting leapdays
    int leap_days=0;
    for(int i=a1.year;i<a2.year;i++){
        if(i%4==0 && i%400!=0 ){
            leap_days++;
        }
    }
    if(a2.month>2){
        leap_days++;
    }
    days+=leap_days;
    
    cout<< days;
}