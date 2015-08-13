#include <iostream>
using namespace std;

/** 3094. Elementar, meu caro Watson! - igual ao problema do uva 299 - Train Swapping porem nao basta ordenar e contar as trocas pq nao passa entao uso um distribution cont ou seria bucket count que eh linear e ai passa.
*/

#define MAX 10002

int swapCnt;
int size;

void swapbubble( int v[], int i)
{
	int aux=0;    
   
	aux = v[i];
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

void sort(int vec[])
{
	//int b[MAX];
	int tmp;
	swapCnt = 0;
	bool trocou = true;

	while (trocou)
	{
		trocou = false;
		for (int i = 1; i <= size; i++)
		{
	//cout << "d " << i << " " << vec[i] << endl;
			if (i != vec[i])
			{
				swapCnt++;
				tmp = vec[vec[i]];
				vec[vec[i]] = vec[i];
				vec[i] = tmp;
				trocou = true;
			}
		}
	}
//for (int i = 1; i <= size; i++) cout << vec[i] << " ";
}

int main()
{
	int n;
	int vec[MAX];

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> size;
		swapCnt = 0;

		for (int j = 1; j <= size; j++)
		{
			cin >> vec[j];
		}

		sort(vec);
		//bubble(vec, size);
		cout << swapCnt << endl;
	}
	return 0;
}
