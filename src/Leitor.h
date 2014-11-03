
#ifndef SRC_LEITOR_H_
#define SRC_LEITOR_H_

#include "Emprestimo.h"
#include "Object.h"

class Emprestimo;
class Object;

class Leitor: public Object {
	std::string nome;
	long telefone;
	std::string email;
	std::vector<Emprestimo*> emprestimos_leitor;
	static long num_leitores;
public:
	Leitor(long id, std::string nom, long tel, std::string eml, std::vector<Emprestimo*> ep_lt);
	Leitor(std::string nom, long tel, std::string eml, std::vector<Emprestimo*> ep_lt);
	Leitor(long id, std::string nom, long tel, std::string eml);
	Leitor(std::string nom, long tel, std::string eml);
	std::string imprime();
	std::string get_nome();
	void set_nome(std::string nom);
	long get_telefone();
	void set_telefone(long tel);
	std::string get_email();
	void set_email(std::string eml);
	void adiciona_emp_leit(Emprestimo* ep);
	bool remove_emp_leit(long id);
	std::vector<Emprestimo*> get_emp_leit();
	void set_emp_leit(std::vector<Emprestimo*> emp_leit);
	std::string imprime_emp_leit();
	std::vector<Emprestimo*> get_emprestimos_atrasados();
	void escreve(std::string ficheiro);
};

class Emprestimos_por_devolver: public Leitor {
public:
	Emprestimos_por_devolver(long id, std::string nom, int tel, std::string eml, std::vector<Emprestimo*> ep_lt): Leitor{id, nom, tel, eml, ep_lt} {};
};

class Maximo_emprestimos: public Leitor {
public:
	Maximo_emprestimos(long id, std::string nom, int tel, std::string eml, std::vector<Emprestimo*> ep_lt): Leitor{id, nom, tel, eml, ep_lt} {};
};

#endif /* SRC_LEITOR_H_ */
