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

   

    
    return 0;
}

// Struct Item:
// Representa um componente com nome, tipo, quantidade e prioridade (1 a 5).
// A prioridade indica a importância do item na montagem do plano de fuga.

// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos itens (nome, tipo ou prioridade).

// Vetor mochila:
// Armazena até 10 itens coletados.
// Variáveis de controle: numItens (quantidade atual), comparacoes (análise de desempenho), ordenadaPorNome (para controle da busca binária).

// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.

// exibirMenu():
// Apresenta o menu principal ao jogador, com destaque para status da ordenação.

// inserirItem():
// Adiciona um novo componente à mochila se houver espaço.
// Solicita nome, tipo, quantidade e prioridade.
// Após inserir, marca a mochila como "não ordenada por nome".

// removerItem():
// Permite remover um componente da mochila pelo nome.
// Se encontrado, reorganiza o vetor para preencher a lacuna.

// listarItens():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.

// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).

// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.
