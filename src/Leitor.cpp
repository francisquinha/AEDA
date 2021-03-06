
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

Leitor::Leitor(string nom, int tip, long tel, string eml, string mrd, time_t ult, bool ct, unsigned long id,
               vector<Emprestimo*> ep_lt):
Object {id}, nome {nom}, tipo{tip}, telefone {tel}, email {eml}, morada {mrd}, data_ult_emp {ult}, emprestimos_leitor {ep_lt}
    {if (ct) num_leitores++;}

void Leitor::adiciona_emp_leit(Emprestimo* ep) {
	emprestimos_leitor.push_back(ep);
}

bool Leitor::remove_emp_leit(const unsigned long id) {
	for (vector<Emprestimo*>::const_iterator it = emprestimos_leitor.begin(); it != emprestimos_leitor.end();it++) {
		if ((*it)->get_ID() == id) {
			emprestimos_leitor.erase(it);
			return true;
		}
	}
	throw Object_nao_existe(id, "emprestimo");
}

vector<Emprestimo*> Leitor::get_emp_leit() const {
	return emprestimos_leitor;
}

string Leitor::get_nome() const {
	return nome;
}

int Leitor::get_tipo() const {
	return tipo;
}

long Leitor::get_telefone() const {
	return telefone;
}

string Leitor::get_email() const {
	return email;
}

string Leitor::get_morada() const {
	return morada;
}

time_t Leitor::get_data_ult_emp() const {
	return data_ult_emp;
}

void Leitor::set_nome(const string nom) {
	nome = nom;
}

void Leitor::set_tipo(const int tip) {
	tipo = tip;
}

void Leitor::set_telefone(const long tel) {
	telefone = tel;
}

void Leitor::set_email(const string eml) {
	email = eml;
}

void Leitor::set_morada(const string mrd) {
	morada = mrd;
}

void Leitor::set_data_ult_emp(const time_t ult) {
	data_ult_emp = ult;
}

string Leitor::imprime() const {
	stringstream out {};
	string tipos {};
	if (tipo == 0) tipos = "Estudante";
	else if (tipo == 1) tipos = "Crianca";
	else tipos = "Adulto";
    tm *ldata = localtime(&data_ult_emp);
    long year {1900 + ldata->tm_year};
    long month {1 + ldata->tm_mon};
    long day {ldata->tm_mday};
    string dt {}, months {}, days {};
    string years {to_string(year)};
    if (month<10) months = "0" + to_string(month);
    else months = to_string(month);
    if (day<10) days = "0" + to_string(day);
    else days = to_string(day);
    if (data_ult_emp == 0) dt = "0";
    else dt = years + "/" + months + "/" + days;
	out << "ID: "<< get_ID() << endl
        << "Nome: " << nome << endl
        << "Tipo: " << tipos << endl
        << "Telefone: "<< telefone << endl
        << "Email: " << email << endl
        << "Morada: " << morada << endl
        << "Data Ultimo Emprestimo: " << dt << endl
        << "ID Emprestimos: ";
	for (vector<Emprestimo*>::const_iterator it = emprestimos_leitor.begin(); it != emprestimos_leitor.end(); it++) {
		out << (*it)->get_ID() << "; ";
	}
	out << endl;
	return out.str();
}

void Leitor::escreve(const string ficheiro) const {
	stringstream out {};
    tm *ldata = localtime(&data_ult_emp);
    long year {1900 + ldata->tm_year};
    long month {1 + ldata->tm_mon};
    long day {ldata->tm_mday};
    string dt {}, months {}, days {};
    string years {to_string(year)};
    if (month<10) months = "0" + to_string(month);
    else months = to_string(month);
    if (day<10) days = "0" + to_string(day);
    else days = to_string(day);
    if (data_ult_emp == 0) dt = "0";
    else dt = years + "/" + months + "/" + days;
	out << get_ID() << endl
        << nome << endl
        << tipo << endl
        << telefone << endl
        << email << endl
        << morada << endl
        << dt << endl;
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

string Leitor::imprime_emp_leit() const {
	stringstream out {};
	for (vector<Emprestimo*>::const_iterator it = emprestimos_leitor.begin(); it != emprestimos_leitor.end(); it++) {
		out << (*it)->imprime();
	}
	return out.str();
}

vector<Emprestimo*> Leitor::get_emprestimos_atrasados() const {
	vector<Emprestimo*> atrasados {};
	for (vector<Emprestimo*>::const_iterator it = emprestimos_leitor.begin(); it != emprestimos_leitor.end(); it++) {
		if ((*it)->get_atraso() > 0) {
			atrasados.push_back(*it);
		}
	}
	return atrasados;
}
