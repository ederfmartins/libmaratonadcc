#include <iostream>
#include <iomanip> // setprecision()
using namespace std;

int main () {
  double a = 3.1415926534;
  double b = 2006.0;
  double c = 1.0e-10;

  // setprecision(1) => 1 casa decimal apos a virgula
  cout << fixed << setprecision(1) << 9.09090901 << endl;
  cout << fixed << setprecision(2) << 9.09090901 << endl;
  cout << fixed << setprecision(3) << 9.09090901 << endl;
  cout << fixed << setprecision(2) << 9.1 << endl;

  // anula o efeito de setprecision
  cout.unsetf(ios::floatfield);

  // 5 digitos no maximo
  cout.precision(5);

  cout << a << '\t' << b << '\t' << c << endl;
  cout << fixed << a << '\t' << b << '\t' << c << endl;
  cout << scientific << a << '\t' << b << '\t' << c << endl;

  // Sets the basefield format flag for the str stream to dec, hex or oct.
  int n =70;
  cout << dec << n << endl;
  cout << hex << n << endl;
  cout << oct << n << endl;

  return 0;
}
/* output
9.1
9.09
9.091
9.10
3.1416  2006    1e-10
3.14159 2006.00000      0.00000
3.14159e+00     2.00600e+03     1.00000e-10
70
46
106
*/

