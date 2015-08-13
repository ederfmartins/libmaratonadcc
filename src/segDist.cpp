double seg_distance(point p, point q, point r)
{
	point A = r - q;
	point B = r - p;
	point C = q - p;

	double a = A * A, b = B * B, c = C * C;

	if (cmp(b, a + c) >= 0) return sqrt(a);
	else if (cmp(a, b + c) >= 0) return sqrt(b);
	else return fabs(A % B) / sqrt(c);
}
