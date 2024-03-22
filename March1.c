/*
1.Antakshari is a popular game played in India. Many word games are like antakshari. One such game is wordakshari. The game can be played by two or more people. The first player must recite a word. The last letter of the word is then used by the next player to recite another word, starting with that word. The winner or winning team is decided by a process of elimination. The person or team that cannot come up with a word with the right consonant is eliminated. The following rules need to be followed while playing this game. 
(i) The first word can begin with any letter. 
(ii) All other words have to begin with the last letter of the previous word 
(iii) No words can be repeated.*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char arr[1000][20];
    printf("You can start the game. \nPlease enter all the words in small.\n");
    scanf("%s",&arr[0]);
    int i=1;
    int flag=0;
    while(flag==0){
        scanf("%s",&arr[i]);

        for(int j=0;j<i;j++){
            if(strcmp(arr[j],arr[i])==0){
                printf("Word once used. GAME OVER!  ");
                flag=1;
                exit(0);
                break;
            }
        }

        if(flag==0){
            if(arr[i][0] == arr[i-1][strlen(arr[i-1])-1]){
                printf("Next word.\n");
                i++;
            }
            else{
                printf("Word first character doesnot match the last character of last word.");
                break;
            }
        }
        

    }
    return 0;
}