#include <stdio.h>//entrada e saída padrão
#include <stdlib.h>//alocação dinâmica de memória
#include <string.h>//manipulação de strings
#include "cliente.h"//inclusão do arquivo de cabeçalho

//Inicializa a fila
void inicializar(Fila *f) {
    f->ini = f->fim = NULL;
}
//Funções para manipulação da fila de clientes
//Adiciona um cliente ao final da fila
void enfileirar(Fila *f, Cliente c) {
    Cliente *novo = malloc(sizeof(Cliente));
    if (!novo) return;
    strcpy(novo->id, c.id);
    novo->qtd = c.qtd;
    novo->prox = NULL;

    if (f->fim)
        f->fim->prox = novo;
    else
        f->ini = novo;

    f->fim = novo;
}
//Remove um cliente do início da fila
bool desenfileirar(Fila *f, Cliente *out) {
    if (vazia(f)) return false;

    Cliente *tmp = f->ini;
    *out = *tmp;

    f->ini = tmp->prox;
    if (!f->ini) f->fim = NULL;

    free(tmp);
    return true;
}
//Verifica se a fila está vazia
bool vazia(Fila *f) {
    return f->ini == NULL;
}
//Libera toda a memória alocada para a fila
void limpar(Fila *f) {
    Cliente tmp;
    while (desenfileirar(f, &tmp));
}
