
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <fstream>

#include "Emprestimo.h"
#include "Excecao.h"

using namespace std;

/** @file
 *
 * @brief Source das funcoes de Emprestimo.
 *
 * Se uma funcao relacionada com emprestimos nao estiver nos ficheiros biblio, esta aqui.
 **/

unsigned long Emprestimo::num_emprestimos {0};

Emprestimo::Emprestimo(Livro* lv, unsigned long ind, Funcionario* fc, Leitor* lt, bool ct,
                       time_t dt, unsigned long id): Object {id}, livro {lv}, funcionario {fc},
    leitor {lt}, data {dt}, indice {ind} {if (ct) num_emprestimos++;}

Livro* Emprestimo::get_livro() const {
	return livro;
}

unsigned long Emprestimo::get_indice() const {
    return indice;
}

Leitor* Emprestimo::get_leitor() const {
	return leitor;
}

time_t Emprestimo::get_data() const {
	return data;
}

Funcionario* Emprestimo::get_funcionario() const {
	return funcionario;
}

int Emprestimo::get_atraso() const {
	time_t hoje = time(0);
	double tempo_dias {trunc(difftime(hoje, data)/86400)};
	double tempo_extra {max(tempo_dias - 7, 0.0)};
	return (int) tempo_extra;
}

double Emprestimo::get_multa() const {
	int tempo_extra=get_atraso();
	int tempo_extra_extra {max(tempo_extra-7, 0)};
	double divida {tempo_extra * 0.25 + tempo_extra_extra * 0.5};
	return divida;
}

string Emprestimo::imprime() const {
	stringstream out {};
	tm *ldata = localtime(&data);
	long year {1900 + ldata->tm_year};
	long month {1 + ldata->tm_mon};
	long day {ldata->tm_mday};
	string dt {}, months {}, days {};
	string years {to_string(year)};
	if (month<10) months = "0" + to_string(month);
	else months = to_string(month);
	if (day<10) days = "0" + to_string(day);
	else days = to_string(day);
	if (data == 0) dt = "0";
	else dt = years + "/" + months + "/" + days;
	out << "ID: "<< get_ID() << endl
			<< "ID Livro: " << livro->get_ID() << endl
            << "Indice Exemplar: " << indice << endl
			<< "ID Funcionario: " << funcionario->get_ID() << endl
			<< "ID Leitor: " << leitor->get_ID() << endl
			<< "Data: " << dt << endl;
	return out.str();
}

void Emprestimo::escreve(const string ficheiro) const {
	stringstream out {};
	tm *ldata = localtime(&data);
	long year {1900 + ldata->tm_year};
	long month {1 + ldata->tm_mon};
	long day {ldata->tm_mday};
	string dt {}, months {}, days {};
	string years {to_string(year)};
	if (month<10) months = "0" + to_string(month);
	else months = to_string(month);
	if (day<10) days = "0" + to_string(day);
	else days = to_string(day);
	if (data == 0) dt = "0";
	else dt = years + "/" + months + "/" + days;
	out << get_ID() << endl
	<< livro->get_ID() << endl
    << indice << endl
	<< funcionario->get_ID() << endl
	<< leitor->get_ID() << endl
	<< dt << endl;
	ofstream myfile (ficheiro, ios::app);
	if (myfile.is_open()) {
		myfile << out.str();
		myfile.close();
	}
	else throw Ficheiro_indisponivel(ficheiro);
}
