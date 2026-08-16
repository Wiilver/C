#include <stdio.h>
#include <stdlib.h>

struct Coor{
    int x;
    int y;
};

struct ArrChar{
    void* arreglo;
    int longitud;
};

int charIni(struct ArrChar *arr, int longitud){
    (*arr).longitud = longitud;
    (*arr).arreglo = calloc(longitud, sizeof(char));
    return ((*arr).arreglo == NULL);
}

struct MatChar{
    struct Coor dim;
    struct ArrChar* matriz;
};

void matIni(struct MatChar *mat, int alto, int largo){
    int i, j;
    struct ArrChar dummy;
    charIni(&dummy, largo);
    (*mat).dim.x = largo;
    (*mat).dim.y = alto;
    (*mat).matriz = calloc(alto, sizeof(&dummy) + largo * sizeof(char));
    
    for(i = 0; i < alto; i++){
        struct ArrChar arreglo;
        charIni(&arreglo, largo);
        for(j = 0; j < largo; j++){
            char* temp = arreglo.arreglo;
            temp[j] = ' ';
        }
        (*mat).matriz[i].arreglo = arreglo.arreglo;   
    }
}

void eqiIni(struct MatChar *mat){
    int i, j, mayor;
    for(i = 0; i < (*mat).dim.y; i++){
        for(j = 0; j < (*mat).dim.x; j++){
            char *temp = (*mat).matriz[i].arreglo;
            temp[j] = (((i==j)||((i+j)==(*mat).dim.x)) ? '#' : ' ');
        }
    }
}

void bolIni(struct MatChar *mat){
    int i, j;
    for(i = 0; i < (*mat).dim.y; i++){
        for(j = 0; j < (*mat).dim.x; j++){
            char *temp = (*mat).matriz[i].arreglo;
            temp[j] = (((i==0)||(j==0)||(i==(*mat).dim.y-1)||(j==(*mat).dim.x-1)) ? '#' : ' ');
        }
    }
}

void figIni(struct MatChar *eqi, struct MatChar *bol, int dim){
    matIni(&(*eqi), dim, dim);
    matIni(&(*bol), dim, dim);

    eqiIni(&(*eqi));
    bolIni(&(*bol));
}

//mal
void bufIni(struct MatChar *buf, int fig){
    int i, j;
    matIni(&(*buf), (fig*fig + fig-1), (fig*fig + fig-1));
    for(i = 0; i < (*buf).dim.y; i ++){
        char *temp = (*buf).matriz[i].arreglo; 
        for(j = 0; j < (*buf).dim.x; j ++){
            if(((j+1)%(fig+1)==0)&&(j!=0)) {temp[j] = '|'; break;}
            if(i==(fig)+(i*fig)) {temp[j] = '-'; break;}
            if((i==(fig)+(i*fig))&&(j==(fig)+(i*fig))) {temp[j] = '-'; break;}
        }
    }
}

void matImp(struct MatChar *mat){
    int i, j;
    for(i = 0; i < (*mat).dim.y; i++){
        for(j = 0; j < (*mat).dim.x; j++){
            char *dummy = (*mat).matriz[i].arreglo;
            printf(" %c ", dummy[j]);
        }
        printf("\n");
    }
}


void cambio(struct MatChar *buf, struct MatChar *mat, struct MatChar *bol, struct MatChar *eqi){
    int i, j;
    for(i = 0; i < (*mat).dim.y; i++){
        for(j = 0; j < (*mat).dim.x; j++)
    }
}



int main(){
    struct MatChar m;
    matIni(&m, 3, 3);
    matImp(&m);
    return 0;
}