#include<stdio.h> 
#include <time.h>
#include <math.h>

int main(){
    int contador = 0;
    double ahora;
    while(1){
        ahora = (double)clock()/CLOCKS_PER_SEC;
        if(floor(ahora) > contador){
            contador++;
            printf("Han pasado %d segundos desde que se inicio el programa\n", contador);
        }
        if(contador==5) break;
    }

    return 0;
}