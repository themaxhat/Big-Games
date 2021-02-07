#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

void land(string board[][10]){	
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

void dig (int &xCor, int &yCor, string &digOrFlag, string board[][10]){
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
		cout << "ok";
	}
	if (digOrFlag == "flag"){
		board[xCor][yCor] = "\033[41m_\033[0m";
	}
	while (digOrFlag == "cancel"){
		cout << "x coordinate: ";
		cin >> xCor;
		cout << endl << "y coordinate: ";
		cin >> yCor;
		cout << endl;
		cout << "dig or flag (or cancel) ";
		cin >> digOrFlag;
	}
}

int main(){
	int xCor;
	int yCor;
	int randX;
	int randY;

	string digOrFlag;
	string board[10][10] = {};
	
	bool mines[10][10] = {};

	srand (time(NULL));

	for (int g = 0; g < 10; g++){
		for (int h = 0; h < 10; h++){
			board[g][h] = "_";
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
	
	land(board);

	dig(xCor, yCor, digOrFlag, board);

	land(board);
	
	return 0;
}
