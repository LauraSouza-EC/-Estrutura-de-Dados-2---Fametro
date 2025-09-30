Compilação e execução

Para executá-lo primeiro tem que garantir que os arquivos(main.c, cliente.c e cliente.h) 
estejam na mesma pasta para facilitar e evitar erros de execução

Depois, com o terminal integrado do VS Code aberto
insira:
  gcc main.c cliente.c -o cliente
E em seguida:
  ./cliente
OBS: Digitar comandos em caixa alta.
(ADD, START, REL, EXIT)

----------------------------------------------------------------

Exemplos das operações

- Informe o estoque inicial: Ex(100)

- ADD <nome_do_cliente> <quantidade_ingresso>
  EX: carla 50
      joao 30
      maria 40

- START
  Inicia o atendimento, se a quantidade em estoque for menor que o pedido:
    Cliente maria pediu 40, só temos 20. Aceita? (S/N)
    Se aceitar, conta como cliente atendido. Se não, é contabilizado como cliente não atendido.

- REL (Gera o relatório do atendimento)
  EX: (Cliente aceita a condição) 
      Total vendido: 100
      Clientes atendidos: 3
      Top-3 maiores compras: 50, 30, 20
      Estoque restante: 0
      Não atendidos:
      (nenhum)
      
      (Cliente não aceita a condição) 
      Total vendido: 100
      Clientes atendidos: 2
      Top-3 maiores compras: 50, 30
      Estoque restante: 20
      Não atendidos:
      - maria (40)
- EXIT
  Encerra execução

----------------------------------------------------------------

Complexidade das Operações

inicializar   O(1)
enfileirar    O(1)
desenfileirar O(1)
vazia         O(1)
limpar        O(n)