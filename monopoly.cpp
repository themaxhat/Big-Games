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

        Property(string nameP, Player ownerP, String colorP, int rent){
            name = nameP;
            owner = ownerP;
            color = colorP;
            rent = rentP;
        }
        Property(string nameP, Player ownerP, String colorP){
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
    Property medAve("Mediterranean Avenue", monopolyMan, "brown");
    Property balAve("Baltic Avenue", monopolyMan, "brown");


    boardArr[0] = go;
}

int main() 
{
    initializeBoard();

    return 0;
}


