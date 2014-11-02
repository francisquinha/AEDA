
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

vector<Emprestimo*> Biblioteca::get_emprestimos() {
	return emprestimos;
}

void Biblioteca::set_emprestimos(vector<Emprestimo*> emp) {
	emprestimos = emp;
}

vector<Funcionario*>Biblioteca::get_funcionarios() {
	return funcionarios;
}

void Biblioteca::set_funcionarios(vector<Funcionario*> func) {
	funcionarios = func;
}

vector<Funcionario*>Biblioteca::get_supervisores() {
	vector<Funcionario*> supervisores{};
	Supervisor* sp{};
	for (vector<Funcionario*>::const_iterator it=funcionarios.begin(); it!=funcionarios.end(); it++){
		sp = dynamic_cast<Supervisor*>(*it);
		if (sp!=0){
			supervisores.push_back(*it);
		}
	}
	return supervisores;
}

vector<Funcionario*>Biblioteca::get_funcionarios_n_sup() {
	vector<Funcionario*> funcionarios_n_sup{};
	Supervisor* sp{};
	for (vector<Funcionario*>::const_iterator it=funcionarios.begin(); it!=funcionarios.end(); it++){
		sp = dynamic_cast<Supervisor*>(*it);
		if (sp==0){
			funcionarios_n_sup.push_back(*it);
		}
	}
	return funcionarios_n_sup;
}

vector<Leitor*> Biblioteca::get_leitores() {
	return leitores;
}

void Biblioteca::set_leitores(vector<Leitor*> leit) {
	leitores = leit;
}

vector<Livro*> Biblioteca::get_livros() {
	return livros;
}

void Biblioteca::set_livros(vector<Livro*> livr) {
	livros = livr;
}

// adicionar Livro a Biblioteca
void Biblioteca::adiciona_livro(Livro* lv){
	livros.push_back(lv);
}

// adicionar Funcionario a Biblioteca
void Biblioteca::adiciona_funcionario(Funcionario* fc){
	funcionarios.push_back(fc);
}

// adicionar Leitor a Biblioteca
void Biblioteca::adiciona_leitor(Leitor* lt){
	leitores.push_back(lt);
}

// obter temas de livros de Biblioteca
vector<string> Biblioteca::get_temas(){
	vector<string> tem{};
	for (vector<Livro*>::const_iterator it=livros.begin(); it!= livros.end(); it++){
		tem.push_back((*it)->get_tema());
	}
	return tem;
}

// obter livros com tema xpto
vector<Livro*> Biblioteca::get_livros_tema(string xpto){
	vector<Livro*> lv{};
	for (vector<Livro*>::const_iterator it=livros.begin(); it!= livros.end(); it++){
		if ((*it)->get_tema()==xpto){
			lv.push_back(*it);
		}
	}
	return lv;
}

// remover Livro da Biblioteca
bool Biblioteca::remove_livro(long id){
	for (vector<Livro*>::const_iterator it=livros.begin(); it!=livros.end(); it++){
		if ((*it)->get_ID()==id){
			livros.erase(it);
			return true;
		}
	}
	throw Object_nao_existe(id);
}

// distribuir funcionarios por supervisores
void Biblioteca::distribui_funcionarios(){
	vector<Funcionario*> func_sup{};
	vector<Funcionario*> supervisores{get_supervisores()};
	vector<Funcionario*> funcionarios_n_sup{get_funcionarios_n_sup()};
	unsigned long num_sup{supervisores.size()};
	for (vector<Funcionario*>::const_iterator it=supervisores.begin(); it!=supervisores.end(); it++){
		(*it)->set_func_sup(func_sup);
	}
	for (unsigned int i{0}; i<funcionarios_n_sup.size(); i++){
		(supervisores[i%num_sup]->adiciona_func_sup(funcionarios_n_sup[i]));
	}
}

// remover Funcionario da Biblioteca
bool Biblioteca::remove_funcionario(long id){
	bool encontrado{false};
	for (vector<Funcionario*>::const_iterator it=funcionarios.begin(); it!=funcionarios.end(); it++){
		if ((*it)->get_ID()==id){
			encontrado=true;
			funcionarios.erase(it);
		}
	}
	if (encontrado) {
		distribui_funcionarios();
		return true;
	}
	throw Object_nao_existe(id);
}

// remover Leitor da Biblioteca
bool Biblioteca::remove_leitor(long id){
	for (vector<Leitor*>::const_iterator it=leitores.begin(); it!=leitores.end(); it++){
		if ((*it)->get_ID()==id){
			if ((*it)->get_emp_leit().size()==0){
				leitores.erase(it);
				return true;
			}
			else{
				throw Emprestimos_por_devolver(id, (*it)->get_nome(),(*it)->get_telefone(),(*it)->get_email(), (*it)->get_emp_leit());
			}
		}
	}
	throw Object_nao_existe(id);
}

// adicionar Emprestimo a Biblioteca
void Biblioteca::adiciona_emprestimo(Emprestimo* ep){
	Livro* lv=ep->get_livro();
	Leitor* lt=ep->get_leitor();
	vector<Emprestimo*> ep_lt=lt->get_emp_leit();
	if (lv->get_emprestado()==false){
		if (ep_lt.size()<3){
			lv->set_emprestado(true);
			lv->set_data_emp(ep->get_data());
			lt->adiciona_emp_leit(ep);
			emprestimos.push_back(ep);
		}
		else {
			cout << "Maximo emprestimos ID: " << lt->get_ID() << endl;
			throw Maximo_emprestimos(lt->get_ID(), lt->get_nome(),lt->get_telefone(),lt->get_email(), lt->get_emp_leit());
		}
	}
	else{
		cout << "Livro Indisponivel ID: " << lv->get_ID() << endl;
		throw Livro_indisponivel(lv->get_ID(),lv->get_titulo(),lv->get_autores(),lv->get_tema(), lv->get_ISBN(),
				lv->get_cota(),lv->get_num_paginas(),lv->get_edicao(),lv->get_emprestado(),lv->get_data_emp());
	}
}

// remover Emprestimo da Biblioteca
bool Biblioteca::remove_emprestimo(long id){
	for (vector<Emprestimo*>::const_iterator it=emprestimos.begin(); it!=emprestimos.end(); it++){
		if ((*it)->get_ID()==id){
			int dias{(*it)->get_atraso()};
			if (dias>0){
				cout << "Devolucao de livro " << dias << " dia(s) em atraso. Deve efetuar o pagamento de "
						<< (*it)->get_multa() << "euros.";
			}
			((*it)->get_livro())->set_emprestado(false);
			((*it)->get_livro())->set_data_emp({});
			((*it)->get_leitor())->remove_emp_leit(id);
			emprestimos.erase(it);
			return true;
		}
	}
	return false;
}

// obter Emprestimos atrasados de Biblioteca
vector<Emprestimo*> Biblioteca::get_emprestimos_atrasados(){
	vector<Emprestimo*> atrasados{};
	for (vector<Emprestimo*>::const_iterator it=emprestimos.begin(); it!=emprestimos.end(); it++){
		if ((*it)->get_atraso()>0){
			atrasados.push_back(*it);
		}
	}
	return atrasados;
}

// promover funcionario a supervisor
bool Biblioteca::promove_funcionario_supervisor(long id){
	vector<Funcionario*> func_sup{};
	vector<Funcionario*> supervisores{get_supervisores()};
	for (vector<Funcionario*>::const_iterator it=funcionarios.begin(); it!=funcionarios.end(); it++){
		if ((*it)->get_ID()==id){
			Supervisor* sp=new Supervisor{id, (*it)->get_nome(), func_sup};
			funcionarios.erase(it);
			funcionarios.push_back(sp);
			distribui_funcionarios();
			return true;
		}
	}
	return false;
}

// despromover supervisor a funcionario
bool Biblioteca::despromove_supervisor_funcionorario(long id){
	vector<Funcionario*> supervisores{get_supervisores()};
	for (vector<Funcionario*>::const_iterator it=supervisores.begin(); it!=supervisores.end(); it++){
		if ((*it)->get_ID()==id){
			Funcionario* fc=new Funcionario{id, (*it)->get_nome()};
			funcionarios.erase(it);
			funcionarios.push_back(fc);
			distribui_funcionarios();
			return true;
		}
	}
	return false;
}

// imprimir Biblioteca
string Biblioteca::imprime(){
	stringstream out{};
	out << "LIVROS" << endl;
	for (vector<Livro*>::const_iterator it=livros.begin(); it!=livros.end(); it++){
		out << (*it)->imprime();
	}
	out << endl << "FUNCIONARIOS" << endl;
	for (vector<Funcionario*>::const_iterator it=funcionarios.begin(); it!=funcionarios.end(); it++){
		out << (*it)->imprime();
	}
	out << endl << "LEITORES" << endl;
	for (vector<Leitor*>::const_iterator it=leitores.begin(); it!=leitores.end(); it++){
		out << (*it)->imprime();
	}
	out << endl << "EMPRESTIMOS" << endl;
	for (vector<Emprestimo*>::const_iterator it=emprestimos.begin(); it!=emprestimos.end(); it++){
		out << (*it)->imprime();
	}
	return out.str();
}

// escrever livros de Biblioteca
void Biblioteca::escreve_livros(string ficheiro){
	ofstream myfile (ficheiro);
	myfile << "";
	myfile.close();
	for (vector<Livro*>::const_iterator it=livros.begin(); it!=livros.end(); it++){
		(*it)->escreve(ficheiro);
	}
}

// escrever funcionarios de Biblioteca
void Biblioteca::escreve_funcionarios(string ficheiro_fc, string ficheiro_sp){
	ofstream file_f (ficheiro_fc);
	file_f << "";
	file_f.close();
	ofstream file_s (ficheiro_sp);
	file_s << "";
	file_s.close();
	for (vector<Funcionario*>::const_iterator it=funcionarios.begin(); it!=funcionarios.end(); it++){
		(*it)->escreve(ficheiro_fc, ficheiro_sp);
	}
}

// escrever leitor de Biblioteca
void Biblioteca::escreve_leitores(string ficheiro){
	ofstream myfile (ficheiro);
	myfile << "";
	myfile.close();
	for (vector<Leitor*>::const_iterator it=leitores.begin(); it!=leitores.end(); it++){
		(*it)->escreve(ficheiro);
	}
}

// escrever emprestimos de Biblioteca
void Biblioteca::escreve_emprestimos(string ficheiro){
	ofstream myfile (ficheiro);
	myfile << "";
	myfile.close();
	for (vector<Emprestimo*>::const_iterator it=emprestimos.begin(); it!=emprestimos.end(); it++){
		(*it)->escreve(ficheiro);
	}
}

// escrever todos os ficheiros de Biblioteca
void Biblioteca::escreve(string ficheiro_lv,string ficheiro_fc,string ficheiro_sp,string ficheiro_lt,string ficheiro_ep){
	escreve_livros(ficheiro_lv);
	escreve_funcionarios(ficheiro_fc, ficheiro_sp);
	escreve_leitores(ficheiro_lt);
	escreve_emprestimos(ficheiro_ep);
}

// ler livros de Biblioteca
void Biblioteca::le_livros(string ficheiro){
	ifstream islv(ficheiro);
	if (!islv) throw Ficheiro_indisponivel(ficheiro);
	string ids{}, tit{},auts{},tem{},isbns{},cot{},num_pags{},edis{},epts{},dts{};
	istringstream autss{};
	while (!islv.eof()){
		getline(islv,ids);
		getline(islv,tit);
		getline(islv,auts);
		getline(islv,tem);
		getline(islv,isbns);
		getline(islv,cot);
		getline(islv,num_pags);
		getline(islv,edis);
		getline(islv,epts);
		getline(islv,dts);
		long id = atol(ids.c_str());
		vector<string>aut{};
		string autor{};
		stringstream autss(auts);
		while(getline(autss,autor,';')){
			aut.push_back(autor);
		}
		long isbn = atol(isbns.c_str());
		int num_pag = atoi(num_pags.c_str());
		int edi = atoi(edis.c_str());
		bool ept = atoi(epts.c_str());
		time_t dt = atol(dts.c_str());
		if (ids!=""){
			Livro* lv = new Livro{id,tit,aut,tem,isbn,cot,num_pag,edi,ept,dt};
			livros.push_back(lv);
		}
	}
	islv.close();
}

// ler funcionarios de Biblioteca
void Biblioteca::le_funcionarios(string ficheiro_fc, string ficheiro_sp){
	ifstream isfc(ficheiro_fc);
	ifstream issp(ficheiro_sp);
	if (!isfc) throw Ficheiro_indisponivel(ficheiro_fc);
	if (!issp) throw Ficheiro_indisponivel(ficheiro_sp);
	string ids{}, nom{}, fsids{};
	istringstream fsidss{};
	long id{}, fsid{};
	bool encontrado{false};
	vector<Funcionario*> func_sup{};
	string funsid{};
	while (!isfc.eof()){
		getline(isfc,ids);
		getline(isfc,nom);
		id = atol(ids.c_str());
		if (ids!=""){
			Funcionario* fc = new Funcionario{id,nom};
			funcionarios.push_back(fc);
		}
	}
	isfc.close();
	while (!issp.eof()){
		getline(issp,ids);
		getline(issp,nom);
		getline(issp,fsids);
		id = atol(ids.c_str());
		stringstream fsidss(fsids);
		func_sup={};
		while(getline(fsidss,funsid,';')){
			encontrado=false;
			fsid = atol(funsid.c_str());
			for (vector<Funcionario*>::const_iterator it=funcionarios.begin(); it!=funcionarios.end(); it++){
				if ((*it)->get_ID()==fsid){
					func_sup.push_back(*it);
					encontrado=true;
				}
			}
			if (!encontrado) throw Object_nao_existe(fsid);
		}
		if (ids!=""){
			Supervisor* sp = new Supervisor{id,nom,func_sup};
			funcionarios.push_back(sp);
		}
	}
	issp.close();
}

// ler leitores de Biblioteca
void Biblioteca::le_leitores(string ficheiro){
	ifstream islt(ficheiro);
	if (!islt) throw Ficheiro_indisponivel(ficheiro);
	string ids{}, nom{}, tels{}, eml{}, epids{};
	long id{}, tel{}, epid{};
	istringstream epidss{};
	bool encontrado{false};
	vector<Emprestimo*> emp_leit{};
	string empids{};
	while (!islt.eof()){
		getline(islt,ids);
		getline(islt,nom);
		getline(islt,tels);
		getline(islt,eml);
		getline(islt,epids);
		id = atol(ids.c_str());
		tel = atol(tels.c_str());
		emp_leit={};
		if (epids!="" and emprestimos.size()>0){
			stringstream epidss(epids);
			while(getline(epidss,empids,';')){
				encontrado=false;
				epid = atol(empids.c_str());
				for (vector<Emprestimo*>::const_iterator it=emprestimos.begin(); it!=emprestimos.end(); it++){
					if ((*it)->get_ID()==epid){
						emp_leit.push_back(*it);
						encontrado=true;
					}
				}
				if (!encontrado) throw Object_nao_existe(epid);
			}
		}
		if (ids!=""){
			Leitor* lt = new Leitor{id,nom,tel,eml,emp_leit};
			leitores.push_back(lt);
		}
	}
	islt.close();
}

// acrescentar emprestimos a leitores de Biblioteca
void Biblioteca::le_leitores_emprestimos(string ficheiro){
	ifstream islt(ficheiro);
	if (!islt) throw Ficheiro_indisponivel(ficheiro);
	string ids{}, nom{}, tels{}, eml{}, epids{};
	long id{}, epid{};
	istringstream epidss{};
	bool encontrado_ep{false}, encontrado_lt{false};
	string empids{};
	Leitor* lt{};
	while (!islt.eof()){
		getline(islt,ids);
		getline(islt,nom);
		getline(islt,tels);
		getline(islt,eml);
		getline(islt,epids);
		id = atol(ids.c_str());
		encontrado_lt=false;
		if (ids!=""){
			for (vector<Leitor*>::const_iterator it=leitores.begin(); it!=leitores.end(); it++){
				if ((*it)->get_ID()==id){
					encontrado_lt=true;
					lt=(*it);
				}
			}
			if (!encontrado_lt) throw Object_nao_existe(id);
			if (epids!="" and emprestimos.size()>0){
				stringstream epidss(epids);
				while(getline(epidss,empids,';')){
					encontrado_ep=false;
					epid = atol(empids.c_str());
					for (vector<Emprestimo*>::const_iterator it=emprestimos.begin(); it!=emprestimos.end(); it++){
						if ((*it)->get_ID()==epid){
							lt->adiciona_emp_leit((*it));
							encontrado_ep=true;
						}
					}
					if (!encontrado_ep) throw Object_nao_existe(id);
				}
			}
			encontrado_ep=false;
		}
	}
	islt.close();
}

// ler emprestimos de Biblioteca
void Biblioteca::le_emprestimos(string ficheiro){
	ifstream isep(ficheiro);
	if (!isep) throw Ficheiro_indisponivel(ficheiro);
	string ids{}, lvids{}, fcids{}, ltids{}, dts{};
	long id{}, lvid{}, fcid{}, ltid{};
	time_t dt{};
	Livro* lv{};
	Funcionario* fc{};
	Leitor* lt{};
	bool encontrado{false};
	while (!isep.eof()){
		getline(isep,ids);
		getline(isep,lvids);
		getline(isep,fcids);
		getline(isep,ltids);
		getline(isep,dts);
		id = atol(ids.c_str());
		lvid = atol(lvids.c_str());
		fcid = atol(fcids.c_str());
		ltid = atol(ltids.c_str());
		if (ids!=""){
			encontrado=false;
			for (vector<Livro*>::const_iterator it=livros.begin(); it!=livros.end(); it++){
				if ((*it)->get_ID()==lvid){
					lv=(*it);
					encontrado=true;
				}
			}
			if (!encontrado) throw Object_nao_existe(lvid);
			encontrado=false;
			for (vector<Funcionario*>::const_iterator it=funcionarios.begin(); it!=funcionarios.end(); it++){
				if ((*it)->get_ID()==fcid){
					fc=(*it);
					encontrado=true;
				}
			}
			if (!encontrado) throw Object_nao_existe(fcid);
			encontrado=false;
			for (vector<Leitor*>::const_iterator it=leitores.begin(); it!=leitores.end(); it++){
				if ((*it)->get_ID()==ltid){
					lt=(*it);
					encontrado=true;
				}
			}
			if (!encontrado) throw Object_nao_existe(ltid);
			Emprestimo* ep = new Emprestimo{id,lv,fc,lt,dt};
			emprestimos.push_back(ep);
		}
	}
	isep.close();
}

// ler todos os ficheiros de Biblioteca
void Biblioteca::le(string ficheiro_lv, string ficheiro_fc, string ficheiro_sp, string ficheiro_lt, string ficheiro_ep){
	le_livros(ficheiro_lv);
	le_funcionarios(ficheiro_fc, ficheiro_sp);
	le_leitores(ficheiro_lt);
	le_emprestimos(ficheiro_ep);
	le_leitores_emprestimos(ficheiro_lt);
}
