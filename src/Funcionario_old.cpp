
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Funcionario_old.h"
#include "Excecao.h"

using namespace std;

/** @file
 *
 * @brief Source das funcoes de Funcionario_old.
 *
 * Se uma funcao relacionada com funcionarios antigos nao estiver nos ficheiros biblio, esta aqui.
 **/

Funcionario_old::Funcionario_old(unsigned long id, string nom, bool ct, time_t dtf): Funcionario {nom, ct, id}, data_fim {dtf} {};

string Funcionario_old::imprime() const {
	stringstream out {};
	tm *ldata = localtime(&data_fim);
	long year {1900 + ldata->tm_year};
	long month {1 + ldata->tm_mon};
	long day {ldata->tm_mday};
	string dt {}, months {}, days {};
	string years {to_string(year)};
	if (month<10) months = "0" + to_string(month);
	else months = to_string(month);
	if (day<10) days = "0" + to_string(day);
	else days = to_string(day);
	if (data_fim == 0) dt = "0";
	else dt = years + "/" + months + "/" + days;
	out << "ID: "<< get_ID() << endl
		<< "Nome: " << get_nome() << endl
		<< "Data Fim: " << dt << endl;
	return out.str();
}

void Funcionario_old::escreve(string ficheiro) const {
	stringstream out {};
	tm *ldata = localtime(&data_fim);
	long year {1900 + ldata->tm_year};
	long month {1 + ldata->tm_mon};
	long day {ldata->tm_mday};
	string dt {}, months {}, days {};
	string years {to_string(year)};
	if (month<10) months = "0" + to_string(month);
	else months = to_string(month);
	if (day<10) days = "0" + to_string(day);
	else days = to_string(day);
	if (data_fim == 0) dt = "0";
	else dt = years + "/" + months + "/" + days;
	out << get_ID() << endl
		<< get_nome() << endl
		<< dt << endl;
	ofstream myfile (ficheiro, ios::app);
	if (myfile.is_open()) {
		myfile << out.str();
		myfile.close();
	}
	else throw Ficheiro_indisponivel(ficheiro);
}




