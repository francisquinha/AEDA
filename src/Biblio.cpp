
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <fstream>

#include "Biblio.h"

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

vector<Supervisor*>Biblioteca::get_supervisores() {
	return supervisores;
}

void Biblioteca::set_supervisores(vector<Supervisor*> sup) {
	supervisores = sup;
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

// remover Livro da Biblioteca
bool Biblioteca::remove_livro(long id){
	vector<Livro*> livros_manter{};
	bool encontrado{false};
	for (unsigned int i{0}; i<livros.size(); i++){
		if (livros[i]->get_ID()==id){
			encontrado=true;
		}
		else{
			livros_manter.push_back(livros[i]);
		}
	}
	if (encontrado) {
		livros=livros_manter;
		return true;
	}
	return false;
}

// remover Funcionario da Biblioteca
bool Biblioteca::remove_funcionario(long id){
	vector<Funcionario*> funcionarios_manter{};
	bool encontrado{false};
	for (unsigned int i{0}; i<funcionarios.size(); i++){
		if (funcionarios[i]->get_ID()==id){
			encontrado=true;
		}
		else{
			funcionarios_manter.push_back(funcionarios[i]);
		}
	}
	if (encontrado) {
		funcionarios=funcionarios_manter;
		return true;
	}
	return false;
}

// remover Leitor da Biblioteca
bool Biblioteca::remove_leitor(long id){
	vector<Leitor*> leitores_manter{};
	bool encontrado{false};
	for (unsigned int i{0}; i<leitores.size(); i++){
		if (leitores[i]->get_ID()==id){
			encontrado=true;
		}
		else{
			leitores_manter.push_back(leitores[i]);
		}
	}
	if (encontrado) {
		leitores=leitores_manter;
		return true;
	}
	return false;
}

// adicionar Emprestimo a Biblioteca
void Biblioteca::adiciona_emprestimo(Emprestimo* ep){
	Livro* lv=ep->get_livro();
	Leitor* lt=ep->get_leitor();
	vector<Emprestimo*> ep_lt=lt->get_emp_leit();
	int di=lv->get_dias_indisponivel();
	if (lv->get_emprestado()==false){
		if (ep_lt.size()<3){
			lv->set_emprestado(true);
			lv->set_dias_indisponivel(7);
			lt->adiciona_emp_leit(ep);
			emprestimos.push_back(ep);
		}
		else {
			cout << "Leitor ja tem 3 emprestimos feitos.";
		}
	}
	else {
		cout << "Este livro nao esta disponivel para emprestar. Regressa dentro de " << di << "dias.";
	}
}

// remover Emprestimo da Biblioteca
bool Biblioteca::remove_emprestimo(long id){
	vector<Emprestimo*> emprestimos_manter{};
	Livro* lv{};
	Leitor* lt{};
	bool encontrado{false};
	Emprestimo* ep{};
	for (unsigned int i{0}; i<emprestimos.size(); i++){
		if (emprestimos[i]->get_ID()==id){
			encontrado=true;
			ep=emprestimos[i];
			lv=ep->get_livro();
			lt=ep->get_leitor();
		}
		else{
			emprestimos_manter.push_back(emprestimos[i]);
		}
	}
	if (encontrado) {
		lv->set_emprestado(false);
		lv->set_dias_indisponivel(0);
		lt->remove_emp_leit(ep);
		int dias{ep->get_atraso()};
		if (dias>0){
			cout << "Devolucao de livro " << dias << " dia(s) em atraso. Deve efetuar o pagamento de "
					<< ep->get_multa() << "euros.";
		}
		emprestimos=emprestimos_manter;
		return true;
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

//notificar leitor por telefone ou email do atraso???


// distribuir funcionarios por supervisores
void Biblioteca::distribui_funcionarios(){
	vector<Funcionario*> func_sup{};
	unsigned long num_sup{supervisores.size()};
	for (vector<Supervisor*>::const_iterator it=supervisores.begin(); it!=supervisores.end(); it++){
		(*it)->set_func_sup(func_sup);
	}
	for (unsigned int i{0}; i<funcionarios.size(); i++){
		(supervisores[i%num_sup]->adiciona_func_sup(funcionarios[i]));
	}
}

// promover funcionario a supervisor
bool Biblioteca::promove_funcionario_supervisor(long id){
	vector<Funcionario*> funcionarios_restantes{};
	Funcionario* fc{};
	bool existe{false};
	for (vector<Funcionario*>::const_iterator it=funcionarios.begin(); it!=funcionarios.end(); it++){
		if ((*it)->get_ID()==id){
			fc=(*it);
			existe=true;
		}
		else{
			funcionarios_restantes.push_back(*it);
		}
	}
	if (existe){
		vector<Funcionario*> func_sup{};
		string nome{fc->get_nome()};
		Supervisor* sp=new Supervisor{id, nome, func_sup};
		supervisores.push_back(sp);
		funcionarios=funcionarios_restantes;
		distribui_funcionarios();
	}
	return existe;
}

// remover supervisor
bool Biblioteca::remove_supervisor(long id){
	bool existe{false};
	vector<Supervisor*> supervisores_restantes{};
	Supervisor* sp{};
	for (vector<Supervisor*>::const_iterator it=supervisores.begin(); it!=supervisores.end(); it++){
		if ((*it)->get_ID()==id){
			sp=(*it);
			existe=true;
		}
		else{
			supervisores_restantes.push_back(*it);
		}
	}
	if (existe){
		supervisores=supervisores_restantes;
		distribui_funcionarios();
	}
	return existe;
}

// despromover supervisor a funcionario
bool Biblioteca::despromove_supervisor_funcionorario(long id){
	vector<Supervisor*> supervisores_restantes{};
	Supervisor* sp{};
	bool existe{false};
	for (vector<Supervisor*>::const_iterator it=supervisores.begin(); it!=supervisores.end(); it++){
		if ((*it)->get_ID()==id){
			sp=(*it);
			existe=true;
		}
		else{
			supervisores_restantes.push_back(*it);
		}
	}
	if (existe){
		supervisores=supervisores_restantes;
		funcionarios.push_back(sp);
		distribui_funcionarios();
	}
	return existe;
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
	out << endl << "SUPERVISORES" << endl;
	for (vector<Supervisor*>::const_iterator it=supervisores.begin(); it!=supervisores.end(); it++){
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
void Biblioteca::escreve_livros(){
	ofstream myfile ("Livro.txt");
	myfile << "";
	myfile.close();
	for (vector<Livro*>::const_iterator it=livros.begin(); it!=livros.end(); it++){
		(*it)->escreve();
	}
}

// escrever funcionarios de Biblioteca
void Biblioteca::escreve_funcionarios(){
	ofstream myfile ("Funcionario.txt");
	myfile << "";
	myfile.close();
	for (vector<Funcionario*>::const_iterator it=funcionarios.begin(); it!=funcionarios.end(); it++){
		(*it)->escreve();
	}
}

// escrever supervisores de Biblioteca
void Biblioteca::escreve_supervisores(){
	ofstream myfile ("Supervisor.txt");
	myfile << "";
	myfile.close();
	for (vector<Supervisor*>::const_iterator it=supervisores.begin(); it!=supervisores.end(); it++){
		(*it)->escreve();
	}
}

// escrever leitor de Biblioteca
void Biblioteca::escreve_leitores(){
	ofstream myfile ("Leitor.txt");
	myfile << "";
	myfile.close();
	for (vector<Leitor*>::const_iterator it=leitores.begin(); it!=leitores.end(); it++){
		(*it)->escreve();
	}
}

// escrever emprestimos de Biblioteca
void Biblioteca::escreve_emprestimos(){
	ofstream myfile ("Emprestimo.txt");
	myfile << "";
	myfile.close();
	for (vector<Emprestimo*>::const_iterator it=emprestimos.begin(); it!=emprestimos.end(); it++){
		(*it)->escreve();
	}
}

// escrever todos os ficheiros de Biblioteca
void Biblioteca::escreve(){
	escreve_livros();
	escreve_funcionarios();
	escreve_supervisores();
	escreve_leitores();
	escreve_emprestimos();
}
