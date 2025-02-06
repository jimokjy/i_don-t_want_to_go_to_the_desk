#include <iostream>
#include <cstring>
#include "include/Screen.h"
#include <windows.h>
#include "include/Keyboard.h"

using namespace std;

int neib(int x, int y, Screen life){
    int da = 0;
    if (life.BUFFER[(x - 1)][y] == '*'){
        da++;
    }
    if (life.BUFFER[(x - 1)][(y - 1)] == '*'){
        da++;
    }
    if (life.BUFFER[x][(y - 1)] == '*'){
        da++;
    }
    if (life.BUFFER[(x + 1)][(y - 1)] == '*'){
        da++;
    }
    if (life.BUFFER[(x + 1)][y] == '*'){
        da++;
    }
    if (life.BUFFER[(x + 1)][(y + 1)] == '*'){
        da++;
    }
    if (life.BUFFER[x][(y + 1)] == '*'){
        da++;
    }
    if (life.BUFFER[(x - 1)][(y + 1)] == '*'){
        da++;
    }
    return da;
}

int main()
{
//--------------------------------------RULES--------------------------------------------------------
    int need_for_life = 2;
    int overpopulation = 4;
    int hunger_dead = 1;
    int need_for_birth = 3;
//---------------------------------------------------------------------------------------------------
    Screen waffle;
    Keyboard butffle;
    waffle.update();

    int y = 1;
    int x = 1;

    char luffer[waffle.WIDTH][waffle.HEIGHT];
    bool pause = true;

    for (int i = 0; i < x; i++){
            for (int j = 0; j < y; j++){
                luffer[j][i] = '.';
            }
        }

    waffle.BUFFER[35][10] = '*';
    waffle.BUFFER[36][10] = '*';
    waffle.BUFFER[37][11] = '*';
    waffle.BUFFER[36][12] = '*';
    waffle.BUFFER[35][12] = '*';
    waffle.BUFFER[34][11] = '*';

    while (true){
        if (pause){
            if (butffle.isPress(0x57)){
                y--;
            }
            if (butffle.isPress(0x53)){
                y++;
            }
            if (butffle.isPress(0x41)){
                x--;
            }
            if (butffle.isPress(0x44)){
                x++;
            }
            waffle.draw(x, y, '#');
        }
        if (not pause){
            for (int i = 0; i < waffle.HEIGHT; i++){
                for (int j = 0; j < waffle.WIDTH; j++){
                    if (neib(j, i, waffle) <= hunger_dead){
                        luffer[j][i] = '.';
                    }
                    if (neib(j, i, waffle) >= overpopulation){
                        luffer[j][i] = '.';
                    }
                    if ((neib(j, i, waffle) == need_for_life) and (waffle.BUFFER[j][i] == '*')){
                        luffer[j][i] = '*';
                    }
                    if (neib(j, i, waffle) == need_for_birth){
                        luffer[j][i] = '*';
                    }
                }
            }
            for (int i = 0; i < waffle.HEIGHT; i++){
                for (int j = 0; j < waffle.WIDTH; j++){
                    waffle.BUFFER[j][i] = luffer[j][i];
                }
            }
        }
        if ((pause) and (butffle.isPress(0x20))){
            pause = false;
        }
        if ((not pause) and (butffle.isPress(0x20))){
            pause = true;
        }
        waffle.update();
        waffle.clear();
        Sleep(100);

    }

}
