#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

int main() {
    Pilha pilha;
    pilha_init(&pilha);

    char comando[16];
    Frame frame;
    // Loop principal para processar comandos
    while (1) {
        printf("> ");
        scanf("%s", comando);
        //Processa os comandos CALL, RET, PEEK, TRACE e EXIT
        if (strcmp(comando, "CALL") == 0) {
            char nomeFunc[48];
            int sp;
            scanf("%s %d", nomeFunc, &sp);
            // Se não conseguir empilhar, exibe erro
            if (!push(&pilha, nomeFunc, sp)) {
                printf("Erro ao empilhar.\n");
            }
        } else if (strcmp(comando, "RET") == 0) {
            if (pop(&pilha, &frame)) {
                printf("Retorno da função %s (SP=%d)\n", frame.func, frame.sp);
            } else {
                printf("Erro: pilha vazia. Nenhuma função para retornar.\n");
            }
        } else if (strcmp(comando, "PEEK") == 0) {
            if (peek(&pilha, &frame)) {
                printf("Topo: %s (SP=%d)\n", frame.func, frame.sp);
            } else {
                printf("Pilha vazia.\n");
            }
        } else if (strcmp(comando, "TRACE") == 0) {
            Frame *atual = pilha.topo;
            int nivel = 0;
            if (!atual) {
                printf("Pilha vazia.\n");
            }
            while (atual) {
                printf("Nível %d: %s (SP=%d)\n", nivel++, atual->func, atual->sp);
                atual = atual->baixo;
            }
        } else if (strcmp(comando, "EXIT") == 0) {
            limpar(&pilha);
            break;
        } else {
            printf("Comando inválido.\n");
        }
    }

    return 0;
}
