#include <iostream>
#include <SFML/Graphics.hpp>

#include "input.hpp"
#include "grid.hpp"
#include "piece.hpp"
#include "game.hpp"

// NAMESPACE
using namespace sf;

// CONSTANTES
const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;

// PROTOTYPES
void LoadFont();
void SetScore(Text& txt, int score);
void CheckBtn(Piece& piece, Grid& grid, bool& test);