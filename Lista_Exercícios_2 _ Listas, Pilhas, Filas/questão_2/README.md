# Questão 2 — Fila para Venda Digital de Ingressos

## 📦 Estrutura
- `cliente.h` — definição das estruturas e funções da fila
- `cliente.c` — implementação das operações da fila
- `main.c` — lógica principal da aplicação

## ⚙️ Compilação
```bash
gcc main.c cliente.c -o venda_ingressos
./venda_ingressos

##  EXEMPLOS
Informe o estoque inicial: 100
> ADD joao 30
> ADD maria 50
> ADD pedro 40
> START
Cliente pedro pediu 40, só temos 20. Aceita? (S/N): S
Estoque esgotado. Fim do processamento.
> REL
Total vendido: 100
Clientes atendidos: 3
Top-3 maiores compras: 50, 30, 20
Estoque restante: 0
Não atendidos:
(nenhum)
> EXIT

Complexidade das Operações
inicializar: O(1)

enfileirar: O(1)

desenfileirar: O(1)

vazia: O(1)

limpar: O(n)