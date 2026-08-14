#include <iostream>

#include "./game/tictactoe.cpp"

int main(){
    char board[SIZE] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int opt = 1;
    std::cout << "\nStockfish for tic-tac-toe\n" << std::endl;
    std::cout << "Board state:\n" << std::endl;
    drawBoard(board);
    while(opt != -1){   
        if(LAST_PLAYER == 'x'){
            std::cout << "Player o's turn." << std::endl;
            int availableMoves;
            for(int i = 0; i < SIZE; i++){
                if(board[i] == 0){
                    availableMoves++;
                }
            }
            
            int aiMove = makeAIMove(board);
            if(aiMove != -1){
                makeMove(board, aiMove, 'o');
                LAST_PLAYER = 'o';
            }
        }
        else{
            std::cout << "Player x's turn." << std::endl;
            std::cout << "Choose your move: (0-8)\n" << std::endl;
            scanf("%d", &opt);
            makeMove(board, opt, 'x');
            LAST_PLAYER = 'x';
        }
        
        drawBoard(board);
        char winner = wins(board);
        if(winner != 0 && winner != 'd'){
            std::cout << "Player " << winner << " wins!" << std::endl;
            opt = -1;
        }
        if(winner == 'd'){
            std::cout << "It's a draw!" << std::endl;
            opt = -1;
        }
    }
    return 0;
}