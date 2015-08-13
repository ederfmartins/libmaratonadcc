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

const double EPS = 1e-10;

int cmp(double x, double y = 0, double tol = EPS)
{
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct point
{
	double x, y;
	point(double x = 0, double y = 0): x(x), y(y) {}

	point operator +(point q) { return point(x + q.x, y + q.y); }
	point operator -(point q) { return point(x - q.x, y - q.y); }
	point operator *(double t) { return point(x * t, y * t); }
	point operator /(double t) { return point(x / t, y / t); }
	double operator *(point q) { return x * q.x + y * q.y; }
	double operator %(point q) { return x * q.y - y * q.x; }

	int cmp(point q) const
	{
		if (int t = ::cmp(x, q.x)) return t;
		return ::cmp(y, q.y);
	}

	bool operator ==(point q) const { return cmp(q) == 0; }
	bool operator !=(point q) const { return cmp(q) != 0; }
	bool operator < (point q) const { return cmp(q) < 0; }

	friend ostream& operator <<(ostream& o, point p) {
	  return o << "(" << p.x << ", " << p.y << ")";
	}
	static point pivot;
};

double abs(point p) { return hypot(p.x, p.y); }
double arg(point p) { return atan2(p.y, p.x); }

point point::pivot;

typedef vector<point> polygon;

int ccw(point p, point q, point r) 
{
	return cmp((p - r) % (q - r));
}

double angle(point p, point q, point r)
{
	point u = p - q, v = r - q;
	return atan2(u % v, u * v);
}

bool between(point p, point q, point r)
{
	return ccw(p, q, r) == 0 && cmp((p - q) * (r - q)) <= 0;
}

int in_poly(point p, polygon& T)
{
	double a = 0;
	int N = T.size();
	for (int i = 0; i < N; i++)
	{
		if (between(T[i], p, T[(i+1) % N])) return -1;
		a += angle(T[i], p, T[(i+1) % N]);
	}
	return cmp(a) != 0;
}


int main()
{
        int n,m,h = 1;
	int x, y;
	bool first = true;

        while (cin >> n)
        {
		if (n == 0) break;
		if (!first) cout << endl;
		first = false;
		polygon poly;

		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			poly.push_back(point(x, y));
		}

		cin >> x >> y;
		point band(x, y);
		int bandPos = in_poly(band, poly);
		cin >> m;
		cout << "Instancia " << h++ << endl;

		for (int i = 1; i <= m; i++)
		{
			cin >> x >> y;
			point p(x, y);
			int solPos = in_poly(p, poly);

			if (solPos == bandPos) cout << "soldado " << i << " defender" << endl;
			else if (solPos == -1) cout << "soldado " << i << " defender" << endl;
			else cout << "soldado " << i << " espanhol" << endl;
		}
        }
        return 0;
}
