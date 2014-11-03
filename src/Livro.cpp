
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

long Livro::num_livros{0};

// construtor Livro
Livro::Livro(long id, string tit, vector<string> aut, string tem, long isbn, string cot, int np, int ed, bool ept, time_t dt):
		Object{id}, titulo{tit}, autores{aut}, tema{tem}, ISBN{isbn}, cota{cot}, num_paginas{np}, edicao{ed},
		emprestado{ept}, data_emp{dt} {}
Livro::Livro(string tit, vector<string> aut, string tem, long isbn, string cot, int np, int ed, bool ept, time_t dt):
		Object{num_livros+1}, titulo{tit}, autores{aut}, tema{tem}, ISBN{isbn}, cota{cot}, num_paginas{np}, edicao{ed},
		emprestado{ept}, data_emp{dt} {num_livros++;}

// modificar estado emprestado de Livro
void Livro::set_emprestado(bool ept) {
	emprestado = ept;
}

// modificar dias de indisponibilidade de Livro
void Livro::set_data_emp(time_t dt) {
	data_emp = dt;
}

// obter emprestado de Livro
bool Livro::get_emprestado() {
	return emprestado;
}

// obter data de emprestimo de Livro
time_t Livro::get_data_emp() {
	return data_emp;
}

// obter numero de dias de emprestimo de Livro
double Livro::get_dias_emp() {
	time_t dt = get_data_emp();
	time_t hj = std::time(0);
	double tempo_dias{floor(difftime(hj,dt)/86400)};
	return tempo_dias;
}

// obter titulo de Livro
string Livro::get_titulo() {
	return titulo;
}

// obter edicao de Livro
int Livro::get_edicao() {
	return edicao;
}

// obter autores de Livro
vector<string> Livro::get_autores() {
	return autores;
}

// obter tema de Livro
string Livro::get_tema() {
	return tema;
}

// obter numero de paginas de Livro
int Livro::get_num_paginas() {
	return num_paginas;
}

// obter ISBN de paginas de Livro
long Livro::get_ISBN() {
	return ISBN;
}

// obter cota de Livro
string Livro::get_cota() {
	return cota;
}

// imprimir Livro
string Livro::imprime() {
	stringstream out{};
	tm *ldata = localtime(&data_emp);
	long ymd{(1900 + ldata->tm_year) * 10000 + (1 + ldata->tm_mon) * 100 + ldata->tm_mday};
	if (data_emp == 0) ymd = 0;
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
			<< "Data Emprestado: " << ymd << endl;
	return out.str();
}

// escrever Livro
void Livro::escreve(string ficheiro) {
	stringstream out{};
	tm *ldata = localtime(&data_emp);
	long ymd{(1900 + ldata->tm_year) * 10000 + (1 + ldata->tm_mon) * 100 + ldata->tm_mday};
	if (data_emp == 0) ymd = 0;
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
			<< ymd << endl;
	ofstream myfile (ficheiro, ios::app);
	if (myfile.is_open()) {
		myfile << out.str();
		myfile.close();
	}
	else throw Ficheiro_indisponivel(ficheiro);
}

