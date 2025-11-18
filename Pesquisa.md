## HOJE : CONCEITOS, FUNCIONAMENTO, EXEMPLOS, OPERAÇÕES {5 QUESTÕES SOBRE CADA ASSUNTO}
<TABELA HASH>

- CONCEITOS: Tabela Hash é uma estrutura de dados que associa chaves a valores de forma extremamente rápida, utiliza uma função hash (é um algoritmo que transforma uma entrada de dados de qualquer tamanho em uma saída de comprimento fixo, chamada de valor hash ou resumo hash. Essa saída é uma sequência de caracteres alfanuméricos, única para cada entrada, e usada principalmente para verificar a integridade de arquivos e garantir a segurança digital) para transformar a chave (string, número etc.) em um índice da tabela. Objetivo principal é buscar, inserir e remover dados em tempo eficiente, geralmente O(1) médio.
    Pode usar tratamento de colisões, porque diferentes chaves podem gerar o mesmo índice, soluções comuns se houver colisão:
        -> encadeamento (Chaining): inserir na lista, é um método para resolver colisões, onde cada "slot" da tabela contém uma lista encadeada para armazenar todos os pares chave-valor que mapeiam para o mesmo índice. vetor de listas encadeadas, perde performance.
        -> endereçamento aberto (Open Addressing): procurar nova posição. Quando uma colisão ocorre (duas chaves mapeiam para o mesmo índice), o algoritmo sonda a tabela procurando por outra posição vazia usando métodos como a sondagem linear (verificando slots sequenciais) ou sondagem quadrática (eleva o índice ao quadrado, espaçamento melhor). Hash duplo

- FUNCIONAMENTO: Ao fazer uma entrada de dado, é atribuído um "identificador" a ela por meio da função hash, que funciona como um índice de uma tabela onde essa entrada será armazenada, com ele é possível realizar buscas, também fazer inserções e remoções de dados de modo mais ágil.

- EXEMPLOS:
## DE USO ##
    Armazenar nomes e telefones em uma lista de contatos; ligar RA de alunos às suas notas; criar um dicionário que relaciona palavras às definições; montar uma tabela de preços, associando produtos aos valores; ou gerenciar usuários e senhas em sistemas de login.
## DE CÓDIGO ##
#include <stdio.h>
#include <string.h>

#define TAM 10   // tamanho da tabela

// Estrutura para guardar um par chave-valor
typedef struct {
    char chave[30];
    char valor[30];
} Item;

// Tabela hash (vetor de itens)
Item tabela[TAM];

// Função hash simples: soma dos caracteres da chave
int hash(char *chave) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++)
        soma += chave[i];
    return soma % TAM;
}

// Inserção simples (sem tratamento de colisão)
void inserir(char *chave, char *valor) {
    int idx = hash(chave);
    strcpy(tabela[idx].chave, chave);
    strcpy(tabela[idx].valor, valor);
}

// Busca
char* buscar(char *chave) {
    int idx = hash(chave);
    if (strcmp(tabela[idx].chave, chave) == 0)
        return tabela[idx].valor;
    return NULL;
}

int main() {
    // Inicializa tabela vazia
    for (int i = 0; i < TAM; i++) {
        tabela[i].chave[0] = '\0'; // marca como vazio
    }

    inserir("Ana", "1111");
    inserir("Joao", "2222");

    printf("Valor associado a 'Ana': %s\n", buscar("Ana"));
    printf("Valor associado a 'Joao': %s\n", buscar("Joao"));

    return 0;
}
- OPERAÇÕES: Inserir - Calcular índice com função hash, depois coloca-se o par (chave, valor) na posição; Remover - Calcular índice, encontrar o elemento, remover da lista ou marcar como apagado (no caso de endereçamento aberto); Buscar - Com o índice procurar a chave na posição. Se houver colisões, percorrer lista/posições até encontrar ou concluir que não existe.

- QUESTÕES:
1)
2)
3)
4)
5)
<ARVORES BINARIA DE PESQUISA (Binary Search Trees – BST)>
uma arvore grafao não direcionado, conexo e aciclico, estrutura recursiva(sub-árvores)
raiz ponto de origem
nó/vértice tem um ou mais filhos
folha/nó terminal não tem filho
nível ditância entre o nó e a raiz
altura é o maior nível (profundidade, total de níveis)

- CONCEITOS: Árvore binária é uma estrutura de dados em forma de árvore onde cada nó tem até dois filhos (esquerda e direita), todos os valores menores que o valor de um nó ficam no subárvore esquerda, todos os valores maiores ficam no subárvore direita, esse arranjo possibilita buscas rápidas, geralmente O(log n) em árvores balanceadas, é usada para organizar, inserir e buscar dados de forma eficiente.

- EXEMPLOS:
## DE USO ##
Uma árvore binária de pesquisa pode ser usada, por exemplo, para armazenar números de forma organizada. Suponha que inserimos os valores 8, 3, 10, 1 e 6. A árvore coloca os valores menores que um nó à esquerda e os maiores à direita, formando uma estrutura que permite buscar rapidamente qualquer número. Por exemplo, para encontrar o 6, o programa compara com a raiz (8), vai para a esquerda (3) e depois para a direita, chegando ao valor buscado de forma eficiente.
## DE CÓDIGO ##
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

// Cria um novo nó
No* novo_no(int valor) {
    No *n = (No*) malloc(sizeof(No));
    n->valor = valor;
    n->esq = n->dir = NULL;
    return n;
}

// Insere um valor na árvore
No* inserir(No *raiz, int valor) {
    if (raiz == NULL) 
        return novo_no(valor);

    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else if (valor > raiz->valor)
        raiz->dir = inserir(raiz->dir, valor);

    return raiz;
}

// Busca um valor na árvore
No* buscar(No *raiz, int valor) {
    if (raiz == NULL || raiz->valor == valor)
        return raiz;

    if (valor < raiz->valor)
        return buscar(raiz->esq, valor);
    else
        return buscar(raiz->dir, valor);
}

int main() {
    No *raiz = NULL;

    raiz = inserir(raiz, 8);
    raiz = inserir(raiz, 3);
    raiz = inserir(raiz, 10);
    raiz = inserir(raiz, 1);
    raiz = inserir(raiz, 6);

    if (buscar(raiz, 6))
        printf("6 encontrado!\n");
    else
        printf("6 nao encontrado.\n");

    return 0;
}

- OPERAÇÕES: Inserir - Começa pela raiz, compara e se menor vai para esquerda, ou se maior, para a direita, percorre a árvore comparando valores até achar o local correto; Remover - três casos possíveis ,primeiro, nó folha (sem filhos) → remove direto, segundo,nó com um filho → liga o pai ao filho, terceiro,nó com dois filhos → substitui pelo menor da subárvore direita ou maior da esquerda.; Buscar - segue o caminho esquerda/direita com base na comparação do valor procurado.

A árvore também pode ser percorrida de maneiras diferentes, dependendo do objetivo:

✔ Em ordem (in-order)

Esquerda → Raiz → Direita
→ retorna os elementos ordenados

✔ Pré-ordem (pre-order)

Raiz → Esquerda → Direita
→ ideal para copiar a árvore ou exibi-la

✔ Pós-ordem (post-order)

Esquerda → Direita → Raiz
→ útil para destruir a árvore

- QUESTÕES:
1)
2)
3)
4)
5)

## SEMANA
 <ARVORE AVL>
 <ARVORE B> 
