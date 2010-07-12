#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <inttypes.h>
#include <ctype.h>

#include <algorithm>
#include <utility>
#include <iostream>

#include <map>
#include <set>
#include <vector>
#include <sstream>

/** 136 - Ugly Numbers 
 * Brute force, faco uma matriz 3d com todos os primos e vo na marra.
 */

using namespace std;

int main()
{
	// brute force part
/*
	int n = 13; // raiz cubica de 1500
	vector<uint64_t> p2;
	vector<uint64_t> p3;
	vector<uint64_t> p5;
	vector<uint64_t> ugly;
	uint64_t tmp;

	tmp = 1;
	for (int i = 0; i < n; i++) { p2.push_back(tmp); tmp *= 2; }

	tmp = 1;
	for (int i = 0; i < n; i++) { p3.push_back(tmp); tmp *= 3; }

	tmp = 1;
	for (int i = 0; i < n; i++) { p5.push_back(tmp); tmp *= 5; }

	uint64_t maior = p2[p2.size()-1]*p3[p3.size()-1]*p5[p5.size()-1];

	while (p2[p2.size() -1 ] < maior) p2.push_back(p2[p2.size() -1 ]*2);
	while (p3[p3.size() -1 ] < maior) p3.push_back(p3[p3.size() -1 ]*3);
	while (p5[p5.size() -1 ] < maior) p5.push_back(p5[p5.size() -1 ]*5);

	for (int i = 0; i < p2.size(); i++)
	{
		for (int j = 0; j < p3.size(); j++)
		{
			for (int k = 0; k < p5.size(); k++)
			{
				ugly.push_back(p2[i]*p3[j]*p5[k]);
			}
		}
	}

	sort(ugly.begin(), ugly.end());	

	cout << "The 1500'th ugly number is " << ugly[1499] << "." << endl;
*/
	cout << "The 1500'th ugly number is 859963392." << endl;
	return 0;
}

