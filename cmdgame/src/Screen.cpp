#include <iostream>
#include <cstring>
#include <windows.h>
#include "../include/Screen.h"

using namespace std;


void Screen::clearBUFFER(){
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            BUFFER[j][i] = '.';
        }
    }
}

Screen::Screen() {
    cout<<"\033[?25l";
    cout.flush();
    clearBUFFER();
}
Screen::~Screen() {
    clearBUFFER();
}
void Screen::clear(){
    MoveCursor(0, 0);
}
void Screen::draw (int x, int y, char sym){
    BUFFER[x][y] = sym;
}
void Screen::update (){
    string out = "";
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            out += BUFFER[j][i];
        }
        out += "\n";
    }
    cout<<out;
}
void Screen::MoveCursor(short int x, short int y){
    HANDLE hStdOut = NULL;
    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = {x, y};
    SetConsoleCursorPosition (hStdOut, coord);
}

