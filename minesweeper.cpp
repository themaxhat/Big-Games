#include <iostream>
#include <stdlib.h>
#include <vector>

#define xLength 25
#define yLength 25
#define minesNumber 99

using namespace std;

/*
************************USER NOTE*************************
**x and y are swapped so some variables may be confusing**
**********************************************************
*/

void reveal(int xMerge, int yMerge, string board[][xLength], string boardNums[][xLength]);
void clearSection (int xCor, int yCor, string board[][xLength], string boardNums[][xLength], bool mines[][xLength]);
void underground(string boardNums[][xLength]);
void land(int looseMines, string board[][xLength]);
void dig (int &looseMines, bool &game, string board[][xLength], bool flagged[][xLength], bool mines[][xLength], string boardNums[][xLength]);

int main(){
	int randX;
	int randY;
	int looseMines = minesNumber;
	
	bool game = true;

	int numbers[yLength][xLength] = {};
	
	string board[yLength][xLength] = {};
	string boardNums[yLength][xLength] = {};

	bool mines[yLength][xLength] = {};
	bool flagged[yLength][xLength] = {};

	srand (time(NULL));
	
	for (int g = 0; g < yLength; g++){
		for (int h = 0; h < xLength; h++){
			board[g][h] = " - ";
			boardNums[g][h] = "   ";
			numbers[g][h] = 0;
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


	//show where the mines are (Control)
	/*
	for (int y = xLength - 1; y >= 0; y--){
		for (int x = 0; x < yLength; x++){
			if (mines[x][y] == true){
				board[x][y] = "\033[31m*\033[0m";
			}
		}
	}
	*/

	//Create the Numbers
	for (int y = xLength - 1; y >= 0; y--){
		for (int x = 0; x < yLength; x++){
			if (mines[x][y] == true){
				if ((mines[x - 1][y + 1] == false) && (x - 1 >= 0) && (y + 1 < xLength)){
					numbers[x - 1][y + 1] = numbers[x - 1][y + 1] + 1;
				}	

				if ((mines[x][y + 1] == false) && (y + 1 < xLength)){
					numbers[x][y + 1] = numbers[x][y + 1] + 1;
				}

				if ((mines[x + 1][y + 1] == false) && (x + 1 < yLength) && (y + 1 < xLength)){		
					numbers[x + 1][y + 1] = numbers[x + 1][y + 1] + 1;
				}	

				if ((mines[x + 1][y] == false) && (x + 1 < yLength)){
					numbers[x + 1][y] = numbers[x + 1][y] + 1;
				}

				if ((mines[x + 1][y - 1] == false) && (x + 1 < yLength) && (y - 1 >= 0)){
					numbers[x + 1][y - 1] = numbers[x + 1][y - 1] + 1;
				}

				if ((mines[x][y - 1] == false) && (y - 1 >= 0)){
					numbers[x][y - 1] = numbers[x][y - 1] + 1;
				}

				if ((mines[x - 1][y - 1] == false) && (x - 1 >= 0) && (y - 1 >= 0)){
					numbers[x - 1][y - 1] = numbers[x - 1][y - 1] + 1;
				}

				if ((mines[x - 1][y] == false) && (x - 1 >= 0)){
					numbers[x - 1][y] = numbers[x - 1][y] + 1;
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
			/*
			if (mines[x][y] == true){
				boardNums[x][y] = "\033[31mX\033[0m";
			}
			*/
		}
	}

	//Show where the mines are (Control)
	for (int y = xLength - 1; y >= 0; y--){
		for (int x = 0; x < yLength; x++){
			if (mines[x][y] == true){
				//board[x][y] = " \033[1;31m-\033[0m ";
				boardNums[x][y] = " \033[31m*\033[0m ";
			}
		}
	}

	while (game == true){		
		land(looseMines, board);
		underground(boardNums);

		dig(looseMines, game, board, flagged, mines, boardNums);
	}

	return 0;
}

void clearSection (int xCor, int yCor, string board[][xLength], string boardNums[][xLength], bool mines[][xLength]){
	if (boardNums[xCor][yCor] == "   "){
		board[xCor][yCor] = boardNums[xCor][yCor];
		
		//North
		if (yCor + 1 < xLength){ 
			if (mines[xCor][yCor + 1] == false){
				board[xCor][yCor + 1] = boardNums[xCor][yCor + 1];
				clearSection(xCor, yCor+1, board, boardNums, mines);
			}
		}

		//South
		if (yCor - 1 >= 0){ 
			if (mines[xCor][yCor - 1] == false){
				board[xCor][yCor - 1] = boardNums[xCor][yCor - 1];
				clearSection(xCor, yCor-1, board, boardNums, mines);
			}
		}		

		//East
		if (xCor - 1 >= 0){ 
			if (mines[xCor - 1][yCor] == false){
				board[xCor - 1][yCor] = boardNums[xCor - 1][yCor];
				clearSection(xCor-1, yCor, board, boardNums, mines);
			}
		}			

		//West
		if (xCor + 1 < yLength){ 
			if (mines[xCor + 1][yCor] == false){
				board[xCor + 1][yCor] = boardNums[xCor + 1][yCor];
				clearSection(xCor+1, yCor, board, boardNums, mines);
			}
		}	

		//North East
		if (xCor - 1 >= 0 && yCor + 1 < xLength){ 
			if (mines[xCor - 1][yCor + 1] == false){
				board[xCor - 1][yCor + 1] = boardNums[xCor - 1][yCor + 1];
				clearSection(xCor-1, yCor+1, board, boardNums, mines);
			}		
		}

		//North West
		if (xCor + 1 < yLength && yCor + 1 < xLength){
			if(mines[xCor + 1][yCor + 1] == false){
				board[xCor + 1][yCor + 1] = boardNums[xCor + 1][yCor + 1];
				clearSection(xCor+1, yCor+1, board, boardNums, mines);
			}
		}	

		//South East
		if (xCor - 1 >= 0 && yCor - 1 >= 0){ 
			if (mines[xCor - 1][yCor - 1] == false){
				board[xCor - 1][yCor - 1] = boardNums[xCor - 1][yCor - 1];
				clearSection(xCor-1, yCor-1, board, boardNums, mines);
			}
		}	

		//South West
		if (xCor + 1 < yLength && yCor - 1 >= 0){ 
			if (mines[xCor + 1][yCor - 1] == false){
				board[xCor + 1][yCor - 1] = boardNums[xCor + 1][yCor - 1];
				clearSection(xCor+1, yCor-1, board, boardNums, mines);
			}
		}
	}
}

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

void land(int looseMines, string board[][xLength]){
	system("clear");

	cout << "            MINESWEEPER          " << endl;
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
	cout << endl;
	cout << "Flags Left: " << looseMines << endl << endl;	
}

void dig (int &looseMines, bool &game, string board[][xLength], bool flagged[][xLength], bool mines[][xLength], string boardNums[][xLength]){
	int hiddenLooseMines = looseMines;
	int xCor;
	int yCor;
	string digOrFlag;
	
	cout << "x coordinate: ";
	cin >> yCor;
	while (yCor > (yLength - 1) || yCor < 0){
		cout << "That's not on the graph, try again. ";
		cin >> yCor;
		cout << endl;
	}
	cout << "y coordinate: ";
	cin >> xCor;
	while (xCor > (xLength - 1) || xCor < 0){
		cout << "That's not on the graph, try again. ";
		cin >> xCor;
		cout << endl;
	}
	cout << endl;

	cout << "dig or flag? (or cancel) ";
	cin >> digOrFlag;

	if (digOrFlag != "dig" && digOrFlag != "flag" && digOrFlag != "cancel"){
		dig(looseMines, game, board, flagged, mines, boardNums);
	}

	//uncovering a spot
	if (digOrFlag == "dig"){
		if (mines[xCor][yCor] == true){
			board[xCor][yCor] = " \033[1;31m*\033[0m ";
			land(looseMines, board);
			cout << "BOOM" << endl << "game over" << endl;
			game = false;
		}
		else if (boardNums[xCor][yCor] == "   "){
			/*
			board[xCor][yCor] = boardNums[xCor][yCor];
			if (xCor + 1 < yLength && yCor + 1 < xLength){
				board[xCor + 1][yCor + 1] = boardNums[xCor + 1][yCor + 1];
			}	
			if (xCor + 1 < yLength){
				board[xCor + 1][yCor] = boardNums[xCor + 1][yCor];
			}	
			if (xCor + 1 < yLength && yCor - 1 >= 0){
				board[xCor + 1][yCor - 1] = boardNums[xCor + 1][yCor - 1];
			}	
			if (yCor - 1 >= 0){
				board[xCor][yCor - 1] = boardNums[xCor][yCor - 1];
			}	
			if (xCor - 1 >= 0 && yCor - 1 >= 0){
				board[xCor - 1][yCor - 1] = boardNums[xCor - 1][yCor - 1];
			}	
			if (xCor - 1 >= 0){
				board[xCor - 1][yCor] = boardNums[xCor - 1][yCor];
			}	
			if (xCor - 1 >= 0 && yCor + 1 < xLength){
				board[xCor - 1][yCor + 1] = boardNums[xCor - 1][yCor + 1];
			}		
			if (yCor + 1 < xLength){
				board[xCor][yCor + 1] = boardNums[xCor][yCor + 1];
			}
			*/
			clearSection(xCor, yCor, board, boardNums, mines);
		}
		else {
			board[xCor][yCor] = boardNums[xCor][yCor];
		}
	}

	//flagging/unflagging a spot
	if (digOrFlag == "flag"){
		if (flagged[xCor][yCor] == false){
			board[xCor][yCor] = " \033[31mx\033[0m ";
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
		else {//if (flagged[xCor][yCor] == true){
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
		dig(looseMines, game, board, flagged, mines, boardNums);
	}

	if (hiddenLooseMines == 0){
		game == false;
		land(looseMines, board);
		cout << "Good game you won!";
	}

}
