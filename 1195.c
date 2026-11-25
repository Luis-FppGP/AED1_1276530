/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Luis Felippe Guimaraes Pinheiro
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1195
Data        : 24/11/2026
Objetivo    : Imprimir uma arvore em notacao posfixa, infixa e prefixa
Dificuldade : Nenhuma, foi um problema bem gostoso de fazer ate.
Uso de IA   : Para corrigir erros no algoritmo. Eu fiz errado a notacao infixa, o resto do codigo estava certinho.
              O claude tambem adicionou uns comentarios e mexeu na identacao quando mandou a versao corrigida, entao mandei a dele mesmo, mas tenho a minha se quiser.
-------------------------------------------------------------------------- */


#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} No;

No *insere(No *raiz, int chave) {   
    if (raiz == NULL) {
        No *novo = malloc(sizeof(No));
        novo->chave = chave;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    if (chave < raiz->chave) raiz->esq = insere(raiz->esq, chave);
    else raiz->dir = insere(raiz->dir, chave);
    return raiz;
}

int primeiro;                                // controla o espaço entre elementos

void imprime(int v) {
    if (!primeiro) printf(" ");
    printf("%d", v);
    primeiro = 0;
}

void prefixa(No *r) {
    if (r == NULL) return;
    imprime(r->chave);                       // raiz, esquerda, direita
    prefixa(r->esq);
    prefixa(r->dir);
}

void infixa(No *r) {
    if (r == NULL) return;
    infixa(r->esq);                          // esquerda, raiz, direita
    imprime(r->chave);
    infixa(r->dir);
}

void posfixa(No *r) {
    if (r == NULL) return;
    posfixa(r->esq);                         // esquerda, direita, raiz
    posfixa(r->dir);
    imprime(r->chave);
}

void libera(No *r) {
    if (r == NULL) return;
    libera(r->esq);
    libera(r->dir);
    free(r);
}

int main() {
    int c, n, x;
    scanf("%d", &c);

    for (int i = 1; i <= c; i++) {
        scanf("%d", &n);
        No *raiz = NULL;
        for (int j = 0; j < n; j++) {
            scanf("%d", &x);
            raiz = insere(raiz, x);
        }

        printf("Case %d:\n", i);
        printf("Pre.: ");  primeiro = 1; prefixa(raiz);  printf("\n");
        printf("In..: ");  primeiro = 1; infixa(raiz);   printf("\n");
        printf("Post: ");  primeiro = 1; posfixa(raiz);  printf("\n\n");

        libera(raiz);
    }
    return 0;
}
