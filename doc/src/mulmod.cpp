long long mulmod(long long a, long long b, long long c)
{
	long long x = 0;
	long long y = a % c;
	while(b > 0)
	{
		if(b & 1ll) x = (x + y) % c;
		y = (y << 1) % c;
		b >>= 1;
	}
	return x % c;
}
