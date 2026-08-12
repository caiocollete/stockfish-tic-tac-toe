#include "rules.h"

char canPlay(int row, int col, char player){    
    if(LAST_PLAYER == player){
        return 0;
    }
    if(board[row][col] != 0){
        return 0;
    }

    return 1;
}

char wins(){
    if(board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != 0){
        return board[0][0];
    }
    if(board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != 0){
        return board[1][0];
    }
    if(board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != 0){
        return board[2][0];
    }
    if(board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != 0){
        return board[0][0];
    }
    if(board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != 0){
        return board[0][1];
    }
    if(board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != 0){
        return board[0][2];
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != 0){
        return board[0][0];
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0){
        return board[0][2];
    }

    return 0;
}