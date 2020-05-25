# Tic-Tac-Toe(Unbeatable)
#include <iostream> 
//#include <stdlib.h> 
//#include <unistd.h>
#include<vector>

using namespace std;

int xdepth = 0;

// forward declarations

int minimax(vector <char> board, vector <bool> taken, int depth, bool ismax);
int score(vector<char> board);
void draw(vector <char> brd);
void valid(int &spot, vector <bool> taken);
bool winning_stuff(vector <char> board, int open);

// function definitions

int score(vector<char> board){
    char winner;
    
        if((board[0] == 'X') && (board[1] == 'X') && (board[2] == 'X')){
            winner = 'X';
        }
        else if((board[3] == 'X') &&(board[4] == 'X') &&(board[5] == 'X')){
            winner = 'X';
        }
        else if((board[6] == 'X') &&(board[7] == 'X') &&(board[8] == 'X')){
            winner = 'X';
        }
        else if((board[0] == 'X') &&(board[3] == 'X') &&(board[6] == 'X')){
            winner = 'X';
        }
        else if((board[1] == 'X') &&(board[4] == 'X') &&(board[7] == 'X')){
            winner = 'X';
        }
        else if((board[2] == 'X') &&(board[5] == 'X') &&(board[8] == 'X')){
            winner = 'X';
        }
        else if((board[0] == 'X') &&(board[4] == 'X') &&(board[8] == 'X')){
            winner = 'X';
        }
        else if((board[2] == 'X') &&(board[4] == 'X') &&(board[6] == 'X')){
            winner = 'X';
        }
        else if((board[0] == 'O') &&(board[1] == 'O') && (board[2] == 'O')){
            winner = 'O';
        }
        else if((board[3] == 'O') &&(board[4] == 'O') &&(board[5] == 'O')){
            winner = 'O';
        }
        else if((board[6] == 'O') &&(board[7] == 'O') &&(board[8] == 'O')){
            winner = 'O';
        }
        else if((board[0] == 'O') &&(board[3] == 'O') &&(board[6] == 'O')){
            winner = 'O';
        }
        else if((board[1] == 'O') &&(board[4] == 'O') &&(board[7] == 'O')){
            winner = 'O';
        }
        else if((board[2] == 'O') &&(board[5] == 'O') &&(board[8] == 'O')){
            winner = 'O';
        }
        else if((board[0] == 'O') &&(board[4] == 'O') &&(board[8] == 'O')){
            winner = 'O';
        }
        else if((board[2] == 'O') &&(board[4] == 'O') &&(board[6] == 'O')){
            winner = 'O';
        }

  
    if (winner == 'X') 
    {
        return -10;
    }
    else if (winner == 'O')
    {
        return 10;
    }
    else  // it is either a tie, or the game is not yet over
    {
        return 0;
    }
}
int minimax(vector <char> board, vector <bool> taken, int depth, bool ismax){
    //cout << xdepth++ << endl;
    //draw(board);
    
    //if ((score(board) == 10) || (score(board) == -10) || (winning_stuff(board, depth)))  
    if ((depth == 0) || (winning_stuff(board, depth))) {
        //cout << "we are at a terminal node\n";
        //draw(board);
        return (score(board) + depth);
    }

    
    if (ismax)
    {
        int best = -1000;
        
        for (int ndx = 0; ndx < 9; ndx++) 
        {
            
            if (taken[ndx] == false)
            {
                board[ndx] = 'O';
                taken[ndx] = true;
                
                //cout << "looking at child node:  " << endl;
                //draw(board);
                int tmp = max(best, minimax(board, taken, depth-1, false));
                
                /* 
                cout << "looking at child node:  " << endl;
                draw(board);
                 cout << "max best: " << best << endl;*/
                // cout << "minimax:  " << tmp << endl << endl;
                
                best = max(best, tmp);
                
                board[ndx] = ndx+48;
                taken[ndx] = false;
            }
        }  

        return best;
    }
    else {
        int best = 1000;
        
        for (int ndx = 0; ndx < 9; ndx++) {
            
            if (taken[ndx] == false)
            {
                board[ndx] = 'X';
                taken[ndx] = true;
                
                 //cout << "looking at child node:  " << endl;
                 //draw(board);
                 int tmp = min(best, minimax(board, taken, depth-1, true));
                 /*
                 cout << "looking at child node:  " << endl;
                 draw(board);
                 cout << "min best: " << best << endl;*/
                 //cout << "minimax:  " << tmp << endl << endl;
                
                best = min(best, tmp);
        
                board[ndx] = ndx+48;
                taken[ndx] = false;
                
                
            }
        }  
        
        return best;
    }
}
void valid(int &spot, vector <bool> taken){
    while ((spot != 0 && spot != 1 && spot != 2 && spot != 3 && spot != 4 && 
           spot != 5 && spot != 6 && spot != 7 && spot != 8) || taken[spot] == true){
        cout<<"That's not avaible\ngo again\n";
        cin>>spot;
    }
}
bool winning_stuff(vector <char> board, int open){
    char winner;
        if((board[0] == 'X') && (board[1] == 'X') && (board[2] == 'X')){
            winner = 'X';
            return true;
        }
        else if((board[3] == 'X') &&(board[4] == 'X') &&(board[5] == 'X')){
            winner = 'X';
            return true;
        }
        else if((board[6] == 'X') &&(board[7] == 'X') &&(board[8] == 'X')){
            winner = 'X';
            return true;
        }
        else if((board[0] == 'X') &&(board[3] == 'X') &&(board[6] == 'X')){
            winner = 'X';
            return true;
        }
        else if((board[1] == 'X') &&(board[4] == 'X') &&(board[7] == 'X')){
            winner = 'X';
            return true;
        }
        else if((board[2] == 'X') &&(board[5] == 'X') &&(board[8] == 'X')){
            winner = 'X';
            return true;
        }
        else if((board[0] == 'X') &&(board[4] == 'X') &&(board[8] == 'X')){
            winner = 'X';
            return true;
        }
        else if((board[2] == 'X') &&(board[4] == 'X') &&(board[6] == 'X')){
            winner = 'X';
            return true;
        }
        
        else if((board[0] == 'O') && (board[1] == 'O') && (board[2] == 'O')){
            winner = 'O';
            return true;
        }
        else if((board[3] == 'O') &&(board[4] == 'O') &&(board[5] == 'O')){
            winner = 'O';
            return true;
        }
        else if((board[6] == 'O') &&(board[7] == 'O') &&(board[8] == 'O')){
            winner = 'O';
            return true;
        }
        else if((board[0] == 'O') &&(board[3] == 'O') &&(board[6] == 'O')){
            winner = 'O';
            return true;
        }
        else if((board[1] == 'O') &&(board[4] == 'O') &&(board[7] == 'O')){
            winner = 'O';
            return true;
        }
        else if((board[2] == 'O') &&(board[5] == 'O') &&(board[8] == 'O')){
            winner = 'O';
            return true;
        }
        else if((board[0] == 'O') &&(board[4] == 'O') &&(board[8] == 'O')){
            winner = 'O';
            return true;
        }
        else if((board[2] == 'O') &&(board[4] == 'O') &&(board[6] == 'O')){
            winner = 'O';
            return true;
        }
        else if(open==0){
            return true;
        }
        else {
            return false;
        }
    return winner;    
}
void draw(vector <char> brd){
    cout<<"Tic-Tac-Toe\nHuman vs. Computer Edition\n";
    cout<<"   |   |   \n";
    cout<<" "<<brd[0]<< " | "<<brd[1]<<" | "<<brd[2]<<" \n";
    cout<<"___|___|___\n";
    cout<<"   |   |   \n";
    cout<<" "<<brd[3]<< " | "<<brd[4]<<" | "<<brd[5]<<" \n";
    cout<<"___|___|___\n";
    cout<<"   |   |   \n";
    cout<<" "<<brd[6]<< " | "<<brd[7]<<" | "<<brd[8]<<" \n";
    cout<<"   |   |   \n\n";
}
int main(){
    vector <bool> taken (9, false);
    vector <char> board {'0','1','2','3','4','5','6','7','8'};
    int spot;
    int cspot;
    int open = 9;
    bool game_over = false;
    
    draw(board);
    
    while (game_over == false){
        
        // human (X) minimizing player
        
        cout << "Human, where do you want to go\n";
        cin >> spot;
        valid(spot, taken);
        taken[spot] = true;
        board[spot] = 'X';
        open--;
        system("clear");
        draw(board);
        
        game_over = winning_stuff(board, open);
        if ((game_over == true) && (open == 0)){
            cout << "It's a tie!!!\n";
            return 0;
        }
        else if (game_over == true){
            cout << "Humans win!!!\n";
            return 0;
        }
       
        // computer (O) maximizing
        int highest=  -100;
        int tempMinimaxValue;
        if (game_over == false) {
            cout<<"Computer is thinking...\n";
            
            // DEBUG:  figure out what is the cspot
            for (int i = 0; i < 9; i++){
                if (taken[i] == false){
                    board[i] = 'O';
                    taken[i] = true;
                    //cout << "staring from node with taking slot:  " << i << endl;
                    //draw(board);
                    tempMinimaxValue =  minimax(board, taken, open-1, false);
                    //cout << tempMinimaxValue << endl;
                    if (tempMinimaxValue > highest)
                    {
                        highest = tempMinimaxValue;
                        cspot = i;
                    }
                    board[i] = i+48;
                    taken[i] = false;
                }    
            }
            cout << "The best spot for me is: \n";
            cout << cspot << endl;
            //cvalid(cspot, taken, board);
            taken[cspot] = true;
            board[cspot] = 'O';
            open--;
        }
        
        system("clear");
        // gui
        draw(board);
    
        game_over = winning_stuff(board, open);
        if (game_over == true){
            cout << "My intellect is too high for you humans\nMuahaha!!!\n";
            return 0;
        }
    }
}
