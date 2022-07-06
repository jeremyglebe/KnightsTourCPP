#include <string>
#include "ChessPiece.h"
using namespace std;

class Board{
public:
    Board();
    ~Board();
    void print();
    ChessPiece& getKnight();
    void visit(int r, int c);
    bool isVisited(int r, int c);
    bool allVisited();
private:
    void _updateDisplayMatrix();
    ChessPiece knight;
    string** displayMatrix;
    bool** visitedMatrix;
};