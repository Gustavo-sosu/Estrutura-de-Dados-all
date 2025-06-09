#include <stdio.h>
#include <stdlib.h>

struct No{
    int valor;
    struct No *prox;
};

struct No* inserirNoFim(struct No *head, int novoValor){
    struct No *novoNo = (struct No*)malloc(sizeof(struct No));
    
    novoNo->valor = novoValor;
    novoNo->prox = NULL;

    if (head == NULL) {
        return novoNo; // Se a lista estiver vazia, o novo nó é o primeiro
    }

    struct No *atual = head;
    while (atual->prox != NULL) {
        atual = atual->prox; // Percorre a lista até o último nó
    }

    atual->prox = novoNo; // Adiciona o novo nó ao final da lista

    return head; // Retorna o ponteiro para o início da lista


}

void imprimirLista(struct No *head){
    struct No *atual = head;
    printf("Lista: ");
    while(atual != NULL){
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

int main(){
    struct No *lista = NULL;

    lista = inserirNoFim(lista, 10);
    lista = inserirNoFim(lista, 20);
    lista = inserirNoFim(lista, 30);
    
    lista = inserirNoFim(lista, 40);

    imprimirLista(lista);

    return 0;
}   
