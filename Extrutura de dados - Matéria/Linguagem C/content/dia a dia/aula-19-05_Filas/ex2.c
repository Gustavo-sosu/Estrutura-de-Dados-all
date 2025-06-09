#include <stdio.h>
#include <stdlib.h>

// Estrutura do paciente
struct Paciente {
    char nome[30];         // Nome do paciente (sem espaços)
    int idade;             // Idade do paciente
    struct Paciente *prox; // Próximo paciente na fila
};

// Inserir paciente na fila correta (prioritária ou comum)
void inserirPaciente(struct Paciente **inicioPrioritaria, struct Paciente **fimPrioritaria,
                     struct Paciente **inicioComum, struct Paciente **fimComum) {
    
    // Aloca memória para novo paciente
    struct Paciente *novo = (struct Paciente*)malloc(sizeof(struct Paciente)); 
    
    printf("Digite o nome do paciente (sem espaços): ");
    scanf("%s", novo->nome); // Lê nome

    printf("Digite a idade do paciente: ");
    scanf("%d", &novo->idade); // Lê idade

    novo->prox = NULL; // Novo paciente ainda não aponta para ninguém

    if (novo->idade >= 60) {
        // Inserir na fila prioritária
        if (*fimPrioritaria == NULL) {
            *inicioPrioritaria = novo;
            *fimPrioritaria = novo;
        } else {
            (*fimPrioritaria)->prox = novo;
            *fimPrioritaria = novo;
        }
        printf("Paciente PRIORITÁRIO inserido.\n");
    } else {
        // Inserir na fila comum
        if (*fimComum == NULL) {
            *inicioComum = novo;
            *fimComum = novo;
        } else {
            (*fimComum)->prox = novo;
            *fimComum = novo;
        }
        printf("Paciente COMUM inserido.\n");
    }
}

// Atender paciente (fila prioritária primeiro)
void atenderPaciente(struct Paciente **inicioPrioritaria, struct Paciente **fimPrioritaria,
                     struct Paciente **inicioComum, struct Paciente **fimComum) {

    struct Paciente *temp;

    if (*inicioPrioritaria != NULL) {
        // Atende da fila prioritária
        temp = *inicioPrioritaria;
        printf("Atendendo (PRIORITÁRIO): %s (idade %d)\n", temp->nome, temp->idade);
        *inicioPrioritaria = temp->prox;

        // Se a fila ficar vazia, atualiza o fim
        if (*inicioPrioritaria == NULL) {
            *fimPrioritaria = NULL;
        }

        free(temp); // Libera a memória
    } else if (*inicioComum != NULL) {
        // Atende da fila comum
        temp = *inicioComum;
        printf("Atendendo (COMUM): %s (idade %d)\n", temp->nome, temp->idade);
        *inicioComum = temp->prox;

        // Se a fila ficar vazia, atualiza o fim
        if (*inicioComum == NULL) {
            *fimComum = NULL;
        }

        free(temp); // Libera a memória
    } else {
        printf("Nenhum paciente na fila.\n");
    }
}

// Mostrar fila (comum ou prioritária)
void mostrarFila(const char *titulo, struct Paciente *inicio) {
    printf("\n%s\n", titulo);

    if (inicio == NULL) {
        printf("(vazia)\n");
        return;
    }

    while (inicio != NULL) {
        printf("- %s (idade %d)\n", inicio->nome, inicio->idade);
        inicio = inicio->prox;
    }
}

// Função principal com menu
int main() {
    // Ponteiros para filas
    struct Paciente *inicioPrioritaria = NULL;
    struct Paciente *fimPrioritaria = NULL;

    struct Paciente *inicioComum = NULL;
    struct Paciente *fimComum = NULL;

    int opcao;

    do {
        // Menu de opções
        printf("\n===== MENU - FILA COM PRIORIDADE (DUAS FILAS) =====\n");
        printf("1. Inserir paciente na fila\n");
        printf("2. Atender próximo paciente\n");
        printf("3. Mostrar fila completa\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirPaciente(&inicioPrioritaria, &fimPrioritaria,
                                &inicioComum, &fimComum);
                break;
            case 2:
                atenderPaciente(&inicioPrioritaria, &fimPrioritaria,
                                &inicioComum, &fimComum);
                break;
            case 3:
                mostrarFila("Fila PRIORITÁRIA:", inicioPrioritaria);
                mostrarFila("Fila COMUM:", inicioComum);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    // Libera todos os pacientes restantes
    while (inicioPrioritaria != NULL || inicioComum != NULL) {
        atenderPaciente(&inicioPrioritaria, &fimPrioritaria,
                        &inicioComum, &fimComum);
    }

    return 0;
}
