#include <iostream>
using namespace std;

/** 299 - Train Swapping */

int swapCnt;
void swapbubble( int v[], int i)
{
	int aux=0;    
   
	aux=v[i];
	v[i] = v[i+1];
	v[i+1] = aux;

	swapCnt++;
    
}
void bubble(int v[], int qtd)
{
	int i;
	int trocou;

	do
	{
		qtd--;
		trocou = 0;

		for(i = 0; i < qtd; i++)
		{
			if(v[i] > v[i + 1])
			{
				swapbubble(v, i);
				trocou = 1;
			}
		}
	}while(trocou);
}

int main()
{
	int n, size;
	int vec[50];

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> size;
		for (int j = 0; j < size; j++) cin >> vec[j];

		swapCnt = 0;
		bubble(vec, size);
		cout << "Optimal train swapping takes " << swapCnt << " swaps." << endl;
	}
	return 0;
}

