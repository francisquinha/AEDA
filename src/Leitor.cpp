
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>

#include "Leitor.h"

using namespace std;

// construtor Leitor
Leitor::Leitor(long id, string nom, long tel, string eml, vector<Emprestimo*> ep_lt):
		 tem_id{id}, nome{nom}, telefone{tel}, email{eml}, emprestimos_leitor{ep_lt} {}

// adicionar Emprestimo a Leitor
void Leitor::adiciona_emp_leit(Emprestimo* ep){
	emprestimos_leitor.push_back(ep);
}

// remover Emprestimo de Leitor
void Leitor::remove_emp_leit(Emprestimo* ep){
	vector<Emprestimo*> emprestimos_manter{};
	long id_emp=ep->get_ID();
	unsigned int i{0};
	bool encontrado{false};
	while (i<emprestimos_leitor.size()){
		if (emprestimos_leitor[i]->get_ID()==id_emp){
			encontrado=true;
		}
		else{
			emprestimos_manter.push_back(emprestimos_leitor[i]);
		}
		i++;
	}
	if (encontrado) {
		emprestimos_leitor=emprestimos_manter;
	}
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
