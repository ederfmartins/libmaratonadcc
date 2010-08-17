bool between(point p, point q, point r)
{
	return ccw(p, q, r) == 0 && cmp((p - q) * (r - q)) <= 0;
}
