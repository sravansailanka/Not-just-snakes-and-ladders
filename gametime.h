#include<time.h>
#include<iostream>
#include<conio.h>
class Gametime{
public:
    clock_t starttime;
    clock_t endtime;
    clock_t timeellapsed;

    Gametime(){
        starttime =0;
        endtime =0;
        timeellapsed =0;
    }
    void Setbegintime();
    void Setendtime();
    void Settimeellapsed();
};

void Gametime::Setbegintime(){
    clock_t begin = clock();
    starttime = begin;
}
void Gametime::Setendtime(){
    clock_t end = clock();
    endtime = end;
}
void Gametime::Settimeellapsed(){
    clock_t ellapse = endtime - starttime;
    timeellapsed = ellapse/1000;
}
