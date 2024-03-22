#include <iostream>
using namespace std;
struct est_arr{
    int hr;
    int min;
    int sec;
};

struct est_arr get_time(){
    struct est_arr initial;
    cin>>initial.hr >>initial.min >>initial.sec ;
    return initial;
}

struct est_arr compute_time(struct est_arr initial,struct est_arr time_taken){
    struct est_arr final;
    if(initial.sec+time_taken.sec>=60){
        final.sec=initial.sec+time_taken.sec-60;
        initial.min++;
    }
    else{
        final.sec=initial.sec+time_taken.sec;
    }

    if(initial.min+time_taken.min>=60){
        final.min=initial.min+time_taken.min-60;
        initial.hr++;
    }
    else{
        final.min=initial.min+time_taken.min;
    }

    if(initial.hr+time_taken.hr>12){
        final.hr=initial.hr+time_taken.hr-12;
    }
    else{
        final.hr=initial.hr+time_taken.hr;
    }
    return final;
}

void show_time(struct est_arr a){
    cout<<a.hr<<" "<<a.min<<" "<<a.sec;
}

int main(){
    cout<<"Enter the starting time:";
    struct est_arr initial = get_time();
    cout<<"Enter the time taken:";
    struct est_arr time_taken = get_time();
    struct est_arr final = compute_time(initial,time_taken);
    show_time(final);
}