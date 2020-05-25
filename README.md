# Tic-Tac-Toe(PvP)

#include<iostream>
#include<vector>

using namespace std;

void valid(int &spot, vector <bool> taken){
    while ((spot != 0 && spot != 1 && spot != 2 && spot != 3 && spot != 4 && 
           spot != 5 && spot != 6 && spot != 7 && spot != 8) || taken[spot] == true){
        cout<<"That's not avaible\ngo again\n";
        cin>>spot;
    }

}    
bool winning_stuff(vector <char> board, int open, bool game_over){
        if(open==0){
            game_over = true;
            cout<<"your done\nno one won\n";
        }
        else if(board[0] == board[1] && board[1] == board[2]){
            game_over = true;
            cout<<board[1]<<" won the game\n";
        }
        else if(board[3] == board[4] && board[4] == board[5]){
            game_over = true;
            cout<<board[3]<<" won the game\n";
        }
        else if(board[6] == board[7] && board[7] == board[8]){
            game_over = true;
            cout<<board[6]<<" won the game\n";
        }
        else if(board[0] == board[3] && board[3] == board[6]){
            game_over = true;
            cout<<board[0]<<" won the game\n";
        }
        else if(board[1] == board[4] && board[4] == board[7]){
            game_over = true;
            cout<<board[1]<<" won the game\n";
        }
        else if(board[2] == board[5] && board[5] == board[8]){
            game_over = true;
            cout<<board[2]<<" won the game\n";
        }
        else if(board[0] == board[4] && board[4] == board[8]){
            game_over = true;
            cout<<board[0]<<" won the game\n";
        }
        else if(board[2] == board[4] && board[4] == board[6]){
            game_over = true;
            cout<<board[2]<<" won the game\n";
        }
        else{
            game_over = false;
        }
    return game_over;
}
void draw(vector <char> brd){
    cout<<"   |   |   \n";
    cout<<" "<<brd[0]<< " | "<<brd[1]<<" | "<<brd[2]<<" \n";
    cout<<"___|___|___\n";
    cout<<"   |   |   \n";
    cout<<" "<<brd[3]<< " | "<<brd[4]<<" | "<<brd[5]<<" \n";
    cout<<"___|___|___\n";
    cout<<"   |   |   \n";
    cout<<" "<<brd[6]<< " | "<<brd[7]<<" | "<<brd[8]<<" \n";
    cout<<"   |   |   \n";
}
int main(){
    vector <bool> taken (9, false);
    vector <char> board {'0','1','2','3','4','5','6','7','8'};
    int spot;
    int open = 9;
    bool game_over = false;
    
    cout<<"Tic-Tac-Toe\n";
    draw(board);
    
    while(game_over == false){
        cout<<"Player 1, where do you want to go\n";
        cin>>spot;
        valid(spot, taken);
        taken[spot] = true;
        board[spot] = 'X';
        open--;
        
        draw(board);
        game_over = winning_stuff(board, open, game_over);
        
        if (game_over == false) {
        cout<<"Player 2, where do you want to go\n";
        cin>>spot;
        valid(spot, taken);
        taken[spot] = true;
        board[spot] = 'O';
        open--;
        }
        
        draw(board);    
        game_over = winning_stuff(board, open, game_over);
        }
    }
