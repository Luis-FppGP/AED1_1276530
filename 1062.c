/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Luis Felippe Guimaraes Pinheiro
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 23/11/2026
Objetivo    : Ver se, dado um vetor ordenado de forma crescente, podemos empilhá-lo e desempilhá-lo em dada ordem.
Dificuldade : Entender o que o enunciado queria dizer, e como implementar de forma simples.
Uso de IA   : O enunciado parecia mal escrito, entao usei IA para entender o que ele queria dizer. Apos
              pensei em resolver de forma similar ao balanco de parentes, empilhando e desempilhando comparando valores,
              mas ainda estava dando erro, no final pedi para o claude consertar, e ele estava com problema no "No" porque estava esperando
              outra flag de parada da pilha pra indicar que nao dava para desempilhar. Passei odio nesse, e acabei usando algumas partes do da IA mesmo
              como o comando "?" para verdadeiro ou falso ja que ela mexeu demais no original e eu estava cansado demais pra querer trocar a essa altura.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} NO;

void push(int v, NO **topo) {
    NO *novo = malloc(sizeof(NO));
    novo->valor = v;
    novo->prox = *topo;
    *topo = novo;
}

void pop(NO **topo) {
    NO *p = *topo;
    *topo = p->prox;
    free(p);
}

int simula(int a[], int n) {
    NO *topo = NULL;
    int prox = 1, ok = 1;

    for (int i = 0; i < n && ok; i++) {

        while (prox <= n && (topo == NULL || topo->valor != a[i]))
            push(prox++, &topo);

        if (topo != NULL && topo->valor == a[i]) pop(&topo);   
        else ok = 0;                                            
    }

    while (topo != NULL) pop(&topo);  
    return ok;
}

int main() {
    int n, a[1000];

    while (scanf("%d", &n) == 1 && n != 0) {
        while (1) {
            int x;
            scanf("%d", &x);
            if (x == 0) break;          

            a[0] = x;
            for (int i = 1; i < n; i++)
                scanf("%d", &a[i]);

            printf(simula(a, n) ? "Yes\n" : "No\n");
        }
        printf("\n");                   
    }
    return 0;
}
