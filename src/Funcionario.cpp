
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Funcionario.h"
#include "Excecao.h"

using namespace std;

long Funcionario::num_funcionarios {0};

/** @file
 *
 * @brief Source das funcoes de Funcionario.
 *
 * Se uma funcao relacionada com funcionarios nao estiver nos ficheiros biblio, esta aqui.
 **/

Funcionario::Funcionario(long id, string nom, bool ct): Object {id}, nome {nom} {if (ct) num_funcionarios++;}
Funcionario::Funcionario(string nom, bool ct): Object {num_funcionarios+1}, nome {nom} {if (ct) num_funcionarios++;}

string Funcionario::get_nome() {
	return nome;
}

string Funcionario::imprime() {
	stringstream out {};
	out << "ID: "<< get_ID() << endl
			<< "Nome: " << nome << endl;
	return out.str();
}

void Funcionario::escreve(string ficheiro) {
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
