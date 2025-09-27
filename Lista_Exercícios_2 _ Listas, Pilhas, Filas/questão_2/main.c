#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"

#define MAX_NAO_ATENDIDOS 100

int main() {
    Fila fila;
    Cliente cliente, nao_atendidos[MAX_NAO_ATENDIDOS];
    int estoque, total_vendido = 0, atendidos = 0, top3[3] = {0};
    int qtd_nao_atendidos = 0;

    inicializar(&fila);

    printf("Informe o estoque inicial: ");
    scanf("%d", &estoque);
    getchar();

    char comando[16];
    while (1) {
        printf("> ");
        scanf("%s", comando);

        if (strcmp(comando, "ADD") == 0) {
            scanf("%s %d", cliente.id, &cliente.qtd);
            enfileirar(&fila, cliente);
        } else if (strcmp(comando, "START") == 0) {
            while (!vazia(&fila) && estoque > 0) {
                desenfileirar(&fila, &cliente);
                if (cliente.qtd <= estoque) {
                    estoque -= cliente.qtd;
                    total_vendido += cliente.qtd;
                    atendidos++;
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
                } else {
                    printf("Cliente %s pediu %d, só temos %d. Aceita? (S/N): ", cliente.id, cliente.qtd, estoque);
                    char resp;
                    scanf(" %c", &resp);
                    resp = toupper(resp);
                    if (resp == 'S') {
                        total_vendido += estoque;
                        atendidos++;
                        estoque = 0;
                    } else {
                        if (qtd_nao_atendidos < MAX_NAO_ATENDIDOS)
                            nao_atendidos[qtd_nao_atendidos++] = cliente;
                    }
                }
            }
            if (estoque == 0) {
                printf("Estoque esgotado. Fim do processamento.\n");
            }
        } else if (strcmp(comando, "REL") == 0) {
            printf("Total vendido: %d\n", total_vendido);
            printf("Clientes atendidos: %d\n", atendidos);
            printf("Top-3 maiores compras: %d, %d, %d\n", top3[0], top3[1], top3[2]);
            printf("Estoque restante: %d\n", estoque);
            printf("Não atendidos:\n");
            for (int i = 0; i < qtd_nao_atendidos; i++)
                printf("- %s (%d)\n", nao_atendidos[i].id, nao_atendidos[i].qtd);
        } else if (strcmp(comando, "EXIT") == 0) {
            limpar(&fila);
            break;
        } else {
            printf("Comando inválido.\n");
        }
    }

    return 0;
}
