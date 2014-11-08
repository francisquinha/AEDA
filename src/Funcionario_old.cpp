
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Funcionario_old.h"
#include "Excecao.h"

using namespace std;

// construtor Funcionario antigo
Funcionario_old::Funcionario_old(long id, string nom, time_t dtf, bool ct): Funcionario {id, nom, ct}, data_fim {dtf} {};
Funcionario_old::Funcionario_old(long id, string nom, bool ct): Funcionario {id, nom, ct}, data_fim {time(0)} {};

// imprimir Funcionario
string Funcionario_old::imprime() {
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

// escrever Funcionario
void Funcionario_old::escreve(string ficheiro) {
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




