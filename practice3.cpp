#include <stdio.h>

struct marks{
    int sports,physics,chemistry,maths;
};

typedef struct student{
    char StudentID[10],StudentName[20];
    struct marks mark;
    double avg;
    int scholarship;
    double fee;
}student;

struct marks input_marks(){
    struct marks a;
    printf("Enter the marks of student in sports, physics, chemistry and maths respectively: ");
    scanf("%d %d %d",&a.sports,&a.physics,&a.chemistry,&a.maths);
    return a;
}

double avg(struct marks a){
    return (a.chemistry+a.maths+a.physics+a.sports)/4.0;
}

int scholar_ship(double avg){
    int s=0;
    if(avg>90){
        s=50;
    }else if(avg>80){
        s=25;
    }else if(avg>70){
        s=10;
    }else if(avg>60){
        s=5;
    }else{
        s=0;
    }
    return s;
}
double fee_paid(int s){
    double fee= (150000*s)/100;
    fee=150000-fee;
    return fee;
}

struct student input(){
    struct student a;
    printf("Enter the stduent id and stduent name respectively: ");
    scanf("%s ",&a.StudentID);
    fgets(a.StudentName,20,stdin);
    a.mark = input_marks();
    a.avg = avg(a.mark);
    a.scholarship = scholar_ship(a.avg);
    a.fee= fee_paid(a.scholarship);
    return a;
}

void display(student a){
    printf("Student ID: %s\nStudent name: %s\n",a.StudentID,a.StudentName);
    printf("Average marks: %.2lf\n",a.avg);
    printf("Scholarship Percentage: %d%\n",a.scholarship);
    printf("Fee paid: %lfRs only",a.fee);
}
int main(){
    student abc=input();
    display(abc);
    
}