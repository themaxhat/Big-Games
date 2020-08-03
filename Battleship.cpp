#include<iostream>
#include<stdlib.h>
using namespace std;

void board(char sea1[][10], char compsea[][10]){
    cout << "      Player 1 board:              Player 2 board:" << endl;
    cout << "    \033[4mA\033[0m \033[4mB\033[0m \033[4mC\033[0m \033[4mD\033[0m \033[4mE\033[0m ";
    cout << "\033[4mF\033[0m \033[4mG\033[0m \033[4mH\033[0m \033[4mI\033[0m \033[4mJ\033[0m ";
    cout << "         \033[4mA\033[0m \033[4mB\033[0m \033[4mC\033[0m \033[4mD\033[0m \033[4mE\033[0m ";
    cout << "\033[4mF\033[0m \033[4mG\033[0m \033[4mH\033[0m \033[4mI\033[0m \033[4mJ\033[0m "<< endl;
    cout << " 1 |" << sea1[0][0]<< "|" << sea1[1][0]<< "|" << sea1[2][0]<< "|" << sea1[3][0]<< "|" << sea1[4][0]<< "|" << sea1[5][0]<< "|" << sea1[6][0]<< "|" << sea1[7][0]<< "|" << sea1[8][0]<< "|" << sea1[9][0]<< "|      1 |" << compsea[0][0]<< "|" << compsea[1][0]<< "|" << compsea[2][0]<< "|" << compsea[3][0]<< "|" << compsea[4][0]<< "|" << compsea[5][0]<< "|" << compsea[6][0]<< "|" << compsea[7][0]<< "|" << compsea[8][0]<< "|" << compsea[9][0]<< "|" << endl;
    cout << " 2 |" << sea1[0][1]<< "|" << sea1[1][1]<< "|" << sea1[2][1]<< "|" << sea1[3][1]<< "|" << sea1[4][1]<< "|" << sea1[5][1]<< "|" << sea1[6][1]<< "|" << sea1[7][1]<< "|" << sea1[8][1]<< "|" << sea1[9][1]<< "|      2 |" << compsea[0][1]<< "|" << compsea[1][1]<< "|" << compsea[2][1]<< "|" << compsea[3][1]<< "|" << compsea[4][1]<< "|" << compsea[5][1]<< "|" << compsea[6][1]<< "|" << compsea[7][1]<< "|" << compsea[8][1]<< "|" << compsea[9][1]<< "|" << endl;
    cout << " 3 |" << sea1[0][2]<< "|" << sea1[1][2]<< "|" << sea1[2][2]<< "|" << sea1[3][2]<< "|" << sea1[4][2]<< "|" << sea1[5][2]<< "|" << sea1[6][2]<< "|" << sea1[7][2]<< "|" << sea1[8][2]<< "|" << sea1[9][2]<< "|      3 |" << compsea[0][2]<< "|" << compsea[1][2]<< "|" << compsea[2][2]<< "|" << compsea[3][2]<< "|" << compsea[4][2]<< "|" << compsea[5][2]<< "|" << compsea[6][2]<< "|" << compsea[7][2]<< "|" << compsea[8][2]<< "|" << compsea[9][2]<< "|" << endl;
    cout << " 4 |" << sea1[0][3]<< "|" << sea1[1][3]<< "|" << sea1[2][3]<< "|" << sea1[3][3]<< "|" << sea1[4][3]<< "|" << sea1[5][3]<< "|" << sea1[6][3]<< "|" << sea1[7][3]<< "|" << sea1[8][3]<< "|" << sea1[9][3]<< "|      4 |" << compsea[0][3]<< "|" << compsea[1][3]<< "|" << compsea[2][3]<< "|" << compsea[3][3]<< "|" << compsea[4][3]<< "|" << compsea[5][3]<< "|" << compsea[6][3]<< "|" << compsea[7][3]<< "|" << compsea[8][3]<< "|" << compsea[9][3]<< "|" << endl;
    cout << " 5 |" << sea1[0][4]<< "|" << sea1[1][4]<< "|" << sea1[2][4]<< "|" << sea1[3][4]<< "|" << sea1[4][4]<< "|" << sea1[5][4]<< "|" << sea1[6][4]<< "|" << sea1[7][4]<< "|" << sea1[8][4]<< "|" << sea1[9][4]<< "|      5 |" << compsea[0][4]<< "|" << compsea[1][4]<< "|" << compsea[2][4]<< "|" << compsea[3][4]<< "|" << compsea[4][4]<< "|" << compsea[5][4]<< "|" << compsea[6][4]<< "|" << compsea[7][4]<< "|" << compsea[8][4]<< "|" << compsea[9][4]<< "|" << endl;
    cout << " 6 |" << sea1[0][5]<< "|" << sea1[1][5]<< "|" << sea1[2][5]<< "|" << sea1[3][5]<< "|" << sea1[4][5]<< "|" << sea1[5][5]<< "|" << sea1[6][5]<< "|" << sea1[7][5]<< "|" << sea1[8][5]<< "|" << sea1[9][5]<< "|      6 |" << compsea[0][5]<< "|" << compsea[1][5]<< "|" << compsea[2][5]<< "|" << compsea[3][5]<< "|" << compsea[4][5]<< "|" << compsea[5][5]<< "|" << compsea[6][5]<< "|" << compsea[7][5]<< "|" << compsea[8][5]<< "|" << compsea[9][5]<< "|" << endl;
    cout << " 7 |" << sea1[0][6]<< "|" << sea1[1][6]<< "|" << sea1[2][6]<< "|" << sea1[3][6]<< "|" << sea1[4][6]<< "|" << sea1[5][6]<< "|" << sea1[6][6]<< "|" << sea1[7][6]<< "|" << sea1[8][6]<< "|" << sea1[9][6]<< "|      7 |" << compsea[0][6]<< "|" << compsea[1][6]<< "|" << compsea[2][6]<< "|" << compsea[3][6]<< "|" << compsea[4][6]<< "|" << compsea[5][6]<< "|" << compsea[6][6]<< "|" << compsea[7][6]<< "|" << compsea[8][6]<< "|" << compsea[9][6]<< "|" << endl;
    cout << " 8 |" << sea1[0][7]<< "|" << sea1[1][7]<< "|" << sea1[2][7]<< "|" << sea1[3][7]<< "|" << sea1[4][7]<< "|" << sea1[5][7]<< "|" << sea1[6][7]<< "|" << sea1[7][7]<< "|" << sea1[8][7]<< "|" << sea1[9][7]<< "|      8 |" << compsea[0][7]<< "|" << compsea[1][7]<< "|" << compsea[2][7]<< "|" << compsea[3][7]<< "|" << compsea[4][7]<< "|" << compsea[5][7]<< "|" << compsea[6][7]<< "|" << compsea[7][7]<< "|" << compsea[8][7]<< "|" << compsea[9][7]<< "|" << endl;
    cout << " 9 |" << sea1[0][8]<< "|" << sea1[1][8]<< "|" << sea1[2][8]<< "|" << sea1[3][8]<< "|" << sea1[4][8]<< "|" << sea1[5][8]<< "|" << sea1[6][8]<< "|" << sea1[7][8]<< "|" << sea1[8][8]<< "|" << sea1[9][8]<< "|      9 |" << compsea[0][8]<< "|" << compsea[1][8]<< "|" << compsea[2][8]<< "|" << compsea[3][8]<< "|" << compsea[4][8]<< "|" << compsea[5][8]<< "|" << compsea[6][8]<< "|" << compsea[7][8]<< "|" << compsea[8][8]<< "|" << compsea[9][8]<< "|" << endl;
    cout << "10 |" << sea1[0][9]<< "|" << sea1[1][9]<< "|" << sea1[2][9]<< "|" << sea1[3][9]<< "|" << sea1[4][9]<< "|" << sea1[5][9]<< "|" << sea1[6][9]<< "|" << sea1[7][9]<< "|" << sea1[8][9]<< "|" << sea1[9][9]<< "|     10 |" << compsea[0][9]<< "|" << compsea[1][9]<< "|" << compsea[2][9]<< "|" << compsea[3][9]<< "|" << compsea[4][9]<< "|" << compsea[5][9]<< "|" << compsea[6][9]<< "|" << compsea[7][9]<< "|" << compsea[8][9]<< "|" << compsea[9][9]<< "|" << endl;

}

int main(){
    char sea1[10][10] = {};
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                sea1 [i][j] = '_';
            }
        }
    char compsea[10][10] = {};
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                compsea [i][j] = '_';
            }
        }
    int ships1 = 2;
    int compships = 10;
    int turn = 1;
    int length1;
    int complength;
    int up1;
    int compup;
    int acrossnum1;
    int compnum;
    int ship1_6 = 1;
    int ship1_4 = 2;
    int ship1_3 = 3;
    int ship1_2 = 4;
    int compship_6 = 1;
    int compship_4 = 2;
    int compship_3 = 3;
    int compship_2 = 4;
    int compacross;
    int compdirection;

    string direction1;

    char across1;

    bool over;

    srand(time(NULL));

    board(sea1, compsea);    

    while (turn == 1){
        cout << "You have " << ships1 << " ships left to place \nWhat letter across do you want to use?\n";
        cin >> across1;
        cout << "What number up do you want to use?\n";
        cin >> up1;
        switch (across1){
            case 'A':
                acrossnum1 = 0;
                break;
            case 'B':
                acrossnum1 = 1;
                break;
            case 'C':
                acrossnum1 = 2;
                break;
            case 'D':
                acrossnum1 = 3;
                break;
            case 'E':
                acrossnum1 = 4;
                break;
            case 'F':
                acrossnum1 = 5;
                break;
            case 'G':
                acrossnum1 = 6;
                break;
            case 'H':
                acrossnum1 = 7;
                break;
            case 'I':
                acrossnum1 = 8;
                break;
            case 'J':
                acrossnum1 = 9;
                break;  
            case 'a':
                acrossnum1 = 0;
                break;
            case 'b':
                acrossnum1 = 1;
                break;
            case 'c':
                acrossnum1 = 2;
                break;
            case 'd':
                acrossnum1 = 3;
                break;
            case 'e':
                acrossnum1 = 4;
                break;
            case 'f':
                acrossnum1 = 5;
                break;
            case 'g':
                acrossnum1 = 6;
                break;
            case 'h':
                acrossnum1 = 7;
                break;
            case 'i':
                acrossnum1 = 8;
                break;
            case 'j':
                acrossnum1 = 9;
                break;   
        }
        
        sea1 [acrossnum1][up1 - 1] = 'O';
        board(sea1, compsea);

        cout << "There are " << ship1_6 << " ships with a length of 6, " << ship1_4 << " ships with a length of four, " << ship1_3 << " ships with a length of three, and " << ship1_2 << " ships with a length of 2\n";
        cout << "What is the length of the ship you want to use?\n";
        cin >> length1;
        while (((length1 == 6) && (ship1_6 == 0)) || ((length1 == 4) && (ship1_4 == 0)) || ((length1 == 3) && (ship1_3 == 0)) || ((length1 == 2) && (ship1_2 == 0))){
            cout << "You don't have any of those ships\npick another one\n";
            cin >> length1;
        }
        while ((length1 != 6) && (length1 != 4) && (length1 != 3) && (length1 != 2)){
            cout << "*invalid length*\nPlease enter a valid length\n";
            cin >> length1;
        }
        switch (length1){
            case 6:
                ship1_6--;
                break;
            case 4:
                ship1_4--;
                break;
            case 3:
                ship1_3--;
                break;
            case 2:
                ship1_2--;
                break;
        }
        cout << "What direction do you want that ship to go?\n";
        cin >> direction1;
        while ((direction1 != "up") && (direction1 != "down") && (direction1 != "left") && (direction1 != "right")){
            cout << "that's not a direction\nup, down, left, or right";
            cin >> direction1;
        }

        //ship length 6
        if ((direction1 == "up") && (length1 == 6)){
            sea1 [acrossnum1][up1 - 2] = 'O';
            sea1 [acrossnum1][up1 - 3] = 'O';
            sea1 [acrossnum1][up1 - 4] = 'O';
            sea1 [acrossnum1][up1 - 5] = 'O';
            sea1 [acrossnum1][up1 - 6] = 'O';
            board(sea1, compsea);
        }
        if ((direction1 == "down") && (length1 == 6)){
            sea1 [acrossnum1][up1] = 'O';
            sea1 [acrossnum1][up1 + 1] = 'O';
            sea1 [acrossnum1][up1 + 2] = 'O';
            sea1 [acrossnum1][up1 + 3] = 'O';
            sea1 [acrossnum1][up1 + 4] = 'O';
            board(sea1, compsea);
        }
        if ((direction1 == "left") && (length1 == 6)){
            sea1 [acrossnum1 - 1][up1 - 1] = 'O';
            sea1 [acrossnum1 - 2][up1 - 1] = 'O';
            sea1 [acrossnum1 - 3][up1 - 1] = 'O';
            sea1 [acrossnum1 - 4][up1 - 1] = 'O';
            sea1 [acrossnum1 - 5][up1 - 1] = 'O';
            board(sea1, compsea);
        }
        if ((direction1 == "right") && (length1 == 6)){
            sea1 [acrossnum1 + 1][up1 - 1] = 'O';
            sea1 [acrossnum1 + 2][up1 - 1] = 'O';
            sea1 [acrossnum1 + 3][up1 - 1] = 'O';
            sea1 [acrossnum1 + 4][up1 - 1] = 'O';
            sea1 [acrossnum1 + 5][up1 - 1] = 'O';
            board(sea1, compsea);
        }

        //ship length 4
        if ((direction1 == "up") && (length1 == 4)){
            sea1 [acrossnum1][up1 - 2] = 'O';
            sea1 [acrossnum1][up1 - 3] = 'O';
            sea1 [acrossnum1][up1 - 4] = 'O';
            board(sea1, compsea);
        }
        if ((direction1 == "down") && (length1 == 4)){
            sea1 [acrossnum1][up1] = 'O';
            sea1 [acrossnum1][up1 + 1] = 'O';
            sea1 [acrossnum1][up1 + 2] = 'O';
            board(sea1, compsea);
        }
        if ((direction1 == "left") && (length1 == 4)){
            sea1 [acrossnum1 - 1][up1 - 1] = 'O';
            sea1 [acrossnum1 - 2][up1 - 1] = 'O';
            sea1 [acrossnum1 - 3][up1 - 1] = 'O';
            board(sea1, compsea);
        }
        if ((direction1 == "right") && (length1 == 4)){
            sea1 [acrossnum1 + 1][up1 - 1] = 'O';
            sea1 [acrossnum1 + 2][up1 - 1] = 'O';
            sea1 [acrossnum1 + 3][up1 - 1] = 'O';
            board(sea1, compsea);
        }

        //ship length 3
        if ((direction1 == "up") && (length1 == 3)){
            sea1 [acrossnum1][up1 - 2] = 'O';
            sea1 [acrossnum1][up1 - 3] = 'O';
            board(sea1, compsea);
        }
        if ((direction1 == "down") && (length1 == 3)){
            sea1 [acrossnum1][up1] = 'O';
            sea1 [acrossnum1][up1 + 1] = 'O';
            board(sea1, compsea);
        }
        if ((direction1 == "left") && (length1 == 3)){
            sea1 [acrossnum1 - 1][up1 - 1] = 'O';
            sea1 [acrossnum1 - 2][up1 - 1] = 'O';
            board(sea1, compsea);
        }
        if ((direction1 == "right") && (length1 == 3)){
            sea1 [acrossnum1 + 1][up1 - 1] = 'O';
            sea1 [acrossnum1 + 2][up1 - 1] = 'O';
            board(sea1, compsea);
        }

        //ship length 2
        if ((direction1 == "up") && (length1 == 2)){
            sea1 [acrossnum1][up1 - 2] = 'O';
            board(sea1, compsea);
        }
        if ((direction1 == "down") && (length1 == 2)){
            sea1 [acrossnum1][up1] = 'O';
            board(sea1, compsea);
        }
        if ((direction1 == "left") && (length1 == 2)){
            sea1 [acrossnum1 - 1][up1 - 1] = 'O';
            board(sea1, compsea);
        }
        if ((direction1 == "right") && (length1 == 2)){
            sea1 [acrossnum1 + 1][up1 - 1] = 'O';
            board(sea1, compsea);
        }

        ships1--;

        if (ships1 <= 0){
            break;
        }
    }

    turn = 2;

    while (turn == 2){
        srand (time(NULL));
        compacross = rand() % 10;
        compup = rand() % 10;
  
        compsea [compnum][compup] = 'O';
        board(sea1, compsea);

        complength = rand() % 6 + 1;
        while (((complength == 6) && (compship_6 == 0)) || ((complength == 4) && (compship_4 == 0)) || ((complength == 3) && (compship_3 == 0)) || ((complength == 2) && (compship_2 == 0))){
            complength = rand() % 6 + 1;
        }
        while ((complength != 6) && (complength != 4) && (complength != 3) && (complength != 2)){
            complength = rand() % 6 + 1;
        }
        switch (complength){
            case 6:
                compship_6--;
                break;
            case 4:
                compship_4--;
                break;
            case 3:
                compship_3--;
                break;
            case 2:
                compship_2--;
                break;
        }
        cin >> compdirection;

        //ship length 6
        if ((compdirection == 0) && (complength == 6)){
            compsea [compnum][compup - 2] = 'O';
            compsea [compnum][compup - 3] = 'O';
            compsea [compnum][compup - 4] = 'O';
            compsea [compnum][compup - 5] = 'O';
            compsea [compnum][compup - 6] = 'O';
            board(sea1, compsea);
        }
        if ((compdirection == 1) && (complength == 6)){
            compsea [compnum][compup] = 'O';
            compsea [compnum][compup + 1] = 'O';
            compsea [compnum][compup + 2] = 'O';
            compsea [compnum][compup + 3] = 'O';
            compsea [compnum][compup + 4] = 'O';
            board(sea1, compsea);
        }
        if ((compdirection == 2) && (complength == 6)){
            compsea [compnum - 1][compup] = 'O';
            compsea [compnum - 2][compup] = 'O';
            compsea [compnum - 3][compup] = 'O';
            compsea [compnum - 4][compup] = 'O';
            compsea [compnum - 5][compup] = 'O';
            board(sea1, compsea);
        }
        if ((compdirection == 3) && (complength == 6)){
            compsea [compnum + 1][compup] = 'O';
            compsea [compnum + 2][compup] = 'O';
            compsea [compnum + 3][compup] = 'O';
            compsea [compnum + 4][compup] = 'O';
            compsea [compnum + 5][compup] = 'O';
            board(sea1, compsea);
        }

        //ship length 4
        if ((compdirection == 0) && (complength == 4)){
            compsea [compnum][compup - 2] = 'O';
            compsea [compnum][compup - 3] = 'O';
            compsea [compnum][compup - 4] = 'O';
            board(sea1, compsea);
        }
        if ((compdirection == 1) && (complength == 4)){
            compsea [compnum][compup] = 'O';
            compsea [compnum][compup + 1] = 'O';
            compsea [compnum][compup + 2] = 'O';
            board(sea1, compsea);
        }
        if ((compdirection == 2) && (complength == 4)){
            compsea [compnum - 1][compup] = 'O';
            compsea [compnum - 2][compup] = 'O';
            compsea [compnum - 3][compup] = 'O';
            board(sea1, compsea);
        }
        if ((compdirection == 3) && (complength == 4)){
            compsea [compnum + 1][compup] = 'O';
            compsea [compnum + 2][compup] = 'O';
            compsea [compnum + 3][compup] = 'O';
            board(sea1, compsea);
        }

        //ship length 3
        if ((compdirection == 0) && (complength == 3)){
            compsea [compnum][compup - 1] = 'O';
            compsea [compnum][compup - 2] = 'O';
            board(sea1, compsea);
        }
        if ((compdirection == 1) && (complength == 3)){
            compsea [compnum][compup] = 'O';
            compsea [compnum][compup + 1] = 'O';
            board(sea1, compsea);
        }
        if ((compdirection == 2) && (complength == 3)){
            compsea [compnum - 1][compup] = 'O';
            compsea [compnum - 2][compup] = 'O';
            board(sea1, compsea);
        }
        if ((compdirection == 3) && (complength == 3)){
            compsea [compnum + 1][compup] = 'O';
            compsea [compnum + 2][compup] = 'O';
            board(sea1, compsea);
        }

        //ship length 2
        if ((compdirection == 0) && (complength == 2)){
            compsea [compnum][compup - 2] = 'O';
            board(sea1, compsea);
        }
        if ((compdirection == 1) && (complength == 2)){
            compsea [compnum][compup] = 'O';
            board(sea1, compsea);
        }
        if ((compdirection == 2) && (complength == 2)){
            compsea [compnum - 1][compup] = 'O';
            board(sea1, compsea);
        }
        if ((compdirection == 3) && (complength == 2)){
            compsea [compnum + 1][compup] = 'O';
            board(sea1, compsea);
        }

        compships--;
        if (compships <= 0){
            break;
        }
    }
}