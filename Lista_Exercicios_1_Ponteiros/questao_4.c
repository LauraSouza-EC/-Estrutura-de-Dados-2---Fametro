#include<stdio.h>

//Função para dobrar o valor da variável
//O valor apontado é multiplicado por dois
    void dobrar(int *a){
        *a=(*a)*2;
    }
int main (){
    int numero;

    //Leitura do valor para a variável
    printf ("Digite um número inteiro: \n");
    scanf("%d",&numero);

    //Chamada da função para dobrar o valor da variável
    //O valor apontado pelo ponteiro é dobrado dentro da função
    //e com o endereço de memória, altera o valor da variável 'numero'
    //na memória.
    dobrar(&numero);

    //Saída do resultado 
    printf ("O dobro do número inteiro: %d \n",numero);
    return 0;
}