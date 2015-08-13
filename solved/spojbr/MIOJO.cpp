#include <stdio.h>
#include <map>
using namespace std;

int A,B,T;
int menorTempo;
//int cnt = 0;

void tenta(int tempoA, int tempoB, int tempoTotal)
{
	//if (cnt > 50) return;
	//cnt++;
	//printf("%d %d %d %d\n", tempoA, tempoB, tempoTotal, menorTempo);

	if (tempoTotal >= menorTempo) return;
	
	if (tempoA == T || tempoB == T)
	{
		if (tempoTotal + T < menorTempo)
			menorTempo = tempoTotal + T;
		return;
	}
	
	//esperar a menor ampuleta acabar
	//caso algum dos tempos seja 0 eu tenho a opção de esperar a ampuleta
	//caso a e b sejam 0 voltei a uma configuração inicial
	if (tempoA > 0 && tempoB > 0) {
		if (tempoA > tempoB) tenta(tempoA-tempoB, 0, tempoTotal + tempoB);
		else tenta(0, tempoB-tempoA, tempoTotal + tempoA);
	}
	else if (tempoA == 0 && tempoB != 0) {
		tenta(A, tempoB, tempoTotal);
		//tenta(A, B-tempoB, tempoTotal);
	}
	else if (tempoB == 0  && tempoA != 0) {
		tenta(tempoA, B, tempoTotal);
		//tenta(A-tempoA, B, tempoTotal);
	}
}

int main()
{
	scanf("%d %d %d", &T, &A, &B);
	menorTempo = 1<<30;
	tenta(A, B, 0);
	tenta(A, 0, 0);
	tenta(0, B, 0);
	printf("%d\n", menorTempo);
	return 0;
}

