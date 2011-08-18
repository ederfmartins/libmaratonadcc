#include <stdio.h>
/** 1831. f91 
 * Obs problema ridiculo so passa se for em c. Quem fez esse problema eh um idiota. Nao apresenta nenhum desafio computacional.
 */

/*int f91_rec(int N)
{
	if (N > 100) return N - 10;
	else return f91_rec( f91_rec(N + 11) );
}*/

int main()
{
	int n;

	/*int f91[101];
	for (int i = 1; i < 101; i++)
	{
		f91[i] = f91_rec(i);
		if (f91[i] != 91) cout << "la " << i << endl;
	}*/

	while (1)
	{
		scanf("%i", &n);
		if (n == 0) break;

		/*if (n > 100) cout << "f91(" << n << ") = " << n - 10 << endl;
		else cout << "f91(" << n << ") = " << 91 << endl;*/
		if (n > 100) printf("f91(%i) = %i\n", n, n-10);
		else printf("f91(%i) = 91\n", n);
	}
	return 0;
}
