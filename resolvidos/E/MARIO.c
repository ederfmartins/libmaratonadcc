#include <stdio.h>

/** 1890. Mario - ad hoc*/

int armarios[100000];
int n,l;

int coberturaJanela(int inicio) {
	int rtrn=0, i=inicio, posFinal=armarios[inicio]+n;
	while(1) {
		if(i < l && armarios[i] < posFinal) {
			i++;
		} else break;
	}
	return i-inicio;
}

int melhorJanela() { // Pega a janela com melhor cobertura
	int i,maiorCobertura=0, indFinal=l-1;
	while(indFinal > 0 && armarios[indFinal] > armarios[l-1]-n) indFinal--;
	if(indFinal < l-1 && armarios[indFinal] < armarios[l-1]-n) indFinal++;

	for(i=0; i <= indFinal; i++) {
		int cobTmp = coberturaJanela(i);
		if(cobTmp > maiorCobertura) maiorCobertura = cobTmp;
	}
	return maiorCobertura;
}

int main() {
	int i;
	while(scanf("%d %d", &n, &l)==2) {
		if((n|l)==0) return 0;
		for(i=0; i < l; i++) {
			scanf("%d", armarios+i);
		}
		// Arrasta janela procurando maior cobertura
		printf("%d\n", n-melhorJanela());
	}
	return 0;
}

