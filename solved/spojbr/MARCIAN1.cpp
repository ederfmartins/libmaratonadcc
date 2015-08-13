#include <iostream>
#include <math.h>
using namespace std;
/*8710. Marciano geometria muito facil*/

int main()
{
	int L, A, P;
	double R;
	cin >> L >> A >> P >> R;
	
	int d = L*L + A*A + P*P;
	
	if (sqrt(d) <= 2*R) cout << "S" << endl;
	else cout << "N" << endl;
	
	return 0;
}

