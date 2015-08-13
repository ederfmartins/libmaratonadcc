#define TAM 10
int cnt = 0;
int total; //numero de elementos de elem
int elem[TAM];
bool usados[TAM]; //ZERE ME

void enumera(int num)
{
	if (num == total)
	{
		cnt++;
		for (int i = 0; i < total; i++) cout << elem[i];
		cout << endl;
		return;
	}

	for (int i = 0; i < total; i++)
	{
		if (!usados[i])
		{
			elem[num] = i;
			usados[i] = true;
			enumera (num + 1);
			usados[i] = false;
		}
	}
}
