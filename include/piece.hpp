#ifndef piecesHPP
#define piecesHPP

#include <iostream>
#include <vector>

typedef unsigned int uint;

class Case{
    private:
        uint x,y;
        uint filled; 
    
    public:
        Case(uint theX=0, uint theY=0, bool isFilled=false) : x(theX), y(theY), filled(isFilled){}

        uint getX() const {return x;}
        uint getY() const {return y;}
        bool isFilled() const {return filled;}

        void setX(uint theX){x = theX;}
        void setY(uint theY){y = theY;}
        void setFilled(bool theFilled){filled = theFilled;}
};

class Piece{
    private:
        std::vector<Case> cases;
        char type; //Type de pièces ('I','O','T','L','J','Z','S')
        int rotationState; //Entier compris entre 0 et 3 pour différencier les 3 états de rotation
    public:
        Piece(char type, uint startX, uint startY) : type(type){initialization(startX, startY, 0);}

        void initialization(uint startX, uint startY, int rotationState);

        std::vector<Case> getCases() const{return cases;}
        char getType() const {return type;}

        int getRotationState() const {return rotationState;}

        // Vérifie si une case appartient à cette pièce
        bool belong(Case C1) const;

        uint getMinX();
        uint getMaxX();
        uint getMinY();
        uint getMaxY();

        // Calculer le centre géométrique de la pièce = pivot pour la rotation
        /*Case getPivot() const {
            uint sumX = 0, sumY = 0;
            uint numCases = cases.size();

            for (const Case& c : cases) {
                sumX += c.getX();
                sumY += c.getY();
            }

            // Calcul des moyennes
            uint pivotX = static_cast<uint>(std::round(static_cast<double>(sumX) / numCases));
            uint pivotY = static_cast<uint>(std::round(static_cast<double>(sumY) / numCases));

            return Case(pivotX, pivotY, false);

        }
*/

        void move(int dx, int dy);

        // rotation en sens horaire
        void rotate();

               
};





#endif