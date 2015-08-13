#include <map>
#include <string>
#include <cstdio>

using namespace std; // USE ISTO!!!

class Comparadora;

class Pessoa {
	int idade;
	string nome;
	friend class Comparadora;
public:
	Pessoa(string nome, int idade) {
		this->idade = idade;
		this->nome = nome;
	}
	void print() const {
		printf("Nome: %s Idade: %d\n", nome.c_str(), idade);
	}
};

class Comparadora { // Ordena crescentemente
public: // <- IMPORTANTE
	bool operator() (const Pessoa &a, const Pessoa &b)
	{
		int idDif = a.idade-b.idade;
		if(idDif < 0) return true;
		else if(idDif==0) return a.nome.compare(b.nome) < 0 ? true : false;
		else return false;
	}
};

int main() {
	Pessoa r("Rangelz", 86);
	Pessoa r2("Rangelzao", 86);
	
	map<Pessoa, string, Comparadora> alunos;
	alunos[r]="UFMG";
	alunos[r2]="PUC";
	// Iterator
	for(map<Pessoa, string, Comparadora>::iterator it=alunos.begin(); it != alunos.end(); it++) {
		it->first.print();
		printf("\t%s\n\n", it->second.c_str());
	}
	// Find
	if(alunos.find(Pessoa("Rangelz", 86)) != alunos.end()) { // Achou!
		printf("Achei Rangel!\n");
	}
	return 0;
}
