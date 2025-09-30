#include <stdio.h>// Entrada e saída padrão
#include <stdlib.h>// Alocação dinâmica de memória
#include <string.h>// Manipulação de strings
#include <ctype.h> // Para usar toupper (converter caractere para maiúsculo)
#include "cliente.h" // Arquivo de cabeçalho com definição de Cliente e Fila

#define MAX_NAO_ATENDIDOS 100 // Definição de número máximo de clientes não atendidos

int main() {
    Fila fila; // Fila de clientes
    Cliente cliente, nao_atendidos[MAX_NAO_ATENDIDOS]; // Cliente atual e lista de não atendidos
    int estoque, total_vendido = 0, atendidos = 0, top3[3] = {0}; // Controle de estoque e estatísticas
    int qtd_nao_atendidos = 0; // Contador de clientes não atendidos

    inicializar(&fila);

    // Solicitação o estoque inicial
    printf("Informe o estoque inicial: ");
    scanf("%d", &estoque);
    getchar(); // Limpa o buffer do teclado

    char comando[16];
    while (1) {
        printf("> ");
        scanf("%s", comando); // 

        // Adiciona cliente à fila
        if (strcmp(comando, "ADD") == 0) {
            scanf("%s %d", cliente.id, &cliente.qtd);
            enfileirar(&fila, cliente);
        }

        // Inicia o atendimento dos clientes
        else if (strcmp(comando, "START") == 0) {
            while (!vazia(&fila) && estoque > 0) { // Enquanto a fila não estiver vazia e estoque maior q 0
                desenfileirar(&fila, &cliente); // Remove cliente da fila

                if (cliente.qtd <= estoque) { // Se há estoque suficiente
                    estoque -= cliente.qtd;
                    total_vendido += cliente.qtd;
                    atendidos++;

                    // Atualiza o top-3 das maiores compras
                    if (cliente.qtd > top3[0]) {
                        top3[2] = top3[1];
                        top3[1] = top3[0];
                        top3[0] = cliente.qtd;
                    } else if (cliente.qtd > top3[1]) {
                        top3[2] = top3[1];
                        top3[1] = cliente.qtd;
                    } else if (cliente.qtd > top3[2]) {
                        top3[2] = cliente.qtd;
                    }
                }

                // Se o estoque for menor que o pedido, perguntar se o cliente aceita o somente
                // o que tem
                else {
                    printf("Cliente %s pediu %d, só temos %d. Aceita? (S/N): ", cliente.id, cliente.qtd, estoque);
                    char resp;
                    scanf(" %c", &resp);
                    resp = toupper(resp); // Converte para maiúsculo

                    if (resp == 'S') { // Cliente aceita o que tem
                        total_vendido += estoque;
                        atendidos++;
                        estoque = 0;
                    } else { // Cliente não aceita, adiciona à lista de não atendidos
                        if (qtd_nao_atendidos < MAX_NAO_ATENDIDOS)
                            nao_atendidos[qtd_nao_atendidos++] = cliente;
                    }
                }
            }

            if (estoque == 0) {
                printf("Estoque esgotado. Fim do processamento.\n");
            }
        }

        else if (strcmp(comando, "REL") == 0) {
            printf("Total vendido: %d\n", total_vendido);
            printf("Clientes atendidos: %d\n", atendidos);
            printf("Top-3 maiores compras: %d, %d, %d\n", top3[0], top3[1], top3[2]);
            printf("Estoque restante: %d\n", estoque);
            printf("Não atendidos:\n");
            for (int i = 0; i < qtd_nao_atendidos; i++)
                printf("- %s (%d)\n", nao_atendidos[i].id, nao_atendidos[i].qtd);
        }

        // Encerra o programa
        else if (strcmp(comando, "EXIT") == 0) {
            limpar(&fila); // Libera memória da fila
            break;
        }else {
            printf("Comando inválido.\n");
        }
    }

    return 0;
}
