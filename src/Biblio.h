
#ifndef SRC_BIBLIOTECA_H_
#define SRC_BIBLIOTECA_H_

#include "Supervisor.h"
#include "Emprestimo.h"
#include "Login.h"

class Livro;
class Funcionario;
class Supervisor;
class Leitor;
class Emprestimo;
class Utilizadores;
class Login;

class Biblioteca {
	std::vector<Livro*> livros;
	std::vector<Funcionario*> funcionarios;
	std::vector<Leitor*> leitores;
	std::vector<Emprestimo*> emprestimos;
	std::vector<Utilizador*> utilizadores;
public:
	Biblioteca() {};
	void adiciona_livro(Livro* lv1);
	void adiciona_funcionario(Funcionario* fc);
	void adiciona_leitor(Leitor* lt);
	void adiciona_emprestimo(Emprestimo* ep);
	void adiciona_utilizador(Utilizador* ut);
	bool remove_livro(long id);
	bool remove_funcionario(long id);
	bool remove_leitor(long id);
	bool remove_emprestimo(long id);
	bool remove_utilizador(long id);
	void distribui_funcionarios();
	bool promove_funcionario_supervisor(long ID);
	bool despromove_supervisor_funcionorario(long id);
	std::string imprime_livros();
	std::string imprime_funcionarios();
	std::string imprime_supervisores();
	std::string imprime_leitores();
	std::string imprime_emprestimos();
	std::string imprime();
	std::vector<Emprestimo*> get_emprestimos_atrasados();
	std::string imprime_emprestimos_atrasados();
	std::vector<Livro*> get_livros();
	std::vector<Emprestimo*> get_emprestimos();
	void set_emprestimos(std::vector<Emprestimo*> emp);
	std::vector<Funcionario*> get_funcionarios();
	void set_funcionarios(std::vector<Funcionario*> func);
	std::vector<Funcionario*> get_supervisores();
	std::vector<Funcionario*> get_funcionarios_n_sup();
	std::vector<Leitor*> get_leitores();
	void set_leitores(std::vector<Leitor*> leit);
	std::vector<Utilizador*> get_utilizadores();
	void set_utilizadores(std::vector<Utilizador*> util);
	void set_livros(std::vector<Livro*> livr);
	std::vector<std::string> get_temas();
	std::vector<Livro*> get_livros_tema(std::string xpto);
	void escreve_livros(std::string ficheiro);
	void escreve_funcionarios(std::string ficheiro_fc, std::string ficheiro_sp);
	void escreve_leitores(std::string ficheiro);
	void escreve_emprestimos(std::string ficheiro);
    void escreve_utilizadores(std::string ficheiro); // escreve utilizadores de Biblioteca num ficheiro; parametros: string com nome do ficheiro
	void escreve(std::string ficheiro_lv, std::string ficheiro_fc, std::string ficheiro_sp, std::string ficheiro_lt, std::string ficheiro_ep, std::string ficheiro_ut);
	void le_livros(std::string ficheiro);
	void le_funcionarios(std::string ficheiro_fc, std::string ficheiro_sp);
	void le_leitores(std::string ficheiro);
	void le_leitores_emprestimos(std::string ficheiro);
	void le_emprestimos(std::string ficheiro);
    void le_utilizadores(std::string ficheiro); // le utilizadores de um ficheiro e coloca-os no vetor de utilizadores de Biblioteca; parametros: string com nome do ficheiro
	void le(std::string ficheiro_lv, std::string ficheiro_fc, std::string ficheiro_sp, std::string ficheiro_lt, std::string ficheiro_ep, std::string ficheiro_ut);
};

#endif /* SRC_BIBLIOTECA_H_ */
