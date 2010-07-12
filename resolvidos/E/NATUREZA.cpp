#include <stdio.h>
#include <map>
#include <string>

using namespace std;

/** 1822. Natureza - dsf para achar componentes conectados*/

#define MAX_BIXOS 5000

int c,r;
map<string,int> nome2ind;
unsigned char relacoes[MAX_BIXOS][MAX_BIXOS];
unsigned char escolhidos[MAX_BIXOS];

int espalha(int nodo) {
	int nodosContagiados = 0;
	for(int i=0; i < c; i++) {
		if(!escolhidos[i] && relacoes[nodo][i]) {
			escolhidos[i] = 1;
			nodosContagiados += espalha(i) + 1;
		}
	}
	return nodosContagiados;
}

int maiorGrafoConexo() {
	int maiorGC=0;
	for(int bixoPartida=0; bixoPartida < c; bixoPartida++) {
		if(escolhidos[bixoPartida]) continue;

		escolhidos[bixoPartida]=1;
		int tamanhoCadeia = espalha(bixoPartida)+1;

		if(tamanhoCadeia > maiorGC) maiorGC = tamanhoCadeia;
	}
	return maiorGC;
}

int main() {
	char tmp[35], tmp2[35];
	while(scanf("%d %d", &c, &r)==2) {
		if((c|r)==0) return 0;
		nome2ind.clear();
		for(int i=0; i < c; i++) {
			scanf("%s", tmp);
			nome2ind[tmp] = i;

			// Inicializa campos
			escolhidos[i] = 0;
			for(int j=0; j < c; j++) relacoes[i][j] = 0;
		}

		for(int i=0; i < r; i++) {
			scanf("%s %s", tmp, tmp2);
			relacoes[nome2ind[tmp]][nome2ind[tmp2]]=1;
			relacoes[nome2ind[tmp2]][nome2ind[tmp]]=1;
		}
		printf("%d\n", maiorGrafoConexo());
	}
	return 0;
}
