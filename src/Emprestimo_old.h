
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
	Emprestimo_old(Livro* lv, Funcionario* fc, Leitor* lt, bool ct,
                   std::time_t dt, unsigned long id, std::time_t dt_e = time(0));

	/**
	 * @brief Funcao que imprime os atributos do emprestimo antigo
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime() const;

	/**
	 * @brief Funcao que escreve os atributos do emprestimo antigo num ficheiro
	 *
	 * @param ficheiro contem o caminho do ficheiro onde pretendemos escrever
	 **/
	void escreve(const std::string ficheiro) const;
};

#endif /* SRC_EMPRESTIMO_OLD_H_ */
