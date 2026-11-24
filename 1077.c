/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Luis Felippe Guimaraes Pinheiro
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1077
Data        : 24/11/2026
Objetivo    : Transformar uma expressao escerita em notacao infixa para posfixa
Dificuldade : Tudo. O enunciado e claro e simples, mas pensar em como transformar da infixa para posfixa,
              e como implementar isso num codigo foi uma experiencia pessima.
Uso de IA   : Praticamente tudo. A minha ideia para trabalhar com a notacao posfixa estava errada, embora eu soubesse
              a forma como empilhar, e o meu codigo alem de errado estava uma bagunca. A IA corrigiu o codigo, explicou a logica da
              transicao e criacao da pilha, e trocou boa parte das funcoes e comandos que eu utilizei porque o codigo estava muito
              mal otimizado. 
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <ctype.h>

int prec(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;                       // '(' e qualquer outro caractere
}

int main() {
    char s[400], pilha[400];
    int n;

    fgets(s, sizeof s, stdin);
    sscanf(s, "%d", &n);

    for (int i = 0; i < n && fgets(s, sizeof s, stdin); i++) {
        int t = 0;                  // topo da pilha (quantidade de elementos)

        for (int j = 0; s[j] != '\0'; j++) {
            char c = s[j];

            if (isalnum(c)) {
                putchar(c);                         // operando: direto para a saída
            } else if (c == '(') {
                pilha[t++] = c;
            } else if (c == ')') {
                while (t > 0 && pilha[t-1] != '(')
                    putchar(pilha[--t]);            // esvazia até o '('
                t--;                                // descarta o '('
            } else if (prec(c) > 0) {               // operador
                while (t > 0 && (prec(pilha[t-1]) > prec(c) ||
                      (prec(pilha[t-1]) == prec(c) && c != '^')))
                    putchar(pilha[--t]);            // sai quem tem que vir antes
                pilha[t++] = c;
            }
            // espaços e '\n' caem aqui e são ignorados
        }

        while (t > 0) putchar(pilha[--t]);          // sobras
        putchar('\n');
    }
    return 0;
}
