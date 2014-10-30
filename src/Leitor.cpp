
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

#include "Leitor.h"

using namespace std;

long Leitor::num_leitores{0};

// construtor Leitor
Leitor::Leitor(long id, string nom, long tel, string eml, vector<Emprestimo*> ep_lt):
		 Object{id}, nome{nom}, telefone{tel}, email{eml}, emprestimos_leitor{ep_lt} {}
Leitor::Leitor(string nom, long tel, string eml, vector<Emprestimo*> ep_lt): Object{num_leitores+1},
		nome{nom}, telefone{tel}, email{eml}, emprestimos_leitor{ep_lt} {num_leitores++;}

// adicionar Emprestimo a Leitor
void Leitor::adiciona_emp_leit(Emprestimo* ep){
	emprestimos_leitor.push_back(ep);
}

// remover Emprestimo de Leitor
bool Leitor::remove_emp_leit(long id){
	for (vector<Emprestimo*>::const_iterator it=emprestimos_leitor.begin(); it!=emprestimos_leitor.end();it++){
		if ((*it)->get_ID()==id){
			emprestimos_leitor.erase(it);
			return true;
		}
	}
	return false;
}

// obter Emprestimos de Leitor
vector<Emprestimo*> Leitor::get_emp_leit(){
	return emprestimos_leitor;
}

// imprimir Leitor
string Leitor::imprime(){
	stringstream out{};
	out << "ID: "<< get_ID() << endl<< "Nome: " << nome << endl << "ID Emprestimos: ";
	for (vector<Emprestimo*>::const_iterator it=emprestimos_leitor.begin(); it!=emprestimos_leitor.end(); it++){
		out << (*it)->get_ID() << "; ";
	}
	out << endl;
	return out.str();
}

// escrever Leitor
void Leitor::escreve(){
	stringstream out{};
	out << get_ID() << endl
			<< nome << endl;
	for (vector<Emprestimo*>::const_iterator it=emprestimos_leitor.begin(); it!=emprestimos_leitor.end(); it++){
		out << (*it)->get_ID() << "; ";
	}
	out << endl;
	ofstream myfile ("Leitor.txt",ios::app);
	if (myfile.is_open()){
		myfile << out.str();
		myfile.close();
	}
	else cout << "Unable to open file";
}
