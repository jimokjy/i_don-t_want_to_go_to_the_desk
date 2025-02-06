
#include <iostream>
#include <cstring>

using namespace std;

class screen {
private:
    static const int WIDTH = 100;
    static const int HEIGHT = 25;
    char BUFFER [WIDTH][HEIGHT];
    void clearBUFFER(){
        for (int i = 0; i < HEIGHT; i++){
            for (int j = 0; j < WIDTH; j++){
                BUFFER[j][i] = " ";
            }
        }
    }
public:
    screen(){
        cout<<"\033[?25l";
        cout.flush();
        clearBUFFER();
    }
    ~screen {
        clearBUFFER();
    }
    void clear(){
        cout<<"\033[2J\033[1;1H";
    }
    void draw (int x, int y, char sym){
        BUFFER[x][y] = sym;
    }
    void update (){
        for (int i = 0; i < HEIGHT; i++){
            for (int j = 0; j < WIDTH; j++){
                cout<<BUFFER[j][i];
            }
            cout<<endl;
        }
        clearBUFFER();
    }
};

int main()
{
    return 0;
}
