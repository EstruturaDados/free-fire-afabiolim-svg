#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITENS 10

typedef struct {
    char nome[30];
    char tipo[15];
    int quantidade;
} Item;

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
        getchar(); // limpa o buffer do teclado

        switch (opcao) {
            case 1:
                if (total < MAX_ITENS) {
                    printf("Nome do item: ");
                    fgets(mochila[total].nome, 30, stdin);
                    mochila[total].nome[strcspn(mochila[total].nome, "\n")] = '\0';

                    printf("Tipo do item: ");
                    fgets(mochila[total].tipo, 15, stdin);
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

            case 2: {
                if (total == 0) {
                    printf(" Mochila vazia!\n");
                } else {
                    char nomeRemover[30];
                    printf("Digite o nome do item para remover: ");
                    fgets(nomeRemover, 30, stdin);
                    nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

                    int encontrado = 0;
                    for (int i = 0; i < total; i++) {
                        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
                            for (int j = i; j < total - 1; j++)
                                mochila[j] = mochila[j + 1];
                            total--;
                            encontrado = 1;
                            printf("Item removido!\n");
                            break;
                        }
                    }
                    if (!encontrado)
                        printf(" Item nao encontrado.\n");
                }
                break;
            }

            case 3:
                if (total == 0) {
                    printf(" Mochila vazia!\n");
                } else {
                    printf("\n========= ITENS NA MOCHILA =========\n");
                    printf("%-20s %-15s %-10s\n", "Nome", "Tipo", "Quantidade");
                    printf("-------------------------------------------\n");
                    for (int i = 0; i < total; i++) {
                        printf("%-20s %-15s %-10d\n",
                               mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
                    }
                }
                break;

            case 4: {
                if (total == 0) {
                    printf(" Mochila vazia!\n");
                } else {
                    char nomeBusca[30];
                    printf("Digite o nome do item para buscar: ");
                    fgets(nomeBusca, 30, stdin);
                    nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

                    int encontrado = 0;
                    for (int i = 0; i < total; i++) {
                        if (strcmp(mochila[i].nome, nomeBusca) == 0) {
                            printf("\n Item encontrado!\n");
                            printf("Nome: %s\n", mochila[i].nome);
                            printf("Tipo: %s\n", mochila[i].tipo);
                            printf("Quantidade: %d\n", mochila[i].quantidade);
                            encontrado = 1;
                            break;
                        }
                    }
                    if (!encontrado)
                        printf(" Item nao encontrado.\n");
                }
                break;
            }

            case 5:
                printf(" Saindo da ilha... Até mais, aventureiro!\n");
                break;

            default:
                printf(" Opcao invalida!\n");
        }

    } while (opcao != 5);

    return 0;
}
