#include <iostream>
#include <vector>
#include <utility>
#include <list>


using namespace std;

int coords[1000][2];
int incid[1000][2];
int inciDist[1000][2];
char cores[1000];

int main() {
	int n;
	while(cin >> n) {
		if(!n) return 0;

		int N=n;
		while(N > 0) {
			N--;
			cin >> coords[N][0] >> coords[N][1];
			inciDist[N][0] = 1000, inciDist[N][1] = -1000;
			incid[N][0] = -1, incid[N][1] = -1;
			cores[N] = 0;
		}

		// Monta matincid
		for(int i=0; i < n-1; i++) {
			for(int j=i+1; j < n; j++) {
				int dx=coords[i][0]-coords[j][0], dy=coords[i][1]-coords[j][1];
				int dist=dx*dx+dy*dy;

				if(dist < inciDist[i][0] ||
					dist == inciDist[i][0] && (coords[j][0] < coords[ incid[i][0] ][0] ||
						(coords[j][0] == coords[ incid[i][0] ][0] && coords[j][1] < coords[ incid[i][0] ][1]) ) ) {
					// shift
					inciDist[i][1] = inciDist[i][0];
					incid[i][1] = incid[i][0];

					// save
					inciDist[i][0] = dist;
					incid[i][0] = j;
				}
				else if(dist < inciDist[i][1] ||
					dist == inciDist[i][1] && (coords[j][0] < coords[ incid[i][1] ][0] ||
						(coords[j][0] == coords[ incid[i][1] ][0] && coords[j][1] < coords[ incid[i][1] ][1]) ) ) {
					inciDist[i][1] = dist;
					incid[i][1] = j;
				}


				if(dist < inciDist[j][0] ||
					dist == inciDist[j][0] && (coords[i][0] < coords[ incid[j][0] ][0] ||
						(coords[i][0] == coords[ incid[j][0] ][0] && coords[i][1] < coords[ incid[j][0] ][1]) ) ) {
					// shift
					inciDist[j][1] = inciDist[j][0];
					incid[j][1] = incid[j][0];

					// save
					inciDist[j][0] = dist;
					incid[j][0] = i;
				}
				else if(dist < inciDist[j][1] ||
					dist == inciDist[j][1] && (coords[i][0] < coords[ incid[j][1] ][0] ||
						(coords[i][0] == coords[ incid[j][1] ][0] && coords[i][1] < coords[ incid[j][1] ][1]) ) ) {
					inciDist[j][1] = dist;
					incid[j][1] = i;
				}
			}
		}

		// Caminhada colorida
		list<int> largura;
		largura.push_front(0);
		while(largura.size()) {
			int cid = largura.front();
			largura.pop_front();
			cores[cid]=1;
			if(incid[cid][0] != -1 && !cores[incid[cid][0]]) largura.push_back(incid[cid][0]);
			if(incid[cid][1] != -1 && !cores[incid[cid][1]]) largura.push_back(incid[cid][1]);
		}

		bool hasSolution = true;
		for(int i=0; i < n; i++) {
			if(!cores[i]) {
				cout << "There are stations that are unreachable.\n";
				hasSolution = false;
				break;
			}
		}
		if(hasSolution) {
			cout << "All stations are reachable.\n";
		}
	}
	return 0;
}
