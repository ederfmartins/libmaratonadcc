#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <inttypes.h>
#include <ctype.h>
#include <limits.h>

#include <algorithm>
#include <utility>
#include <iostream>

#include <map>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <sstream>

using namespace std;

#define abs(a) ((a) > 0 ? (a) : -(a))
#define INF 
#define arredonda(a) fixed << setprecision(1) << (a)

#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)

/**
 * -1 se x < y
 * 0 se x = y
 * 1 se x > y
 */
const double EPS = 1e-10;
#define _inline(f...) f() __attribute__((always_inline)); f
_inline(int cmp)(double x, double y = 0, double tol = EPS)
{
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

bool myCmpfunction (int i, int j) { return (i<j); }

bool dentro(int x, int y, int n)
{
	return x >= 0 && x < n && y >= 0 && y < n;
}

set<pair<int,int> > possiveis(int x, int y, int n, int passos)
{
	set<pair<int,int> > ret;
	
	for (int i = 0; i <= passos; i++)
	{
		int xx = x + i;
		int yy = y + passos - i;
		
		if (dentro(xx, yy, n)) {
			ret.insert(make_pair<int, int>(xx, yy));
		}
		
		xx = x - i;
		yy = y - passos + i;
		
		//cout << "xx=" << xx << " yy=" << yy << endl;
		
		if (dentro(xx, yy, n)) {
			ret.insert(make_pair<int, int>(xx, yy));
		}
		
		xx = x + i;
		yy = y - passos + i;
		
		if (dentro(xx, yy, n)) {
			ret.insert(make_pair<int, int>(xx, yy));
		}
		
		xx = x - i;
		yy = y + passos - i;
		
		if (dentro(xx, yy, n)) {
			ret.insert(make_pair<int, int>(xx, yy));
		}
	}
	
	return ret;
}

void imprime(set<pair<int,int> > s)
{
	for (set<pair<int,int> >::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}
}

int main()
{
	int n, k, x, y, p;
	
	cin >> n >> k;
	set<pair<int,int> > posi;
	
	for (int i = 0; i < k; i++)
	{
		cin >> x >> y >> p;
		
		if (i == 0) {
			posi = possiveis(x, y, n, p);
		}
		else {
			set<pair<int,int> > posi1 = possiveis(x, y, n, p);
			
			set<pair<int,int> > intersect;
			set_intersection(posi.begin(), posi.end(), posi1.begin(), posi1.end(), std::inserter(intersect, intersect.begin()));
			
//			cout << "set 1" << endl;
//			imprime(posi);
//			cout << "set 2" << endl;
//			imprime(posi1);
//			cout << "intersecao" << endl;
//			imprime(intersect);
			
			posi = intersect;
		}
		
		if (posi.size() == 0) break;
	}
	
	if (posi.size() == 0 || posi.size() > 1) cout << "-1 -1" << endl;
	else cout << posi.begin()->first << " " << posi.begin()->second << endl;
	
	return 0;
}

