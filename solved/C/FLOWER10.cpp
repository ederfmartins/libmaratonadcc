#include <string>
#include <sstream>
#include <iostream>


using namespace std;


int main() {
	string linha;
	while(getline(cin, linha)) {
		stringstream separador(linha);
		string word;
		separador >> word;
		char first;
		if(word[0] == '*') return 0;
		else first=tolower(word[0]);
		bool res=true;
		while(separador >> word) {
			if(first != tolower(word[0])) {
				cout << "N\n";
				res=false;
				break;
			}
		}
		if(res) cout << "Y\n";
	}
	return 0;
}
