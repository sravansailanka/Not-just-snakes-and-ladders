#include<iostream>
#include<windows.h>
using namespace std;
void displayrules(){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

    cout<<"1. Each player is given one chance to roll the dice.\n";
    cout<<"2. A player has three options to choose:\n";
            SetConsoleTextAttribute(h,4);
        cout<<"\ta. 'x'- Roll the dice.\n";
        cout<<"\tb. 'q'- Quit.\n";
        cout<<"\tc. 'e'- Exchange turns.\n";
            SetConsoleTextAttribute(h,1);
    cout<<"3. Player's position is incremented based on the value on of the dice displayed when rolled.\n";
    cout<<"4. If a player finds the bottom of a ladder he/she climbs up the ladder.\n";
    cout<<"5. If a player finds the head of a snake he/she is sent to the tail of the snake.\n";
    cout<<"6. A player wins if his/her position is equal to 100.\n";
    cout<<"7. There are two implementations in this game when compared to the traditional game:\n";
            SetConsoleTextAttribute(h,4);
        cout<<"\ta. The players can exchange there positions based on the mutual agreement.\n";
        cout<<"\tb. Before starting the game players can change snakes into ladders and ladders into snakes.\n";
    SetConsoleTextAttribute(h,15);
}
