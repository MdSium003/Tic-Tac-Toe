#include <stdio.h>

int Winner(int check[15]) {
    if(check[1-1] == check[2-1] && check[1-1] == check[3-1]) {
        return check[1-1];
    }
    if(check[4-1] == check[5-1] && check[4-1] == check[6-1]) {
        return check[4-1];
    }
    if(check[7-1] == check[8-1] && check[7-1] == check[9-1]) {
        return check[7-1];
    }
    if(check[1-1] == check[4-1] && check[1-1] == check[7-1]) {
        return check[1-1];
    }
    if(check[2-1] == check[5-1] && check[2-1] == check[8-1]) {
        return check[2-1];
    }
    if(check[3-1] == check[6-1] && check[3-1] == check[9-1]) {
        return check[3-1];
    }
    if(check[1-1] == check[5-1] && check[1-1] == check[9-1]) {
        return check[1-1];
    }
    if(check[3-1] == check[5-1] && check[3-1] == check[7-1]) {
        return check[3-1];
    }
    return 0;
}

void Print(int check[15])
{
    printf("\n\n");
    int i,j;
    for(i=0;i<9;i++) {
        if(check[i] == 0) {
            printf("   ");
        }
        else if(check[i] == 1) {
            printf(" X ");
        }
        else if(check[i] == 2) {
            printf(" O ");
        }
        if((i+1) % 3 != 0) {
            printf("|");
        }
        else if((i+1) != 9){
            printf("\n");
            for(j=0;j<11;j++) {
                printf("-");
            }
            printf("\n");
        }
        else {
            printf("\n\n\n\n");
        }
    }
}

int main ()
{
    printf("Welcome to Tic Tac Toe Game\n      A Classic Game\n\n");
    int i,ans,winner = 0;
    int check[15];
    for(i=0;i<15;i++) {
        check[i] = 0;
    }
    Print(check);
    printf(" *Adust the Window For Better Experience* \n\n\n");
    for(i=0;i<9;i++) {
        if(i == 0 || i %2 == 0) {
            printf("First Player Move : ");
            scanf("%d", &ans);
            while(check[ans-1] != 0 || ans>9 || ans<1) {
                printf("Wrong Move. Please give a good move : ");
                scanf("%d", &ans);
            }
            check[ans-1] = 1;
        }
        else {
            printf("Second Player Move : ");
            scanf("%d", &ans);
            while(check[ans-1] != 0 || ans>9 || ans<1) {
                printf("Wrong Move. Please give a good move : ");
                scanf("%d", &ans);
            }
            check[ans-1] = 2;
        }
        Print(check);
        if(i>=4) {
            winner = Winner(check);
            if(winner == 1) {
                printf("       **** Game Over ****\n  First Player is the Winner of\n      The Chicken Dinner \n\n\n");
                return 0;
            }
            else if(winner == 2) {
                printf("       **** Game Over ****\n  Second Player is the Winner of\n      The Chicken Dinner \n\n\n");
                return 0;
            }
        }
    }
    return 0;
}
