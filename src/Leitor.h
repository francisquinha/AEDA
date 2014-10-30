
#ifndef SRC_LEITOR_H_
#define SRC_LEITOR_H_

#include "Emprestimo.h"
#include "tem_id.h"

class Emprestimo;
class tem_id;

class Leitor: public tem_id {
	std::string nome;
	long telefone;
	std::string email;
	std::vector<Emprestimo*> emprestimos_leitor;
	static long num_leitores;
public:
	Leitor(long id, std::string nom, long tel, std::string eml, std::vector<Emprestimo*> ep_lt);
	Leitor(std::string nom, long tel, std::string eml, std::vector<Emprestimo*> ep_lt);
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
	void escreve();
};

#endif /* SRC_LEITOR_H_ */
