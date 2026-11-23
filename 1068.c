/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Luis Felippe Guimaraes Pinheiro
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 22/11/2026
Objetivo    : Mostrar se uma expressao esta com os parentesis ordenados corretamente
Dificuldade : problemas com os ponteiros, tive que relembrar manipulacao de strings, e o enunciado esta escrito errado
Uso de IA   : O judge diz que tem um valor N para o numero de expressoes a ser enviada, mas nao foi o caso, e tambem tive problemas com alocacao de ponteiros,
              pedi que o claude me apontasse onde estava errado e corrigi. 
-------------------------------------------------------------------------- */


#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char valor;
    struct no *prox;
} NO;

void push(char c, NO **topo) {          
    NO *novo = malloc(sizeof(NO));
    novo->valor = c;
    novo->prox = *topo;
    *topo = novo;
}

int pop(NO **topo) {                    
    if (*topo == NULL) return 0;
    NO *p = *topo;
    *topo = p->prox;
    free(p);
    return 1;
}

int main() {
    char s[1100];
    while (fgets(s, sizeof s, stdin)) {
        NO *topo = NULL;
        int ok = 1;
        for (int j = 0; s[j] != '\0' && ok; j++) {
            if (s[j] == '(') push('(', &topo);
            else if (s[j] == ')') ok = pop(&topo);   
        }
        if (ok && topo == NULL) printf("correct\n");
        else printf("incorrect\n");
        while (topo != NULL) pop(&topo);              
    }
    return 0;
}
