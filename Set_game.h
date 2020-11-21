#include<iostream>
#include<cstring>
using namespace std;
class Player{
public:
    string name;
    int pos;
    Player(){
        cout<<"player name: ";
        cin>>name;
        pos = 0;
    }
    string getname(){ return name;}
    int getpos(){return pos;}
};
class Snake{
public:
    int head;
    int tail;
};
class Ladder{
public:
    int top;
    int bottom;
};
void Setladders(Ladder* L){
    L[0].bottom = 3;
    L[1].bottom = 10;
    L[2].bottom = 27;
    L[3].bottom = 56;
    L[4].bottom = 61;
    L[5].bottom = 72;

    L[0].top = 39;
    L[1].top = 12;
    L[2].top = 53;
    L[3].top = 84;
    L[4].top = 99;
    L[5].top = 90;

}
void Setsnakes(Snake* S){
    S[0].head = 16;
    S[1].head = 31;
    S[2].head = 47;
    S[3].head = 63;
    S[4].head = 66;
    S[5].head = 97;

    S[0].tail = 13;
    S[1].tail = 4;
    S[2].tail = 25;
    S[3].tail = 60;
    S[4].tail = 52;
    S[5].tail = 75;
}
bool isLadder(Ladder* L, int pos){

    int i =0;
    for(i; i<6 && L[i].bottom != pos; i++);
    if(i == 6) return false;
    else return true;
}
bool isSnake(Snake* S, int pos){
    int i =0;
    for(i; i<6 && S[i].head != pos; i++);
    if(i == 6) return false;
    else return true;
}
int getTop(Ladder* L, int pos){
    int i;
    for(i=0;i<6&& pos != L[i].bottom;i++);
    return L[i].top;
}
int getTail(Snake* S, int pos){
    int i;
    for(i=0;i<6&& pos != S[i].head;i++);
    return S[i].tail;
}
void interchangeSnakesandLadders(Snake* S,Ladder* L){
    for(int i=0; i<6; i++){
        int up,bottom;
        up = S[i].head;
        S[i].head = L[i].top;
        L[i].top = up;

        bottom = S[i].tail;
        S[i].tail = L[i].bottom;
        L[i].bottom = bottom;
    }

}
