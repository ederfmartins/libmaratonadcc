#include <stdio.h>
#include <math.h>

#include <iostream>
#include <iomanip>
using namespace std;

double round(double x, int decimalDigits)
{
	double d, exp = pow(10, decimalDigits);
	d = floor(x * exp)*10;
	x = floor(x * (exp + 1));
	if (x - d >= 5) d += 10;
	return d /(exp+1);

  //return floor( value + 0.5 );
}

int main ()
{
	cout << fixed << setprecision(2) << 9.05690901 << endl;

  printf ("floor of 2.3 is %.1lf\n", floor (2.3) );
  printf ("floor of 3.8 is %.1lf\n", floor (3.8) );
  printf ("floor of -2.3 is %.1lf\n", floor (-2.3) );
  printf ("floor of -3.8 is %.1lf\n", floor (-3.8) );
  printf ("ceil of 2.3 is %.1lf\n", ceil (2.3) );
  printf ("ceil of 3.8 is %.1lf\n", ceil (3.8) );
  printf ("ceil of -2.3 is %.1lf\n", ceil (-2.3) );
  printf ("ceil of -3.8 is %.1lf\n", ceil (-3.8) );


  printf ("round of 2.3 is %.1lf\n", round (2.3, 1) );
  printf ("round of 3.8 is %.1lf\n", round (3.8) );
  printf ("round of -2.3 is %.1lf\n", round (-2.3) );
  printf ("round of -3.8 is %.1lf\n", round (-3.8) );
  return 0;
}
/*floor of 2.3 is 2.0
floor of 3.8 is 3.0
floor of -2.3 is -3.0
floor of -3.8 is -4.0
ceil of 2.3 is 3.0
ceil of 3.8 is 4.0
ceil of -2.3 is -2.0
ceil of -3.8 is -3.0*/

