#include <stdio.h> //entrada e saída padrão
#include <stdlib.h>//alocação dinâmica de memória
#include <string.h>//manipulação de strings
#include "estoque.h"//inclusão do arquivo de cabeçalho

int main() {
    //Declaração de um ponteiro para o início da lista de produtos e 
    //uma string para armazenar o comando do usuário
    Produto *lista = NULL;
    char comando[16];

    printf("=== Controle de Estoque ===\n");
    printf("Comandos: ADD, UPD, DEL, FIND, LIST, REL, EXIT\n");
    //Loop infinito para processar comandos do usuário
    while (1) {
        printf("> ");
        if (scanf("%s", comando) != 1) break;

        if (strcmp(comando, "ADD") == 0) {
            Produto p;
            scanf("%s \"%[^\"]\" %d %f", p.codigo, p.nome, &p.qtd, &p.preco);
            lista = inserir_ordenado_por_codigo(lista, p);

        } else if (strcmp(comando, "UPD") == 0) {
            char codigo[16];
            int delta;
            scanf("%s %d", codigo, &delta);
            lista = ajustar_quantidade(lista, codigo, delta);

        } else if (strcmp(comando, "DEL") == 0) {
            char codigo[16];
            scanf("%s", codigo);
            lista = remover_por_codigo(lista, codigo);

        } else if (strcmp(comando, "FIND") == 0) {
            char codigo[16];
            scanf("%s", codigo);
            Produto *p = buscar(lista, codigo);
            if (p) {
                printf("[%s] %s | qtd: %d | preco: %.2f\n",
                       p->codigo, p->nome, p->qtd, p->preco);
            } else {
                printf("Produto nao encontrado!\n");
            }

        } else if (strcmp(comando, "LIST") == 0) {
            listar(lista);

        } else if (strcmp(comando, "REL") == 0) {
            relatorio(lista);

        } else if (strcmp(comando, "EXIT") == 0) {
            lista = limpar(lista);
            printf("Saindo...\n");
            break;

        } else {
            printf("Comando invalido!\n");
        }
    }

    return 0;
}
