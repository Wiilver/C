#include <stdio.h>
#include <stdlib.h>

struct Array{
    int longitud;
    void* arreglo;
    char tipo;
};

int ArrayIni(struct Array* arr, int longitud, char tipo){
    int espacio;
    (*arr).longitud = longitud;
    /* Hay un problema llamado no quiero agregarle letras a esto, pero falta long long, long double */
    switch(tipo){
        case 'I':
            espacio = (longitud * sizeof(int));
            break;
        case 'D':
            espacio = (longitud * sizeof(double));
            break;
        case 'F':
            espacio = (longitud * sizeof(float));
            break;
        case 'L':
            espacio = (longitud * sizeof(long long));
            break;
        case 'S':
            espacio = (longitud * sizeof(short));
            break;
        case 'C':
            espacio = (longitud * sizeof(char));
            break;
        default:
            return 1;
    }
    (*arr).tipo = tipo;
    (*arr).arreglo = calloc(longitud, espacio);
    if((*arr).arreglo == NULL) return 1;
    return 0;
}

void ArrayImp(struct Array* arr){
    int i;
    switch((*arr).tipo){
        case 'I':
            int* pi = (*arr).arreglo;
            for(i = 0; i < (*arr).longitud; i++) printf("El valor numero %d de su arreglo es : %d\n", i+1, pi[i]);
            break;
        case 'D':
            double* pd = (*arr).arreglo;
            for(i = 0; i < (*arr).longitud; i++) printf("El valor numero %d de su arreglo es : %f\n", i+1, pd[i]);
            break;
        case 'F':
            float* pf = (*arr).arreglo;
            for(i = 0; i < (*arr).longitud; i++) printf("El valor numero %d de su arreglo es : %f\n", i+1, pf[i]);
            break;
        case 'L':
            long long* pl = (*arr).arreglo;
            for(i = 0; i < (*arr).longitud; i++) printf("El valor numero %d de su arreglo es : %lld\n", i+1, pl[i]);
            break;
        case 'S':
            short* ps = (*arr).arreglo;
            for(i = 0; i < (*arr).longitud; i++) printf("El valor numero %d de su arreglo es : %hd\n", i+1, ps[i]);
            break;
        case 'C':
            char* pc = (*arr).arreglo;
            for(i = 0; i < (*arr).longitud; i++) printf("El valor numero %d de su arreglo es : %c\n", i+1, pc[i]);
            break;
    }
    printf("\n");
}

void ArrayLLe(struct Array* arr){
    int i;
    switch((*arr).tipo){
        case 'I':
            int* pi = (*arr).arreglo;
            for(i = 0; i < (*arr).longitud; i++) pi[i] = 2147483645;
            break;
        case 'D':
            double* pd = (*arr).arreglo;
            for(i = 0; i < (*arr).longitud; i++) pd[i] = 123.456789123455;
            break;
        case 'F':
            float* pf = (*arr).arreglo;
            for(i = 0; i < (*arr).longitud; i++) pf[i] = 123.456788;
            break;
        case 'L':
            long long* pl = (*arr).arreglo;
            for(i = 0; i < (*arr).longitud; i++) pl[i] = 922337203685477581;
            break;
        case 'S':
            short* ps = (*arr).arreglo;
            for(i = 0; i < (*arr).longitud; i++) ps[i] = 32767;
            break;
        case 'C':
            char* pc = (*arr).arreglo;
            for(i = 0; i < (*arr).longitud; i++) pc[i] = 'A';
            break;
    }
}


int main(){
    struct Array a;
    ArrayIni(&a, 5, 'S');
    ArrayLLe(&a);
    ArrayImp(&a);
    return 0;
}