#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <iostream>

using namespace std;

int compare (const void * a, const void * b)
{
  return ( *(int*)b - *(int*)a);
}



int main()
{
	int M, N;
	int vec[10000];

	cin >> N >> M;

	for (int i = 0; i < N; i++) cin >> vec[i];

	qsort(vec, N, sizeof(int), compare);

	for (int i = 0; i < M; i++) cout << vec[i] << endl;

	return 0;
}

