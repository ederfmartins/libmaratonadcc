#include <stdio.h>
#include <math.h>

using namespace std;

char expressao[100010];
char pilha[100010];

bool par(char a, char b)
{
	if ((a == '{' && b == '}') || (a == '[' && b == ']') || (a == '(' && b == ')')) return true;
	else return false;
}

int main()
{
	int T, idx;
	bool ok;
	scanf("%d\n", &T);
	
	for (int teste = 0; teste < T; teste++)
	{
		scanf("%s\n", expressao);
		ok = true;
		idx = 0;
		
		for (int i = 0; expressao[i] != '\0'; i++)
		{
			if (expressao[i] == '{' || expressao[i] == '[' || expressao[i] == '(') {
				pilha[idx++] = expressao[i];
			}
			else {
				if (!par(pilha[idx-1], expressao[i])) {
					ok = false;
					//printf("a pilha=%s expressao=%c idx=\n", pilha, expressao[i], idx);
					break;
				}
				idx--;
			}
			
			//printf("pilha=%s expressao=%c\n", pilha, expressao[i]);
		} 
		
		if (ok && idx == 0) printf("S\n");
		else printf("N\n");
	}
	
	return 0;
}
