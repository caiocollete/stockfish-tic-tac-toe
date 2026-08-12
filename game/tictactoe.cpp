#include <iostream>
#include <cstdlib>

#include "./rules/rules.cpp"

void generateMove(){
    srand(time(0));
    int row, col;
    char player = (LAST_PLAYER == 'x') ? 'o' : 'x';
    char isValid = 0;
    while(!isValid){
        row = rand() % SIZE;
        col = rand() % SIZE;
        isValid = canPlay(row, col, player);
    }
    board[row][col] = player;
    LAST_PLAYER = player;
}

void drawBoard(){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(board[i][j] == 0){
                std::cout << "-";
            } else {
                std::cout << board[i][j];
            }
        }
        std::cout << std::endl;
    }
}