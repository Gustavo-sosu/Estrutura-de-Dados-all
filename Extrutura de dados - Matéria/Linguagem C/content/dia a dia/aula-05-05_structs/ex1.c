#include <stdio.h>

// Definição da estrutura 'pessoa'
struct pessoa {
    int idade;      
    float altura;
};

// Criação de um apelido 'Pessoa' para 'struct pessoa'
typedef struct pessoa Pessoa;


int main(){
    // Declaração de uma variável de um tipo pessoa
    Pessoa p;

    // Atribuição dos valores
    p.idade = 5;
    p.altura = 1.65;

    printf("A idade da pessoa é: %d", p.idade);         // Mostrar idade
    printf("\nA altura da pessoa é: %.2f", p.altura);   // Mostrar a altura com 2 casas decimais

    return 0;
}