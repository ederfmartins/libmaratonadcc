struct point
{
	double x, y;
	double z; // para pontos no espaco
	point(double x = 0, double y = 0, double z = 0): x(x), y(y), z(z) {}

	point operator +(point q) { return point(x + q.x, y + q.y, z + q.z); }
	point operator -(point q) { return point(x - q.x, y - q.y, z - q.z); }
	point operator *(double t) { return point(x * t, y * t, z * t); }
	point operator /(double t) { return point(x / t, y / t, z / t); }
	double operator *(point q) { return x * q.x + y * q.y + z * q.z; }
	point vec(point q) { return point(y * q.z - z * q.y, z * q.x - x * q.z, x * q.y - y * q.x); }
	double operator %(point q) { return x * q.y - y * q.x; }

	int cmp(point q) const
	{
		if (int t = ::cmp(x, q.x)) return t;
		else if (int t = ::cmp(y, q.y)) return t;
		return ::cmp(z, q.z);
	}

	bool operator ==(point q) const { return cmp(q) == 0; }
	bool operator !=(point q) const { return cmp(q) != 0; }
	bool operator < (point q) const { return cmp(q) < 0; }

	friend ostream& operator <<(ostream& o, point p) {
	  return o << "(" << p.x << ", " << p.y << ", " << p.z << ")";
	}
	static point pivot;
};

// para pontos 2D
double abs(point p) { return hypot(p.x, p.y); }
double arg(point p) { return atan2(p.y, p.x); }

point point::pivot;

typedef vector<point> polygon;

int ccw(point p, point q, point r) 
{
	return cmp((p - r) % (q - r));
}

double angle(point p, point q, point r)
{
	point u = p - q, v = r - q;
	return atan2(u % v, u * v);
}
