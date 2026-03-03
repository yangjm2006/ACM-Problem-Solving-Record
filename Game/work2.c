#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 3
void initBoard(char board[SIZE][SIZE]) {
   for(int i=0;i<SIZE;i++)
       for(int j=0;j<SIZE;j++)
           board[i][j] = ' ';
}
void printBoard(char board[SIZE][SIZE]) {
   printf("+---+---+---+\n");
   for(int i=0;i<SIZE;i++) {
       printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
       printf("+---+---+---+\n");
   }
}
int isFull(char board[SIZE][SIZE]) {
   for(int i=0;i<SIZE;i++)
       for(int j=0;j<SIZE;j++)
           if(board[i][j] == ' ') return 0;
   return 1;
}
char checkWin(char b[SIZE][SIZE]) {
   for(int i=0;i<SIZE;i++) {
       if(b[i][0] != ' ' && b[i][0]==b[i][1] && b[i][1]==b[i][2]) return b[i][0];
       if(b[0][i] != ' ' && b[0][i]==b[1][i] && b[1][i]==b[2][i]) return b[0][i];
   }
   if(b[0][0] != ' ' && b[0][0]==b[1][1] && b[1][1]==b[2][2]) return b[0][0];
   if(b[2][0] != ' ' && b[2][0]==b[1][1] && b[1][1]==b[0][2]) return b[2][0];
   if(isFull(b)) return 'q';
   return ' ';
}
void playerMove(char board[SIZE][SIZE]) {
   int r,c;
   while(1) {
       printf("请输入坐标(row col)：");
       scanf("%d %d",&r,&c);
       if(r>=0 && r<SIZE && c>=0 && c<SIZE && board[r][c]==' ') {
           board[r][c]='x';
           break;
       }
       printf("输入无效，请重试！\n");
   }
}
void computerMove(char board[SIZE][SIZE]) {
   int r,c;
   while(1) {
       r = rand()%SIZE; c = rand()%SIZE;
       if(board[r][c]==' ') { board[r][c]='o'; break; }
   }
}
int main() {
   srand((unsigned)time(NULL));
   char board[SIZE][SIZE];
   char winner = ' ';
   initBoard(board);
   while(1) {
       printBoard(board);
       playerMove(board);
       winner = checkWin(board);
       if(winner != ' ') break;
       computerMove(board);
       winner = checkWin(board);
       if(winner != ' ') break;
   }
   printBoard(board);
   if(winner=='x') printf("恭喜你赢了！\n");
   else if(winner=='o') printf("你输了！\n");
   else printf("平局！\n");
   return 0;
}