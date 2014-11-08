
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <cmath>

#include "Livro_old.h"
#include "Excecao.h"

using namespace std;

/** @file
 *
 * @brief Source das funcoes de Livro_old.
 *
 * Se uma funcao relacionada com livros antigos nao estiver nos ficheiros biblio, esta aqui.
 **/

// construtor Livro antigo
Livro_old::Livro_old(long id, string tit, vector<string> aut, string tem, long isbn, string cot, int np, int ed, bool ept, long id_ep, time_t dt, time_t dtf, bool ct):
		Livro {id, tit, aut, tem, isbn, cot, np, ed, ept, id_ep, dt, ct}, data_fim {dtf} {};
Livro_old::Livro_old(long id, string tit, vector<string> aut, string tem, long isbn, string cot, int np, int ed, bool ept, long id_ep, time_t dt, bool ct):
		Livro {id, tit, aut, tem, isbn, cot, np, ed, ept, id_ep, dt, ct}, data_fim {time(0)} {};


// imprimir Livro
string Livro_old::imprime() {
	stringstream out {};
	tm *ldataf = localtime(&data_fim);
	long yearf {1900 + ldataf->tm_year};
	long monthf {1 + ldataf->tm_mon};
	long dayf {ldataf->tm_mday};
	string yearsf {to_string(yearf)};
	string monthsf{}, daysf{};
	if (monthf<10) monthsf = "0" + to_string(monthf);
	else monthsf = to_string(monthf);
	if (dayf<10) daysf = "0" + to_string(dayf);
	else daysf = to_string(dayf);
	string dtf {};
	if (data_fim == 0) dtf = "0";
	else dtf = yearsf + "/" + monthsf + "/" + daysf;
	vector<string> autors {get_autores()};
	out << "ID: "<< get_ID() << endl
			<< "Titulo: " << get_titulo() << endl
			<< "Autores: ";
	for (vector<string>::const_iterator it = autors.begin(); it != autors.end(); it++) {
		out << *it << "; ";
	}
	out << endl << "Tema: " << get_tema() << endl
			<< "ISBN: " << get_ISBN() << endl
			<< "Cota: " << get_cota() << endl
			<< "Num. Paginas: " << get_num_paginas() << endl
			<< "Edicao: " << get_edicao() << endl
			<< "Data fim: " << dtf << endl;
	return out.str();
}

// escrever Livro
void Livro_old::escreve(string ficheiro) {
	stringstream out {};
	tm *ldataf = localtime(&data_fim);
	long yearf {1900 + ldataf->tm_year};
	long monthf {1 + ldataf->tm_mon};
	long dayf {ldataf->tm_mday};
	string yearsf {to_string(yearf)};
	string monthsf{}, daysf{};
	if (monthf<10) monthsf = "0" + to_string(monthf);
	else monthsf = to_string(monthf);
	if (dayf<10) daysf = "0" + to_string(dayf);
	else daysf = to_string(dayf);
	string dtf {};
	if (data_fim == 0) dtf = "0";
	else dtf = yearsf + "/" + monthsf + "/" + daysf;
	vector<string> autors {get_autores()};
	out << get_ID() << endl
		<< get_titulo() << endl;
	for (vector<string>::const_iterator it = autors.begin(); it != autors.end(); it++) {
		out << *it << ";";
	}
	out << endl << get_tema() << endl
				<< get_ISBN() << endl
				<< get_cota() << endl
				<< get_num_paginas() << endl
				<< get_edicao() << endl
				<< dtf << endl;
	ofstream myfile (ficheiro, ios::app);
	if (myfile.is_open()) {
		myfile << out.str();
		myfile.close();
	}
	else throw Ficheiro_indisponivel(ficheiro);
}




