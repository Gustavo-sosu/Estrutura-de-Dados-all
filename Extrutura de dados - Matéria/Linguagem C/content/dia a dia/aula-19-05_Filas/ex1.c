#include <stdio.h>
#include <stdlib.h>

// Estrutura do paciente
struct Paciente {
    char nome[30];           // Nome do paciente (sem espaços)
    int idade;               // Idade do paciente
    struct Paciente *prox;   // Ponteiro para o próximo paciente na fila
};

// Função para inserir paciente com ou sem prioridade
void enfileirarComPrioridade(struct Paciente **inicio, struct Paciente **fim) {
    // Aloca dinamicamente um novo paciente
    struct Paciente *novo = (struct Paciente*)malloc(sizeof(struct Paciente));

    // Coleta dados do paciente
    printf("Digite o nome do paciente (sem espacos): ");
    scanf("%s", novo->nome);

    printf("Digite a idade do paciente: ");
    scanf("%d", &novo->idade);

    novo->prox = NULL;  // Novo paciente sempre aponta para NULL no início

    // PRIORIDADE: se idade >= 60, insere no início da fila
    if (novo->idade >= 60) {
        // Aponta o novo paciente para o atual início da fila
        novo->prox = *inicio;
        *inicio = novo;

        // Se a fila estava vazia, o fim também deve apontar para esse novo
        if (*fim == NULL) {
            *fim = novo;
        }

        printf("Paciente PRIORITÁRIO inserido no início da fila.\n");
    } else {
        // Paciente comum: insere no fim da fila
        if (*fim == NULL) {
            // Fila vazia: novo será início e fim
            *inicio = novo;
            *fim = novo;
        } else {
            // Adiciona no final
            (*fim)->prox = novo;
            *fim = novo;
        }

        printf("Paciente comum inserido no fim da fila.\n");
    }
}

// Função para atender o próximo paciente (sempre no início da fila)
void atenderPaciente(struct Paciente **inicio, struct Paciente **fim) {
    if (*inicio == NULL) {
        printf("Fila vazia! Nenhum paciente para atender.\n");
        return;
    }

    // Armazena temporariamente o paciente atual
    struct Paciente *temp = *inicio;
    printf("Atendendo: %s (idade %d)\n", temp->nome, temp->idade);

    // Avança para o próximo da fila
    *inicio = temp->prox;

    // Se após o atendimento a fila ficou vazia, atualiza o fim
    if (*inicio == NULL) {
        *fim = NULL;
    }

    // Libera memória do paciente atendido
    free(temp);
}

// Função para mostrar todos os pacientes da fila
void mostrarFila(struct Paciente *inicio) {
    if (inicio == NULL) {
        printf("Fila vazia.\n");
        return;
    }

    printf("\nFila de pacientes (prioritários primeiro):\n");
    while (inicio != NULL) {
        printf("- %s (idade %d)\n", inicio->nome, inicio->idade);
        inicio = inicio->prox;
    }
}

// Função principal com menu de opções
int main() {
    struct Paciente *inicio = NULL;  // Ponteiro para o início da fila
    struct Paciente *fim = NULL;     // Ponteiro para o fim da fila
    int opcao;

    do {
        // Menu principal
        printf("\n===== MENU - FILA COM PRIORIDADE =====\n");
        printf("1. Inserir paciente na fila\n");
        printf("2. Atender próximo paciente\n");
        printf("3. Mostrar fila\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // Executa ação com base na opção escolhida
        if (opcao == 1) {
            enfileirarComPrioridade(&inicio, &fim);
        } else if (opcao == 2) {
            atenderPaciente(&inicio, &fim);
        } else if (opcao == 3) {
            mostrarFila(inicio);
        } else if (opcao == 0) {
            printf("Saindo do programa...\n");
        } else {
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 0);

    // Libera memória restante (caso ainda existam pacientes na fila)
    while (inicio != NULL) {
        atenderPaciente(&inicio, &fim);
    }

    return 0;
}
