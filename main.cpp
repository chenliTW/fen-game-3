#include <Windows.h>

#include "fn.h"

#include <conio.h>

int main(){
    reset();
    game.print_info();
    while(1){
        system("cls");
        frame();
        for(int i=0;i<75-(game.level);++i){
            if(kbhit()){
                char ch = getch();
                switch((int)ch){
                    case 100://d
                        now.moveLR(1);
                        system("cls");
                        frame();
                        break;
                    case 115://s
                        if(!now.is_touched()){
                            now.decend();
                        }
                        system("cls");
                        frame();
                        break;
                    case 97://a
                        now.moveLR(0);
                        system("cls");
                        frame();
                        break;
                    case 119://w
                        now.nextmodel();
                        system("cls");
                        frame();
                        break;
                }
                i+=15;
            }
            Sleep(5);
        }
        if(now.is_touched()){
            slash();
            nextblock();
            game.print_info();
        }else{
            now.decend();
        }
    }
    return 0;
}
