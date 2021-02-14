#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

void land(string board[][10]){
	system("clear");

	cout << "       MINESWEEPER     " << endl;
	cout << "   _ _ _ _ _ _ _ _ _ _ " << endl;
	for (int i = 9; i >= 0; i--){
		cout << i << " |";
		for (int j = 0; j < 10; j++){
			cout << board[i][j] << "|";
		}
		cout << endl;
	}
	cout << "   0 1 2 3 4 5 6 7 8 9" << endl;	
}

void dig (int &xCor, int &yCor, string &digOrFlag, string board[][10], bool flagged[][10], bool mines[][10], bool &game){
	//land(board);
	//numPrint(mines);
	/*
	for (int y = 9; y >= 0; y--){
		for (int x = 0; x < 10; x++){
			if (mines[x][y] == true){
				board[x][y] = "\033[31m_\033[0m";
			}
		}
	}
	*/
	cout << "x coordinate: ";
	cin >> xCor;
	while (xCor > 9 || xCor < 0){
		cout << "That's not on the graph, try again. ";
		cin >> xCor;
		cout << endl;
	}
	cout << endl << "y coordinate: ";
	cin >> yCor;
	while (yCor > 9 || yCor < 0){
		cout << "That's not on the graph, try again. ";
		cin >> yCor;
		cout << endl;
	}
	cout << endl;

	cout << "dig or flag? (or cancel) ";
	cin >> digOrFlag;

	while (digOrFlag != "dig" && digOrFlag != "flag" && digOrFlag != "cancel"){
		cout << "That's not digging or flagging (or cancelling) \nTry again, dig or flag?";
		cin >> digOrFlag;
	}

	if (digOrFlag == "dig"){
		if (mines[xCor][yCor] == true){
			system("clear");
			cout << "GAME OVER" << endl;
			game = false;
		}
		else {
			cout << "ah poop" << endl;
			game = false;
		}
	}

	if (digOrFlag == "flag"){
		board[xCor][yCor] = "\033[41m_\033[0m";
		flagged[xCor][yCor] = true;
	}

	while (digOrFlag == "cancel"){
		dig(xCor, yCor, digOrFlag, board, flagged, mines, game);
	}

}

int main(){
	int xCor;
	int yCor;
	int randX;
	int randY;

	
	int numbers[10][10] = {};
	for (int c = 0; c < 10; c++){
		for (int d = 0; d < 10; d++){
			numbers[c][d] = 0;
		}
	}
	

	bool game = true;

	string digOrFlag;
	string board[10][10] = {};
	string boardNums[10][10] = {};

	bool mines[10][10] = {};
	bool flagged[10][10] = {};


	srand (time(NULL));

	for (int g = 0; g < 10; g++){
		for (int h = 0; h < 10; h++){
			board[g][h] = "_";
			boardNums[g][h] = " ";
		}
	}

	//plant the mines
	for (int i = 0; i < 15; i++){
		randX = rand() % 10;
		randY = rand() % 10;

		while (mines[randX][randY] == true){
			randX = rand() % 10;
			randX = rand() % 10;
		}

		mines[randX][randY] = true;
	}

/*
	//show where the mines are (Control)
	for (int y = 9; y >= 0; y--){
		for (int x = 0; x < 10; x++){
			if (mines[x][y] == true){
				board[x][y] = "\033[31m_\033[0m";
			}
		}
	}
*/

	//Create the Numbers
	for (int y = 9; y >= 0; y--){
		for (int x = 0; x < 10; x++){
			if (mines[x][y] == true){

				if (mines[x - 1][y + 1] == false){
					numbers[x - 1][y + 1] = numbers[x - 1][y + 1] + 1;
				}	

				if (mines[x][y + 1] == false){
					numbers[x][y + 1] = numbers[x][y + 1] + 1;
				}

				if (mines[x + 1][y + 1] == false){		
					numbers[x + 1][y + 1] = numbers[x + 1][y + 1] + 1;
				}	

				if (mines[x + 1][y] == false){
					numbers[x + 1][y] = numbers[x + 1][y] + 1;
				}

				if (mines[x + 1][y - 1] == false){
					numbers[x + 1][y - 1] = numbers[x + 1][y - 1] + 1;
				}

				if (mines[x][y - 1] == false){
					numbers[x][y - 1] = numbers[x][y - 1] + 1;
				}

				if (mines[x - 1][y - 1] == false){
					numbers[x - 1][y - 1] = numbers[x - 1][y - 1] + 1;
				}

				if (mines[x - 1][y] == false){
					numbers[x - 1][y] = numbers[x - 1][y] + 1;
				}
			}
		}
	}
	
	//Give the numbers to show on the board
	for (int y = 9; y >= 0; y--){
		for (int x = 0; x < 10; x++){
			if ((numbers[x][y] == 0) && (mines[x][y] == false)){
				boardNums[x][y] = " ";
			}
			else {
				boardNums[x][y] = to_string(numbers[x][y]);
			}
			/*
			if (mines[x][y] == true){
				boardNums[x][y] = "\033[31mX\033[0m";
			}
			*/
		}
	}

	//show where the mines are (Control)
	for (int y = 9; y >= 0; y--){
		for (int x = 0; x < 10; x++){
			if (mines[x][y] == true){
				board[x][y] = "\033[31m_\033[0m";
				boardNums[x][y] = "\033[31mX\033[0m";
			}
		}
	}

	while (game == true){
		land(board);

		cout << "       MINESWEEPER     " << endl;
		cout << "   _ _ _ _ _ _ _ _ _ _ " << endl;
		for (int i = 9; i >= 0; i--){
			cout << i << " |";
			for (int j = 0; j < 10; j++){
				//cout << numbers[i][j] << "|";
				cout << boardNums[i][j] << "|";
			}
			cout << endl;
		}
		cout << "   0 1 2 3 4 5 6 7 8 9" << endl;	

		dig(xCor, yCor, digOrFlag, board, flagged, mines, game);
	}

	return 0;
}
