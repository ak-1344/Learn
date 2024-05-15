#include <stdio.h>
#include <string.h>

void cypher(char *s, int n){
    int len= strlen(s);
    for(int i=0;i<len;i++){
        s[i]+=n;
        if( (s[i]>'Z' && s[i]<'A') || s[i]>'z'){
            s[i]-=26;
        }
        if(s[i]-n == ' '){
            s[i]=' ';
        }
    }
}

int main(){
    char s[100];
    int key;
    fgets(s,100,stdin);
    scanf("%d", &key);
    cypher(s,key);
    printf("%s",s);
    return 0;
}