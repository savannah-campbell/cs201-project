/*
The createBoard class is used to create the board that the player will see and
transfer the necessary information that it takes in to the class that checks
for wins and creates the actual game mechanics. This class makes the UI easier
to maintain rather than working through the linked list and graph each time.
*/
#include <stdio.h>
#include <ctype.h>
#include "setPiece.c"

//This function initializes the board array that the user will see.
void fillBoard(int x, int y, char board[x][y]){
  for(int i = 0; i < x; i++){
    for(int j = 0; j <= y; j++){
      if(j%2 == 0)
        board[i][j] = '|';
      else
          board[i][j] = ' ';
    }
  }
}

void printBoard(int x, int y, char print[x][y]){
  for(int i = 0; i < x; i++){
    for(int j = 0; j <= y; j++)
      printf("%c", print[i][j]);
    printf("\n");
  }
}

void printNum(int x, int print[x]){
  for(int i = 0; i < x; i++){
    if(i < 10)
      printf(" %d", print[i]);
    else
      printf("%d", print[i]);
  }
}


int generateBoard(void){
  int width, height;

  //This loop gets a valid size for the board
  while(1){
    char answer = ' ';
    printf("\nWhat is the height of the board?");
    scanf("%d", &height);
    printf("\nWhat is the width of the board?");
    scanf("%d", &width);
    if(height < 4 || width < 4)
      printf("\nThe height and width must be greater than or equal to 4.\nTry again.\n");
    else if(height > 40 || width > 40){
      printf("\nBoard sizes greater than 40x40 will have unweildy screen handling.");
      printf("\nDo you wish to continue anyway (Y/N)?");
      scanf("%c", &answer);
      answer = tolower(answer);
      if(answer == 'y')
        break;
    }
    else
      break;
  }

  int y = width*2;

  char board[height][y];
  int rowNum[width]; //this will help the player know what row they're dropping the piece in
  int num = 1;

  //This loop fills rowNum bc I don't want to make a function for it.
  for(int i = 0; i < width; i++)
  {
    rowNum[i] = num;
    num++;
  }

  fillBoard(height, y, board);
  int win = 0;
  while(win == 0){
    printBoard(height, y, board);
    printNum(width, rowNum);
    printf("\nPlayer One's Turn:");
    win = placePiece(chooseRow(y), height, y, board, 1);
    if(win != 0)
      break;
    printBoard(height, y, board);
    printNum(width, rowNum);
    printf("\nPlayer Two's Turn: ");
    win = placePiece(chooseRow(y), height, y, board, 2);
  }

  printBoard(height, y, board);
  printNum(width, rowNum);

//  playerOne(y, height, board);
  return win;
}


/*
void playerOne(int width, int height, char board[height][width]){
  placePiece(chooseRow(width), height, width, board);
  printBoard(height, width, board);
}
*/
