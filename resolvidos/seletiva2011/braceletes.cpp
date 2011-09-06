#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

#define MAX_PATTERN_SIZE 10010
int F[MAX_PATTERN_SIZE];

void build_failure_function(const string &pattern)
{
	int m=pattern.size();
	F[0] = -1;
	for(int i=0; i < m; i++)
	{
		F[i+1] = F[i]+1;
		while(F[i+1] > 0 && pattern[i] != pattern[ F[i+1]-1 ] )
			F[i+1] = F[ F[i+1]-1 ] +1;
	}
}

//kmp
bool kmp(const string &text, const string &pattern) 
{
	build_failure_function(pattern);
	int j=0, m=pattern.size(), n=text.size();

	for(int i=0; i < n; i++)
	{
		while(true)
		{
			if(text[i] == pattern[j] )
			{
				if(++j == m )
				{
					return true;
				}
				break;
			}

			if ( j==0) break;
			j=F[j];
		}
	}

	return false;
}

int main() {
	int n;
	char pattern[101];
	char invPattern[101];
	char text[10001];

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s %s", pattern, text);
		string ntext(text);
		string spattern(pattern);
		int lenp = spattern.size();

		for (int j = 0; j < lenp; j++)
		{
			invPattern[j] = pattern[lenp - j -1];
		}
		invPattern[lenp] = '\0';

		string invSpattern(invPattern);

		//cout << invSpattern << endl;

		ntext += text;
		if (kmp(ntext, spattern) || kmp(ntext, invSpattern)) printf("S\n");
		else printf("N\n");
	}

	return 0;
}

