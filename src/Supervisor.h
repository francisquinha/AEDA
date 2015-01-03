
#ifndef SRC_SUPERVISOR_H_
#define SRC_SUPERVISOR_H_

#include "Funcionario.h"

class Funcionario;

/** @file
 *
 * @brief Header das funcoes de Supervisor.
 *
 * As funcoes relacionadas com supervisores, nao estando nos ficheiros Biblio ou Funcionario, estao aqui.
 **/

/**
 * @brief Classe com toda a informacao de Supervisor
 **/
class Supervisor: public Funcionario {

	std::vector<Funcionario*> funcionarios_sup; /**< @brief vetor com os apontadores para os funcionarios supervisionados **/

public:

    /**
	 * @brief Construtor de Supervisor
	 *
	 * @param id codigo de identificacao do supervisor
	 * @param nom nome do supervisor
	 * @param func_sup vetor com os apontadores para os funcionarios supervisionados
	 * @param ct indica se devemos incrementar o numero de funcionarios
	 **/
	Supervisor(unsigned long id, std::string nom, std::vector<Funcionario*> func_sup, bool ct);

	/**
	 * @brief Funcao para adicionar um funcionario aos supervisionados
	 *
	 * @param fc apontador para o funcionario que pretendemos adicionar
	 **/
	void adiciona_func_sup(Funcionario* fc);

	/**
	 * @brief Funcao para determinar os funcionarios supervisionados
	 *
	 * @param func_sup vetor de apontadores para os funcionarios supervisionados
	 **/
	void set_func_sup(std::vector<Funcionario*> func_sup);

	/**
	 * @brief Funcao para obter os funcionarios supervisionados
	 *
	 * @return vetor de apontadores para os funcionarios supervisionados
	 **/
	std::vector<Funcionario*> get_func_sup() const;

	/**
	 * @brief Funcao que imprime os atributor de supervisor
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime() const;

	/**
	 * @brief Funcao que escreve os atributor de supervisor num ficheiro
	 *
	 * @param ficheiro contem o caminho para o ficheiro onde queremos escrever
	 **/
	void escreve(const std::string ficheiro) const;
};

#endif /* SRC_SUPERVISOR_H_ */
