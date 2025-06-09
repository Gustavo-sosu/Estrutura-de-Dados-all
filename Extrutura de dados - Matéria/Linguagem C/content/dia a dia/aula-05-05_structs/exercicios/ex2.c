struct Pessoa {
    int idade;
    float altura;
};

int main(){
    struct Pessoa *p = (struct Pessoa *)malloc(sizeof(struct Pessoa)); // O que falta

    p->idade = 20;
    p->altura = 1.75;
}