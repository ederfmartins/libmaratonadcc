#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    double notas[5], maior, menor, soma = 0;
    for (int i = 0; i < 5; i++)
        cin >> notas[i];
    maior = menor = notas[0];

    for (int i = 0; i < 5; i++) {
        if (notas[i] > maior) maior = notas[i];
        else if (notas[i] < menor) menor = notas[i];
        soma += notas[i];
    }
    
    printf("%.1f\n", soma-maior-menor);

    return 0;
}