#include <stdio.h>
void space(int n){
    for(int i=0;i<n;i++){
        printf(" ");
    }
}

int main(){
    char a;
    printf("Entre the character in small: ");
    scanf("%c",&a);

    int n= a-'a'+1;
    for(int i=0;i<n;i++){
        space(n-i-1);
        for(int j=0;j<=i;j++){
            printf("%c",(char)('A'+j));
        }
        for(int j=0;j<i;j++){
            printf("%c",(char)('A'+i-j-1));
        }
        
        printf("\n");
    }
    return 0;
}