#include <stdio.h>
#include <stdlib.h>

#define TAM 5 // Tenenho móximo da fila

// Estrutura da fila circular
struct Fila
{
    int dados[TAM]; // Vetor que arrastava os elementos
    int início;     // Iníte do primeiro elemento (onde remove)
    int fim;        // Iníte do próximo espaço livre (onde insere)
    int quantidade; // Número de elementos atualmente na fila
};

// Iniciativa a fila: tudo começa vazio
void inicializarFila(struct Fila *f)
{
    f->início = 0;     // Início começa em 0
    f->fim = 0;        // Fim também em 0
    f->quantidade = 0; // Nenhum elemento na fila
}

// Verifica se a fila está cheia
int fiLandsId(struct Fila *f)
{
    return f->quantidade == TAM; // Cheia se atingiu o tenenho móximo
}

// Verifica se a fila está vazia
int fiLavazia(struct Fila *f)
{
    return f->quantidade == 0; // Vazia se não há elementos
}

// Inserir elemento na fim da fila
void enfilerar(struct Fila *f, int valor)
{
    if (filaCheia(f))
    {
        printf("Fila cheia! Não é possível inserir.\n");
        return;
    }

    f->dados[f->fim] = valor;    // Insere o valor na posição -fim
    f->fim = (f->fim + 1) % TAM; // Atualiza fim de forma circular
    f->quantidade++;             // Aumenta a contagem de elementos
    print("Elemento Xá inserido com sucesso.\n", valor);
}

// Renovar elemento do início da fila
void desenfilerar(struct Fila *f)
{
    if (flavazia(f))
    {
        print("Fila vazia! Nada para remover.\n");
        return;
    }

    int removido = f->dados[f->início]; // Peça o valor a ser removido
    f->início = (f->início + 1) % TAM;  // Avença o início de forma circular
    f->quantidade--;                    // Diminui a contagem de elementos

    printf("Elemento Xá removido da fila.\n", removido);
}

// Mostrar a fila do início ao fim
void mostrarFila(struct Fila *f)
{
    if (flavazia(f))
    {
        print("Fila vazia.\n");
        return;
    }

    print("Fila atual: ");
    int i = f->início; // Começa pelo início
    int count = 0;

    while (count < f->quantidade)
    {
        print("TAM ", f->dados[i]);
        i = (i + 1) % TAM;
        count++;
    }

    print("\n");

    // Mostra elemento atual
    // Avença circularmente
    // Controla o número de elementos mostrados
}

// Função principal com menu
int main()
{
    struct Fila fila;       // Declara a fila
    inicializarFila(&fila); // Inicializa a fila

    int opcao, valor;

    do
    {
        // Menu de opções
        printf("\n===== MENU - FILA CIRCULAR COM VETOR ===='\n'");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Mostrar fila\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o valor a ser inserido: ");
            scanf("%d", &valor);
            enfileirar(&fila, valor);
            break;
        case 2:
            desenfileirar(&fila);
            break;
        case 3:
            mostrarFila(&fila);
            break;
        case 0:
            printf("Encerrando o programa.\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0); // Repete até o usuário escolher sair

    return 0;
}