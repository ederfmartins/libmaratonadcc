/*
 * Solução do problema 'Altas aventuras' (OBI 2010 - Nível 2, Fase 2)
 *
 * Maurício de Lemos Rodrigues Collares Neto (<mauricioc@gmail.com>)
 */

#include <cstdio>
#include <cstring>
#include <cmath>

long long C[50001][31];

int main()
{
    int n, k, ret = 0;
    scanf("%d %d", &n, &k);

    /*
      Tentemos estabelecer uma fórmula recursiva para o maior valor de
      N tal que T testes e K balões determinam unicamente o máximo que
      podemos encher um. Chamemos esse valor de A[T][K]. Se tentarmos
      estourar um balão no valor x, podem acontecer duas coisas:

      1) Ele pode não estourar. Tesse caso, temos que verificar a
      região [x+1, A[T][K]] tendo T-1 testes e K balões.

      2) Ele pode estourar. Nesse caso, temos que verificar a região
      [1, x-1] tendo T-1 testes e K-1 balões (pois um acabou de ser
      estourado).

      Ora, o maior tamanho da região 1 é dado por A[T-1][K] (note que
      apenas o tamanho da região importa; o valor incial não é
      importante), e o maior tamanho da região 2 é dado por
      A[T-1][K].

      Conclui-se que o maior valor possível de ser testado com T
      testes e K balões é dado por A[T-1][K] + A[T-1][K-1] + 1, pois
      este valor maximiza o tamanho das duas regiões. Note que as duas
      primeiras parcelas correspondem aos tamanhos máximos das regiões
      1 e 2, e a terceira parcela corresponde ao fato de que não
      precisamos mais testar a posição x. Com esse valor, o primeiro
      teste será feito em x = A[T-1][K] + 1.

      Isto já nos dá uma solução usando programação dinâmica,
      suficiente para ganhar 40 pontos. Dado o limite em T, não
      poderemos calcular todos os valores para conseguir 100
      pontos. Um dos jeitos possíveis de contornar isso é resolver a
      recorrência. Para isso, podemos notar que a recorrência é quase
      a recorrência dada pela relação de Stiefel: Binomial[T][K] =
      Binomial[T-1][K] + Binomial[T-1][K-1]. O "+1", atrapalha, no
      entanto, então teremos que remover ele de um jeito ou de outro.

      O primeiro impulso é remover o 1 definindo uma sequência
      auxiliar B[T][K] = A[T][K] - 1, mas isso não funciona, visto que
      a recorrência original possui um termo do lado esquerdo e dois
      do lado direito (escreva a recorrência de B[T][K] para ver o que
      acontece!). Depois de algumas tentativas, podemos pensar em
      subtrair um valor da sequência de outro valor da sequência para
      contornar esse problema. Definindo C[T][K] = A[T][K+1] -
      A[T][K], temos:

      C[T][K] = A[T][K+1] - A[T][K] =
      A[T-1][K+1] + A[T-1][K] + 1 - A[T-1][K] - A[T-1][K-1] - 1 =
      (A[T-1][K+1] - A[T-1][K]) + (A[T-1][K] + A[T-1][K-1]) =
      C[T-1][K] + C[T-1][K-1]

      Sucesso! Esta é exatamente a relação de Stiefel, só precisamos
      conferir os valores iniciais agora. A[0][i] é igual a zero para
      todo i, pois não podemos concluir nada com zero testes;
      portanto, C[0][i] também é igual a zero pra todo i. Mas
      Binomial[0][0] = 1. Temos mais um problema a contornar. Dessa
      vez, vamos tentar roubar um pouco: Binomial[0][0] é, de fato, 1,
      mas Binomial[0][i] é zero se i >= 1. Então tentemos ver se
      C[0][i] = Binomial[0][i+1].

      Ora, é fácil de ver que a mudança no termo da direita não afeta
      a relação de Stiefel, e agora os valores de C[0][i] concordam
      sempre! Segue-se que, de fato, C[T][K] = Binomial[T][K+1] pra
      todo T e todo K não negativos. Mas o que isso implica para
      A[T][K]?

      A[T][K] = (A[T][K] - A[T][K-1]) + (A[T][K-1] + A[T][K-2]) +
      ... + (A[T][1] - A[T][0]) + A[T][0]
      = C[T][K-1] + C[T][K-2] + ... + C[T][0] + A[T][0]
      = C[T][K-1] + C[T][K-2] + ... + C[T][0], pois A[T][0] = 0.
      = Binomial[T][K] + Binomial[T][K-1] + ... +
      Binomial[T][1].

      Temos então uma fórmula bonita para A[T][K]. Voltemos para o
      nosso problema: Queremos saber qual o menor número de testes que
      precisamos para determinar o valor mínimo N de estouro. Ou
      seja, queremos saber o menor T tal que A[T][K] >= N (se convença
      disso a partir da definição de A[T][K] antes de
      continuar).

      Se K = 1, A[T][K] é igual a Binomial[T][1] = T, donde a resposta
      é N, de imediato. Já se K = 2, então A[T][K] = T*(T+1)/2, e
      portanto T = 5*10^4 já é mais que suficiente para fazer A[T][K]
      ser maior que o maior valor possível de N, que é 10^9. Podemos
      então tentar cada valor de T em sequência, mas aí surge um outro
      problema: Como calcular Binomial[T][K] quando T e K são grandes?
      Poderíamos notar que, nesse caso, o valor do binomial vai passar
      rapidamente de 10^9, mas vamos resolver esse problema de outro
      jeito.

      Note que ter mais de 30 balões nunca é vantagem: Se fosse,
      teríamos que fazer mais de 30 testes; do contrário, pelo menos
      um balão ficaria parado. Mas, com 30 testes e 30 balões, já
      temos A[30][30] = 2^30 - 1 > 10^9, lembrando que a soma da
      n-ésima linha do triângulo de Pascal é 2^n, donde podemos supor
      que K é menor ou igual a 30 (outra maneira de ver isso é que,
      com mais de 30 balões e 30 testes, temos balões suficientes para
      fazer uma busca binária direta, sem se preocupar com o fim do
      estoque de balões). Nosso problema está resolvido.

      A solução abaixo precomputa os binomiais necessários
      (trabalhando com long long, mas sem preocupar com overflow: se
      algum binomial estourar, é fácil de ver que a soma dos binomiais
      irá chegar em N muito antes de tentarmos somá-lo a nossa
      resposta) e depois faz uma busca linear em T. O caso K == 1 é
      tratado em especial, como acima.
    */

    memset(C, 0, sizeof C);
    C[0][0] = 1;
    for(int i = 1; i <= 50000; i++) {
        C[i][0] = 1;
        for(int j = 1; j <= 30; j++)
            C[i][j] = C[i-1][j-1] + C[i-1][j];
    }

    if(k == 1)
        printf("%d\n", n);
    else {
        if(k > 30)
            k = 30;

        for(int i = 1; ; i++) {
            long long soma = 0;
            for(int j = 1; j <= k; j++) {
                soma += C[i][j];
                if(soma >= n) {
                    printf("%d\n", i);
                    return 0;
                }
            }
        }
    }
}
