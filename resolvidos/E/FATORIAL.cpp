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

int fatorial[1000001];

int mpow(int a, int b, int n = 10)
{
  if(b == 0)
    return 1;
  else {
    long long res = mpow(a, b/2, n);
    res = (res*res) % n;
    if(b%2 == 1)
      res = (res*a) % n;
    return (int) res;
  }
}

int main()
{
	int n, h = 1;
	int x = 1;
	int t = 0, f = 0;
	
	std::cout.sync_with_stdio(false);
	
	fatorial[0] = 1;

	for (int i = 1; i <= 1000001; i++)
	{
		int k = i;
		
		while (k % 2 == 0) { k /= 2; t++; }
		while (k % 5 == 0) { k /= 5; f++; }
		
		if (t > f) {
			t-= f;
			f = 0;
		} else {
			f-= t;
			t = 0;
		}
		
		x = (x*k)%10;
		fatorial[i] = (x * mpow(2, t) * mpow(5, f))%10;
	}

	while (cin >> n)
	{
		cout << "Instancia " << h++ << endl;
		cout << fatorial[n] << endl << endl;
	}

	return 0;
}

/*
Seja F[0] = 1 = 0! 

Seja t = 0 e f = 0 (esses contam os "2" e "5" sobrando) 

Seja x = 1 // o fatorial sem fatores 2 ou 5 mod 10 

Para cada i de 1 ate o maximo, faca 

k <- i
enquanto k mod 2 = 0: {k/= 2; ++t} // fatora por 2
enquanto k mod 5 = 0: {k/= 5; ++f} // fatora por 5 

subtraia o maior do menor entre f e t // um deles vira 0, equivalente a retirar os 0's do final. pode fazer "if (t > f) {t-= f; f = 0;} else {f-= t; t = 0;}" 

agora, ponha k dentro de x (ver definicao) 
x = (x*k)%10; 

finalmente calcule as contribuicoes de 2 e 5 em cima de x e calcule o ultimo digito do fatorial: 

F[i] = (x * mpow(2, t) * mpow(5, f))%10; 

aqui mpow eh a funcao de exponenciacao mod 10 

Verificar que o procedimento funciona e que ele eh O(n log n), onde n eh o valor maximo. 
*/



