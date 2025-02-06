#ifndef KEYBOARD_H
#define KEYBOARD_H


class Keyboard
{
public:
    Keyboard();

    virtual ~Keyboard();

    bool isPress(int button);
};

#endif // KEYBOARD_H
