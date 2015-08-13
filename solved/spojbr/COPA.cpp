#include <stdio.h>

using namespace std;

int main()
{
	int n, J, tmp;
	char time[100];
	
	while (1)
	{
		scanf("%d %d", &n, &J);
		
		if (n == 0 && J == 0) break;
		
		int somaPontos = 0;
		for (int i = 0; i < n; i++) {
			scanf("%s %d", time, &tmp);
			somaPontos += tmp;
		}
		
		printf("%d\n", 3*J - somaPontos);
		
		//soma pontos time i = 3*vi+ ii
		//soma total = 3 (v1 + .. + vn) + (ii+...+in) 
		//soma total = 3 * Soma#vitorias + Soma#empates
		
		//#jogos = (Soma#vitorias + Soma#empates + Soma#derrotas)/2
		//#vitorias = #derrotas
		
		//2*#jogos = 2*Soma#vitorias + Soma#empates => (2*#jogos - Soma#empates)/2 = Soma#vitorias 
		//soma total = 3 * (2*#jogos - #empates)/2 + #empates
		//2*soma total = 6 *#jogos - 3*#empates + 2*#empates => 6 *#jogos - 2*soma total  = #empates
		
	}
	
	return 0;
}

