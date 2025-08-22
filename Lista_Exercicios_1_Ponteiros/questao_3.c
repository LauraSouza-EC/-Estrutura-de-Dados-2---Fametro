#include <stdio.h>

int main() {
// Declaração da variável inteira e do ponteiro
    int numero = 0;          
    int *ponteiro;             
//Leitura do valor para a variável
    printf("Digite um número:\n");
    scanf("%d",&numero);
// Atribuindo ao ponteiro o endereço de memória de 'numero' 
    ponteiro = &numero;        

// Saídas: 1 valor de 'numero'; 2 o endereço de memória da variável 'numero';
// 3 endereço de memória atribuido ao ponteiro; 4 valor apontado pelo ponterio.
    printf("Valor da variável: %d\n", numero);                             //1
    printf("Endereço da variável: %p\n", &numero);                         //2
    printf("Valor do ponteiro (endereço armazenado): %p\n", ponteiro);     //3
    printf("Valor apontado pelo ponteiro: %d\n", *ponteiro);               //4

    return 0;
}