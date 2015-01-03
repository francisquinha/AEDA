
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Funcionario.h"
#include "Excecao.h"

using namespace std;

unsigned long Funcionario::num_funcionarios {0};

/** @file
 *
 * @brief Source das funcoes de Funcionario.
 *
 * Se uma funcao relacionada com funcionarios nao estiver nos ficheiros biblio, esta aqui.
 **/

Funcionario::Funcionario(string nom, bool ct, unsigned long id): Object {id}, nome {nom} {if (ct) num_funcionarios++;}

string Funcionario::get_nome() const {
	return nome;
}

string Funcionario::imprime() const {
	stringstream out {};
	out << "ID: "<< get_ID() << endl
			<< "Nome: " << nome << endl;
	return out.str();
}

void Funcionario::escreve(const string ficheiro) const {
	stringstream out {};
	out << get_ID() << endl
			<< nome << endl;
	ofstream myfile (ficheiro, ios::app);
	if (myfile.is_open()) {
		myfile << out.str();
		myfile.close();
	}
	else throw Ficheiro_indisponivel(ficheiro);
}
