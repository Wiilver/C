#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//Podria hacer que la funcion imprimir formara parte de Arreglo, pero seria raro

//Genericos
struct Arreglo{
    int longitud;
    int tama;
    char tipo;
    void* arreglo;
};

void iniciar(struct Arreglo* arr, int longitud, char tipo){
    (*arr).longitud = longitud;
    (*arr).tipo = tipo;
    switch(tipo){
        case 'I':
            (*arr).tama = sizeof(int);
            break;
        case 'D':
            (*arr).tama = sizeof(double);
            break;
    }
    (*arr).arreglo = calloc(longitud, (*arr).tama);
    assert((*arr).arreglo != NULL);
}


struct ArrInt{
    struct Arreglo propiedades;
    void (*iniciar)(struct ArrInt*, int);
    void (*cambiar)(struct ArrInt*, int, int);
    void (*imprimir)(struct ArrInt*);
};

void intImp(struct ArrInt *arr){
    int* a = (*arr).propiedades.arreglo;
    int i;
    for(i = 0; i < (*arr).propiedades.longitud; i++) printf("El valor numero %d de tu arreglo es igual a : %d\n", i+1, a[i]);
}

void intCam(struct ArrInt* arr, int indice, int valor){
    assert(((*arr).propiedades.longitud > indice)&&(indice > 0));
    int* a = (*arr).propiedades.arreglo;
    a[indice] = valor;
}

void intIni(struct ArrInt* arr, int longitud){
    iniciar(&(*arr).propiedades, longitud, 'I');
    (*arr).imprimir = intImp;
    (*arr).cambiar = intCam;
}


struct ArrDob{
    struct Arreglo propiedades;
    void (*iniciar)(struct ArrDob*, int);
    void (*cambiar)(struct ArrDob*, int, double);
    void (*imprimir)(struct ArrDob*);
};

void dobImp(struct ArrDob*arr){
    double* a = (*arr).propiedades.arreglo;
    int i;
    for(i = 0; i < (*arr).propiedades.longitud; i++) printf("El valor numero %d de tu arreglo es igual a : %lf\n", i+1, a[i]);
}

void dobCam(struct ArrDob* arr, int indice, double valor){
    assert(((*arr).propiedades.longitud > indice)&&(indice > 0));
    double* a = (*arr).propiedades.arreglo;
    a[indice] = valor;
}

void dobIni(struct ArrDob* arr, int longitud){
    iniciar(&(*arr).propiedades, longitud, 'D');
    (*arr).imprimir = dobImp;
    (*arr).cambiar = dobCam;
}


int main(){
    struct ArrInt enteros;
    enteros.iniciar = intIni;
    enteros.iniciar(&enteros, 5);

    struct ArrDob dobles;
    dobles.iniciar = dobIni;
    dobles.iniciar(&dobles, 5);

    dobles.cambiar(&dobles, 0, 2.5);    
    dobles.cambiar(&dobles, 1, 4.5);    
    dobles.cambiar(&dobles, 2, 6.5);    
    dobles.cambiar(&dobles, 3, 8.5);    
    dobles.cambiar(&dobles, 4, 10.5);    

    enteros.cambiar(&enteros, 0, 2);
    enteros.cambiar(&enteros, 1, 4);
    enteros.cambiar(&enteros, 2, 6);
    enteros.cambiar(&enteros, 3, 8);
    enteros.cambiar(&enteros, 4, 10);

    enteros.imprimir(&enteros);
    printf("\n");
    dobles.imprimir(&dobles);

    return 0;
}