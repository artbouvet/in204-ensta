#include "grid.hpp"

void Grid::empty() {
        state.clear();
        state.resize(Hauteur, std::vector<char>(Largeur, '.'));
    }

void Grid::placePiece(const Piece& piece) {
        char T = piece.getType();
        for (Case C : piece.getCases()) {
            int x = C.getX();
            int y = C.getY();
            state[y][x] = T; // Utilise le type de la pièce comme symbole
        }
    }

void Grid::clearPiece(const Piece& piece) {
        for (Case C : piece.getCases()) {
            int x = C.getX();
            int y = C.getY();
            state[y][x] = '.'; // Réinitialise en '.'
        }
    }

bool Grid::movePiece(Piece& piece, int dx, int dy) {
        // Vérification si chaque case de la pièce reste dans les limites après le déplacement
        for (const Case& C : piece.getCases()) {
            int newX = C.getX() + dx;
            int newY = C.getY() + dy;
            if (newX < 0 || newX >= Largeur || newY < 0 || newY >= Hauteur) {
                return false;
            }
        }
        // Gestion des collisions si mouvement vers le bas
        if (dy == 1) { // Mouvement vers le bas
            for (const Case& C : piece.getCases()) {
                uint newX = C.getX() + dx;
                uint newY = C.getY() + dy;
                Case newCase(newX,newY);

                // Vérifier la case en dessous
                if (newY < Hauteur) {
                    // Vérifier si la case en dessous est déjà occupée par une pièce de type différent
                    if (state[newY][newX] != '.' && state[newY][newX] != piece.getType()) {
                        return true; // Si la case en dessous est occupée par une autre pièce, on bloque le mouvement
                    }
                    // Vérifier si la case en dessous est déjà occupée par une pièce de même type
                    
                    else if(state[newY][newX] == piece.getType() && piece.belong(newCase) == false){
                        return true;
                    }
                }
            }
    }
        // Gestion des colissions si mouvement vers la gauche
        if (dx == -1) {
                for (const Case& C : piece.getCases()) {
                    uint newX = C.getX() + dx;
                    uint newY = C.getY() + dy;
                    Case newCase(newX,newY);

                    // Vérifier la case en dessous
                    if (newX >= 0) {
                        // Vérifier si la case à gauche est déjà occupée par une pièce de type différent
                        if (state[newY][newX] != '.' && state[newY][newX] != piece.getType()) {
                            return false; // Si la case en dessous est occupée par une autre pièce, on bloque le mouvement
                        }
                        // Vérifier si la case en dessous est déjà occupée par une pièce de même type
                        
                        else if(state[newY][newX] == piece.getType() && piece.belong(newCase) == false){
                            return false;
                        }
                    }
                }
        }

        // Gestion des colissions si mouvement vers la droite
        if (dx == +1) { 
                for (const Case& C : piece.getCases()) {
                    uint newX = C.getX() + dx;
                    uint newY = C.getY() + dy;
                    Case newCase(newX,newY);

                    // Vérifier la case en dessous
                    if (newX < Largeur) {
                        // Vérifier si la case à gauche est déjà occupée par une pièce de type différent
                        if (state[newY][newX] != '.' && state[newY][newX] != piece.getType()) {
                            return false; // Si la case en dessous est occupée par une autre pièce, on bloque le mouvement
                        }
                        // Vérifier si la case en dessous est déjà occupée par une pièce de même type
                        
                        else if(state[newY][newX] == piece.getType() && piece.belong(newCase) == false){
                            return false;
                        }
                    }
                }
        }
        // Si aucune case n'est en dehors, on effectue le déplacement
        clearPiece(piece);
        piece.move(dx, dy);
        placePiece(piece);

        if(dy==1 && piece.getMaxY() >= Hauteur -1){
            return true;
        }
        return false;
    }

bool Grid::rotatePiece(Piece& piece) {
        /*
        std::vector<Case> cases = piece.getCases();
        uint pivotX = cases[0].getX();
        uint pivotY = cases[0].getY();
        // Vérification si chaque case de la pièce reste dans les limites après le déplacement
        for (const Case& C : piece.getCases()) {
            uint newX = pivotX - (C.getY() - pivotY);
            uint newY = pivotY + (C.getX() - pivotX);
            if (newX < 0 || newX >= Largeur || newY < 0 || newY >= Hauteur) {
                return false;
            }
        }
        // Gestion des collisions
        for (const Case& C : piece.getCases()) {
            uint newX = pivotX - (C.getY() - pivotY);
            uint newY = pivotY + (C.getX() - pivotX);
            Case newCase(newX,newY);
        // Vérifier si la nouvelle case est déjà occupée par une pièce de type différent
            if (state[newY][newX] != '.' && state[newY][newX] != piece.getType()) {
                return true; // Si la case en dessous est occupée par une autre pièce, on bloque le mouvement
            }
            // Vérifier si la nouvelle case est déjà occupée par une pièce de même type
                    
            else if(state[newY][newX] == piece.getType() && piece.belong(newCase) == false){
                return true;
            }
        }*/
        
        // Si aucune case n'est en dehors, on effectue le déplacement

        clearPiece(piece);
        std::vector<Case> cases = piece.getCases();
        uint pivotX = cases[0].getX();
        uint pivotY = cases[0].getY();

        Piece newPiece = piece;

        int newRotationState = (piece.getRotationState()+1)%4;
        
        newPiece.initialization(pivotX,pivotY,newRotationState);

        piece.rotate();
        placePiece(piece);
/*
        if(dy==1 && piece.getMaxY() >= Hauteur -1){
            return true;
        }*/
        return false;
    }

void Grid::clearLine(int line){
        for (int col=0; col < Hauteur; ++col){
            state[line][col] = '.'; // Réinitialise en '.'
        }
    }
void Grid::downLine(int i){ //i correspond à l'indice de la ligne que l'on souhaite descendre d'un rang
        state[i+1] = state[i];
    }

void drawGrid(RenderWindow& window, Grid grid){
    std::vector<std::vector<char>> gridState = grid.getState();
    Color color;
 
    for(int i = 0; i < lignes; ++i){
        for(int j = 0; j< colonnes; ++j){

            switch(gridState[i][j]){
                case '.':
                    color = Color::Black;
                    break;
                case 'I':
                    color = Color::Red;
                    break;
                case 'O':
                    color = Color::Blue;
                    break;
                case 'L':
                    color = Color::Green;
                    break;
                case 'J':
                    color = Color::Red;
                    break;
                case 'T':
                    color = Color::Cyan;
                    break;
                case 'Z':
                    color = Color::Yellow;
                    break;
                case 'S':
                    color = Color::Magenta;
                    break;
    }

            RectangleShape Cell(Vector2f(caseSize-1, caseSize-1));
            Cell.setPosition(j*caseSize, i*caseSize);
            Cell.setFillColor(color);
            Cell.setOutlineColor(Color::White);
            Cell.setOutlineThickness(1);
            window.draw(Cell);
        }
    }
}

void drawPiece(RenderWindow& window, Piece piece){
    std::vector<Case> cases = piece.getCases();
    char type = piece.getType();

    Color color;
    switch(type){
        case 'I':
            color = Color::Red;
            break;
        case 'O':
            color = Color::Blue;
            break;
        case 'L':
            color = Color::Green;
            break;
        case 'J':
            color = Color::Red;
            break;
        case 'T':
            color = Color::Cyan;
            break;
        case 'Z':
            color = Color::Yellow;
            break;
        case 'S':
            color = Color::Magenta;
            break;
    }

    for(int i = 0; i<4; ++i){
        uint x = cases[i].getX();
        uint y = cases[i].getY();

        

        RectangleShape Cell(Vector2f(caseSize-1, caseSize-1));
        Cell.setPosition(x*caseSize, y*caseSize);
        Cell.setFillColor(color);
        Cell.setOutlineColor(Color::White);
        Cell.setOutlineThickness(1);

        window.draw(Cell);
    }
}

Piece generateRandomPiece(uint x, uint y){
    // Tirage d'un entier entre 1 et 7
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 7);
    int i = distrib(gen);
    
    if(i == 1){
        Piece piece('I',x,y);
        return piece;
    }
    else if(i == 2){
        Piece piece('O',x,y);
        return piece;
    }
    else if(i == 3){
        Piece piece('T',x,y);
        return piece;
    }
    else if(i == 4){
        Piece piece('L',x,y);
        return piece;
    }
    else if(i == 5){
        Piece piece('J',x,y);
        return piece;
    }
    else if(i == 6){
        Piece piece('S',x,y);
        return piece;
    }
    else if(i == 7){
        Piece piece('Z',x,y);
        return piece;
    }
}