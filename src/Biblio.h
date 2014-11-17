#ifndef SRC_BIBLIOTECA_H_
#define SRC_BIBLIOTECA_H_

#include "Administrador.h"
#include "Supervisor.h"
#include "Emprestimo_old.h"
#include "Funcionario_old.h"
#include "Livro_old.h"
#include "Leitor_old.h"
#include "Login.h"
#include "Excecao.h"

class Livro_old;
class Leitor_old;
class Supervisor;
class Emprestimo_old;
class Utilizadores;
class Login;

/** @file
 *
 * @brief Header das funcoes da Biblioteca.
 *
 * Apos os menus, estas sao as funcoes chamadas pelas varias opcoes da aplicacao.
 **/

/**
 * @brief Classe com a informacao da Biblioteca.
 *
 *	E composta por livros, funcionarios (normais, supervisores ou administrador), leitores, emprestimos e utilizadores.
 *	A excecao dos utilizadores, e guardado historico de todos estes objetos em objetos do tipo _old (subclasses da respetiva
 *	classe). Por exemplo, um leitor removido nao desaparece, e guardado como leitor_old com a data em que foi removido. *
 **/
class Biblioteca {

	std::vector<Livro*> livros; /**< @brief vetor com apontadores para os livros da Biblioteca **/
	std::vector<Funcionario*> funcionarios; /**< @brief vetor com apontadores para os funcionarios da Biblioteca **/
	std::vector<Leitor*> leitores; /**< @brief vetor com apontadores para os leitores da Biblioteca **/
	std::vector<Emprestimo*> emprestimos; /**< @brief vetor com apontadores para os emprestimos da Biblioteca **/
	std::vector<Utilizador*> utilizadores; /**< @brief vetor com apontadores para os utilizadores da Biblioteca **/

public:

	/**
	 * @brief Construtor de Biblioteca
	 **/
	Biblioteca() {};

	/**
	 * @brief Funcao para obter todos os emprestimos atrasados da Biblioteca
	 *
	 * @return vector<Emprestimo*> com os apontadores para os emprestimos atrasados

	 **/
	std::vector<Emprestimo*> get_emprestimos_atrasados();

	/**
	 * @brief Funcao que imprime os emprestimos atrasados por leitor para que os leitores posssam ser contactados
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime_emprestimos_atrasados();

	/**
	 * @brief Funcao para obter os livros antigos da Biblioteca
	 *
	 * @return vector<Livro_old*> com os apontadores para os livros antigos da biblioteca
	 **/
	std::vector<Livro_old*> get_livros_old();

	/**
	 * @brief Funcao para obter os livros da Biblioteca
	 *
	 * @return vector<Livro*> com os apontadores para os livros da biblioteca
	 **/
	std::vector<Livro*> get_livros();

	/**
	 * @brief Funcao para obter os emprestimos antigos da Biblioteca
	 *
	 * @return vector<Emprestimo_old*> com os apontadores para os emprestimos antigos
	 **/
	std::vector<Emprestimo_old*> get_emprestimos_old();

	/**
	 * @brief Funcao para obter os emprestimos atuais da Biblioteca
	 *
	 * @return vector<Emprestimo*> com os apontadores para os emprestimos atuais
	 **/
	std::vector<Emprestimo*> get_emprestimos();

	/**
	 * @brief Funcao para obter os funcionarios antigos da Biblioteca
	 *
	 * @return vector<Fucionario_old*> com os apontadores para os funcionarios antigos
	 **/
	std::vector<Funcionario_old*> get_funcionarios_old();

	/**
	 * @brief Funcao para obter os funcionarios da Biblioteca
	 *
	 * @return vector<Fucionario*> com os apontadores para os funcionarios
	 **/
	std::vector<Funcionario*> get_funcionarios_todos();

	/**
	 * @brief Funcao para obter os supervisores da Biblioteca
	 *
	 * @return vector<Funcionario*> com os apontadores para os supervisores
	 **/
	std::vector<Funcionario*> get_supervisores();

	/**
	 * @brief Funcao para obter os funcionarios nao supervisores da Biblioteca
	 *
	 * @return vector<Funcionario*> com os apontadores para os funcionarios nao supervisores da biblioteca
	 **/
	std::vector<Funcionario*> get_funcionarios();

	/**
	 * @brief Funcao para obter os leitores antigos da Biblioteca
	 *
	 * @return vector<Leitor_old*> com os apontadores para os leitores antigos da biblioteca
	 **/
	std::vector<Leitor_old*> get_leitores_old();

	/**
	 * @brief Funcao para obter os leitores da Biblioteca
	 *
	 * @return vector<Leitor*> com os apontadores para os leitores da biblioteca
	 **/
	std::vector<Leitor*> get_leitores();

	/**
	 * @brief Funcao para obter os utilizadores da Biblioteca
	 *
	 * @return vector<Utilizador*> com os apontadores para os utilizadores da biblioteca
	 **/
	std::vector<Utilizador*> get_utilizadores();

	/**
	 * @brief Funcao para adicionar um livro antigo a Biblioteca
	 *
	 * @param lv apontador para o livro antigo
	 **/
	void adiciona_livro_old(Livro_old* lv);

	/**
	 * @brief Funcao para adicionar um novo livro a Biblioteca
	 *
	 * @param lv apontador para o novo livro
	 **/
	void adiciona_livro(Livro* lv);

	/**
	 * @brief Funcao para adicionar um funcionario antigo a Biblioteca
	 *
	 * @param fc apontador para o funcionario antigo
	 **/
	void adiciona_funcionario_old(Funcionario_old* fc);

	/**
	 * @brief Funcao para adicionar um novo funcionario a Biblioteca
	 *
	 * @param fc apontador para o novo funcionario
	 **/
	void adiciona_funcionario(Funcionario* fc);

	/**
	 * @brief Funcao para adicionar um leitor antigo a Biblioteca
	 *
	 * @param lt apontador para o leitor antigo
	 **/
	void adiciona_leitor_old(Leitor_old* lt);

	/**
	 * @brief Funcao para adicionar um novo leitor a Biblioteca
	 *
	 * @param lt apontador para o novo leitor
	 **/
	void adiciona_leitor(Leitor* lt);

	/**
	 * @brief Funcao para adicionar um emprestimo antigo a Biblioteca
	 *
	 * @param ep apontador para o emprestimo antigo
	 **/
	void adiciona_emprestimo_old(Emprestimo_old* ep);

	/**
	 * @brief Funcao para adicionar um novo emprestimo a Biblioteca
	 *
	 * @param ep apontador para o novo emprestimo
	 **/
	void adiciona_emprestimo(Emprestimo* ep);

	/**
	 * @brief Funcao para adicionar um novo emprestimo a Biblioteca
	 *
	 * @param id_lv identificacao do livro do emprestimo
	 * @param id_lt identificacao do leitor do emprestimo
	 * @param id_fc identificacao do funcionario do emprestimo
	 **/
	void adiciona_emprestimo_ids(long id_lv, long id_lt, long id_fc);

	/**
	 * @brief Funcao para adicionar um novo utilizador a Biblioteca
	 *
	 * @param ut apontador para o novo utilizador
	 **/
	void adiciona_utilizador(Utilizador* ut);

	/**
	 * @brief Funcao para remover um livro da Biblioteca
	 *
	 * @param id identificacao do livro que queremos remover
	 *
	 * @return true se existe algum livro com o id fornecido
	 *
	 * @exception Object_nao_existe se nao existe nenhum livro com o id fornecido
	 *
	 * Nota: remove o primeiro livro com o id indicado.
	 **/
	bool remove_livro(long id);

	/**
	 * @brief Funcao para remover um funcionario da Biblioteca
	 *
	 * @param lond id identificacao do funcionario que queremos remover
	 *
	 * @return true se existe algum funcionario com o id fornecido
	 *
	 * @exception Object_nao_existe se nao existe nenhum funcionario com o id fornecido
	 *
	 * Nota: remove o primeiro funcionario com o id indicado.
	 **/
	bool remove_funcionario(long id);

	/**
	 * @brief Funcao para remover um leitor da Biblioteca
	 *
	 * @param lond id identificacao do leitor que queremos remover
	 *
	 * @return true se existe algum leitor com o id fornecido
	 *
	 * @exception Object_nao_existe se nao existe nenhum leitor com o id fornecido
	 *
	 * Nota: remove o primeiro leitor com o id indicado.
	 **/
	bool remove_leitor(long id);

	/**
	 * @brief Funcao para remover um emprestimo da Biblioteca
	 *
	 * @param lond id identificacao do emprestimo que queremos remover
	 *
	 * @return true se existe algum emprestimo com o id fornecido
	 *
	 * @exception Object_nao_existe se nao existe nenhum emprestimo com o id fornecido
	 *
	 * Nota: remove o primeiro emprestimo com o id indicado.
	 **/
	bool remove_emprestimo(long id);

	/**
	 * @brief Funcao para remover um utilizador da Biblioteca
	 *
	 * @param lond id identificacao do utilizador que queremos remover
	 *
	 * @return true se existe algum utilizador com o id fornecido
	 *
	 * @exception Object_nao_existe se nao existe nenhum utilizador com o id fornecido
	 *
	 * Nota: remove o primeiro utilizador com o id indicado.
	 **/
	bool remove_utilizador(long id);

	/**
	 * @brief Funcao para distribuir uniformemente os funcionarios pelos supervisores
	 *
	 * No final o numero de funcionarios por supervisor e o mais equilibrado possivel.
	 **/
	void distribui_funcionarios();

	/**
	 * @brief Funcao para promover um funcionario a supervisor
	 *
	 * @param long id identificacao do funcionario que pretendemos promover
	 *
	 * @return true se existe um funcionario com o id fornecido
	 *
	 * @exception Object_nao_existe se nao existe nenhum funcionario com o id fornecido
	 *
	 * Notas: - promove o primeiro funcionario com o id indicado;
	 * 		  - no final os funcionarios sao redistribuidos, pelo que se mantem o equlibrio
	 *  	  	 entre o numero de funcionarios por supervisor.
	 **/
	bool promove_funcionario_supervisor(long id);

	/**
	 * @brief Funcao para despromover um supervisor a funcionario
	 *
	 * @param long id identificacao do supervisor que pretendemos despromover
	 *
	 * @return true se existe um supervisor com o id fornecido
	 *
	 * @exception Object_nao_existe se nao existe nenhum supervisor com o id fornecido
	 *
	 * Notas: - despromove o primeiro supervisor com o id indicado;
	 * 		   - no final os funcionarios sao redistribuidos, pelo que se mantem o equlibrio
	 *  		 entre o numero de funcionarios por supervisor.
	 **/
	bool despromove_supervisor_funcionorario(long id);

	/**
	 * @brief Funcao que imprime todos os livros antigos da Biblioteca
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime_livros_old();

	/**
	 * @brief Funcao que imprime todos os livros da Biblioteca
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime_livros();

	/**
	 * @brief Funcao que imprime os livros da Biblioteca com um determinado tema
	 *
	 * @param tem tema pretendido
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime_livros_tema(std::string tem);

	/**
	 * @brief Funcao que imprime todos os livros emprestados da Biblioteca
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime_livros_emprestados();

	/**
	 * @brief Funcao que imprime todos os livros disponiveis (nao emprestados) da Biblioteca
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime_livros_disponiveis();

	/**
	 * @brief Funcao que imprime todos os funcionarios antigos da Biblioteca
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime_funcionarios_old();

	/**
	 * @brief Funcao que imprime todos os funcionarios da Biblioteca
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime_funcionarios();

	/**
	 * @brief Funcao que imprime todos os supervisores da Biblioteca
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime_supervisores();

	/**
	 * @brief Funcao que imprime todos os leitores antigos da Biblioteca
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime_leitores_old();

	/**
	 * @brief Funcao que imprime todos os leitores da Biblioteca
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime_leitores();

	/**
	 * @brief Funcao que imprime todos os emprestimos antigos da Biblioteca
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime_emprestimos_old();

	/**
	 * @brief Funcao que imprime todos os emprestimos da Biblioteca
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime_emprestimos();

	/**
	 * @brief Funcao que imprime todos os utilizadores da Biblioteca
	 *
	 * @return string com o resultado da impressao
	 *
	 * Nota: nao imprime a password dos utilizadores
	 **/
	std::string imprime_utilizadores();

	/**
	 * @brief Funcao que imprime todos os livros, funcionarios, supervisores, leitores e emprestimos da Biblioteca
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime();

	/* codigo desnecessario

	void set_emprestimos(std::vector<Emprestimo*> emp);

	void set_funcionarios(std::vector<Funcionario*> func);

	void set_leitores(std::vector<Leitor*> leit);

	void set_utilizadores(std::vector<Utilizador*> util);

	void set_livros(std::vector<Livro*> livr);

	**/

	/**
	 * @brief Funcao para obter os temas dos livros da Biblioteca
	 *
	 * @return vector<string> com os temas dos livros da Biblioteca
	 **/
	std::vector<std::string> get_temas();

	/**
	 * @brief Funcao para obter os livros com um determinado tema da Biblioteca
	 *
	 * @param tem tema escolhido.
	 *
	 * @return vector<Livro*> com os apontadores para os livros com tema tem
	 **/
	std::vector<Livro*> get_livros_tema(std::string tem);

	/**
	 * @brief Funcao para obter os livros disponiveis (nao emprestados) da Biblioteca
	 *
	 * @return vector<Livro*> com os apontadores para os livros disponiveis
	 **/
	std::vector<Livro*> get_livros_disponiveis();

	/**
	 * @brief Funcao para obter os livros emprestados da Biblioteca
	 *
	 * @return vector<Livro*> com os apontadores para os livros emprestados
	 **/
	std::vector<Livro*> get_livros_emprestados();

	/**
	 * @brief Funcao que escreve todos os livros antigos da Biblioteca para um ficheiro
	 *
	 * @param ficheiro contem o caminho para o ficheiro onde queremos escrever
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void escreve_livros_old(std::string ficheiro);

	/**
	 * @brief Funcao que escreve todos os livros da Biblioteca para um ficheiro
	 *
	 * @param ficheiro contem o caminho para o ficheiro onde queremos escrever
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void escreve_livros(std::string ficheiro);

	/**
	 * @brief Funcao que escreve os funcionarios antigos da Biblioteca para um ficheiro
	 *
	 * @param ficheiro contem o caminho para o ficheiro onde queremos escrever
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void escreve_funcionarios_old(std::string ficheiro);

	/**
	 * @brief Funcao que escreve os funcionarios da Biblioteca
	 *
	 * @param ficheiro contem o caminho para o ficheiro onde queremos escrever
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void escreve_funcionarios(std::string ficheiro);

	/**
	 * @brief Funcao que escreve os supervisores da Biblioteca
	 *
	 * @param ficheiro contem o caminho para o ficheiro onde queremos escrever
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void escreve_supervisores(std::string ficheiro);

	/**
	 * @brief Funcao que escreve todos os leitores antigos da Biblioteca para um ficheiro
	 *
	 * @param string ficheiro contem o caminho para o ficheiro onde queremos escrever
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void escreve_leitores_old(std::string ficheiro);

	/**
	 * @brief Funcao que escreve todos os leitores da Biblioteca para um ficheiro
	 *
	 * @param string ficheiro contem o caminho para o ficheiro onde queremos escrever
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void escreve_leitores(std::string ficheiro);

	/**
	 * @brief Funcao que escreve todos os emprestimos antigos da Biblioteca para um ficheiro
	 *
	 * @param ficheiro contem o caminho para o ficheiro onde queremos escrever
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void escreve_emprestimos_old(std::string ficheiro);

	/**
	 * @brief Funcao que escreve todos os emprestimos da Biblioteca para um ficheiro
	 *
	 * @param ficheiro contem o caminho para o ficheiro onde queremos escrever
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void escreve_emprestimos(std::string ficheiro);

	/**
	 * @brief Funcao que escreve todos os utilizadores da Biblioteca para um ficheiro
	 *
	 * @param ficheiro contem o caminho para o ficheiro onde queremos escrever
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void escreve_utilizadores(std::string ficheiro);

	/**
	 * @brief Funcao que escreve toda a informacao da Biblioteca para 6 ficheiros
	 *
	 * @param ficheiro_lvo contem o caminho para o ficheiro onde queremos escrever os livros antigos
	 * @param ficheiro_lv contem o caminho para o ficheiro onde queremos escrever os livros
	 * @param ficheiro_fco contem o caminho para o ficheiro onde queremos escrever os funcionarios antigos
	 * @param ficheiro_fc contem o caminho para o ficheiro onde queremos escrever os funcionarios
	 * @param ficheiro_sp contem o caminho para o ficheiro onde queremos escrever os supervisores
	 * @param ficheiro_lto contem o caminho para o ficheiro onde queremos escrever os leitores antigos
	 * @param ficheiro_lt contem o caminho para o ficheiro onde queremos escrever os leitores
	 * @param ficheiro_epo contem o caminho para o ficheiro onde queremos escrever os emprestimos antigos
	 * @param ficheiro_ep contem o caminho para o ficheiro onde queremos escrever os emprestimos
	 * @param ficheiro_ut contem o caminho para o ficheiro onde queremos escrever os utilizadores
	 *
	 * @exception Ficheiro_indisponivel se algum ficheiro nao existir
	 **/
	void escreve(std::string ficheiro_lvo, std::string ficheiro_lv, std::string ficheiro_fco, std::string ficheiro_fc,
			std::string ficheiro_sp, std::string ficheiro_lto, std::string ficheiro_lt, std::string ficheiro_epo,
			std::string ficheiro_ep, std::string ficheiro_ut);

	/**
	 * @brief Funcao que le todos os livros antigos de um ficheiro e os adiciona a Biblioteca
	 *
	 * @param ficheiro contem o caminho para o ficheiro de onde queremos ler
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void le_livros_old(std::string ficheiro);

	/**
	 * @brief Funcao que le todos os livros de um ficheiro e os adiciona a Biblioteca
	 *
	 * @param ficheiro contem o caminho para o ficheiro de onde queremos ler
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void le_livros(std::string ficheiro);

	/**
	 * @brief Funcao que le os funcionarios antigos de um ficheiro e os adiciona a Biblioteca
	 *
	 * @param ficheiro contem o caminho para o ficheiro de onde queremos ler
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void le_funcionarios_old(std::string ficheiro);

	/**
	 * @brief Funcao que le os funcionarios de um ficheiro e os adiciona a Biblioteca
	 *
	 * @param ficheiro contem o caminho para o ficheiro de onde queremos ler
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void le_funcionarios(std::string ficheiro);

	/**
	 * @brief Funcao que le os supervisores de um ficheiro e os adiciona a Biblioteca
	 *
	 * @param ficheiro contem o caminho para o ficheiro de onde queremos ler
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void le_supervisores(std::string ficheiro);

	/**
	 * @brief Funcao que le todos os leitores antigos de um ficheiro e os adiciona a Biblioteca
	 *
	 * @param ficheiro contem o caminho para o ficheiro de onde queremos ler
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void le_leitores_old(std::string ficheiro);

	/**
	 * @brief Funcao que le todos os leitores de um ficheiro e os adiciona a Biblioteca
	 *
	 * @param ficheiro contem o caminho para o ficheiro de onde queremos ler
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void le_leitores(std::string ficheiro);

	/**
	 * @brief Funcao que le todos os emprestimos antigos de um ficheiro e os adiciona a Biblioteca
	 *
	 * @param ficheiro contem o caminho para o ficheiro de onde queremos ler
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void le_emprestimos_old(std::string ficheiro);

	/**
	 * @brief Funcao que le todos os emprestimos de um ficheiro e os adiciona a Biblioteca
	 *
	 * @param ficheiro contem o caminho para o ficheiro de onde queremos ler
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 *
	 * Nota: E atualizada a informacao sobre emprestimos nos leitores e nos livros.
	 **/
	void le_emprestimos(std::string ficheiro);

	/**
	 * @brief Funcao que le todos os utilizadores de um ficheiro e os adiciona a Biblioteca
	 *
	 * @param string ficheiro contem o caminho para o ficheiro de onde queremos ler
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void le_utilizadores(std::string ficheiro);

	/**
	 * @brief Funcao que le toda a informacao de 6 ficheiros e adiciona a Biblioteca
	 *
	 * @param ficheiro_lvo contem o caminho para o ficheiro onde queremos ler os livros antigos
	 * @param ficheiro_lv contem o caminho para o ficheiro onde queremos ler os livros
	 * @param ficheiro_fco contem o caminho para o ficheiro onde queremos ler os funcionarios antigos
	 * @param ficheiro_fc contem o caminho para o ficheiro onde queremos ler os funcionarios
	 * @param ficheiro_sp contem o caminho para o ficheiro onde queremos ler os supervisores
	 * @param ficheiro_lto contem o caminho para o ficheiro onde queremos ler os leitores antigos
	 * @param ficheiro_lt contem o caminho para o ficheiro onde queremos ler os leitores
	 * @param ficheiro_epo contem o caminho para o ficheiro onde queremos ler os emprestimos antigos
	 * @param ficheiro_ep contem o caminho para o ficheiro onde queremos ler os emprestimos
	 * @param ficheiro_ut contem o caminho para o ficheiro onde queremos ler os utilizadores
	 *
	 * @exception Ficheiro_indisponivel se algum ficheiro nao existir
	 **/
	void le(std::string ficheiro_lvo, std::string ficheiro_lv, std::string ficheiro_fco, std::string ficheiro_fc,
			std::string ficheiro_sp, std::string ficheiro_lto, std::string ficheiro_lt, std::string ficheiro_epo,
			std::string ficheiro_ep, std::string ficheiro_ut);
};

#endif /* SRC_BIBLIOTECA_H_ */
