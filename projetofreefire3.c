#include <stdio.h>
#include <string.h>
#include <stdbool.h> // usar bool, true, false

#define MAX_ITENS 10

// Ordenação
typedef enum {
    ORDENAR_NOME = 1,
    ORDENAR_TIPO,
    ORDENAR_PRIORIDADE
} CriterioOrdenacao;


//estrutura da mochila
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
    int prioridade; // 1 (baixa) a 5 (alta)
} Item;


// Função que exibe um item
void exibirItem(Item it) {
    printf("Nome: %s\n", it.nome);
    printf("Tipo: %s\n", it.tipo);
    printf("Quantidade: %d\n", it.quantidade);
    printf("Prioridade: %d\n", it.prioridade);
}

// Adiciona um item na mochila 
void adicionarItem(Item mochila[], int *total) {
    if (*total >= MAX_ITENS) {
        printf(" Mochila cheia! Nao e possivel adicionar mais itens.\n");
        return;
    }

    // Leitura dos item
    printf("Nome do item: ");
    fgets(mochila[*total].nome, sizeof(mochila[*total].nome), stdin);
    mochila[*total].nome[strcspn(mochila[*total].nome, "\n")] = '\0';

    printf("Tipo do item: ");
    fgets(mochila[*total].tipo, sizeof(mochila[*total].tipo), stdin);
    mochila[*total].tipo[strcspn(mochila[*total].tipo, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &mochila[*total].quantidade);

    // Ler prioridade 1..5
    do {
        printf("Prioridade (1 a 5): ");
        scanf("%d", &mochila[*total].prioridade);
        if (mochila[*total].prioridade < 1 || mochila[*total].prioridade > 5)
            printf("Prioridade invalida. Digite um valor entre 1 e 5.\n");
    } while (mochila[*total].prioridade < 1 || mochila[*total].prioridade > 5);

    getchar(); // limpar o '\n' restante no buffer após scanf
    (*total)++;
    printf("Item adicionado com sucesso!\n");
}

// Remove um item pelo nome
