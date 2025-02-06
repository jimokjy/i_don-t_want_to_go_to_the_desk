#ifndef SCREEN_H
#define SCREEN_H


class Screen
{
public:
    static const int WIDTH = 100;
    static const int HEIGHT = 20;
    char BUFFER [WIDTH][HEIGHT];

    void clearBUFFER();

    Screen();

    virtual ~Screen();

    void clear();

    void draw (int x, int y, char sym);

    void update ();

    void MoveCursor(short int x, short int y);
};

#endif // SCREEN_H
