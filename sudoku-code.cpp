#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

int difficultyLevel = 15;

string line = " +";
char empty = ' ';

int boardInt[9][9];
char boardBP[9][9];
char boardCell[9][9] = {
                        {empty,empty,empty,empty,empty,empty,empty,empty,empty},
                        {empty,empty,empty,empty,empty,empty,empty,empty,empty},
                        {empty,empty,empty,empty,empty,empty,empty,empty,empty},
                        
                        {empty,empty,empty,empty,empty,empty,empty,empty,empty},
                        {empty,empty,empty,empty,empty,empty,empty,empty,empty},
                        {empty,empty,empty,empty,empty,empty,empty,empty,empty},

                        {empty,empty,empty,empty,empty,empty,empty,empty,empty},
                        {empty,empty,empty,empty,empty,empty,empty,empty,empty},
                        {empty,empty,empty,empty,empty,empty,empty,empty,empty}
};

void repeatPrint(string str, int itr){
    for (int i = 0; i < itr; i++){
        cout << str;
    }
}

void fillBoard(){
    srand(time(NULL));

    for (int y = 0; y < 9; y++){
        for (int x = 0; x < 9; x++){
            boardInt[y][x] = rand() % 9 + 1;
        }
    }
}

void initializeBoard(){
    for (int y = 0; y < 9; y++){
        for (int x = 0; x < 9; x++){
            switch (boardInt[y][x]){
                case 1:
                    boardBP[y][x] = '1';
                    break;
                case 2:
                    boardBP[y][x] = '2';
                    break;
                case 3:
                    boardBP[y][x] = '3';
                    break;
                case 4:
                    boardBP[y][x] = '4';
                    break;
                case 5:
                    boardBP[y][x] = '5';
                    break;
                case 6:
                    boardBP[y][x] = '6';
                    break;
                case 7:
                    boardBP[y][x] = '7';
                    break;
                case 8:
                    boardBP[y][x] = '8';
                    break;
                case 9:
                    boardBP[y][x] = '9';
                    break;
                default:
                    boardBP[y][x] = '0';
                    break;
            }
        }
    }

    for (int y = 0; y < 9; y++){
        for (int x = 0; x < 9; x++){
            if (rand() % 100 < difficultyLevel){
                boardCell[y][x] = boardBP[y][x];
            }
        }
    }
}

void drawBoard(){

    int columnLine = 3;
    int rowLine = 4;
    int yCoord = 9;

    for (int y = 0; y < 9; y++){

        if (rowLine == 4){
            cout << ' ';
            repeatPrint(line,13);
            cout << endl;
            rowLine = 1;
        }
        if (rowLine != 4){
            cout << yCoord;
        }

        for (int x = 0; x < 9; x++){
            if (columnLine == 3){
                cout << line;
                columnLine = 0;
            }
            cout << ' ' << boardCell[y][x];
            columnLine++;
        }

        cout << line << endl;
        rowLine++;
        yCoord--;
    }

    cout << ' ';
    repeatPrint(line,13);
    cout << endl;
    cout << "    1 2 3   4 5 6   7 8 9\n";

}

int main(){
    fillBoard();
    initializeBoard();
    drawBoard();    
}
