#include <iostream>
#include <cstdlib>
#include <stdint.h>

using namespace std;

uint64_t pavalia(uint64_t a) {
	if(a<=100llu)
		return 2llu*a;
	else if(a<=10000llu)
		return 200llu+(a-100llu)*3llu;
	else if(a<=1000000llu)
		return 29900llu+(a-10000llu)*5llu;
	else
		return 4979400 + (a-1000000)*7;
}

uint64_t avalia(uint64_t a, uint64_t b) {
	return llabs(pavalia(a) - pavalia(b));
}

uint64_t inv(uint64_t A) {
	if(A <= 200llu)
		return A/2llu;
	else if(A <= 29900llu)
		return 100llu+(A-200llu)/3llu;
	else if(A <= 4979400llu)
		return 10000llu+(A-29900llu)/5llu;
	else {
		return 1000000llu+(A-4979400llu)/7llu;
	}
}

int main() {
	uint64_t A,B;
	while(cin >> A >> B) {
		if(!A) return 0;
		uint64_t z1,z0,sum, meio;
		sum = inv(A);
		meio=(sum+1)/2;
		A=sum;

		if(meio <= 100) {
			// caso 1 ou 2
			z0=(2*A-B)/4;
			if(avalia(sum-z0, z0) == B)
				cout << pavalia(z0) << endl; // caso 1
			else // caso 2
				cout << pavalia( (3*A-B-100)/5 ) << endl;
		}
		else if(meio <= 10000) {
			// casos 2, 3 ou 4 || 8
			z0 = (3*A-B-100)/5;
			if(avalia(sum-z0, z0) == B)
				cout << pavalia(z0) << endl; // caso 2
			else {
				z0 = (3*A-B)/6;
				if(avalia(sum-z0, z0) == B)
					cout << pavalia(z0) << endl; // caso 3
				else {
					z0 = (5*A-B-20000)/8;
					if(avalia(sum-z0, z0) == B)
						cout << pavalia( z0 ) << endl; // caso 4
					else
						cout << pavalia( (5*A-B-20100)/7 ) << endl; // caso 8
				}
			}
		}
		else if(meio <= 1000000) {
			// casos 4, 5 ou 6 || 8
			z0 = (5*A-B-20000)/8;
			if(avalia(sum-z0, z0) == B)
				cout << pavalia(z0) << endl; // caso 4
			else {
				z0 = (5*A-B)/10;
				if(avalia(sum-z0, z0) == B)
					cout << pavalia(z0) << endl; // caso 5
				else {
					z0 = (7*A-B-2000500)/12;
					if(avalia(sum-z0, z0) == B)
						cout << pavalia( z0 ) << endl; // caso 6
					else
						cout << pavalia( (5*A-B-20100)/7 ) << endl; // caso 8
				}
			}
		}
		else {
			// casos 6 ou 7 || 9 ou 10
			z0=(7*A-B-2000500)/12;
			if(avalia(sum-z0, z0) == B)
				cout << pavalia(z0) << endl; // caso 6
			else {
				z0 = (7*A-B)/14;
				if(avalia(sum-z0, z0) == B)
					cout << pavalia( z0 ) << endl; // caso 7
				else {
					z0 = (7*A-B-2020500)/10;
					if(avalia(sum-z0, z0) == B)
						cout << pavalia( z0 ) << endl; // caso 9
					else
						cout << pavalia( (7*A-B-2020600)/9 ) << endl; // caso 10
				}
			}
		}
	}
	return 0;
}
