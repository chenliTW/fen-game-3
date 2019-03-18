#include <Windows.h>

#include "fn.h"

#include <string.h>
#include <time.h>

char world[SIZE+10][SIZE];

void info::print_info(){
    std::string board="##########|level:  ||next:   ||        ||        ||        ||        ||        |##########";
    board[17]=(char)(level+48);
    for(int i=0;i<13;++i){
        for(int j=0;j<10;++j){
            if(10*i+j<board.length()){
                world[j+SIZE][i]=board[10*i+j];
            }
        }
    }
    next.shownextblock();
}

void block_type::gen_block_type(){
    //         @
    //         @  @@@@
    //         @
    //         @
    ax[0][0]=0;bx[0][0]=0;cx[0][0]=0;dx[0][0]=0;
    ay[0][0]=1;by[0][0]=0;cy[0][0]=-1;dy[0][0]=-2;
    ax[0][1]=1;bx[0][1]=0;cx[0][1]=-1;dx[0][1]=-2;
    ay[0][1]=0;by[0][1]=0;cy[0][1]=0;dy[0][1]=0;
    ax[0][2]=0;bx[0][2]=0;cx[0][2]=0;dx[0][2]=0;
    ay[0][2]=1;by[0][2]=0;cy[0][2]=-1;dy[0][2]=-2;
    ax[0][3]=1;bx[0][3]=0;cx[0][3]=-1;dx[0][3]=-2;
    ay[0][3]=0;by[0][3]=0;cy[0][3]=0;dy[0][3]=0;
    //@@      @     @
    // @ @@@  @   @@@
    // @ @    @@
    ax[1][0]=-1;bx[1][0]=0;cx[1][0]=0;dx[1][0]=0;
    ay[1][0]=-1;by[1][0]=-1;cy[1][0]=0;dy[1][0]=1;
    ax[1][1]=-1;bx[1][1]=0;cx[1][1]=1;dx[1][1]=-1;
    ay[1][1]=0;by[1][1]=0;cy[1][1]=0;dy[1][1]=1;
    ax[1][2]=0;bx[1][2]=0;cx[1][2]=0;dx[1][2]=1;
    ay[1][2]=-1;by[1][2]=0;cy[1][2]=1;dy[1][2]=1;
    ax[1][3]=1;bx[1][3]=-1;cx[1][3]=0;dx[1][3]=1;
    ay[1][3]=-1;by[1][3]=0;cy[1][3]=0;dy[1][3]=0;
    // @@ @    @
    // @  @@@  @ @@@
    // @      @@   @
    ax[2][0]=0;bx[2][0]=1;cx[2][0]=0;dx[2][0]=0;
    ay[2][0]=-1;by[2][0]=-1;cy[2][0]=0;dy[2][0]=1;
    ax[2][1]=-1;bx[2][1]=-1;cx[2][1]=0;dx[2][1]=1;
    ay[2][1]=-1;by[2][1]=0;cy[2][1]=0;dy[2][1]=0;
    ax[2][2]=0;bx[2][2]=0;cx[2][2]=-1;dx[2][2]=0;
    ay[2][2]=-1;by[2][2]=0;cy[2][2]=1;dy[2][2]=1;
    ax[2][3]=-1;bx[2][3]=0;cx[2][3]=1;dx[2][3]=1;
    ay[2][3]=0;by[2][3]=0;cy[2][3]=0;dy[2][3]=1;
    // @   @         @
    //@@@ @@   @@@   @@
    //     @    @    @
    ax[3][0]=0;bx[3][0]=-1;cx[3][0]=0;dx[3][0]=1;
    ay[3][0]=-1;by[3][0]=0;cy[3][0]=0;dy[3][0]=0;
    ax[3][1]=0;bx[3][1]=-1;cx[3][1]=0;dx[3][1]=0;
    ay[3][1]=-1;by[3][1]=0;cy[3][1]=0;dy[3][1]=1;
    ax[3][2]=-1;bx[3][2]=0;cx[3][2]=1;dx[3][2]=0;
    ay[3][2]=0;by[3][2]=0;cy[3][2]=0;dy[3][2]=1;
    ax[3][3]=0;bx[3][3]=0;cx[3][3]=1;dx[3][3]=0;
    ay[3][3]=-1;by[3][3]=0;cy[3][3]=0;dy[3][3]=1;
    //@@
    //@@
    ax[4][0]=-1;bx[4][0]=0;cx[4][0]=-1;dx[4][0]=0;
    ay[4][0]=0;by[4][0]=0;cy[4][0]=1;dy[4][0]=1;
    ax[4][1]=-1;bx[4][1]=0;cx[4][1]=-1;dx[4][1]=0;
    ay[4][1]=0;by[4][1]=0;cy[4][1]=1;dy[4][1]=1;
    ax[4][2]=-1;bx[4][2]=0;cx[4][2]=-1;dx[4][2]=0;
    ay[4][2]=0;by[4][2]=0;cy[4][2]=1;dy[4][2]=1;
    ax[4][3]=-1;bx[4][3]=0;cx[4][3]=-1;dx[4][3]=0;
    ay[4][3]=0;by[4][3]=0;cy[4][3]=1;dy[4][3]=1;
}

block_type defult_block;

void block::backtotop(){
    x=SIZE/2;
    y=3;
}

void block::shownextblock(){
    x=SIZE+4;
    y=5;
    print_block();
}

void block::print_block(){
    world[defult_block.ax[type][model]+x][defult_block.ay[type][model]+y]='@';
    world[defult_block.bx[type][model]+x][defult_block.by[type][model]+y]='@';
    world[defult_block.cx[type][model]+x][defult_block.cy[type][model]+y]='@';
    world[defult_block.dx[type][model]+x][defult_block.dy[type][model]+y]='@';
}

void block::erase_block(){
    world[defult_block.ax[type][model]+x][defult_block.ay[type][model]+y]=' ';
    world[defult_block.bx[type][model]+x][defult_block.by[type][model]+y]=' ';
    world[defult_block.cx[type][model]+x][defult_block.cy[type][model]+y]=' ';
    world[defult_block.dx[type][model]+x][defult_block.dy[type][model]+y]=' ';
}

void block::decend(){
    erase_block();
    y++;
}

void block::moveLR(bool direction){//0->LEFT
    erase_block();
    if(direction){
        if(!right_blocked()){
            x++;
        }
    }else{
        if(!left_blocked()){
            x--;
        }
    }
}

void block::nextmodel(){
    erase_block();
    if(model+1>3){
        model=0;
    }else{
        model++;
    }
    print_block();
}

bool block::right_blocked(){
    switch(type){
        case 0:
            if(model==1||model==3){
                if(world[x+2][y]=='@'||world[x+2][y]=='|'){
                    return 1;
                }
            }else if(model==0||model==2){
                if(world[x+1][y-1]=='@'||world[x+1][y-1]=='|'||world[x+1][y]=='@'||world[x+1][y]=='|'||world[x+1][y+1]=='@'||world[x+1][y+1]=='|'||world[x+1][y+2]=='@'||world[x+1][y+2]=='|'){
                    return 1;
                }
            }
            break;
        case 1:
            if(model==0){
                if(world[x+1][y-1]=='@'||world[x+1][y-1]=='|'||world[x+1][y]=='@'||world[x+1][y]=='|'||world[x+1][y+1]=='@'||world[x+1][y+1]=='|'){
                    return 1;
                }
            }else if(model==1){
                if(world[x+2][y]=='@'||world[x+2][y]=='|'||world[x][y+1]=='@'||world[x][y+1]=='|'){
                    return 1;
                }
            }else if(model==2){
                if(world[x+1][y-1]=='@'||world[x+1][y-1]=='|'||world[x+1][y]=='@'||world[x+1][y]=='|'||world[x+2][y+1]=='@'||world[x+2][y+1]=='|'){
                    return 1;
                }
            }else if(model==3){
                if(world[x+2][y-1]=='@'||world[x+2][y-1]=='|'||world[x+2][y]=='@'||world[x+2][y]=='|'){
                    return 1;
                }
            }
            break;
        case 2:
            if(model==0){
                if(world[x+2][y-1]=='@'||world[x+2][y-1]=='|'||world[x+1][y]=='@'||world[x+1][y]=='|'||world[x+1][y+1]=='@'||world[x+1][y+1]=='|'){
                    return 1;
                }
            }else if(model==1){
                if(world[x][y-1]=='@'||world[x][y-1]=='|'||world[x+2][y]=='@'||world[x+2][y]=='|'){
                    return 1;
                }
            }else if(model==2){
                if(world[x+1][y-1]=='@'||world[x+1][y-1]=='|'||world[x+1][y]=='@'||world[x+1][y]=='|'||world[x+1][y+1]=='@'||world[x+1][y+1]=='|'){
                    return 1;
                }
            }else if(model==3){
                if(world[x+2][y]=='@'||world[x+2][y]=='|'||world[x+2][y+1]=='@'||world[x+2][y+1]=='|'){
                    return 1;
                }
            }
            break;
        case 3:
            if(model==0){
                if(world[x+2][y]=='@'||world[x+2][y]=='|'||world[x+1][y-1]=='@'||world[x+1][y-1]=='|'){
                    return 1;
                }
            }else if(model==1){
                if(world[x+1][y-1]=='@'||world[x+1][y-1]=='|'||world[x+1][y]=='@'||world[x+1][y]=='|'||world[x+1][y+1]=='@'||world[x+1][y+1]=='|'){
                    return 1;
                }
            }else if(model==2){
                if(world[x+2][y]=='@'||world[x+2][y]=='|'||world[x+1][y+1]=='@'||world[x+1][y+1]=='|'){
                    return 1;
                }
            }else if(model==3){
                if(world[x+1][y-1]=='@'||world[x+1][y-1]=='|'||world[x+2][y]=='@'||world[x+2][y]=='|'||world[x+1][y+1]=='@'||world[x+1][y+1]=='|'){
                    return 1;
                }
            }
            break;
        case 4:
            if(world[x+1][y]=='@'||world[x+1][y]=='|'||world[x+1][y+1]=='@'||world[x+1][y+1]=='|'){
                return 1;
            }
            break;
    }
    return 0;
}

bool block::left_blocked(){
    switch(type){
        case 0:
            if(model==1||model==3){
                if(world[x-3][y]=='@'||world[x-3][y]=='|'){
                    return 1;
                }
            }else if(model==0||model==2){
                if(world[x-1][y-1]=='@'||world[x-1][y-1]=='|'||world[x-1][y]=='@'||world[x-1][y]=='|'||world[x-1][y+1]=='@'||world[x-1][y+1]=='|'||world[x-1][y+2]=='@'||world[x-1][y+2]=='|'){
                    return 1;
                }
            }
            break;
        case 1:
            if(model==0){
                if(world[x-2][y-1]=='@'||world[x-2][y-1]=='|'||world[x-1][y]=='@'||world[x-1][y]=='|'||world[x-1][y+1]=='@'||world[x-1][y+1]=='|'){
                    return 1;
                }
            }else if(model==1){
                if(world[x-2][y]=='@'||world[x-2][y]=='|'||world[x-2][y+1]=='@'||world[x-2][y+1]=='|'){
                    return 1;
                }
            }else if(model==2){
                if(world[x-1][y-1]=='@'||world[x-1][y-1]=='|'||world[x-1][y]=='@'||world[x-1][y]=='|'||world[x-1][y+1]=='@'||world[x-1][y+1]=='|'){
                    return 1;
                }
            }else if(model==3){
                if(world[x-2][y]=='@'||world[x-2][y]=='|'||world[x][y-1]=='@'||world[x][y-1]=='|'){
                    return 1;
                }
            }
            break;
        case 2:
            if(model==0){
                if(world[x-1][y-1]=='@'||world[x-1][y-1]=='|'||world[x-1][y]=='@'||world[x-1][y]=='|'||world[x-1][y+1]=='@'||world[x-1][y+1]=='|'){
                    return 1;
                }
            }else if(model==1){
                if(world[x-2][y-1]=='@'||world[x-2][y-1]=='|'||world[x-2][y]=='@'||world[x-2][y]=='|'){
                    return 1;
                }
            }else if(model==2){
                if(world[x-1][y-1]=='@'||world[x-1][y-1]=='|'||world[x-1][y]=='@'||world[x-1][y]=='|'||world[x-2][y+1]=='@'||world[x-2][y+1]=='|'){
                    x++;
                }
            }else if(model==3){
                if(world[x-2][y]=='@'||world[x-2][y]=='|'||world[x][y+1]=='@'||world[x][y+1]=='|'){
                    return 1;
                }
            }
            break;
        case 3:
            if(model==0){
                if(world[x-2][y]=='@'||world[x-2][y]=='|'||world[x-1][y-1]=='@'||world[x-1][y-1]=='|'){
                    return 1;
                }
            }else if(model==1){
                if(world[x-1][y-1]=='@'||world[x-1][y-1]=='|'||world[x-2][y]=='@'||world[x-2][y]=='|'||world[x-1][y+1]=='@'||world[x-1][y+1]=='|'){
                    return 1;
                }
            }else if(model==2){
                if(world[x-2][y]=='@'||world[x-2][y]=='|'||world[x-1][y+1]=='@'||world[x-1][y+1]=='|'){
                    return 1;
                }
            }else if(model==3){
                if(world[x-1][y-1]=='@'||world[x-1][y-1]=='|'||world[x-1][y]=='@'||world[x-1][y]=='|'||world[x-1][y+1]=='@'||world[x-1][y+1]=='|'){
                    return 1;
                }
            }
            break;
        case 4:
            if(world[x-2][y]=='@'||world[x-2][y]=='|'||world[x-2][y+1]=='@'||world[x-2][y+1]=='|'){
                return 1;
            }
            break;
    }
    return 0;
}

bool block::is_touched(){
    switch(type){
        case 0:
            if(model==0||model==2){
                if(world[x][y+2]=='@'||world[x][y+2]=='#'){
                    return 1;
                }
            }else if(model==1||model==3){
                for(int i=-1;i<2;++i){
                    if(world[x+i][y+1]=='@'||world[x+i][y+1]=='#'){
                        return 1;
                    }
                }
            }
            break;
        case 1:
            if(model==0){
                if(world[x][y+2]=='@'||world[x][y+2]=='#'||world[x-1][y]=='@'||world[x-1][y]=='#'){
                    return 1;
                }
            }else if(model==1){
                if(world[x-1][y+2]=='@'||world[x-1][y+2]=='#'||world[x][y+1]=='@'||world[x][y+1]=='#'||world[x+1][y+1]=='@'||world[x+1][y+1]=='#'){
                    return 1;
                }
            }else if(model==2){
                if(world[x][y+2]=='@'||world[x][y+2]=='#'||world[x+1][y+2]=='@'||world[x+1][y+2]=='#'){
                    return 1;
                }
            }else if(model==3){
                if(world[x-1][y+1]=='@'||world[x-1][y+1]=='#'||world[x][y+1]=='@'||world[x][y+1]=='#'||world[x+1][y+1]=='@'||world[x+1][y+1]=='#'){
                    return 1;
                }
            }
            break;
        case 2:
            if(model==0){
                if(world[x][y+2]=='@'||world[x][y+2]=='#'||world[x+1][y]=='@'||world[x+1][y]=='#'){
                    return 1;
                }
            }else if(model==1){
                if(world[x-1][y+1]=='@'||world[x-1][y+1]=='#'||world[x][y+1]=='@'||world[x][y+1]=='#'||world[x+1][y+1]=='@'||world[x+1][y+1]=='#'){
                    return 1;
                }
            }else if(model==2){
                if(world[x-1][y+2]=='@'||world[x-1][y+2]=='#'||world[x][y+2]=='@'||world[x][y+2]=='#'){
                    return 1;
                }
            }else if(model==3){
                if(world[x-1][y+1]=='@'||world[x-1][y+1]=='#'||world[x][y+1]=='@'||world[x][y+1]=='#'||world[x+1][y+2]=='@'||world[x+1][y+2]=='#'){
                    return 1;
                }
            }
            break;
        case 3:
            if(model==0){
                if(world[x-1][y+1]=='@'||world[x-1][y+1]=='#'||world[x][y+1]=='@'||world[x][y+1]=='#'||world[x+1][y+1]=='@'||world[x+1][y+1]=='#'){
                    return 1;
                }
            }else if(model==1){
                if(world[x-1][y+1]=='@'||world[x-1][y+1]=='#'||world[x][y+2]=='@'||world[x][y+2]=='#'){
                    return 1;
                }
            }else if(model==2){
                if(world[x-1][y+1]=='@'||world[x-1][y+1]=='#'||world[x][y+2]=='@'||world[x][y+2]=='#'||world[x+1][y+1]=='@'||world[x+1][y+1]=='#'){
                    return 1;
                }
            }else if(model==3){
                if(world[x+1][y+1]=='@'||world[x+1][y+1]=='#'||world[x][y+2]=='@'||world[x][y+2]=='#'){
                    return 1;
                }
            }
            break;
        case 4:
            if(world[x][y+2]=='@'||world[x][y+2]=='#'||world[x-1][y+2]=='@'||world[x-1][y+2]=='#'){
                return 1;
            }
            break;
    }
    return 0;
}

info game;

block now,next;

void reset(){
    srand(time(NULL));
    memset(world,0,sizeof(world));
    defult_block.gen_block_type();
    next.type=rand()%5;
    next.model=0;
    nextblock();
    for(int y=0;y<SIZE;++y){
        for(int x=0;x<SIZE;++x){
            if(x==0||x==SIZE-1){
                world[x][y]='|';
            }else if(y==SIZE-1){
                world[x][y]='#';
            }else{
                world[x][y]=' ';
            }
        }
    }
}

void nextblock(){
    srand(time(NULL));
    now.backtotop();
    now.type=next.type;
    now.model=0;
    next.type=rand()%5;
    next.model=0;
}

void slash(){
    bool full_line[SIZE-2]={};
    for(int y=SIZE-2;y>0;--y){
        int x;
        for(x=1;x<SIZE-1;++x){
            if(world[x][y]!='@'){
                break;
            }
        }
        if(x==SIZE-1){
            full_line[y-1]=1;
        }
    }
    for(int y=SIZE-2;y>0;--y){
        if(full_line[y-1]){
            for(int x=1;x<SIZE-1;++x){
                world[x][y]='*';
            }
        }
    }
    system("cls");
    frame();
    Sleep(700);
    for(int y=1;y<SIZE-1;++y){
        if(full_line[y-1]){
            for(int yy=y;yy>1;--yy){
                decend_line(yy-1);
            }
        }
    }
}

void decend_line(int y){ //y down
    for(int x=1;x<SIZE-1;++x){
        world[x][y+1]=world[x][y];
    }
}

void frame(){
    now.print_block();
    std::string output="";
    for(int y=0;y<SIZE;++y){
        for(int x=0;x<SIZE+10;++x){
            output.push_back(world[x][y]);
        }
        output.push_back('\n');
    }
    std::cout<<output;
}
