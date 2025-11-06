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