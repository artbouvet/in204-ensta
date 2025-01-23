#ifndef GRIDHPP
#define GRIDHPP

#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>

#include "piece.hpp"
 
// NAMESPACE
using namespace sf;

class Grid {
private:
    uint Hauteur, Largeur;
    std::vector<std::vector<char>> state; // Matrice 2D de la grille - Etat de la grille

public:
    Grid(uint H, uint L) : Hauteur(H), Largeur(L) {
        state.resize(Hauteur, std::vector<char>(Largeur, '.'));
    }

    void empty();

    std::vector<std::vector<char>> getState() const {return state;}
    void setState(std::vector<std::vector<char>> theState){state = theState;}

    // Place une pièce dans la grille
    void placePiece(const Piece& piece);

    void clearPiece(const Piece& piece);

    bool movePiece(Piece& piece, int dx, int dy);

    bool rotatePiece(Piece& piece);
    
    void clearLine(int line);

    void downLine(int i);
    
};

// CONSTANTES
const int lignes = 20;
const int colonnes = 10;
const int caseSize = 30;

// PROTOTYPE
void drawGrid(RenderWindow& window, Grid grid);
void drawPiece(RenderWindow& window, Piece piece);
Piece generateRandomPiece(uint x, uint y);



#endif