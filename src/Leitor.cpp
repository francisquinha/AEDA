
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

#include "Leitor.h"
#include "Excecao.h"

using namespace std;

unsigned long Leitor::num_leitores {0};

/** @file
 *
 * @brief Source das funcoes de Leitor.
 *
 * Se uma funcao relacionada com leitores nao estiver nos ficheiros biblio, esta aqui.
 **/

Leitor::Leitor(string nom, int tip, long tel, string eml, string mrd, bool ct, unsigned long id,
               vector<Emprestimo*> ep_lt):
Object {id}, nome {nom}, tipo{tip}, telefone {tel}, email {eml}, morada {mrd}, emprestimos_leitor {ep_lt}
    {if (ct) num_leitores++;}

void Leitor::adiciona_emp_leit(Emprestimo* ep) {
	emprestimos_leitor.push_back(ep);
}

bool Leitor::remove_emp_leit(unsigned long id) {
	for (vector<Emprestimo*>::const_iterator it = emprestimos_leitor.begin(); it != emprestimos_leitor.end();it++) {
		if ((*it)->get_ID() == id) {
			emprestimos_leitor.erase(it);
			return true;
		}
	}
	throw Object_nao_existe(id, "emprestimo");
}

vector<Emprestimo*> Leitor::get_emp_leit() {
	return emprestimos_leitor;
}

string Leitor::get_nome() {
	return nome;
}

int Leitor::get_tipo() {
	return tipo;
}

long Leitor::get_telefone() {
	return telefone;
}

string Leitor::get_email() {
	return email;
}

string Leitor::get_morada() {
	return morada;
}

void Leitor::set_nome(string nom) {
	nome = nom;
}

void Leitor::set_tipo(int tip) {
	tipo = tip;
}

void Leitor::set_telefone(long tel) {
	telefone = tel;
}

void Leitor::set_email(string eml) {
	email = eml;
}

void Leitor::set_morada(string mrd) {
	email = mrd;
}

time_t Leitor::get_data_ult_emp() {
    if (emprestimos_leitor.empty()) return 0;
    return (emprestimos_leitor[emprestimos_leitor.size()-1]->get_data());
}

string Leitor::imprime() {
	stringstream out {};
	string tipos {};
	if (tipo == 0) tipos = "Estudante";
	else if (tipo == 1) tipos = "Crianca";
	else tipos = "Adulto";
	out << "ID: "<< get_ID() << endl<< "Nome: " << nome << endl << "Tipo: " << tipos << endl
			<< "Telefone: "<< telefone << endl << "Email: " << email << endl << "Morada: " << morada << endl << "ID Emprestimos: ";
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
			<< tipo << endl
			<< telefone << endl
			<< email << endl
	        << morada << endl;
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
