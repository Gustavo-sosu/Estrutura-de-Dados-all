#include <stdio.h>
#include <stdlib.h>

#define TAM 5 // Define o tamanho máximo da fila

// Estrutura da fila com vetor
struct Fila {
    int dados[TAM];     // Vetor fixo para armazenar os elementos da fila
    int inicio;         // Índice do início da fila (remove)
    int fim;            // Índice do fim da fila (insere)
};

// Inicializa a fila (coloca início e fim em 0)
void inicializarFila(struct Fila *f) {
    f->inicio = 0; // Começa no início
    f->fim = 0;    // Fim também começa em 0 (fila vazia)
}

// Verifica se a fila está cheia
int filaCheia(struct Fila *f) {
    return f->fim == TAM; // Se o índice de fim atingiu o limite do vetor
}

// Verifica se a fila está vazia
int filaVazia(struct Fila *f) {
    return f->inicio == f->fim; // Se início e fim estão na mesma posição, a fila está vazia
}

// Insere um novo elemento no fim da fila
void enfileirar(struct Fila *f, int valor) {
    if (filaCheia(f)) {
        printf("Fila cheia! Não é possível inserir.\n");
        return;
    }

    f->dados[f->fim] = valor; // Coloca o valor na posição 'fim'
    f->fim++;                 // Avança o ponteiro do fim
    printf("Elemento %d inserido com sucesso.\n", valor);
}

// Remove um elemento do início da fila
void desenfileirar(struct Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia! Nada para remover.\n");
        return;
    }

    int removido = f->dados[f->inicio]; // Pega o valor a ser removido
    f->inicio++;                        // Avança o ponteiro de início
    printf("Elemento %d removido da fila.\n", removido);
}

// Mostra os elementos da fila atual
void mostrarFila(struct Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }

    printf("Fila atual: ");
    for (int i = f->inicio; i < f->fim; i++) {
        printf("%d ", f->dados[i]); // Mostra cada valor entre início e fim
    }

    printf("\n");
}

// Função principal com menu
int main() {
    struct Fila fila; // Declara uma variável do tipo Fila

    inicializarFila(&fila); // Inicializa a fila

    int opcao, valor;

    do {
        // Exibe o menu de opções
        printf("\n===== MENU - FILA COM VETOR =====\n");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Mostrar fila\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao); // Lê a opção escolhida

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);         // Lê o valor a ser inserido
                enfileirar(&fila, valor);    // Chama função de inserção
                break;
            case 2:
                desenfileirar(&fila);        // Chama função de remoção
                break;
            case 3:
                mostrarFila(&fila);          // Chama função de exibição
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao inválida.\n");
        }
    } while (opcao != 0); // Repete até o usuário escolher sair

    return 0;
}
