
#include "Livro.h"
#include "Excecao.h"

using namespace std;

unsigned long Livro::num_livros {0};

/** @file
 *
 * @brief Source das funcoes de Livro.
 *
 * Se uma funcao relacionada com livros nao estiver nos ficheiros biblio, esta aqui.
 **/

Livro::Livro(int ano, string tit, vector<string> aut, string tem, long isbn, string cot, int np,
             int ed, bool ct, unsigned long id, int ex, int exd,
             vector<unsigned long> id_ep, vector<time_t> dt): Object {id}, ano_edicao {ano},
titulo {tit}, autores {aut}, tema {tem}, ISBN {isbn}, cota {cot}, num_paginas {np}, edicao {ed},
exemplares {ex}, ex_disponiveis(exd), ID_ep{id_ep}, data_emp {dt} {if (ct) num_livros++;}


void Livro::set_ID_ep(unsigned long ind, unsigned long id_ep) {
    ID_ep[ind] = id_ep;
}

int Livro::get_ano_edicao() {
    return ano_edicao;
}

void Livro::set_data_emp(unsigned long ind, time_t dt) {
	data_emp[ind] = dt;
}

vector<unsigned long> Livro::get_ID_ep() {
	return ID_ep;
}

vector<time_t> Livro::get_data_emp() {
	return data_emp;
}

void Livro::inc_ID_ep() {
    ID_ep.push_back(0);
}

void Livro::del_ID_ep(unsigned long ind) {
    ID_ep.erase(ID_ep.begin() + ind);
}

void Livro::inc_data_emp() {
    data_emp.push_back(0);
}

void Livro::del_data_emp(unsigned long ind) {
    data_emp.erase(data_emp.begin() + ind);
}

double Livro::get_dias_emp(unsigned long ind) {
	time_t dt = get_data_emp()[ind];
	time_t hj = std::time(0);
	double tempo_dias {floor(difftime(hj,dt)/86400)};
	return tempo_dias;
}

string Livro::get_titulo() {
	return titulo;
}

int Livro::get_edicao() {
	return edicao;
}

vector<string> Livro::get_autores() {
	return autores;
}

string Livro::get_tema() {
	return tema;
}

int Livro::get_num_paginas() {
	return num_paginas;
}

long Livro::get_ISBN() {
	return ISBN;
}

string Livro::get_cota() {
	return cota;
}

int Livro::get_exemplares() {
    return exemplares;
}

void Livro::inc_exemplares() {
    exemplares++;
}

void Livro::dec_exemplares() {
    exemplares--;
}

int Livro::get_ex_disponiveis() {
    return ex_disponiveis;
}

void Livro::inc_ex_disponiveis() {
    ex_disponiveis++;
}

void Livro::dec_ex_disponiveis() {
    ex_disponiveis--;
}

string Livro::imprime() {
	stringstream out {};
    stringstream datas {};
    for (vector<time_t>::const_iterator it = data_emp.begin(); it != data_emp.end(); it++) {
        time_t data {*it};
        tm *ldata = localtime(&data);
        long year {1900 + ldata->tm_year};
        long month {1 + ldata->tm_mon};
        long day {ldata->tm_mday};
        string years {to_string(year)};
        string months {}, days {};
        if (month<10) months = "0" + to_string(month);
        else months = to_string(month);
        if (day<10) days = "0" + to_string(day);
        else days = to_string(day);
        string dt {};
        if (data == 0) dt = "0";
        else dt = years + "/" + months + "/" + days;
        datas << dt << "; ";
    }
	out << "ID: "<< get_ID() << endl
        << "Ano Edicao: " << ano_edicao << endl
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
        << "Exemplares: " << exemplares << endl
        << "Exemplares Disponiveis: " << ex_disponiveis << endl
        << "IDs Emprestimos: ";
    for (vector<unsigned long>::const_iterator it = ID_ep.begin(); it != ID_ep.end(); it++) {
        out << *it << "; ";
    }
    out << endl << "Datas Emprestimos: " << datas.str() << endl;
	return out.str();
}

void Livro::escreve(string ficheiro) {
	stringstream out {};
    stringstream datas {};
    for (vector<time_t>::const_iterator it = data_emp.begin(); it != data_emp.end(); it++) {
        time_t data {*it};
        tm *ldata = localtime(&data);
        long year {1900 + ldata->tm_year};
        long month {1 + ldata->tm_mon};
        long day {ldata->tm_mday};
        string years {to_string(year)};
        string months {}, days {};
        if (month<10) months = "0" + to_string(month);
        else months = to_string(month);
        if (day<10) days = "0" + to_string(day);
        else days = to_string(day);
        string dt {};
        if (data == 0) dt = "0";
        else dt = years + "/" + months + "/" + days;
        datas << dt << ";";
    }
	out << get_ID() << endl
        << ano_edicao << endl
        << titulo << endl;
	for (vector<string>::const_iterator it = autores.begin(); it != autores.end(); it++) {
		out << *it << ";";
	}
	out << endl << tema << endl
        << ISBN << endl
        << cota << endl
        << num_paginas << endl
        << edicao << endl
        << exemplares << endl
        << ex_disponiveis << endl;
    for (vector<unsigned long>::const_iterator it = ID_ep.begin(); it != ID_ep.end(); it++) {
        out << *it << ";";
    }
	out	<< endl	<< datas.str() << endl;
	ofstream myfile (ficheiro, ios::app);
	if (myfile.is_open()) {
		myfile << out.str();
		myfile.close();
	}
	else throw Ficheiro_indisponivel(ficheiro);
}
