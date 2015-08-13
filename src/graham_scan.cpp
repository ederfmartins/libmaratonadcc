#define INF 1e9
#define EPS 1e-9

int cmp(double a, double b = 0.0) {
	return a+EPS < b ? -1 : a-EPS > b;
}

struct Point {
	double x, y;
	Point(double a=0.0,double b=0.0){x=a,y=b;}
	Point operator+(const Point &P) const {return Point(x+P.x,y+P.y);}
	Point operator-(const Point &P) const {return Point(x-P.x,y-P.y);}
	Point operator*(double c) const {return Point(x*c,y*c);}
	Point operator/(double c) const {return Point(x/c,y/c);}
	double operator!() const {return sqrt(x*x+y*y);}
	bool operator==(const Point &p) const {return !cmp(x,p.x) && !cmp(y,p.y);}
	bool operator<(const Point &p) const {if (cmp(x,p.x)) return cmp(x,p.x) < 0; return cmp(y,p.y) < 0;}
	void print(string prefix = "") const {printf("%s%.3lf %.3lf\n",prefix.c_str(),x,y);}
};

typedef vector<Point> Polygon;

double cross(Point A, Point B) {
	return A.x*B.y - B.x*A.y;
}

Point pmin;

bool lessThan(Point A, Point B) {
	if (cmp(cross(A-pmin,B-pmin))) return cmp(cross(A-pmin,B-pmin)) > 0;
	return cmp(!(pmin-A),!(pmin-B)) < 0;
}

int sort(Polygon &p) {
	int imin = 0, i, j, n = p.size();
	
	for (i=1; i < p.size(); i++) {
		if (p[i] <  p[imin]) imin = i;
	}
	
	swap(p[0],p[imin]);
	pmin = p[0];
	
	sort(p.begin()+1,p.end(),lessThan);
	
	for (i=n-1; i > 0 && !cmp(cross(p[i]-p[0],p[i-1]-p[0])); i--);
	if (i == 0) return 1;
	for (j=0; j < (n-i)/2; j++) swap(p[i+j],p[n-j-1]);
	return 0;
}

Polygon convex_hull(Polygon &p) { // tirar o & para nao alterar o poligono original
	int hs = 2, n = p.size();
	Polygon hull;
	
	if (p.size() < 3) return p;
	
	int isline = sort(p);
	hull.push_back(p[0]), hull.push_back(p[1]);
	
	for (int i=2; i <= n-isline; i++) {
		while (hull.size() > 1 && cmp(cross(p[i%n]-hull[hs-1],hull[hs-2]-hull[hs-1])) <= 0) { // trocar o <= para < para manter pontos intermediarios
			hull.pop_back(), hs--;
		}
		if (i < n) hull.push_back(p[i]), hs++;
	}
	
	return hull;
}

int main() {
	Polygon p;

	while (...) {
		double x = ...;
		double y = ...;
		p.push_back(Point(x,y));
	}

	Polygon hull = convex_hull(p);

	for (int i=0; i < hull.size(); i++) {
		...
	}
	return 0;
}
