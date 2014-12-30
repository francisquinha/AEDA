#ifndef SRC_LOGIN_H_
#define SRC_LOGIN_H_

#include <string>
#include <vector>
#include "Object.h"

class Object;

/** @file
 *
 * @brief Header das funcoes de Utilizador
 *
 * Se uma funcao relacionada com utilizadores nao estiver nos ficheiros biblio, esta aqui.
 **/

/**
 * @brief Classe com toda a informacao de Utilizador
 *
 * Para aceder ao sistema informatico da Biblioteca e necessario fornecer o ID e a password
 * de um utilizador. Nesse momento e determinado o nivel de acesso desse utilizador e mediante
 * esse nivel de acesso, sao determinadas as funcoes a que o utilizador tem acesso.
 * Os utilizadores devem corresponder aos funcionarios. Nao e obrigatorio que assim seja,
 * mas um utilizador que nao seja funcionario nao podera adicionar emprestimos.
 *
 * Os niveis de acesso sao:
 * 0 - Administrador - acesso a todas as funcoes;
 * 1 - Supervisor - nao pode adicionar, remover, promover e despromover funcionarios;
 * 2 - Funcionario - alem das restricoes do supervisor, nao pode adicionar nem remover livros.
 **/
class Utilizador: public Object {

	std::string password; /**< @brief password do utilizador **/

	int acesso; /**< @brief Tipo de acesso do utilizador: 0 - Administrador; 1 - Supervisor; 2 - Funcionario **/
public:

	/**
	 * @brief Construtor de Utilizador
	 *
	 * @param id codigo de identificacao do utilizadr
	 * @param pass password do utilizador
	 * @param acess nivel de acesso do utilizador
	 **/
	Utilizador(unsigned long id, std::string pass, int acess);

	/**
	 * @brief Funcao para obter a password do utilizador
	 *
	 * @return string com a password do utilizador
	 **/
	std::string get_password() const;

	/**
	 * @brief Funcao para determinar a password do utilizador
	 *
	 * @param pass password do utilizador
	 **/
	void set_password(std::string pass);

	/**
	 * @brief Funcao para obter o nivel de acesso do utilizador
	 *
	 * @return int com a nivel de acesso do utilizador
	 **/
	int get_acesso() const;

	/**
	 * @brief Funcao para determinar o nivel de acesso do utilizador
	 *
	 * @param acess nivel de acesso do utilizador
	 **/
	void set_acesso(int acess);

	/**
	 * @brief Funcao que escreve os atributos do utilizador
	 *
	 * @param ficheiro contem o caminho do ficheiro onde pretendemos escrever
	 **/
	void escreve(std::string ficheiro) const;

	/**
	 * @brief Funcao que imprime os atributos do utilizador exceto a password
	 *
	 * @return string contem o resultado da impressao
	 **/
	std::string imprime() const;

};

#endif // SRC_LOGIN_H_
