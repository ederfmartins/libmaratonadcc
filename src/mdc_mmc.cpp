int gcd(int x, int y)
{
	return y ? gcd(y, x % y) : abs(x);
}
uint64_t lcm(int x, int y)
{
	if (x && y) return abs(x) / gcd(x, y) * uint64_t(abs(y));
	else return uint64_t(abs(x | y));
}
