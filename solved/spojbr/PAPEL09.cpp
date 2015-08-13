#include <stdio.h>
using namespace std;

int main()
{
	int competidores, totalFolhas, folhasPorCompetidor;
	scanf("%d %d %d", &competidores, &totalFolhas, &folhasPorCompetidor);
	if (competidores * folhasPorCompetidor <= totalFolhas) printf("S\n");
	else printf("N\n");
	return 0;
}
