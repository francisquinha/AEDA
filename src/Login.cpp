#include <fstream>
#include <iostream>
#include <sstream>

#include "Login.h"
#include "Excecao.h"

using namespace std;

/** @file
 *
 * @brief Source das funcoes de Utilizador
 *
 * Se uma funcao relacionada com utilizadores nao estiver nos ficheiros biblio, esta aqui.
 **/

// Construtor de utilizador; parametros: id, password e acesso
Utilizador::Utilizador(long id, std::string pass, int acess): Object {id}, password {pass}, acesso {acess} {}

// obter password do utilizador; retorno: password
string Utilizador::get_password() {
	return password;
}

// determinar password do utilizador; parametros: password
void Utilizador::set_password(std::string pass) {
	password = pass;
}

// obter tipo de acesso do utilizador; retorno: acesso
int Utilizador::get_acesso() {
	return acesso;
}

// determinar tipo de acesso do utilizador; parametros: acesso
void Utilizador::set_acesso(int acess) {
	acesso = acess;
}

// escreve utilizador num ficheiro; parametros: string com nome do ficheiro
void Utilizador::escreve(std::string ficheiro) {
	stringstream out {};
	out << get_ID() << endl
			<< password << endl
			<< acesso << endl;
	ofstream myfile (ficheiro, ios::app);
	if (myfile.is_open()) {
		myfile << out.str();
		myfile.close();
	}
	else throw Ficheiro_indisponivel(ficheiro);
}

// imprime utilizador
string Utilizador::imprime() {
	stringstream out {};
	out << "ID: " << get_ID() << endl
			<< "Nivel de acesso: " << acesso << endl;
	return out.str();
}
