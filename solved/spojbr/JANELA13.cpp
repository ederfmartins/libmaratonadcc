#include <stdio.h>
#include <algorithm>
using namespace std;

#define TAM 4
#define LEM_JANELA 200
#define FIM_MOLDURA 600

int main()
{
    int buraco = 0;
    int fim_janela[TAM];
    fim_janela[0] = 0;
    //to or more use for kkk
    scanf("%d %d %d", &fim_janela[1], &fim_janela[2], &fim_janela[3]);

    for (int i = 1; i < TAM; i++) fim_janela[i] += LEM_JANELA;
    sort(fim_janela, fim_janela+TAM);

    
    for (int i = 1; i < TAM; i++)
    {
        int inicio_janela = fim_janela[i] - LEM_JANELA;
        if (inicio_janela > fim_janela[i-1])
        {
            buraco += inicio_janela - fim_janela[i-1];
        }
    }

    if (fim_janela[TAM-1] < FIM_MOLDURA)
    {
        buraco += FIM_MOLDURA - fim_janela[TAM-1];
    }

    printf("%d\n", 100*buraco);
    return 0;
}
