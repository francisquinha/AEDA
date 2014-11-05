
#ifndef SRC_BIBLIOTECA_H_
#define SRC_BIBLIOTECA_H_

#include "Administrador.h"
#include "Supervisor.h"
#include "Emprestimo.h"
#include "Login.h"
#include "Excecao.h"

class Livro;
class Funcionario;
class Supervisor;
class Leitor;
class Emprestimo;
class Utilizadores;
class Login;

/* Biblioteca.
 *
 * Contem os seguintes vectores: livros - todos os livros da Biblioteca;
 * 							 	 funcionarios - todos os funcionarios, incluindo os supervisores e o administrador;
 * 							 	 leitores - todos os leitores da Biblioteca;
 * 							 	 emprestimos - todos os emprestimos que existem atualmente na Biblioteca;
 * 							 	 utilizadores - todos os utilizadores do sistema informatico.
 *
 * Notas: nao e guardado historico dos emprestimos, mas devia ser, isto e, devia existir um outro vector de emprestimos_antigos,
 *  com o atributo adicional data_entrega;
 * 		  os utilizadores devem ser os mesmos que os funcionarios e o seu ID tambem, caso contrario nem todas as funcoes funcionarao
 * 	corretamente. */
class Biblioteca {

	std::vector<Livro*> livros;
	std::vector<Funcionario*> funcionarios;
	std::vector<Leitor*> leitores;
	std::vector<Emprestimo*> emprestimos;
	std::vector<Utilizador*> utilizadores;

public:

	/* Construtor de Biblioteca. */
	Biblioteca() {};

	/* Funcao para adicionar um novo livro a Biblioteca.
	 * Parametros: Livro* lv - apontador para o novo livro. */
	void adiciona_livro(Livro* lv);

	/* Funcao para adicionar um novo funcionario a Biblioteca.
	 * Parametros: Funcionario* fc - apontador para o novo funcionario. */
	void adiciona_funcionario(Funcionario* fc);

	/* Funcao para adicionar um novo leitor a Biblioteca.
	 * Parametros: Leitor* lt - apontador para o novo leitor. */
	void adiciona_leitor(Leitor* lt);

	/* Funcao para adicionar um novo emprestimo a Biblioteca.
	 * Parametros: Emprestimo* ep - apontador para o novo emprestimo. */
	void adiciona_emprestimo(Emprestimo* ep);

	/* Funcao para adicionar um novo utilizador a Biblioteca.
	 * Parametros: Utilizador* ut - apontador para o novo utilizador. */
	void adiciona_utilizador(Utilizador* ut);

	/* Funcao para remover um livro da Biblioteca.
	 * Parametros: lond id - id do livro que queremos remover.
	 * Retorno: true - se existe algum livro com esse id;
	 * 			excecao Object_nao_existe - caso contrario.
	 * Nota: remove o primeiro livro com o id indicado. */
	bool remove_livro(long id);

	/* Funcao para remover um funcionario da Biblioteca.
	 * Parametros: lond id - id do funcionario que queremos remover.
	 * Retorno: true - se existe algum funcionario com esse id;
	 * 			excecao Object_nao_existe - caso contrario.
	 * Nota: remove o primeiro funcionario com o id indicado. */
	bool remove_funcionario(long id);

	/* Funcao para remover um leitor da Biblioteca.
	 * Parametros: lond id - id do leitor que queremos remover.
	 * Retorno: true - se existe algum leitor com esse id;
	 * 			excecao Object_nao_existe - caso contrario.
	 * Nota: remove o primeiro leitor com o id indicado. */
	bool remove_leitor(long id);

	/* Funcao para remover um emprestimo da Biblioteca.
	 * Parametros: lond id - id do emprestimo que queremos remover.
	 * Retorno: true - se existe algum emprestimo com esse id;
	 * 			excecao Object_nao_existe - caso contrario.
	 * Nota: remove o primeiro emprestimo com o id indicado. */
	bool remove_emprestimo(long id);

	/* Funcao para remover um utilizador da Biblioteca.
	 * Parametros: lond id - id do utilizador que queremos remover.
	 * Retorno: true - se existe algum utilizador com esse id;
	 * 			excecao Object_nao_existe - caso contrario.
	 * Nota: remove o primeiro utilizador com o id indicado. */
	bool remove_utilizador(long id);

	/* Funcao para distribuir uniformemente os funcionarios pelos supervisores.
	 * No final o numero de funcionarios por supervisor e o mais equilibrado possivel. */
	void distribui_funcionarios();

	/* Funcao para promover um funcionario a supervisor.
	 * Parametros: long id - id do funcionario que pretendemos promover.
	 * Retorno: true - se existe um funcionario com esse id;
	 * 			excecao Object_nao_existe - caso contrario.
	 * Notas: promove o primeiro funcionario com o id indicado;
	 * 		  no final os funcionarios sao redistribuidos, pelo que se mantem o equlibrio
	 *  entre o numero de funcionarios por supervisor. */
	bool promove_funcionario_supervisor(long id);

	/* Funcao para despromover um supervisor a funcionario.
	 * Parametros: long id - id do supervisor que pretendemos despromover.
	 * Retorno: true - se existe um supervisor com esse id;
	 * 			excecao Object_nao_existe - caso contrario.
	 * Notas: despromove o primeiro supervisor com o id indicado;
	 * 		  no final os funcionarios sao redistribuidos, pelo que se mantem o equlibrio
	 *  entre o numero de funcionarios por supervisor. */
	bool despromove_supervisor_funcionorario(long id);

	/* Funcao que imprime todos os livros da Biblioteca.
	 * Retorno: string com o resultado da impressao. */
	std::string imprime_livros();

	/* Funcao que imprime os livros da Biblioteca com um determinado tema.
	 * Parametros: string tem - tema pretendido.
	 * Retorno: string com o resultado da impressao. */
	std::string imprime_livros_tema(std::string tem);

	/* Funcao que imprime todos os livros emprestados da Biblioteca.
	 * Retorno: string com o resultado da impressao. */
	std::string imprime_livros_emprestados();

	/* Funcao que imprime todos os livros disponiveis (nao emprestados) da Biblioteca.
	 * Retorno: string com o resultado da impressao. */
	std::string imprime_livros_disponiveis();

	/* Funcao que imprime todos os funcionarios da Biblioteca.
	 * Retorno: string com o resultado da impressao. */
	std::string imprime_funcionarios();

	/* Funcao que imprime todos os supervisores da Biblioteca.
	 * Retorno: string com o resultado da impressao. */
	std::string imprime_supervisores();

	/* Funcao que imprime todos os leitores da Biblioteca.
	 * Retorno: string com o resultado da impressao. */
	std::string imprime_leitores();

	/* Funcao que imprime todos os emprestimos da Biblioteca.
	 * Retorno: string com o resultado da impressao. */
	std::string imprime_emprestimos();

	/* Funcao que imprime todos os utilizadores da Biblioteca.
	 * Retorno: string com o resultado da impressao.
	 * Nota: nao imprime a password dos utilizadores. */
	std::string imprime_utilizadores();

	/* Funcao que imprime todos os livros, funcionarios, supervisores, leitores e emprestimos da Biblioteca.
	 * Retorno: string com o resultado da impressao. */
	std::string imprime();

	/* Funcao para obter todos os emprestimos atrasados da Biblioteca.
	 * Retorno: vector<Emprestimo*> com os apontadores para os emprestimos atrasados. */
	std::vector<Emprestimo*> get_emprestimos_atrasados();

	/* Funcao para imprimir os emprestimos atrasados por leitor para que os leitores posssam ser contactados.
	 * Retorno: string com o resultado da impressao. */
	std::string imprime_emprestimos_atrasados();

	/* Funcao para obter os livros da Biblioteca.
	 * Retorno: vector<Livro*> com os apontadores para os livros da biblioteca. */
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

	std::vector<Livro*> get_livros_tema(std::string tem);

	std::vector<Livro*> get_livros_disponiveis();

	std::vector<Livro*> get_livros_emprestados();

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
