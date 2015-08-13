#include <iostream>

using namespace std;

#define abs(x) ((x) > 0 ? (x) : -(x))

int gcd(int x, int y)
{
	return y ? gcd(y, x % y) : abs(x);
}

/*
	Era o que eu achava mesmo. Acordei domingo com a solução do problema na cabeça :)
	O pulo do gato era fazer uma mudança de cordenada para a origem ser o ponto (a,b) pois nesse caso a equação da reta se
	resume a
	y = ax
	Seja a = p/q com p e q primos entre si
	como a = (b-d)/(c-a) inclinação da reta
	Sendo x um numero inteiro resulta que para y ser inteiro x tem que ser multiplo de q, logo o problema se resume a contar os
	multiplos de q no intervalo [0, (c-a)]
	
	calcular p e q é fácil
	p/q = (b-d)/(c-a)
	ou
	p/q = mdc(b-d, c-a)*p/mdc(b-d, c-a)*q
	
	logo (c-a) = mdc(b-d, c-a)*q
	assim temos mdc multiplos de q em (c-a), e como o ponto inicial não foi contado temos que somar 1.

*/
int main()
{
	int n;
	int a, b, c, d;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b >> c >> d;
		
		if (c - a == 0) cout << abs(d-b) + 1 << endl;
		else if (d - b == 0) cout << abs(c-a) + 1 << endl;
		else cout << gcd(abs(d-b), abs(c - a)) + 1 << endl;
	}
	
	return 0;
}

