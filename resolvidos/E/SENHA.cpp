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

int read()
{
	int tmp, ret;
	cin >> tmp;
	ret = 1<<tmp;
	//cout << "bla" << hex << ret << endl;
	cin >> tmp;
	ret |= 1<<tmp;
	//cout << hex << ret << endl;
	return ret;
}

int senha[6];
string decode()
{
	string ret;
	char digit[4];
	digit[2] = '\0';
	
	for (int i = 0; i < 6; i++)
	{
		int masq;
		//cout << hex << senha[i] << endl;
		for (int j = 0; j < 10; j++)
		{
			masq = 1<<j;
			if ((senha[i] & masq) != 0)
			{

				if (i == 5)
				{
					digit[0] = j + '0';
					digit[1] = '\0';				
				}
				else
				{
					digit[0] = j + '0';
					digit[1] = ' ';
				}
				
				ret += digit;
				break;
			}
		}
	}
	
	return ret;
}

string getsenha(int dicas)
{
	int a, b, c, d, e, tmp;
	char s;
	
	a = read(); //cout << hex << a << endl;
	b = read(); //cout << hex << b << endl;
	c = read(); //cout << hex << c << endl;
	d = read(); //cout << hex << d << endl;
	e = read(); //cout << hex << e << endl;
	
	for (int i = 0; i < 6; i++)
	{
		cin >> s;
		switch(s)
		{
			case 'A': senha[i] = a; break;
			case 'B': senha[i] = b; break;
			case 'C': senha[i] = c; break;
			case 'D': senha[i] = d; break;
			case 'E': senha[i] = e; break;
			default: cout << "ops" <<endl;
		}
	}
	
	for (int j = 1; j < dicas; j++)
	{
		a = read();
		b = read();
		c = read();
		d = read();
		e = read();
	
		for (int i = 0; i < 6; i++)
		{
			cin >> s;
			switch(s)
			{
				case 'A': senha[i] &= a; break;
				case 'B': senha[i] &= b; break;
				case 'C': senha[i] &= c; break;
				case 'D': senha[i] &= d; break;
				case 'E': senha[i] &= e; break;
			}
		}
	}
	
	return decode();	
}

int main()
{
	int n, t = 1;
	string exp;

	while (1)
	{
		cin >> n;
		if (n == 0) break;
		
		cout << "Teste " << t++ << endl << getsenha(n) << endl << endl;
	}

	return 0;
}
