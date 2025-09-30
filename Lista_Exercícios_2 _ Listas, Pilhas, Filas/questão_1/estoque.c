// DEFINIÇÃO DAS FUNÇÕES PARA MANIPULAR A LISTA ENCADEADA (ESTOQUE)
#include <stdio.h>  //ENTRADA E SAÍDA
#include <stdlib.h> //ALOCAÇÃO DE MEMÓRIA DINÂMICA
#include <string.h> //MANIPULAÇÃO DE STRINGS
#include "estoque.h" //INCLUSÃO DO CABEÇALHO


//Inserir no início da lista e indicar o próximo nó
Produto* inserir_inicio(Produto *L, Produto p) {
    Produto *novo = (Produto*) malloc(sizeof(Produto));
    if (!novo) return L;
    *novo = p;
    novo->prox = L;
    return novo;
}
//Compara o código, se encontrar atualiza a quantidade e o preço
//Se não encontrar, insere o novo produto na posição correta
Produto* inserir_ordenado_por_codigo(Produto *L, Produto p) {
    Produto *atual = L, *anterior = NULL;

    while (atual != NULL && strcmp(atual->codigo, p.codigo) < 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual != NULL && strcmp(atual->codigo, p.codigo) == 0) {
        atual->qtd += p.qtd;
        atual->preco = p.preco;
        return L;
    }
   
    Produto *novo = (Produto*) malloc(sizeof(Produto));
    if (!novo) return L;
    *novo = p;
    novo->prox = atual;

    if (anterior == NULL) {
        return novo;
    } else {
        anterior->prox = novo;
        return L;
    }
}
//Percorre a lista até encontrar o nó correspondente, excluindo-o da lista
//e liberando a memória alocada
Produto* remover_por_codigo(Produto *L, const char *codigo) {
    Produto *atual = L, *anterior = NULL;

    while (atual != NULL && strcmp(atual->codigo, codigo) != 0) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) return L;

    if (anterior == NULL) {
        L = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    return L;
}
//Busca o produto pelo código e ajusta a quantidade
//e garante que quantidade não fique negativa
Produto* ajustar_quantidade(Produto *L, const char *codigo, int delta_qtd) {
    Produto *p = L;
    while (p != NULL && strcmp(p->codigo, codigo) != 0)
        p = p->prox;

    if (p == NULL) return L;

    if (p->qtd + delta_qtd >= 0)
        p->qtd += delta_qtd;

    return L;
}
//Busca o produto pelo código e retorna o ponteiro para o nó
Produto* buscar(Produto *L, const char *codigo) {
    while (L != NULL) {
        if (strcmp(L->codigo, codigo) == 0) return L;
        L = L->prox;
    }
    return NULL;
}
//Percorre a lista e imprime os detalhes de cada produto
void listar(Produto *L) {
    while (L != NULL) {
        printf("[%s] %s | qtd: %d | preco: %.2f\n",
               L->codigo, L->nome, L->qtd, L->preco);
        L = L->prox;
    }
}
//Libera a memória alocada para todos os nós da lista
Produto* limpar(Produto *L) {
    Produto *aux;
    while (L != NULL) {
        aux = L;
        L = L->prox;
        free(aux);
    }
    return NULL;
}
//Mostra total de itens distintos, valor total do estoque e o produto com 
//maior valor imobilizado.
void relatorio(Produto *L) {
    int distintos = 0;
    float valor_total = 0.0, maior_valor = -1.0;
    Produto *mais_caro = NULL;

    while (L != NULL) {
        distintos++;
        valor_total += L->qtd * L->preco;
        if (L->qtd * L->preco > maior_valor) {
            maior_valor = L->qtd * L->preco;
            mais_caro = L;
        }
        L = L->prox;
    }

    printf("Itens distintos: %d\n", distintos);
    printf("Valor total estoque: %.2f\n", valor_total);
    if (mais_caro)
        printf("Maior valor imobilizado: [%s] %s = %.2f\n",
               mais_caro->codigo, mais_caro->nome, maior_valor);
}
