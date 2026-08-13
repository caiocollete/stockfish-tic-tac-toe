#include "rules.h"

char canPlay(int pos, char player){    
    if(LAST_PLAYER == player){
        return 0;
    }
    if(board[pos] != 0){
        return 0;
    }

    return 1;
}

char wins(){
    
    for(int i = 0; i < 3; i++){
        if(board[i] == board[i+3] && board[i+3] == board[i+6] && board[i] != 0){
            return board[i];
        }
    }

    for(int i = 0; i < 9; i+=3){
        if(board[i] == board[i+1] && board[i+1] == board[i+2] && board[i] != 0){
            return board[i];
        }
    }

    if(board[0] == board[4] && board[4] == board[8] && board[0] != 0){
        return board[0];
    }
    if(board[2] == board[4] && board[4] == board[6] && board[0] != 0){
        return board[2];
    }

    return 0;
}