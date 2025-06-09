#include <stdio.h>
#include <stdlib.h>

struct No{
    int valor;
    struct No *proximo;
};

struct No* removerElemento(struct No *head, int valorRemover){
    if(head == NULL) {
        printf("Lista vazia.\n");
        return NULL; // Lista vazia
    }

    if(head->valor == valorRemover) {
        struct No *temp = head;
        head = head->proximo; // Remove o primeiro nó
        free(temp);
        return head;
    }

    struct No *atual = head;
    struct No *anterior = NULL;

    while(atual != NULL && atual->valor != valorRemover) {
        anterior = atual;
        atual = atual->proximo; // Percorre a lista
    }

    if(atual == NULL) {
        printf("Elemento %d não encontrado na lista.\n", valorRemover);
        return head; // Elemento não encontrado
    }

    anterior->proximo = atual->proximo; // Remove o nó
    free(atual); // Libera a memória do nó removido
    return head; // Retorna o ponteiro para o início da lista
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
    lista = inserirNoFim(lista, 40);
    
    imprimirLista(lista);

    lista = removerElemento(lista, 30);
    imprimirLista(lista);

    lista = removerElemento(lista, 99);

    lista = removerElemento(lista, 10);
    imprimirLista(lista);
    return 0;
}