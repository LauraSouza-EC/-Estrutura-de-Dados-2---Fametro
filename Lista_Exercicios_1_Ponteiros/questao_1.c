#include <stdio.h>

// Função para trocar os valores das variáveis
void trocarValores(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
} //a variável temp recebe o valor apontado por *a
// *a recebe o valor apontado por *b e *b a variável temp

int main() {
// Declaração das variáveis
    int x, y;
//Leitura dos valores para as variáveis
    printf("Digite dois valores inteiros:\n");
    scanf("%d", &x);
    scanf("%d", &y);
// Chamando a função para troca, indicando o endereço de memória das variáveis
    trocarValores(&x, &y);
// Saída para mostrar a troca
    printf("Valores trocados:\n");
    printf("x = %d, y = %d\n", x, y);
    return 0;
}