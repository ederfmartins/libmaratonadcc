#include <iostream>
#include <string>
#include <map>
using namespace std;

/** 2280. Encontre o telefone */

int main()
{
	map<char, char> keyMap;
	keyMap['A'] = '2';
	keyMap['B'] = '2';
	keyMap['C'] = '2';
	keyMap['D'] = '3';
	keyMap['E'] = '3';
	keyMap['F'] = '3';
	keyMap['G'] = '4';
	keyMap['H'] = '4';
	keyMap['I'] = '4';
	keyMap['J'] = '5';
	keyMap['K'] = '5';
	keyMap['L'] = '5';
	keyMap['M'] = '6';
	keyMap['N'] = '6';
	keyMap['O'] = '6';
	keyMap['P'] = '7';
	keyMap['Q'] = '7';
	keyMap['R'] = '7';
	keyMap['S'] = '7';
	keyMap['T'] = '8';
	keyMap['U'] = '8';
	keyMap['V'] = '8';
	keyMap['W'] = '9';
	keyMap['X'] = '9';
	keyMap['Y'] = '9';
	keyMap['Z'] = '9';

	string linha;
	while (getline(cin, linha))
	{
		for(int i = 0; i < linha.length(); i++)
		{
			if (linha[i] >= '0' && linha[i] <= '9') cout << linha[i];
			else if (linha[i] == '-') cout << linha[i];
			else cout << keyMap[linha[i]];
		}
		cout << endl;
	}
	return 0;   
}
