
#ifndef SRC_EMPRESTIMO_OLD_H_
#define SRC_EMPRESTIMO_OLD_H_

#include "Emprestimo.h"
#include <ctime>

class Emprestimo;

/** @file
 *
 * @brief Header das funcoes de Emprestimo_old.
 *
 * Se uma funcao relacionada com emprestimos antigos nao estiver nos ficheiros biblio, esta aqui.
 **/

/**
 * @brief Classe com toda a informacao de Emprestimo_old
 *
 * Na Biblioteca, os emprestimos antigos sao guardados no mesmo vetor dos emprestimos atuais.
 **/
class Emprestimo_old: public Emprestimo {

	std::time_t data_entrega; /**< @brief data de fim do emprestimo **/

public:

	/**
	 * @brief Construtor de Emprestimo_old
	 *
	 * @param id codigo de identificacao do emprestimo
	 * @param lv apontador para o livro
	 * @param fc apontador para o funcionarios
	 * @param lt apontador para o leitor
	 * @param dt data de inicio emprestimo
	 * @param dt_e data de fim do emprestimo
	 **/
	Emprestimo_old(long id, Livro* lv, Funcionario* fc, Leitor* lt, std::time_t dt, std::time_t dt_e);

	/**
	 * @brief Construtor de Emprestimo_old
	 *
	 * @param id codigo de identificacao do emprestimo
	 * @param lv apontador para o livro
	 * @param fc apontador para o funcionarios
	 * @param lt apontador para o leitor
	 * @param dt data de inicio emprestimo
	 **/
	Emprestimo_old(long id, Livro* lv, Funcionario* fc, Leitor* lt, std::time_t dt);

	/**
	 * @brief Construtor de Emprestimo_old
	 *
	 * @param id codigo de identificacao do emprestimo
	 * @param lv apontador para o livro
	 * @param fc apontador para o funcionarios
	 * @param lt apontador para o leitor
	 * @param dt data de inicio emprestimo
	 * @param dt_e data de fim do emprestimo
	 * @param ct indica se devemos aumentar o contador de emprestimos da Biblioteca
	 **/
	Emprestimo_old(long id, Livro* lv, Funcionario* fc, Leitor* lt, std::time_t dt, std::time_t dt_e, bool ct);

	/**
	 * @brief Construtor de Emprestimo_old
	 *
	 * @param id codigo de identificacao do emprestimo
	 * @param lv apontador para o livro
	 * @param fc apontador para o funcionarios
	 * @param lt apontador para o leitor
	 * @param dt data de inicio emprestimo
	 * @param dt_e data de fim do emprestimo
	 * @param ct indica se devemos aumentar o contador de emprestimos da Biblioteca
	 **/
	Emprestimo_old(long id, Livro* lv, Funcionario* fc, Leitor* lt, std::time_t dt, bool ct);

	/**
	 * @brief Funcao que imprime os atributos do emprestimo antigo
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime();

	/**
	 * @brief Funcao que escreve os atributos do emprestimo antigo num ficheiro
	 *
	 * @param ficheiro contem o caminho do ficheiro onde pretendemos escrever
	 **/
	void escreve(std::string ficheiro);
};

#endif /* SRC_EMPRESTIMO_OLD_H_ */
