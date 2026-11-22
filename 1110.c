/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Luis Felippe Guimaraes Pinheiro
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 22/11/2026
Objetivo    : Montar uma pilha de cartas, que devem ser descartadas de uma maneira especifica, e explicitar as cartas descartadas e a remanescente.
Dificuldade : problemas de implementacao com o uso de ponteiros
Uso de IA   : correcao de erros de alocacao e ponteiros
-------------------------------------------------------------------------- */
#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *prox;
} NO;

typedef struct {
    NO *inicio;
    NO *fim;
} Pilha;

void criar(int n, Pilha *pilha) {
    pilha->inicio = pilha->fim = NULL;
    for (int i = 1; i <= n; i++) {
        NO *novo = malloc(sizeof(NO));
        novo->valor = i;
        novo->prox = NULL;
        if (pilha->inicio == NULL) pilha->inicio = novo;
        else pilha->fim->prox = novo;
        pilha->fim = novo;
    }
    pilha->fim->prox = pilha->inicio;   // fecha o círculo
}

int descarta(Pilha *pilha) {
    int primeiro = 1;
    while (pilha->inicio != pilha->fim) {        // 2 ou mais cartas
        NO *topo = pilha->inicio;
        if (!primeiro) printf(",");
        printf(" %d", topo->valor);              // descarta o topo
        primeiro = 0;

        pilha->inicio = topo->prox;              // remove o topo
        pilha->fim->prox = pilha->inicio;        // mantém circular
        free(topo);

        pilha->fim = pilha->inicio;              // próxima carta vai para a base
        pilha->inicio = pilha->inicio->prox;
    }
    return pilha->inicio->valor;
}

int main() {
    int n;
    Pilha pilha;                                 // não precisa de malloc
    while (scanf("%d", &n) == 1 && n != 0) {
        criar(n, &pilha);
        printf("Discarded cards:");
        int resto = descarta(&pilha);
        printf("\nRemaining card: %d\n", resto);
        free(pilha.inicio);                      // libera a última carta
    }
    return 0;
}
