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