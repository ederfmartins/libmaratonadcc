#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

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

/// ******************************* ALGEBRA ******************************** ///
// Simplex
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

int main() {
	int n,m,g;
	int played[50][50];
	int r[50]; // Jogos restantes

	while(cin >> n >> m >> g) {
		if(!n) {
			return 0;
		}
		vector<pair<int,int> > placar(n);

		const int numJogos=(n-1)*m;
		for(int i=0; i < n; i++) {
			placar[i].first = 0, placar[i].second = i;
			r[i] = numJogos;
			for(int j=i+1; j < n; j++) {
				played[i][j]=0;
			}
		}

		// cria vet de pts
		int maior=-1;
		for(int jogo=0; jogo < g; jogo++) {
			char res;
			int i,j;
			cin >> i >> res >> j;
			switch(res) {
				case '=':
				placar[i].first++;
				placar[j].first++;
				break;
				case '>': // i ganha
				placar[i].first+=2;
				break;
				default: // j ganha
				placar[j].first+=2;
				break;
			}

			r[i]--, r[j]--;
			if(i>j) played[j][i]++;
			else played[i][j]++;

			if(i!=0 && maior < placar[i].first) maior = placar[i].first;
			if(j!=0 && maior < placar[j].first) maior = placar[j].first;
		}
		// da vitorias pra 0
		for(int i=1; i < n; i++) {
			int dif=(m-played[0][i]);
			if(dif) {
				placar[0].first+=2*(dif);
				r[i]-=(dif);
				played[0][i]+=(dif);
			}
		}
		// Se X <= placar maior -> N
		if(placar[0].first <= maior) {
			cout << "N\n";
		} else {
			sort(placar.begin(), placar.end());

			// Pivota placar
			int v=-1,d=-1;
			for(int i=0; i < n-1; i++) {
				if(placar[i].first+r[ placar[i].second ] < placar[n-1].first-1) {
					v = i;
				}
				else {
					break;
				}
			}
			for(int i=v+1; i < n-1; i++) {
				if(placar[i].first+r[ placar[i].second ] > placar[n-1].first-1) {
					d = i;
					break;
				}
			}

			if(d == -1) {
				cout << "Y\n";
			} else if(v == -1) {
				cout << "N\n";
			}else {
				// Conta qt de arestas
				vector<double> verticesI;
				vector<vector<double> > A;
				vector<double> b;
				vector<pair<int, int> > arestas;
				for(int i=d; i < n-1; i++) {
					for(int j=0; j <= v; j++) {
						int max,min;
						if(placar[i].second > placar[j].second) {
							max=placar[i].second;
							min=placar[j].second;
						} else {
							max=placar[j].second;
							min=placar[i].second;
						}
						if(played[min][max] < m) {
							arestas.push_back(make_pair(placar[i].second, placar[j].second));
							verticesI.push_back(0); // Ao fim, verticesI vai ter tantos elementos quantos vertices houverem
							b.push_back(m-played[min][max]);
						}
					}
				}
				if(!verticesI.size()) {
					cout << "N\n";
					continue;
				}
				verticesI[0]=1; int k=0;

				while(A.size() < b.size()-1) {
					A.push_back(verticesI); verticesI[k++]=0;verticesI[k]=1;
				}
				A.push_back(verticesI);

				int nedges = A.size();
				// Prossegue a montagem do tableau
				vector<double> c(nedges, 1);

				// no derrotas=somatorio dos vertices
				int posl=0;set<int> destinos;
				for(int i = d; i < n-1; i++) {
					vector<double> curlinha(nedges);
					for(int k=0; k < posl; k++) {
						curlinha[k] = 0;
					}
					for(int j=0; j <= v; j++) {
						int max,min;
						if(placar[i].second > placar[j].second) {
							max=placar[i].second;
							min=placar[j].second;
						} else {
							max=placar[j].second;
							min=placar[i].second;
						}
						if(played[min][max] < m) {
							destinos.insert(placar[j].second);
							curlinha[posl++] = 1;
						}
					}
					for(int k=posl+1; k < nedges; k++) {
						curlinha[k] = 0;
					}
					A.push_back(curlinha);
					b.push_back(r[i]-(placar[n-1].first-1 - placar[i].first) );
				}
				// Fecha igualdade (repete a e b com valores negativados)
				int len=A.size(), last=len;
				for(int i=nedges; i < len; i++) {
					A.push_back(A[i]);
					for(int j=0; j < A[last].size(); j++ ) {
						A[last][j] = -A[last][j];
					}
					last++;
					b.push_back(-b[i]);
				}
				// Restricoes de vitorias
				for(set<int>::iterator i=destinos.begin(); i != destinos.end(); i++) {
					vector<double> curlinha(arestas.size(), 0);
					for(int j=0; j < arestas.size(); j++) {
						if(*i == arestas[j].second) {
							curlinha[j] = 1;
						}
					}
					A.push_back(curlinha);
					int vitorias = (placar[n-1].first-placar[*i].first-1)/2;
					b.push_back(vitorias > r[*i] ? r[*i] : vitorias);
				}

				// Ufa! Soh rodar o simplex agora
				simplex sim(A,b,c);
				vector<double> s = sim.solve();
				if(!s.size()) cout << "N\n";
				else cout << "Y\n";
			}
		}
	}
	return 0;
}

