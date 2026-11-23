@@ -0,0 +1,51 @@
/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Luis Felippe Guimaraes Pinheiro
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 23/11/2026
Objetivo    : mostrar a distancia percorrida num vetor ordenado
Dificuldade : nenhuma, foi um dos poucos problemas ate agora que eu lidei bem.
Uso de IA   : Eu sempre peco pro claude corrigir de qualquer forma, mas os meus poucos erros foram inicializar
              o atual com o endereco, então percorrido estava errado, e o claude tambem recomendou trocar pra long long  
              pois a distancia podia estourar o tamanho da variavel int.
-------------------------------------------------------------------------- */

  #include <stdio.h>
#include <stdlib.h>

int BuscaBinaria(int endereco[], int n, int entrega) {
    int inicio = -1, fim = n, meio;
    while (inicio < fim - 1) {
        meio = (inicio + fim) / 2;
        if (endereco[meio] < entrega) inicio = meio;
        else fim = meio;
    }
    return fim;                       
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int endereco[n];                  
    for (int i = 0; i < n; i++)
        scanf("%d", &endereco[i]);

    long long percorrido = 0;
    int atual = 0;                    
    int entrega;

    for (int i = 0; i < m; i++) {
        scanf("%d", &entrega);
        int alvo = BuscaBinaria(endereco, n, entrega);   
        percorrido += abs(alvo - atual);
        atual = alvo;                
    }

    printf("%lld\n", percorrido);
    return 0;
}
