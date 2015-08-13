#include <iostream>
using namespace std;
int matriz[7][8];
int pecas[28][2] = {
{0,0}, {0,1}, {0,2}, {0,3},
{0,4}, {0,5}, {0,6}, {1,1},
{1,2}, {1,3}, {1,4}, {1,5},
{1,6}, {2,2}, {2,3}, {2,4},
{2,5}, {2,6}, {3,3}, {3,4},
{3,5}, {3,6}, {4,4}, {4,5},
{4,6}, {5,5}, {5,6}, {6,6}
};
bool usadas[28];

#define call(x, y, x1, y1) {\
	int a = matriz[(x)][(y)];\
	int b = matriz[(x1)][(y1)];\
	matriz[(x)][(y)] = -1;\
	matriz[(x1)][(y1)] = -1;\
	numPosicoes += conta((x), (y)+1, cntUsadas+1);\
	matriz[(x)][(y)] = a;\
	matriz[(x1)][(y1)] = b;\
}\

int conta(int x, int y, int cntUsadas)
{
//cout << x << " " << y << " " << cntUsadas << endl;
	if (cntUsadas >= 28) return 1;
	if (x >= 7 && y >= 8) return 0;
	if (y >= 8) return conta(x+1, 0, cntUsadas);
	if (x >= 7) return 0;
	if (matriz[x][y] == -1) return conta(x, y+1, cntUsadas);
	
	int numPosicoes = 0;
	
//for (int j = 0; j < 7; j++) { for (int k = 0; k < 8; k++) cout << matriz[j][k]<<" "; cout << endl; }
	
	for (int i = 0; i < 28; i++)
	{
//cout << i << " " << pecas[i][0] << " " << pecas[i][1] << " " << usadas[i] << endl;
		if (!usadas[i])
		{
			usadas[i] = true;
			if (y+1 < 8 && matriz[x][y+1] != -1)
			{
				if ((matriz[x][y] == pecas[i][0] && matriz[x][y+1] == pecas[i][1]) || (matriz[x][y] == pecas[i][1] && matriz[x][y+1] == pecas[i][0]))
					call(x, y, x, y+1)
			}
			if (x+1 < 7 && matriz[x+1][y] != -1)
			{
				if ((matriz[x][y] == pecas[i][0] && matriz[x+1][y] == pecas[i][1]) || (matriz[x][y] == pecas[i][1] && matriz[x+1][y] == pecas[i][0]))
					call(x, y, x+1, y)
			}
			usadas[i] = false;
		}
	}
	
	return numPosicoes;
}

int main()
{
	int n;
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 7; j++)
			for (int k = 0; k < 8; k++)
				cin >> matriz[j][k];
		
		for (int j = 0; j < 28; j++)
			usadas[j] = false;

		cout << "Teste " << i+1 << endl << conta(0, 0, 0) << endl << endl;
	}
	
	return 0;
}
