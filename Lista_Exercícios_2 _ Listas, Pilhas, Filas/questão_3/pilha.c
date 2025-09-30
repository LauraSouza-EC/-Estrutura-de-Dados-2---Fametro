#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

// Inicializa a pilha, apontando o topo para NULL indicando
// que está vazia
void pilha_init(Pilha *p) {
    p->topo = NULL;
}
// Adiciona um novo frame ao topo da pilha
bool push(Pilha *p, const char *func, int sp) {
    Frame *novo = malloc(sizeof(Frame));
    if (!novo) return false;

    strcpy(novo->func, func);
    novo->sp = sp;
    novo->baixo = p->topo;
    p->topo = novo;
    return true;
}
// Remove o frame do topo da pilha e copia seus dados para 'out'
bool pop(Pilha *p, Frame *out) {
    if (vazia(p)) return false;

    Frame *tmp = p->topo;
    *out = *tmp;
    p->topo = tmp->baixo;
    free(tmp);
    return true;
}
// Copia os dados do frame do topo da pilha para 'out' sem removê-lo
bool peek(Pilha *p, Frame *out) {
    if (vazia(p)) return false;

    *out = *(p->topo);
    return true;
}
// Verifica se a pilha está vazia
bool vazia(Pilha *p) {
    return p->topo == NULL;
}
// Limpa a pilha, removendo todos os frames
void limpar(Pilha *p) {
    Frame tmp;
    while (pop(p, &tmp));
}
