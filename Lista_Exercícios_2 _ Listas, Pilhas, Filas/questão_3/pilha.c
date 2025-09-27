#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void pilha_init(Pilha *p) {
    p->topo = NULL;
}

bool push(Pilha *p, const char *func, int sp) {
    Frame *novo = malloc(sizeof(Frame));
    if (!novo) return false;

    strcpy(novo->func, func);
    novo->sp = sp;
    novo->baixo = p->topo;
    p->topo = novo;
    return true;
}

bool pop(Pilha *p, Frame *out) {
    if (vazia(p)) return false;

    Frame *tmp = p->topo;
    *out = *tmp;
    p->topo = tmp->baixo;
    free(tmp);
    return true;
}

bool peek(Pilha *p, Frame *out) {
    if (vazia(p)) return false;

    *out = *(p->topo);
    return true;
}

bool vazia(Pilha *p) {
    return p->topo == NULL;
}

void limpar(Pilha *p) {
    Frame tmp;
    while (pop(p, &tmp));
}
