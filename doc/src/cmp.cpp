const double EPS = 1e-10;
/**
 * -1 se x < y
 * 0 se x = y
 * 1 se x > y
 */
inline int cmp (double x, double y = 0, double tol = EPS)
{
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

