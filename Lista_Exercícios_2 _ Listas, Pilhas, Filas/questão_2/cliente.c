#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

void inicializar(Fila *f) {
    f->ini = f->fim = NULL;
}

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

bool desenfileirar(Fila *f, Cliente *out) {
    if (vazia(f)) return false;

    Cliente *tmp = f->ini;
    *out = *tmp;

    f->ini = tmp->prox;
    if (!f->ini) f->fim = NULL;

    free(tmp);
    return true;
}

bool vazia(Fila *f) {
    return f->ini == NULL;
}

void limpar(Fila *f) {
    Cliente tmp;
    while (desenfileirar(f, &tmp));
}
