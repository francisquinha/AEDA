
#ifndef SRC_LEITOR_OLD_H_
#define SRC_LEITOR_OLD_H_

#include <ctime>
#include "Leitor.h"

class Leitor;

/** @file
 *
 * @brief Header das funcoes dos Leitor_old.
 *
 * Se uma funcao relacionada com leitores antigos nao estiver nos ficheiros biblio, esta aqui.
 **/

/**
 * @brief Classe com toda a informacao de Leitor antigo
 *
 * Na Biblioteca, os leitores antigos sao guardados no mesmo vetor dos leitores atuais.
 **/
class Leitor_old: public Leitor {

	std::time_t data_fim;

public:

	/**
	 * @brief Construtor de Leitor antigo
	 *
	 * @param id codigo de identificacao do leitor
	 * @param nom nome do leitor
	 * @param tel telefone do leitor
	 * @param eml email do leitor
	 * @param ep_lt vetor de apontadores para os emprestimos do leitor
	 * @param ct indica se devemos incrementar o contador de leitores
	 **/
	Leitor_old(long id, std::string nom, long tel, std::string eml, std::time_t dtf, bool ct);

	/**
	 * @brief Construtor de Leitor antigo
	 *
	 * @param id codigo de identificacao do leitor
	 * @param nom nome do leitor
	 * @param tel telefone do leitor
	 * @param eml email do leitor
	 * @param ep_lt vetor de apontadores para os emprestimos do leitor
	 * @param ct indica se devemos incrementar o contador de leitores
	 **/
	Leitor_old(long id, std::string nom, long tel, std::string eml, bool ct);

	/**
	 * @brief Funcao que imprime os atributos do leitor antigo
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime();

	/**
	 * @brief Funcao que escreve os atributos do leitor antigo num ficheiro
	 *
	 * @param ficheiro caminho para o ficheiro que pretendemos usar
	 **/
	void escreve(std::string ficheiro);
};

#endif /* SRC_LEITOR_OLD_H_ */
