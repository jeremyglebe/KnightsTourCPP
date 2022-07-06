#include "Board.h"
#include <iostream>

Board::Board(){
    // Create a new Knight ChessPiece
    knight = ChessPiece("♞ ");
    // Initializing 2D arrays from double pointers
    visitedMatrix = new bool*[8];
    displayMatrix = new string*[8];
    for (int r = 0; r < 8; r++){
        visitedMatrix[r] = new bool[8];
        displayMatrix[r] = new string[8];
        for(int c = 0; c < 8; c++){
            visitedMatrix[r][c] = false;
            // Alternate space colors for chessboar
            if((r+c)%2){
                displayMatrix[r][c] = "██";
            }else{
                displayMatrix[r][c] = "  ";
            }
        }
    }
}

Board::~Board(){
    for(int r = 0; r < 8; r++){
        delete[] visitedMatrix[r];
        delete[] displayMatrix[r];
    }
    delete[] visitedMatrix;
    delete[] displayMatrix;
}

void Board::print(){
    // Update display board before printing
    _updateDisplayMatrix();
    // Print by looping through rows and columns
    for(int r = 0; r < 8; r++){
        for(int c = 0; c < 8; c++){
            cout << displayMatrix[r][c];
        }
        cout << '\n';
    }
}

void Board::_updateDisplayMatrix(){
    // Reset all the colored spaces
    for (int r = 0; r < 8; r++){
        for(int c = 0; c < 8; c++){
            if(visitedMatrix[r][c] == true){
                displayMatrix[r][c] = "✓ ";
            }
            else if((r+c)%2){
                displayMatrix[r][c] = "██";
            }else{
                displayMatrix[r][c] = "  ";
            }
        }
    }
    // Place the knight on the display matrix
    int r = knight.getRow();
    int c = knight.getCol();
    displayMatrix[r][c] = knight.getSymbol();
    cout << r+1 << ',' << c+1 << '\n';
}

ChessPiece& Board::getKnight(){return knight;}

void Board::visit(int r, int c){
    visitedMatrix[r][c] = true;
}

bool Board::isVisited(int r, int c){
    return visitedMatrix[r][c];
}

bool Board::allVisited(){
    for(int r = 0; r < 8; r++){
        for(int c = 0; c < 8; c++){
            if(!isVisited(r,c)){
                return false;
            }
        }
    }
    return true;
}