
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cmath>
#include <fstream>

#include "Biblio.h"
#include "Excecao.h"

using namespace std;

unsigned int Biblioteca::ordem {0};

/** @file
 *
 * @brief Source das funcoes da Biblioteca.
 *
 * Apos os menus, estas sao as funcoes chamadas pelas varias opcoes da aplicacao.
 **/

Biblioteca::Biblioteca(): disponiveis {Livro(0, "", {}, "", 0, "", 0, 0, false)} {}

void Biblioteca::set_ordem(const unsigned int ord) {
    if (ord == 0 or ord == 1 or ord == 2) ordem = ord;
}

unsigned int Biblioteca::get_ordem() {
    return ordem;
}

/* com dynamic_cast o apontador lo so nao e nulo se (*it) for do tipo Livro_old */
vector<Livro_old*> Biblioteca::get_livros_old() const{
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
vector<Livro*> Biblioteca::get_livros() const {
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
vector<Emprestimo_old*> Biblioteca::get_emprestimos_old() const {
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
vector<Emprestimo*> Biblioteca::get_emprestimos() const{
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
vector<Funcionario_old*> Biblioteca::get_funcionarios_old() const {
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
vector<Funcionario*>Biblioteca::get_funcionarios_todos() const {
	return funcionarios;
}

/* com dynamic_cast o apontador sp so nao e nulo se (*it) for do tipo Supervisor */
vector<Funcionario*>Biblioteca::get_supervisores() const {
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
vector<Funcionario*>Biblioteca::get_funcionarios() const {
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
vector<Leitor_old*> Biblioteca::get_leitores_old() const {
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
vector<Leitor*> Biblioteca::get_leitores() const {
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

vector<Utilizador*>Biblioteca::get_utilizadores() const {
	return utilizadores;
}

/* com dynamic_cast o apontador po so nao e nulo se (*it) for do tipo Pedido_old */
vector<Pedido_old*> Biblioteca::get_pedidos_old() const {
    vector<Pedido_old*> ped_old {};
    Pedido_old* po{};
    for (vector<Pedido*>::const_iterator it = pedidos.begin(); it != pedidos.end(); it++){
        po = dynamic_cast<Pedido_old*>(*it);
        if (po != 0){
            ped_old.push_back(po);
        }
    }
    return ped_old;
}

/* com dynamic_cast o apontador po so nao e nulo se (*it) for do tipo Pedido_old */
vector<Pedido*> Biblioteca::get_pedidos() const {
    vector<Pedido*> ped {};
    Pedido_old* po{};
    for (vector<Pedido*>::const_iterator it = pedidos.begin(); it != pedidos.end(); it++){
        po = dynamic_cast<Pedido_old*>(*it);
        if (po == 0){
            ped.push_back(*it);
        }
    }
    return ped;
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
    adiciona_disponivel(*lv);
	cout << "Livro adicionado." << endl;
}

void Biblioteca::adiciona_livro_old(Livro_old* lv) {
	livros.push_back(lv);
}

Livro* Biblioteca::adiciona_exemplar(const unsigned long id) {
    Livro_old* lvo {};
    bool encontrado {false};
    Livro* lv {};
    for (vector<Livro*>::iterator it = livros.begin(); it != livros.end(); it++) {
        lvo = dynamic_cast<Livro_old*>(*it);
        if ((*it)->get_ID() == id) {
            encontrado = true;
            if (lvo == 0) {
                remove_disponivel(**it);
                (*it)->inc_exemplares();
                (*it)->inc_ex_disponiveis();
                (*it)->inc_emp_livro();
                if ((*it)->get_ex_disponiveis() > 0 ) adiciona_disponivel(**it);
                cout << "Exemplar adicionado." << endl;
                return (*it);
            }
            else lv = new Livro{(*it)->get_ano_edicao(), (*it)->get_titulo(),
                (*it)->get_autores(), (*it)->get_tema(), (*it)->get_ISBN(), (*it)->get_cota(),
                (*it)->get_num_paginas(), (*it)->get_edicao(), false, id};
        }
    }
    if (encontrado) {
        livros.push_back(lv);
        cout << "Exemplar adicionado." << endl;
        return lv;
    }
    throw Object_nao_existe(id, "livro");
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

vector<string> Biblioteca::get_temas() const {
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

vector<Livro*> Biblioteca::get_livros_tema(const string tem) const {
	vector<Livro*> lv {};
	vector<Livro*> livrs {get_livros()};
	for (vector<Livro*>::const_iterator it = livrs.begin(); it !=  livrs.end(); it++) {
		if ((*it)->get_tema() == tem) {
			lv.push_back(*it);
		}
	}
	return lv;
}

vector<Livro*> Biblioteca::get_livros_disponiveis() const {
	vector<Livro*> lv {};
	vector<Livro*> livrs {get_livros()};
	for (vector<Livro*>::const_iterator it = livrs.begin(); it !=  livrs.end(); it++) {
		if ((*it)->get_ex_disponiveis()) { /* se ha exemplares do livro disponiveis */
			lv.push_back(*it);
		}
	}
	return lv;
}

vector<Livro*> Biblioteca::get_livros_emprestados() const {
	vector<Livro*> lv {};
	vector<Livro*> livrs {get_livros()};
	for (vector<Livro*>::const_iterator it = livrs.begin(); it !=  livrs.end(); it++) {
        if ((*it)->get_exemplares() > (*it)->get_ex_disponiveis()) {
            /* se ha algum exemplar emprestado, exemplares > ex_disponiveis */
			lv.push_back(*it);
		}
	}
	return lv;
}

/* apagar um elemento de um vetor com erase(it) pode dar problemas com o iterador,
 * porque se apagarmos o ultimo elemento, o iterador nunca chega ao fim.
 * mas como estamos a fazer return logo depois, nao deve haver problema. */
bool Biblioteca::remove_livro(const unsigned long id, const unsigned long ind) {
	Livro_old* lvo {};
	for (vector<Livro*>::iterator it = livros.begin(); it != livros.end(); it++) {
		lvo = dynamic_cast<Livro_old*>(*it);
		if ((*it)->get_ID() == id and lvo == 0) {
            remove_disponivel(**it);
            if ((*it)->get_exemplares() > ind) { /* se existir exemplar com o indice escolhido */
                if ((*it)->get_emp_livro()[ind] == NULL) { /* se o exemplar do livro nao esta emprestado*/
                    bool existe_old {false};
                    Livro_old* lvoo {};
                    for (vector<Livro*>::iterator itt = livros.begin(); itt != livros.end(); itt++) {
                        lvoo = dynamic_cast<Livro_old*>(*itt);
                        if ((*itt)->get_ID() == id and lvoo != 0) {
                            /* se ja existe outro exemplar do livro removido */
                            existe_old = true;
                            (*itt)->inc_exemplares();
                            /* aumentamos o numero de exemplares removidos */
                            lvoo->adiciona_dtf(time(0));
                            /* acrescentamos data ao vetor data_fim*/
                        }
                    }
                    if (!existe_old) {
                        Livro_old* lo = new Livro_old{(*it)->get_ano_edicao(), (*it)->get_titulo(),
                            (*it)->get_autores(), (*it)->get_tema(), (*it)->get_ISBN(),
                            (*it)->get_cota(), (*it)->get_num_paginas(), (*it)->get_edicao(), false, id};
                        adiciona_livro_old(lo); /* ao remover um livro adicionamo-lo como Livro_old */
                    }
                    if ((*it)->get_exemplares() > 1) {
                        /* se nao estamos a remover o ultimo exemplar do livro */
                        (*it)->dec_exemplares(); /* diminuimos o numero de exemplares */
                        (*it)->dec_ex_disponiveis(); /* e o numero de exemplares disponiveis */
                        (*it)->del_emp_livro(ind); /* removemos o indice do exemplar do vetor ID_ep */
                        if ((*it)->get_ex_disponiveis() > 0 ) adiciona_disponivel(**it);
                    }
                    else {
                        priority_queue<Pedido> pds {(*it)->get_pedidos()};
                        while (!pds.empty()) {
                            try {
                                remove_pedido(pds.top().get_ID());
                            }
                            catch (Object_nao_existe &ob) {
                                ostringstream ostr {};
                                ostr << ob;
                                cout << ostr.str();
                            }
                            catch (Pedido_nao_prioritario &pd) {
                                ostringstream ostr {};
                                ostr << pd;
                                cout << ostr.str();
                            }
                        }
                        livros.erase(it);
                        /* se estamos a remover o ultimo exemplar do livro */
                        /* removemos o registo do livro dos livros atuais */
                    }
                    cout << endl << "Livro removido." << endl;
                    return true;
                }
                else throw Livro_emprestado{ind, (*it)->get_ano_edicao(), (*it)->get_titulo(),
                    (*it)->get_autores(), (*it)->get_tema(), (*it)->get_ISBN(), (*it)->get_cota(),
                    (*it)->get_num_paginas(), (*it)->get_edicao(), id, (*it)->get_exemplares(),
                (*it)->get_ex_disponiveis(), (*it)->get_emp_livro(), (*it)->get_pedidos()};
            }
            else throw Exemplar_inexistente{ind, (*it)->get_ano_edicao(), (*it)->get_titulo(),
                (*it)->get_autores(), (*it)->get_tema(), (*it)->get_ISBN(), (*it)->get_cota(),
                (*it)->get_num_paginas(), (*it)->get_edicao(), id, (*it)->get_exemplares(),
                (*it)->get_ex_disponiveis(), (*it)->get_emp_livro(), (*it)->get_pedidos()};
		}
	}
	throw Object_nao_existe(id, "livro");
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
bool Biblioteca::remove_funcionario(const unsigned long id) {
	for (vector<Funcionario*>::const_iterator it = funcionarios.begin(); it != funcionarios.end(); it++) {
		if ((*it)->get_ID() == id) {
			Funcionario_old* fo = new Funcionario_old{(*it)->get_ID(), (*it)->get_nome(), false};
			adiciona_funcionario_old(fo); /* ao remover um funcionario adicionamo-lo como Funcionario_old */
			funcionarios.erase(it);
			distribui_funcionarios();
			cout << endl << "Funcionario removido." << endl;
			return true;
		}
	}
	throw Object_nao_existe(id, "funcionario");
}

/* apagar um elemento de um vetor com erase(it) pode dar problemas com o iterador,
 * porque se apagarmos o ultimo elemento, o iterador nunca chega ao fim.
 * mas como estamos a fazer return logo depois, nao deve haver problema. */
bool Biblioteca::remove_leitor(const unsigned long id) {
	Leitor_old* lto {};
	for (vector<Leitor*>::const_iterator it = leitores.begin(); it != leitores.end(); it++) {
		lto = dynamic_cast<Leitor_old*>(*it);
		if ((*it)->get_ID() == id and lto == 0) {
			if ((*it)->get_emp_leit().size() == 0) {
				Leitor_old* lo = new Leitor_old{(*it)->get_ID(), (*it)->get_nome(),
                    (*it)->get_tipo(), (*it)->get_telefone(), (*it)->get_email(),
                    (*it)->get_morada(), (*it)->get_data_ult_emp(), false};
				adiciona_leitor_old(lo); /* ao remover um leitor adicionamo-lo como Leitor_old */
                remove_inativo(**it);
				leitores.erase(it);
				cout << endl << "Leitor removido." << endl;
				return true;
			}
			else { /* nao podemos remover um leitor com emprestimos por devolver */
				throw Emprestimos_por_devolver(id, (*it)->get_nome(), (*it)->get_tipo(),
                                               (*it)->get_telefone(), (*it)->get_email(),
                                               (*it)->get_morada(), (*it)->get_data_ult_emp(),
                                               (*it)->get_emp_leit());
			}
		}
	}
	throw Object_nao_existe(id, "leitor");
}

void Biblioteca::adiciona_emprestimo_old(Emprestimo_old* ep) {
	emprestimos.push_back(ep);
}

void Biblioteca::adiciona_emprestimo(Emprestimo* ep) {
	Livro* lv = ep->get_livro();
    unsigned long ind = ep->get_indice();
	Leitor* lt = ep->get_leitor();
	vector<Emprestimo*> ep_lt = lt->get_emp_leit();
    vector<Emprestimo*> ep_lv = lv->get_emp_livro();
    if (lv->get_exemplares() > ind) {
        if (ep_lv[ind] == NULL) {
            if (ep_lt.size() < 3) {
                remove_disponivel(*lv);
                lv->set_emp_livro(ind, ep);
                lv->dec_ex_disponiveis();
                lt->adiciona_emp_leit(ep);
                lt->set_data_ult_emp(ep->get_data());
                emprestimos.push_back(ep);
                remove_inativo(*lt);
                if (lv->get_ex_disponiveis() > 0 ) adiciona_disponivel(*lv);
                cout << "Emprestimo adicionado." << endl;
            }
            else throw Maximo_emprestimos(lt->get_ID(), lt->get_nome(), lt->get_tipo(),
                                          lt->get_telefone(), lt->get_email(), lt->get_morada(),
                                          lt->get_data_ult_emp(), lt->get_emp_leit());
            /* nao podemos adicionar mais emprestimos a um leitor que ja tenha 3 */
        }
        else throw Exemplar_indisponivel(ind, lv->get_ano_edicao(), lv->get_titulo(),
                                         lv->get_autores(), lv->get_tema(), lv->get_ISBN(),
                                         lv->get_cota(), lv->get_num_paginas(), lv->get_edicao(),
                                         lv->get_ID(), lv->get_exemplares(),
                                         lv->get_ex_disponiveis(), lv->get_emp_livro(),
                                         lv->get_pedidos());
        /* nao podemos emprestar um livro que ja esteja emprestado */
	}
    else throw Exemplar_inexistente(ind, lv->get_ano_edicao(), lv->get_titulo(),
                                    lv->get_autores(), lv->get_tema(), lv->get_ISBN(),
                                    lv->get_cota(), lv->get_num_paginas(), lv->get_edicao(),
                                    lv->get_ID(), lv->get_exemplares(),
                                    lv->get_ex_disponiveis(), lv->get_emp_livro(),
                                    lv->get_pedidos());
}

void Biblioteca::adiciona_emprestimo_ids(const unsigned long id_lv, const unsigned long id_lt,
                                         const unsigned long id_fc) {
	Livro* lv{};
    vector<Livro*> livrs = get_livros();
    bool livro_encontrado {false};
    for (vector<Livro*>::const_iterator it = livrs.begin(); it != livrs.end(); it++){
    	if ((*it)->get_ID() == id_lv) {
    		lv = (*it);
    		livro_encontrado = true;
    	}
    }
    if (livro_encontrado) {
        if (lv->get_ex_disponiveis() > 0) {
            unsigned long ind {0};
            vector<Emprestimo*> ep_lv {lv->get_emp_livro()};
            Emprestimo* ep_ind {ep_lv[ind]};
            while (ep_ind != NULL and ind < ep_lv.size() - 1) {
                ind++;
                ep_ind = ep_lv[ind];
            }
            Leitor* lt{};
            vector<Leitor*> leitors = get_leitores();
            bool leitor_encontrado {false};
            for (vector<Leitor*>::const_iterator it = leitors.begin(); it != leitors.end(); it++){
                if ((*it)->get_ID() == id_lt) {
                    lt = (*it);
                    leitor_encontrado = true;
                }
            }
            if (leitor_encontrado) {
                Funcionario* fc{};
                bool func_encontrado {false};
                vector<Funcionario*> funcs = get_funcionarios_todos();
                for (vector<Funcionario*>::const_iterator it = funcs.begin(); it != funcs.end(); it++){
                    if ((*it)->get_ID() == id_fc) {
                        fc = (*it);
                        func_encontrado=true;
                    }
                }
                if (func_encontrado) {
                    Emprestimo* ep = new Emprestimo{lv, ind, fc, lt, true};
                    try {
                        adiciona_emprestimo(ep);
                    }
                    catch (Exemplar_inexistente &exe) {
                        ostringstream ostr{};
                        ostr << exe;
                        cout << ostr.str();
                        cout << "Por favor escolha o indice de um exemplar existente." << endl;
                    }
                    catch (Exemplar_indisponivel &liv) {
                        ostringstream ostr{};
                        ostr << liv;
                        cout << ostr.str();
                        cout << "Por favor escolha um exemplar disponivel." << endl;
                    }
                    catch(Maximo_emprestimos &lei ) {
                        ostringstream ostr{};
                        ostr << lei;
                        cout << ostr.str();
                        cout << "Por favor escolha um leitor com menos de 3 emprestimos." << endl;
                    }
                }
                else throw Object_nao_existe(id_fc, "funcionario");
            }
            else throw Object_nao_existe(id_lt, "leitor");
        }
        else throw Livro_indisponivel(lv->get_ano_edicao(), lv->get_titulo(),
                                      lv->get_autores(), lv->get_tema(), lv->get_ISBN(),
                                      lv->get_cota(), lv->get_num_paginas(), lv->get_edicao(),
                                      lv->get_ID(), lv->get_exemplares(),
                                      lv->get_ex_disponiveis(), lv->get_emp_livro(),
                                      lv->get_pedidos());
   	}
    else throw Object_nao_existe(id_lv, "livro");
}

void Biblioteca::adiciona_pedido_old(Pedido_old* pd) {
    pedidos.push_back(pd);
}

void Biblioteca::adiciona_pedido(Pedido* pd) {
    Livro* lv = pd->get_livro();
    Leitor* lt = pd->get_leitor();
    vector<Emprestimo*> ep_lt = lt->get_emp_leit();
    vector<Emprestimo*> ep_lv = lv->get_emp_livro();
    if (lv->get_ex_disponiveis() > 0)
        throw Livro_disponivel(lv->get_ano_edicao(), lv->get_titulo(), lv->get_autores(),
                               lv->get_tema(), lv->get_ISBN(), lv->get_cota(),
                               lv->get_num_paginas(), lv->get_edicao(), lv->get_ID(),
                               lv->get_exemplares(), lv->get_ex_disponiveis(),
                               lv->get_emp_livro(), lv->get_pedidos());
    else {
        lv->adiciona_ped_livro(*pd);
        pedidos.push_back(pd);
        cout << "Pedido adicionado." << endl;
    }
}

void Biblioteca::adiciona_pedido_ids(const unsigned long id_lv, const unsigned long id_lt,
                                     const unsigned long id_fc) {
    Livro* lv{};
    vector<Livro*> livrs = get_livros();
    bool livro_encontrado {false};
    for (vector<Livro*>::const_iterator it = livrs.begin(); it != livrs.end(); it++) {
        if ((*it)->get_ID() == id_lv) {
            lv = (*it);
            livro_encontrado = true;
        }
    }
    if (livro_encontrado) {
        Leitor* lt{};
        vector<Leitor*> leitors = get_leitores();
        bool leitor_encontrado {false};
        for (vector<Leitor*>::const_iterator it = leitors.begin(); it != leitors.end(); it++) {
            if ((*it)->get_ID() == id_lt) {
                lt = (*it);
                leitor_encontrado = true;
            }
        }
        if (leitor_encontrado) {
            Funcionario* fc{};
            bool func_encontrado {false};
            vector<Funcionario*> funcs = get_funcionarios_todos();
            for (vector<Funcionario*>::const_iterator it = funcs.begin(); it != funcs.end(); it++) {
                if ((*it)->get_ID() == id_fc) {
                    fc = (*it);
                    func_encontrado=true;
                }
            }
            if (func_encontrado) {
                Pedido* pd = new Pedido{lv, fc, lt, true};
                try {
                    adiciona_pedido(pd);
                }
                catch (Livro_disponivel &lv) {
                    throw Livro_disponivel(lv.get_ano_edicao(), lv.get_titulo(), lv.get_autores(),
                                           lv.get_tema(), lv.get_ISBN(), lv.get_cota(),
                                           lv.get_num_paginas(), lv.get_edicao(), lv.get_ID(),
                                           lv.get_exemplares(), lv.get_ex_disponiveis(),
                                           lv.get_emp_livro(), lv.get_pedidos());
                }
            }
            else throw Object_nao_existe(id_fc, "funcionario");
        }
        else throw Object_nao_existe(id_lt, "leitor");
    }
    else throw Object_nao_existe(id_lv, "livro");
}

/* apagar um elemento de um vetor com erase(it) pode dar problemas com os iteradores,
 * porque se apagarmos o ultimo elemento, nunca chegam ao fim.
 * mas como estamos a adicionar um elemento antes de apagar, nao deve haver problema */
Emprestimo* Biblioteca::remove_emprestimo(const unsigned long id) {
	Emprestimo_old* epo {};
	for (vector<Emprestimo*>::iterator it = emprestimos.begin(); it != emprestimos.end(); it++) {
		epo = dynamic_cast<Emprestimo_old*>(*it);
		if ((*it)->get_ID() == id and epo == 0) {
            remove_disponivel(*((*it)->get_livro()));
            remove_inativo(*((*it)->get_leitor()));
			int dias {(*it)->get_atraso()};
			if (dias > 0) { /* se a devolucao estiver atrasada, temos que cobrar multa */
				cout << endl << "Devolucao de livro " << dias << " dia(s) em atraso. Deve efetuar o pagamento de "
						<< (*it)->get_multa() << " euros." << endl;
			}
            ((*it)->get_livro())->set_emp_livro((*it)->get_indice(), NULL);
            ((*it)->get_livro())->inc_ex_disponiveis();
			((*it)->get_leitor())->remove_emp_leit(id);
            if (((*it)->get_livro())->get_ex_disponiveis() > 0)
                disponiveis.insert(*((*it)->get_livro()));
			Emprestimo_old* eo = new Emprestimo_old{(*it)->get_livro(),
                (*it)->get_funcionario(), (*it)->get_leitor(), false,
                (*it)->get_data(), (*it)->get_ID()};
			adiciona_emprestimo_old(eo); /* ao remover um emprestimo adicionamo-lo como Emprestimo_old */
            Emprestimo* ep = *it;
			emprestimos.erase(it);
            double tempo_dias
                {trunc(difftime(time(0), (*it)->get_leitor()->get_data_ult_emp())/86400)};
            if (tempo_dias > 365) adiciona_inativo(*((*it)->get_leitor()));
			cout << endl << "Emprestimo removido." << endl;
			return ep;
		}
	}
	throw Object_nao_existe(id, "emprestimo");
}

/* apagar um elemento de um vetor com erase(it) pode dar problemas com os iteradores,
 * porque se apagarmos o ultimo elemento, nunca chegam ao fim.
 * mas como estamos a adicionar um elemento antes de apagar, nao deve haver problema */
bool Biblioteca::remove_pedido(const unsigned long id) {
    Pedido_old* pdo {};
    for (vector<Pedido*>::iterator it = pedidos.begin(); it != pedidos.end(); it++) {
        pdo = dynamic_cast<Pedido_old*>(*it);
        if ((*it)->get_ID() == id and pdo == 0) {
            Pedido pdp {((*it)->get_livro())->get_pedidos().top()};
            if (pdp.get_ID() == id) {
                ((*it)->get_livro())->remove_ped_livro();
                Pedido_old* po = new Pedido_old{(*it)->get_livro(),
                (*it)->get_funcionario(), (*it)->get_leitor(), false,
                (*it)->get_data(), (*it)->get_ID()};
                adiciona_pedido_old(po); /* ao remover um pedido adicionamo-lo como Pedido_old */
                pedidos.erase(it);
                cout << endl << "Pedido removido." << endl;
                return true;
            }
            else throw Pedido_nao_prioritario((*it)->get_livro(), (*it)->get_funcionario(),
                                              (*it)->get_leitor(), false, (*it)->get_data(),
                                              (*it)->get_ID());
        }
    }
    throw Object_nao_existe(id, "pedido");
}

/* apagar um elemento de um vetor com erase(it) pode dar problemas com os iteradores,
 * porque se apagarmos o ultimo elemento, nunca chegam ao fim.
 * mas como estamos a adicionar um elemento antes de apagar, nao deve haver problema */
bool Biblioteca::desiste_pedido(const unsigned long id) {
    Pedido_old* pdo {};
    for (vector<Pedido*>::iterator it = pedidos.begin(); it != pedidos.end(); it++) {
        pdo = dynamic_cast<Pedido_old*>(*it);
        if ((*it)->get_ID() == id and pdo == 0) {
            priority_queue<Pedido> pdl {((*it)->get_livro())->get_pedidos()};
            priority_queue<Pedido> pds {};
            while (!pdl.empty()) {
                if (pdl.top().get_ID() != id) pds.push(pdl.top());
                pdl.pop();
            }
            ((*it)->get_livro())->set_pedidos(pds);
            Pedido_old* po = new Pedido_old{(*it)->get_livro(), (*it)->get_funcionario(),
                (*it)->get_leitor(), false, (*it)->get_data(), (*it)->get_ID()};
            adiciona_pedido_old(po); /* ao remover um pedido adicionamo-lo como Pedido_old */
            pedidos.erase(it);
            cout << endl << "Pedido removido." << endl;
            return true;
        }
    }
    throw Object_nao_existe(id, "emprestimo");
}

/* apagar um elemento de um vetor com erase(it) pode dar problemas com o iterador,
 * porque se apagarmos o ultimo elemento, o iterador nunca chega ao fim.
 * mas como estamos a fazer return logo depois, nao deve haver problema. */
bool Biblioteca::remove_utilizador(const unsigned long id) {
	for (vector<Utilizador*>::const_iterator it = utilizadores.begin(); it != utilizadores.end(); it++) {
		if ((*it)->get_ID() == id) {
			utilizadores.erase(it);
			cout << endl << "Utilizador removido." << endl;
			return true;
		}
	}
	throw Object_nao_existe(id, "utilizador");
}

vector<Emprestimo*> Biblioteca::get_emprestimos_atrasados() const {
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
string Biblioteca::imprime_emprestimos_atrasados() const {
	stringstream out {};
	vector<Emprestimo*> atrasados {get_emprestimos_atrasados()};
	vector<Leitor*> lt_atrasados {};
	vector<long> id_lt {};
	unsigned long id {};
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

bool Biblioteca::promove_funcionario_supervisor(const unsigned long id) {
	vector<Funcionario*> func_sup {};
	Supervisor* spd {};
	Funcionario_old* fco {};
	for (vector<Funcionario*>::const_iterator it = funcionarios.begin(); it != funcionarios.end(); it++) {
		if ((*it)->get_ID() == id) {
			spd = dynamic_cast<Supervisor*>(*it);
			fco = dynamic_cast<Funcionario_old*>(*it);
			if (spd==0 and fco==0) {
				Supervisor* sp = new Supervisor {id, (*it)->get_nome(), func_sup, false};
				funcionarios.erase(it);
				funcionarios.push_back(sp);
				/* sempre que ha alteracoes nos funcionarios e necessario distribui-los para garantir o equilibrio */
				distribui_funcionarios();
				for (vector<Utilizador*>::const_iterator it = utilizadores.begin(); it != utilizadores.end(); it++) {
					if ((*it)->get_ID() == id) {
						(*it)->set_acesso(1);
					}
				}
				cout << endl << "Funcionario promovido." << endl;
				return true;
			}
			else throw Object_nao_existe(id, "funcionario");
		}
	}
	throw Object_nao_existe(id, "funcionario");
}

bool Biblioteca::despromove_supervisor_funcionorario(const unsigned long id) {
	Supervisor* sp {};
	for (vector<Funcionario*>::const_iterator it = funcionarios.begin(); it != funcionarios.end(); it++) {
		if ((*it)->get_ID() == id) {
			sp = dynamic_cast<Supervisor*>(*it);
			if (sp != 0) {
				Funcionario* fc=new Funcionario {(*it)->get_nome(), false, id};
				funcionarios.erase(it);
				funcionarios.push_back(fc);
				/* sempre que ha alteracoes nos funcionarios e necessario distribui-los para garantir o equilibrio */
				distribui_funcionarios();
				for (vector<Utilizador*>::const_iterator it = utilizadores.begin(); it != utilizadores.end(); it++) {
					if ((*it)->get_ID() == id) {
						(*it)->set_acesso(2);
					}
				}
				cout << endl << "Supervisor despromovido." << endl;
				return true;
			}
			else throw Object_nao_existe(id, "supervisor");
		}
	}
	throw Object_nao_existe(id, "supervisor");
}

string Biblioteca::imprime_livros_old() const {
	stringstream out {};
	vector<Livro_old*> livrs {get_livros_old()};
	out << "LIVROS ANTIGOS" << endl << endl;
	for (vector<Livro_old*>::const_iterator it = livrs.begin(); it != livrs.end(); it++) {
		out << (*it)->imprime() << endl;
	}
	return out.str();
}

string Biblioteca::imprime_livros() const {
	stringstream out {};
	vector<Livro*> livrs {get_livros()};
	out << "LIVROS" << endl << endl;
	for (vector<Livro*>::const_iterator it = livrs.begin(); it != livrs.end(); it++) {
		out << (*it)->imprime() << endl;
	}
	return out.str();
}

string Biblioteca::imprime_livros_tema(const string tem) const {
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

string Biblioteca::imprime_livros_disponiveis() const {
	stringstream out {};
    /*
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
    */
    if (disponiveis.isEmpty()) {
        out << "Nao existem livros disponiveis." << endl << endl;
    }
    else {
        out << "LIVROS DISPONIVEIS" << endl << endl;
        for (BSTItrIn<Livro> it = disponiveis; !it.isAtEnd(); it.advance()) {
            out << it.retrieve().imprime() << endl;
        }
    }
	return out.str();
}

string Biblioteca::imprime_livros_emprestados() const {
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

string Biblioteca::imprime_funcionarios_old() const {
	stringstream out {};
	out << "FUNCIONARIOS ANTIGOS" << endl << endl;
	vector<Funcionario_old*> funcios {get_funcionarios_old()};
	for (vector<Funcionario_old*>::const_iterator it = funcios.begin(); it != funcios.end(); it++) {
		out << (*it)->imprime() << endl;
	}
	return out.str();
}

string Biblioteca::imprime_funcionarios() const {
	stringstream out {};
	out << "FUNCIONARIOS" << endl << endl;
	vector<Funcionario*> funcios {get_funcionarios()};
	for (vector<Funcionario*>::const_iterator it = funcios.begin(); it != funcios.end(); it++) {
		out << (*it)->imprime() << endl;
	}
	return out.str();
}

string Biblioteca::imprime_supervisores() const {
	stringstream out {};
	out << "SUPERVISORES" << endl << endl;
	vector<Funcionario*> supers {get_supervisores()};
	for (vector<Funcionario*>::const_iterator it = supers.begin(); it != supers.end(); it++) {
		out << (*it)->imprime() << endl;
	}
	return out.str();
}

string Biblioteca::imprime_leitores_inativos() const {
    stringstream out {};
    out << "LEITORES INATIVOS" << endl << endl;
    for (Hash_Leitores::const_iterator it = inativos.begin(); it != inativos.end(); it++) {
        out << it->imprime() << endl;
    }
    return out.str();
}

string Biblioteca::imprime_leitores_old() const {
	stringstream out {};
	out << "LEITORES ANTIGOS" << endl << endl;
	vector<Leitor_old*> lei_old {get_leitores_old()};
	for (vector<Leitor_old*>::const_iterator it = lei_old.begin(); it != lei_old.end(); it++) {
		out << (*it)->imprime() << endl;
	}
	return out.str();
}

string Biblioteca::imprime_leitores() const {
	stringstream out {};
	out << "LEITORES" << endl << endl;
	vector<Leitor*> lei {get_leitores()};
	for (vector<Leitor*>::const_iterator it = lei.begin(); it != lei.end(); it++) {
		out << (*it)->imprime() << endl;
	}
	return out.str();
}

string Biblioteca::imprime_emprestimos_old() const {
	stringstream out {};
	out << "EMPRESTIMOS ANTIGOS" << endl << endl;
	vector<Emprestimo_old*> emp_old {get_emprestimos_old()};
	for (vector<Emprestimo_old*>::const_iterator it = emp_old.begin(); it != emp_old.end(); it++) {
		out << (*it)->imprime() << endl;
	}
	return out.str();
}

string Biblioteca::imprime_emprestimos() const {
	stringstream out {};
	vector<Emprestimo*> emp {get_emprestimos()};
	out << "EMPRESTIMOS" << endl << endl;
	for (vector<Emprestimo*>::const_iterator it = emp.begin(); it != emp.end(); it++) {
		out << (*it)->imprime() << endl;
	}
	return out.str();
}

string Biblioteca::imprime_utilizadores() const {
	stringstream out {};
	out << "UTILIZADORES" << endl << endl;
	for (vector<Utilizador*>::const_iterator it = utilizadores.begin(); it != utilizadores.end(); it++) {
		out << (*it)->imprime() << endl;
	}
	return out.str();
}

string Biblioteca::imprime_pedidos_old() const {
    stringstream out {};
    out << "PEDIDOS ANTIGOS" << endl << endl;
    vector<Pedido_old*> ped_old {get_pedidos_old()};
    for (vector<Pedido_old*>::const_iterator it = ped_old.begin(); it != ped_old.end(); it++) {
        out << (*it)->imprime() << endl;
    }
    return out.str();
}

string Biblioteca::imprime_pedidos() const {
    stringstream out {};
    vector<Pedido*> ped {get_pedidos()};
    out << "PEDIDOS" << endl << endl;
    for (vector<Pedido*>::const_iterator it = ped.begin(); it != ped.end(); it++) {
        out << (*it)->imprime() << endl;
    }
    return out.str();
}

string Biblioteca::imprime() const {
	stringstream out {};
	out << imprime_livros() << endl
		<< imprime_funcionarios() << endl
		<< imprime_supervisores() << endl
		<< imprime_leitores() << endl
		<< imprime_emprestimos();
	return out.str();
}

void Biblioteca::escreve_livros_old(const string ficheiro) const {
	vector<Livro_old*> livrs {get_livros_old()};
	ofstream myfile(ficheiro);
	myfile << "";
	myfile.close();
	for (vector<Livro_old*>::const_iterator it = livrs.begin(); it != livrs.end(); it++) {
		(*it)->escreve(ficheiro);
	}
}

void Biblioteca::escreve_livros(const string ficheiro) const {
	vector<Livro*> livrs {get_livros()};
	ofstream myfile(ficheiro);
	myfile << "";
	myfile.close();
	for (vector<Livro*>::const_iterator it = livrs.begin(); it != livrs.end(); it++) {
		(*it)->escreve(ficheiro);
	}
}

void Biblioteca::escreve_funcionarios_old(const string ficheiro) const {
	ofstream file_f(ficheiro);
	file_f << "";
	file_f.close();
	vector<Funcionario_old*> funo {get_funcionarios_old()};
	for (vector<Funcionario_old*>::const_iterator it = funo.begin(); it != funo.end(); it++) {
		(*it)->escreve(ficheiro);
	}
}

void Biblioteca::escreve_funcionarios(const string ficheiro) const {
	ofstream file_f(ficheiro);
	file_f << "";
	file_f.close();
	vector<Funcionario*> fun {get_funcionarios()};
	for (vector<Funcionario*>::const_iterator it = fun.begin(); it != fun.end(); it++) {
		(*it)->escreve(ficheiro);
	}
}

void Biblioteca::escreve_supervisores(const string ficheiro) const {
	ofstream file_f(ficheiro);
	file_f << "";
	file_f.close();
	vector<Funcionario*> sup {get_supervisores()};
	for (vector<Funcionario*>::const_iterator it = sup.begin(); it != sup.end(); it++) {
		(*it)->escreve(ficheiro);
	}
}

void Biblioteca::escreve_leitores_old(const string ficheiro) const {
	ofstream myfile(ficheiro);
	myfile << "";
	myfile.close();
	vector<Leitor_old*> lei_old {get_leitores_old()};
	for (vector<Leitor_old*>::const_iterator it = lei_old.begin(); it != lei_old.end(); it++) {
		(*it)->escreve(ficheiro);
	}
}

void Biblioteca::escreve_leitores(const string ficheiro) const {
	ofstream myfile(ficheiro);
	myfile << "";
	myfile.close();
	vector<Leitor*> lei {get_leitores()};
	for (vector<Leitor*>::const_iterator it = lei.begin(); it != lei.end(); it++) {
		(*it)->escreve(ficheiro);
	}
}

void Biblioteca::escreve_emprestimos_old(const string ficheiro) const {
	ofstream myfile(ficheiro);
	myfile << "";
	myfile.close();
	vector<Emprestimo_old*> emp_old {get_emprestimos_old()};
	for (vector<Emprestimo_old*>::const_iterator it = emp_old.begin(); it != emp_old.end(); it++) {
		(*it)->escreve(ficheiro);
	}
}

void Biblioteca::escreve_emprestimos(const string ficheiro) const {
	ofstream myfile(ficheiro);
	myfile << "";
	myfile.close();
	vector<Emprestimo*> emp {get_emprestimos()};
	for (vector<Emprestimo*>::const_iterator it = emp.begin(); it != emp.end(); it++) {
		(*it)->escreve(ficheiro);
	}
}

void Biblioteca::escreve_utilizadores(const string ficheiro) const {
	ofstream myfile(ficheiro);
	myfile << "";
	myfile.close();
	for (vector<Utilizador*>::const_iterator it = utilizadores.begin(); it != utilizadores.end(); it++) {
		(*it)->escreve(ficheiro);
	}
}

void Biblioteca::escreve_pedidos_old(const string ficheiro) const {
    ofstream myfile(ficheiro);
    myfile << "";
    myfile.close();
    vector<Pedido_old*> ped_old {get_pedidos_old()};
    for (vector<Pedido_old*>::const_iterator it = ped_old.begin(); it != ped_old.end(); it++) {
        (*it)->escreve(ficheiro);
    }
}

void Biblioteca::escreve_pedidos(const string ficheiro) const {
    ofstream myfile(ficheiro);
    myfile << "";
    myfile.close();
    vector<Pedido*> emp {get_pedidos()};
    for (vector<Pedido*>::const_iterator it = emp.begin(); it != emp.end(); it++) {
        (*it)->escreve(ficheiro);
    }
}

/* e necessario apanhar as possiveis excecoes em caso de os ficheiros nao estarem disponiveis */
void Biblioteca::escreve(const string ficheiro_lvo, const string ficheiro_lv,
                         const string ficheiro_fco, const string ficheiro_fc,
                         const string ficheiro_sp, const string ficheiro_lto,
                         const string ficheiro_lt, const string ficheiro_epo,
                         const string ficheiro_ep, const string ficheiro_ut,
                         const string ficheiro_pdo, const string ficheiro_pd) const {
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
    try {
        escreve_pedidos(ficheiro_pd);
    }
    catch (Ficheiro_indisponivel &fic) {
        ostringstream ostr{};
        ostr << fic;
        cout << ostr.str();
    }
    try {
        escreve_pedidos_old(ficheiro_pdo);
    }
    catch (Ficheiro_indisponivel &fic) {
        ostringstream ostr{};
        ostr << fic;
        cout << ostr.str();
    }

}

void Biblioteca::le_livros_old(const string ficheiro) {
	ifstream islv(ficheiro);
	if (!islv) throw Ficheiro_indisponivel(ficheiro);
    string ids {}, anos {}, tit {}, auts {}, tem {}, isbns {}, cot {}, num_pags {}, edis {},
        exs {}, ymds {}, years {}, months {}, days {};
	struct tm* dtfinfo {};
	while (!islv.eof()) {
        getline(islv, ids);
        getline(islv, anos);
		getline(islv, tit);
		getline(islv, auts);
		getline(islv, tem);
		getline(islv, isbns);
		getline(islv, cot);
		getline(islv, num_pags);
		getline(islv, edis);
        getline(islv, exs);
        getline(islv, ymds);
        int ano = atoi(anos.c_str());
		unsigned long id = atol(ids.c_str());
		vector<string> aut {};
        vector<time_t> dtf {};
		string autor {};
        string ymd {};
		stringstream autss(auts);
        stringstream ymdss(ymds);
		while (getline(autss, autor, ';')) {
			aut.push_back(autor);
		}
        while (getline(ymdss, ymd, ';')) {
            stringstream ymds(ymd);
            time_t dataf {};
            if (ymds.str() == "0") dataf=0;
            else {
                getline(ymds, years, '/');
                getline(ymds, months, '/');
                getline(ymds, days);
                int year = atoi(years.c_str());
                int month = atoi(months.c_str());
                int day = atoi(days.c_str());
                time (&dataf);
                dtfinfo = localtime ( &dataf );
                dtfinfo->tm_year = year - 1900;
                dtfinfo->tm_mon = month - 1;
                dtfinfo->tm_mday = day;
                dataf = mktime (dtfinfo);
            }
            dtf.push_back(dataf);
        }
		long isbn = atol(isbns.c_str());
		int num_pag = atoi(num_pags.c_str());
		int edi = atoi(edis.c_str());
        int ex = atoi(exs.c_str());
		if (ids != "") {
			Livro_old* lo = new Livro_old {ano, tit, aut, tem, isbn, cot, num_pag, edi, true,
                id, ex, dtf};
			adiciona_livro_old(lo);
		}
	}
	islv.close();
}

void Biblioteca::le_livros(const string ficheiro) {
	ifstream islv(ficheiro);
	if (!islv) throw Ficheiro_indisponivel(ficheiro);
    string ids {}, anos {}, tit {}, auts {}, tem {}, isbns {}, cot {}, num_pags {}, edis {},
        exs {}, exds {}, eps {}, pds {};
	istringstream autss {};
	while (!islv.eof()) {
		getline(islv, ids);
        getline(islv, anos);
		getline(islv, tit);
		getline(islv, auts);
		getline(islv, tem);
		getline(islv, isbns);
		getline(islv, cot);
		getline(islv, num_pags);
		getline(islv, edis);
		getline(islv, exs);
        getline(islv, exds);
		getline(islv, eps);
		getline(islv, pds);
		unsigned long id = atol(ids.c_str());
        int ano = atoi(anos.c_str());
		vector<string> aut {};
		string autor {};
		stringstream autss(auts);
		while (getline(autss, autor, ';')) {
			aut.push_back(autor);
		}
		long isbn = atol(isbns.c_str());
		int num_pag = atoi(num_pags.c_str());
		int edi = atoi(edis.c_str());
        int ex = atoi(exs.c_str());
        vector<Emprestimo*> ep {};
        for (int i = 0; i != ex; i++) {
            ep.push_back(NULL);
        }
		if (ids != "") {
			Livro* lv = new Livro {ano, tit, aut, tem, isbn, cot, num_pag, edi, true, id, ex,
                ex, ep};
			adiciona_livro(lv);
		}
	}
	islv.close();
}

void Biblioteca::le_funcionarios_old(const string ficheiro) {
	ifstream isfc(ficheiro);
	if (!isfc) throw Ficheiro_indisponivel(ficheiro);
	string ids {}, nom {}, ymds {}, years{}, months{}, days{};
	unsigned long id {};
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
			Funcionario_old* fco = new Funcionario_old {id, nom, true};
			adiciona_funcionario_old(fco);
		}
	}
	isfc.close();
}

void Biblioteca::le_funcionarios(const string ficheiro) {
	ifstream isfc(ficheiro);
	if (!isfc) throw Ficheiro_indisponivel(ficheiro);
	string ids {}, nom {};
	unsigned long id {};
	while (!isfc.eof()) {
		getline(isfc, ids);
		getline(isfc, nom);
		id = atol(ids.c_str());
		if (ids != "") {
			Funcionario* fc = new Funcionario {nom, true, id};
			adiciona_funcionario(fc);
		}
	}
	isfc.close();
}

void Biblioteca::le_supervisores(const string ficheiro) {
	ifstream issp(ficheiro);
	if (!issp) throw Ficheiro_indisponivel(ficheiro);
	string ids {}, nom {}, fsids {};
	istringstream fsidss {};
	unsigned long id {}, fsid {};
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
			if (!encontrado) throw Object_nao_existe(fsid, "funcionario");
		}
		if (ids != "") {
			Supervisor* sp = new Supervisor {id, nom, func_sup, true};
			adiciona_funcionario(sp);
		}
	}
	issp.close();
}

void Biblioteca::le_leitores_old(const string ficheiro) {
	ifstream islt(ficheiro);
	if (!islt) throw Ficheiro_indisponivel(ficheiro);
    string ids {}, nom {}, tels {}, eml {}, ymds {}, years {}, months {}, days {}, ymdfs {},
        yearfs {}, monthfs {}, dayfs {}, tips {}, mrd {};
    unsigned long id {};
    long tel {};
	int tip {};
    time_t dt {}, dtf {};
	struct tm* dtinfo {};
	int year {}, month {}, day {}, yearf {}, monthf {}, dayf {};
	while (!islt.eof()) {
		getline(islt, ids);
		getline(islt, nom);
		getline(islt, tips);
		getline(islt, tels);
		getline(islt, eml);
        getline(islt, mrd);
		getline(islt, ymds);
        getline(islt, ymdfs);
		id = atol(ids.c_str());
		tip = atoi(tips.c_str());
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
        if (ymdfs == "0") dtf=0;
        else {
            stringstream ymdss(ymdfs);
            getline(ymdss, yearfs, '/');
            getline(ymdss, monthfs, '/');
            getline(ymdss, dayfs);
            yearf = atoi(yearfs.c_str());
            monthf = atoi(monthfs.c_str());
            dayf = atoi(dayfs.c_str());
            time (&dtf);
            dtinfo = localtime ( &dtf );
            dtinfo->tm_year = yearf - 1900;
            dtinfo->tm_mon = monthf - 1;
            dtinfo->tm_mday = dayf;
            dtf = mktime (dtinfo);
        }
		if (ids != "") {
			Leitor_old* lto = new Leitor_old {id, nom, tip, tel, eml, mrd, dt, true, dtf};
			adiciona_leitor_old(lto);
		}
	}
	islt.close();
}

void Biblioteca::le_leitores(const string ficheiro) {
	ifstream islt(ficheiro);
	if (!islt) throw Ficheiro_indisponivel(ficheiro);
    string ids {}, nom {}, tels {}, eml {}, epids {}, tips {}, mrd {}, ymds {}, years {},
        months {}, days {};
    unsigned long id {};
    long tel {};
	int tip{};
    time_t dt {};
    struct tm* dtinfo {};
    int year {}, month {}, day {};
	istringstream epidss {};
	string empids {};
	while (!islt.eof()) {
		getline(islt, ids);
		getline(islt, nom);
		getline(islt, tips);
		getline(islt, tels);
		getline(islt, eml);
        getline(islt, mrd);
        getline(islt, ymds);
		getline(islt, epids);
		id = atol(ids.c_str());
		tip = atoi(tips.c_str());
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
			Leitor* lt = new Leitor {nom, tip, tel, eml, mrd, dt, true, id, {}};
			adiciona_leitor(lt);
		}
	}
	islt.close();
}

void Biblioteca::le_emprestimos_old(const string ficheiro) {
	ifstream isep(ficheiro);
	if (!isep) throw Ficheiro_indisponivel(ficheiro);
	string ids {}, lvids {}, fcids {}, ltids {}, ymds {}, years {}, months {}, days {};
	string ymdse {}, yearse {}, monthse {}, dayse {};
	unsigned long id {}, lvid {}, fcid {}, ltid {};
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
			if (!encontrado) throw Object_nao_existe(lvid, "livro");
			encontrado = false;
			for (vector<Funcionario*>::const_iterator it = funcionarios.begin(); it != funcionarios.end(); it++) {
				if ((*it)->get_ID() == fcid) {
					fc = (*it);
					encontrado = true;
				}
			}
			if (!encontrado) throw Object_nao_existe(fcid, "funcionario");
			encontrado=false;
			for (vector<Leitor*>::const_iterator it = leitores.begin(); it != leitores.end(); it++) {
				if ((*it)->get_ID() == ltid) {
					lt = (*it);
					encontrado = true;
				}
			}
			if (!encontrado) throw Object_nao_existe(ltid, "leitor");
			Emprestimo_old* ep = new Emprestimo_old {lv, fc, lt, true, dt, id, dte};
			adiciona_emprestimo_old(ep);
		}
	}
	isep.close();
}

void Biblioteca::le_emprestimos(const string ficheiro) {
	ifstream isep(ficheiro);
	if (!isep) throw Ficheiro_indisponivel(ficheiro);
    string ids {}, lvids {}, fcids {}, ltids {}, ymds {}, years {}, months {}, days {}, inds {};
	unsigned long id {}, lvid {}, fcid {}, ltid {};
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
        getline(isep, inds);
		getline(isep, fcids);
		getline(isep, ltids);
		getline(isep, ymds);
		id = atol(ids.c_str());
        lvid = atol(lvids.c_str());
        unsigned long ind = atol(inds.c_str());
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
			if (!encontrado) throw Object_nao_existe(lvid, "livro");
			encontrado = false;
			for (vector<Funcionario*>::const_iterator it = funcionarios.begin(); it != funcionarios.end(); it++) {
				if ((*it)->get_ID() == fcid) {
					fc = (*it);
					encontrado = true;
				}
			}
			if (!encontrado) throw Object_nao_existe(fcid, "funcionario");
			encontrado=false;
			for (vector<Leitor*>::const_iterator it = leitores.begin(); it != leitores.end(); it++) {
				if ((*it)->get_ID() == ltid) {
					lt = (*it);
					encontrado = true;
				}
			}
			if (!encontrado) throw Object_nao_existe(ltid, "leitor");
			Emprestimo* ep = new Emprestimo {lv, ind, fc, lt, true, dt, id};
			try {
				adiciona_emprestimo(ep);
			}
			catch (Exemplar_indisponivel &liv) {
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

void Biblioteca::le_utilizadores(const string ficheiro) {
	ifstream isut(ficheiro);
	if (!isut) throw Ficheiro_indisponivel(ficheiro);
	string ids {}, pass {}, aces {};
	unsigned long id {};
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

void Biblioteca::le_pedidos_old(const string ficheiro) {
    ifstream ispd(ficheiro);
    if (!ispd) throw Ficheiro_indisponivel(ficheiro);
    string ids {}, lvids {}, fcids {}, ltids {}, ymds {}, years {}, months {}, days {};
    string ymdse {}, yearse {}, monthse {}, dayse {};
    unsigned long id {}, lvid {}, fcid {}, ltid {};
    time_t dt {}, dte{};
    struct tm* dtinfo {};
    struct tm* dteinfo {};
    int year {}, month {}, day {}, yeare {}, monthe {}, daye {};
    Livro* lv {};
    Funcionario* fc {};
    Leitor* lt {};
    bool encontrado {false};
    while (!ispd.eof()) {
        getline(ispd, ids);
        getline(ispd, lvids);
        getline(ispd, fcids);
        getline(ispd, ltids);
        getline(ispd, ymds);
        getline(ispd, ymdse);
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
            if (!encontrado) throw Object_nao_existe(lvid, "livro");
            encontrado = false;
            for (vector<Funcionario*>::const_iterator it = funcionarios.begin(); it != funcionarios.end(); it++) {
                if ((*it)->get_ID() == fcid) {
                    fc = (*it);
                    encontrado = true;
                }
            }
            if (!encontrado) throw Object_nao_existe(fcid, "funcionario");
            encontrado=false;
            for (vector<Leitor*>::const_iterator it = leitores.begin(); it != leitores.end(); it++) {
                if ((*it)->get_ID() == ltid) {
                    lt = (*it);
                    encontrado = true;
                }
            }
            if (!encontrado) throw Object_nao_existe(ltid, "leitor");
            Pedido_old* pd = new Pedido_old {lv, fc, lt, true, dt, id, dte};
            adiciona_pedido_old(pd);
        }
    }
    ispd.close();
}

void Biblioteca::le_pedidos(const string ficheiro) {
    ifstream ispd(ficheiro);
    if (!ispd) throw Ficheiro_indisponivel(ficheiro);
    string ids {}, lvids {}, fcids {}, ltids {}, ymds {}, years {}, months {}, days {};
    unsigned long id {}, lvid {}, fcid {}, ltid {};
    time_t dt {};
    struct tm* dtinfo {};
    int year {}, month {}, day {};
    Livro* lv {};
    Funcionario* fc {};
    Leitor* lt {};
    bool encontrado {false};
    while (!ispd.eof()) {
        getline(ispd, ids);
        getline(ispd, lvids);
        getline(ispd, fcids);
        getline(ispd, ltids);
        getline(ispd, ymds);
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
            if (!encontrado) throw Object_nao_existe(lvid, "livro");
            encontrado = false;
            for (vector<Funcionario*>::const_iterator it = funcionarios.begin(); it != funcionarios.end(); it++) {
                if ((*it)->get_ID() == fcid) {
                    fc = (*it);
                    encontrado = true;
                }
            }
            if (!encontrado) throw Object_nao_existe(fcid, "funcionario");
            encontrado=false;
            for (vector<Leitor*>::const_iterator it = leitores.begin(); it != leitores.end(); it++) {
                if ((*it)->get_ID() == ltid) {
                    lt = (*it);
                    encontrado = true;
                }
            }
            if (!encontrado) throw Object_nao_existe(ltid, "leitor");
            Pedido* pd = new Pedido {lv, fc, lt, true, dt, id};
            try {
                adiciona_pedido(pd);
            }
            catch (Livro_disponivel &liv) {
                ostringstream ostr{};
                ostr << liv;
                cout << ostr.str();
            }
        }
    }
    ispd.close();
}

/* e necessario apanhar as possiveis excecoes de indisponibilidade de algum ficheiro
 * ou de inexistencia de um livro, leitor ou funcionario a que a criacao de um emprestimo
 * (atual ou antigo) tenta aceder */
void Biblioteca::le(const string ficheiro_lvo, const string ficheiro_lv,
                    const string ficheiro_fco, const string ficheiro_fc,
                    const string ficheiro_sp, const string ficheiro_lto,
                    const string ficheiro_lt, const string ficheiro_epo,
                    const string ficheiro_ep, const string ficheiro_ut,
                    const string ficheiro_pdo, const string ficheiro_pd) {
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
    try {
        le_pedidos_old(ficheiro_pdo);
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
        le_pedidos(ficheiro_pd);
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
}

void Biblioteca::adiciona_inativos() {
    inativos = {};
    vector<Leitor*> leitors {get_leitores()};
    for (vector<Leitor*>::const_iterator it = leitors.begin(); it != leitors.end(); it++) {
        double tempo_dias {trunc(difftime(time(0), (*it)->get_data_ult_emp())/86400)};
        if (tempo_dias > 365) {
            inativos.insert(**it);
        }
    }
}

void Biblioteca::adiciona_inativo(const Leitor& lt) {
    inativos.insert(lt);
}

bool Biblioteca::remove_inativo(const Leitor& lt) {
    Hash_Leitores::const_iterator it = inativos.find(lt);
    if (it != inativos.end()) {
        inativos.erase(it);
        return true;
    }
    return false;
}

void Biblioteca::adiciona_disponiveis() {
    disponiveis.makeEmpty();
    vector<Livro*> livrs {get_livros()};
    for (vector<Livro*>::const_iterator it = livrs.begin(); it != livrs.end(); it++) {
        if ((*it)->get_ex_disponiveis() > 0) disponiveis.insert(**it);
    }
}

void Biblioteca::adiciona_disponivel(const Livro& lv) {
    disponiveis.insert(lv);
}

void Biblioteca::remove_disponivel(const Livro& lv) {
    disponiveis.remove(lv);
}


