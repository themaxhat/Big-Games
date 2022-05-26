#include <iostream>
#include <array>

using namespace std;


class Player{
    public:
        string name;

        Player(string nameP){
            name = nameP;
            position = 0;
        }
        Player(){
            name = "null";
            position = 0;
        }

    private:
        int position;
    
};

class Property{
    public:
        string name;
        Player owner;
        string color;
        int rent;
        int price;

        Property(string nameP, Player ownerP, string colorP, int rentP, int priceP){
            name = nameP;
            owner = ownerP;
            color = colorP;
            rent = rentP;
            price = priceP;
        }
        Property(string nameP, Player ownerP, string colorP){
            name = nameP;
            owner = ownerP;
            color = colorP;
        }
        Property(){
            name = "null";
            color = "black";
        }
};

Property boardArr[40];
Player monopolyMan("Monopoly Man"); 

void initializeBoard(){
    // Special properties
    Property go("Go", monopolyMan, "special");

    // Utilities
    
    // RR

    // Monopoly Properties
    Property medAve("Mediterranean Ave.", monopolyMan, "brown", 2, 60);
    Property balAve("Baltic Ave.", monopolyMan, "brown", 4, 60);

    Property oriAve("Oriental Ave.", monopolyMan, "light blue", 6, 100);
    Property verAve("Vermont Ave.", monopolyMan, "light blue", 6, 100);
    Property conAve("Connecticut Ave.", monopolyMan, "light blue", 8, 120);

    Property stChar("St. Charles Place", monopolyMan, "pink", 10, 140);
    Property staAve("States Ave.", monopolyMan, "pink", 10, 140);
    Property vgaAve("Virgina Ave.", monopolyMan, "pink", 12, 160);

    Property stJms("St. James Place", monopolyMan, "orange", 14, 180);
    Property tenAve("Tennessee Ave.", monopolyMan, "orange", 14, 180);
    Property nyAve("New York Ave.", monopolyMan, "orange", 16, 200);

    Property kenAve("Kentucky Ave.", monopolyMan, "red", 18, 220);
    Property indAve("Indiana Ave.", monopolyMan, "red", 18, 220);
    Property illAve("Illinois Ave.", monopolyMan, "red", 20, 240);

    Property atlAve("Atlantic Ave.", monopolyMan, "yellow", 22, 260);
    Property venAve("Ventnor Ave.", monopolyMan, "yellow", 22, 260);
    Property mvnGdn("Marvin Gardens", monopolyMan, "yellow", 24, 280);

    Property pcfAve("Pacific Ave.", monopolyMan, "green", 26, 300);
    Property ncAve("North Carolina Ave.", monopolyMan, "green", 26, 300);
    Property penAve("Pennsylvania Ave.", monopolyMan, "green", 28, 320);

    Property prkPla("Park Place", monopolyMan, "blue", 35, 350);
    Property brdwlk("Boardwalk", monopolyMan, "blue", 50, 400);

    boardArr[0] = go;
}

int main() 
{
    initializeBoard();

    return 0;
}


