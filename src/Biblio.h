
#ifndef SRC_BIBLIOTECA_H_
#define SRC_BIBLIOTECA_H_

#include "Supervisor.h"
#include "Emprestimo.h"

class Livro;
class Funcionario;
class Supervisor;
class Leitor;
class Emprestimo;

class Biblioteca {
	std::vector<Livro*> livros;
	std::vector<Funcionario*> funcionarios;
//	std::vector<Supervisor*> supervisores; // supervisores passam a estar no vector de funcionarios - polimorfismo
	std::vector<Leitor*> leitores;
	std::vector<Emprestimo*> emprestimos;
public:
	Biblioteca() {};
	void adiciona_livro(Livro* lv1);
	void adiciona_funcionario(Funcionario* fc);
	void adiciona_leitor(Leitor* lt);
	void adiciona_emprestimo(Emprestimo* ep);
	bool remove_livro(long id);
	bool remove_funcionario(long id);
	bool remove_leitor(long id);
	bool remove_emprestimo(long id);
	void distribui_funcionarios();
	bool promove_funcionario_supervisor(long ID);
//	bool remove_supervisor(long ID); // deixa de fazer sentido com os supervisores no vector dos funcionarios
	bool despromove_supervisor_funcionorario(long id);
	std::string imprime();
	std::vector<Emprestimo*> get_emprestimos_atrasados();
	std::vector<Livro*> get_livros();
	std::vector<Emprestimo*> get_emprestimos();
	void set_emprestimos(std::vector<Emprestimo*> emp);
	std::vector<Funcionario*> get_funcionarios();
	void set_funcionarios(std::vector<Funcionario*> func);
	std::vector<Funcionario*> get_supervisores();
	std::vector<Funcionario*> get_funcionarios_n_sup();
	std::vector<Leitor*> get_leitores();
	void set_leitores(std::vector<Leitor*> leit);
	void set_livros(std::vector<Livro*> livr);
	std::vector<std::string> get_temas();
	std::vector<Livro*> get_livros_tema(std::string xpto);
	void escreve_livros();
	void escreve_funcionarios();
	void escreve_leitores();
	void escreve_emprestimos();
	void escreve();
	void le_livros(std::string ficheiro);
	void le_funcionarios(std::string ficheiro_fc, std::string ficheiro_sp);
	void le_leitores(std::string ficheiro);
	void le_emprestimos(std::string ficheiro);
	void le(std::string ficheiro_lv,std::string ficheiro_fc,std::string ficheiro_sp,std::string ficheiro_lt,std::string ficheiro_ep);
};

#endif /* SRC_BIBLIOTECA_H_ */
