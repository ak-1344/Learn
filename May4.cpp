#include<stdio.h>

void print(char arr[3][3]) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%c ", arr[i][j]);
        }
        printf("\n");
    }
}

int check(char arr[3][3]) {
    int check = 0;
    for(int i=0; i<3; i++) {
        if(arr[i][0]==arr[i][1] && arr[i][1]==arr[i][2] && arr[i][0]!='_') check = 1;
        if(arr[0][i]==arr[1][i] && arr[1][i]==arr[2][i] && arr[0][i]!='_') check = 1;
    }
    if(arr[0][0]==arr[1][1] && arr[1][1]==arr[2][2] && arr[0][0]!='_') check = 1;
    if(arr[0][2]==arr[1][1] && arr[1][1]==arr[2][0] && arr[0][2]!='_') check = 1;
    return check;
}

int main() {
    int p[9][2]={{0,0},{0,1},{0,2},
                 {1,0},{1,1},{1,2},
                 {2,0},{2,1},{2,2}};
    char arr[3][3] = { {'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'} };
    int flag = 0;
    printf("\nWelcome to the TicTacToe Game.\n");
    printf("The First player represents 0. \nThe Second player represents x.\n\n");
    printf("To play the game, \nPlayer have to specify the position to place its marker.\n");
    printf("Positions are \n1 2 3\n4 5 6\n7 8 9\n");
    int position[9]={-1,-1,-1,-1,-1,-1,-1,-1,-1};



    while(flag==0) {
        int i=0;
        flag = check(arr);
        if(i==9){
        printf("All boxes filled.\nNo one wins. DRAW!!\nPlease restart the game.");
        break;}
        if(flag==1) {
            printf("Player 1 wins!\n");
            break;
        }
        int a;


        printf("Player 1, Please enter the position: ");
        scanf("%d", &a);
        if(a<1 || a>9){ printf("Error input. Please enter correct position."); flag=1;}
        for(int j=0;j<9;j++){
            if(position[j]==a){
                printf("Position used, ERROR input. Please restart the game.\n");
                flag=1;
                break;
            }
        }
        position[i]=a;
        i++;
        a--;
        if(i==9){
        printf("All boxes filled.\nNo one wins. DRAW!!\nPlease restart the game.");
        break;}
        if(flag==1) break;
        arr[p[a][0]][p[a][1]] = '0';
        print(arr);

        flag = check(arr);
        if(flag==1) {
            printf("Player 1 wins!\n");
            break;
        }




        printf("Player 2, Please enter the position: ");
        scanf("%d", &a);
        if(a<1 || a>9){ printf("Error input. Please enter correct position."); flag=1;}
        for(int j=0;j<9;j++){
            if(position[j]==a){
                printf("Position used, ERROR input. Please restart the game.\n");
                flag=1;
                break;
            }
        }
        if(i==9){
        printf("All boxes filled.\nNo one wins. DRAW!!\nPlease restart the game.");
        break;}
        position[i]=a;
        i++;
        a--;

        if(flag==1) break;
        arr[p[a][0]][p[a][1]] = 'x';
        print(arr);

        flag = check(arr);
        if(flag==1) {
            printf("Player 2 wins!\n");
            break;
        }
    }    
    return 0;
}