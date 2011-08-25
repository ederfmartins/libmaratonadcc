#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	vector<string> alunos;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++)
	{
		string a;
		cin >> a;
		alunos.push_back(a);
	}
	
	sort(alunos.begin(), alunos.end());
	
	cout << alunos[k-1] << endl;
	
	return 0;
}
