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