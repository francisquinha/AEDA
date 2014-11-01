
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <fstream>

#include "Emprestimo.h"
#include "Excecao.h"

using namespace std;

long Emprestimo::num_emprestimos{0};

// construtor Emprestimo
Emprestimo::Emprestimo(long id, Livro* lv, Funcionario* fc, Leitor* lt, time_t dt): Object{id},
		livro{lv}, funcionario{fc}, leitor{lt}, data{dt}{}
Emprestimo::Emprestimo(long id, Livro* lv, Funcionario* fc, Leitor* lt): Object{id},
		livro{lv}, funcionario{fc}, leitor{lt}, data{std::time(NULL)}{}
Emprestimo::Emprestimo(Livro* lv, Funcionario* fc, Leitor* lt): Object{num_emprestimos+1},
		livro{lv}, funcionario{fc}, leitor{lt}, data{std::time(NULL)}{num_emprestimos++;}

// obter Livro de Emprestimo
Livro* Emprestimo::get_livro(){
	return livro;
}

// obter Leitor de Emprestimo
Leitor* Emprestimo::get_leitor(){
	return leitor;
}

// obter data de Emprestimo
time_t Emprestimo::get_data(){
	return data;
}

// obter Funcionario de Emprestimo
Funcionario* Emprestimo::get_funcionario(){
	return funcionario;
}

// obter atraso na entrega de Emprestimo
int Emprestimo::get_atraso(){
	time_t hoje = std::time(NULL);
	double tempo_dias{floor(difftime(hoje,data)/86400)};
	double tempo_extra{min(tempo_dias-7,0.0)};
	return (int) tempo_extra;
}

// obter multa na entraga de Emprestimo
double Emprestimo::get_multa(){
	int tempo_extra=get_atraso();
	int tempo_extra_extra{min(tempo_extra-7,0)};
	double divida{tempo_extra*0.25+tempo_extra_extra*0.5};
	return divida;
}

// imprimir Emprestimo
string Emprestimo::imprime(){
	stringstream out{};
	out << "ID: "<< get_ID() << endl
			<< "ID Livro: " << livro->get_ID() << endl
			<< "ID Funcionario: " << funcionario->get_ID() << endl
			<< "ID Leitor: " << leitor->get_ID() << endl
			<< "Data: " << data << endl;
	return out.str();
}

// escrever Livro
void Emprestimo::escreve(){
	stringstream out{};
	out << get_ID() << endl
	<< livro->get_ID() << endl
	<< funcionario->get_ID() << endl
	<< leitor->get_ID() << endl
	<< data << endl;
	ofstream myfile ("Emprestimo.txt",ios::app);
	if (myfile.is_open()){
		myfile << out.str();
		myfile.close();
	}
	else throw Ficheiro_indisponivel("Emprestimo.txt");
}
