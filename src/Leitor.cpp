
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

#include "Leitor.h"
#include "Excecao.h"

using namespace std;

long Leitor::num_leitores {0};

// construtor Leitor
vector<Emprestimo*> ep_lt {};
Leitor::Leitor(long id, string nom, long tel, string eml, vector<Emprestimo*> ep_lt):
		 Object {id}, nome {nom}, telefone {tel}, email {eml}, emprestimos_leitor {ep_lt} {num_leitores++;}
Leitor::Leitor(string nom, long tel, string eml, vector<Emprestimo*> ep_lt): Object {num_leitores+1},
		nome {nom}, telefone {tel}, email {eml}, emprestimos_leitor {ep_lt} {num_leitores++;}
Leitor::Leitor(long id, string nom, long tel, string eml):
				 Object {id}, nome {nom}, telefone {tel}, email {eml}, emprestimos_leitor {ep_lt} {num_leitores++;}
Leitor::Leitor(string nom, long tel, string eml): Object {num_leitores+1},
				nome {nom}, telefone {tel}, email {eml}, emprestimos_leitor {ep_lt} {num_leitores++;}

// adicionar Emprestimo a Leitor
void Leitor::adiciona_emp_leit(Emprestimo* ep) {
	emprestimos_leitor.push_back(ep);
}

// remover Emprestimo de Leitor
bool Leitor::remove_emp_leit(long id) {
	for (vector<Emprestimo*>::const_iterator it = emprestimos_leitor.begin(); it != emprestimos_leitor.end();it++) {
		if ((*it)->get_ID() == id) {
			emprestimos_leitor.erase(it);
			return true;
		}
	}
	return false;
}

// obter Emprestimos de Leitor
vector<Emprestimo*> Leitor::get_emp_leit() {
	return emprestimos_leitor;
}

// determinar Emprestimos de Leitor
void Leitor::set_emp_leit(vector<Emprestimo*> emp_leit) {
	emprestimos_leitor=emp_leit;
}

// obter nome de Leitor
string Leitor::get_nome() {
	return nome;
}

// obter telefone de Leitor
long Leitor::get_telefone() {
	return telefone;
}

// obter email de Leitor
string Leitor::get_email() {
	return email;
}

// determinar nome de Leitor
void Leitor::set_nome(string nom) {
	nome = nom;
}

// determinar telefone de Leitor
void Leitor::set_telefone(long tel) {
	telefone = tel;
}

// determinar email de Leitor
void Leitor::set_email(string eml) {
	email = eml;
}

// imprimir Leitor
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

// escrever Leitor
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

// imprimir emprestimos de Leitor
string Leitor::imprime_emp_leit() {
	stringstream out {};
	for (vector<Emprestimo*>::const_iterator it = emprestimos_leitor.begin(); it != emprestimos_leitor.end(); it++) {
		out << (*it)->imprime();
	}
	return out.str();
}

// obter Emprestimos atrasados de Leitor
vector<Emprestimo*> Leitor::get_emprestimos_atrasados() {
	vector<Emprestimo*> atrasados {};
	for (vector<Emprestimo*>::const_iterator it = emprestimos_leitor.begin(); it != emprestimos_leitor.end(); it++) {
		if ((*it)->get_atraso() > 0) {
			atrasados.push_back(*it);
		}
	}
	return atrasados;
}
