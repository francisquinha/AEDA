
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <fstream>

#include "Biblio.h"
#include "Excecao.h"

using namespace std;

/** @file
 *
 * @brief Source das funcoes da Biblioteca.
 *
 * Apos os menus, estas sao as funcoes chamadas pelas varias opcoes da aplicacao.
 **/

/* com dynamic_cast o apontador lo so nao e nulo se (*it) for do tipo Livro_old */
vector<Livro_old*> Biblioteca::get_livros_old() {
	vector<Livro_old*> liv_old {};
	Livro_old* lo{};
	for (vector<Livro*>::const_iterator it = livros.begin(); it != livros.end(); it++){
		lo = dynamic_cast<Livro_old*>(*it);
		if (lo != 0){
			liv_old.push_back(lo);
		}
	}
	return liv_old;
}

/* com dynamic_cast o apontador lo so nao e nulo se (*it) for do tipo Livro_old */
vector<Livro*> Biblioteca::get_livros() {
	vector<Livro*> liv {};
	Livro_old* lo{};
	for (vector<Livro*>::const_iterator it = livros.begin(); it != livros.end(); it++){
		lo = dynamic_cast<Livro_old*>(*it);
		if (lo == 0){
			liv.push_back(*it);
		}
	}
	return liv;
}

/* com dynamic_cast o apontador eo so nao e nulo se (*it) for do tipo Emprestimo_old */
vector<Emprestimo_old*> Biblioteca::get_emprestimos_old() {
	vector<Emprestimo_old*> emp_old {};
	Emprestimo_old* eo{};
	for (vector<Emprestimo*>::const_iterator it = emprestimos.begin(); it != emprestimos.end(); it++){
		eo = dynamic_cast<Emprestimo_old*>(*it);
		if (eo != 0){
			emp_old.push_back(eo);
		}
	}
	return emp_old;
}

/* com dynamic_cast o apontador eo so nao e nulo se (*it) for do tipo Emprestimo_old */
vector<Emprestimo*> Biblioteca::get_emprestimos() {
	vector<Emprestimo*> emp {};
	Emprestimo_old* eo{};
	for (vector<Emprestimo*>::const_iterator it = emprestimos.begin(); it != emprestimos.end(); it++){
		eo = dynamic_cast<Emprestimo_old*>(*it);
		if (eo == 0){
			emp.push_back(*it);
		}
	}
	return emp;
}

/* com dynamic_cast o apontador fo so nao e nulo se (*it) for do tipo Funcionario_old */
vector<Funcionario_old*> Biblioteca::get_funcionarios_old() {
	vector<Funcionario_old*> fun_old {};
	Funcionario_old* fo{};
	for (vector<Funcionario*>::const_iterator it = funcionarios.begin(); it != funcionarios.end(); it++){
		fo = dynamic_cast<Funcionario_old*>(*it);
		if (fo != 0){
			fun_old.push_back(fo);
		}
	}
	return fun_old;
}

/* aqui obtemos os funcionarios todos, independentemente da subclasse */
vector<Funcionario*>Biblioteca::get_funcionarios_todos() {
	return funcionarios;
}

/* com dynamic_cast o apontador sp so nao e nulo se (*it) for do tipo Supervisor */
vector<Funcionario*>Biblioteca::get_supervisores() {
	vector<Funcionario*> supervisores {};
	Supervisor* sp {};
	for (vector<Funcionario*>::const_iterator it = funcionarios.begin(); it != funcionarios.end(); it++) {
		sp = dynamic_cast<Supervisor*>(*it);
		if (sp != 0) {
			supervisores.push_back(*it);
		}
	}
	return supervisores;
}

/* com dynamic_cast os apontadores sp, ad e fo so nao sao nulos se (*it)
 * for do tipo Supervisor, Administrador e Funcionario_old, respectivamente */
vector<Funcionario*>Biblioteca::get_funcionarios() {
	vector<Funcionario*> funcionarios_n_sup {};
	Supervisor* sp {};
	Administrador* ad {};
	Funcionario_old* fo {};
	for (vector<Funcionario*>::const_iterator it = funcionarios.begin(); it != funcionarios.end(); it++) {
		sp = dynamic_cast<Supervisor*>(*it);
		ad = dynamic_cast<Administrador*>(*it);
		fo = dynamic_cast<Funcionario_old*>(*it);
		if (sp == 0 and ad == 0 and fo == 0) {
			funcionarios_n_sup.push_back(*it);
		}
	}
	return funcionarios_n_sup;
}

/* com dynamic_cast o apontador lo so nao e nulo se (*it) for do tipo Leitor_old */
vector<Leitor_old*> Biblioteca::get_leitores_old() {
	vector<Leitor_old*> lei_old {};
	Leitor_old* lo{};
	for (vector<Leitor*>::const_iterator it = leitores.begin(); it != leitores.end(); it++){
		lo = dynamic_cast<Leitor_old*>(*it);
		if (lo != 0){
			lei_old.push_back(lo);
		}
	}
	return lei_old;
}

/* com dynamic_cast o apontador lo so nao e nulo se (*it) for do tipo Leitor_old */
vector<Leitor*> Biblioteca::get_leitores() {
	vector<Leitor*> lei {};
	Leitor_old* lo{};
	for (vector<Leitor*>::const_iterator it = leitores.begin(); it != leitores.end(); it++){
		lo = dynamic_cast<Leitor_old*>(*it);
		if (lo == 0){
			lei.push_back(*it);
		}
	}
	return lei;
}

vector<Utilizador*>Biblioteca::get_utilizadores() {
	return utilizadores;
}

/* codigo desnecessario

void Biblioteca::set_emprestimos(vector<Emprestimo*> emp) {
	emprestimos = emp;
}

void Biblioteca::set_funcionarios(vector<Funcionario*> func) {
	funcionarios = func;
}

void Biblioteca::set_utilizadores(vector<Utilizador*> util) {
	utilizadores = util;
}

void Biblioteca::set_leitores(vector<Leitor*> leit) {
	leitores = leit;
}

void Biblioteca::set_livros(vector<Livro*> livr) {
	livros = livr;
}
*/

void Biblioteca::adiciona_livro(Livro* lv) {
	livros.push_back(lv);
	cout << "Livro adicionado." << endl;
}

void Biblioteca::adiciona_livro_old(Livro_old* lv) {
	livros.push_back(lv);
}

void Biblioteca::adiciona_funcionario_old(Funcionario_old* fc) {
	funcionarios.push_back(fc);
}

void Biblioteca::adiciona_funcionario(Funcionario* fc) {
	funcionarios.push_back(fc);
	cout << "Funcionario adicionado." << endl;
}

void Biblioteca::adiciona_leitor_old(Leitor_old* lt) {
	leitores.push_back(lt);
}

void Biblioteca::adiciona_leitor(Leitor* lt) {
	leitores.push_back(lt);
	cout << "Leitor adicionado." << endl;
}

void Biblioteca::adiciona_utilizador(Utilizador* ut) {
	utilizadores.push_back(ut);
	cout << "Utilizador adicionado." << endl;
}

vector<string> Biblioteca::get_temas() {
	vector<string> tem {};
	vector<Livro*> livrs {get_livros()};
	for (vector<Livro*>::const_iterator it = livrs.begin(); it !=  livrs.end(); it++) {
		bool adicionar{true};
		for (vector<string>::const_iterator itt = tem.begin(); itt != tem.end(); itt++) {
			if ((*itt) == (*it)->get_tema()) {
				adicionar = false; /* apenas queremos colocar cada tema uma vez */
			}
		}
		if (adicionar) tem.push_back((*it)->get_tema());
	}
	sort(tem.begin(), tem.end()); /* queremos os temas ordenados alfabeticamente*/
	return tem;
}

vector<Livro*> Biblioteca::get_livros_tema(string tem) {
	vector<Livro*> lv {};
	vector<Livro*> livrs {get_livros()};
	for (vector<Livro*>::const_iterator it = livrs.begin(); it !=  livrs.end(); it++) {
		if ((*it)->get_tema() == tem) {
			lv.push_back(*it);
		}
	}
	return lv;
}

vector<Livro*> Biblioteca::get_livros_disponiveis() {
	vector<Livro*> lv {};
	vector<Livro*> livrs {get_livros()};
	for (vector<Livro*>::const_iterator it = livrs.begin(); it !=  livrs.end(); it++) {
		if ((*it)->get_emprestado() == false) { /* se esta disponivel, emprestado = false */
			lv.push_back(*it);
		}
	}
	return lv;
}

vector<Livro*> Biblioteca::get_livros_emprestados() {
	vector<Livro*> lv {};
	vector<Livro*> livrs {get_livros()};
	for (vector<Livro*>::const_iterator it = livrs.begin(); it !=  livrs.end(); it++) {
		if ((*it)->get_emprestado() == true) { /* se esta emprestado, emprestado = true */
			lv.push_back(*it);
		}
	}
	return lv;
}

/* apagar um elemento de um vetor com erase(it) pode dar problemas com o iterador,
 * porque se apagarmos o ultimo elemento, o iterador nunca chega ao fim.
 * mas como estamos a fazer return logo depois, nao deve haver problema. */
bool Biblioteca::remove_livro(long id) {
	Livro_old* lvo {};
	for (vector<Livro*>::const_iterator it = livros.begin(); it != livros.end(); it++) {
		lvo = dynamic_cast<Livro_old*>(*it);
		if ((*it)->get_ID() == id and lvo == 0) {
			Livro_old* lo = new Livro_old{(*it)->get_ID(), (*it)->get_titulo(), (*it)->get_autores(),
				(*it)->get_tema(), (*it)->get_ISBN(), (*it)->get_cota(), (*it)->get_num_paginas(),
				(*it)->get_edicao(), (*it)->get_emprestado(), (*it)->get_data_emp(), time(0), false};
			adiciona_livro_old(lo); /* ao remover um livro adicionamo-lo como Livro_old */
			livros.erase(it);
			cout << endl << "Livro removido." << endl;
			return true;
		}
	}
	throw Object_nao_existe(id);
}

/* distribuicao dos funcionarios de forma uniforme pelos supervisores.
 * para garantir o equilibrio, usamos o modulo numero de supervisores*/
void Biblioteca::distribui_funcionarios() {
	vector<Funcionario*> func_sup {};
	vector<Funcionario*> supervisores {get_supervisores()};
	vector<Funcionario*> funcionarios {get_funcionarios()};
	unsigned long num_sup {supervisores.size()};
	for (vector<Funcionario*>::const_iterator it = supervisores.begin(); it != supervisores.end(); it++) {
		(*it)->set_func_sup(func_sup);
	}
	for (unsigned int i {0}; i<funcionarios.size(); i++) {
		(supervisores[i%num_sup]->adiciona_func_sup(funcionarios[i]));
	}
}

/* apagar um elemento de um vetor com erase(it) pode dar problemas com o iterador,
 * porque se apagarmos o ultimo elemento, o iterador nunca chega ao fim.
 * mas como estamos a fazer return logo depois, nao deve haver problema. */
bool Biblioteca::remove_funcionario(long id) {
	bool encontrado {false};
	for (vector<Funcionario*>::const_iterator it = funcionarios.begin(); it != funcionarios.end(); it++) {
		if ((*it)->get_ID() == id) {
			encontrado = true;
			Funcionario_old* fo = new Funcionario_old{(*it)->get_ID(), (*it)->get_nome(), time(0), false};
			adiciona_funcionario_old(fo); /* ao remover um funcionario adicionamo-lo como Funcionario_old */
			funcionarios.erase(it);
		}
	}
	if (encontrado) {
		distribui_funcionarios();
		cout << endl << "Funcionario removido." << endl;
		return true;
	}
	throw Object_nao_existe(id);
}

/* apagar um elemento de um vetor com erase(it) pode dar problemas com o iterador,
 * porque se apagarmos o ultimo elemento, o iterador nunca chega ao fim.
 * mas como estamos a fazer return logo depois, nao deve haver problema. */
bool Biblioteca::remove_leitor(long id) {
	Leitor_old* lto {};
	for (vector<Leitor*>::const_iterator it = leitores.begin(); it != leitores.end(); it++) {
		lto = dynamic_cast<Leitor_old*>(*it);
		if ((*it)->get_ID() == id and lto == 0) {
			if ((*it)->get_emp_leit().size() == 0) {
				Leitor_old* lo = new Leitor_old{(*it)->get_ID(), (*it)->get_nome(), (*it)->get_telefone(), (*it)->get_email(), time(0), false};
				adiciona_leitor_old(lo); /* ao remover um leitor adicionamo-lo como Leitor_old */
				leitores.erase(it);
				cout << endl << "Leitor removido." << endl;
				return true;
			}
			else { /* nao podemos remover um leitor com emprestimos por devolver */
				throw Emprestimos_por_devolver(id, (*it)->get_nome(),(*it)->get_telefone(), (*it)->get_email(), (*it)->get_emp_leit());
			}
		}
	}
	throw Object_nao_existe(id);
}

void Biblioteca::adiciona_emprestimo_old(Emprestimo_old* ep) {
	emprestimos.push_back(ep);
}

void Biblioteca::adiciona_emprestimo(Emprestimo* ep) {
	Livro* lv = ep->get_livro();
	Leitor* lt = ep->get_leitor();
	vector<Emprestimo*> ep_lt = lt->get_emp_leit();
	if (lv->get_emprestado() == false) {
		if (ep_lt.size() < 3) {
			lv->set_emprestado(true);
			lv->set_ID_ep(ep->get_ID());
			lv->set_data_emp(ep->get_data());
			lt->adiciona_emp_leit(ep);
			emprestimos.push_back(ep);
			cout << "Emprestimo adicionado." << endl;
		}
		else { /* nao podemos adicionar mais emprestimos a um leitor que ja tenha 3 */
			throw Maximo_emprestimos(lt->get_ID(), lt->get_nome(), lt->get_telefone(), lt->get_email(), lt->get_emp_leit());
		}
	}
	else { /* nao podemos emprestar um livro que ja esteja emprestado */
		throw Livro_indisponivel(lv->get_ID(), lv->get_titulo(), lv->get_autores(), lv->get_tema(), lv->get_ISBN(),
				lv->get_cota(), lv->get_num_paginas(), lv->get_edicao(), lv->get_emprestado(), lv-> get_ID_ep(),
				lv->get_data_emp());
	}
}

/* apagar um elemento de um vetor com erase(it) pode dar problemas com os iteradores,
 * porque se apagarmos o ultimo elemento, nunca chegam ao fim.
 * mas como estamos a adicionar um elemento antes de apagar, nao deve haver problema */
bool Biblioteca::remove_emprestimo(long id) {
	Emprestimo_old* epo {};
	for (vector<Emprestimo*>::const_iterator it = emprestimos.begin(); it != emprestimos.end(); it++) {
		epo = dynamic_cast<Emprestimo_old*>(*it);
		if ((*it)->get_ID() == id and epo == 0) {
			int dias {(*it)->get_atraso()};
			if (dias > 0) { /* se a devolucao estiver atrasada, temos que cobrar multa */
				cout << endl << "Devolucao de livro " << dias << " dia(s) em atraso. Deve efetuar o pagamento de "
						<< (*it)->get_multa() << "euros." << endl;
			}
			((*it)->get_livro())->set_emprestado(false);
			((*it)->get_livro())->set_ID_ep(0);
			((*it)->get_livro())->set_data_emp( {});
			((*it)->get_leitor())->remove_emp_leit(id);
			Emprestimo_old* eo = new Emprestimo_old{(*it)->get_ID(), (*it)->get_livro(), (*it)->get_funcionario(), (*it)->get_leitor(), (*it)->get_data(), false};
			adiciona_emprestimo_old(eo); /* ao remover um emprestimo adicionamo-lo como Emprestimo_old */
			emprestimos.erase(it);
			cout << endl << "Emprestimo removido." << endl;
			return true;
		}
	}
	throw Object_nao_existe(id);
}

/* apagar um elemento de um vetor com erase(it) pode dar problemas com o iterador,
 * porque se apagarmos o ultimo elemento, o iterador nunca chega ao fim.
 * mas como estamos a fazer return logo depois, nao deve haver problema. */
bool Biblioteca::remove_utilizador(long id) {
	for (vector<Utilizador*>::const_iterator it = utilizadores.begin(); it != utilizadores.end(); it++) {
		if ((*it)->get_ID() == id) {
			utilizadores.erase(it);
			cout << endl << "Utilizador removido." << endl;
			return true;
		}
	}
	throw Object_nao_existe(id);
}

vector<Emprestimo*> Biblioteca::get_emprestimos_atrasados() {
	vector<Emprestimo*> atrasados {};
	vector<Emprestimo*> emp {get_emprestimos()};
	for (vector<Emprestimo*>::const_iterator it = emp.begin(); it != emp.end(); it++) {
		if ((*it)->get_atraso() > 0) {
			atrasados.push_back(*it);
		}
	}
	return atrasados;
}

/* impressao de emprestimos atrasados organizador por leitor, para fazer os contactos */
string Biblioteca::imprime_emprestimos_atrasados() {
	stringstream out {};
	vector<Emprestimo*> atrasados {get_emprestimos_atrasados()};
	vector<Leitor*> lt_atrasados {};
	vector<long> id_lt {};
	long id {};
	bool acrescenta {true};
	out << "EMPRESTIMOS ATRASADOS" << endl << endl;
	for (vector<Emprestimo*>::const_iterator it = atrasados.begin(); it != atrasados.end(); it++) {
		id = (*it)->get_leitor()->get_ID();
		acrescenta=true;
		for (vector<long>::const_iterator itid = id_lt.begin(); itid!= id_lt.end(); itid++) {
			if ((*itid) == id) acrescenta=false;
		}
		if (acrescenta) {
			id_lt.push_back(id);
			lt_atrasados.push_back((*it)->get_leitor());
		}
	}
	for (vector<Leitor*>::const_iterator itl = lt_atrasados.begin(); itl!= lt_atrasados.end(); itl++) {
		out << "LEITOR" << endl;
		out << (*itl)->imprime();
		vector<Emprestimo*> ep_atrasados {(*itl)->get_emprestimos_atrasados()};
		out << "EMPRESTIMOS" << endl;
		for (vector<Emprestimo*>::const_iterator ite = ep_atrasados.begin(); ite != ep_atrasados.end(); ite++) {
			out << (*ite)->imprime();
		}
		out << endl;
	}
	return out.str();
}

bool Biblioteca::promove_funcionario_supervisor(long id) {
	vector<Funcionario*> func_sup {};
	vector<Funcionario*> supervisores {get_supervisores()};
	for (vector<Funcionario*>::const_iterator it = funcionarios.begin(); it != funcionarios.end(); it++) {
		if ((*it)->get_ID() == id) {
			Supervisor* sp = new Supervisor {id, (*it)->get_nome(), func_sup};
			funcionarios.erase(it);
			funcionarios.push_back(sp);
			/* sempre que ha alteracoes nos funcionarios e necessario distribui-los para garantir o equilibrio */
			distribui_funcionarios();
			return true;
		}
	}
	throw Object_nao_existe(id);
}

bool Biblioteca::despromove_supervisor_funcionorario(long id) {
	vector<Funcionario*> supervisores {get_supervisores()};
	for (vector<Funcionario*>::const_iterator it = supervisores.begin(); it != supervisores.end(); it++) {
		if ((*it)->get_ID() == id) {
			Funcionario* fc=new Funcionario {id, (*it)->get_nome(), false};
			funcionarios.erase(it);
			funcionarios.push_back(fc);
			/* sempre que ha alteracoes nos funcionarios e necessario distribui-los para garantir o equilibrio */
			distribui_funcionarios();
			return true;
		}
	}
	throw Object_nao_existe(id);
}

string Biblioteca::imprime_livros_old() {
	stringstream out {};
	vector<Livro_old*> livrs {get_livros_old()};
	out << "LIVROS ANTIGOS" << endl << endl;
	for (vector<Livro_old*>::const_iterator it = livrs.begin(); it != livrs.end(); it++) {
		out << (*it)->imprime() << endl;
	}
	return out.str();
}

string Biblioteca::imprime_livros() {
	stringstream out {};
	vector<Livro*> livrs {get_livros()};
	out << "LIVROS" << endl << endl;
	for (vector<Livro*>::const_iterator it = livrs.begin(); it != livrs.end(); it++) {
		out << (*it)->imprime() << endl;
	}
	return out.str();
}

string Biblioteca::imprime_livros_tema(string tem) {
	stringstream out {};
	vector<Livro*> livrs {get_livros_tema(tem)};
	if (livrs.size() == 0) {
		out << "Nao existem livros com o tema " << tem << "." << endl << endl;
	}
	else {
		out << "LIVROS COM TEMA: " << tem << endl << endl;
		for (vector<Livro*>::const_iterator it = livrs.begin(); it != livrs.end(); it++) {
			out << (*it)->imprime() << endl;
		}
	}
	return out.str();
}

string Biblioteca::imprime_livros_disponiveis() {
	stringstream out {};
	vector<Livro*> livrs {get_livros_disponiveis()};
	if (livrs.size() == 0) {
		out << "Nao existem livros disponiveis." << endl << endl;
	}
	else {
		out << "LIVROS DISPONIVEIS" << endl << endl;
		for (vector<Livro*>::const_iterator it = livrs.begin(); it != livrs.end(); it++) {
			out << (*it)->imprime() << endl;
		}
	}
	return out.str();
}

string Biblioteca::imprime_livros_emprestados() {
	stringstream out {};
	vector<Livro*> livrs {get_livros_emprestados()};
	if (livrs.size() == 0) {
		out << "Nao existem livros emprestados." << endl << endl;
	}
	else {
		out << "LIVROS EMPRESTADOS" << endl << endl;
		for (vector<Livro*>::const_iterator it = livrs.begin(); it != livrs.end(); it++) {
			out << (*it)->imprime() << endl;
		}
	}
	return out.str();
}

string Biblioteca::imprime_funcionarios_old() {
	stringstream out {};
	out << "FUNCIONARIOS ANTIGOS" << endl << endl;
	vector<Funcionario_old*> funcios {get_funcionarios_old()};
	for (vector<Funcionario_old*>::const_iterator it = funcios.begin(); it != funcios.end(); it++) {
		out << (*it)->imprime() << endl;
	}
	return out.str();
}

string Biblioteca::imprime_funcionarios() {
	stringstream out {};
	out << "FUNCIONARIOS" << endl << endl;
	vector<Funcionario*> funcios {get_funcionarios()};
	for (vector<Funcionario*>::const_iterator it = funcios.begin(); it != funcios.end(); it++) {
		out << (*it)->imprime() << endl;
	}
	return out.str();
}

string Biblioteca::imprime_supervisores() {
	stringstream out {};
	out << "SUPERVISORES" << endl << endl;
	vector<Funcionario*> supers {get_supervisores()};
	for (vector<Funcionario*>::const_iterator it = supers.begin(); it != supers.end(); it++) {
		out << (*it)->imprime() << endl;
	}
	return out.str();
}

string Biblioteca::imprime_leitores_old() {
	stringstream out {};
	out << "LEITORES ANTIGOS" << endl << endl;
	vector<Leitor_old*> lei_old {get_leitores_old()};
	for (vector<Leitor_old*>::const_iterator it = lei_old.begin(); it != lei_old.end(); it++) {
		out << (*it)->imprime() << endl;
	}
	return out.str();
}

string Biblioteca::imprime_leitores() {
	stringstream out {};
	out << "LEITORES" << endl << endl;
	vector<Leitor*> lei {get_leitores()};
	for (vector<Leitor*>::const_iterator it = lei.begin(); it != lei.end(); it++) {
		out << (*it)->imprime() << endl;
	}
	return out.str();
}

string Biblioteca::imprime_emprestimos_old() {
	stringstream out {};
	out << "EMPRESTIMOS ANTIGOS" << endl << endl;
	vector<Emprestimo_old*> emp_old {get_emprestimos_old()};
	for (vector<Emprestimo_old*>::const_iterator it = emp_old.begin(); it != emp_old.end(); it++) {
		out << (*it)->imprime() << endl;
	}
	return out.str();
}

string Biblioteca::imprime_emprestimos() {
	stringstream out {};
	vector<Emprestimo*> emp {get_emprestimos()};
	out << "EMPRESTIMOS" << endl << endl;
	for (vector<Emprestimo*>::const_iterator it = emp.begin(); it != emp.end(); it++) {
		out << (*it)->imprime() << endl;
	}
	return out.str();
}

string Biblioteca::imprime_utilizadores() {
	stringstream out {};
	out << "UTILIZADORES" << endl << endl;
	for (vector<Utilizador*>::const_iterator it = utilizadores.begin(); it != utilizadores.end(); it++) {
		out << (*it)->imprime() << endl;
	}
	return out.str();
}

string Biblioteca::imprime() {
	stringstream out {};
	out << imprime_livros() << endl
		<< imprime_funcionarios() << endl
		<< imprime_supervisores() << endl
		<< imprime_leitores() << endl
		<< imprime_emprestimos();
	return out.str();
}

void Biblioteca::escreve_livros_old(string ficheiro) {
	vector<Livro_old*> livrs {get_livros_old()};
	ofstream myfile(ficheiro);
	myfile << "";
	myfile.close();
	for (vector<Livro_old*>::const_iterator it = livrs.begin(); it != livrs.end(); it++) {
		(*it)->escreve(ficheiro);
	}
}

void Biblioteca::escreve_livros(string ficheiro) {
	vector<Livro*> livrs {get_livros()};
	ofstream myfile(ficheiro);
	myfile << "";
	myfile.close();
	for (vector<Livro*>::const_iterator it = livrs.begin(); it != livrs.end(); it++) {
		(*it)->escreve(ficheiro);
	}
}

void Biblioteca::escreve_funcionarios_old(string ficheiro) {
	ofstream file_f(ficheiro);
	file_f << "";
	file_f.close();
	vector<Funcionario_old*> funo {get_funcionarios_old()};
	for (vector<Funcionario_old*>::const_iterator it = funo.begin(); it != funo.end(); it++) {
		(*it)->escreve(ficheiro);
	}
}

void Biblioteca::escreve_funcionarios(string ficheiro) {
	ofstream file_f(ficheiro);
	file_f << "";
	file_f.close();
	vector<Funcionario*> fun {get_funcionarios()};
	for (vector<Funcionario*>::const_iterator it = fun.begin(); it != fun.end(); it++) {
		(*it)->escreve(ficheiro);
	}
}

void Biblioteca::escreve_supervisores(string ficheiro) {
	ofstream file_f(ficheiro);
	file_f << "";
	file_f.close();
	vector<Funcionario*> sup {get_supervisores()};
	for (vector<Funcionario*>::const_iterator it = sup.begin(); it != sup.end(); it++) {
		(*it)->escreve(ficheiro);
	}
}

void Biblioteca::escreve_leitores_old(string ficheiro) {
	ofstream myfile(ficheiro);
	myfile << "";
	myfile.close();
	vector<Leitor_old*> lei_old {get_leitores_old()};
	for (vector<Leitor_old*>::const_iterator it = lei_old.begin(); it != lei_old.end(); it++) {
		(*it)->escreve(ficheiro);
	}
}

void Biblioteca::escreve_leitores(string ficheiro) {
	ofstream myfile(ficheiro);
	myfile << "";
	myfile.close();
	vector<Leitor*> lei {get_leitores()};
	for (vector<Leitor*>::const_iterator it = lei.begin(); it != lei.end(); it++) {
		(*it)->escreve(ficheiro);
	}
}

void Biblioteca::escreve_emprestimos_old(string ficheiro) {
	ofstream myfile(ficheiro);
	myfile << "";
	myfile.close();
	vector<Emprestimo_old*> emp_old {get_emprestimos_old()};
	for (vector<Emprestimo_old*>::const_iterator it = emp_old.begin(); it != emp_old.end(); it++) {
		(*it)->escreve(ficheiro);
	}
}

void Biblioteca::escreve_emprestimos(string ficheiro) {
	ofstream myfile(ficheiro);
	myfile << "";
	myfile.close();
	vector<Emprestimo*> emp {get_emprestimos()};
	for (vector<Emprestimo*>::const_iterator it = emp.begin(); it != emp.end(); it++) {
		(*it)->escreve(ficheiro);
	}
}

void Biblioteca::escreve_utilizadores(string ficheiro) {
	ofstream myfile(ficheiro);
	myfile << "";
	myfile.close();
	for (vector<Utilizador*>::const_iterator it = utilizadores.begin(); it != utilizadores.end(); it++) {
		(*it)->escreve(ficheiro);
	}
}

/* e necessario apanhar as possiveis excecoes em caso de os ficheiros nao estarem disponiveis */
void Biblioteca::escreve(string ficheiro_lvo, string ficheiro_lv, string ficheiro_fco,
		string ficheiro_fc, string ficheiro_sp, string ficheiro_lto, string ficheiro_lt,
		string ficheiro_epo, string ficheiro_ep, string ficheiro_ut) {
	try {
		escreve_livros_old(ficheiro_lvo);
	}
	catch (Ficheiro_indisponivel &fic) {
		ostringstream ostr{};
		ostr << fic;
		cout << ostr.str();
	}
	try {
		escreve_livros(ficheiro_lv);
	}
	catch (Ficheiro_indisponivel &fic) {
		ostringstream ostr{};
		ostr << fic;
		cout << ostr.str();
	}
	try {
		escreve_funcionarios_old(ficheiro_fco);
	}
	catch (Ficheiro_indisponivel &fic) {
		ostringstream ostr{};
		ostr << fic;
		cout << ostr.str();
	}
	try {
		escreve_funcionarios(ficheiro_fc);
	}
	catch (Ficheiro_indisponivel &fic) {
		ostringstream ostr{};
		ostr << fic;
		cout << ostr.str();
	}
	try {
		escreve_supervisores(ficheiro_sp);
	}
	catch (Ficheiro_indisponivel &fic) {
		ostringstream ostr{};
		ostr << fic;
		cout << ostr.str();
	}
	try {
		escreve_leitores_old(ficheiro_lto);
	}
	catch (Ficheiro_indisponivel &fic) {
		ostringstream ostr{};
		ostr << fic;
		cout << ostr.str();
	}
	try {
		escreve_leitores(ficheiro_lt);
	}
	catch (Ficheiro_indisponivel &fic) {
		ostringstream ostr{};
		ostr << fic;
		cout << ostr.str();
	}
	try {
		escreve_emprestimos(ficheiro_ep);
	}
	catch (Ficheiro_indisponivel &fic) {
		ostringstream ostr{};
		ostr << fic;
		cout << ostr.str();
	}
	try {
		escreve_emprestimos_old(ficheiro_epo);
	}
	catch (Ficheiro_indisponivel &fic) {
		ostringstream ostr{};
		ostr << fic;
		cout << ostr.str();
	}
	try {
		escreve_utilizadores(ficheiro_ut);
	}
	catch (Ficheiro_indisponivel &fic) {
		ostringstream ostr{};
		ostr << fic;
		cout << ostr.str();
	}
}

void Biblioteca::le_livros_old(string ficheiro) {
	ifstream islv(ficheiro);
	if (!islv) throw Ficheiro_indisponivel(ficheiro);
	string ids {}, tit {}, auts {}, tem {}, isbns {}, cot {}, num_pags {}, edis {};
	string epts {}, ideps {}, ymds {}, ymdsf {}, yearsf {}, monthsf {}, daysf {};
	istringstream autss {};
	struct tm* dtfinfo {};
	while (!islv.eof()) {
		getline(islv, ids);
		getline(islv, tit);
		getline(islv, auts);
		getline(islv, tem);
		getline(islv, isbns);
		getline(islv, cot);
		getline(islv, num_pags);
		getline(islv, edis);
		getline(islv, ymdsf);
		long id = atol(ids.c_str());
		vector<string>aut {};
		string autor {};
		stringstream autss(auts);
		while (getline(autss, autor, ';')) {
			aut.push_back(autor);
		}
		long isbn = atol(isbns.c_str());
		int num_pag = atoi(num_pags.c_str());
		int edi = atoi(edis.c_str());
		time_t dtf {};
		if (ymdsf == "0") dtf=0;
		else {
			stringstream ymdssf(ymdsf);
			getline(ymdssf, yearsf, '/');
			getline(ymdssf, monthsf, '/');
			getline(ymdssf, daysf);
			int yearf = atoi(yearsf.c_str());
			int monthf = atoi(monthsf.c_str());
			int dayf = atoi(daysf.c_str());
			time (&dtf);
			dtfinfo = localtime ( &dtf );
			dtfinfo->tm_year = yearf - 1900;
			dtfinfo->tm_mon = monthf - 1;
			dtfinfo->tm_mday = dayf;
			dtf = mktime (dtfinfo);
		}
		if (ids != "") {
			Livro_old* lo = new Livro_old {id, tit, aut, tem, isbn, cot, num_pag, edi, 0, 0, 0, dtf, true};
			adiciona_livro_old(lo);
		}
	}
	islv.close();
}

void Biblioteca::le_livros(string ficheiro) {
	ifstream islv(ficheiro);
	if (!islv) throw Ficheiro_indisponivel(ficheiro);
	string ids {}, tit {}, auts {}, tem {}, isbns {}, cot {}, num_pags {}, edis {}, epts {}, ideps {}, ymds {};
	istringstream autss {};
	while (!islv.eof()) {
		getline(islv, ids);
		getline(islv, tit);
		getline(islv, auts);
		getline(islv, tem);
		getline(islv, isbns);
		getline(islv, cot);
		getline(islv, num_pags);
		getline(islv, edis);
		getline(islv, epts);
		getline(islv, ideps);
		getline(islv, ymds);
		long id = atol(ids.c_str());
		vector<string>aut {};
		string autor {};
		stringstream autss(auts);
		while (getline(autss, autor, ';')) {
			aut.push_back(autor);
		}
		long isbn = atol(isbns.c_str());
		int num_pag = atoi(num_pags.c_str());
		int edi = atoi(edis.c_str());
		if (ids != "") {
			Livro* lv = new Livro {id, tit, aut, tem, isbn, cot, num_pag, edi, 0, 0, 0, true};
			adiciona_livro(lv);
		}
	}
	islv.close();
}

void Biblioteca::le_funcionarios_old(string ficheiro) {
	ifstream isfc(ficheiro);
	if (!isfc) throw Ficheiro_indisponivel(ficheiro);
	string ids {}, nom {}, ymds {}, years{}, months{}, days{};
	long id {};
	time_t dt {};
	struct tm* dtinfo {};
	int year {}, month {}, day {};
	while (!isfc.eof()) {
		getline(isfc, ids);
		getline(isfc, nom);
		getline(isfc, ymds);
		id = atol(ids.c_str());
		if (ymds == "0") dt=0;
		else {
			stringstream ymdss(ymds);
			getline(ymdss, years, '/');
			getline(ymdss, months, '/');
			getline(ymdss, days);
			year = atoi(years.c_str());
			month = atoi(months.c_str());
			day = atoi(days.c_str());
			time (&dt);
			dtinfo = localtime ( &dt );
			dtinfo->tm_year = year - 1900;
			dtinfo->tm_mon = month - 1;
			dtinfo->tm_mday = day;
			dt = mktime (dtinfo);
		}
		if (ids != "") {
			Funcionario_old* fco = new Funcionario_old {id, nom, dt, true};
			adiciona_funcionario_old(fco);
		}
	}
	isfc.close();
}

void Biblioteca::le_funcionarios(string ficheiro) {
	ifstream isfc(ficheiro);
	if (!isfc) throw Ficheiro_indisponivel(ficheiro);
	string ids {}, nom {};
	long id {};
	while (!isfc.eof()) {
		getline(isfc, ids);
		getline(isfc, nom);
		id = atol(ids.c_str());
		if (ids != "") {
			Funcionario* fc = new Funcionario {id, nom, true};
			adiciona_funcionario(fc);
		}
	}
	isfc.close();
}

void Biblioteca::le_supervisores(string ficheiro) {
	ifstream issp(ficheiro);
	if (!issp) throw Ficheiro_indisponivel(ficheiro);
	string ids {}, nom {}, fsids {};
	istringstream fsidss {};
	long id {}, fsid {};
	bool encontrado {false};
	vector<Funcionario*> func_sup {};
	string funsid {};
	while (!issp.eof()) {
		getline(issp, ids);
		getline(issp, nom);
		getline(issp, fsids);
		id = atol(ids.c_str());
		stringstream fsidss(fsids);
		func_sup= {};
		while(getline(fsidss, funsid, ';')) {
			encontrado=false;
			fsid = atol(funsid.c_str());
			for (vector<Funcionario*>::const_iterator it = funcionarios.begin(); it != funcionarios.end(); it++) {
				if ((*it)->get_ID() == fsid) {
					func_sup.push_back(*it);
					encontrado = true;
				}
			}
			if (!encontrado) throw Object_nao_existe(fsid);
		}
		if (ids != "") {
			Supervisor* sp = new Supervisor {id, nom, func_sup};
			adiciona_funcionario(sp);
		}
	}
	issp.close();
}

void Biblioteca::le_leitores_old(string ficheiro) {
	ifstream islt(ficheiro);
	if (!islt) throw Ficheiro_indisponivel(ficheiro);
	string ids {}, nom {}, tels {}, eml {}, ymds {}, years{}, months{}, days{};
	long id {}, tel {};
	time_t dt {};
	struct tm* dtinfo {};
	int year {}, month {}, day {};
	while (!islt.eof()) {
		getline(islt, ids);
		getline(islt, nom);
		getline(islt, tels);
		getline(islt, eml);
		getline(islt, ymds);
		id = atol(ids.c_str());
		tel = atol(tels.c_str());
		if (ymds == "0") dt=0;
		else {
			stringstream ymdss(ymds);
			getline(ymdss, years, '/');
			getline(ymdss, months, '/');
			getline(ymdss, days);
			year = atoi(years.c_str());
			month = atoi(months.c_str());
			day = atoi(days.c_str());
			time (&dt);
			dtinfo = localtime ( &dt );
			dtinfo->tm_year = year - 1900;
			dtinfo->tm_mon = month - 1;
			dtinfo->tm_mday = day;
			dt = mktime (dtinfo);
		}
		if (ids != "") {
			Leitor_old* lto = new Leitor_old {id,nom,tel,eml,dt,true};
			adiciona_leitor_old(lto);
		}
	}
	islt.close();
}

void Biblioteca::le_leitores(string ficheiro) {
	ifstream islt(ficheiro);
	if (!islt) throw Ficheiro_indisponivel(ficheiro);
	string ids {}, nom {}, tels {}, eml {}, epids {};
	long id {}, tel {};
	istringstream epidss {};
	string empids {};
	while (!islt.eof()) {
		getline(islt, ids);
		getline(islt, nom);
		getline(islt, tels);
		getline(islt, eml);
		getline(islt, epids);
		id = atol(ids.c_str());
		tel = atol(tels.c_str());
		if (ids != "") {
			Leitor* lt = new Leitor {id,nom,tel,eml,{}, true};
			adiciona_leitor(lt);
		}
	}
	islt.close();
}

void Biblioteca::le_emprestimos_old(string ficheiro) {
	ifstream isep(ficheiro);
	if (!isep) throw Ficheiro_indisponivel(ficheiro);
	string ids {}, lvids {}, fcids {}, ltids {}, ymds {}, years {}, months {}, days {};
	string ymdse {}, yearse {}, monthse {}, dayse {};
	long id {}, lvid {}, fcid {}, ltid {};
	time_t dt {}, dte{};
	struct tm* dtinfo {};
	struct tm* dteinfo {};
	int year {}, month {}, day {}, yeare {}, monthe {}, daye {};
	Livro* lv {};
	Funcionario* fc {};
	Leitor* lt {};
	bool encontrado {false};
	while (!isep.eof()) {
		getline(isep, ids);
		getline(isep, lvids);
		getline(isep, fcids);
		getline(isep, ltids);
		getline(isep, ymds);
		getline(isep, ymdse);
		id = atol(ids.c_str());
		lvid = atol(lvids.c_str());
		fcid = atol(fcids.c_str());
		ltid = atol(ltids.c_str());
		if (ymds == "0") dt=0;
		else {
			stringstream ymdss(ymds);
			getline(ymdss, years, '/');
			getline(ymdss, months, '/');
			getline(ymdss, days);
			year = atoi(years.c_str());
			month = atoi(months.c_str());
			day = atoi(days.c_str());
			time (&dt);
			dtinfo = localtime ( &dt );
			dtinfo->tm_year = year - 1900;
			dtinfo->tm_mon = month - 1;
			dtinfo->tm_mday = day;
			dt = mktime (dtinfo);
		}
		if (ymdse == "0") dte=0;
		else {
			stringstream ymdsse(ymdse);
			getline(ymdsse, yearse, '/');
			getline(ymdsse, monthse, '/');
			getline(ymdsse, dayse);
			yeare = atoi(yearse.c_str());
			monthe = atoi(monthse.c_str());
			daye = atoi(dayse.c_str());
			time (&dte);
			dteinfo = localtime ( &dte );
			dteinfo->tm_year = yeare - 1900;
			dteinfo->tm_mon = monthe - 1;
			dteinfo->tm_mday = daye;
			dte = mktime (dteinfo);
		}
		if (ids != "") {
			encontrado=false;
			for (vector<Livro*>::const_iterator it = livros.begin(); it != livros.end(); it++) {
				if ((*it)->get_ID() == lvid) {
					lv = (*it);
					encontrado = true;
				}
			}
			if (!encontrado) throw Object_nao_existe(lvid);
			encontrado = false;
			for (vector<Funcionario*>::const_iterator it = funcionarios.begin(); it != funcionarios.end(); it++) {
				if ((*it)->get_ID() == fcid) {
					fc = (*it);
					encontrado = true;
				}
			}
			if (!encontrado) throw Object_nao_existe(fcid);
			encontrado=false;
			for (vector<Leitor*>::const_iterator it = leitores.begin(); it != leitores.end(); it++) {
				if ((*it)->get_ID() == ltid) {
					lt = (*it);
					encontrado = true;
				}
			}
			if (!encontrado) throw Object_nao_existe(ltid);
			Emprestimo_old* ep = new Emprestimo_old {id,lv,fc,lt,dt,dte,true};
			adiciona_emprestimo_old(ep);
		}
	}
	isep.close();
}

void Biblioteca::le_emprestimos(string ficheiro) {
	ifstream isep(ficheiro);
	if (!isep) throw Ficheiro_indisponivel(ficheiro);
	string ids {}, lvids {}, fcids {}, ltids {}, ymds {}, years {}, months {}, days {};
	long id {}, lvid {}, fcid {}, ltid {};
	time_t dt {};
	struct tm* dtinfo {};
	int year {}, month {}, day {};
	Livro* lv {};
	Funcionario* fc {};
	Leitor* lt {};
	bool encontrado {false};
	while (!isep.eof()) {
		getline(isep, ids);
		getline(isep, lvids);
		getline(isep, fcids);
		getline(isep, ltids);
		getline(isep, ymds);
		id = atol(ids.c_str());
		lvid = atol(lvids.c_str());
		fcid = atol(fcids.c_str());
		ltid = atol(ltids.c_str());
		if (ymds == "0") dt=0;
		else {
			stringstream ymdss(ymds);
			getline(ymdss, years, '/');
			getline(ymdss, months, '/');
			getline(ymdss, days);
			year = atoi(years.c_str());
			month = atoi(months.c_str());
			day = atoi(days.c_str());
			time (&dt);
			dtinfo = localtime ( &dt );
			dtinfo->tm_year = year - 1900;
			dtinfo->tm_mon = month - 1;
			dtinfo->tm_mday = day;
			dt = mktime (dtinfo);
		}
		if (ids != "") {
			encontrado=false;
			for (vector<Livro*>::const_iterator it = livros.begin(); it != livros.end(); it++) {
				if ((*it)->get_ID() == lvid) {
					lv = (*it);
					encontrado = true;
				}
			}
			if (!encontrado) throw Object_nao_existe(lvid);
			encontrado = false;
			for (vector<Funcionario*>::const_iterator it = funcionarios.begin(); it != funcionarios.end(); it++) {
				if ((*it)->get_ID() == fcid) {
					fc = (*it);
					encontrado = true;
				}
			}
			if (!encontrado) throw Object_nao_existe(fcid);
			encontrado=false;
			for (vector<Leitor*>::const_iterator it = leitores.begin(); it != leitores.end(); it++) {
				if ((*it)->get_ID() == ltid) {
					lt = (*it);
					encontrado = true;
				}
			}
			if (!encontrado) throw Object_nao_existe(ltid);
			Emprestimo* ep = new Emprestimo {id,lv,fc,lt,dt,true};
			try {
				adiciona_emprestimo(ep);
			}
			catch (Livro_indisponivel &liv) {
				ostringstream ostr{};
				ostr << liv;
				cout << ostr.str();
			}
			catch(Maximo_emprestimos &lei ) {
				ostringstream ostr{};
				ostr << lei;
				cout << ostr.str();
			}
		}
	}
	isep.close();
}

void Biblioteca::le_utilizadores(string ficheiro) {
	ifstream isut(ficheiro);
	if (!isut) throw Ficheiro_indisponivel(ficheiro);
	string ids {}, pass {}, aces {};
	long id {};
	int ace {};
	while (!isut.eof()) {
		getline(isut, ids);
		getline(isut, pass);
		getline(isut, aces);
		id = atol(ids.c_str());
		ace = atoi(aces.c_str());
		if (ids != "") {
			Utilizador* ut = new Utilizador {id, pass, ace};
			adiciona_utilizador(ut);
		}
	}
	isut.close();
}

/* e necessario apanhar as possiveis excecoes de indisponibilidade de algum ficheiro
 * ou de inexistencia de um livro, leitor ou funcionario a que a criacao de um emprestimo
 * (atual ou antigo) tenta aceder */
void Biblioteca::le(string ficheiro_lvo, string ficheiro_lv, string ficheiro_fco,
		string ficheiro_fc, string ficheiro_sp, string ficheiro_lto, string ficheiro_lt,
		string ficheiro_epo, string ficheiro_ep, string ficheiro_ut) {
	try {
		le_livros_old(ficheiro_lvo);
	}
	catch (Ficheiro_indisponivel &fic) {
		ostringstream ostr{};
		ostr << fic;
		cout << ostr.str();
	}
	try {
		le_livros(ficheiro_lv);
	}
	catch (Ficheiro_indisponivel &fic) {
		ostringstream ostr{};
		ostr << fic;
		cout << ostr.str();
	}
	try {
		le_funcionarios_old(ficheiro_fco);
	}
	catch (Ficheiro_indisponivel &fic) {
		ostringstream ostr{};
		ostr << fic;
		cout << ostr.str();
	}
	try {
		le_funcionarios(ficheiro_fc);
	}
	catch (Ficheiro_indisponivel &fic) {
		ostringstream ostr{};
		ostr << fic;
		cout << ostr.str();
	}
	try {
		le_supervisores(ficheiro_sp);
	}
	catch (Ficheiro_indisponivel &fic) {
		ostringstream ostr{};
		ostr << fic;
		cout << ostr.str();
	}
	try {
		le_leitores_old(ficheiro_lto);
	}
	catch (Ficheiro_indisponivel &fic) {
		ostringstream ostr{};
		ostr << fic;
		cout << ostr.str();
	}
	try {
		le_leitores(ficheiro_lt);
	}
	catch (Ficheiro_indisponivel &fic) {
		ostringstream ostr{};
		ostr << fic;
		cout << ostr.str();
	}
	try {
		le_emprestimos_old(ficheiro_epo);
	}
	catch (Ficheiro_indisponivel &fic) {
		ostringstream ostr{};
		ostr << fic;
		cout << ostr.str();
	}
	catch (Object_nao_existe &obj) {
		ostringstream ostr{};
		ostr << obj;
		cout << ostr.str();
	}
	try {
		le_emprestimos(ficheiro_ep);
	}
	catch (Ficheiro_indisponivel &fic) {
		ostringstream ostr{};
		ostr << fic;
		cout << ostr.str();
	}
	catch (Object_nao_existe &obj) {
		ostringstream ostr{};
		ostr << obj;
		cout << ostr.str();
	}
	try {
		le_utilizadores(ficheiro_ut);
	}
	catch (Ficheiro_indisponivel &fic) {
		ostringstream ostr{};
		ostr << fic;
		cout << ostr.str();
	}
}

