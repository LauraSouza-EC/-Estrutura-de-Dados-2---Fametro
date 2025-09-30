Compilação e execução

O programa permite adicionar, remover, atualizar, buscar e listar produtos, além de gerar relatórios.

Para executá-lo primeiro tem que garantir que os arquivos(main.c,estoque.c e estoque.h) 
estejam na mesma pasta para facilitar e evitar erros de execução

Depois, com o terminal integrado do VS Code aberto
insira:
  gcc main.c estoque.c -o estoque
E em seguida:
  ./estoque
OBS: Digitar comandos em caixa alta.
(ADD, UPD, DEL, FIND, LIST, REL, EXIT)

----------------------------------------------------------------

Exemplos das operações

- ADD <cod> <"nome do produto"> <quantidade> <preco>
  EX: ADD P001 "Camiseta Azul" 10 49.90

- UPD <cod> <delta_qtd>
  EX: UPD P001 -3

- DEL <cod>
  EX: DEL P001

- FIND <cod>
  EX: FIND P001 
 
- LIST 
  Vai listar os produtos individualmente, exibindo:
  <cod> <"nome do produto"> <quantidade> <preco>

- REL 
  Relatório geral com total de itens distintos, o valor total
  do estoque, e o item com o maior valor imobilizado.

- EXIT
  Encerra a execução do programa
  
----------------------------------------------------------------

Complixidade das operações

inserir_inicio               O(1)     
inserir_ordenado_por_codigo  O(n)     
remover_por_codigo           O(n)     
ajustar_quantidade           O(n)     
buscar                       O(n)     
listar                       O(n)     
limpar                       O(n)     
relatorio                    O(n)    
