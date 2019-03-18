#ifndef FN_H_INCLUDED
#define FN_H_INCLUDED

#define SIZE 15

#include <stdlib.h>
#include <iostream>

class info{
    public:
        int level=1;
        int slashed_line=0;
        int pt=0;
        void print_info();
}extern game;

class block_type{
public:
    int ax[5][4]={},bx[5][4]={},cx[5][4]={},dx[5][4]={};
    int ay[5][4]={},by[5][4]={},cy[5][4]={},dy[5][4]={};
    void gen_block_type();
};

class block{
private:
    int x=SIZE/2;
    int y=3;
public:
    int type=0;
    int model=0;
    void backtotop();
    void shownextblock();
    void print_block();
    void erase_block();
    void decend();
    void moveLR(bool direction);
    void nextmodel();
    bool right_blocked();
    bool left_blocked();
    bool is_touched();
}extern now,next;

void reset();

void nextblock();

void slash();

void decend_line(int y);

void frame();

#endif // FN_H_INCLUDED
