#include <stdio.h>

int main() {
    char b[3][3], p = 'X';
    int i, j, r, c, win = 0, moves = 0;

    // initialize board
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            b[i][j]=' ';

    while(moves<9 && win==0) {
        // display board
        for(i=0;i<3;i++) {
            for(j=0;j<3;j++)
                printf("%c ", b[i][j]);
            printf("\n");
        }

        // input
        printf("Player %c (row col): ", p);
        scanf("%d %d", &r, &c);

        if(r<0||r>2||c<0||c>2||b[r][c]!=' ') {
            printf("Invalid!\n");
            continue;
        }

        b[r][c] = p;
        moves++;

        // check win
        for(i=0;i<3;i++) {
            if(b[i][0]==p && b[i][1]==p && b[i][2]==p) win=1;
            if(b[0][i]==p && b[1][i]==p && b[2][i]==p) win=1;
        }
        if(b[0][0]==p && b[1][1]==p && b[2][2]==p) win=1;
        if(b[0][2]==p && b[1][1]==p && b[2][0]==p) win=1;

        if(win==1) {
            printf("Player %c wins!\n", p);
            break;
        }

        p = (p=='X') ? 'O' : 'X';
    }

    if(win==0)
        printf("Draw!\n");

    return 0;
}
