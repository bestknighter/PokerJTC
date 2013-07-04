#include "gameLogic.h"

int main(int argc, char *argv[]){
    int esc = 1;
    Stats* stats;
    stats = initGame();
    do{
        system("CLS");
        switch(esc){
            case 0:
                break;
            case 1:
                esc = menuPrincipal();
                break;
            case 11:
                restartGame(stats);
                esc = menuNovoJogo(stats);
                break;
            case 111:
                menuNovoJogador(stats);
                esc /= 10;
                break;
            case 112:
                seletorRodada(stats);
                esc = novaPartida();
                break;
            case 10:
            case 110:
                esc = 0;
                break;
        };
    }while(esc!=0);
    return 0;
}
