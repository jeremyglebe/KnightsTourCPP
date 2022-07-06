#include <string>
using namespace std;
// "Object oriented programming" means grouping data with the operations that
// work on the data. Such as having the "move" function be a method of "ChessPiece"

class ChessPiece{
public:
    ChessPiece();
    ChessPiece(string sym);
    // This is called "overloading", where two functions/methods have the same
    // name and different parameters
    void move(int row, int col); // Accepts a specific row and column to move to
    void move(char choice); // Accepts a char, indicating which pre-defined spot they wish to move to
    // "Get" methods to read private members
    int getRow();
    int getCol();
    string getSymbol();
private:
    string symbol;
    int row;
    int col;
};