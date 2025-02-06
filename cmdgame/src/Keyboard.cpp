#include "../include/Keyboard.h"
#include <windows.h>
#include <iostream>
#include <cstring>

using namespace std;


Keyboard::Keyboard()
{

}

Keyboard::~Keyboard()
{

}

bool Keyboard::isPress(int button){
    return (GetAsyncKeyState(button) & 0x01);
}


