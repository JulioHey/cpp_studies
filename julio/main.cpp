#include <iostream>
#include <conio.h>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int userX, userY, fruitX, fruitY, score;

enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};

eDirection dir;

// only called one time;
void Setup() {
    gameOver = false;
    dir = STOP;
    userX = width/2;
    userY= height/2;

    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

// Draw the game on the screen
void Draw() {
    system("cls"); //system("clear")_

    for (int i = 0; i < width + 2; i ++) 
        cout << "#";

    cout << endl;

    for (int i = 0; i < height; i++)  {

        for (int j = 0; j < width; j++) {
            if (j == 0 || j == width - 1)
                cout << "#";
            else 
                cout << " ";
        }
        
        cout << endl;
    }


    for (int i = 0; i < width + 2; i++) 
        cout << "#";
    cout << endl;



}

void Input() {

}

void Logic() {

}

int main() {
    Setup();

    // Loop for game engine
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        // Sleep(10);
    }

    return 0;
}