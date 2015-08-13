#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int salesman[1000];

class mycomparison
{
	public:
	mycomparison(const bool& revparam=false) {}
	bool operator() (const pair<int, int>& p1, const pair<int, int>& p2) const
	{
		if (p1.first < p2.first) return false;
		else if (p1.first > p2.first) return true;
		else return p1.second > p2.second;
	}
};

int main()
{
	int n, l, tmp;
	
	scanf("%d %d", &n, &l);
	
	priority_queue<pair<int, int>, vector<pair<int, int> >, mycomparison> nextSalesman;
	for (int i = 0; i < n; i++)
	{
		salesman[i] = 0;
		nextSalesman.push(make_pair(0, i));
	}
	
	for (int i = 0; i < l; i++)
	{
		scanf("%d", &tmp);
		pair<int, int> currentSalesMan = nextSalesman.top();
		nextSalesman.pop();
		
		salesman[currentSalesMan.second]++;
		nextSalesman.push(make_pair(tmp+currentSalesMan.first, currentSalesMan.second));
	}
	
	for (int i = 0; i < n; i++)
		printf("%d %d\n", i+1, salesman[i]);
	
	return 0;
}
