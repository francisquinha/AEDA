
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

Leitor_old::Leitor_old(unsigned long id, string nom, int tip, long tel, string eml, string mrd, time_t ult, bool ct, time_t dtf):
		Leitor {nom, tip, tel, eml, mrd, ult, ct, id}, data_fim {dtf} {};

string Leitor_old::imprime() const {
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
        << "Tipo: " << get_tipo() << endl
        << "Telefone: "<< get_telefone() << endl
        << "Email: " << get_email() << endl
        << "Morada: " << get_morada() << endl
        << "Data Ultimo Emprestimo: " << get_data_ult_emp() << endl
        << "Data Fim: " << dt << endl;
	return out.str();
}

void Leitor_old::escreve(string ficheiro) const {
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
        << get_tipo() << endl
        << get_telefone() << endl
        << get_email() << endl
        << get_morada() << endl
        << get_data_ult_emp() << endl
        << dt << endl;
	ofstream myfile (ficheiro, ios::app);
	if (myfile.is_open()) {
		myfile << out.str();
		myfile.close();
	}
	else throw Ficheiro_indisponivel(ficheiro);
}
