#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <inttypes.h>
#include <ctype.h>

#include <algorithm>
#include <utility>
#include <iostream>

#include <map>
#include <set>
#include <vector>
#include <sstream>

using namespace std;

#define NUM_ITENS 60
#define ESPACO_MAXIMO 2001
int lookupDinamico[NUM_ITENS][ESPACO_MAXIMO];

// Especifico: Desculpa
int c,f;
struct Frase {
	unsigned char tamanho, desculpas;
	Frase(unsigned char n, unsigned char d) : tamanho(n), desculpas(d) {};
	Frase(){};
};
vector<Frase> frases(NUM_ITENS);
bool cmpFrase (Frase i, Frase j) { return (i.tamanho > j.tamanho || i.tamanho==j.tamanho&&i.desculpas<j.desculpas); }

int expansaoDinamica(int left, unsigned char frase)
{
	//printf("left:%d frase:%d tam:%d peso:%d\n", left, frase, frases[frase].tamanho, (int)((unsigned char)frases[frase].desculpas));
	if(frase==0) {
		if(left >= frases[0].tamanho) return frases[0].desculpas;
		else return 0;
	}
	else if (lookupDinamico[frase][left] != 0) {
		return lookupDinamico[frase][left];
	} else if(left < frases[frase].tamanho) {
		/*int i;
		for(i=frase; i < f && frases[i].tamanho > left; i++) {}
		if((i < f) && (frases[i].tamanho < left)) {
			lookupDinamico[frase][left] = expansaoDinamica(left, i);
			return lookupDinamico[frase][left];
		}
		else */return 0;
	} else {
		// Primeiro: Tenta com meu valor
		int comigo = expansaoDinamica(left - (int)((unsigned char)frases[frase].tamanho),
									frase-1)
		+ (int)((unsigned char)frases[frase].desculpas);
		// Agora, tenta sem meu valor
		int semigo = expansaoDinamica(left, frase - 1);
		if(comigo > semigo) {
			// Eh melhor comigo
			lookupDinamico[frase][left] = comigo;
		} else {
			// Eh melhor sem mim
			lookupDinamico[frase][left] = semigo;
		}
		//printf("\tFrase %d\n\tesp:%d comigo:%d semigo: %d\n", frase, left, comigo, semigo);
		return lookupDinamico[frase][left];
	}
}

int main()
{
	int caso = 1;
	while(scanf("%d %d", &c, &f) == 2) {
		if((c|f)==0) return 0;
		int i = 0, j;
		while (i < f) {
			int n, d;
			scanf("%d %d", &n, &d);
			//frases[i] = Frase(n, d);
			frases[i].tamanho = n;
			frases[i].desculpas = d;
			i++;
		}
		// Ordena frases pelo tamanho
		sort(frases.begin(), frases.begin()+f, cmpFrase);
		/*for(i=0;i<f;i++) {
			printf("%d %d\n", frases[i].tamanho, frases[i].desculpas);
		}printf("\n");*/
		// Inicializa o lookup
		for (j = 0; j < f; j++) {
			for (i = 0; i <= c; i++) {
				lookupDinamico[j][i] = 0;
			}
			lookupDinamico[j][frases[j].tamanho] = frases[j].desculpas;
		}

		/*int inicio=0;
		while(inicio < f && frases[inicio].tamanho > c) {
			inicio++; // Pula frases que nao cabem no cartao
		}*/
		/*int res = 0;
		/ *if(inicio < f)* / res = expansaoDinamica(c, f-1);*/

		printf("Teste %d\n", caso);
		printf("%d\n\n", expansaoDinamica(c, f-1));

		caso++;
	}
	return 0;
}
