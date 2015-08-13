#include <stdio.h>
#include <set>
using namespace std;

int main() {
	int ok = 0;
	int n;
	set<pair<int, int> > raios;
	pair<int, int> par;
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &par.first, &par.second);
		
		if (raios.count(par)) {
			ok = 1;
			break;
		}
		raios.insert(par);
	}
	
	printf("%d\n", ok);
	
	return 0;
}

