#include <stdio.h> 

void imprimir(float);
void imprimir(int);


int main(){
    int i = 10;
    float j = 10.29;
    imprimir(i);
    return 0; 
}


void imprimir(float i){
    printf("%f\n", i);
}
void imprimir(int i){
    printf("%d\n", i );
}