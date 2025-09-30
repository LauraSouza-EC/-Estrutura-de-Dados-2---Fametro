//CABEÇALHO PARA EVITAR INCLUSÕES MÚLTIPLAS 
#ifndef ESTOQUE_H
#define ESTOQUE_H

//STRUCT PARA O PRODUTO
typedef struct Produto {
    char codigo[16];
    char nome[64];
    int qtd;
    float preco;
    struct Produto *prox;
} Produto;

//FUNÇÕES PARA MANIPULÇÃO DA LISTA ENCADEADA (ESTOQUE)
Produto* inserir_inicio(Produto *L, Produto p);
Produto* inserir_ordenado_por_codigo(Produto *L, Produto p);
Produto* remover_por_codigo(Produto *L, const char *codigo);
Produto* ajustar_quantidade(Produto *L, const char *codigo, int delta_qtd);
Produto* buscar(Produto *L, const char *codigo);
void listar(Produto *L);
Produto* limpar(Produto *L);
void relatorio(Produto *L);

#endif
