#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <sstream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;
#define TAM 10001

vector<pair<int, int> > cv;
int m, b;

int max(int *n, int size) {
	int maior=n[0];
	for(int i=1; i < size; i++)
		if(maior < n[i]) maior = n[i];

	return maior;
}
bool cmp(pair<int, int> a, pair<int,int> b) {
	return ((double)a.second)/a.first > ((double)b.second)/b.first;
}
int solve() {
	int votos=0;
	sort(cv.begin(), cv.end(), cmp);
	int resta=m;
	for(int i = 0; i < cv.size(); i++) {
		if(resta-cv[i].first < 0) {
			votos += (int)((double)cv[i].second)*((double)resta/(double)cv[i].first);
			break;
		} else {
			votos += cv[i].second;
			resta -= cv[i].first;
		}
	}
	return votos;
}

int main()
{
	//m orcamento, b # pessoas
	while(scanf("%d %d", &m, &b)==2) {
		cv.clear();
		for(int i = 0; i < b; i++)
		{
			int c,v;
			scanf("%d %d", &v, &c);
			cv.push_back(make_pair(c, v));
		}

		cout << solve() << endl;
	}
	return 0;
}

