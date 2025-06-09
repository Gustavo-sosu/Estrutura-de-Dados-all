#include <stdio.h>

struct aluno {
    char nome[40];
    float nota;
};

int main() {

    struct aluno *aluno = (struct aluno *)malloc(sizeof(struct aluno));



    printf("Digite o nome do aluno: \n");
    scanf("%s", &aluno->nome);

    printf("Digite a nota do aluno: \n");
    scanf("%f", &aluno->nota);
    
    printf("Nome: %s\n", aluno->nome);
    printf("Nota: %f\n", aluno->nota);

    return 0;
}