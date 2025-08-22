#include<stdio.h>
//Função para copiar a string
// O ponteiro 'destino' deve receber o valor(caracteres)
//de 'origem'
    void copiarString(char *origem, char *destino){
        // '\0'indica o fim da string
        while(*origem !='\0'){
            *destino=*origem;
            //avança os ponteiros para o próximo caractere
            origem++;
            destino++;
        }
        //Finaliza a cópia ao chegar no fim da string
        *destino = '\0';
    }
    int main(){
        char origem[100];
        char destino[100];
        printf("Digite uma palavra:\n");
        scanf("%s",origem);
        //Só copia o valor, não altera no endereço de memória
        copiarString(origem,destino);

        printf("String copiada: %s\n",destino);
    return 0;
}