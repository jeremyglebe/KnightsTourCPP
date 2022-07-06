// Program: We will be writing an interactive "game" of the Knight's Tour problem
//     to review for the exam. Why? Because it is an easy example that includes
//     lots of coding, classes, arrays, 2D arrays, and so on.
// Description of Knight's Tour:
//     Basically the player wants to visit every space on a chessboard using just
//     a knight and never visit the same place twice.
//     More here: https://en.wikipedia.org/wiki/Knight%27s_tour

#include <iostream>
#include <thread>
#include <chrono>
#include "Board.h"
using namespace std;

// Functions are broken down into several components
// The following line is a "prototype", which let's the compiler know about a
// function before it is implemented
void printHeader();
// Prompt for controls
void printPrompt();
// Prints the end of the game if you're a loser
void printLose();
// Prints if you win
void printWin();
// Causes the thread to wait before continuing
void sleep_ms(int ms);

int main() {
    // Create an instance of the Board class
    Board game;
    // Character for player input
    char input = ' ';
    // Go until the user quits
    while(input != 'q'){
        // "clear" the screen
        cout << string(40, '\n');
        // This is a function call, it will print a header for our program
        printHeader();
        // Get the Knight's current position
        int r = game.getKnight().getRow();
        int c = game.getKnight().getCol();
        // Lose condition
        if(game.isVisited(r,c)){
            // If the player has landed on a space already visited once
            printLose();
            input = 'q';
        }
        // Keep playing condition
        else{
            // If the player has not yet visited this space
            game.visit(game.getKnight().getRow(), game.getKnight().getCol());
            // If all spaces are visited, the player wins!
            if(game.allVisited()){
                // "clear" the screen
                cout << string(40, '\n');
                // This is a function call, it will print a header for our program
                printHeader();
                // Win text
                printWin();
                input = 'q';
            }
            // Otherwise, the player takes another turn
            else{
                printPrompt(); // This prints a "controls" prompt
                game.print(); // This prints the board using a call to it's method
                cin >> input;
                game.getKnight().move(input);
            }
        }
        sleep_ms(150);
    }
}

// Below is the "definintion" of a function, where it is implemented
void printHeader()
{ // Everything inside these braces is the function's "body"
    string header;
    header += "  |                                                                                                                                        \n";
    header += "  |                                                                                                                                        \n";
    header += "  + \\                                                                                                                                      \n";
    header += "  \\\\.G_.*=.                                                                                                                                \n";
    header += "   `(#'/.\\|     __  ___ .__   __.  __    _______  __    __  .___________.__     _______.   .___________.  ______    __    __  .______      \n";
    header += "    .>' (_--.  |  |/  / |  \\ |  | |  |  /  _____||  |  |  | |           (_ )   /       |   |           | /  __  \\  |  |  |  | |   _  \\     \n";
    header += " _=/d   ,^\\    |  '  /  |   \\|  | |  | |  |  __  |  |__|  | `---|  |----`|/   |   (----`   `---|  |----`|  |  |  | |  |  |  | |  |_)  |    \n";
    header += "~~ \\)-'   '    |    <   |  . `  | |  | |  | |_ | |   __   |     |  |           \\   \\           |  |     |  |  |  | |  |  |  | |      /     \n";
    header += "   / |         |  .  \\  |  |\\   | |  | |  |__| | |  |  |  |     |  |       .----)   |          |  |     |  `--'  | |  `--'  | |  |\\  \\----.\n";
    header += "  '  '         |__|\\__\\ |__| \\__| |__|  \\______| |__|  |__|     |__|       |_______/           |__|      \\______/   \\______/  | _| `._____|\n";
    // Knight and horse by Andreas Freise
    // https://www.asciiart.eu/people/occupations/knights
    // Text font "Star Wars" from patorjk
    // https://www.patorjk.com/software/taag/
    // (Always give credit if you didn't make something, especially cool stuff like this ascii art!)
    cout << header << endl;
}

void printPrompt(){
    cout << "Movement reference:  ██a ██ b██\n";
    cout << "                     c ██  ██ d\n";
    cout << "Enter the keys on    ██  ♞   ██\n";
    cout << "the right to move    e ██  ██ f\n";
    cout << "Enter q to quit      ██g ██ h██\n\n";
}

void printLose(){
    string lose;
    lose += "▄▄▄█████▓ ▒█████   ▒█████      ▄▄▄▄    ▄▄▄      ▓█████▄  ▐██▌ \n";
    lose += "▓  ██▒ ▓▒▒██▒  ██▒▒██▒  ██▒   ▓█████▄ ▒████▄    ▒██▀ ██▌ ▐██▌ \n";
    lose += "▒ ▓██░ ▒░▒██░  ██▒▒██░  ██▒   ▒██▒ ▄██▒██  ▀█▄  ░██   █▌ ▐██▌ \n";
    lose += "░ ▓██▓ ░ ▒██   ██░▒██   ██░   ▒██░█▀  ░██▄▄▄▄██ ░▓█▄   ▌ ▓██▒ \n";
    lose += "  ▒██▒ ░ ░ ████▓▒░░ ████▓▒░   ░▓█  ▀█▓ ▓█   ▓██▒░▒████▓  ▒▄▄  \n";
    lose += "  ▒ ░░   ░ ▒░▒░▒░ ░ ▒░▒░▒░    ░▒▓███▀▒ ▒▒   ▓▒█░ ▒▒▓  ▒  ░▀▀▒ \n";
    lose += "    ░      ░ ▒ ▒░   ░ ▒ ▒░    ▒░▒   ░   ▒   ▒▒ ░ ░ ▒  ▒  ░  ░ \n";
    lose += "  ░      ░ ░ ░ ▒  ░ ░ ░ ▒      ░    ░   ░   ▒    ░ ░  ░     ░ \n";
    lose += "             ░ ░      ░ ░      ░            ░  ░   ░     ░    \n";
    lose += "                                    ░            ░            \n\n";
    cout << lose;
    // Text font "Bloody" from patorjk
    // https://www.patorjk.com/software/taag/
}

void printWin(){
    string win;
    win += "    ____                          _  _                                          __ \n";
    win += "   F ___J   ____     _ ___       FJ  L]     ____     _ ___      ____     _ ___  LJ \n";
    win += "  J |___:  F __ J   J '__ \",    J |__| L   F __ J   J '__ J    F __ J   J '__ \",FJ \n";
    win += "  | _____|| |--| |  | |__|-J    |  __  |  | |--| |  | |__| |  | |--| |  | |__|-J__L\n";
    win += "  F |____JF L__J J  F L  `-'    F L__J J  F L__J J  F L  J J  F L__J J  F L  `-'__ \n";
    win += " J__F    J\\______/FJ__L        J__L  J__LJ\\______/FJ__L  J__LJ\\______/FJ__L    J__L\n";
    win += " |__|     J______F |__L        |__L  J__| J______F |__L  J__| J______F |__L    |__|\n";
    cout << win;
    // Text font "Henry 3D" from patorjk
    // https://www.patorjk.com/software/taag/
}

void sleep_ms(int ms)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}