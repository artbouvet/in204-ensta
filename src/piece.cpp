#include "piece.hpp"

void Piece::initialization(uint startX, uint startY, int rState){
            rotationState = rState;
            cases.clear();
            if (type == 'I' && (rotationState == 0 || rotationState == 2)) {
                for (int j = 0; j < 4; ++j) {
                    Case C(startX, startY + j);
                    cases.push_back(C);
                }
            }

            else if (type == 'I' && (rotationState == 1 || rotationState == 3)) {
                for (int i = 0; i < 4; ++i) {
                    Case C(startX +i, startY);
                    cases.push_back(C);
                }
            }

            else if(type == 'O'){
                for(int j=0; j<2; ++j){
                    for(int i=0; i<2; ++i){
                        Case C(startX+i,startY+j);
                        cases.push_back(C);
                    }}
            }
            else if(type == 'T' && rotationState == 0){
                for(int j=0; j<3; ++j){
                    Case C(startX, startY+j);
                    cases.push_back(C);
                }
                Case C(startX+1,startY+1);
                cases.push_back(C);
            }
            else if(type == 'T' && rotationState == 1){
                for(int i=0; i<3; ++i){
                    Case C(startX+i, startY);
                    cases.push_back(C);
                }
                Case C(startX+1,startY+1);
                cases.push_back(C);
            }
            else if(type == 'T' && rotationState == 2){
                for(int j=0; j<3; ++j){
                    Case C(startX+1, startY+j);
                    cases.push_back(C);
                }
                Case C(startX,startY+1);
                cases.push_back(C);
            }
            else if(type == 'T' && rotationState == 3){
                for(int i=0; i<3; ++i){
                    Case C(startX+i, startY+1);
                    cases.push_back(C);
                }
                Case C(startX+1,startY);
                cases.push_back(C);
            }
            else if(type == 'L'  && rotationState == 0){
                for(int j=0; j<3; ++j){
                    Case C(startX, startY+j);
                    cases.push_back(C);
                }
                Case C(startX+1,startY);
                cases.push_back(C);
            }
            else if(type == 'L'  && rotationState == 1){
                for(int i=0; i<3; ++i){
                    Case C(startX+i, startY);
                    cases.push_back(C);
                }
                Case C(startX+2,startY+1);
                cases.push_back(C);
            }
            else if(type == 'L'  && rotationState == 2){
                for(int j=0; j<3; ++j){
                    Case C(startX+1, startY+j);
                    cases.push_back(C);
                }
                Case C(startX,startY+2);
                cases.push_back(C);
            }
            else if(type == 'L'  && rotationState == 3){
                for(int i=0; i<3; ++i){
                    Case C(startX+i, startY+1);
                    cases.push_back(C);
                }
                Case C(startX,startY);
                cases.push_back(C);
            }
            else if(type == 'J'  && rotationState == 0){
                for(int j=0; j<3; ++j){
                    Case C(startX, startY+j);
                    cases.push_back(C);
                }
                Case C(startX+1,startY+2);
                cases.push_back(C);
            }
            else if(type == 'J'  && rotationState == 1){
                for(int i=0; i<3; ++i){
                    Case C(startX+i, startY);
                    cases.push_back(C);
                }
                Case C(startX,startY+1);
                cases.push_back(C);
            }
            else if(type == 'J'  && rotationState == 2){
                for(int j=0; j<3; ++j){
                    Case C(startX+1, startY+j);
                    cases.push_back(C);
                }
                Case C(startX,startY);
                cases.push_back(C);
            }
            else if(type == 'J'  && rotationState == 3){
                for(int i=0; i<3; ++i){
                    Case C(startX+i, startY+1);
                    cases.push_back(C);
                }
                Case C(startX+2,startY);
                cases.push_back(C);
            }
            else if(type == 'Z' && (rotationState == 0 || rotationState == 2)){
                Case C1(startX,startY);
                cases.push_back(C1);
                Case C2(startX+1,startY);
                cases.push_back(C2);
                Case C3(startX+1,startY+1);
                cases.push_back(C3);
                Case C4(startX+2,startY+1);
                cases.push_back(C4);
            }
            else if(type == 'Z' && (rotationState == 1||rotationState == 3)){
                Case C1(startX+1,startY);
                cases.push_back(C1);
                Case C2(startX+1,startY+1);
                cases.push_back(C2);
                Case C3(startX,startY+1);
                cases.push_back(C3);
                Case C4(startX,startY+2);
                cases.push_back(C4);
            }
            else if(type == 'S' && (rotationState == 0||rotationState == 2)){
                Case C1(startX,startY+1);
                cases.push_back(C1);
                Case C2(startX+1,startY+1);
                cases.push_back(C2);
                Case C3(startX+1,startY);
                cases.push_back(C3);
                Case C4(startX+2,startY);
                cases.push_back(C4);
            }
            else if(type == 'S' && (rotationState == 1||rotationState==3)){
                Case C1(startX,startY);
                cases.push_back(C1);
                Case C2(startX,startY+1);
                cases.push_back(C2);
                Case C3(startX+1,startY+1);
                cases.push_back(C3);
                Case C4(startX+1,startY+2);
                cases.push_back(C4);
            }
        }

bool Piece::belong(Case C1) const {
    for(const Case& C : cases){
        if(C.getX()==C1.getX() && C.getY()==C1.getY()){
            return true;
        }
    }
    return false;
}


uint Piece::getMinX(){
    uint minX = cases[0].getX();
    for(Case& C : cases){
        if(C.getX() < minX){
            minX = C.getX();
        }
    }
    return minX;
}
uint Piece::getMaxX(){
    uint maxX = cases[0].getX();
    for(Case& C : cases){
        if(C.getX() > maxX){
            maxX = C.getX();
        }
    }
    return maxX;
}
uint Piece::getMinY(){
    uint minY = cases[0].getY();
    for(Case& C : cases){
        if(C.getY() < minY){
            minY = C.getY();
            }
        }
    return minY;
}
uint Piece::getMaxY(){
    uint maxY = cases[0].getY();
    for(Case& C : cases){
        if(C.getY() > maxY){
            maxY = C.getY();
        }
    }
    return maxY;
}


void Piece::move(int dx, int dy){
    for(Case& C : cases){
        C.setX(C.getX() + dx);
        C.setY(C.getY() + dy);
    }
}



void Piece::rotate(){
    uint pivotX = cases[0].getX();
    uint pivotY = cases[0].getY();
    int newR = (rotationState+1)%4;

    initialization(pivotX,pivotY,newR);
    rotationState = newR;
            /*
            for (Case& c : cases){
                uint newX = pivotX - (c.getY() - pivotY);
                uint newY = pivotY + (c.getX() - pivotX);
                c.setX(newX);
                c.setY(newY);
            }
            */
}

