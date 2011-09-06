#include <stdio.h>
#include <string>
#include <string.h>
#include <sstream>
using namespace std;

char seq[10001];

void rlt(string& ret)
{
	int i = 1;
	char atual = seq[0];
	int cntAt = 1;
	stringstream ss;

	while (seq[i] != '\0')
	{
	//printf("(%c %c)", seq[i], atual);
		if (atual == seq[i]) cntAt++;
		else {
			ss << cntAt << atual;
			atual = seq[i];
			cntAt = 1;
		}
		
		i++;
	}
	
	ss << cntAt << atual;
	
	ret = ss.str();
}

int main()
{
	int n;
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%s", seq);
		string r;
		rlt(r);
		
		char c;
		if (r.size() < strlen(seq)) c = 'S';
		else c = 'N';

		printf("%s %c\n", r.c_str(), c);
	}

	return 0;
}
