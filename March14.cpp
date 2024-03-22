#include<stdio.h>

int palindrome(int a){
    int b;
    for(int i=a;i>0;i=i/10){
        b= b*10 +i;
    }
    if(b==a) return a;
    else return 0;
}

int main(){
    int a,b;
    printf("Enther the size of a and b: ");
    scanf("%d %d",&a,&b);

    int A[100]={0}, B[100]={0};

    for(int i=0;i<a;i++){
        scanf("%d",&A[i]);
    }
    for(int i=0;i<b;i++){
        scanf("%d",&B[i]);
    }

    int max=a;
    if(b>a) max=b;

    int C[max];
    int sum;
    for(int i=0;i<max;i++){
        C[i]=A[i]+B[i];
        sum+= palindrome(C[i]);
    }

    printf("%d",sum);
    return 0;
}