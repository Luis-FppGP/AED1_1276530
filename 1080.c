/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Luis Felippe Guimaraes Pinheiro
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 24/08/2026
Objetivo    : Mostrar o maior valor de um vetor de 100 inteiros positivos.
Dificuldade : Nenhum, o problema e simples, mas por lguma razão não estava tendo acertos corretor no judge
Uso de IA   : Usei IA porque o judge estava colocando meu problema como errado mesmo apos eu corrigi-lo varias vezes, mas ainda assim 
              nao foi o suficiente
-------------------------------------------------------------------------- */


#include <stdio.h>
 
int main() {
 
    int N[100], indice, maior;
    
    for(int i = 0; i < 100; i++){
        scanf("%d", &N[i]);
        if(i == 0) maior = N[0];
        if(maior < N[i]){
            maior = N[i];
            indice = i;
        }
    }
    
    printf("%d\n%d", maior, indice + 1);
 
    return 0;
}