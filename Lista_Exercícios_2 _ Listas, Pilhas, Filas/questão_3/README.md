Compilação e execução

Para executá-lo primeiro tem que garantir que os arquivos(main.c, pilha.c e pilha.h) 
estejam na mesma pasta para facilitar e evitar erros de execução

Depois, com o terminal integrado do VS Code aberto
insira:
  gcc main.c pilha.c -o pilha
E em seguida:
  ./pilha

OBS: Digitar comandos em caixa alta.
(CALL, TRACE, PEEK, RET, EXIT)

----------------------------------------------------------------

Exemplos das operações

- CALL <nomeFunc> <sp>(empilha novo frame)
  EX: CALL main 100
      CALL funcA 120
      CALL funcB 140

- TRACE (imprime a pilha do topo ao fundo, numerando níveis)
  Nível 0: funcB (SP=140)
  Nível 1: funcA (SP=120)
  Nível 2: main (SP=100)

- PEEK (mostra o frame do topo sem removê-lo)
  Topo: funcB (SP=140)

- RET (desempilha; se vazia, mostrar mensagem de erro amigável.)
  Retorno da função funcB (SP=140)
- RET
  Retorno da função funcA (SP=120)
- RET
  Retorno da função main (SP=100)
- RET
  Erro: pilha vazia. Nenhuma função para retornar.

- EXIT
  Encerra execução
----------------------------------------------------------------

Complexidade das Operações

pilha_init  O(1)
push        O(1)
pop         O(1)
peek        O(1)
vazia       O(1)
limpar      O(n)