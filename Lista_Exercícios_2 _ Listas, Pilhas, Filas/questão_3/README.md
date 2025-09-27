# Questão 3 — Pilha de Processos (versão simplificada)

## 📦 Estrutura
- `pilha.h` — definição das estruturas e funções da pilha
- `pilha.c` — implementação das operações
- `main.c` — lógica principal da aplicação

## ⚙️ Compilação
```bash
gcc main.c pilha.c -o pilha_processos

▶️ Execução
bash
./pilha_processos

🧪 Exemplos
bash
> CALL main 100
> CALL funcA 120
> CALL funcB 140
> TRACE
Nível 0: funcB (SP=140)
Nível 1: funcA (SP=120)
Nível 2: main (SP=100)
> PEEK
Topo: funcB (SP=140)
> RET
Retorno da função funcB (SP=140)
> RET
Retorno da função funcA (SP=120)
> RET
Retorno da função main (SP=100)
> RET
Erro: pilha vazia. Nenhuma função para retornar.
> EXIT

📊 Complexidade das Operações
pilha_init: O(1)

push: O(1)

pop: O(1)

peek: O(1)

vazia: O(1)

limpar: O(n)