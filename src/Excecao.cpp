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

// excecao para quando nao existe Livro, Funcionario, Leitor, Emprestimo
ostream& operator<<(ostream &out, Object_nao_existe &object){
	Livro* lv = dynamic_cast<Livro*>(&object);
	Funcionario* fc = dynamic_cast<Funcionario*>(&object);
	Leitor* lt = dynamic_cast<Leitor*>(&object);
	Emprestimo* ep = dynamic_cast<Emprestimo*>(&object);
	if (lv!=0){
		out << "Excecao. Nao existe Livro com ID ";
	}
	else if (fc!=0){
		out << "Excecao. Nao existe Funcionario com ID ";
	}
	else if (lt!=0){
		out << "Excecao. Nao existe Leitor com ID ";
	}
	else if (ep!=0){
		out << "Excecao. Nao existe Emprestimo com ID ";
	}
	else{
		out << "Excecao. Nao existe Object com ID ";
	}
	out << object.get_ID() << "." << endl;
	return out;
}

// excecao para quando o livro nao esta disponivel
ostream& operator<<(ostream &out, Livro_indisponivel &livro){
	out << "Excecao. Livro nao esta disponivel para emprestar. Foi emprestado ha " << livro.get_dias_emp() << " dia(s)." << endl;
	return out;
}

// excecao para quando o leitor que queremos remover ainda tem emprestimos para devolver
ostream& operator<<(ostream &out, Emprestimos_por_devolver &leitor){
	out << "Excecao. Tem que devolver emprestimo(s) com ID: ";
	for (vector<Emprestimo*>::const_iterator it=leitor.get_emp_leit().begin(); it!=leitor.get_emp_leit().end(); it++){
		out << (*it)->get_ID() << "; ";
	}
	out << endl;
	return out;
}

// excecao para quando o leitor ja tem 3 emprestimos
ostream& operator<<(ostream &out, Maximo_emprestimos &leitor){
	out << "Excecao. Leitor ja tem 3 emprestimos feitos." << endl;
	return out;
}

// excecao para quando o ficheiro nao esta disponivel
string Ficheiro_indisponivel::get_ficheiro(){
	return ficheiro;
}

ostream& operator<<(ostream &out, Ficheiro_indisponivel &ficheiro){
	out << "Excecao. O ficheiro " << ficheiro.get_ficheiro() << "nao esta disponivel." << endl;
	return out;
}

