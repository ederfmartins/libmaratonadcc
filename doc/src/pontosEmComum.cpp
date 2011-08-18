bool seg_intersect(point p, point q, point r, point s)
{
	point A = q - p;
	point B = s - r;
	point C = r - p;
	point D = s - q;

	int a = cmp(A % C) + 2 * cmp(A % D);
	int b = cmp(B % C) + 2 * cmp(B % D);

	if (a == 3 || a == -3 || b == 3 || b == -3) return false;
	if (a || b || p == r || p == s || q == r || q == s) return true;

	int t = (p < r) + (p < s) + (q < r) + (q < s);
	return t != 0 && t != 4;
}
