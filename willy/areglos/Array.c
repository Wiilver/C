#include <stdio.h>
#include <stdlib.h>

struct ArrInt{
    int longitud;
    int* arreglo;
};

struct MatInt{
    int longitud;
    struct ArrInt* matriz;
};


int ArrIntLee(struct ArrInt* arr, int indice){
    return((*arr).arreglo[indice]);
}

void ArrIntIni(struct ArrInt* arr, int longitud){
    (*arr).longitud = longitud;
    (*arr).arreglo = calloc(longitud, longitud * sizeof(int));
}

void ArrIntAsi(struct ArrInt* arr, int indice, int valor){
    (*arr).arreglo[indice] = valor;
}

void ArrIntLle(struct ArrInt* arr){
    int i, resp;
    for(i = 0; i < (*arr).longitud; i++){
        printf("Ingrese el valor que le quiera dar a su arreglo en el indice %d : ", i+1);
        scanf("%d", &resp);
        ArrIntAsi(arr, i, resp);
        printf("\n");
    }
}

void ArrIntRel(struct ArrInt* arr, int valor){
    int i;
    for(int i = 0; i < (*arr).longitud; i++) (*arr).arreglo[i] = valor;
}

void ArrIntImp(struct ArrInt* arr){
    int i;
    for(i = 0; i < (*arr).longitud; i++){
        printf("El valor %d de su arreglo es igual a %d\n", i+1, ArrIntLee(arr, i));
    }
}


void MatIntIni(struct MatInt* mat, int longitud){
    int i;
    struct ArrInt dummy;
    ArrIntIni(&dummy, longitud);
    (*mat).longitud = longitud;
    (*mat).matriz = calloc(longitud, longitud * sizeof(struct MatInt) + longitud * sizeof(dummy.arreglo[0]));

    for(i = 0; i < longitud; i++){
        struct ArrInt temp;
        ArrIntIni(&temp, longitud);
        ArrIntRel(&temp, i);
        (*mat).matriz[i] = temp;
    }
}

void MatIntImp(struct MatInt* mat){
    int i,j;
    for(i = 0; i < (*mat).longitud; i++){
        for(j = 0; j < (*mat).matriz[i].longitud; j++){
            printf(" %d ", (*mat).matriz[i].arreglo[j]);
        }
        printf("\n");
    }
}


int main(){
    struct MatInt a;
    MatIntIni(&a, 5);
    a.matriz[0].arreglo[0] = 8;
    MatIntImp(&a);
    return 0;
}