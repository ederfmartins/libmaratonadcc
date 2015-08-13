#include <stdio.h>
#include <string>
#include <string.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
map<string, int> cartas;
	cartas["4C"] = 1;
	cartas["4E"] = 2;
	cartas["4O"] = 3;

	cartas["5C"] = 4;
	cartas["5E"] = 5;
	cartas["5O"] = 6;
	cartas["5P"] = 7;

	cartas["6C"] = 8;
	cartas["6E"] = 9;
	cartas["6O"] = 10;
	cartas["6P"] = 11;

	cartas["7E"] = 12;
	cartas["7P"] = 13;

	cartas["QC"] = 14;
	cartas["QE"] = 15;
	cartas["QO"] = 16;
	cartas["QP"] = 17;

	cartas["JC"] = 18;
	cartas["JE"] = 19;
	cartas["JO"] = 20;
	cartas["JP"] = 21;

	cartas["KC"] = 22;
	cartas["KE"] = 23;
	cartas["KO"] = 24;
	cartas["KP"] = 25;

	cartas["AC"] = 26;
	cartas["AO"] = 27;
	cartas["AP"] = 28;

	cartas["2C"] = 29;
	cartas["2E"] = 30;
	cartas["2O"] = 31;
	cartas["2P"] = 32;

	cartas["3C"] = 33;
	cartas["3E"] = 34;
	cartas["3O"] = 35;
	cartas["3P"] = 36;

	cartas["7O"] = 37;
	cartas["AE"] = 38;
	cartas["7C"] = 39;
	cartas["4P"] = 40;

	int n;
	string tmp, atual;
	cin >> n;
	while(n != 0){
		vector <pair<int, string> > mao;
		for (int i = 0; i < 3; i++){
			cin >> tmp;
			mao.push_back(make_pair(cartas[tmp], tmp));
		}
		for (int i = 0; i < 3; i++){
			pair <int, string> menorQueVence = make_pair(50, "bbabab");
			pair <int, string> menorAll = make_pair(50, "ccccccc");
			cin >> atual;
			int valorAtual = cartas[atual];
			//cout << valorAtual << endl;
			for (int j = 0; j < (3-i); j++){
				if (mao[j].first > valorAtual){
					if (mao[j].first < menorQueVence.first)
						menorQueVence = mao[j];
				}else{
					if (mao[j].first < menorAll.first)
						menorAll = mao[j];
				}
			}
			if (menorQueVence.first == 50){ // PERDEU
				cout << menorAll.second  << endl;
				for (vector <pair<int, string> >::iterator j = mao.begin(); j != mao.end(); ++j){
					if (j->first == menorAll.first){ mao.erase(j); break;}
				}
			}else{
				cout << menorQueVence.second << endl;
				for (vector <pair<int, string> >::iterator j = mao.begin(); j != mao.end(); ++j){
					if (j->first == menorQueVence.first){ mao.erase(j); break;}
				}
			}
		}	
		n--;
	}

	return 0;
}
