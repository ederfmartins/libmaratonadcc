#include <string>
#include <sstream>
#include <iostream>


using namespace std;


int main() {
	string linha="Olah mundo";
	stringstream separador(linha); // Tokenizador
	string word;
	separador >> word; // word=Olah
	char mu[4];
	separador.readsome(mu, 3); // Le " mu" (inclui espaco)
	cout << separador.tellg() << endl; // 7 (posicao de leitura)
	cout << separador.tellp() << endl; // 0, posicao de escrita

	separador.seekp(separador.str().size());
	separador << " cruel"; // separador = "Olah mundo cruel"

	separador.seekp(5);
	separador << "doido"; // separador = "Olah doido cruel" (sobrescrito)
	return 0;
}
