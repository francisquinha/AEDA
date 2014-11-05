#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "Administrador.h"
#include "Excecao.h"

using namespace std;

// construtor Administrador
Administrador::Administrador(long id, string nom): Funcionario {id, nom} {}

// escrever Funcionario
void Administrador::escreve(string ficheiro_fc, string ficheiro_sp) {
	stringstream out {};
	ofstream myfile (ficheiro_fc, ios::app);
	if (myfile.is_open()) {
		myfile << out.str();
		myfile.close();
	}
	else throw Ficheiro_indisponivel(ficheiro_fc);
}



