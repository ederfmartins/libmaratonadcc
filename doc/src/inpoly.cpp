int in_poly(point p, polygon& T)
{
	double a = 0;
	int N = T.size();
	for (int i = 0; i < N; i++)
	{
		if (between(T[i], p, T[(i+1) % N])) return -1;
		a += angle(T[i], p, T[(i+1) % N]);
	}
	return cmp(a) != 0;
}
