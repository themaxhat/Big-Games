#include<iostream>
#include<stdlib.h>

using namespace std;

void board(string sea1[][10], char compsea[][10], string seensea[][10]){
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

    cout << endl;

    cout << " 1 |" << sea1[0][0]<< "|" << sea1[1][0]<< "|" << sea1[2][0]<< "|" << sea1[3][0]<< "|" << sea1[4][0]<< "|" << sea1[5][0]<< "|" << sea1[6][0]<< "|" << sea1[7][0]<< "|" << sea1[8][0]<< "|" << sea1[9][0]<< "|      1 |" << seensea[0][0]<< "|" << seensea[1][0]<< "|" << seensea[2][0]<< "|" << seensea[3][0]<< "|" << seensea[4][0]<< "|" << seensea[5][0]<< "|" << seensea[6][0]<< "|" << seensea[7][0]<< "|" << seensea[8][0]<< "|" << seensea[9][0]<< "|" << endl;
    cout << " 2 |" << sea1[0][1]<< "|" << sea1[1][1]<< "|" << sea1[2][1]<< "|" << sea1[3][1]<< "|" << sea1[4][1]<< "|" << sea1[5][1]<< "|" << sea1[6][1]<< "|" << sea1[7][1]<< "|" << sea1[8][1]<< "|" << sea1[9][1]<< "|      2 |" << seensea[0][1]<< "|" << seensea[1][1]<< "|" << seensea[2][1]<< "|" << seensea[3][1]<< "|" << seensea[4][1]<< "|" << seensea[5][1]<< "|" << seensea[6][1]<< "|" << seensea[7][1]<< "|" << seensea[8][1]<< "|" << seensea[9][1]<< "|" << endl;
    cout << " 3 |" << sea1[0][2]<< "|" << sea1[1][2]<< "|" << sea1[2][2]<< "|" << sea1[3][2]<< "|" << sea1[4][2]<< "|" << sea1[5][2]<< "|" << sea1[6][2]<< "|" << sea1[7][2]<< "|" << sea1[8][2]<< "|" << sea1[9][2]<< "|      3 |" << seensea[0][2]<< "|" << seensea[1][2]<< "|" << seensea[2][2]<< "|" << seensea[3][2]<< "|" << seensea[4][2]<< "|" << seensea[5][2]<< "|" << seensea[6][2]<< "|" << seensea[7][2]<< "|" << seensea[8][2]<< "|" << seensea[9][2]<< "|" << endl;
    cout << " 4 |" << sea1[0][3]<< "|" << sea1[1][3]<< "|" << sea1[2][3]<< "|" << sea1[3][3]<< "|" << sea1[4][3]<< "|" << sea1[5][3]<< "|" << sea1[6][3]<< "|" << sea1[7][3]<< "|" << sea1[8][3]<< "|" << sea1[9][3]<< "|      4 |" << seensea[0][3]<< "|" << seensea[1][3]<< "|" << seensea[2][3]<< "|" << seensea[3][3]<< "|" << seensea[4][3]<< "|" << seensea[5][3]<< "|" << seensea[6][3]<< "|" << seensea[7][3]<< "|" << seensea[8][3]<< "|" << seensea[9][3]<< "|" << endl;
    cout << " 5 |" << sea1[0][4]<< "|" << sea1[1][4]<< "|" << sea1[2][4]<< "|" << sea1[3][4]<< "|" << sea1[4][4]<< "|" << sea1[5][4]<< "|" << sea1[6][4]<< "|" << sea1[7][4]<< "|" << sea1[8][4]<< "|" << sea1[9][4]<< "|      5 |" << seensea[0][4]<< "|" << seensea[1][4]<< "|" << seensea[2][4]<< "|" << seensea[3][4]<< "|" << seensea[4][4]<< "|" << seensea[5][4]<< "|" << seensea[6][4]<< "|" << seensea[7][4]<< "|" << seensea[8][4]<< "|" << seensea[9][4]<< "|" << endl;
    cout << " 6 |" << sea1[0][5]<< "|" << sea1[1][5]<< "|" << sea1[2][5]<< "|" << sea1[3][5]<< "|" << sea1[4][5]<< "|" << sea1[5][5]<< "|" << sea1[6][5]<< "|" << sea1[7][5]<< "|" << sea1[8][5]<< "|" << sea1[9][5]<< "|      6 |" << seensea[0][5]<< "|" << seensea[1][5]<< "|" << seensea[2][5]<< "|" << seensea[3][5]<< "|" << seensea[4][5]<< "|" << seensea[5][5]<< "|" << seensea[6][5]<< "|" << seensea[7][5]<< "|" << seensea[8][5]<< "|" << seensea[9][5]<< "|" << endl;
    cout << " 7 |" << sea1[0][6]<< "|" << sea1[1][6]<< "|" << sea1[2][6]<< "|" << sea1[3][6]<< "|" << sea1[4][6]<< "|" << sea1[5][6]<< "|" << sea1[6][6]<< "|" << sea1[7][6]<< "|" << sea1[8][6]<< "|" << sea1[9][6]<< "|      7 |" << seensea[0][6]<< "|" << seensea[1][6]<< "|" << seensea[2][6]<< "|" << seensea[3][6]<< "|" << seensea[4][6]<< "|" << seensea[5][6]<< "|" << seensea[6][6]<< "|" << seensea[7][6]<< "|" << seensea[8][6]<< "|" << seensea[9][6]<< "|" << endl;
    cout << " 8 |" << sea1[0][7]<< "|" << sea1[1][7]<< "|" << sea1[2][7]<< "|" << sea1[3][7]<< "|" << sea1[4][7]<< "|" << sea1[5][7]<< "|" << sea1[6][7]<< "|" << sea1[7][7]<< "|" << sea1[8][7]<< "|" << sea1[9][7]<< "|      8 |" << seensea[0][7]<< "|" << seensea[1][7]<< "|" << seensea[2][7]<< "|" << seensea[3][7]<< "|" << seensea[4][7]<< "|" << seensea[5][7]<< "|" << seensea[6][7]<< "|" << seensea[7][7]<< "|" << seensea[8][7]<< "|" << seensea[9][7]<< "|" << endl;
    cout << " 9 |" << sea1[0][8]<< "|" << sea1[1][8]<< "|" << sea1[2][8]<< "|" << sea1[3][8]<< "|" << sea1[4][8]<< "|" << sea1[5][8]<< "|" << sea1[6][8]<< "|" << sea1[7][8]<< "|" << sea1[8][8]<< "|" << sea1[9][8]<< "|      9 |" << seensea[0][8]<< "|" << seensea[1][8]<< "|" << seensea[2][8]<< "|" << seensea[3][8]<< "|" << seensea[4][8]<< "|" << seensea[5][8]<< "|" << seensea[6][8]<< "|" << seensea[7][8]<< "|" << seensea[8][8]<< "|" << seensea[9][8]<< "|" << endl;
    cout << "10 |" << sea1[0][9]<< "|" << sea1[1][9]<< "|" << sea1[2][9]<< "|" << sea1[3][9]<< "|" << sea1[4][9]<< "|" << sea1[5][9]<< "|" << sea1[6][9]<< "|" << sea1[7][9]<< "|" << sea1[8][9]<< "|" << sea1[9][9]<< "|     10 |" << seensea[0][9]<< "|" << seensea[1][9]<< "|" << seensea[2][9]<< "|" << seensea[3][9]<< "|" << seensea[4][9]<< "|" << seensea[5][9]<< "|" << seensea[6][9]<< "|" << seensea[7][9]<< "|" << seensea[8][9]<< "|" << seensea[9][9]<< "|" << endl;

}

int main(){
    string sea1[10][10] = {};
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                sea1 [i][j] = "_";
            }
        }
    char compsea[10][10] = {};
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                compsea [i][j] = '_';
            }
        }
    string seensea[10][10] = {};
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                seensea [i][j] = "_";
            }
        }
    bool taken1[10][10] = {};
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                taken1 [i][j] = false;
            }
        }
    bool comptaken[10][10] = {};
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                comptaken [i][j] = false;
            }
        }

    int ships1 = 1;
    int compships = 10;
    int turn = 1;
    int length1;
    int complength;
    int up1;
    int compup;
    int acrossnum1;
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
    int attack1;
    int upattack1;
    int compattack;
    int compupattack;

    string direction1;

    char across1;
    char attackacross;

    bool over = false;

    srand(time(NULL));

    board(sea1, compsea, seensea);    



    //Placing Boats
    while (turn == 1){

        cout << "You have " << ships1 << " ships left to place \nWhat letter across do you want to use?\n";
        //cin >> across1;
        across1 = 'c';
        cout << "What number up do you want to use?\n";
        //cin >> up1;
        up1 = 5;
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
        board(sea1, compsea, seensea);

        cout << "There are " << ship1_6 << " ships with a length of 6, " << ship1_4 << " ships with a length of four, " << ship1_3 << " ships with a length of three, and " << ship1_2 << " ships with a length of 2\n";
        cout << "What is the length of the ship you want to use?\n";
        //cin >> length1;
        length1 = 6;
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
        //cin >> direction1;
        direction1 = "right";
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
            taken1 [acrossnum1][up1 - 2] = true;
            taken1 [acrossnum1][up1 - 3] = true;
            taken1 [acrossnum1][up1 - 4] = true;
            taken1 [acrossnum1][up1 - 5] = true;
            taken1 [acrossnum1][up1 - 6] = true;
            board(sea1, compsea, seensea);
        }
        if ((direction1 == "down") && (length1 == 6)){
            sea1 [acrossnum1][up1] = 'O';
            sea1 [acrossnum1][up1 + 1] = 'O';
            sea1 [acrossnum1][up1 + 2] = 'O';
            sea1 [acrossnum1][up1 + 3] = 'O';
            sea1 [acrossnum1][up1 + 4] = 'O';
            taken1 [acrossnum1][up1] = true;
            taken1 [acrossnum1][up1 + 1] = true;
            taken1 [acrossnum1][up1 + 2] = true;
            taken1 [acrossnum1][up1 + 3] = true;
            taken1 [acrossnum1][up1 + 4] = true;
            board(sea1, compsea, seensea);
        }
        if ((direction1 == "left") && (length1 == 6)){
            sea1 [acrossnum1 - 1][up1 - 1] = 'O';
            sea1 [acrossnum1 - 2][up1 - 1] = 'O';
            sea1 [acrossnum1 - 3][up1 - 1] = 'O';
            sea1 [acrossnum1 - 4][up1 - 1] = 'O';
            sea1 [acrossnum1 - 5][up1 - 1] = 'O';
            taken1 [acrossnum1 - 1][up1 - 1] = true;
            taken1 [acrossnum1 - 2][up1 - 1] = true;
            taken1 [acrossnum1 - 3][up1 - 1] = true;
            taken1 [acrossnum1 - 4][up1 - 1] = true;
            taken1 [acrossnum1 - 5][up1 - 1] = true;
            board(sea1, compsea, seensea);
        }
        if ((direction1 == "right") && (length1 == 6)){
            sea1 [acrossnum1 + 1][up1 - 1] = 'O';
            sea1 [acrossnum1 + 2][up1 - 1] = 'O';
            sea1 [acrossnum1 + 3][up1 - 1] = 'O';
            sea1 [acrossnum1 + 4][up1 - 1] = 'O';
            sea1 [acrossnum1 + 5][up1 - 1] = 'O';
            taken1 [acrossnum1 + 1][up1 - 1] = true;
            taken1 [acrossnum1 + 2][up1 - 1] = true;
            taken1 [acrossnum1 + 3][up1 - 1] = true;
            taken1 [acrossnum1 + 4][up1 - 1] = true;
            taken1 [acrossnum1 + 5][up1 - 1] = true;
            board(sea1, compsea, seensea);
        }

        //ship length 4
        if ((direction1 == "up") && (length1 == 4)){
            sea1 [acrossnum1][up1 - 2] = 'O';
            sea1 [acrossnum1][up1 - 3] = 'O';
            sea1 [acrossnum1][up1 - 4] = 'O';
            taken1 [acrossnum1][up1 - 2] = true;
            taken1 [acrossnum1][up1 - 3] = true;
            taken1 [acrossnum1][up1 - 4] = true;
            board(sea1, compsea, seensea);
        }
        if ((direction1 == "down") && (length1 == 4)){
            sea1 [acrossnum1][up1] = 'O';
            sea1 [acrossnum1][up1 + 1] = 'O';
            sea1 [acrossnum1][up1 + 2] = 'O';
            taken1 [acrossnum1][up1] = true;
            taken1 [acrossnum1][up1 + 1] = true;
            taken1 [acrossnum1][up1 + 2] = true;
            board(sea1, compsea, seensea);
        }
        if ((direction1 == "left") && (length1 == 4)){
            sea1 [acrossnum1 - 1][up1 - 1] = 'O';
            sea1 [acrossnum1 - 2][up1 - 1] = 'O';
            sea1 [acrossnum1 - 3][up1 - 1] = 'O';
            taken1 [acrossnum1 - 1][up1 - 1] = true;
            taken1 [acrossnum1 - 2][up1 - 1] = true;
            taken1 [acrossnum1 - 3][up1 - 1] = true;
            board(sea1, compsea, seensea);
        }
        if ((direction1 == "right") && (length1 == 4)){
            sea1 [acrossnum1 + 1][up1 - 1] = 'O';
            sea1 [acrossnum1 + 2][up1 - 1] = 'O';
            sea1 [acrossnum1 + 3][up1 - 1] = 'O';
            taken1 [acrossnum1 + 1][up1 - 1] = true;
            taken1 [acrossnum1 + 2][up1 - 1] = true;
            taken1 [acrossnum1 + 3][up1 - 1] = true;
            board(sea1, compsea, seensea);
        }

        //ship length 3
        if ((direction1 == "up") && (length1 == 3)){
            sea1 [acrossnum1][up1 - 1] = 'O';
            sea1 [acrossnum1][up1 - 2] = 'O';
            taken1 [acrossnum1][up1 - 1] = true;
            taken1 [acrossnum1][up1 - 2] = true;
            board(sea1, compsea, seensea);
        }
        if ((direction1 == "down") && (length1 == 3)){
            sea1 [acrossnum1][up1] = 'O';
            sea1 [acrossnum1][up1 + 1] = 'O';
            taken1 [acrossnum1][up1] = true;
            taken1 [acrossnum1][up1 + 1] = true;
            board(sea1, compsea, seensea);
        }
        if ((direction1 == "left") && (length1 == 3)){
            sea1 [acrossnum1 - 1][up1 - 1] = 'O';
            sea1 [acrossnum1 - 2][up1 - 1] = 'O';
            taken1 [acrossnum1 - 1][up1 - 1] = true;
            taken1 [acrossnum1 - 2][up1 - 1] = true;
            board(sea1, compsea, seensea);
        }
        if ((direction1 == "right") && (length1 == 3)){
            sea1 [acrossnum1 + 1][up1 - 1] = 'O';
            sea1 [acrossnum1 + 2][up1 - 1] = 'O';
            taken1 [acrossnum1 + 1][up1 - 1] = true;
            taken1 [acrossnum1 + 2][up1 - 1] = true;
            board(sea1, compsea, seensea);
        }

        //ship length 2
        if ((direction1 == "up") && (length1 == 2)){
            sea1 [acrossnum1][up1 - 2] = 'O';
            taken1 [acrossnum1][up1 - 2] = true;
            board(sea1, compsea, seensea);
        }
        if ((direction1 == "down") && (length1 == 2)){
            sea1 [acrossnum1][up1] = 'O';
            taken1 [acrossnum1][up1] = true;
            board(sea1, compsea, seensea);
        }
        if ((direction1 == "left") && (length1 == 2)){
            sea1 [acrossnum1 - 1][up1 - 1] = 'O';
            taken1 [acrossnum1 - 1][up1 - 1] = true;
            board(sea1, compsea, seensea);
        }
        if ((direction1 == "right") && (length1 == 2)){
            sea1 [acrossnum1 + 1][up1 - 1] = 'O';
            taken1 [acrossnum1 + 1][up1 - 1] = true;
            board(sea1, compsea, seensea);
        }

        ships1--;

        if (ships1 <= 0){
            break;
        }
    }

    //computer placing boats
    turn = 2;

    while (turn == 2){
        srand (time(NULL));
        int compacross = rand() % 10;
        int compup = rand() % 10;
  
        while (comptaken[compacross][compup] == true){
            srand (time(NULL));
            compacross = rand() % 9;
            compup = rand() % 9;
        }

        compsea [compacross][compup] = 'O';
        comptaken [compacross][compup] = true;
        board(sea1, compsea, seensea);

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
        compdirection = rand() % 4;

        //ship length 6
        if ((compdirection == 0) && (complength == 6)){
            compsea [compacross][compup - 1] = 'O';
            compsea [compacross][compup - 2] = 'O';
            compsea [compacross][compup - 3] = 'O';
            compsea [compacross][compup - 4] = 'O';
            compsea [compacross][compup - 5] = 'O';
            comptaken [compacross][compup - 1] = true;
            comptaken [compacross][compup - 2] = true;
            comptaken [compacross][compup - 3] = true;
            comptaken [compacross][compup - 4] = true;
            comptaken [compacross][compup - 5] = true;
            board(sea1, compsea, seensea);
        }
        if ((compdirection == 1) && (complength == 6)){
            compsea [compacross][compup + 1] = 'O';
            compsea [compacross][compup + 2] = 'O';
            compsea [compacross][compup + 3] = 'O';
            compsea [compacross][compup + 4] = 'O';
            compsea [compacross][compup + 5] = 'O';
            comptaken [compacross][compup + 1] = true;
            comptaken [compacross][compup + 2] = true;
            comptaken [compacross][compup + 3] = true;
            comptaken [compacross][compup + 4] = true;
            comptaken [compacross][compup + 5] = true;
            board(sea1, compsea, seensea);
        }
        if ((compdirection == 2) && (complength == 6)){
            compsea [compacross - 1][compup] = 'O';
            compsea [compacross - 2][compup] = 'O';
            compsea [compacross - 3][compup] = 'O';
            compsea [compacross - 4][compup] = 'O';
            compsea [compacross - 5][compup] = 'O';
            comptaken [compacross - 1][compup] = true;
            comptaken [compacross - 2][compup] = true;
            comptaken [compacross - 3][compup] = true;
            comptaken [compacross - 4][compup] = true;
            comptaken [compacross - 5][compup] = true;
            board(sea1, compsea, seensea);
        }
        if ((compdirection == 3) && (complength == 6)){
            compsea [compacross + 1][compup] = 'O';
            compsea [compacross + 2][compup] = 'O';
            compsea [compacross + 3][compup] = 'O';
            compsea [compacross + 4][compup] = 'O';
            compsea [compacross + 5][compup] = 'O';
            comptaken [compacross + 1][compup] = true;
            comptaken [compacross + 2][compup] = true;
            comptaken [compacross + 3][compup] = true;
            comptaken [compacross + 4][compup] = true;
            comptaken [compacross + 5][compup] = true;
            board(sea1, compsea, seensea);
        }

        //ship length 4
        if ((compdirection == 0) && (complength == 4)){
            compsea [compacross][compup - 1] = 'O';
            compsea [compacross][compup - 2] = 'O';
            compsea [compacross][compup - 3] = 'O';
            comptaken [compacross][compup - 1] = true;
            comptaken [compacross][compup - 2] = true;
            comptaken [compacross][compup - 3] = true;
            board(sea1, compsea, seensea);
        }
        if ((compdirection == 1) && (complength == 4)){
            compsea [compacross][compup + 1] = 'O';
            compsea [compacross][compup + 2] = 'O';
            compsea [compacross][compup + 3] = 'O';
            comptaken [compacross][compup + 1] = true;
            comptaken [compacross][compup + 2] = true;
            comptaken [compacross][compup + 3] = true;
            board(sea1, compsea, seensea);
        }
        if ((compdirection == 2) && (complength == 4)){
            compsea [compacross - 1][compup] = 'O';
            compsea [compacross - 2][compup] = 'O';
            compsea [compacross - 3][compup] = 'O';
            comptaken [compacross - 1][compup] = true;
            comptaken [compacross - 2][compup] = true;
            comptaken [compacross - 3][compup] = true;
            board(sea1, compsea, seensea);
        }
        if ((compdirection == 3) && (complength == 4)){
            compsea [compacross + 1][compup] = 'O';
            compsea [compacross + 2][compup] = 'O';
            compsea [compacross + 3][compup] = 'O';
            comptaken [compacross + 1][compup] = true;
            comptaken [compacross + 2][compup] = true;
            comptaken [compacross + 3][compup] = true;
            board(sea1, compsea, seensea);
        }

        //ship length 3
        if ((compdirection == 0) && (complength == 3)){
            compsea [compacross][compup - 1] = 'O';
            compsea [compacross][compup - 2] = 'O';
            comptaken [compacross][compup - 1] = true;
            comptaken [compacross][compup - 2] = true;
            board(sea1, compsea, seensea);
        }
        if ((compdirection == 1) && (complength == 3)){
            compsea [compacross][compup + 1] = 'O';
            compsea [compacross][compup + 2] = 'O';
            comptaken [compacross][compup + 1] = true;
            comptaken [compacross][compup + 2] = true;
            board(sea1, compsea, seensea);
        }
        if ((compdirection == 2) && (complength == 3)){
            compsea [compacross - 1][compup] = 'O';
            compsea [compacross - 2][compup] = 'O';
            comptaken [compacross - 1][compup] = true;
            comptaken [compacross - 2][compup] = true;
            board(sea1, compsea, seensea);
        }
        if ((compdirection == 3) && (complength == 3)){
            compsea [compacross + 1][compup] = 'O';
            compsea [compacross + 2][compup] = 'O';
            comptaken [compacross + 1][compup] = true;
            comptaken [compacross + 2][compup] = true;
            board(sea1, compsea, seensea);
        }

        //ship length 2
        if ((compdirection == 0) && (complength == 2)){
            compsea [compacross][compup - 1] = 'O';
            comptaken [compacross][compup - 1] = true;
            board(sea1, compsea, seensea);
        }
        if ((compdirection == 1) && (complength == 2)){
            compsea [compacross][compup + 1] = 'O';
            comptaken [compacross][compup + 1] = true;
            board(sea1, compsea, seensea);
        }
        if ((compdirection == 2) && (complength == 2)){
            compsea [compacross - 1][compup] = 'O';
            comptaken [compacross - 1][compup] = true;
            board(sea1, compsea, seensea);
        }
        if ((compdirection == 3) && (complength == 2)){
            compsea [compacross + 1][compup] = 'O';
            comptaken [compacross + 1][compup] = true;
            board(sea1, compsea, seensea);
        }

/*
        cout << endl;
        cout << "Coordinates: (" << compacross + 1 << ", " << compup + 1 << ")" << endl;
        cout << "Ship Length: " << complength << endl;
        cout << "Direction: " << compdirection << endl << endl;
*/

        compships--;

        if (compships <= 0){
            break;
        }
    }

    turn = 1;

    //Attacking
    while (over == false){
        if (turn == 1){
            cout << "What letter do you want to attack\n";
            cin >> attackacross;
            switch (attackacross){
                case 'A':
                    attack1 = 0;
                    break;
                case 'B':
                    attack1 = 1;
                    break;
                case 'C':
                    attack1 = 2;
                    break;
                case 'D':
                    attack1 = 3;
                    break;
                case 'E':
                    attack1 = 4;
                    break;
                case 'F':
                    attack1 = 5;
                    break;
                case 'G':
                    attack1 = 6;
                    break;
                case 'H':
                    attack1 = 7;
                    break;
                case 'I':
                    attack1 = 8;
                    break;
                case 'J':
                    attack1 = 9;
                    break;  
                case 'a':
                    attack1 = 0;
                    break;
                case 'b':
                    attack1 = 1;
                    break;
                case 'c':
                    attack1 = 2;
                    break;
                case 'd':
                    attack1 = 3;
                    break;
                case 'e':
                    attack1 = 4;
                    break;
                case 'f':
                    attack1 = 5;
                    break;
                case 'g':
                    attack1 = 6;
                    break;
                case 'h':
                    attack1 = 7;
                    break;
                case 'i':
                    attack1 = 8;
                    break;
                case 'j':
                    attack1 = 9;
                    break;   
            }
            cout << "What number up do you want to attack\n";
            cin >> up1;            
            if (comptaken[attack1][up1 - 1] == true){
                seensea[attack1][up1 - 1] = "\033[1;31mX\033[0m";
            }
            else {
                seensea[attack1][up1 - 1] = "X";
            }

            board(sea1, compsea, seensea);
            turn = 2;
        }

        if (turn == 2){
            compattack = 3;
            compupattack = 5;            
            if (taken1[compattack][compupattack - 1] == true){
                sea1[compattack][compupattack - 1] = "\033[1;31mX\033[0m";
            }
            else {
                sea1[compattack][compupattack - 1] = "X";
            }

            board(sea1, compsea, seensea);
            turn = 1;
        }
    }
    if (over == true){
        cout << "game over!";
    }
}
