#include <iostream>
#include <limits>
#include <iomanip>
#include <math.h>

using namespace std;

#define SIZE 1000

struct Ponto
{
	double x, y;
	double dist2(Ponto& p)
	{
		return (x - p.x)*(x - p.x) + (y - p.y)*(y - p.y);
	}
};

Ponto pontos[SIZE];

int main()
{
	int n;
	double dist = numeric_limits<double>::max(), tmp;
	
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> pontos[i].x >> pontos[i].y;
		
		for (int j = 0; j < i; j++) {
			tmp = pontos[i].dist2(pontos[j]);
			if (tmp < dist) dist = tmp;
		}
	}
	
	cout << fixed << setprecision(3) << sqrt(dist) << endl;
	return 0;
}

