#include<iostream>
#include<vector>

using namespace std;

bool game(char board[][7], bool taken[][7], int &score){

    //rows

    for (int row = 0; row < 6; row++){
        char last = 'A';
        int counter = 0;
        for (int column = 0; column < 7; column++){
            if (board[row][column] == last){
                counter++;
                if (counter == 4){
                    if (last == 'X'){
                        score = -10;
                    }
                    if (last == 'O'){
                        score = 10;
                    }
                    return true;
                }
            }
            else if (taken[row][column] == true){
                counter = 1;
                last = board[row][column];
            }
            else {
                counter = 0;
                last = 'A';
            }
        }
    }

    //columns

    for (int column = 0; column < 7; column++){
        char last = 'A';
        int counter = 0;
        for (int row = 0; row < 6; row++){
            if (board[row][column] == last){
                counter++;
                if (counter == 4){
                    if (last == 'X'){
                        score = -10;
                    }
                    if (last == 'O'){
                        score = 10;
                    }
                    return true;
                }
            }
            else if (taken[row][column] == true){
                counter = 1;
                last = board[row][column];
            }
            else {
                counter = 0;
                last = 'A';
            }
        }
    }

    // up diagonals

    for (int row = 0; row < 6; row++){
        for (int column = 0; column < 7; column++){
            if ((board[row][column] == board[row + 1][column + 1]) 
            && (board[row][column] == board[row + 2][column + 2])
            && (board[row][column] == board[row + 3][column + 3])
            && (board[row][column] != '_')
            && (row + 3 < 6) && (column + 3 < 7)){
                if (board[row][column] == 'X'){
                    score = -10;
                    }
                if (board[row][column] == 'O'){
                    score = 10;
                }
                return true;
            }
        }
    }

    //down diagonals

    for (int row = 0; row < 6; row++){
        for (int column = 6; column >= 0; column--){
            if ((board[row][column] == board[row + 1][column - 1]) 
            && (board[row][column] == board[row + 2][column - 2])
            && (board[row][column] == board[row + 3][column - 3])
            && (board[row][column] != '_')
            && (row + 3 < 6) && (column - 3 >= 0)){
                if (board[row][column] == 'X'){
                    score = -10;
                }
                if (board[row][column] == 'O'){
                    score = 10;
                }
                return true;
            }
        }
    }

    score = 0;
    return false;
}

void draw(char board[][7]){
    cout<<"          CONNECT 4\n";
    cout<<" _1_ _2_ _3_ _4_ _5_ _6_ _7_ "<<endl;
    cout<<"| "<<board[5][0]<<" | "<<board[5][1]<<" | "<<board[5][2]<<" | "<<board[5][3]<<" | "<<board[5][4]<<" | "<<board[5][5]<<" | "<<board[5][6]<<" |\n";
    cout<<"| "<<board[4][0]<<" | "<<board[4][1]<<" | "<<board[4][2]<<" | "<<board[4][3]<<" | "<<board[4][4]<<" | "<<board[4][5]<<" | "<<board[4][6]<<" |\n";
    cout<<"| "<<board[3][0]<<" | "<<board[3][1]<<" | "<<board[3][2]<<" | "<<board[3][3]<<" | "<<board[3][4]<<" | "<<board[3][5]<<" | "<<board[3][6]<<" |\n";
    cout<<"| "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<" | "<<board[2][3]<<" | "<<board[2][4]<<" | "<<board[2][5]<<" | "<<board[2][6]<<" |\n";
    cout<<"| "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<" | "<<board[1][3]<<" | "<<board[1][4]<<" | "<<board[1][5]<<" | "<<board[1][6]<<" |\n";
    cout<<"| "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<" | "<<board[0][3]<<" | "<<board[0][4]<<" | "<<board[0][5]<<" | "<<board[0][6]<<" |\n";

    /*
    for (int row = 5; row >= 0; row--){
        for (int column = 0; column < 7; column++){
            cout << "board[" << row << "][" << column << "] ";
        }
        cout << endl;
    }
    */
}

int minimax(char board[][7], bool taken[][7], vector <int> bottom, int alpha, int beta, int depth, bool ismax){
    int score;

    //base case
    //if ((depth == 0) || (game(board, taken, score))) {
    if ((game(board, taken, score)) || (depth == 0)) {

        //cout << "looking at (terminal) node with value: " << score << endl;
        //draw(board);
        //cout << "score for this board is " << score << endl;
        return (score + depth);
        //return (score);
    }

    //maximizer

    if (ismax)
    {
        int best = -1000;

        for (int c = 0; c < 7; c++) 
        {
            if (bottom[c] < 6)
            {
                board[bottom [c]][c] = 'O';
                taken[bottom [c]][c] = true;
                bottom [c] ++;

                        //cout << "looking at (maximize) child node: " << c << endl;
                        //draw(board);

                best = max(best, minimax(board, taken, bottom, alpha, beta, depth-1, false));

                bottom [c] --;
                board[bottom [c]][c] = '_';
                taken[bottom [c]][c] = false;

                alpha = max(alpha, best);
                if (beta <= alpha){
                    break;
                }
            }
        }

        return best;
    }

    //minimizer

    else {
        int best = 1000;


        for (int c = 0; c < 7; c++){
            if (bottom[c] < 6)
            {
                board[bottom [c]][c] = 'X';
                taken[bottom [c]][c] = true;
                bottom [c] ++;

                        //cout << "looking at (minimize) child node: " << c << endl;
                        //draw(board);

                best = min(best, minimax(board, taken, bottom, alpha, beta, depth-1, true));
                bottom [c] --;

                board[bottom [c]][c] = '_';
                taken[bottom [c]][c] = false;

                beta = min(beta, best);
                if (beta <= alpha){
                    break;
                }
            }
        }
        return best;
    }
}

int main(){
    vector <int> bottom {0, 0, 0, 0, 0, 0, 0};
    bool taken[6][7] = {};
    char board[6][7] = {};

    for (int row = 0; row < 6; row++){
        for (int column = 0; column < 7; column++){
            board[row][column] = '_';
        }
    }

    int spotA;
    int spotB;

    int open = 42;

    bool over = false;
    string choice;
    int score;

    int alpha = -10000;
    int beta = 10000;

    cout << "Welcome to CONNECT 4 Code Edition!\nWould you like to play vs. an A.I. or vs a friend\n";
    cin >> choice;
        while ((choice != "AI") && (choice != "friend")){
            cout << "*invalid*\nAI or friend?\n";
            cin >> choice;
        }

    if (choice == "friend"){
        system("clear");
        draw(board);

        while (over == false){
            if (over == true) {
                cout<<"Player 2 wins!";
            }
            else {
                cout<<"Player 1, which column do you want to use\n";
                cin>>spotA;
                //validA(spotA, taken, bottom);
                spotA = spotA - 1;
                taken [bottom [spotA] ] [spotA] = true;
                board [bottom [spotA] ] [spotA] = 'X';
                bottom [spotA] ++;
                open--;
            }

            system("clear");
            draw(board);
            over = game(board, taken, score);
            //cout << score << endl;

            if (over == true) {
                cout<<"Player 1 wins!";
            }
            else {
                cout<<"Player 2, which column do you want to use\n";
                cin>>spotB;
                //validB(spot, taken);
                spotB = spotB - 1;
                taken [bottom [spotB]] [spotB] = true;
                board [bottom [spotB]] [spotB] = 'O';
                bottom [spotB] ++;
                open--;
            }

            //cout<<minimax(board, taken, bottom, open, true);
            system("clear");
            draw(board);
            over = game(board, taken, score);
            //cout << score << endl;
        }
    }

    else {
    while (over == false){
        system("clear");
        draw(board);
        //cout << score << endl;

        cout<<"Player 1, which column do you want to use\n";
        cin>>spotA;
        spotA = spotA - 1;
        board [bottom [spotA] ] [spotA] = 'X';
        taken [bottom [spotA] ] [spotA] = true;
        bottom [spotA] ++;
        open--;

        over = game(board, taken, score);

        system("clear");
        draw(board);
        //cout << score << endl;

        if (over) {
            cout<<"human wins!";
        }

        else {
            int highest= -9999;
            int tempMinimaxValue;

            for (int i = 0; i < 7; i++){
                if (bottom[i] < 6){
                    board[bottom [i]][i] = 'O';
                    taken[bottom [i]][i] = true;
                    bottom [i] ++;

                        //cout << "looking at (main) child node: " << i << endl;
                        //draw(board);

                    tempMinimaxValue =  minimax(board, taken, bottom, alpha, beta, 9, false);

                    if (tempMinimaxValue > highest) {
                        highest = tempMinimaxValue;
                        spotB = i;
                    }

                    bottom [i] --;
                    board[bottom [i]][i] = '_';
                    taken[bottom [i]][i] = false;
                }
            }

            board[bottom [spotB]][spotB] = 'O';
            taken[bottom [spotB]][spotB] = true;
            bottom [spotB] ++;
            open--;

            over = game(board, taken, score);
            if (over) {
                cout<<"AI wins!";
            }
        }
    }
    //system("clear");
    draw(board);
    //cout << score << endl;
    }
}
