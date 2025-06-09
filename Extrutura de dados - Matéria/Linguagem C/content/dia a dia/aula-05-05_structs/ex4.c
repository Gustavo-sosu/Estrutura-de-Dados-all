#include <stdio.h>

void dobrar(int *num) {
    *num = *num * 2;
}

int main(){
    int valor = 10;
    printf("Antes da funcção: %d\n", valor);
    dobrar(&valor);
    printf("Depois da funcção: %d\n", valor);
    return 0;
}