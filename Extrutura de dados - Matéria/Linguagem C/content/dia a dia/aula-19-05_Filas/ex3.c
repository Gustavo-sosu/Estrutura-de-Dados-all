#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó da lista
struct No {
    int valor;                  // Valor armazenado
    struct No *anterior;        // Ponteiro para o nó anterior
    struct No *proximo;         // Ponteiro para o próximo nó
};

// Inserir elemento no início da lista
void inserirInicio(struct No **inicio, struct No **fim, int valor) {
    struct No *novo = (struct No *)malloc(sizeof(struct No));
    novo->valor = valor;
    novo->anterior = NULL;
    novo->proximo = *inicio;

    if (*inicio != NULL) {
        (*inicio)->anterior = novo;
    } else {
        *fim = novo; // Se lista vazia, novo é também o fim
    }

    *inicio = novo;
    printf("Inserido %d no início.\n", valor);
}

// Inserir elemento no fim da lista
void inserirFim(struct No **inicio, struct No **fim, int valor) {
    struct No *novo = (struct No *)malloc(sizeof(struct No));
    novo->valor = valor;
    novo->proximo = NULL;
    novo->anterior = *fim;

    if (*fim != NULL) {
        (*fim)->proximo = novo;
    } else {
        *inicio = novo; // Se lista vazia, novo é também o início
    }

    *fim = novo;
    printf("Inserido %d no fim.\n", valor);
}

// Remover elemento do início da lista
void removerInicio(struct No **inicio, struct No **fim) {
    if (*inicio == NULL) {
        printf("Lista vazia. Nada para remover.\n");
        return;
    }

    struct No *temp = *inicio;
    printf("Removendo %d do início.\n", temp->valor);
    *inicio = temp->proximo;

    if (*inicio != NULL) {
        (*inicio)->anterior = NULL;
    } else {
        *fim = NULL; // Lista ficou vazia
    }

    free(temp);
}

// Remove o primeiro nó que contém o valor especificado
void removerPorValor(struct No **inicio, struct No **fim, int valor) {
    // Verifica se a lista está vazia
    if (*inicio == NULL) {
        printf("Lista vazia. Nada para remover.\n");
        return;
    }

    struct No *atual = *inicio; // Ponteiro auxiliar para percorrer a lista

    // Percorre a lista até encontrar o valor ou chegar ao final
    while (atual != NULL && atual->valor != valor) {
        atual = atual->proximo; // Avança para o próximo nó
    }

    // Se percorreu tudo e não encontrou o valor
    if (atual == NULL) {
        printf("Valor %d não encontrado na lista.\n", valor);
        return;
    }

    // Se o nó a ser removido é o único da lista
    if (atual == *inicio && atual == *fim) {
        *inicio = NULL;
        *fim = NULL;
    }
    // Se o nó está no início
    else if (atual == *inicio) {
        *inicio = atual->proximo;               // Atualiza o início
        (*inicio)->anterior = NULL;             // Remove o ponteiro para o antigo primeiro
    }
    // Se o nó está no fim
    else if (atual == *fim) {
        *fim = atual->anterior;                 // Atualiza o fim
        (*fim)->proximo = NULL;                 // Remove o ponteiro para o antigo último
    }
    // Se o nó está no meio
    else {
        atual->anterior->proximo = atual->proximo; // Liga o anterior ao próximo
        atual->proximo->anterior = atual->anterior; // Liga o próximo ao anterior
    }

    printf("Valor %d removido da lista.\n", atual->valor);
    free(atual); // Libera a memória do nó removido
}


// Remover elemento do fim da lista
void removerFim(struct No **inicio, struct No **fim) {
    if (*fim == NULL) {
        printf("Lista vazia. Nada para remover.\n");
        return;
    }

    struct No *temp = *fim;
    printf("Removendo %d do fim.\n", temp->valor);
    *fim = temp->anterior;

    if (*fim != NULL) {
        (*fim)->proximo = NULL;
    } else {
        *inicio = NULL; // Lista ficou vazia
    }

    free(temp);
}

// Mostrar lista do início ao fim
void mostrarInicioAoFim(struct No *inicio) {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Lista do início ao fim: ");
    while (inicio != NULL) {
        printf("%d ", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("\n");
}

// Mostrar lista do fim ao início
void mostrarFimAoInicio(struct No *fim) {
    if (fim == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Lista do fim ao início: ");
    while (fim != NULL) {
        printf("%d ", fim->valor);
        fim = fim->anterior;
    }
    printf("\n");
}

// Função principal com menu
int main() {
    struct No *inicio = NULL;
    struct No *fim = NULL;
    int opcao, valor;

    do {
        printf("\n====== MENU - LISTA DUPLAMENTE ENCADEADA ======\n");
        printf("1. Inserir no início\n");
        printf("2. Inserir no fim\n");
        printf("3. Remover do início\n");
        printf("4. Remover do fim\n");
        printf("5. Mostrar do início ao fim\n");
        printf("6. Mostrar do fim ao início\n");
        printf("7. Remover por valor\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserirInicio(&inicio, &fim, valor);
                break;
            case 2:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                inserirFim(&inicio, &fim, valor);
                break;
            case 3:
                removerInicio(&inicio, &fim);
                break;
            case 4:
                removerFim(&inicio, &fim);
                break;
            case 5:
                mostrarInicioAoFim(inicio);
                break;
            case 6:
                mostrarFimAoInicio(fim);
                break;

            case 7:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                removerPorValor(&inicio, &fim, valor);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    // Libera todos os nós restantes
    while (inicio != NULL) {
        struct No *temp = inicio;
        inicio = inicio->proximo;
        free(temp);
    }

    return 0;
}