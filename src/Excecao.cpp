#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <fstream>

#include "Excecao.h"

using namespace std;

/** @file
 *
 * @brief Source das classes e dos operadores << de Excecao.
 *
 * Todas as excessoes estao aqui.
 **/


// excecao para quando nao existe Livro, Funcionario, Leitor, Emprestimo
ostream& operator<<(ostream &out, Object_nao_existe &object) {
	out << "Nao existe ID ";
	out << object.get_ID() << "." << endl;
	return out;
}

// excecao para quando o livro nao esta disponivel
ostream& operator<<(ostream &out, Livro_indisponivel &livro) {
	out << "Livro com ID " << livro.get_ID() << " nao esta disponivel para emprestar. Foi emprestado ha " << livro.get_dias_emp() << " dia(s)." << endl;
	return out;
}

// excecao para quando o livro que queremos remover esta emprestado
ostream& operator<<(ostream &out, Livro_emprestado &livro) {
	out << "Livro emprestado, tem que devolver emprestimo com ID " << livro.get_ID_ep() << "." << endl;
	return out;
}

// excecao para quando o leitor que queremos remover ainda tem emprestimos para devolver
ostream& operator<<(ostream &out, Emprestimos_por_devolver &leitor) {
	out << "Tem que devolver emprestimo(s) com ID: ";
	for (vector<Emprestimo*>::const_iterator it = leitor.get_emp_leit().begin(); it != leitor.get_emp_leit().end(); it++) {
		out << (*it)->get_ID() << "; ";
	}
	out << endl;
	return out;
}

// excecao para quando o leitor ja tem 3 emprestimos
ostream& operator<<(ostream &out, Maximo_emprestimos &leitor) {
	out << "Leitor ja tem 3 emprestimos feitos." << endl;
	return out;
}

// excecao para quando o ficheiro nao esta disponivel
string Ficheiro_indisponivel::get_ficheiro() {
	return ficheiro;
}

ostream& operator<<(ostream &out, Ficheiro_indisponivel &ficheiro) {
	out << "O ficheiro " << ficheiro.get_ficheiro() << " nao esta disponivel." << endl;
	return out;
}

