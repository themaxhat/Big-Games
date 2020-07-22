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
void compplay(list <string> &uter, bool &validation, int cnewcolor, string &top, list<string>::iterator it, bool &running, bool&reverse, int &order, list <string> &cards, list <string> hand, list <string> comp1, list <string> comp2, list <string> comp3);
void powers(int &order, bool &reverse, string top);
void table(string top, list <string> hand, list <string> comp1, list <string> comp2, list <string> comp3, list <string> cards);
bool validnum(string top, bool &validation, list <string>::iterator it);
void validcol(string top, bool &validation, list <string>::iterator it);

void change(bool &running, bool reverse, int &order, list <string> hand, list <string> comp1, list <string> comp2, list <string> comp3, list <string> cards){
	if (reverse == false) {
		sleep(5000); 
		order++;
		if ((order == 5) || (order == 6)){
			order = 1;
		}
	}
	if (reverse == true) {
		sleep(5000);
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

void compplay(list <string> &uter, bool &validation, int cnewcolor, string &top, list<string>::iterator it, bool &running, bool&reverse, int &order, list <string> &cards, list <string> hand, list <string> comp1, list <string> comp2, list <string> comp3){

	if ((top == "\033[1;31m+2 \033[0m") || (top == "\033[1;32m+2 \033[0m") || (top == "\033[1;33m+2 \033[0m") || (top == "\033[1;34m+2 \033[0m")){
		for (int i = 0; i < 2; i++){
			draw(uter, cards);
		}
	}	
	if ((top == "\033[1;31m+4 \033[0m") || (top == "\033[1;32m+4 \033[0m") || (top == "\033[1;33m+4 \033[0m") || (top == "\033[1;34m+4 \033[0m")){
		for (int i = 0; i < 4; i++){
			draw(uter, cards);
		}
	}

	for (int i = 0; i <= uter.size(); i++){
		list <string>::iterator it = hand.begin();
		advance(it, i);

		validcol(top, validation, it);
		if (validation == true){
			uter.erase(it);
			top = *it;
			powers(order, reverse, top);

			if ((*it == "\033[1;37mC  \033[0m" ) || (*it == "\033[1;37m+4 \033[0m")){
				cnewcolor = rand() % 4;
				if ((*it == "\033[1;37mC  ") && (cnewcolor == 0)){
					top = "\033[1;31mC  \033[0m";
				}
				if ((*it == "\033[1;37mC  ") && (cnewcolor == 1)){
					top = "\033[1;32mC  \033[0m";
				}
				if ((*it == "\033[1;37mC  ") && (cnewcolor == 2)){
					top = "\033[1;34mC  \033[0m";
				}	
				if ((*it == "\033[1;37mC  ") && (cnewcolor == 3)){
					top = "\033[1;33mC  \033[0m";
				}
				if ((*it == "\033[1;37m+4 ") && (cnewcolor == 0)){
					top = "\033[1;31m+4 \033[0m";
				}
				if ((*it == "\033[1;37m+4 ") && (cnewcolor == 1)){
					top = "\033[1;32m+4 \033[0m";
				}
				if ((*it == "\033[1;37m+4 ") && (cnewcolor == 2)){
					top = "\033[1;34m+4 \033[0m";
				}	
				if ((*it == "\033[1;37m+4 ") && (cnewcolor == 3)){
					top = "\033[1;33m+4 \033[0m";
				}

			table(top, hand, comp1, comp2, comp3, cards);

			}

			break;
		}
	}

	if (validation == false){
		draw(uter, cards);
		table(top, hand, comp1, comp2, comp3, cards);	
	}

/*
	int choice = rand() % 2;
	if (choice == 0){
		draw(uter, cards);
		table(top, hand, comp1, comp2, comp3, cards);
	}
	if (choice == 1){
		int random = rand() % uter.size();
		list <string>::iterator it = uter.begin();
		advance(it, random);
		top = *it;
		uter.erase(it);

		powers(order, reverse, top);
		
		
	
		table(top, hand, comp1, comp2, comp3,cards);
		
	}
*/
	change(running, reverse, order, hand, comp1, comp2, comp3, cards);	

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
	//system("clear");
	cout << "Play Pile: " << top << endl << endl;

	cout << "Player 2 hand: " << comp1.size() << endl;
	cout << "Player 3 hand: " << comp2.size() << endl;
	cout << "Player 4 hand: " << comp3.size() << endl;
	cout << "Deck size: " << cards.size() << endl;
	cout << endl;

	cout << "Your hand: ";
	for(auto i : hand){
		cout << i;
	}
	cout << endl << "           1  2  3  4  5  6  7  8  9  10 11 12 13 14 15" << endl;
}

/*
bool validnum(string top, bool &validation, list <string>::iterator it){
	unordered_set <string> zero = {
		"\033[1;31m0  \033[0m","\033[1;32m0  \033[0m","\033[1;33m0  \033[0m","\033[1;34m0  \033[0m"
	};
	unordered_set <string> one = {
		"\033[1;31m1  \033[0m","\033[1;32m1  \033[0m","\033[1;33m1  \033[0m","\033[1;34m1  \033[0m"
	};
	unordered_set <string> two = {
		"\033[1;31m2  \033[0m","\033[1;32m2  \033[0m","\033[1;33m2  \033[0m","\033[1;34m2  \033[0m"
	};
	unordered_set <string> three = {
		"\033[1;31m3  \033[0m","\033[1;32m3  \033[0m","\033[1;33m3  \033[0m","\033[1;34m3  \033[0m"
	};
	unordered_set <string> four = {
		"\033[1;31m4  \033[0m","\033[1;32m4  \033[0m","\033[1;33m4  \033[0m","\033[1;34m4  \033[0m"
	};
	unordered_set <string> five = {
		"\033[1;31m5  \033[0m","\033[1;32m5  \033[0m","\033[1;33m5  \033[0m","\033[1;34m5  \033[0m"
	};
	unordered_set <string> six = {
		"\033[1;31m6  \033[0m","\033[1;32m6  \033[0m","\033[1;33m6  \033[0m","\033[1;34m6  \033[0m"
	};
	unordered_set <string> seven = {
		"\033[1;31m7  \033[0m","\033[1;32m7  \033[0m","\033[1;33m7  \033[0m","\033[1;34m7  \033[0m"
	};
	unordered_set <string> eight = {
		"\033[1;31m8  \033[0m","\033[1;32m8  \033[0m","\033[1;33m8  \033[0m","\033[1;34m8  \033[0m"
	};
	unordered_set <string> nine = {
		"\033[1;31m9  \033[0m","\033[1;32m9  \033[0m","\033[1;33m9  \033[0m","\033[1;34m9  \033[0m"
	};
	unordered_set <string> reverse = {
		"\033[1;31mR  \033[0m","\033[1;32mR  \033[0m","\033[1;33mR  \033[0m","\033[1;34mR  \033[0m"
	};
	unordered_set <string> skip = {
		"\033[1;31mS  \033[0m","\033[1;32mS  \033[0m","\033[1;33mS  \033[0m","\033[1;34mS  \033[0m"
	};
	unordered_set <string> draw = {
		"\033[1;31m+2 \033[0m","\033[1;32m+2 \033[0m","\033[1;33m+2 \033[0m","\033[1;34m+2 \033[0m"
		"\033[1;31m+4 \033[0m","\033[1;32m+4 \033[0m","\033[1;33m+4 \033[0m","\033[1;34m+4 \033[0m"
	};
	string ValidNumber1;
	string ValidNumber2;

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

	if ((ValidNumber1 == "zero") && (ValidNumber2 != "zero")){
		validation = false;
	}
	if ((ValidNumber1 == "one") && (ValidNumber2 != "one")){
		validation = false;
	}
	if ((ValidNumber1 == "two") && (ValidNumber2 != "two")){
		validation = false;
	}
	if ((ValidNumber1 == "three") && (ValidNumber2 != "three")){
		validation = false;
	}
	if ((ValidNumber1 == "four") && (ValidNumber2 != "four")){
		validation = false;
	}
	if ((ValidNumber1 == "five") && (ValidNumber2 != "five")){
		validation = false;
	}
	if ((ValidNumber1 == "six") && (ValidNumber2 != "six")){
		validation = false;
	}
	if ((ValidNumber1 == "seven") && (ValidNumber2 != "seven")){
		validation = false;
	}
	if ((ValidNumber1 == "eight") && (ValidNumber2 != "eight")){
		validation = false;
	}
	if ((ValidNumber1 == "nine") && (ValidNumber2 != "nine")){
		validation = false;
	}
	if ((ValidNumber1 == "reverse") && (ValidNumber2 != "reverse")){
		validation = false;
	}
	if ((ValidNumber1 == "skip") && (ValidNumber2 != "skip")){
		validation = false;
	}
	if ((ValidNumber1 == "draw") && (ValidNumber2 != "draw")){
		validation = false;
	}
	else {
		validation = true;
	}

	if (validation == true){
		return true;
	}
	else {
		return false;
	}
}
*/

void validcol(string top, bool &validation, list <string>::iterator it){
	unordered_set <string> green = {
		"\033[1;32m0  \033[0m","\033[1;32m0  \033[0m","\033[1;32m1  \033[0m","\033[1;32m1  \033[0m","\033[1;32m2  \033[0m","\033[1;32m2  \033[0m","\033[1;32m3  \033[0m","\033[1;32m3  \033[0m",
		"\033[1;32m4  \033[0m","\033[1;32m4  \033[0m","\033[1;32m5  \033[0m","\033[1;32m5  \033[0m","\033[1;32m6  \033[0m","\033[1;32m6  \033[0m","\033[1;32m7  \033[0m","\033[1;32m7  \033[0m",
		"\033[1;32m8  \033[0m","\033[1;32m8  \033[0m","\033[1;32m9  \033[0m","\033[1;32m9  \033[0m","\033[1;32m+2 \033[0m","\033[1;32m+2 \033[0m","\033[1;32mR  \033[0m","\033[1;32mR  \033[0m",
		"\033[1;32mS  \033[0m","\033[1;32mS  \033[0m","\033[1;32m+4 \033[0m","\033[1;32mC  \033[0m",
	};
	unordered_set <string> red = {
		"\033[1;31m0  \033[0m","\033[1;31m0  \033[0m","\033[1;31m1  \033[0m","\033[1;31m1  \033[0m","\033[1;31m2  \033[0m","\033[1;31m2  \033[0m","\033[1;31m3  \033[0m","\033[1;31m3  \033[0m",
		"\033[1;31m4  \033[0m","\033[1;31m4  \033[0m","\033[1;31m5  \033[0m","\033[1;31m5  \033[0m","\033[1;31m6  \033[0m","\033[1;31m6  \033[0m","\033[1;31m7  \033[0m","\033[1;31m7  \033[0m",
		"\033[1;31m8  \033[0m","\033[1;31m8  \033[0m","\033[1;31m9  \033[0m","\033[1;31m9  \033[0m","\033[1;31m+2 \033[0m","\033[1;31m+2 \033[0m","\033[1;31mR  \033[0m","\033[1;31mR  \033[0m",
		"\033[1;31mS  \033[0m","\033[1;31mS  \033[0m","\033[1;31m+4 \033[0m","\033[1;31mC  \033[0m",
	};
	unordered_set <string> yellow = { 
		"\033[1;33m0  \033[0m","\033[1;33m0  \033[0m","\033[1;33m1  \033[0m","\033[1;33m1  \033[0m","\033[1;33m2  \033[0m","\033[1;33m2  \033[0m","\033[1;33m3  \033[0m","\033[1;33m3  \033[0m",
		"\033[1;33m4  \033[0m","\033[1;33m4  \033[0m","\033[1;33m5  \033[0m","\033[1;33m5  \033[0m","\033[1;33m6  \033[0m","\033[1;33m6  \033[0m","\033[1;33m7  \033[0m","\033[1;33m7  \033[0m",
		"\033[1;33m8  \033[0m","\033[1;33m8  \033[0m","\033[1;33m9  \033[0m","\033[1;33m9  \033[0m","\033[1;33m+2 \033[0m","\033[1;33m+2 \033[0m","\033[1;33mR  \033[0m","\033[1;33mR  \033[0m",
		"\033[1;33mS  \033[0m","\033[1;33mS  \033[0m","\033[1;33m+4 \033[0m","\033[1;33mC  \033[0m",
    };
	unordered_set <string> blue ={
		"\033[1;34m0  \033[0m","\033[1;34m0  \033[0m","\033[1;34m1  \033[0m","\033[1;34m1  \033[0m","\033[1;34m2  \033[0m","\033[1;34m2  \033[0m","\033[1;34m3  \033[0m","\033[1;34m3  \033[0m",
		"\033[1;34m4  \033[0m","\033[1;34m4  \033[0m","\033[1;34m5  \033[0m","\033[1;34m5  \033[0m","\033[1;34m6  \033[0m","\033[1;34m6  \033[0m","\033[1;34m7  \033[0m","\033[1;34m7  \033[0m",
		"\033[1;34m8  \033[0m","\033[1;34m8  \033[0m","\033[1;34m9  \033[0m","\033[1;34m9  \033[0m","\033[1;34m+2 \033[0m","\033[1;34m+2 \033[0m","\033[1;34mR  \033[0m","\033[1;34mR  \033[0m",
		"\033[1;34mS  \033[0m","\033[1;34mS  \033[0m","\033[1;34m+4 \033[0m","\033[1;34mC  \033[0m",
	};
	unordered_set <string> black = {
		"\033[1;37m+4 \033[0m", "\033[1;37mC  \033[0m"
	};
		unordered_set <string> zero = {
		"\033[1;31m0  \033[0m","\033[1;32m0  \033[0m","\033[1;33m0  \033[0m","\033[1;34m0  \033[0m"
	};
	unordered_set <string> one = {
		"\033[1;31m1  \033[0m","\033[1;32m1  \033[0m","\033[1;33m1  \033[0m","\033[1;34m1  \033[0m"
	};
	unordered_set <string> two = {
		"\033[1;31m2  \033[0m","\033[1;32m2  \033[0m","\033[1;33m2  \033[0m","\033[1;34m2  \033[0m"
	};
	unordered_set <string> three = {
		"\033[1;31m3  \033[0m","\033[1;32m3  \033[0m","\033[1;33m3  \033[0m","\033[1;34m3  \033[0m"
	};
	unordered_set <string> four = {
		"\033[1;31m4  \033[0m","\033[1;32m4  \033[0m","\033[1;33m4  \033[0m","\033[1;34m4  \033[0m"
	};
	unordered_set <string> five = {
		"\033[1;31m5  \033[0m","\033[1;32m5  \033[0m","\033[1;33m5  \033[0m","\033[1;34m5  \033[0m"
	};
	unordered_set <string> six = {
		"\033[1;31m6  \033[0m","\033[1;32m6  \033[0m","\033[1;33m6  \033[0m","\033[1;34m6  \033[0m"
	};
	unordered_set <string> seven = {
		"\033[1;31m7  \033[0m","\033[1;32m7  \033[0m","\033[1;33m7  \033[0m","\033[1;34m7  \033[0m"
	};
	unordered_set <string> eight = {
		"\033[1;31m8  \033[0m","\033[1;32m8  \033[0m","\033[1;33m8  \033[0m","\033[1;34m8  \033[0m"
	};
	unordered_set <string> nine = {
		"\033[1;31m9  \033[0m","\033[1;32m9  \033[0m","\033[1;33m9  \033[0m","\033[1;34m9  \033[0m"
	};
	unordered_set <string> reverse = {
		"\033[1;31mR  \033[0m","\033[1;32mR  \033[0m","\033[1;33mR  \033[0m","\033[1;34mR  \033[0m"
	};
	unordered_set <string> skip = {
		"\033[1;31mS  \033[0m","\033[1;32mS  \033[0m","\033[1;33mS  \033[0m","\033[1;34mS  \033[0m"
	};
	unordered_set <string> draw = {
		"\033[1;31m+2 \033[0m","\033[1;32m+2 \033[0m","\033[1;33m+2 \033[0m","\033[1;34m+2 \033[0m"
		"\033[1;31m+4 \033[0m","\033[1;32m+4 \033[0m","\033[1;33m+4 \033[0m","\033[1;34m+4 \033[0m"
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


/*
	if (((ValidColor1 == "green") && (ValidColor2 != "green")) && ((ValidColor1 == "green") && (ValidColor2 != "black"))){
		validation = false;
	}
	if (((ValidColor1 == "red") && (ValidColor2 != "red")) && ((ValidColor1 == "red") && (ValidColor2 != "black"))){
		validation = false;
	}
	if (((ValidColor1 == "yellow") && (ValidColor2 != "yellow")) && ((ValidColor1 == "yellow") && (ValidColor2 != "black"))){
		validation = false;
	}
	if (((ValidColor1 == "blue") && (ValidColor2 != "blue")) && ((ValidColor1 == "blue") && (ValidColor2 != "black"))){
		validation = false;
	}
	else {
		validation = true;
	}
	
	if (validation == false){
		if ((ValidNumber1 == "zero") && (ValidNumber2 != "zero")){
			validation = false;
		}
		else if ((ValidNumber1 == "one") && (ValidNumber2 != "one")){
			validation = false;
		}
		else if ((ValidNumber1 == "two") && (ValidNumber2 != "two")){
			validation = false;
		}
		else if ((ValidNumber1 == "three") && (ValidNumber2 != "three")){
			validation = false;
		}
		else if ((ValidNumber1 == "four") && (ValidNumber2 != "four")){
			validation = false;
		}
		else if ((ValidNumber1 == "five") && (ValidNumber2 != "five")){
			validation = false;
		}
		else if ((ValidNumber1 == "six") && (ValidNumber2 != "six")){
			validation = false;
		}
		else if ((ValidNumber1 == "seven") && (ValidNumber2 != "seven")){
			validation = false;
		}
		else if ((ValidNumber1 == "eight") && (ValidNumber2 != "eight")){
			validation = false;
		}
		else if ((ValidNumber1 == "nine") && (ValidNumber2 != "nine")){
			validation = false;
		}
		else if ((ValidNumber1 == "reverse") && (ValidNumber2 != "reverse")){
			validation = false;
		}
		else if ((ValidNumber1 == "skip") && (ValidNumber2 != "skip")){
			validation = false;
		}
		else if ((ValidNumber1 == "draw") && (ValidNumber2 != "draw")){
			validation = false;
		}
		else {
			validation = true;
		}
	}
*/
//	return validation;
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
		"\033[1;37mC  \033[0m","\033[1;37mC  \033[0m","\033[1;37mC  \033[0m","\033[1;37mC  "
	};

	list <string> hand(0);
	list <string> comp1(0);
	list <string> comp2(0);
	list <string> comp3(0);
	
	bool running = true;
	string top;
	string choice;
	int whichcard;
	bool reverse = false;
	string color;
	int order = 1;
	string newcolor;
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
	top = *it;
	cards.erase(it);

	// play game
	while (running == true) {
		table(top, hand, comp1, comp2, comp3, cards);

		if (order == 1) {
			if ((top == "\033[1;31m+2 \033[0m") || (top == "\033[1;32m+2 \033[0m") || (top == "\033[1;33m+2 \033[0m") || (top == "\033[1;34m+2 \033[0m")){
				for (int i = 0; i < 2; i++){
					draw(hand, cards);
				}
			}	
			if ((top == "\033[1;31m+4 \033[0m") || (top == "\033[1;32m+4 \033[0m") || (top == "\033[1;33m+4 \033[0m") || (top == "\033[1;34m+4 \033[0m")){
				for (int i = 0; i < 4; i++){
					draw(hand, cards);
				}
			}
			
			cout << "do you want to draw or play?\n";
			cin >> choice;
			while ((choice != "draw") && (choice != "play")){
				cout << "*invalid*\ndo you want to draw or play?\n";
				cin >> choice;
			}
			if (choice == "draw"){
				draw(hand, cards);
				table(top, hand, comp1, comp2, comp3,cards);
			}
			if (choice == "play"){
				cout << "which card do you want to play? (Use the numbers below the cards) ";
				cin >> whichcard;

				list <string>::iterator it = hand.begin();
				advance(it, whichcard - 1);

				validcol(top, validation, it);
				if (validation == true){
					hand.erase(it);
					top = *it;
					powers(order, reverse, top);
				}
				/*
				if (validation == false){
					validnum(top, validation, it);
					if (validation == true){
						hand.erase(it);
						top = *it;
						powers(order, reverse, top);
					}
					*/
					while (validation == false){
						cout << "that card isn't valid, draw or play?\n";
						cin >> choice;
						while ((choice != "draw") && (choice != "play")){
							cout << "*invalid*\ndo you want to draw or play?\n";
							cin >> choice;
						}
						if (choice == "draw"){
							draw(hand, cards);
							table(top, hand, comp1, comp2, comp3, cards);
							validation = true;		
						}
						if (choice == "play"){
							list <string>::iterator it = hand.begin();
							cout << "which card do you want to play? (Use the numbers below the cards) ";
							cin >> whichcard;
							advance(it, whichcard - 1);
							validcol(top, validation, it);
							
							if (validation == false){
									cout << "you lost your chance, I'm making you draw" << endl;
									draw(hand, cards);
									table(top, hand, comp1, comp2, comp3, cards);
									validation = true;
							}
							
							else {
								hand.erase(it);
								top = *it;
								powers(order, reverse, top);
							}
						}
					}
				//}

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

				table(top, hand, comp1, comp2, comp3, cards);
			}

			change(running, reverse, order, hand, comp1, comp2, comp3, cards);
		}

		//compter 1
		if (order == 2){
			compplay(comp1, validation, cnewcolor, top, it, running, reverse, order, cards, hand, comp1, comp2, comp3);	
		}

		//computer 2
		if (order == 3){
			compplay(comp2, validation, cnewcolor, top, it, running, reverse, order, cards, hand, comp1, comp2, comp3);	
		}

		//computer 3
		if (order == 4){
			compplay(comp3, validation, cnewcolor, top, it, running, reverse, order, cards, hand, comp1, comp2, comp3);	
		}

	}

	//game over
	if (running == false){
		cout << endl << "game over!" << endl;
	}
}
