
#include "Livro_old.h"
#include "Excecao.h"

using namespace std;

/** @file
 *
 * @brief Source das funcoes de Livro_old.
 *
 * Se uma funcao relacionada com livros antigos nao estiver nos ficheiros biblio, esta aqui.
 **/

Livro_old::Livro_old(int ano, string tit, vector<string> aut, string tem, long isbn,
                     string cot, int np, int ed, bool ct, unsigned long id, int ex,
                     std::vector<time_t> dtf):
    Livro {ano, tit, aut, tem, isbn, cot, np, ed, ct, id, ex}, data_fim {dtf} {};

void Livro_old::adiciona_dtf(const time_t dtf) {
    data_fim.push_back(dtf);
}

string Livro_old::imprime() const {
    stringstream out {};
    stringstream datas {};
    for (vector<time_t>::const_iterator it = data_fim.begin(); it != data_fim.end(); it++) {
        time_t data_f {*it};
        tm *ldata = localtime(&data_f);
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
        if (data_f == 0) dt = "0";
        else dt = years + "/" + months + "/" + days;
        datas << dt << "; ";
    }
    out << "ID: "<< get_ID() << endl
        << "Ano Edicao: " << get_ano_edicao() << endl
        << "Titulo: " << get_titulo() << endl
        << "Autores: ";
    for (vector<string>::const_iterator it = get_autores().begin(); it != get_autores().end(); it++) {
        out << *it << "; ";
    }
    out << endl << "Tema: " << get_tema() << endl
        << "ISBN: " << get_ISBN() << endl
        << "Cota: " << get_cota() << endl
        << "Num. Paginas: " << get_num_paginas() << endl
        << "Edicao: " << get_edicao() << endl
        << "Exemplares: " << get_exemplares() << endl
        << "Data fim: " << datas.str() << endl;
	return out.str();
}

void Livro_old::escreve(const string ficheiro) const {
	stringstream out {};
    stringstream datas {};
    for (vector<time_t>::const_iterator it = data_fim.begin(); it != data_fim.end(); it++) {
        time_t data_f {*it};
        tm *ldata = localtime(&data_f);
        long year {1900 + ldata->tm_year};
        long month {1 + ldata->tm_mon};
        long day {ldata->tm_mday};
        string years {to_string(year)};
        string months {}, days {};
        if (month < 10) months = "0" + to_string(month);
        else months = to_string(month);
        if (day < 10) days = "0" + to_string(day);
        else days = to_string(day);
        string dt {};
        if (data_f == 0) dt = "0";
        else dt = years + "/" + months + "/" + days;
        datas << dt << ";";
    }
	vector<string> autors {get_autores()};
	out << get_ID() << endl
		<< get_ano_edicao() << endl
        << get_titulo() << endl;
	for (vector<string>::const_iterator it = autors.begin(); it != autors.end(); it++) {
		out << *it << ";";
	}
	out << endl << get_tema() << endl
        << get_ISBN() << endl
		<< get_cota() << endl
		<< get_num_paginas() << endl
		<< get_edicao() << endl
        << get_exemplares() << endl
        << datas.str() << endl;
	ofstream myfile (ficheiro, ios::app);
	if (myfile.is_open()) {
		myfile << out.str();
		myfile.close();
	}
	else throw Ficheiro_indisponivel(ficheiro);
}




