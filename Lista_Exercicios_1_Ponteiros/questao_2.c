#include<stdio.h>

void encontrarMaiorMenor(int *array, int tamanho, int *maior, int *menor);

int main(){
    //Declarando variáveis e definindo tamanho do array
    int maior, menor,tamanho;
    printf("Tamanho do vetor: \n");
    scanf("%d",&tamanho);
    
    //Declaração do vetor e leitura dos valores
    int numeros[tamanho];
    printf("Digite os números para o vetor de tamanho %d: \n",tamanho);
     for(int i=0;i<tamanho;i++){
        scanf("%d",&numeros[i]);
     }
    //Chamada da função para encontrar o maior e menor do vtor
    encontrarMaiorMenor(numeros, tamanho, &maior, &menor);
     //Saída do resultado
    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);

    return 0;
}
void encontrarMaiorMenor(int *array, int tamanho, int *maior, int *menor) {
//Os ponteiros apontam para o primeiro elemento do vetor para
//começar a comparação  
    *maior = array[0];
    *menor = array[0];
// 'i=1'para evitar comparar o primeiro elemento novamente
    for (int i = 1; i < tamanho; i++) {
        if (array[i] > *maior) {
            *maior = array[i];
        }
        if (array[i] < *menor) {
            *menor = array[i];
        }
    }
}