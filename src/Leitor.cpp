
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

#include "Leitor.h"
#include "Excecao.h"

using namespace std;

long Leitor::num_leitores {0};

/** @file
 *
 * @brief Source das funcoes de Leitor.
 *
 * Se uma funcao relacionada com leitores nao estiver nos ficheiros biblio, esta aqui.
 **/

Leitor::Leitor(long id, string nom, long tel, string eml, vector<Emprestimo*> ep_lt, bool ct):
		 Object {id}, nome {nom}, telefone {tel}, email {eml}, emprestimos_leitor {ep_lt} {if (ct) num_leitores++;}
Leitor::Leitor(string nom, long tel, string eml, vector<Emprestimo*> ep_lt, bool ct): Object {num_leitores+1},
		nome {nom}, telefone {tel}, email {eml}, emprestimos_leitor {ep_lt} {if (ct) num_leitores++;}
Leitor::Leitor(long id, string nom, long tel, string eml, bool ct):
				 Object {id}, nome {nom}, telefone {tel}, email {eml}, emprestimos_leitor {} {if (ct) num_leitores++;}
Leitor::Leitor(string nom, long tel, string eml, bool ct): Object {num_leitores+1},
				nome {nom}, telefone {tel}, email {eml}, emprestimos_leitor {} {if (ct) num_leitores++;}

void Leitor::adiciona_emp_leit(Emprestimo* ep) {
	emprestimos_leitor.push_back(ep);
}

bool Leitor::remove_emp_leit(long id) {
	for (vector<Emprestimo*>::const_iterator it = emprestimos_leitor.begin(); it != emprestimos_leitor.end();it++) {
		if ((*it)->get_ID() == id) {
			emprestimos_leitor.erase(it);
			return true;
		}
	}
	throw Object_nao_existe(id);
}

vector<Emprestimo*> Leitor::get_emp_leit() {
	return emprestimos_leitor;
}

string Leitor::get_nome() {
	return nome;
}

long Leitor::get_telefone() {
	return telefone;
}

string Leitor::get_email() {
	return email;
}

void Leitor::set_nome(string nom) {
	nome = nom;
}

void Leitor::set_telefone(long tel) {
	telefone = tel;
}

void Leitor::set_email(string eml) {
	email = eml;
}

string Leitor::imprime() {
	stringstream out {};
	out << "ID: "<< get_ID() << endl<< "Nome: " << nome << endl << "Telefone: "<< telefone << endl
			<< "Email: " << email << endl << "ID Emprestimos: ";
	for (vector<Emprestimo*>::const_iterator it = emprestimos_leitor.begin(); it != emprestimos_leitor.end(); it++) {
		out << (*it)->get_ID() << "; ";
	}
	out << endl;
	return out.str();
}

void Leitor::escreve(string ficheiro) {
	stringstream out {};
	out << get_ID() << endl
			<< nome << endl
			<< telefone << endl
			<< email << endl;
	for (vector<Emprestimo*>::const_iterator it = emprestimos_leitor.begin(); it != emprestimos_leitor.end(); it++) {
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

string Leitor::imprime_emp_leit() {
	stringstream out {};
	for (vector<Emprestimo*>::const_iterator it = emprestimos_leitor.begin(); it != emprestimos_leitor.end(); it++) {
		out << (*it)->imprime();
	}
	return out.str();
}

vector<Emprestimo*> Leitor::get_emprestimos_atrasados() {
	vector<Emprestimo*> atrasados {};
	for (vector<Emprestimo*>::const_iterator it = emprestimos_leitor.begin(); it != emprestimos_leitor.end(); it++) {
		if ((*it)->get_atraso() > 0) {
			atrasados.push_back(*it);
		}
	}
	return atrasados;
}
