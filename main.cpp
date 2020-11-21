#include<iostream>
#include<cstring>
#include<conio.h>
#include<windows.h>
#include "gametime.h"
#include "Displayrules.h"
#include "Set_game.h"
#include "Player1.h"
using namespace std;

int main()
{

    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    Ladder L[6];
    Snake S[6];
    Setsnakes(S);
    Setladders(L);
    SetConsoleTextAttribute(h,2);
    cout<<"\tWELCOME TO \"NOT JUST SNAKE AND LADDER\"\n\t\t  A 2-player game\n";
    SetConsoleTextAttribute(h,15);
    cout<<"Enter players name:\n";
    cout<<"Enter 1st ";
    SetConsoleTextAttribute(h,9);
    Player p1;
    SetConsoleTextAttribute(h,15);
    cout<<"Enter 2nd ";
    SetConsoleTextAttribute(h,6);
    Player p2;
    SetConsoleTextAttribute(h,1);
    cout<<"\nGAME RULES :\n";
    displayrules();
    char choice;
    SetConsoleTextAttribute(h,15);
    cout<<"Enter\n1. To play normal snake and ladders.\n2. To interchange snakes and ladders and then play.\n";
    Gametime timer;
    timer.Setbegintime();
    while(1){
        cout<<"choice : ";cin>>choice;
        if(choice == '1'){
            break;
        }
        else if(choice == '2'){
            interchangeSnakesandLadders(S,L);
            break;
        }
        else{
            cout<<"enter valid choice\n";
        }
    }
    cout<<"Let's start the game!\n";
    int turn = 0;
    int dice;
    srand(time(0));

    while(1){

        //player 1
        if(turn%2 == 0){
            SetConsoleTextAttribute(h,3);
            cout<<p1.getname()<<" : You are at "<<p1.getpos()<<endl;
            cout<<"Enter choice(x/q/e) : ";cin>> choice;
            if(choice == 'x'){
                for(int k =0; k<7;k++){
                    dice = rand()%6 + 1;
                    cout<<dice<<"\b";
                    for(int x = 0;x<100000000;x++);
                }
                cout<<dice<<endl;
                cout<<"Dice Displayed:"<<dice<<endl;
                p1.pos = p1.pos + dice;
                if(p1.pos == 100){
                    cout<<"--------------------------------";
                    cout<<"\n\t\t\tCONGRATS\n\t\t";
                    cout<<p1.getname() <<" Won\n";
                    cout<<"--------------------------------\n";
                    break;

                }
                else if(p1.pos > 100){
                    p1.pos = p1.pos - dice;
                }
                else if(isLadder(L,p1.pos)){
                    cout<<"Hurray you found a ladder\n";
                    p1.pos = getTop(L,p1.pos);
                }
                else if(isSnake(S,p1.pos)){
                    cout<<"OOPS..! It's a snake\n";
                    p1.pos = getTail(S,p1.pos);
                }
                cout<<p1.getname()<<" reached : "<<p1.pos<<endl<<endl;

            }
            else if(choice == 'q'){
                cout<<"Final positions\n"<<p1.getname()<<" : "<<p1.pos<<endl;
                cout<<p2.getname()<<" : "<<p2.pos<<endl;

                cout<<"Thanks for playing. Have a nice day.\n";
                break;
            }
            else if(choice == 'e'){
                string temp;
                char c1,c2;
                cout<<"CONFORMATION FROM "<<p1.getname()<<"(y/n) :";cin>>c1;
                cout<<"CONFORMATION FROM "<<p2.getname()<<"(y/n) :";cin>>c2;
                if(c1 == 'y' && c2 == 'y'){
                    temp = p1.name;
                    p1.name = p2.name;
                    p2.name = temp;
                    cout<<"Turns are exchanged\n";
                }
                else
                    cout<<"Failed to exchange turns\n";
            }
            else{
                cout<<"Invalid CHOICE\nEnter proper choice :";cin>>choice;
                continue;
            }
        }
        //player 2
        else{
            SetConsoleTextAttribute(h,6);
            cout<<"\t\t"<<p2.getname()<<" : You are at "<<p2.getpos()<<endl;
            cout<<"\t\tEnter choice(x/q/e) : ";cin>> choice;
            if(choice == 'x'){
                for(int k =0; k<7;k++){
                    dice = rand()%6 + 1;
                    cout<<"\t\t"<<dice<<"\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
                    for(int x = 0; x<100000000;x++);
                }
                cout<<"\t\t"<<dice<<endl;

                cout<<"\t\tDice Displayed:"<<dice<<endl;
                p2.pos = p2.pos + dice;
                if(p2.pos == 100){
                    cout<<"-----------------------------------";
                    cout<<"\n\t\tCONGRATS\n";
                    cout<<"\t\t"<<p2.getname() <<" Won\n";
                    cout<<"-----------------------------------\n";
                    break;
                }
                else if(p2.pos >100){
                    p2.pos = p2.pos-dice;
                }
                else if(isLadder(L,p2.pos)){
                    cout<<"\t\tHurray you found a ladder\n";
                    p2.pos = getTop(L,p2.pos);
                }
                else if(isSnake(S,p2.pos)){
                    cout<<"\t\tOOPS..! It's a snake\n";
                    p2.pos = getTail(S,p2.pos);
                }
                cout<<"\t\t"<<p2.getname()<<" reached : "<<p2.pos<<endl<<endl;

            }
            else if(choice == 'q'){
                cout<<"Final positions\n"<<p1.getname()<<" : "<<p1.pos<<endl;
                cout<<p2.getname()<<" : "<<p2.pos<<endl;

                cout<<"Thanks for playing. Have a nice day.\n";
                break;
            }
            else if(choice == 'e'){
                string temp;
                char c1,c2;
                cout<<"CONFORMATION FROM "<<p1.getname()<<"(y/n) :";cin>>c1;
                cout<<"CONFORMATION FROM "<<p2.getname()<<"(y/n) :";cin>>c2;
                if(c1 == 'y' && c2 == 'y'){
                    temp = p1.name;
                    p1.name = p2.name;
                    p2.name = temp;
                    cout<<"Turns are exchanged\n";
                }
                else
                    cout<<"Failed to exchange turns\n";
            }
            else{
                SetConsoleTextAttribute(h,15);
                cout<<"Invalid CHOICE\nEnter proper choice :";cin>>choice;
                continue;
            }
        }
        turn++;
    }
    cout<<"DO YOU WANT TO PLAY AGAIN?(y/n):";cin>>choice;
    if(choice == 'y'){

        main();
    }
    else {
        SetConsoleTextAttribute(h,15);
        timer.Setendtime();
        timer.Settimeellapsed();
        cout<<"Total time taken to complete the game: ";
        cout<<timer.timeellapsed<<" seconds";
        cout<<"\nProgram exited successfully\n";
        return 0 ;
    }
    return 0;
}
