#include <iostream>
#include <stdlib.h>
#include <vector>
#include <iomanip> 
#include <unistd.h> 

//change these to change the size of the board 
//and the number of mines

#define xLength 18
#define yLength 14
#define minesNumber 40

using namespace std;

/*
************************EDITOR NOTE************************
 **x and y are swapped so some variables may be confusing**
***********************************************************
*/

void clearSection (int xCor, int yCor, string board[][xLength], string boardNums[][xLength], bool mines[][xLength], bool seen[][xLength]);
void underground(string boardNums[][xLength]);
void land(int looseMines, string board[][xLength]);
void dig (int &looseMines, int &hiddenLooseMines, bool &game, string board[][xLength], bool flagged[][xLength], bool mines[][xLength], string boardNums[][xLength], bool seen[][xLength]);
void plant(bool mines[][xLength], string boardNums[][xLength]);
bool gameOver(bool flagged[][xLength], bool mines[][xLength], string board[][xLength]);


int main(){

	int looseMines = minesNumber;
	int hiddenLooseMines = looseMines;
	
	bool gameOn = true;
	
	string board[yLength][xLength] = {};
	string boardNums[yLength][xLength] = {};

	bool mines[yLength][xLength] = {};
	bool flagged[yLength][xLength] = {};
	bool seen[yLength][xLength] = {};
	
	srand (time(NULL));
	
	for (int g = 0; g < yLength; g++){
		for (int h = 0; h < xLength; h++){
			board[g][h] = " - ";
			boardNums[g][h] = "   ";
			seen[g][h] = false;
		}
	}

	plant(mines, boardNums);

	while (gameOver(flagged, mines, board) == false && gameOn == true){		
		land(looseMines, board);
		//underground(boardNums);

		dig(looseMines, hiddenLooseMines, gameOn, board, flagged, mines, boardNums, seen);
	}

	return 0;
}

//Clearing a whole section of blank spots when just one blank is dug
void clearSection (int xCor, int yCor, string board[][xLength], string boardNums[][xLength], bool mines[][xLength], bool seen[yLength][xLength]){

	//land(minesNumber, board);
	//usleep(1000);

	if (boardNums[xCor][yCor] == "   "){
		board[xCor][yCor] = boardNums[xCor][yCor];
		seen[xCor][yCor] = true;
		
		//North
		if (yCor + 1 < xLength && seen[xCor][yCor + 1] == false){ 
			if (mines[xCor][yCor + 1] == false){
				board[xCor][yCor + 1] = boardNums[xCor][yCor + 1];
				clearSection(xCor, yCor+1, board, boardNums, mines, seen);
			}
		}

		//South
		if (yCor - 1 >= 0 && seen[xCor][yCor - 1] == false){ 
			if (mines[xCor][yCor - 1] == false){
				board[xCor][yCor - 1] = boardNums[xCor][yCor - 1];
				clearSection(xCor, yCor-1, board, boardNums, mines, seen);
			}
		}		

		//East
		if (xCor - 1 >= 0 && seen[xCor - 1][yCor] == false){ 
			if (mines[xCor - 1][yCor] == false){
				board[xCor - 1][yCor] = boardNums[xCor - 1][yCor];
				clearSection(xCor-1, yCor, board, boardNums, mines, seen);
			}
		}			

		//West
		if (xCor + 1 < yLength && seen[xCor + 1][yCor] == false){ 
			if (mines[xCor + 1][yCor] == false){
				board[xCor + 1][yCor] = boardNums[xCor + 1][yCor];
				clearSection(xCor+1, yCor, board, boardNums, mines, seen);
			}
		}	

		//North East
		if (xCor - 1 >= 0 && yCor + 1 < xLength && seen[xCor - 1][yCor + 1] == false){ 
			if (mines[xCor - 1][yCor + 1] == false){
				board[xCor - 1][yCor + 1] = boardNums[xCor - 1][yCor + 1];
				clearSection(xCor-1, yCor+1, board, boardNums, mines, seen);
			}		
		}

		//North West
		if (xCor + 1 < yLength && yCor + 1 < xLength && seen[xCor + 1][yCor + 1] == false){
			if(mines[xCor + 1][yCor + 1] == false){
				board[xCor + 1][yCor + 1] = boardNums[xCor + 1][yCor + 1];
				clearSection(xCor+1, yCor+1, board, boardNums, mines, seen);
			}
		}	

		//South East
		if (xCor - 1 >= 0 && yCor - 1 >= 0 && seen[xCor - 1][yCor - 1] == false){ 
			if (mines[xCor - 1][yCor - 1] == false){
				board[xCor - 1][yCor - 1] = boardNums[xCor - 1][yCor - 1];
				clearSection(xCor-1, yCor-1, board, boardNums, mines, seen);
			}
		}	

		//South West
		if (xCor + 1 < yLength && yCor - 1 >= 0 && seen[xCor + 1][yCor - 1] == false){ 
			if (mines[xCor + 1][yCor - 1] == false){
				board[xCor + 1][yCor - 1] = boardNums[xCor + 1][yCor - 1];
				clearSection(xCor+1, yCor-1, board, boardNums, mines, seen);
			}
		}
	}
}

//Test case so I know where the mines are
void underground(string boardNums[][xLength]){
	cout << "            MINESWEEPER          " << endl;
	for (int i = (yLength - 1); i >= 0; i--){
		if (i < 10){
			cout << i << "  ";
		}
		else {
			cout << i << " ";
		}
		for (int j = 0; j < xLength; j++){
			cout << boardNums[i][j];
		}
		cout << endl;
	}
	cout << endl << "    ";
	for (int i = 0; i < xLength; i++){
		if (i < 10){
			cout << i << "  ";
		}
		else {
			cout << i << " ";
		}
	}
	cout << endl << endl;
}

//the board
void land(int looseMines, string board[][xLength]){
	system("clear");

	cout << "    MINESWEEPER" << "    Flags Left: " << looseMines << endl;
	for (int i = (yLength - 1); i >= 0; i--){
		if (i < 10){
			cout << i << "  ";
		}
		else {
			cout << i << " ";
		}
		for (int j = 0; j < xLength; j++){
			cout << board[i][j];
		}
		cout << endl;
	}
	cout << endl << "    ";
	for (int i = 0; i < xLength; i++){
		if (i < 10){
			cout << i << "  ";
		}
		else {
			cout << i << " ";
		}
	}
	cout << endl << endl;
	

}

//"digging" a spot (or flagging)
void dig (int &looseMines, int &hiddenLooseMines, bool &gameOn, string board[][xLength], bool flagged[][xLength], bool mines[][xLength], string boardNums[][xLength], bool seen[][xLength]){
	int xCor;
	int yCor;
	string digOrFlag;
	int numOfMoves = 0;
	
	cout << "x coordinate: ";
	cin >> yCor;
	while (yCor > (xLength - 1) || yCor < 0){
		cout << "That's not on the graph, try again. ";
		cin >> yCor;
		cout << endl;
	}
	cout << "y coordinate: ";
	cin >> xCor;
	while (xCor > (yLength - 1) || xCor < 0){
		cout << "That's not on the graph, try again. ";
		cin >> xCor;
		cout << endl;
	}
	cout << endl;

	cout << "dig or flag? (or cancel) ";
	cin >> digOrFlag;

	if (digOrFlag != "dig" && digOrFlag != "flag" && digOrFlag != "cancel"){
		cout << endl << "Not gonna work. Try again" << endl;

		dig(looseMines, hiddenLooseMines, gameOn, board, flagged, mines, boardNums, seen);
	}

	if (numOfMoves == 0){
		while (boardNums[xCor][yCor] != "   "){
			plant(mines, boardNums);
		}
		numOfMoves++;
	}

	//uncovering a spot
	if (digOrFlag == "dig"){
		if (mines[xCor][yCor] == true){
			board[xCor][yCor] = " \033[1;31m*\033[0m ";
			land(looseMines, board);
			cout << "BOOM" << endl << "game over" << endl;
			gameOn = false;
			gameOver(flagged, mines, board);
		}
		else if (boardNums[xCor][yCor] == "   "){
			clearSection(xCor, yCor, board, boardNums, mines, seen);
		}
		else {
			board[xCor][yCor] = boardNums[xCor][yCor];
		}
	}

	//flagging/unflagging a spot
	if (digOrFlag == "flag"){
		if (flagged[xCor][yCor] == false){
			board[xCor][yCor] = " \033[31m!\033[0m ";
			flagged[xCor][yCor] = true;
			for (int i = 0; i < yLength; i++){
				for (int j = 0; j < xLength; j++){
					if ((mines[i][j] == true) && (flagged[i][j] == true)){
						hiddenLooseMines--;
					}
				}
			}
			looseMines--;
		}
		else {
			board[xCor][yCor] = " - ";
			flagged[xCor][yCor] = false;
			looseMines++;
			if (mines[xCor][yCor] == true){
				hiddenLooseMines++;
			}
		}
	}
	
	//cancelling your choice
	if (digOrFlag == "cancel"){
		dig(looseMines, hiddenLooseMines, gameOn, board, flagged, mines, boardNums, seen);
	}
}

//plant mines and give numbers
void plant (bool mines[][xLength], string boardNums[][xLength]){
	int numbers[yLength][xLength] = {};
	int randX;
	int randY;

	for (int i = 0; i < yLength; i++){
		for (int j = 0; j < xLength; j++){
			mines[i][j] = false;
			numbers[i][j] = 0;
		}
	}

	//Plant the mines
	for (int i = 0; i < minesNumber; i++){
		randX = rand() % yLength;
		randY = rand() % xLength;

		while (mines[randX][randY] == true){
			randX = rand() % yLength;
			randX = rand() % xLength;
		}

		mines[randX][randY] = true;
	}

	//Create the Numbers
	for (int y = xLength - 1; y >= 0; y--){
		for (int x = 0; x < yLength; x++){
			if (mines[x][y] == true){
				if ((mines[x - 1][y + 1] == false) && (x - 1 >= 0) && (y + 1 < xLength)){
					numbers[x - 1][y + 1]++;
				}	

				if ((mines[x][y + 1] == false) && (y + 1 < xLength)){
					numbers[x][y + 1]++;
				}

				if ((mines[x + 1][y + 1] == false) && (x + 1 < yLength) && (y + 1 < xLength)){		
					numbers[x + 1][y + 1]++;
				}	

				if ((mines[x + 1][y] == false) && (x + 1 < yLength)){
					numbers[x + 1][y]++;
				}

				if ((mines[x + 1][y - 1] == false) && (x + 1 < yLength) && (y - 1 >= 0)){
					numbers[x + 1][y - 1]++;
				}

				if ((mines[x][y - 1] == false) && (y - 1 >= 0)){
					numbers[x][y - 1]++;
				}

				if ((mines[x - 1][y - 1] == false) && (x - 1 >= 0) && (y - 1 >= 0)){
					numbers[x - 1][y - 1]++;
				}

				if ((mines[x - 1][y] == false) && (x - 1 >= 0)){
					numbers[x - 1][y]++;
				}
			}
		}
	}

	//Give the numbers to show on the board
	for (int y = xLength - 1; y >= 0; y--){
		for (int x = 0; x < yLength; x++){
			if ((numbers[x][y] == 0) && (mines[x][y] == false)){
				boardNums[x][y] = "   ";
			}
			else {
				boardNums[x][y] = " " + to_string(numbers[x][y]) + " ";
			}
		}
	}

	//Show where the mines are in boardNums
	for (int y = xLength - 1; y >= 0; y--){
		for (int x = 0; x < yLength; x++){
			if (mines[x][y] == true){
				boardNums[x][y] = " \033[31m*\033[0m ";
			}
		}
	}
}

//see if the game is over
bool gameOver(bool flagged[][xLength], bool mines[][xLength], string board[][xLength]){
	int minesLeft = minesNumber;
	
	for (int g = 0; g < yLength; g++){
		for (int h = 0; h < xLength; h++){
			if (flagged[g][h] == true && mines[g][h] == true){
				minesLeft--;
			}	
		}
	}


	if (minesLeft == 0){
		land(0, board);
		cout << "You Won!!!" << endl;
		return true;
	}
	else {
		return false;
	}
}
