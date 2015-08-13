#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int n;
    int anoNasc;
    int anoFalec;
	scanf("%d\n", &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d\n", &anoNasc, &anoFalec);
        
        if (anoNasc < 0 && anoFalec > 0)
            printf("%d\n", abs(anoFalec - anoNasc - 1));
        else
            printf("%d\n", abs(anoFalec - anoNasc));
	}
	
	return 0;
}
