#include <iostream>
#include <conio.h>

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int userX, userY, fruitX, fruitY, score;

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
                cout << " ";
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

    if (userX == fruitX && userY == fruitY)
    {
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
    }

    cout << "Infelizmente você perdeu...\n";
    cout << "Você fez "<< score <<" pontos!!\n";

    return 0;
}