#include<stdio.h>
#include <string.h>
void contarVogaisConsoantes(char *str, int *vogais, int *consoantes){
    // Inicialização dos ponteiros para a contagem
    *vogais = 0;
    *consoantes = 0;
    //Leitura da string, '\0' é para indicar o fim dela
    while(*str!='\0'){
        //Variável que recebe o caracter para análise feita na condicional
        char c=*str;
     //Condicional para contagem
     //Definição do intervalo para análise
        if(c>='a'&&c<='z'){
        //Condicional pra contagem de vogais
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'){
                (*vogais)++;
            }else{
                (*consoantes)++;
            }
        }
    //Avança a leitura da string, para o próximo caracter
        str++;
    }
}
int main(){
    char palavra [100];
    int vogal, consoante;

    printf ("Digite uma palavra: \n");
    //lê a string e também os espaços
    fgets(palavra,sizeof(palavra),stdin);
    // Para evitar o \n de ser adicionado a final da sting
    palavra[strcspn(palavra, "\n")] = '\0';
    //Uso de '&'para passar o endereço de memória onde modificará 
    //o conteúdo para a contagem
    contarVogaisConsoantes(palavra,&vogal,&consoante);
    printf("Vogais: %d\n",vogal);
    printf("Consoantes: %d\n",consoante);
    return 0;
}     