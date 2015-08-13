#include <string.h>
#include <iostream>

using namespace std;

#define TAM_SENHA 6

int senha[TAM_SENHA];

string decode()
{
	string ret;
	
	for (int i = 0; i < TAM_SENHA; i++)
	{
		switch(senha[i])
		{
			case 1: ret += "0 "; break;
			case 2: ret += "1 "; break;
			case 4: ret += "2 "; break;
			case 8: ret += "3 "; break;
			case 16: ret += "4 "; break;
			case 32: ret += "5 "; break;
			case 64: ret += "6 "; break;
			case 128: ret += "7 "; break;
			case 256: ret += "8 "; break;
			case 512: ret += "9 "; break;
		}
	}
	
	return ret;
}

int readAsBitSet()
{
	int tmp, ret;
	cin >> tmp;
	ret = 1<<tmp;
	cin >> tmp;
	ret |= 1<<tmp;
	return ret;
}

string getsenha(int dicas)
{
	int a, b, c, d, e, tmp;
	char s;
	
	for (int i = 0; i < TAM_SENHA; i++) senha[i] = 0xfff;
	
	for (int j = 0; j < dicas; j++)
	{
		a = readAsBitSet();
		b = readAsBitSet();
		c = readAsBitSet();
		d = readAsBitSet();
		e = readAsBitSet();
	
		for (int i = 0; i < TAM_SENHA; i++)
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