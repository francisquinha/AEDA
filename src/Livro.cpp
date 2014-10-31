
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
Livro::Livro(long id, string tit, vector<string> aut, long isbn, string cot, int np, int ed, bool ept, time_t dt):
		Object{id}, titulo{tit}, autores{aut}, ISBN{isbn}, cota{cot}, num_paginas{np}, edicao{ed},
		emprestado{ept}, data_emp{dt} {}
Livro::Livro(string tit, vector<string> aut, long isbn, string cot, int np, int ed, bool ept, time_t dt):
		Object{num_livros+1}, titulo{tit}, autores{aut}, ISBN{isbn}, cota{cot}, num_paginas{np}, edicao{ed},
		emprestado{ept}, data_emp{dt} {num_livros++;}

// modificar estado emprestado de Livro
void Livro::set_emprestado(bool ept){
	emprestado=ept;
}

// modificar dias de indisponibilidade de Livro
void Livro::set_data_emp(time_t dt){
	data_emp=dt;
}

// obter emprestado de Livro
bool Livro::get_emprestado(){
	return emprestado;
}

// obter indisponibilidade de Livro
time_t Livro::get_data_emp(){
	return data_emp;
}

// obter titulo de Livro
string Livro::get_titulo(){
	return titulo;
}

// obter edicao de Livro
int Livro::get_edicao(){
	return edicao;
}

// obter autores de Livro
vector<string> Livro::get_autores(){
	return autores;
}

// obter numero de paginas de Livro
int Livro::get_num_paginas(){
	return num_paginas;
}

// obter ISBN de paginas de Livro
long Livro::get_ISBN(){
	return ISBN;
}

// obter cota de Livro
string Livro::get_cota(){
	return cota;
}

// imprimir Livro
string Livro::imprime(){
	stringstream out{};
	out << "ID: "<< get_ID() << endl
			<< "Titulo: " << titulo << endl
			<< "Autores: ";
	for (vector<string>::const_iterator it=autores.begin(); it!=autores.end(); it++){
		out << *it << "; ";
	}
	out << endl << "ISBN: " << ISBN << endl
			<< "Cota: " << cota << endl
			<< "Num. Paginas: " << num_paginas << endl
			<< "Edicao: " << edicao << endl
			<< "Emprestado: " << emprestado << endl
			<< "Data Emprestado: " << data_emp << endl;
	return out.str();
}

// escrever Livro
void Livro::escreve(){
	stringstream out{};
	out << get_ID() << endl
			<< titulo << endl;
	for (vector<string>::const_iterator it=autores.begin(); it!=autores.end(); it++){
		out << *it << "; ";
	}
	out << endl << ISBN << endl
			<< cota << endl
			<< num_paginas << endl
			<< edicao << endl
			<< emprestado << endl
			<< data_emp << endl;
	ofstream myfile ("Livro.txt",ios::app);
	if (myfile.is_open()){
		myfile << out.str();
		myfile.close();
	}
	else throw Ficheiro_indisponivel("Livro.txt");
}

