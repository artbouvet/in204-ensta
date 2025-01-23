#include "main.hpp"

// Variables globales
Font font;
Text txt;
char temp[256];

RenderWindow window;
Input input;




int main(){

    window.create(VideoMode(WIN_WIDTH,WIN_HEIGHT),"My TETRIS");
    window.setVerticalSyncEnabled(true);

    int score = 0;

    //Affichage Score
    LoadFont();
    SetScore(txt, score);

    Clock clock;


    Piece piece = generateRandomPiece(4,0);


    Grid grid(lignes, colonnes);
    grid.placePiece(piece);

    
    bool test = 0;

    while(window.isOpen()){
        
        
        SetScore(txt, score);
        Event event;

        nextStep(piece, test);
        lineFullHandler(grid, test, score);
        
        if (clock.getElapsedTime().asMilliseconds()>=300){
            test = grid.movePiece(piece, 0,1);
            clock.restart();
        }

        while(window.pollEvent(event)){
            input.InputHandler(event, window);
            CheckBtn(piece, grid, test);
        }
    
        window.clear(Color::Black);

        // Elements à afficher
        drawGrid(window,grid);
        window.draw(txt);
        

        // Dessiner à l'écran les éléments
        window.display();

        
    }

    return 0;
}

// Chargement de la police d'écriture
void LoadFont(){
    if(!font.loadFromFile("res/Poppins-Regular.ttf")){
        std::cout << "Erreur chargement font" << std::endl;
    }
}

// Création texte
void SetScore(Text& txt, int score){
    txt.setPosition(400,50);
    txt.setFont(font);


    sprintf(temp, "%d", score);
    txt.setString(temp);


    txt.setCharacterSize(26);
    txt.setFillColor(Color::White);
    txt.setStyle(Text::Bold);

}

void CheckBtn(Piece& piece, Grid& grid, bool& test){

    static bool spacePressedPreviously = false; // Résolution du problème de rotation où la fonction rotatePiece() est appelée 2 fois à chaque appui sur entrée : essayer de comprendre pourquoi plus tard
    std::vector<Case> cases = piece.getCases();

    if(input.getButton().left == true){
        test = grid.movePiece(piece, -1, 0);
    }
    if(input.getButton().right == true){
        test = grid.movePiece(piece, 1, 0);
    }
    if(input.getButton().up == true){
        test = grid.movePiece(piece, 0, -1);
    }
    if(input.getButton().down == true){
        while(!test){
            test = grid.movePiece(piece, 0,1);
        }
    }
    if(input.getButton().space == true && !spacePressedPreviously){
        grid.rotatePiece(piece);
    }
    spacePressedPreviously = input.getButton().space;
}

