
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

#include "Leitor_old.h"
#include "Excecao.h"

using namespace std;

/** @file
 *
 * @brief Source das funcoes de Leitor_old.
 *
 * Se uma funcao relacionada com leitores antigos nao estiver nos ficheiros biblio, esta aqui.
 **/

Leitor_old::Leitor_old(long id, string nom, int tip, long tel, string eml, time_t dtf, bool ct):
		Leitor {id, nom, tip, tel, eml, {}, ct}, data_fim {dtf} {};
Leitor_old::Leitor_old(long id, string nom, int tip, long tel, string eml, bool ct):
		Leitor {id, nom, tip, tel, eml, {}, ct}, data_fim {time(0)} {};

string Leitor_old::imprime() {
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
	out << "ID: "<< get_ID() << endl<< "Nome: " << get_nome() << endl << "Telefone: "<< get_telefone() << endl
			<< "Email: " << get_email() << endl << "Data Fim: " << dt << endl;
	return out.str();
}

void Leitor_old::escreve(string ficheiro) {
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
			<< get_telefone() << endl
			<< get_email() << endl
			<< dt << endl;
	ofstream myfile (ficheiro, ios::app);
	if (myfile.is_open()) {
		myfile << out.str();
		myfile.close();
	}
	else throw Ficheiro_indisponivel(ficheiro);
}
