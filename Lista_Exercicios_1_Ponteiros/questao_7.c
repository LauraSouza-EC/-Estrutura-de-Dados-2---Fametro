#include<stdio.h>

void inverterString(char *str) {
  //Declaração de ponteiros para a string indicando o começo e
  //o fim, ambos recebem o valor da string
  char *comeco = str;
  char *fim = str; 
  //Leitura de cada caracter até '\0',voltando ao último
  //caracter necessário para a inversão correta da string
  while(*fim!='\0'){
    fim++;
  }
  //Volta ao último caracter necessário
  fim--;
  while (comeco<fim){
    //A variável temp recebe o valor apontado por '*comeco'
    char temp =*comeco;
    //O ponteiro '*comeco' recebe o valor apontado por '*fim'
    *comeco=*fim;
    //'*fim' recebe o valor de temp
    *fim=temp;
    //Em 'comeco'a leitura segue a ordem original da string
    //e 'fim' o inverso, assim invertendo os caracter da ponta até
    //chegar ao centro
    comeco++;
    fim--;
  }
}

int main(){
    char palavra[100];

    printf("Digite uma palavra: \n");
    scanf("%s",palavra);

    inverterString(palavra);

    printf("String invertida: %s\n",palavra);
    return 0;
}