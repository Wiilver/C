#include <stdio.h>
#include <stdlib.h>

struct A{
    void* a;
    int c;
};

int main(){
    int b = 0;
    void* c;
    struct A a;
    printf("%d", sizeof(a));
    return 0;
}