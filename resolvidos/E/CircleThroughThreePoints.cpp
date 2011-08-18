#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 Problema 190 da uva.
*/

#define abs(a) ((a) >= 0 ? (a) : (a) =-(a))

using namespace std;
double arredonda(double n, int s)
{
	double x = 1;
	
	for(int i = 0; i < s; i++) x *= 10;
	return ((long int)(n * x * 10)) - ((long int)(n * x))*10 > 4 ? ((long int)(n * x) + 1)/x : ((long int)(n * x))/x;
}

/*
	x^2 + y^2 + c*x + d*y + e = 0
	-(x^2 + y^2) = c*x + d*y + e

	c*x1 + d*y1 + e = -(x1^2 + y1^2) 
	c*x2 + d*y2 + e = -(x2^2 + y2^2)
	c*x3 + d*y3 + e = -(x3^2 + y3^2)

	det = x1*y2 + x2*y3 + x3*y1 - y2*x3 - y3*x1 - y1*x2
	x1 y1 1
	x2 y2 1
	x3 y3 1
	...
*/

int main(int argc, char* argv[])
{
	double det, v1, v2, v3;
	double x1, y1, x2, y2, x3, y3;
	double c, d, e, h, k, r2;

	while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3)
	{
		// resolve sistema linear...
		v1 = -(x1*x1 + y1*y1);
		v2 = -(x2*x2 + y2*y2);
		v3 = -(x3*x3 + y3*y3);
		det = x1*y2 + x2*y3 + x3*y1 - y2*x3 - y3*x1 - y1*x2;

		if (det != 0)
		{
			c = v1*y2 + v2*y3 + v3*y1 - y2*v3 - y3*v1 - y1*v2;
			d = x1*v2 + x2*v3 + x3*v1 - v2*x3 - v3*x1 - v1*x2;
			e = x1*y2*v3 + x2*y3*v1 + x3*y1*v2 - y2*x3*v1 - y3*x1*v2 - y1*x2*v3;

			c /= det; d /= det; e /= det;

			// acha equacao
			h = c/2;
			k = d/2;
			r2 = h*h + k*k - e; // e = h2 + k2 - r2

			// imprime
			char sign1 = h > 0 ? '+':'-';
			char sign2 = k > 0 ? '+':'-';
			char sign3 = e > 0 ? '+':'-';

			abs(h); abs(k); abs(r2);
			abs(c); abs(d); abs(e);

			h = arredonda(h, 3); k = arredonda(k, 3); r2 = arredonda(sqrt(r2), 3);
			c = arredonda(c, 3); d = arredonda(d, 3); e = arredonda(e, 3);

			cout.precision(3);

			if (h == 0) cout << "x^2";
			else cout << "(x " << sign1 << " " << fixed << h << ")^2";

			if (k == 0) cout << " + y^2 = " << fixed << r2 << "^2" << endl;
			else cout << " + (y " << sign2 << " " << fixed << k << ")^2 = " << fixed << r2 << "^2" << endl;

			cout << "x^2 + y^2 ";

			if (c != 0) cout << sign1 << " " << fixed << c << "x ";
			if (d != 0) cout << sign2 << " " << fixed << d << "y ";
			if (e != 0) cout << sign3 << " " << fixed << e;

			cout << " = 0" << endl << endl;

	
			//cout << "(x " << sign1 << " " << fixed << h << ")^2 + (y " << sign2 << " " << fixed << k << ")^2 = " << fixed << r2 << "^2" << endl;
			//cout << "x^2 + y^2 " << sign1 << " " << fixed << c << "x " << sign2 << " " << fixed << d << "y " << sign3 << " " << fixed << e << " = 0" << endl << endl;
		}
	}

	return 0;
}
