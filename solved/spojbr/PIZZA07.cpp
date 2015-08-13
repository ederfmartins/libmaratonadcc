#include <stdio.h>
#include <algorithm>

using namespace std;

#define SIZE 100000

int array[SIZE];

int maxSum(int a[], int n)
{
    int somaMaxima = 0, somaAtual = 0;
    
    for(int i = 0; i < n; i++)
    {
        somaAtual = somaAtual + a[i];
        if(somaAtual < 0) somaAtual = 0;
        
        if(somaMaxima < somaAtual)
            somaMaxima = somaAtual;
    }
    
    return somaMaxima;
}
 

int maxCircularSum(int a[], int n)
{
   //(1)
   int maxSoma = maxSum(a, n);
 
   // (2)
   int somaTotal  =  0;
   for(int i = 0; i < n; i++)
   {
        somaTotal += a[i];
        a[i] = -a[i];
   }
   
   int somaComplemento = somaTotal + maxSum(a, n);
   
   //max((1), (2))
   return (somaComplemento > maxSoma)? somaComplemento: maxSoma;
}


int main()
{
	int n;
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &array[i]);

	printf("%d\n", maxCircularSum(array, n));
	return 0;
}

