# Controle de Estoque com Lista Encadeada

Este projeto implementa um sistema de **controle de estoque** usando uma **lista simplesmente encadeada** em C.  
O programa permite adicionar, remover, atualizar, buscar e listar produtos, além de gerar relatórios.

## Estrutura de Dados

Cada produto é representado por:

```c
typedef struct Produto {
    char codigo[16];
    char nome[64];
    int qtd;
    float preco;
    struct Produto *prox;
} Produto;
```

## Funcionalidades

- **ADD `<cod> "<nome>" <qtd> <preco>`**  
  Adiciona um novo produto ordenado por código.  
  Se já existir, atualiza a quantidade e o preço.

- **UPD `<cod> <delta_qtd>`**  
  Ajusta a quantidade (não permite quantidade negativa).

- **DEL `<cod>`**  
  Remove o produto do estoque.

- **FIND `<cod>`**  
  Busca e exibe os dados do produto.

- **LIST**  
  Lista todos os produtos cadastrados.

- **REL**  
  Mostra:
  - Total de itens distintos
  - Valor total do estoque (Σ qtd * preço)
  - Produto com maior valor imobilizado

- **EXIT**  
  Libera a memória e encerra o programa.

## Exemplo de uso

```
=== Controle de Estoque ===
> ADD P001 "Camiseta Azul" 10 49.90
> ADD P002 "Calca Jeans" 5 99.90
> LIST
[P001] Camiseta Azul | qtd: 10 | preco: 49.90
[P002] Calca Jeans   | qtd: 5  | preco: 99.90
> UPD P001 -3
> FIND P001
[P001] Camiseta Azul | qtd: 7 | preco: 49.90
> REL
Itens distintos: 2
Valor total estoque: 1049.40
Maior valor imobilizado: [P002] Calca Jeans = 499.50
> EXIT
Saindo...
```

## Compilação e Execução

```bash
gcc main.c estoque.c -o estoque
./estoque
```

## Complexidade Big-O

| Operação                       | Complexidade |
|--------------------------------|--------------|
| `inserir_inicio`               | **O(1)**     |
| `inserir_ordenado_por_codigo`  | **O(n)**     |
| `remover_por_codigo`           | **O(n)**     |
| `ajustar_quantidade`           | **O(n)**     |
| `buscar`                       | **O(n)**     |
| `listar`                       | **O(n)**     |
| `limpar`                       | **O(n)**     |
| `relatorio`                    | **O(n)**     |
