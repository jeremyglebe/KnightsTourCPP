#include "ChessPiece.h"
#include <iostream>
// The ".cpp" file is where we implement class methods!

// We specify that a method belongs to a class from another file (".h")
// by using the "scope resolution" operator (it's in the class' scope!)
ChessPiece::ChessPiece(string sym){
    symbol = sym;
    row = 0;
    col = 0;
}
ChessPiece::ChessPiece(){
    symbol = "k";
    row = 0;
    col = 0;
}

// The scope becomes part of the name, which means it still comes
// after the return type
void ChessPiece::move(int r, int c){
    // Check if the row and column are valid
    if(r >= 0 && c >= 0 && r <=8 && c <=8){
        // Notice that I don't have to pass in data members?
        row = r;
        // All variables in the class are automatically in scope of
        // it's methods!
        col = c;
    }
}

void ChessPiece::move(char choice){
    // Okay, so this method does something weird but it will make the
    // game more fun
    // Instead of having players enter a row and a column each time,
    // we will let them pick from the 8 locations a knight can move to
    // by entering a,b,c,d,e,f,g,h. Letters will correpond with positions
    // from left to right and top to bottom.
    if(choice == 'a'){
        // Calling the other version of move with specific row/column
        move(row-2, col-1);
    }
    else if (choice == 'b'){
        move(row-2, col+1);
    }
    else if (choice == 'c'){
        move(row-1, col-2);
    }
    else if (choice == 'd'){
        move(row-1, col+2);
    }
    else if (choice == 'e'){
        move(row+1, col-2);
    }
    else if (choice == 'f'){
        move(row+1, col+2);
    }
    else if(choice == 'g'){
        move(row+2, col-1);
    }
    else if (choice == 'h'){
        move(row+2, col+1);
    }
}

int ChessPiece::getRow(){return row;}
int ChessPiece::getCol(){return col;}
string ChessPiece::getSymbol(){return symbol;}