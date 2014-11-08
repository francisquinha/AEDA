
#ifndef SRC_FUNCIONARIO_OLD_H_
#define SRC_FUNCIONARIO_OLD_H_

#include <vector>

#include "Funcionario.h"

class Funcionario;

/**
 * @brief Classe com toda a informacao de Funcionario antigo
 **/
class Funcionario_old: public Funcionario {

	std::time_t data_fim;

public:

	/**
	 * @brief Construtor de Funcionario antigo
	 *
	 * @param id codigo de identificacao do funcionario
	 * @param nom nome do funcionario
	 * @param dtf data em que foi removido o funcionario
	 * @param ct indica se devemos incrementar o contador de funcionarios
	 **/
	Funcionario_old(long id, std::string nom, std::time_t dtf, bool ct);

	/**
	 * @brief Construtor de Funcionario antigo
	 *
	 * @param id codigo de identificacao do funcionario
	 * @param nom nome do funcionario
	 * @param ct indica se devemos incrementar o contador de funcionarios
	 **/
	Funcionario_old(long id, std::string nom, bool ct);

	/**
	 * @brief Funcao que imprime os atributos do funcionario antigo
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime();

	/**
	 * @brief Funcao que escreve os atributos do funcionario antigo num ficheiro
	 *
	 * @param ficheiro caminho para o ficheiro onde pretendemos escrever
	 **/
	void escreve(std::string ficheiro);

};


#endif /* SRC_FUNCIONARIO_OLD_H_ */
