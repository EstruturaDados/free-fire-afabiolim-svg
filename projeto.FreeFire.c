#include <stdio.h>
#include <string.h>


#define MAX_ITENS 10

// Estrutura da mochila
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Aricipal
int main(){
    Item mochila[MAX_ITENS];
    int total = 0;
    int opcao;

    do {
        printf("\n========== 🏝️ CODIGO DA ILHA - NIVEL NOVATO 🏝️ ==========\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();// limpa o buffer


         switch (opcao) {
            case 1: // Adicionar item
                if (total >= MAX_ITENS) {
                    printf("\n Mochila cheia! Nao e possivel adicionar mais itens.\n");
                } else {
                    printf("\n Adicionando novo item...\n");
                    printf("Nome do item: ");
                    fgets(mochila[total].nome, sizeof(mochila[total].nome), stdin);
                    mochila[total].nome[strcspn(mochila[total].nome, "\n")] = '\0';

                     printf("Tipo do item: ");
                    fgets(mochila[total].tipo, sizeof(mochila[total].tipo), stdin);
                    mochila[total].tipo[strcspn(mochila[total].tipo, "\n")] = '\0';

                    printf("Quantidade: ");
                    scanf("%d", &mochila[total].quantidade);
                    getchar();

                    total++;
                    printf(" Item adicionado com sucesso!\n");
                }
                break;
                 

    
}