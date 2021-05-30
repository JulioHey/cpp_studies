#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

bool gameOver;
const int width = 40;
const int height = 20;
int userX, userY, fruitX, fruitY, score;

int tailX[1000], tailY[1000];
int nTail;

enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};

eDirection dir;

void generateNewFruit() {
    fruitX = rand() % width;
    fruitY = rand() % height;
    return;
}


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
void Draw() 
{
    system("cls"); //system("clear")_

    for (int i = 0; i < width + 2; i ++) 
        cout << "#";

    cout << endl;

    for (int i = 0; i < height; i++)  
    {

        for (int j = 0; j < width; j++) 
        {
            if (j == 0 || j == width - 1)
                cout << "#";
            else if (i == userY && j == userX) {
                cout << "O";
            }
            else if (i == fruitY && j == fruitX) {
                cout << "F";
            }
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k ++)
                {
                    if (tailX[k] ==j && tailY[k] == i)
                    {
                        print = true;
                        cout << "o";
                    }
                        
                }
                if (!print) {
                    cout << " ";
                }
            }
        }
        
        cout << endl;
    }


    for (int i = 0; i < width + 2; i++) 
        cout << "#";
    cout << endl;
    cout << "SCORE: " << score << endl;
}

void Input() 
{
    if (_kbhit())
    {
        // Pega input
        switch (_getch()) 
        {
            case 'a':
                dir = LEFT;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'w':
                dir = UP;
                break;
            case 'x':
                gameOver = true;
                break;
        }

    }
}

void Logic() 
{
    int prevX = tailX[0];
    int prevY = tailY[0];

    tailX[0] = userX;
    tailY[0] = userY;

    int prev2X, prev2Y;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];

        tailX[i] = prevX;
        tailY[i] = prevY;

        prevX = prev2X;
        prevY = prev2Y;
    }


    switch (dir)
    {
        case LEFT:
            userX--;
            break;
        case RIGHT:
            userX++;
            break;
        case UP:
            userY--;
            break;
        case DOWN:
            userY++;
            break;
        case STOP:
            break;
        default:
            break;
    }


    if (userX > width || userX < 0 || userY > height || userY < 0)
    {
        gameOver = true;
    }

    for (int i = 0; i < nTail; i++) 
    {
        if (tailX[i] == userX && tailY[i] == userY)
        {
            gameOver = true;
        }
    }

    if (userX == fruitX && userY == fruitY)
    {
        nTail++;
        score ++;
        generateNewFruit();
    }
}

int main() 
{
    Setup();

    // Loop for game engine
    while (!gameOver) 
    {
        Draw();
        Input();
        Logic();
        Sleep(50);
    }
    cout << "Infelizmente você perdeu...\n";
    cout << "Você fez "<< score <<" pontos!!\n";
    return 0;
}