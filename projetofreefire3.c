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