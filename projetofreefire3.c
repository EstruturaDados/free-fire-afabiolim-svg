#include <stdio.h>
#include <string.h>
#include <stdbool.h> // para usar bool, true, false

#define MAX_ITENS 10



// representa os criterios de ordenacao.

typedef enum {
    ORDENAR_NOME = 1,
    ORDENAR_TIPO,
    ORDENAR_PRIORIDADE
} CriterioOrdenacao;

// Estrutura que representa cada item da mochila.
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
    int prioridade; // 1 (baixa) a 5 (alta)
} Item;



// Função para imprimir uma linha 
void linha() {
    printf("------------------------------------------------------------\n");
}

// Função que exibe um item (formato amigável).
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

    // Leitura dos campos do item
    printf("Nome do item: ");
    fgets(mochila[*total].nome, sizeof(mochila[*total].nome), stdin);
    mochila[*total].nome[strcspn(mochila[*total].nome, "\n")] = '\0';

    printf("Tipo do item: ");
    fgets(mochila[*total].tipo, sizeof(mochila[*total].tipo), stdin);
    mochila[*total].tipo[strcspn(mochila[*total].tipo, "\n")] = '\0';

    printf("Quantidade: ");
    scanf("%d", &mochila[*total].quantidade);

    // Ler prioridade e garantir que esteja no intervalo 1..5
    do {
        printf("Prioridade (1 a 5): ");
        scanf("%d", &mochila[*total].prioridade);
        if (mochila[*total].prioridade < 1 || mochila[*total].prioridade > 5)
            printf("Prioridade invalida. Digite um valor entre 1 e 5.\n");
    } while (mochila[*total].prioridade < 1 || mochila[*total].prioridade > 5);

    getchar(); // limpar o '\n' restante no buffer após scanf
    (*total)++;
    printf(" Item adicionado com sucesso!\n");
}

// Remove um item pelo nome.
void removerItem(Item mochila[], int *total) {
    if (*total == 0) {
        printf(" Mochila vazia! Nada para remover.\n");
        return;
    }

    char nomeRemover[30];
    printf("Digite o nome do item para remover: ");
    fgets(nomeRemover, sizeof(nomeRemover), stdin);
    nomeRemover[strcspn(nomeRemover, "\n")] = '\0';

    int pos = -1;
    for (int i = 0; i < *total; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        printf(" Item nao encontrado.\n");
        return;
    }

    // Desloca os itens esquerda para "remover" o item
    for (int j = pos; j < *total - 1; j++) {
        mochila[j] = mochila[j + 1];
    }
    (*total)--;
    printf(" Item '%s' removido.\n", nomeRemover);
}

// Lista todos os itens na mochila em formato de tabela simples.
void listarItens(Item mochila[], int total) {
    if (total == 0) {
        printf(" Mochila vazia.\n");
        return;
    }

    printf("\n%-25s %-15s %-10s %-10s\n", "Nome", "Tipo", "Quantidade", "Prioridade");
    linha();
    for (int i = 0; i < total; i++) {
        printf("%-25s %-15s %-10d %-10d\n",
               mochila[i].nome,
               mochila[i].tipo,
               mochila[i].quantidade,
               mochila[i].prioridade);
    }
}



// Função ordena a mochila de acordo com o criterio
int ordenarMochila(Item mochila[], int total, CriterioOrdenacao criterio) {
    int comparacoes = 0;

    // Insertion sort: percorre do segundo elemento até o final
    for (int i = 1; i < total; i++) {
        Item atual = mochila[i]; // elemento que vamos inserir lista ordenada
        int j = i - 1;

        // Enquanto j >= 0 e a condicao de troca for verdadeira, deslocamos
        while (j >= 0) {
            comparacoes++; // contamos cada comparacao 

            bool deveDeslocar = false; // determina se deslocamos mochila

            if (criterio == ORDENAR_NOME) {
                // strcmp > 0 significa mochila[j].nome > atual.nome (lexicograficamente)
                if (strcmp(mochila[j].nome, atual.nome) > 0)
                    deveDeslocar = true;
            } else if (criterio == ORDENAR_TIPO) {
                // ordenar por tipo
                if (strcmp(mochila[j].tipo, atual.tipo) > 0)
                    deveDeslocar = true;
                else if (strcmp(mochila[j].tipo, atual.tipo) == 0) {
                    // Critério secundário: se os tipos forem iguais, ordenar por nome
                    if (strcmp(mochila[j].nome, atual.nome) > 0)
                        deveDeslocar = true;
                }
            } else if (criterio == ORDENAR_PRIORIDADE) {
                // Ordenamos por prioridade crescente (1 -> 5). 
                if (mochila[j].prioridade > atual.prioridade)
                    deveDeslocar = true;
                else if (mochila[j].prioridade == atual.prioridade) {
                    // Critério secundário: se prioridades iguais, ordenar por nome
                    if (strcmp(mochila[j].nome, atual.nome) > 0)
                        deveDeslocar = true;
                }
            }

            if (!deveDeslocar)
                break; // posição correta encontrada

            // desloca o elemento para a direita
            mochila[j + 1] = mochila[j];
            j--;
        }

        mochila[j + 1] = atual; // insere o elemento na posição
    }

    return comparacoes;
}



// Busca binaria o vetor esteja ordenado por nome
int buscaBinariaPorNome(Item mochila[], int total, char nomeBusca[]) {
    int inicio = 0;
    int fim = total - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;
        int cmp = strcmp(mochila[meio].nome, nomeBusca);

        if (cmp == 0) {
            return meio; // encontrado
        } else if (cmp < 0) {
            // mochila[meio].nome < nomeBusca -> procurar à direita
            inicio = meio + 1;
        } else {
            // mochila[meio].nome > nomeBusca -> procurar à esquerda
            fim = meio - 1;
        }
    }

    return -1; // nao encontrado
}

// Função principal

int main() {
    Item mochila[MAX_ITENS];
    int total = 0;
    int opcao;
    bool ordenadoPorNome = false; // Indica se a mochila está ordenada por nome

    do {
        printf("\n========== CODIGO DA ILHA - NIVEL MESTRE ==========\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Ordenar mochila\n");
        printf("5. Buscar item (busca binaria por nome)\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpa o '\n' deixado pelo scanf

        switch (opcao) {
            case 1:
                adicionarItem(mochila, &total);
                ordenadoPorNome = false; 
                break;

            case 2:
                removerItem(mochila, &total);
                ordenadoPorNome = false; // remocao e invalida ordenacao por nome
                break;

            case 3:
                listarItens(mochila, total);
                break;

            case 4: {
                if (total == 0) {
                    printf(" Mochila vazia! Nada a ordenar.\n");
                    break;
                }

                int escolha;
                printf("\nEscolha o criterio de ordenacao:\n");
                printf("1. Nome\n2. Tipo\n3. Prioridade\n");
                printf("Opcao: ");
                scanf("%d", &escolha);
                getchar();

                if (escolha < 1 || escolha > 3) {
                    printf(" Criterio invalido!\n");
                    break;
                }

                // funcao de ordenacao e pega o numero
                int comparacoes = ordenarMochila(mochila, total, (CriterioOrdenacao)escolha);
                printf(" Mochila ordenada com sucesso!\n");
                printf(" Comparacoes realizadas durante a ordenacao: %d\n", comparacoes);

                // atualiza ordenacao por nome
                ordenadoPorNome = (escolha == ORDENAR_NOME);
                break;
            }

            case 5: {
                if (total == 0) {
                    printf(" Mochila vazia! Nada para buscar.\n");
                    break;
                }
                if (!ordenadoPorNome) {
                    printf(" Para usar busca binaria, a mochila deve estar ordenada por NOME.\n");
                    printf("Use a opcao 4 e escolha 'Nome' como criterio.\n");
                    break;
                }

                char nomeBusca[30];
                printf("Digite o nome do item a buscar: ");
                fgets(nomeBusca, sizeof(nomeBusca), stdin);
                nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

                int indice = buscaBinariaPorNome(mochila, total, nomeBusca);
                if (indice != -1) {
                    printf("\n Item encontrado na posicao %d:\n", indice);
                    exibirItem(mochila[indice]);
                } else {
                    printf(" Item nao encontrado.\n");
                }
                break;
            }

            case 6:
                printf(" Saindo. Boa sorte na ilha, Mestre!\n");
                break;

            default:
                printf(" Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 6);

    return 0;
}
