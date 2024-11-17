#include <iostream>
#include <ctime>
#include <vector>


using namespace std;

// declare the Players and their lives

int player;
int PC; 
int livesPLayer = 4;
int livesPC = 4;

// declare the shots (blank / live)

int live;
int blank;
int max = 8;
int min = 2;
int option;

// items

int bier;
int cigarrettes;
int handcuffs;
int magneficGlass;



// declare amos

void loadGun(){

live = ( rand() %  8 ) + 1;
blank = ( rand() %  8 ) + 1;

if (live > 4 || live < 2){
  loadGun();
}

if (blank > 4 || blank < 2){
  loadGun();
}

}

// display functions

void dislpayShots( int* live, int* blank){
loadGun(); 
cout << endl;
cout << "Live: " << *live << " " << "Blank: " << *blank << endl;
}

void displayHealth( int livesPLayer, int livesPC){
cout << endl;
cout << "You: " <<  livesPLayer << endl;
cout << "PC: " <<  livesPC << endl;
cout << "********************************** \n";
}


bool gameOver(){
    if (livesPC == 0 || livesPLayer == 0){
        return false;
    } 
    else {
        return true;
    }
}


void takeRisk( int* livesPLayer, int* livesPC , int* blank, int* live){
    cout << "1.You          2.Dealer" << endl;
    cin >> option;
    int random = ( rand() % 2) + 1;
   
    bool heartLost = false; // Flag to track if a heart is lost due to a boom

    if (random == 1) {
        cout << "Boom \n";
        if (option == 1) {
            (*livesPLayer)--;
            heartLost = true;
        } else {
            (*livesPC)--;
            heartLost = true;
        }
    } else {
        cout << "It's a blank \n";
        (*blank)--;
    }

    if (heartLost) {
        (*live)--;
        cout << "You lose a heart \n";
    } else {
        cout << "No hearts lost \n";
    }
   
   dislpayShots( live , blank);
   if ( *live + *blank == 0 && !gameOver()){
    loadGun();
   }
}



int main(){

dislpayShots( &live , &blank);
do{
cout << "**********************************";
srand (time(NULL));
displayHealth( livesPLayer, livesPC);
takeRisk( &livesPLayer, &livesPC, &blank, &live);
}
while(gameOver());
}