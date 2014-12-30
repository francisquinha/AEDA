#ifndef SRC_FUNCIONARIO_H_
#define SRC_FUNCIONARIO_H_

#include <vector>
#include "Object.h"

class Object;

/** @file
 *
 * @brief Header das funcoes de Funcionario.
 *
 * Se uma funcao relacionada com funcionarios nao estiver nos ficheiros biblio, esta aqui.
 **/

/**
 * @brief Classe com toda a informacao de Funcionario
 **/
class Funcionario: public Object {

	std::string nome; /**< @brief nome do funcionario **/
	static unsigned long num_funcionarios; /**< @brief contador de funcionarios na biblioteca **/

public:

	/**
	 * @brief Construtor de Funcionario
	 *
	 * @param id codigo de identificacao do funcionario
	 * @param nom nome do funcionario
	 * @param ct indica se devemos incrementar o contador de funcionarios
	 **/
	Funcionario(std::string nom, bool ct, unsigned long id = num_funcionarios + 1);

	/**
	 * @brief Destrutor virtual de Funcionario
	 **/
	virtual ~Funcionario() {};

	/**
	 * @brief Funcao que imprime os atributos do funcionario
	 *
	 * @return string com o resultado da impressao
	 **/
	virtual std::string imprime();

	/**
	 * @brief Funcao para obter o nome do funcionario
	 *
	 * @return string com o nome do funcionario
	 **/
	std::string get_nome() const;

	/**
	 * @brief Funcao que escreve os atributos do funcionario num ficheiro
	 *
	 * @param ficheiro caminho para o ficheiro onde pretendemos escrever
	 **/
	virtual void escreve(std::string ficheiro);

	/**
	 * @brief Funcao virtual para determinar os funcionarios supervisionados por um supervisor
	 *
	 * @param func_sup vetor com os apontadores para os funcionarios supervisionados
	 *
	 * Nota: Esta funcao nao faz nada, apenas esta declarada para que seja chamada a implementacao
	 * na classe supervisor.
	 **/
	virtual void set_func_sup(std::vector<Funcionario*> func_sup) {};

	/**
	 * @brief Funcao virtual para obter os funcionarios supervisionados por um supervisor
	 *
	 * @return vector<Funcionario*> com os apontadores para os funcionarios supervisionados
	 *
	 * Nota: Esta funcao retorna um vetor vazio e apenas esta declarada para que seja chamada
	 * a implementacao na classe supervisor
	 **/
	virtual std::vector<Funcionario*> get_func_sup() const{
		std::vector<Funcionario*> v {};
		return v;
	};

	/**
	 * @brief Funcao virtual para adicionar um funcionario aos os funcionarios supervisionados por um supervisor
	 *
	 * @param fc apontador para o funcionario que pretendemos adicionar
	 *
	 * Nota: Esta funcao nao faz nada, apenas esta declarada para que seja chamada a implementacao
	 * na classe supervisor.
	 **/
	virtual void adiciona_func_sup(Funcionario* fc) {};
};

#endif /* SRC_FUNCIONARIO_H_ */
