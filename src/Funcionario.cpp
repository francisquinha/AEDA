
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Funcionario.h"

using namespace std;

long Funcionario::num_funcionarios{0};

// construtor Funcionario
Funcionario::Funcionario(long id, string nom): Object{id}, nome{nom}{}
Funcionario::Funcionario(string nom): Object{num_funcionarios+1}, nome{nom}{num_funcionarios++;}

// obter nome
string Funcionario::get_nome() {
	return nome;
}

// establecer nome
void Funcionario::set_nome(string nom) {
	nome = nom;
}

// imprimir Funcionario
string Funcionario::imprime(){
	stringstream out{};
	out << "ID: "<< get_ID() << endl
			<< "Nome: " << nome << endl;
	return out.str();
}

// escrever Funcionario
void Funcionario::escreve(){
	stringstream out{};
	out << get_ID() << endl
			<< nome << endl;
	ofstream myfile ("Funcionario.txt",ios::app);
	if (myfile.is_open()){
		myfile << out.str();
		myfile.close();
	}
	else cout << "Unable to open file";
}
