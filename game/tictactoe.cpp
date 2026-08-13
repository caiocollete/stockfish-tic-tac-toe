#include <iostream>
#include <cstdlib>

#include "./rules/rules.cpp"

char makeMove(int pos){
    char player = (LAST_PLAYER == 'x') ? 'o' : 'x';
    if(canPlay(pos, player)){
        board[pos] = player;
        LAST_PLAYER = player;
        return 1;
    }
    return 0;
}

void generateMove(){
    srand(time(0));
    int pos = rand() % SIZE;
    while(!makeMove(pos)){
        pos = rand() % SIZE;
    }
}

void drawBoard(){
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

// retorna a ser jogada pelo jogador atual
/*int minimax(int depth, char player){
    if(wins() != 0 || depth == 0){
        -1;
    }
    else if(player == 'x'){
                α = +∞
        PARA CADA filho DE nó
            α = min(α, minimax(filho, profundidade-1))
        FIM PARA
        RETORNE α
    }
    else{
        α = -∞
        PARA CADA filho DE nó
            α = max(α, minimax(filho, profundidade-1))
        FIM PARA
        RETORNE α
    }

    return -1;
}*/