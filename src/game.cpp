#include "game.hpp"

// retourne le nombre de lignes supprimées
void lineFullHandler(Grid& grid, bool test, int& score){
    std::vector<std::vector<char>> state = grid.getState();
    int nbLinesFull = 0;
    for(int i = 0; i<lignes; ++i){
        std::vector<char> line = state[i];
        if(isFull(line) == true && test == true){
            nbLinesFull += 1;
            grid.clearLine(i);
            for (int k = i-1; k>=0; --k){
                grid.downLine(k);
            }
            grid.clearLine(0);
        }
    }
    score += calculScore(nbLinesFull);
    
}

bool isFull(std::vector<char> line){
    for(int j = 0; j < colonnes; ++j){
        if(line[j] == '.'){
            return false;
        }
    }
    return true;
}

int calculScore(int nbLinesFull){
    int score;
    switch(nbLinesFull){
        case 0 :
            score = 0;
            break;
        case 1 :
            score = 40;
            break;
        case 2 :
            score = 100;
            break;
        case 3 :
            score = 300;
            break;
        case 4 :
            score = 1200;
            break;
    }
    return score;
}

// Si test = true, génère une autre pièce et la considère comme pièce courante (=celle qu'on manipule)
void nextStep(Piece& piece, bool test){
    if(test == true){
        piece = generateRandomPiece(4,0);
    }
}

