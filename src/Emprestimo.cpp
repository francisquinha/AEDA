
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

long Emprestimo::num_emprestimos{0};

// construtor Emprestimo
Emprestimo::Emprestimo(long id, Livro* lv, Funcionario* fc, Leitor* lt, time_t dt): Object{id},
		livro{lv}, funcionario{fc}, leitor{lt}, data{dt} {}
Emprestimo::Emprestimo(long id, Livro* lv, Funcionario* fc, Leitor* lt): Object{id},
		livro{lv}, funcionario{fc}, leitor{lt}, data{std::time(0)} {}
Emprestimo::Emprestimo(Livro* lv, Funcionario* fc, Leitor* lt): Object{num_emprestimos+1},
		livro{lv}, funcionario{fc}, leitor{lt}, data{std::time(0)} {num_emprestimos++;}
Emprestimo::Emprestimo(Livro* lv, Funcionario* fc, Leitor* lt, time_t dt): Object{num_emprestimos+1},
		livro{lv}, funcionario{fc}, leitor{lt}, data{dt} {num_emprestimos++;}

// obter Livro de Emprestimo
Livro* Emprestimo::get_livro() {
	return livro;
}

// obter Leitor de Emprestimo
Leitor* Emprestimo::get_leitor() {
	return leitor;
}

// obter data de Emprestimo
time_t Emprestimo::get_data() {
	return data;
}

// obter Funcionario de Emprestimo
Funcionario* Emprestimo::get_funcionario() {
	return funcionario;
}

// obter atraso na entrega de Emprestimo
int Emprestimo::get_atraso() {
	time_t hoje = std::time(0);
	double tempo_dias{floor(difftime(hoje, data)/86400)};
	double tempo_extra{max(tempo_dias - 7, 0.0)};
	return (int) tempo_extra;
}

// obter multa na entraga de Emprestimo
double Emprestimo::get_multa() {
	int tempo_extra=get_atraso();
	int tempo_extra_extra{max(tempo_extra-7, 0)};
	double divida{tempo_extra * 0.25 + tempo_extra_extra * 0.5};
	return divida;
}

// imprimir Emprestimo
string Emprestimo::imprime() {
	stringstream out{};
	tm *ldata = localtime(&data);
	long year{1900 + ldata->tm_year};
	long month{1 + ldata->tm_mon};
	long day {ldata->tm_mday};
	string dt{}, months{}, days{};
	string years{to_string(year)};
	if (month<10) months = "0" + to_string(month);
	else months = to_string(month);
	if (day<10) days = "0" + to_string(day);
	else days = to_string(day);
	if (data == 0) dt = "0";
	else dt = years + "/" + months + "/" + days;
	out << "ID: "<< get_ID() << endl
			<< "ID Livro: " << livro->get_ID() << endl
			<< "ID Funcionario: " << funcionario->get_ID() << endl
			<< "ID Leitor: " << leitor->get_ID() << endl
			<< "Data: " << dt << endl;
	return out.str();
}

// escrever Emprestimo
void Emprestimo::escreve(string ficheiro) {
	stringstream out{};
	tm *ldata = localtime(&data);
	long year{1900 + ldata->tm_year};
	long month{1 + ldata->tm_mon};
	long day {ldata->tm_mday};
	string dt{}, months{}, days{};
	string years{to_string(year)};
	if (month<10) months = "0" + to_string(month);
	else months = to_string(month);
	if (day<10) days = "0" + to_string(day);
	else days = to_string(day);
	if (data == 0) dt = "0";
	else dt = years + "/" + months + "/" + days;
	out << get_ID() << endl
	<< livro->get_ID() << endl
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
