
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
             vector<Emprestimo*> ep, priority_queue<Pedido> pd):
    Object {id}, ano_edicao {ano}, titulo {tit}, autores {aut}, tema {tem}, ISBN {isbn}, cota {cot},
    num_paginas {np}, edicao {ed}, exemplares {ex}, ex_disponiveis(exd), emprestimos_livro{ep},
    pedidos{pd} {if (ct) num_livros++;}


void Livro::set_emp_livro(unsigned long ind, Emprestimo* ep) {
    emprestimos_livro[ind] = ep;
}

int Livro::get_ano_edicao() const {
    return ano_edicao;
}

vector<Emprestimo*> Livro::get_emp_livro() const {
	return emprestimos_livro;
}

void Livro::inc_emp_livro() {
    emprestimos_livro.push_back(NULL);
}

void Livro::del_emp_livro(const unsigned long ind) {
    emprestimos_livro.erase(emprestimos_livro.begin() + ind);
}

double Livro::get_dias_emp(unsigned long ind) const {
    if (exemplares > ind) {
        time_t dt = emprestimos_livro[ind]->get_data();
        time_t hj = std::time(0);
        double tempo_dias {floor(difftime(hj,dt)/86400)};
        return tempo_dias;
    }
    throw Exemplar_inexistente(ind, ano_edicao, titulo, autores, tema, ISBN, cota, num_paginas, edicao, get_ID(), exemplares, ex_disponiveis, emprestimos_livro, pedidos);
}

string Livro::get_titulo() const {
	return titulo;
}

int Livro::get_edicao() const {
	return edicao;
}

vector<string> Livro::get_autores() const {
	return autores;
}

string Livro::get_tema() const {
	return tema;
}

int Livro::get_num_paginas() const {
	return num_paginas;
}

long Livro::get_ISBN() const {
	return ISBN;
}

string Livro::get_cota() const {
	return cota;
}

void Livro::set_ano_edicao(const int ano) {
    ano_edicao = ano;
}

void Livro::set_titulo(const std::string tit) {
    titulo = tit;
}

void Livro::set_autores(const std::vector<std::string> aut) {
    autores = aut;
}

void Livro::set_tema(const std::string tem) {
    tema = tem;
}

void Livro::set_ISBN(const long isbn) {
    ISBN = isbn;
}

void Livro::set_cota(const std::string cot) {
    cota = cot;
}

void Livro::set_num_paginas(const int np) {
    num_paginas = np;
}

void Livro::set_edicao(const int ed) {
    edicao = ed;
}

int Livro::get_exemplares() const {
    return exemplares;
}

void Livro::inc_exemplares() {
    exemplares++;
}

void Livro::dec_exemplares() {
    exemplares--;
}

int Livro::get_ex_disponiveis() const {
    return ex_disponiveis;
}

void Livro::inc_ex_disponiveis() {
    ex_disponiveis++;
}

void Livro::dec_ex_disponiveis() {
    ex_disponiveis--;
}

priority_queue<Pedido> Livro::get_pedidos() const {
    return pedidos;
}

void Livro::adiciona_ped_livro(Pedido pd) {
    pedidos.push(pd);
}

void Livro::remove_ped_livro() {
    pedidos.pop();
}

void Livro::set_pedidos(priority_queue<Pedido> pds) {
    pedidos = pds;
}

string Livro::imprime() const {
	stringstream out {};
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
    for (vector<Emprestimo*>::const_iterator it = emprestimos_livro.begin(); it != emprestimos_livro.end(); it++) {
        if (*it == NULL) out << "0; ";
        else out << (*it)->get_ID() << "; ";
    }
    out << endl << "IDs Pedidos: ";
    priority_queue<Pedido> peds {pedidos};
    while (!peds.empty()) {
        out << peds.top().get_ID() << "; ";
        peds.pop();
    }
    out << endl;
	return out.str();
}

void Livro::escreve(const string ficheiro) const {
	stringstream out {};
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
    for (vector<Emprestimo*>::const_iterator it = emprestimos_livro.begin(); it != emprestimos_livro.end(); it++) {
        if (*it == NULL) out << "0;";
        else out << (*it)->get_ID() << ";";
    }
    out << endl;
    priority_queue<Pedido> peds {pedidos};
    while (!peds.empty()) {
        out << peds.top().get_ID() << "; ";
        peds.pop();
    }
    out << endl;
	ofstream myfile (ficheiro, ios::app);
	if (myfile.is_open()) {
		myfile << out.str();
		myfile.close();
	}
	else throw Ficheiro_indisponivel(ficheiro);
}
