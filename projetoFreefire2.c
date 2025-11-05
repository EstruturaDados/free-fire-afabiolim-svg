#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10

typedef struct {
    char nome[30];
    char tipo[15];
    int quantidade;
} Item;
// funçao
int main() {
    Item mochila[MAX_ITENS];
    int total = 0;
    int opcao;

    do {
        printf("\n=========CODIGO DA ILHA - NIVEL AVENTUREIRO ==========\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item por nome\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

         switch (opcao) {
            case 1:
                if (total < MAX_ITENS) {
                    printf("Nome do item: ");
                    fgets(mochila[total].nome, 30, stdin);
                    mochila[total].nome[strcspn(mochila[total].nome, "\n")] = '\0';

                    printf("Tipo do item: ");
                    fgets(mochila[total].tipo, 20, stdin);
                    mochila[total].tipo[strcspn(mochila[total].tipo, "\n")] = '\0';

                    printf("Quantidade: ");
                    scanf("%d", &mochila[total].quantidade);
                    getchar();

                    total++;
                    printf(" Item adicionado!\n");
                } else {
                    printf(" Mochila cheia!\n");
                }
                break;