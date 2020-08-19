#include<list>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<iomanip>
#include<unistd.h>
#include<unordered_set>

using namespace std;

void change(bool &running, bool reverse, int &order, list <string> hand, list <string> comp1, list <string> comp2, list <string> comp3, list <string> cards);
void draw(list <string> &comp, list <string> &cards);
void compplay(list <string> &uter, int &cnewcolor, string &top, bool &reverse, int &order, list <string> &cards, bool &validation);
void humplay(list <string> &hand, string &top,bool &validation, bool &reverse, int &order, list <string> &comp1, list <string> &comp2, list <string> &comp3, list <string> &cards);
void powers(int &order, bool &reverse, string top);
void table(string top, list <string> hand, list <string> comp1, list <string> comp2, list <string> comp3, list <string> cards);
bool validnum(string top, bool &validation, list <string>::iterator it);
void valid(string top, bool &validation, list <string>::iterator it);

void change(bool &running, bool reverse, int &order, list <string> hand, list <string> comp1, list <string> comp2, list <string> comp3, list <string> cards){
	if (reverse == false) {
		order++;
		if ((order == 5) || (order == 6)){
			order = 1;
		}
	}
	if (reverse == true) {
		order--;
		if ((order == 0) || (order == -1)){
			order = 4;
		}
	}

	if ((hand.size() == 0) || (comp1.size() == 0) || (comp2.size() == 0) || (comp3.size() == 0)) {
		running = false;
	} 
	else {
		running = true;
	}	
}

void draw(list <string> &comp, list <string> &cards){
	int random = rand() % cards.size();
	list <string>::iterator it = cards.begin();
	advance(it, random);
	comp.push_back(*it);
	cards.erase(it);
}

void humplay(list <string> &hand, string &top,bool &validation, bool &reverse, int &order, list <string> &comp1, list <string> &comp2, list <string> &comp3, list <string> &cards){
	int whichcard;
	string newcolor;
	string choice;
	
	if ((top == "\033[1;31m+2 \033[0m") || (top == "\033[1;32m+2 \033[0m") || (top == "\033[1;33m+2 \033[0m") || (top == "\033[1;34m+2 \033[0m")){
		for (int i = 0; i < 2; i++){
			draw(hand, cards);
		}
		if (top == "\033[1;31m+2 \033[0m"){
			top = "\033[1;31m+2\033[0m";
		}
		if (top == "\033[1;32m+2 \033[0m"){
			top = "\033[1;32m+2\033[0m";
		}
		if (top == "\033[1;33m+2 \033[0m"){
			top = "\033[1;34m+2\033[0m";
		}
		if (top == "\033[1;34m+2 \033[0m"){
			top = "\033[1;34m+2\033[0m";
		}
		return;
	}	
	if ((top == "\033[1;31m+4 \033[0m") || (top == "\033[1;32m+4 \033[0m") || (top == "\033[1;33m+4 \033[0m") || (top == "\033[1;34m+4 \033[0m")){
		for (int i = 0; i < 4; i++){
			draw(hand, cards);
		}
		if (top == "\033[1;31m+4 \033[0m"){
			top = "\033[1;31m+4\033[0m";
		}
		if (top == "\033[1;32m+4 \033[0m"){
			top = "\033[1;32m+4\033[0m";
		}
		if (top == "\033[1;33m+4 \033[0m"){
			top = "\033[1;34m+4\033[0m";
		}
		if (top == "\033[1;34m+4 \033[0m"){
			top = "\033[1;34m+4\033[0m";
		}
		return;
	}
	
	cout << "do you want to draw or play?\n";
	cin >> choice;
	while ((choice != "draw") && (choice != "play")){
		cout << "*invalid*\ndo you want to draw or play?\n";
		cin >> choice;
	}
	if (choice == "draw"){
		draw(hand, cards);
		table(top, hand, comp1, comp2, comp3, cards);
		humplay(hand, top, reverse, validation, order, comp1, comp2, comp3, cards);
	}
	if (choice == "play"){
		cout << "which card do you want to play? (Use the numbers below the cards) ";
		cin >> whichcard;

		list <string>::iterator it = hand.begin();
		advance(it, whichcard - 1);

		valid(top, validation, it);
		if (validation == true){
			hand.erase(it);
			top = *it;
			powers(order, reverse, top);
		}
		if (validation == false){
			cout << "You can't use that card\n";
			humplay(hand, top, reverse, validation, order, comp1, comp2, comp3, cards);
		}


		//change color
		if ((*it == "\033[1;37mC  \033[0m" ) || (*it == "\033[1;37m+4 \033[0m")){
			cout << "what color? ";
			cin >> newcolor;
			cout << endl;
			if ((newcolor != "red") && (newcolor != "green") && (newcolor != "blue") && (newcolor != "yellow")){
				cout << "*invalid*\nwhich color?\n";
				cin >> newcolor;
			}
			if ((newcolor == "red") && (*it == "\033[1;37mC  \033[0m")){
				top = "\033[1;31mC \033[0m";
			}
			if ((newcolor == "green") && (*it == "\033[1;37mC  \033[0m")){
				top = "\033[1;32mC  \033[0m";
			}
			if ((newcolor == "blue") && (*it == "\033[1;37mC  \033[0m")){
				top = "\033[1;34mC  \033[0m";
			}	
			if ((newcolor == "yellow") && (*it == "\033[1;37mC  \033[0m")){
				top = "\033[1;33mC  \033[0m";
			}

			if ((newcolor == "red") && (*it == "\033[1;37m+4 \033[0m")){
				top = "\033[1;31m+4 \033[0m";
			}
			if ((newcolor == "green") && (*it == "\033[1;37m+4 \033[0m")){
				top = "\033[1;32m+4 \033[0m";
			}
			if ((newcolor == "blue") && (*it == "\033[1;37m+4 \033[0m")){
				top = "\033[1;34m+4 \033[0m";
			}	
			if ((newcolor == "yellow") && (*it == "\033[1;37m+4 \033[0m")){
				top = "\033[1;33m+4\033[0m";
			}
		}
	
	}	

}

void compplay(list <string> &uter, int &cnewcolor, string &top, bool &reverse, int &order, list <string> &cards, bool &validation){
	unordered_set <string> one = {
		"\033[1;31m1  \033[0m","\033[1;31m2  \033[0m","\033[1;31m3  \033[0m","\033[1;31m4  \033[0m",
		"\033[1;31m5  \033[0m","\033[1;31m6  \033[0m","\033[1;31m7  \033[0m","\033[1;31m8  \033[0m",
		"\033[1;31m9  \033[0m",
		"\033[1;32m1  \033[0m","\033[1;32m2  \033[0m","\033[1;32m3  \033[0m","\033[1;32m4  \033[0m",
		"\033[1;32m5  \033[0m","\033[1;32m6  \033[0m","\033[1;32m7  \033[0m","\033[1;32m8  \033[0m",
		"\033[1;32m9  \033[0m",
		"\033[1;33m1  \033[0m","\033[1;33m2  \033[0m","\033[1;33m3  \033[0m","\033[1;33m4  \033[0m",
		"\033[1;33m5  \033[0m","\033[1;33m6  \033[0m","\033[1;33m7  \033[0m","\033[1;33m8  \033[0m",
		"\033[1;33m9  \033[0m",
		"\033[1;34m1  \033[0m","\033[1;34m2  \033[0m","\033[1;34m3  \033[0m","\033[1;34m4  \033[0m",
		"\033[1;34m5  \033[0m","\033[1;34m6  \033[0m","\033[1;34m7  \033[0m","\033[1;34m8  \033[0m",
		"\033[1;34m9  \033[0m",
		"imax"
	};
	unordered_set <string> two = {
		"\033[1;31mR  \033[0m","\033[1;32mR  \033[0m","\033[1;33mR  \033[0m","\033[1;34mR  \033[0m",
		"imax"
	};
	unordered_set <string> three = {
		"\033[1;31mS  \033[0m","\033[1;32mS  \033[0m","\033[1;33mS  \033[0m","\033[1;34mS  \033[0m",
		"imax"
	};
	unordered_set <string> four = {
		"\033[1;31m+2 \033[0m","\033[1;32m+2 \033[0m","\033[1;33m+2 \033[0m","\033[1;34m+2 \033[0m",
		"\033[1;37mC  \033[0m","imax"
	};
	unordered_set <string> five = {
		"\033[1;37+4 \033[0m","imax"
	};

	int best_score = 0;
	int current_score;
	list<string>::iterator best;

	if ((top == "\033[1;31m+2 \033[0m") || (top == "\033[1;32m+2 \033[0m") || (top == "\033[1;33m+2 \033[0m") || (top == "\033[1;34m+2 \033[0m")){
		for (int i = 0; i < 2; i++){
			draw(uter, cards);
		}
		if (top == "\033[1;31m+2 \033[0m"){
			top = "\033[1;31m+2\033[0m";
		}
		if (top == "\033[1;32m+2 \033[0m"){
			top = "\033[1;32m+2\033[0m";
		}
		if (top == "\033[1;33m+2 \033[0m"){
			top = "\033[1;34m+2\033[0m";
		}
		if (top == "\033[1;34m+2 \033[0m"){
			top = "\033[1;34m+2\033[0m";
		}
		return;
	}	
	if ((top == "\033[1;31m+4 \033[0m") || (top == "\033[1;32m+4 \033[0m") || (top == "\033[1;33m+4 \033[0m") || (top == "\033[1;34m+4 \033[0m")){
		for (int i = 0; i < 4; i++){
			draw(uter, cards);
		}
		if (top == "\033[1;31m+4 \033[0m"){
			top = "\033[1;31m+4\033[0m";
		}
		if (top == "\033[1;32m+4 \033[0m"){
			top = "\033[1;32m+4\033[0m";
		}
		if (top == "\033[1;33m+4 \033[0m"){
			top = "\033[1;34m+4\033[0m";
		}
		if (top == "\033[1;34m+4 \033[0m"){
			top = "\033[1;34m+4\033[0m";
		}
		return;
	}

	for (list <string>::iterator it = uter.begin(); it != uter.end(); it++) {
		
		valid(top, validation, it);
		if (validation == true){
			if (five.find(*it) != five.end()){
				current_score = 5;
			}
			else {
				if (four.find(*it) != four.end()){
					current_score = 4;
				}
				else {
					if (three.find(*it) != three.end()){
						current_score = 3;
					}
					else {
						if (two.find(*it) != two.end()){
							current_score = 2;
						}
						else {
							current_score = 1;		
						}
					}
				}
			}

			if (current_score > best_score){
				best_score = current_score;
				best = it;
			}

			
		}
	}


	while (validation == false){
		draw(uter, cards);
		best = uter.end();
		best--;		
		valid(top, validation, best);
		//compplay(uter, cnewcolor, top, reverse, order, cards, validation);
	}

	top = *best;
	uter.erase(best);
	powers(order, reverse, top);

	if ((top == "\033[1;37mC  \033[0m" ) || (top == "\033[1;37m+4 \033[0m")){
		cnewcolor = rand() % 4;
		if ((top == "\033[1;37mC  \033[0m") && (cnewcolor == 0)){
			top = "\033[1;31mC  \033[0m";
		}
		if ((top == "\033[1;37mC  \033[0m") && (cnewcolor == 1)){
			top = "\033[1;32mC  \033[0m";
		}
		if ((top == "\033[1;37mC  \033[0m") && (cnewcolor == 2)){
			top = "\033[1;34mC  \033[0m";
		}	
		if ((top == "\033[1;37mC  \033[0m") && (cnewcolor == 3)){
			top = "\033[1;33mC  \033[0m";
		}
		if ((top == "\033[1;37m+4 \033[0m") && (cnewcolor == 0)){
			top = "\033[1;31m+4 \033[0m";
		}
		if ((top == "\033[1;37m+4 \033[0m") && (cnewcolor == 1)){
			top = "\033[1;32m+4 \033[0m";
		}
		if ((top == "\033[1;37m+4 \033[0m") && (cnewcolor == 2)){
			top = "\033[1;34m+4 \033[0m";
		}	
		if ((top == "\033[1;37m+4 \033[0m") && (cnewcolor == 3)){
			top = "\033[1;33m+4 \033[0m";
		}
	}
}

void powers(int &order, bool &reverse, string top){
	if (((top == "\033[1;31mR  \033[0m") || (top == "\033[1;32mR  \033[0m") || (top == "\033[1;33mR  \033[0m") || (top == "\033[1;34mR  \033[0m")) && (reverse == false)){
		reverse = true;
		return;
	}
	if (((top == "\033[1;31mR  \033[0m") || (top == "\033[1;32mR  \033[0m") || (top == "\033[1;33mR  \033[0m") || (top == "\033[1;34mR  \033[0m")) && (reverse == true)){
		reverse = false;
		return;
	}

	//skip
	if (((top == "\033[1;31mS  \033[0m") || (top == "\033[1;32mS  \033[0m") || (top == "\033[1;33mS  \033[0m") || (top == "\033[1;34mS  \033[0m")) && (reverse == false)){
		order++;
		if (order == 5){
			order = 1;
		}
		if (order == 6){
			order = 2;
		}
		return;
	}
	if (((top == "\033[1;31mS  \033[0m") || (top == "\033[1;32mS  \033[0m") || (top == "\033[1;33mS  \033[0m") || (top == "\033[1;34mS  \033[0m")) && (reverse == true)){
		order--;
		if (order == 0){
			order = 4;
		}
		if (order == -1){
			order = 3;
		}
		return;
	}
}

void table(string top, list <string> hand, list <string> comp1, list <string> comp2, list <string> comp3, list <string> cards) {
	system("clear");
	cout << "Play Pile: " << top << endl << endl;

	cout << "Player 2 hand: " << comp1.size() << endl;
	
	for(auto i : comp1){
		cout << i;
	}
	
	cout << endl << "Player 3 hand: " << comp2.size() << endl;
	
	for(auto i : comp2){
		cout << i;
	}
	
	cout << endl << "Player 4 hand: " << comp3.size() << endl;
	
	for(auto i : comp3){
		cout << i;
	}
	
	cout << endl << "Deck size: " << cards.size() << endl;
	cout << endl;

	cout << "Your hand: ";
	for(auto i : hand){
		cout << i;
	}
	cout << endl << "           1  2  3  4  5  6  7  8  9  10 11 12 13 14 15" << endl;
}

void valid(string top, bool &validation, list <string>::iterator it){
	validation = false;

	unordered_set <string> green = {
		"\033[1;32m0  \033[0m","\033[1;32m1  \033[0m","\033[1;32m2  \033[0m","\033[1;32m3  \033[0m",
		"\033[1;32m4  \033[0m","\033[1;32m5  \033[0m","\033[1;32m6  \033[0m","\033[1;32m7  \033[0m",
		"\033[1;32m8  \033[0m","\033[1;32m9  \033[0m","\033[1;32m+2 \033[0m","\033[1;32mR  \033[0m",
		"\033[1;32mS  \033[0m","\033[1;32m+4 \033[0m","\033[1;32mC  \033[0m","\033[1;32m+4\033[0m",
		"\033[1;32m+2\033[0m","imax"
	};
	unordered_set <string> red = {
		"\033[1;31m0  \033[0m","\033[1;31m1  \033[0m","\033[1;31m2  \033[0m","\033[1;31m3  \033[0m",
		"\033[1;31m4  \033[0m","\033[1;31m5  \033[0m","\033[1;31m6  \033[0m","\033[1;31m7  \033[0m",
		"\033[1;31m8  \033[0m","\033[1;31m9  \033[0m","\033[1;31m+2 \033[0m","\033[1;31mR  \033[0m",
		"\033[1;31mS  \033[0m","\033[1;31m+4 \033[0m","\033[1;31mC  \033[0m","\033[1;31m+4\033[0m",
		"\033[1;31m+2\033[0m","imax"
	};
	unordered_set <string> yellow = { 
		"\033[1;33m0  \033[0m","\033[1;33m1  \033[0m","\033[1;33m2  \033[0m","\033[1;33m3  \033[0m",
		"\033[1;33m4  \033[0m","\033[1;33m5  \033[0m","\033[1;33m6  \033[0m","\033[1;33m7  \033[0m",
		"\033[1;33m8  \033[0m","\033[1;33m9  \033[0m","\033[1;33m+2 \033[0m","\033[1;33mR  \033[0m",
		"\033[1;33mS  \033[0m","\033[1;33m+4 \033[0m","\033[1;33mC  \033[0m","\033[1;33m+4\033[0m",
		"\033[1;33m+2\033[0m","imax"
    };
	unordered_set <string> blue ={
		"\033[1;34m0  \033[0m","\033[1;34m1  \033[0m","\033[1;34m2  \033[0m","\033[1;34m3  \033[0m",
		"\033[1;34m4  \033[0m","\033[1;34m5  \033[0m","\033[1;34m6  \033[0m","\033[1;34m7  \033[0m",
		"\033[1;34m8  \033[0m","\033[1;34m9  \033[0m","\033[1;34m+2 \033[0m","\033[1;34mR  \033[0m",
		"\033[1;34mS  \033[0m","\033[1;34m+4 \033[0m","\033[1;34mC  \033[0m","\033[1;34m+4\033[0m",
		"\033[1;34m+2\033[0m","imax"
	};
	unordered_set <string> black = {
		"\033[1;37m+4 \033[0m", "\033[1;37mC  \033[0m","imax"
	};
	unordered_set <string> zero = {
		"\033[1;31m0  \033[0m","\033[1;32m0  \033[0m","\033[1;33m0  \033[0m","\033[1;34m0  \033[0m","imax"
	};
	unordered_set <string> one = {
		"\033[1;31m1  \033[0m","\033[1;32m1  \033[0m","\033[1;33m1  \033[0m","\033[1;34m1  \033[0m","imax"
	};
	unordered_set <string> two = {
		"\033[1;31m2  \033[0m","\033[1;32m2  \033[0m","\033[1;33m2  \033[0m","\033[1;34m2  \033[0m","imax"
	};
	unordered_set <string> three = {
		"\033[1;31m3  \033[0m","\033[1;32m3  \033[0m","\033[1;33m3  \033[0m","\033[1;34m3  \033[0m","imax"
	};
	unordered_set <string> four = {
		"\033[1;31m4  \033[0m","\033[1;32m4  \033[0m","\033[1;33m4  \033[0m","\033[1;34m4  \033[0m","imax"
	};
	unordered_set <string> five = {
		"\033[1;31m5  \033[0m","\033[1;32m5  \033[0m","\033[1;33m5  \033[0m","\033[1;34m5  \033[0m","imax"
	};
	unordered_set <string> six = {
		"\033[1;31m6  \033[0m","\033[1;32m6  \033[0m","\033[1;33m6  \033[0m","\033[1;34m6  \033[0m","imax"
	};
	unordered_set <string> seven = {
		"\033[1;31m7  \033[0m","\033[1;32m7  \033[0m","\033[1;33m7  \033[0m","\033[1;34m7  \033[0m","imax"
	};
	unordered_set <string> eight = {
		"\033[1;31m8  \033[0m","\033[1;32m8  \033[0m","\033[1;33m8  \033[0m","\033[1;34m8  \033[0m","imax"
	};
	unordered_set <string> nine = {
		"\033[1;31m9  \033[0m","\033[1;32m9  \033[0m","\033[1;33m9  \033[0m","\033[1;34m9  \033[0m","imax"
	};
	unordered_set <string> reverse = {
		"\033[1;31mR  \033[0m","\033[1;32mR  \033[0m","\033[1;33mR  \033[0m","\033[1;34mR  \033[0m","imax"
	};
	unordered_set <string> skip = {
		"\033[1;31mS  \033[0m","\033[1;32mS  \033[0m","\033[1;33mS  \033[0m","\033[1;34mS  \033[0m","imax"
	};
	unordered_set <string> draw = {
		"\033[1;31m+2 \033[0m","\033[1;32m+2 \033[0m","\033[1;33m+2 \033[0m","\033[1;34m+2 \033[0m",
		"\033[1;31m+4 \033[0m","\033[1;32m+4 \033[0m","\033[1;33m+4 \033[0m","\033[1;34m+4 \033[0m",
		"\033[1;31m+2\033[0m","\033[1;32m+2\033[0m","\033[1;33m+2\033[0m","\033[1;34m+2\033[0m",
		"\033[1;31m+4\033[0m","\033[1;32m+4\033[0m","\033[1;33m+4\033[0m","\033[1;34m+4\033[0m",
		"\033[1;37m+4 \033[0m","imax"
	};

	string ValidNumber1;
	string ValidColor1;
	string ValidNumber2;
	string ValidColor2;

	validation = false;

	//same color
	if (green.find(top) != green.end()){
		ValidColor1 = "green";
	}
	else {
		if (red.find(top) != red.end()){
			ValidColor1 = "red";
		}
		else {
			if (yellow.find(top) != yellow.end()){
				ValidColor1 = "yellow";
			}
			else {
				if (blue.find(top) != blue.end()){
					ValidColor1 = "blue";
				}
				else {
					if (black.find(top) != black.end()){
						ValidColor1 = "black";
					}	
					else {
						validation = false;
					}
				}
			}
		}
	}
	if (green.find(*it) != green.end()){
		ValidColor2 = "green";
	}
	else {
		if (red.find(*it) != red.end()){
			ValidColor2 = "red";
		}
		else {
			if (yellow.find(*it) != yellow.end()){
				ValidColor2 = "yellow";
			}
			else {
				if (blue.find(*it) != blue.end()){
					ValidColor2 = "blue";
				}
				else {
					if (black.find(*it) != black.end()){
						ValidColor2 = "black";
					}	
					else {
						validation = false;
					}
				}				
			}
		}
	}
	if (zero.find(top) != zero.end()){
		ValidNumber1 = "zero";
	}
	else {
		if (one.find(top) != one.end()){
			ValidNumber1 = "one";
		}
		else {
			if (two.find(top) != two.end()){
				ValidNumber1 = "two";
			}
			else {
				if (three.find(top) != three.end()){
					ValidNumber1 = "three";
				}
				else {
					if (four.find(top) != four.end()){
						ValidNumber1 = "four";
					}
					else {
						if (five.find(top) != five.end()){
							ValidNumber1 = "five";
						}
						else {
							if (six.find(top) != six.end()){
								ValidNumber1 = "six";
							}
							else {
								if (seven.find(top) != seven.end()){
									ValidNumber1 = "seven";
								}
								else {
									if (eight.find(top) != eight.end()){
										ValidNumber1 = "eight";
									}
									else {
										if (nine.find(top) != nine.end()){
											ValidNumber1 = "nine";
										}
										else {
											if (reverse.find(top) != reverse.end()){
												ValidNumber1 = "reverse";
											}
											else {
												if (skip.find(top) != skip.end()){
													ValidNumber1 = "skip";
												}
												else {
													if (draw.find(top) != draw.end()){
														ValidNumber1 = "draw";
													}
													else {
														validation = false;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if (zero.find(*it) != zero.end()){
		ValidNumber2 = "zero";
	}
	else {
		if (one.find(*it) != one.end()){
			ValidNumber2 = "one";
		}
		else {
			if (two.find(*it) != two.end()){
				ValidNumber2 = "two";
			}
			else {
				if (three.find(*it) != three.end()){
					ValidNumber2 = "three";
				}
				else {
					if (four.find(*it) != four.end()){
						ValidNumber2 = "four";
					}
					else {
						if (five.find(*it) != five.end()){
							ValidNumber2 = "five";
						}
						else {
							if (six.find(*it) != six.end()){
								ValidNumber2 = "six";
							}
							else {
								if (seven.find(*it) != seven.end()){
									ValidNumber2 = "seven";
								}
								else {
									if (eight.find(*it) != eight.end()){
										ValidNumber2 = "eight";
									}
									else {
										if (nine.find(*it) != nine.end()){
											ValidNumber2 = "nine";
										}
										else {
											if (reverse.find(*it) != reverse.end()){
												ValidNumber2 = "reverse";
											}
											else {
												if (skip.find(*it) != skip.end()){
													ValidNumber2 = "skip";
												}
												else {
													if (draw.find(*it) != draw.end()){
														ValidNumber2 = "draw";
													}
													else {
														validation = false;
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	validation = ((ValidColor2 == "black") || (ValidColor1 == ValidColor2) || (ValidNumber1 == ValidNumber2));

}

int main(){
	list <string> cards = {     
		"\033[1;31m0  \033[0m","\033[1;31m0  \033[0m","\033[1;31m1  \033[0m","\033[1;31m1  \033[0m","\033[1;31m2  \033[0m","\033[1;31m2  \033[0m","\033[1;31m3  \033[0m","\033[1;31m3  \033[0m",
		"\033[1;31m4  \033[0m","\033[1;31m4  \033[0m","\033[1;31m5  \033[0m","\033[1;31m5  \033[0m","\033[1;31m6  \033[0m","\033[1;31m6  \033[0m","\033[1;31m7  \033[0m","\033[1;31m7  \033[0m",
		"\033[1;31m8  \033[0m","\033[1;31m8  \033[0m","\033[1;31m9  \033[0m","\033[1;31m9  \033[0m","\033[1;31m+2 \033[0m","\033[1;31m+2 \033[0m","\033[1;31mR  \033[0m","\033[1;31mR  \033[0m",
		"\033[1;31mS  \033[0m","\033[1;31mS  \033[0m",

		"\033[1;32m0  \033[0m","\033[1;32m0  \033[0m","\033[1;32m1  \033[0m","\033[1;32m1  \033[0m","\033[1;32m2  \033[0m","\033[1;32m2  \033[0m","\033[1;32m3  \033[0m","\033[1;32m3  \033[0m",
		"\033[1;32m4  \033[0m","\033[1;32m4  \033[0m","\033[1;32m5  \033[0m","\033[1;32m5  \033[0m","\033[1;32m6  \033[0m","\033[1;32m6  \033[0m","\033[1;32m7  \033[0m","\033[1;32m7  \033[0m",
		"\033[1;32m8  \033[0m","\033[1;32m8  \033[0m","\033[1;32m9  \033[0m","\033[1;32m9  \033[0m","\033[1;32m+2 \033[0m","\033[1;32m+2 \033[0m","\033[1;32mR  \033[0m","\033[1;32mR  \033[0m",
		"\033[1;32mS  \033[0m","\033[1;32mS  \033[0m",

		"\033[1;34m0  \033[0m","\033[1;34m0  \033[0m","\033[1;34m1  \033[0m","\033[1;34m1  \033[0m","\033[1;34m2  \033[0m","\033[1;34m2  \033[0m","\033[1;34m3  \033[0m","\033[1;34m3  \033[0m",
		"\033[1;34m4  \033[0m","\033[1;34m4  \033[0m","\033[1;34m5  \033[0m","\033[1;34m5  \033[0m","\033[1;34m6  \033[0m","\033[1;34m6  \033[0m","\033[1;34m7  \033[0m","\033[1;34m7  \033[0m",
		"\033[1;34m8  \033[0m","\033[1;34m8  \033[0m","\033[1;34m9  \033[0m","\033[1;34m9  \033[0m","\033[1;34m+2 \033[0m","\033[1;34m+2 \033[0m","\033[1;34mR  \033[0m","\033[1;34mR  \033[0m",
		"\033[1;34mS  \033[0m","\033[1;34mS  \033[0m",

		"\033[1;33m0  \033[0m","\033[1;33m0  \033[0m","\033[1;33m1  \033[0m","\033[1;33m1  \033[0m","\033[1;33m2  \033[0m","\033[1;33m2  \033[0m","\033[1;33m3  \033[0m","\033[1;33m3  \033[0m",
		"\033[1;33m4  \033[0m","\033[1;33m4  \033[0m","\033[1;33m5  \033[0m","\033[1;33m5  \033[0m","\033[1;33m6  \033[0m","\033[1;33m6  \033[0m","\033[1;33m7  \033[0m","\033[1;33m7  \033[0m",
		"\033[1;33m8  \033[0m","\033[1;33m8  \033[0m","\033[1;33m9  \033[0m","\033[1;33m9  \033[0m","\033[1;33m+2 \033[0m","\033[1;33m+2 \033[0m","\033[1;33mR  \033[0m","\033[1;33mR  \033[0m",
		"\033[1;33mS  \033[0m","\033[1;33mS  \033[0m",

		"\033[1;37m+4 \033[0m","\033[1;37m+4 \033[0m","\033[1;37m+4 \033[0m","\033[1;37m+4 \033[0m",
		"\033[1;37mC  \033[0m","\033[1;37mC  \033[0m","\033[1;37mC  \033[0m","\033[1;37mC  \033[0m"

		"\033[1;31m0  \033[0m","\033[1;31m0  \033[0m","\033[1;31m1  \033[0m","\033[1;31m1  \033[0m","\033[1;31m2  \033[0m","\033[1;31m2  \033[0m","\033[1;31m3  \033[0m","\033[1;31m3  \033[0m",
		"\033[1;31m4  \033[0m","\033[1;31m4  \033[0m","\033[1;31m5  \033[0m","\033[1;31m5  \033[0m","\033[1;31m6  \033[0m","\033[1;31m6  \033[0m","\033[1;31m7  \033[0m","\033[1;31m7  \033[0m",
		"\033[1;31m8  \033[0m","\033[1;31m8  \033[0m","\033[1;31m9  \033[0m","\033[1;31m9  \033[0m","\033[1;31m+2 \033[0m","\033[1;31m+2 \033[0m","\033[1;31mR  \033[0m","\033[1;31mR  \033[0m",
		"\033[1;31mS  \033[0m","\033[1;31mS  \033[0m",

		"\033[1;32m0  \033[0m","\033[1;32m0  \033[0m","\033[1;32m1  \033[0m","\033[1;32m1  \033[0m","\033[1;32m2  \033[0m","\033[1;32m2  \033[0m","\033[1;32m3  \033[0m","\033[1;32m3  \033[0m",
		"\033[1;32m4  \033[0m","\033[1;32m4  \033[0m","\033[1;32m5  \033[0m","\033[1;32m5  \033[0m","\033[1;32m6  \033[0m","\033[1;32m6  \033[0m","\033[1;32m7  \033[0m","\033[1;32m7  \033[0m",
		"\033[1;32m8  \033[0m","\033[1;32m8  \033[0m","\033[1;32m9  \033[0m","\033[1;32m9  \033[0m","\033[1;32m+2 \033[0m","\033[1;32m+2 \033[0m","\033[1;32mR  \033[0m","\033[1;32mR  \033[0m",
		"\033[1;32mS  \033[0m","\033[1;32mS  \033[0m",

		"\033[1;34m0  \033[0m","\033[1;34m0  \033[0m","\033[1;34m1  \033[0m","\033[1;34m1  \033[0m","\033[1;34m2  \033[0m","\033[1;34m2  \033[0m","\033[1;34m3  \033[0m","\033[1;34m3  \033[0m",
		"\033[1;34m4  \033[0m","\033[1;34m4  \033[0m","\033[1;34m5  \033[0m","\033[1;34m5  \033[0m","\033[1;34m6  \033[0m","\033[1;34m6  \033[0m","\033[1;34m7  \033[0m","\033[1;34m7  \033[0m",
		"\033[1;34m8  \033[0m","\033[1;34m8  \033[0m","\033[1;34m9  \033[0m","\033[1;34m9  \033[0m","\033[1;34m+2 \033[0m","\033[1;34m+2 \033[0m","\033[1;34mR  \033[0m","\033[1;34mR  \033[0m",
		"\033[1;34mS  \033[0m","\033[1;34mS  \033[0m",

		"\033[1;33m0  \033[0m","\033[1;33m0  \033[0m","\033[1;33m1  \033[0m","\033[1;33m1  \033[0m","\033[1;33m2  \033[0m","\033[1;33m2  \033[0m","\033[1;33m3  \033[0m","\033[1;33m3  \033[0m",
		"\033[1;33m4  \033[0m","\033[1;33m4  \033[0m","\033[1;33m5  \033[0m","\033[1;33m5  \033[0m","\033[1;33m6  \033[0m","\033[1;33m6  \033[0m","\033[1;33m7  \033[0m","\033[1;33m7  \033[0m",
		"\033[1;33m8  \033[0m","\033[1;33m8  \033[0m","\033[1;33m9  \033[0m","\033[1;33m9  \033[0m","\033[1;33m+2 \033[0m","\033[1;33m+2 \033[0m","\033[1;33mR  \033[0m","\033[1;33mR  \033[0m",
		"\033[1;33mS  \033[0m","\033[1;33mS  \033[0m",

		"\033[1;37m+4 \033[0m","\033[1;37m+4 \033[0m","\033[1;37m+4 \033[0m","\033[1;37m+4 \033[0m",
		"\033[1;37mC  \033[0m","\033[1;37mC  \033[0m","\033[1;37mC  \033[0m","\033[1;37mC  \033[0m"
	};

	list <string> hand(0);
	list <string> comp1(0);
	list <string> comp2(0);
	list <string> comp3(0);
	
	bool running = true;
	string top;

	bool reverse = false;
	string color;
	int order = 1;
	int cnewcolor;
	bool validation;

	system("clear");

	//deal cards

	srand(time(NULL));


	// deal all the cards
	for(int i = 7; i > 0; i--) {
		draw(hand, cards);
		draw(comp1, cards);
		draw(comp2, cards);
		draw(comp3, cards);
	}

	// place the first played card from the deck
	int strand = rand() % cards.size();
	list <string>::iterator it = cards.begin();
	advance(it, strand);
	while ((*it == "\033[1;31m+4 \033[0m") || (*it == "\033[1;31mC  \033[0m")){
		int strand = rand() % cards.size();
		list <string>::iterator it = cards.begin();
		advance(it, strand);
	}
	top = *it;
	cards.erase(it);

	// play game
	while (running == true) {
		table(top, hand, comp1, comp2, comp3, cards);
		switch(order) {
			case 1:
				humplay(hand, top, validation, reverse, order, comp1, comp2, comp3, cards);
				break;
			case 2:
				compplay(comp1, cnewcolor, top, reverse, order, cards, validation);
				break;
			case 3:
				compplay(comp2, cnewcolor, top, reverse, order, cards, validation);	
				break;
			case 4:
				compplay(comp3, cnewcolor, top, reverse, order, cards, validation);	
				break;
		}
		table(top, hand, comp1, comp2, comp3, cards);
		change(running, reverse, order, hand, comp1, comp2, comp3, cards);
	}

	//game over
	if (running == false){
		cout << endl << "game over!" << endl;
	}
}
