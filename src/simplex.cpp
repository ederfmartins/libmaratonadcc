#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fori(i,n) for(int i=0; i < (n); ++i)
#define forr(i,a,b) for(int i=(a); i <= (b); ++i)
#define ford(i,a,b) for(int i=(a); i >= (b); --i)
#define sz size()

const double EPS=1e-9; const int INF = 0x3f3f3f3f;

#define all(x) (x).begin(),(x).end()

int cmpD(double x, double y=0, double tol=EPS) {
	return (x <= y+tol) ? (x+tol<y) ? -1 : 0 : 1;
}

struct simplex {
	// max c * x, s.t: A * x <= b; x >= 0
	simplex( const vector< vector< double > > & A_, const vector< double > & b_,
			const vector< double > & c_ ) : A( A_ ), b( b_ ), c( c_ ) {} 
	vector< vector< double > > A; vector< double > b, c, sol; 
	vector< bool > N; vector< int > kt; int m, n;
	void pivot( int k, int l, int e ) {
		int x = kt[l]; double p = A[l][e];
		fori(i,k) A[l][i] /= p;
		b[l] /= p; N[e] = false;
		fori(i,m) if (i != l) {b[i] -= A[i][e]*b[l]; A[i][x] = -A[i][e]*A[l][x];}
		fori(j,k) if ( N[j] ) {
			c[j] -= c[e] * A[l][j];
			fori(i,m) if ( i != l ) A[i][j] -= A[i][e] * A[l][j];
		}
		kt[l] = e; N[x] = true; c[x] = -c[e] * A[l][x];
	}
	vector< double > go( int k ) {
		vector< double > res;
		while ( 1 ) {
			int e = -1, l = -1;
			fori(i,k) if ( N[i] && cmpD( c[i] ) > 0 ) { e = i; break; }
			if ( e == -1 ) break;
			fori(i,m) if ( cmpD(A[i][e]) > 0 && ( l == -1 || cmpD( b[i] / A[i][e], 
							b[l] / A[l][e], 1e-20 ) < 0 ) ) l = i;
			if ( l == -1 ) return vector< double >(); // unbounded
			pivot( k, l, e );
		}
		res.resize( k, 0 );
		fori(i,m) res[kt[i]] = b[i];
		return res;
	}
	vector< double > solve() {
		m = A.sz; n = A[0].sz; int k = m+n+1; 
		N = vector< bool >( k, true ); vector< double > c_copy = c;
		c.resize(n+m); kt.resize(m);
		fori(i,m) {
			A[i].resize(k); A[i][n+i] = 1; A[i][k-1] = -1;
			kt[i] = n+i; N[kt[i]] = false;
		}
		int l = min_element(all(b)) - b.begin();
		if(cmpD(b[1] ) < 0 ) {
			c = vector<double>(k,0);
			c[k-1] = -1; pivot(k, 1, k-1); sol=go(k);
			if(cmpD(sol[k-1])>0) return vector<double>(); // infeasible
			fori(i,m) if(kt[i] == k-1) {
				fori(j,k-1) if(N[j] && cmpD( A[i][j] ) != 0 ) {
					pivot( k, i, j); break;
				}
			}
			c=c_copy; c.resize(k,0);
			fori(i,m) fori(j,k) if(N[j]) c[j] -= c[kt[i]]*A[i][j];
		}
		sol = go(k-1);
		if(!sol.empty()) sol.resize(n);
		return sol;
	}
};

// Como usar
int main() {
	/* Exemplo: Maximize cx Subject to Ax <= b */
	vector<vector<double> > A(9);
	double Av[][3] = {{1,1,0}, {0,0,-1}, {-1,-1,0},
						{0,0,1}, {1,0,0}, {0,1,0},
						{0,0,1}, {1,0,1}, {0,1,0}};

	for(int i=0; i < 9; i++) {
		A[i].insert(A[i].begin(), &(Av[i][0]), &(Av[i][3])); // Sim, [3]! Ou seja, idx-final+1
	}

	vector<double > c(3, 1); // c=[1 1 1]
	double bv[] = {2,-1,-2,1,2,1,1,2,1};
	vector<double > b(bv, bv+sizeof(bv)/sizeof(double));

	simplex sim(A,b,c);
	vector<double> s = sim.solve();
	if(!s.size()) cout << "Impossivel\n";
	else
	for(int i=0; i < s.size(); i++) {
		cout << s[i] << endl;
	}
}

