
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

#include "Supervisor.h"
#include "Excecao.h"

using namespace std;

/** @file
 *
 * @brief Source das funcoes de Supervisor.
 *
 * As funcoes relacionadas com supervisores, nao estando nos ficheiros Biblio ou Funcionario, estao aqui.
 **/

Supervisor::Supervisor(unsigned long id, string nom, vector<Funcionario*> func_sup,
                       bool ct = false):
				Funcionario {nom, ct, id}, funcionarios_sup {func_sup} {}

vector<Funcionario*> Supervisor::get_func_sup() {
	return funcionarios_sup;
}

void Supervisor::set_func_sup(vector<Funcionario*> func_sup) {
	funcionarios_sup=func_sup;
}

void Supervisor::adiciona_func_sup(Funcionario* fc) {
	funcionarios_sup.push_back(fc);
}

string Supervisor::imprime() {
	stringstream out {};
	out << "ID: "<< get_ID() << endl
			<< "Nome: " << get_nome() << endl
			<< "ID Funcionarios: ";
	for (vector<Funcionario*>::const_iterator it = funcionarios_sup.begin(); it != funcionarios_sup.end(); it++) {
		out << (*it)->get_ID() << "; ";
	}
	out << endl;
	return out.str();
}

void Supervisor::escreve(string ficheiro) {
	stringstream out {};
	out << get_ID() << endl
			<< get_nome() << endl;
	for (vector<Funcionario*>::const_iterator it = funcionarios_sup.begin(); it != funcionarios_sup.end(); it++) {
		out << (*it)->get_ID() << ";";
	}
	out << endl;
	ofstream myfile (ficheiro, ios::app);
	if (myfile.is_open()) {
		myfile << out.str();
		myfile.close();
	}
	else throw Ficheiro_indisponivel(ficheiro);
}
