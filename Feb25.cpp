#include <iostream>
char lowercase(char a){
    if((int)a>=65 && (int)a<=90){
        a+=32;
    }
    return a;
}

int main(){
    char ar[100];
    char nar[100];
    int n;
    scanf("%s",&ar);
    scanf("%s",&nar);
    for(int i=0;i<100;i++){
        ar[i]=lowercase(ar[i]);
        if(ar[i]=='\0'){
            n=i;
            break;
        } 
    }
    int nn;
    for(int i=0;i<100;i++){
        nar[i]=lowercase(nar[i]);
        if(nar[i]=='\0'){
            nn=i;
            break;
        } 
    }
    int flag=0;
    if(n!=nn){
        printf("String length not same.");
        flag=1;
    }
    if(flag==0){
        for(int i=0;i<n;i++){
            if(ar[i]!=nar[i]){
                if(ar[i]>nar[i]){
                    printf("1");
                }
                else{
                    printf("-1");
                }
                flag=1;
                break;
            }
        }
    }
    if(flag==0) printf("0");
}