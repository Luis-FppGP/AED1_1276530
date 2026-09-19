/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Luis Felippe Guimaraes Pinheiro
Linguagem   : C
Problema    : 
Data        : 18/09/2026
Objetivo    : dizer se uma matriz 9x9 forma um sistema de sudoku.
Dificuldade : fazer a analise das matrizes 3x3 de cada instancia. Depois de um tempo, e possivel ver uma forma mais facil
              mas eu tenho um serio problema de ser preguicoso e tentar sofrer usando o mesmo codigo do que mudar fazer tudo de novo
              desde o comeco. Gastei um tempo quebrando a cabeça, no final joguei pra IA e tentei codar o que ela me recomendou.              
Uso de IA   : Eu tive um problema porque estava colocando a separacao do vetor como nos slides, e assim a memoria da matriz nao era contigua
              isso causava um erro na funcao que eu nao sabia como resolver, entao usei o claude para me explicar melhor as diferencas
              sintaticas da alocacao de memoria dinamica.
-------------------------------------------------------------------------- */
 
 //O programa primeiro varre o vetor N, com instancias n que representam a grade do sudoku de 81 valores para cada instancia
 //Em cada loop, passa por uma instancia, e ativa a funcao Sudoku, que faz a verificacao das linhas e colunas
 //Para essa verificacao, ele cria dois loops para a varredura de todas as casas. Na funcao sudoku, ele usa uma flag para, quando tiver
 //um valor repetido, ele use o valor na matriz para ver se aquele valor ja ocorreu no loop, ao tornar true o valor da flag 
 //A cada novo loop, a flag volta a ser zero, e ele le um novo indice de linha e coluna para a flag.
 //Dentro da sudoku também tem a chamada da bloco que faz as matrizes 3x3 dentro do instancia
 //Na sudoku eu coloquei 2 loops pra bloco, o bi e bj recebem 3 em cada novo loop quando sao repassados pra funcao bloco porque assim
 //voltam pras coordenadas de inicio de cada matriz no plano, eu quase fiz isso na mao, e to com odio desse problema
 //1) Fora do bloco: entrei no loop no ponto zero; 2)Dentro do bloco: novo check, entro no outro loop de dentro do Bloco
 //3)linha vai de 0 a 2 e passa pelos 3 pontos do indice somanto
 //4)check repete como nas linhas e coluna do sudoku
 //5)Nao limpo o check porque estou no mesmo bloquinho, se for repetido, retorno true que ele ativa o if e manda zero, e ativa o false na main
 //baita trava lingua
 //Meio que e isso, ele faz esses loops, checa linhas, colunas e o cubo, da um no setar os flags mas foi, e se nao der falso, a matriz 
 //e um sudoku, e coloca SIM.


#include <stdio.h>
#include <stdlib.h>

int Bloco(int N[9][9], int bi, int bj)
{
    int check[10] = {0};
    for(int k = bi; k < bi + 3; k++)
      for(int l = bj; l < bj + 3; l++){
        if(check[N[k][l]]) return 1; // repetido no 3x3
        check[N[k][l]] = 1;
      }
    return 0;
}

int Sudoku(int N[9][9])
{
    //linhas e colunas
    for(int k = 0; k < 9; k++)
    {
      int checkLinha[10] = {0};
      int checkColuna[10] = {0};
      for(int j = 0; j < 9; j++)
      {
        if(checkLinha[N[k][j]]) return 0; // repetido na linha
        checkLinha[N[k][j]] = 1;
        
        if(checkColuna[N[j][k]]) return 0; // repetido na coluna
        checkColuna[N[j][k]] = 1;
      }
    }
    
    // Loop pra cada bloco 3x3
    for(int bi = 0; bi < 9; bi += 3)
      for(int bj = 0; bj < 9; bj += 3)
        if(Bloco(N, bi, bj)) return 0;
    
    return 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
      
      int (*N)[9] = malloc(9 * sizeof(int[9]));
      
      for(int k = 0; k < 9; k++)
        for(int j = 0; j < 9; j++)
          scanf("%d", &N[k][j]);
    
    printf("Instancia %d\n", i + 1);
    if(Sudoku(N)) printf("SIM\n");
      else printf("NAO\n");
    printf("\n");
    
    free(N);
    }
    
    return 0;
}
