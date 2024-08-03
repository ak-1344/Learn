/*
n=5

*       *
* *   *
* * *
* * * * 
* * * * * 
*/

#include <stdio.h>

void space(int n){
    for(int i=0;i<n;i++){
        printf("  ");
    }
}

int main(){
    int n; scanf("%d",&n);

    int count =2;

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            printf("* ");
        }
        space(n-i-count);
        if(n-i-count>=0){
            printf("*\n");
            count++;
        }else{
            printf("\n");
        }
    }

}