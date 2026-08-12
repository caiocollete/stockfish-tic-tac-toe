#include <iostream>

#include "./game/tictactoe.cpp"

int main(){
    int opt = 1;
    std::cout << "\nStockfish for tic-tac-toe\n" << std::endl;
    while(opt != 0){
        std::cout << "Board state:\n" << std::endl;
        drawBoard();
        std::cout << "Press 1 to generate a move or 0 to quit\n" << std::endl;
        scanf("%d", &opt);
        
        if(opt == 1){
            generateMove();
            char winner = wins();
            drawBoard();
            if(winner != 0){
                std::cout << "Player " << winner << " wins!" << std::endl;
                opt = 0;
            }
        }
    }
    return 0;
}