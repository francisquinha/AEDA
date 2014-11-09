
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <cmath>

#include "Livro.h"
#include "Excecao.h"

using namespace std;

long Livro::num_livros {0};

/** @file
 *
 * @brief Source das funcoes de Livro.
 *
 * Se uma funcao relacionada com livros nao estiver nos ficheiros biblio, esta aqui.
 **/

Livro::Livro(long id, string tit, vector<string> aut, string tem, long isbn, string cot, int np, int ed, bool ept, long id_ep, time_t dt, bool ct):
		Object {id}, titulo {tit}, autores {aut}, tema {tem}, ISBN {isbn}, cota {cot}, num_paginas {np}, edicao {ed},
		emprestado {ept}, ID_ep{id_ep}, data_emp {dt} {if (ct) num_livros++;}
Livro::Livro(string tit, vector<string> aut, string tem, long isbn, string cot, int np, int ed, bool ept, long id_ep, time_t dt, bool ct):
		Object {num_livros+1}, titulo {tit}, autores {aut}, tema {tem}, ISBN {isbn}, cota {cot}, num_paginas {np}, edicao {ed},
		emprestado {ept}, ID_ep{id_ep}, data_emp {dt} {if(ct) num_livros++;}

void Livro::set_emprestado(bool ept) {
	emprestado = ept;
}

void Livro::set_ID_ep(long id_ep) {
	ID_ep = id_ep;
}

void Livro::set_data_emp(time_t dt) {
	data_emp = dt;
}

bool Livro::get_emprestado() {
	return emprestado;
}

long Livro::get_ID_ep() {
	return ID_ep;
}

time_t Livro::get_data_emp() {
	return data_emp;
}

double Livro::get_dias_emp() {
	time_t dt = get_data_emp();
	time_t hj = std::time(0);
	double tempo_dias {floor(difftime(hj,dt)/86400)};
	return tempo_dias;
}

string Livro::get_titulo() {
	return titulo;
}

int Livro::get_edicao() {
	return edicao;
}

vector<string> Livro::get_autores() {
	return autores;
}

string Livro::get_tema() {
	return tema;
}

int Livro::get_num_paginas() {
	return num_paginas;
}

long Livro::get_ISBN() {
	return ISBN;
}

string Livro::get_cota() {
	return cota;
}

string Livro::imprime() {
	stringstream out {};
	tm *ldata = localtime(&data_emp);
	long year {1900 + ldata->tm_year};
	long month {1 + ldata->tm_mon};
	long day {ldata->tm_mday};
	string years {to_string(year)};
	string months {}, days {};
	if (month<10) months = "0" + to_string(month);
	else months = to_string(month);
	if (day<10) days = "0" + to_string(day);
	else days = to_string(day);
	string dt {};
	if (data_emp == 0) dt = "0";
	else dt = years + "/" + months + "/" + days;
	out << "ID: "<< get_ID() << endl
			<< "Titulo: " << titulo << endl
			<< "Autores: ";
	for (vector<string>::const_iterator it = autores.begin(); it != autores.end(); it++) {
		out << *it << "; ";
	}
	out << endl << "Tema: " << tema << endl
			<< "ISBN: " << ISBN << endl
			<< "Cota: " << cota << endl
			<< "Num. Paginas: " << num_paginas << endl
			<< "Edicao: " << edicao << endl
			<< "Emprestado: " << emprestado << endl
			<< "ID Emprestimo: " << ID_ep << endl
			<< "Data Emprestado: " << dt << endl;
	return out.str();
}

void Livro::escreve(string ficheiro) {
	stringstream out {};
	tm *ldata = localtime(&data_emp);
	long year {1900 + ldata->tm_year};
	long month {1 + ldata->tm_mon};
	long day {ldata->tm_mday};
	string years {to_string(year)};
	string months {}, days {};
	if (month<10) months = "0" + to_string(month);
	else months = to_string(month);
	if (day<10) days = "0" + to_string(day);
	else days = to_string(day);
	string dt {};
	if (data_emp == 0) dt = "0";
	else dt = years + "/" + months + "/" + days;
	out << get_ID() << endl
			<< titulo << endl;
	for (vector<string>::const_iterator it = autores.begin(); it != autores.end(); it++) {
		out << *it << ";";
	}
	out << endl << tema << endl
			<< ISBN << endl
			<< cota << endl
			<< num_paginas << endl
			<< edicao << endl
			<< emprestado << endl
			<< ID_ep << endl
			<< dt << endl;
	ofstream myfile (ficheiro, ios::app);
	if (myfile.is_open()) {
		myfile << out.str();
		myfile.close();
	}
	else throw Ficheiro_indisponivel(ficheiro);
}
