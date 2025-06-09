#include <stdio.h>
struct Produto {
    char nome[30];
    float preco;
};

int main() {
    struct Produto produtos[3];
    struct Produto *ptr = produtos;

    printf("Digite o nome do produto 1: \n");
    scanf("%s", ptr->nome);
    printf("Digite o preco do produto 1: \n");
    scanf("%f", &ptr->preco);

    ptr++;

    printf("Digite o nome do produto 2: \n");
    scanf("%s", ptr->nome);
    printf("Digite o preco do produto 2: \n");
    scanf("%f", &ptr->preco);

    ptr++;

    printf("Digite o nome do produto 3: \n");
    scanf("%s", ptr->nome);
    printf("Digite o preco do produto 3: \n");
    scanf("%f", &ptr->preco);

    printf("\nProdutos cadastrados:\n");
    for (int i = 0; i < 3; i++) {
        printf("Produto %d: Nome: %s, Preco: %.2f\n", i + 1, produtos[i].nome, produtos[i].preco);
    }
}
