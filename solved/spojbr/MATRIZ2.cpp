#include <stdio.h>
#include <stdint.h>

using namespace std;

#define SIZE 100010

int64_t A[SIZE], B[SIZE];

void imprime(int x[], int n)
{
	for (int i = 1; i <= n; i++) printf("%d ", x[i]);
	printf("\n");
}

int main()
{
	int n;
	int64_t P , Q, R, S, X, Y, I, J;
	int64_t soma = 0;
	
	scanf("%d %lld %lld %lld %lld %lld %lld %lld %lld", &n, &P, &Q, &R, &S, &X, &Y, &I, &J);
	
	for (int j = 1; j <= n; j++) A[j] = (P * I + Q * j) % X;
	for (int i = 1; i <= n; i++) B[i] = (R * i + S * J) % Y;
	
//	imprime(A, n);
//	imprime(B, n);
	
	for (int i = 1; i <= n; i++) soma += A[i] * B[i];
	
	printf("%lld\n", soma);
	
	return 0;
}

