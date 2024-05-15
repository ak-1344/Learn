#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char words[5][8];
    for (int i = 0; i < 5; i++)
    {
        scanf("%s", &words[i]);
    }
    printf("Choose a random number bw 1 and 5: ");
    int choice;
    scanf("%d", &choice);
    choice--;

    int count;
    char *guess;
    for (int i = 0; i < 8; i++)
    {
        if (words[choice][i] != '\0')
        {
            guess[i] = '*';
        }
    }
    printf("%s",guess);
    while (1)
    {
        if (strcmp(guess, words[choice]) == 0)
        {
            printf("You got it!! Congrats");
            break;
        }
        getchar();
        char temp;
        printf("\n Guess the letter from the word: ");
        scanf("%c", &temp);
        count++;
        int temp_c = 0;
        for (int i = 0; i < 8; i++)
        {
            if (words[choice][i] != '\0')
            {
                if (words[choice][i] == temp)
                {
                    temp_c++;
                    
                    guess[i] = temp;
                }
            }
        }
        if(temp_c ==0){
            printf("No letter matched..");
        }else{
            printf("%s",guess);
        }
    }
}