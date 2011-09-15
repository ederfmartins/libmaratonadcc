/**
 * -1 se x < y
 * 0 se x = y
 * 1 se x > y
 */
const double EPS = 1e-10;
#define _inline(f...) f() __attribute__((always_inline)); f
_inline(int cmp)(double x, double y = 0, double tol = EPS)
{
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

