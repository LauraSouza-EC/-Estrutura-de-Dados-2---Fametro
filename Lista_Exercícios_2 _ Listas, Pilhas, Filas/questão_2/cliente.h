#ifndef CLIENTE_H
#define CLIENTE_H

#include <stdbool.h> //para usar o tipo bool(verdadeiro/falso)

typedef struct Cliente {
    char id[24];
    int qtd;
    struct Cliente *prox;
} Cliente;
//Sentinela para a fila (início e fim)
typedef struct {
    Cliente *ini, *fim;
} Fila;

void inicializar(Fila *f);
void enfileirar(Fila *f, Cliente c);
bool desenfileirar(Fila *f, Cliente *out);
bool vazia(Fila *f);
void limpar(Fila *f);

#endif
