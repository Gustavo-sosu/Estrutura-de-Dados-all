#include <stdio.h>
#include <stdlib.h>

struct No{
    int valor;
    struct No *proximo;
};

struct No* buscarElemento(struct No *head, int valorBuscar){
    struct No *atual = head;
    while(atual != NULL) {
        if(atual->valor == valorBuscar) {
            return atual; // Retorna o nó encontrado
        }
        atual = atual->proximo; // Percorre a lista
    }
    return NULL; // Retorna NULL se o elemento não for encontrado
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

struct No* inserirNoFim(struct No *head, int novoValor){
    struct No *novoNo = (struct No*)malloc(sizeof(struct No));
    
    novoNo->valor = novoValor;
    novoNo->proximo = NULL;

    if (head == NULL) {
        return novoNo; // Se a lista estiver vazia, o novo nó é o primeiro
    }

    struct No *atual = head;
    while (atual->proximo != NULL) {
        atual = atual->proximo; // Percorre a lista até o último nó
    }

    atual->proximo = novoNo; // Adiciona o novo nó ao final da lista

    return head; // Retorna o ponteiro para o início da lista
}

int main(){
    struct No *lista = NULL;

    lista = inserirNoFim(lista, 10);
    lista = inserirNoFim(lista, 20);
    lista = inserirNoFim(lista, 30);

    imprimirLista(lista);

    struct No *resultado = buscarElemento(lista, 20);
    if(resultado != NULL) {
        printf("Elemento %d encontrado na lista.\n", resultado->valor);
    } else {
        printf("Elemento não encontrado na lista.\n");
    }

    resultado = buscarElemento(lista, 99);
    if(resultado != NULL) {
        printf("Elemento %d encontrado na lista.\n", resultado->valor);
    } else {
        printf("Elemento não encontrado na lista.\n");
    }

    return 0;
}