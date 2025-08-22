#include <stdio.h>
#include <math.h>

//Função para realizar as operações(protótipo)
void calcOp(float a,float b,float *soma,float *subt,float *mult,float *div);

int main(){
    float num1,num2;
    float rSoma,rSubt,rMult,rDiv;
    printf("Digite dois números: \n");
    scanf("%f",&num1);
    scanf("%f",&num2);
//'&'indica o endereço de memória das variáveis de respostas
// para armazenar os resultados (rOperaçãoRealizaada)
    calcOp(num1,num2,&rSoma,&rSubt,&rMult,&rDiv);

    printf("Resultados\n");
    printf("Soma: %.2f\n",rSoma);
    printf("Subtração: %.2f\n",rSubt);
    printf("Multiplicação: %.2f\n",rMult);
//Saída condicional para a divisão, evitando
//erro em caso de visão por zero    
    if(num2!=0){
    printf("Divisão: %.2f\n",rDiv);
    }else{
      printf("Divisão: Syntax Error\nNão é possível dividir por zero\n");  
    }
    

    return 0;
}
void calcOp(float a,float b,float *soma,float *subt,float *mult,float *div){
    *soma = a+b;
    *subt = a-b;
    *mult = a*b;
    // Condicional para evitar a divisão por zero
    if(b!=0){
        *div = a/b;
    }else{
        *div=0;
    }
}