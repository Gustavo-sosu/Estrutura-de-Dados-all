#include <stdio.h>
#include <stdlib.h>

struct No{
    int valor;
    struct No *proximo;
};

struct No* InserirNoInicio(struct No *lista, int valor){
    struct No *novo = (struct No*)malloc(sizeof(struct No));
    novo->valor = valor;
    novo->proximo = lista;
    return novo;
}

void imprimirLista(struct No *head){
    struct No *atual = head;
    printf("Lista: ");
    while(atual != NULL){
        printf("%d -> ", atual->valor);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

int main(){
    struct No *lista = NULL;

    lista = InserirNoInicio(lista, 30);
    lista = InserirNoInicio(lista, 20); 
    lista = InserirNoInicio(lista, 10);

    lista = InserirNoInicio(lista, 5);    

    imprimirLista(lista);
    return 0;
}