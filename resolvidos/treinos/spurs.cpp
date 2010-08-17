#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <inttypes.h>
#include <ctype.h>

#include <algorithm>
#include <utility>
#include <iostream>

#include <map>
#include <set>
#include <vector>
#include <sstream>

using namespace std;

double EPS = 1e-10;

int cmp(double x, double y = 0, double tol = EPS)
{
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class BasketTime
{
	public:
	int id;
	int pontos;
	int cestasPro;
	int cestasContra;
	BasketTime(int pid = 0)
	{
		id = pid;
		pontos = cestasPro = cestasContra = 0;
	}
	double avg()
	{
		return cestasContra != 0 ? ((double)cestasPro) /cestasContra : cestasPro;
	}
};

bool BasketTimeCmp(BasketTime t1, BasketTime t2)
{
	if (t1.pontos > t2.pontos) return true;
	else if (t1.pontos < t2.pontos) return false;
	else if (cmp(t1.avg(),t2.avg()) == 1) return true;
	else if (cmp(t1.avg(),t2.avg()) == -1) return false;
	else if (t1.cestasPro > t2.cestasPro) return true;
	else if (t1.cestasPro < t2.cestasPro) return false;
	else if (t1.id < t2.id) return true;
	else return false;
}

int main()
{
        int h = 1;
	int n, x, y, w, z;
	bool first = true;

        while (cin >> n)
        {
		if (n == 0) break;

		if (!first) cout << endl;
		first = false;

		int m = n*(n-1)/2;
		vector<BasketTime> times;
		for (int i = 0; i < n; i++) times.push_back(BasketTime(i+1));

		for (int i = 0; i < m; i++)
		{
			cin >> x >> y >> z >> w;
			times[x-1].cestasPro += y;
			times[z-1].cestasPro += w;

			times[x-1].cestasContra += w;
			times[z-1].cestasContra += y;

			if (y > w) { times[x-1].pontos += 2; times[z-1].pontos += 1; }
			else { times[z-1].pontos += 2; times[x-1].pontos += 1; }
		}

		sort(times.begin(), times.end(), BasketTimeCmp);
		
		cout << "Instancia " << h++ << endl;
		for (int i = 0; i < n; i++)
		{
			//cout << "t=" << times[i].id << " p=" << times[i].cestasPro;
			cout << times[i].id;
			if (i != n - 1) cout << " ";
			else cout << endl;
		}
        }
        return 0;
}
