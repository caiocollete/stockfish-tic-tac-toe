#include <iostream>
#include <cstdlib>
#include <algorithm>

#include "./rules/rules.cpp"

char makeMove(char board[], int pos, char player){
    if(canPlay(board, pos, player)){
        board[pos] = player;
        return 1;
    }
    return 0;
}


void drawBoard(char board[]){
    for(int i = 0; i < SIZE; i++){
        if(i % 3 == 0 && i != 0){
            std::cout << std::endl;
        }
        if(board[i] == 0){
            std::cout << "-";
        }
        else{
            std::cout << board[i];
        }
    }
    std::cout << std::endl;
}

int minimax(char board[], int depth, bool isMaximizing){
    char winner = wins(board);
    if(winner == 'o'){
        return 10 - depth;
    }
    else if(winner == 'x'){
        return depth - 10;
    }
    else if(winner == 'd'){
        return 0;
    }

    if(isMaximizing){
        int bestScore = -1000;
        for(int i = 0; i < SIZE; i++){
            if(board[i] == 0){
                board[i] = 'o';
                int score = minimax(board, depth + 1, false);
                board[i] = 0;
                bestScore = std::max(score, bestScore);
            }
        }
        return bestScore;
    }
    else{
        int bestScore = 1000;
        for(int i = 0; i < SIZE; i++){
            if(board[i] == 0){
                board[i] = 'x';
                int score = minimax(board, depth + 1, true);
                board[i] = 0;
                bestScore = std::min(score, bestScore);
            }
        }
        return bestScore;
    }
}

int makeAIMove(char board[]){
    int bestScore = -1000;
    int move = -1;
    for(int i = 0; i < SIZE; i++){
        if(board[i] == 0){
            board[i] = 'o';
            int score = minimax(board, 0, false);
            board[i] = 0;
            if(score > bestScore){
                bestScore = score;
                move = i;
            }
        }
    }
    return move;
}