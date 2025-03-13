#include<stdio.h>
#include<stdint.h>
#include<stdbool.h>

#define CELLC 100
#define SIMC 100

int main(void){
  uint8_t mask = 110;
  bool board[SIMC][CELLC] = {};
  board[0][CELLC - 1] = 1;
  

  for(int i = 0; i < SIMC - 1; i ++){
    
    for(int j = 1; j < CELLC - 1; j ++){
      uint8_t bitshifts = 4 * board[i][j - 1] + 2 * board[i][j] + board[i][j+1];
      board[i+1][j] = (mask >> bitshifts) & 1;
    }

    for(int j = 0; j < CELLC; j ++){
      printf("%c", board[i][j] ? 'X' : ' ');
    }
    printf("\n");
  }
}


