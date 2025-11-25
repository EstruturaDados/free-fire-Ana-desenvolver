#include <stdio.h>
#include <string.h>
#define MAX_ITENS 10

// Código da Ilha – Edição Free Fire
// Nível: Novato

// Estrutura que representa um item da mochila
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

int main() {
    Item mochila[MAX_ITENS];
    int total = 0;  // quantidade de itens atualmente na mochila
    int opcao;

    do {
        printf("\n=====  MOCHILA DE SOBREVIVÊNCIA =====\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item pelo nome\n");
        printf("3 - Listar itens\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

 switch(opcao) {

            case 1: // Adicionar item
                if (total >= MAX_ITENS) {
                    printf("A mochila está cheia! Não é possível adicionar mais itens.\n");
                } else {
                    printf("Digite o nome do item: ");
                    scanf("%s", mochila[total].nome);

                    printf("Digite o tipo do item: ");
                    scanf("%s", mochila[total].tipo);

                    printf("Digite a quantidade: ");
                    scanf("%d", &mochila[total].quantidade);

                    total++;
                    printf("Item adicionado com sucesso!\n");
                }
                break;

            case 2: { // Remover item
                if (total == 0) {
                    printf("A mochila está vazia!\n");
                } else {
                    char nomeRemover[30];
                    int encontrado = 0;

                    printf("Digite o nome do item a ser removido: ");
                    scanf("%s", nomeRemover);

                    for (int i = 0; i < total; i++) {
                        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
                            // Sobrescreve o item removido com o último da lista
                            mochila[i] = mochila[total - 1];
                            total--;
                            encontrado = 1;
                            printf("Item removido com sucesso!\n");
                            break;
                        }
                    }

                    if (!encontrado) {
                        printf("Item não encontrado!\n");
                    }
                }
                break;
            }

            case 3: // Listar itens
                if (total == 0) {
                    printf("A mochila está vazia!\n");
                } else {
                    printf("\n===== ITENS CADASTRADOS =====\n");
                    printf("%-20s %-15s %-10s\n", "Nome", "Tipo", "Quantidade");
                    printf("---------------------------------------------\n");

                    for (int i = 0; i < total; i++) {
                        printf("%-20s %-15s %-10d\n",
                               mochila[i].nome,
                               mochila[i].tipo,
                               mochila[i].quantidade);
                    }
                }
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 0);

return 0;
}

