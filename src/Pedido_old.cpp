
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <fstream>

#include "Pedido_old.h"
#include "Excecao.h"

using namespace std;

/** @file
 *
 * @brief Source das funcoes de Pedido_old.
 *
 * Se uma funcao relacionada com pedidos antigos nao estiver nos ficheiros biblio, esta aqui.
 **/

Pedido_old::Pedido_old(Livro* lv, Funcionario* fc, Leitor* lt, bool ct,
                               std::time_t dt, unsigned long id, std::time_t dt_f):
Pedido {lv, fc, lt, ct, dt, id}, data_fim {dt_f} {}

string Pedido_old::imprime() const {
    stringstream out {};
    time_t dat=get_data();
    tm *ldata = localtime(&dat);
    long year {1900 + ldata->tm_year};
    long month {1 + ldata->tm_mon};
    long day {ldata->tm_mday};
    string dt {}, months {}, days {};
    string years {to_string(year)};
    if (month<10) months = "0" + to_string(month);
    else months = to_string(month);
    if (day<10) days = "0" + to_string(day);
    else days = to_string(day);
    if (dat == 0) dt = "0";
    else dt = years + "/" + months + "/" + days;
    tm *ldata_e = localtime(&data_fim);
    long year_e {1900 + ldata_e->tm_year};
    long month_e {1 + ldata_e->tm_mon};
    long day_e {ldata_e->tm_mday};
    string dt_e {}, months_e {}, days_e {};
    string years_e {to_string(year_e)};
    if (month_e<10) months_e= "0" + to_string(month_e);
    else months_e = to_string(month_e);
    if (day_e<10) days_e = "0" + to_string(day_e);
    else days_e = to_string(day_e);
    if (data_fim == 0) dt_e = "0";
    else dt_e = years_e + "/" + months_e + "/" + days_e;
    out << "ID: "<< get_ID() << endl
    << "ID Livro: " << get_livro()->get_ID() << endl
    << "ID Funcionario: " << get_funcionario()->get_ID() << endl
    << "ID Leitor: " << get_leitor()->get_ID() << endl
    << "Data Inicio: " << dt << endl
    << "Data Fim: " << dt_e << endl;
    return out.str();
}

void Pedido_old::escreve(const string ficheiro) const {
    stringstream out {};
    time_t dat=get_data();
    tm *ldata = localtime(&dat);
    long year {1900 + ldata->tm_year};
    long month {1 + ldata->tm_mon};
    long day {ldata->tm_mday};
    string dt {}, months {}, days {};
    string years {to_string(year)};
    if (month<10) months = "0" + to_string(month);
    else months = to_string(month);
    if (day<10) days = "0" + to_string(day);
    else days = to_string(day);
    if (dat == 0) dt = "0";
    else dt = years + "/" + months + "/" + days;
    tm *ldata_e = localtime(&data_fim);
    long year_e {1900 + ldata_e->tm_year};
    long month_e {1 + ldata_e->tm_mon};
    long day_e {ldata_e->tm_mday};
    string dt_e {}, months_e {}, days_e {};
    string years_e {to_string(year_e)};
    if (month_e<10) months_e= "0" + to_string(month_e);
    else months_e = to_string(month_e);
    if (day_e<10) days_e = "0" + to_string(day_e);
    else days_e = to_string(day_e);
    if (data_fim == 0) dt_e = "0";
    else dt_e = years_e + "/" + months_e + "/" + days_e;
    out << get_ID() << endl
    << get_livro()->get_ID() << endl
    << get_funcionario()->get_ID() << endl
    << get_leitor()->get_ID() << endl
    << dt << endl
    << dt_e << endl;
    ofstream myfile (ficheiro, ios::app);
    if (myfile.is_open()) {
        myfile << out.str();
        myfile.close();
    }
    else throw Ficheiro_indisponivel(ficheiro);
}
