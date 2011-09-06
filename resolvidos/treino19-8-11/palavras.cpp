#include <stdio.h>
#include <string>
#include <string.h>
#include <sstream>
#include <iostream>
using namespace std;
int l, c, psize;
char matriz[51][51];
char palavra[100];

int incx[8] = {0,  0, 1, -1, 1, -1,  1, -1};
int incy[8] = {1, -1, 0,  0, 1, -1, -1,  1};

bool procura(int x, int y, int pos)
{
	if (pos >= psize) return false;
	if (x < 0 || x >= l) return false;
	if (y < 0 || y >= c) return false;
	
	if (palavra[pos] == matriz[x][y])
	{
		if (pos == psize -1) return true;
		
		for (int i = 0; i < 8; i++)
		{
			if (procura(x + incx[i], y + incy[i], pos+1)) return true;
		}
	}
	
	return false;
}

int main()
{
	int p, t = 0;
	while(scanf("%d %d %d", &l, &c, &p) == 3 && l != 0 && c != 0 && p != 0){
		for (int i = 0; i < l; i++) scanf("%s", matriz[i]);
		
		printf("Teste %d\n", ++t);
		
		for (int i = 0; i < p; i++)
		{
			scanf("%s", palavra);
			psize = strlen(palavra);
			bool achou = false;
			
			for (int a = 0; a < l; a++)
			{
				for (int b = 0; b < c; b++)
				{
					if (procura(a, b, 0)) {
						printf("%s: linha %d, coluna %d\n", palavra, a+1, b+1); 
						achou = true;
					}
				}
			}
			
			if (!achou) printf("%s: nao encontrada\n", palavra);
		}
	}

	return 0;
}
