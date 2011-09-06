#include<stdio.h>
#include<math.h>



int main(){
	long long int n, n2;
	long long int a, b;
	int pot;

	scanf("%lld", &n);
	while(n != 0){
		n2 = n*n;

		pot = 10;
		a = n2/pot;
		b = n2%pot;
		int flag = 0;
		if (n == 1)
			printf("1: S\n");	
		else{
		while (a != 0){
			if (b != 0){
				if (a+b == n){
					printf("%d: S\n", n);
					flag = 1;
					break;
				}
			}
			a = a/10;
			pot *= 10;
			b = n2%pot;
		}
		if (flag == 0) 
			printf("%d: N\n", n);
		}
		scanf("%lld", &n);
	}

	return 0;
}
