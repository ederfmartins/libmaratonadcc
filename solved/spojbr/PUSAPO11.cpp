#include <stdio.h>

using namespace std;

int pedras[110];

int main()
{
	int n, m, start, step;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) pedras[0] = 0;
	
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &start, &step);
		
		for (int s = 0; s < n; s++) {
			if ((start-1)%step == s%step)
				pedras[s] = 1;
		}
	}
	
	for (int i = 0; i < n; i++) printf("%d\n", pedras[i]);
	
	return 0;
}

