#include <iostream>

using namespace std;


// Para gerar essa tabela eh so fazer um for nas partes p1 e p2 e ir testando se (p1 + p2)^2 = p1p2
char n2[3][3] = {"00", "01", "81"};
char n4[5][5] = {"0000", "0001","2025","3025","9801"};
char n6[5][7] = {"000000", "000001", "088209", "494209", "998001"};
char n8[9][9] = { "00000000", "00000001", "04941729", "07441984", "24502500", "25502500", "52881984", "60481729", "99980001"};

//256 - Quirksome Squares

int main()
{
	int n;
	while( cin >> n)
	{
		switch (n)
		{
			case 2: for (int i = 0; i < 3; i++) cout << n2[i] << endl; break;
			case 4: for (int i = 0; i < 5; i++) cout << n4[i] << endl; break;
			case 6: for (int i = 0; i < 5; i++) cout << n6[i] << endl; break;
			case 8: for (int i = 0; i < 9; i++) cout << n8[i] << endl; break;
		}
	}
	return 0;
}
