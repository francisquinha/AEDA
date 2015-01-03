
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <fstream>

#include "Pedido.h"
#include "Excecao.h"

using namespace std;

/** @file
 *
 * @brief Source das funcoes de Pedido.
 *
 * Se uma funcao relacionada com pedidos em espera nao estiver nos ficheiros biblio, esta aqui.
 **/

unsigned long Pedido::num_pedidos {0};

Pedido::Pedido(Livro* lv, Funcionario* fc, Leitor* lt, bool ct, time_t dt, unsigned long id):Object {id}, livro {lv}, funcionario {fc}, leitor {lt}, data {dt} {if (ct) num_pedidos++;}

bool Pedido::operator <(const Pedido pd) const {
    double tempo_dias {floor(difftime(data, pd.get_data())/86400)};
    if (tempo_dias > 0) return true;
    else if (tempo_dias == 0) {
        if (leitor->get_tipo() > (pd.get_leitor())->get_tipo()) return true;
        else if (leitor->get_tipo() == (pd.get_leitor())->get_tipo())
            return data > pd.get_data();
        return false;
    }
    return false;
}

Livro* Pedido::get_livro() const {
    return livro;
}

Leitor* Pedido::get_leitor() const {
	return leitor;
}

time_t Pedido::get_data() const {
	return data;
}

Funcionario* Pedido::get_funcionario() const {
	return funcionario;
}

string Pedido::imprime() const {
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
			<< "ID Funcionario: " << funcionario->get_ID() << endl
			<< "ID Leitor: " << leitor->get_ID() << endl
			<< "Data: " << dt << endl;
	return out.str();
}

void Pedido::escreve(const string ficheiro) const {
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




