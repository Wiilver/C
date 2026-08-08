#include <stdio.h>
#include <stdlib.h>

struct ArrInt{
    int longitud;
    int* arreglo;
};


int ArrIntLee(struct ArrInt* arr, int indice){
    return((*arr).arreglo[indice]);
}

int ArrIntIni(struct ArrInt* arr, int longitud){
    (*arr).longitud = longitud;
    (*arr).arreglo = calloc(longitud, longitud * sizeof(int));
    if((*arr).arreglo == NULL) return 1;
    return 0;
}

int ArrIntAsi(struct ArrInt* arr, int indice, int valor){
    if(indice >= (*arr).longitud) return 1;  
    (*arr).arreglo[indice] = valor;
    return 0;
}

void ArrIntLle(struct ArrInt* arr){
    int i, resp;
    for(i = 0; i < (*arr).longitud; i++){
        printf("Ingrese el valor que le quiera dar a su arreglo en el indice %d : ", i+1);
        scanf("%d", &resp);
        ArrIntAsi(arr, i, resp);
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
    printf("\n");
}

void ArrIntRei(struct ArrInt* arr){
    free((*arr).arreglo);
    (*arr).arreglo = NULL;
    (*arr).longitud = 0;
}

int ArrIntEli(struct ArrInt* arr, int indice){
    int i;
    for(int i = indice; i < (*arr).longitud - 1; i++){
        (*arr).arreglo[i] = (*arr).arreglo[i + 1];
    }
    (*arr).arreglo = realloc((*arr).arreglo, (--(*arr).longitud) * sizeof(int));
    if((*arr).arreglo == NULL) return 1;
    return 0;
}

int ArrIntCam(struct ArrInt* arr, int longitud){
    int i;
    if(longitud < 0) return 1;
    if(longitud == (*arr).longitud) return 0;
    if(longitud == 1){
        ArrIntRei(arr);
        return 0;
    }
    (*arr).arreglo = realloc((*arr).arreglo, longitud * sizeof(int));
    if((*arr).arreglo == NULL) return 1;
    if((*arr).longitud > longitud){
        (*arr).longitud = longitud;
        return 0;
    }
    for(i = (*arr).longitud; i < longitud; i++) (*arr).arreglo[i] = 0;
    (*arr).longitud = longitud;
    return 0;
}

void error(char mensaje[]){
    printf("\nHubo un error con el siguiente mensaje : %s\n", mensaje);
}

int main(){
    struct ArrInt a;
    if(ArrIntIni(&a, 5)){
        error("No se pudo iniciar el arreglo correctamente");
        return 1;
    };

    ArrIntLle(&a);
    
    printf("\nSu arreglo mide %d\n", a.longitud);
    ArrIntImp(&a);

    if(ArrIntEli(&a, 2)){
        error("Fallo al tratar de reubicar la memoria");
        return 1;
    };

    printf("\nSu arreglo mide %d\n", a.longitud);
    ArrIntImp(&a);

    if(ArrIntCam(&a, 7)){
        error("Fallo al cambiar el tamaño del arreglo");
        return 1;
    }

    printf("\nSu arreglo mide %d\n", a.longitud);
    ArrIntImp(&a);

    return 0;
}