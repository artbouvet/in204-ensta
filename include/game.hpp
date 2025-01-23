#ifndef GAMEHPP
#define GAMEHPP

#include "piece.hpp"
#include "grid.hpp"

void lineFullHandler(Grid& grid, bool test, int& score);
bool isFull(std::vector<char> line);
int calculScore(int nbLinesFull);

void nextStep(Piece& piece, bool test);

#endif
