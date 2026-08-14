#include <stdio.h>
#include <stdlib.h>

//Para errores

int checarNulo(void* ptr){
    return (ptr==NULL);
}

int checarIndice(int indice, int longitud){
    return ((indice >= longitud)||indice < 0);
}

//Estan mal los punteros
struct Arreglo{
    int longitud;
    void *arreglo;
    int (*iniciar)(void*, int);
    int (*imprimir)(void*, int, int);
};

//Enteros
int intIni(void* arr, int longitud){
    arr = calloc(longitud, sizeof(int));
    return checarNulo(arr);
}

int intImp(void* arr, int indice, int longitud){
    if(checarIndice(indice, longitud)) return 1;
    int *p = arr;
    printf("El valor %d de tu arreglo es igual a : %d\n", indice, p[indice]);
    return 0;
}

//Dobles
int dobIni(void* arr, int longitud){
    arr = calloc(longitud, sizeof(double));
    return checarNulo(arr);
}

int dobImp(void* arr, int indice, int longitud){
    if(checarIndice(indice, longitud)) return 1;
    double *p = arr;
    printf("El valor %d de tu arreglo es igual a : %lf\n", indice, p[indice]);
    return 0;
}

int main(){
    struct Arreglo enteros;    
    struct Arreglo dobles;    

    enteros.longitud = 5;
    dobles.longitud = 5;

    enteros.iniciar = intIni;
    enteros.imprimir = intImp;
    
    dobles.iniciar = dobIni;
    dobles.imprimir = dobImp;

    enteros.iniciar(&enteros.arreglo, enteros.longitud);
    dobles.iniciar(&dobles.arreglo, dobles.longitud);

    enteros.imprimir(&enteros.arreglo, 0, enteros.longitud);
    dobles.imprimir(&dobles.arreglo, 0, dobles.longitud);


    return 0;
}