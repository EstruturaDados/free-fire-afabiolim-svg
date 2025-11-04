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

    do
    {
        printf("\n========== 🏝️ CODIGO DA ILHA - NIVEL NOVATO 🏝️ ==========\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpa o buffer

        
    } while (condition);
    
}