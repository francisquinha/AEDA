
#ifndef SRC_EMPRESTIMO_H_
#define SRC_EMPRESTIMO_H_

#include "Livro.h"
#include "Funcionario.h"
#include "Leitor.h"
#include "tem_id.h"
#include <ctime>

class Livro;
class Funcionario;
class Leitor;
class tem_id;

class Emprestimo: public tem_id{
	Livro* livro;
	Funcionario* funcionario;
	Leitor* leitor;
	std::time_t data; // data em que e feito o emprestimo
	static long num_emprestimos;
public:
	Emprestimo(long id, Livro* lv, Funcionario* fc, Leitor* lt);
	Emprestimo(Livro* lv, Funcionario* fc, Leitor* lt);
	Livro* get_livro();
	void set_livro(Livro* lv);
	Funcionario* get_funcionario();
	void set_funcionario(Funcionario* fc);
	Leitor* get_leitor();
	void set_leitor(Leitor* lt);
	std::time_t get_data();
	void set_data(std::time_t dt);
	int get_atraso();
	double get_multa();
	std::string imprime();
	void escreve();
};

#endif /* SRC_EMPRESTIMO_H_ */
