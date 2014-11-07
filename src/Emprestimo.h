
#ifndef SRC_EMPRESTIMO_H_
#define SRC_EMPRESTIMO_H_

#include "Livro.h"
#include "Funcionario.h"
#include "Leitor.h"
#include "Object.h"
#include <ctime>

class Livro;
class Funcionario;
class Leitor;
class Object;

/**
 * @brief Classe com toda a informacao de Emprestimo
 **/
class Emprestimo: public Object {

	Livro* livro; /**< @brief apontador para o livro do emprestimo **/
	Funcionario* funcionario; /**< @brief apontador para o funcionario que fez o emprestimo **/
	Leitor* leitor; /**< @brief apontador para o leitor do emprestimo **/
	std::time_t data; /**< @brief data do emprestimo **/
	static long num_emprestimos; /**< @brief contador de emprestimos na biblioteca (atuais e antigos) **/

public:

	/**
	 * @brief Construtor de Emprestimo
	 *
	 * @param id codigo de identificacao do emprestimo
	 * @param lv apontador para o livro
	 * @param fc apontador para o funcionarios
	 * @param lt apontador para o leitor
	 * @param dt data do emprestimo
	 * @param ct indica se devemos incrementar o contador de emprestimos
	 **/
	Emprestimo(long id, Livro* lv, Funcionario* fc, Leitor* lt, std::time_t dt, bool ct);

	/**
	 * @brief Construtor de Emprestimo
	 *
	 * @param id codigo de identificacao do emprestimo
	 * @param lv apontador para o livro
	 * @param fc apontador para o funcionarios
	 * @param lt apontador para o leitor
	 * @param dt data do emprestimo
	 **/
	Emprestimo(long id, Livro* lv, Funcionario* fc, Leitor* lt, std::time_t dt);

	/**
	 * @brief Construtor de Emprestimo
	 *
	 * @param id codigo de identificacao do emprestimo
	 * @param lv apontador para o livro
	 * @param fc apontador para o funcionarios
	 * @param lt apontador para o leitor
	 **/
	Emprestimo(long id, Livro* lv, Funcionario* fc, Leitor* lt);

	/**
	 * @brief Construtor de Emprestimo
	 *
	 * @param lv apontador para o livro
	 * @param fc apontador para o funcionarios
	 * @param lt apontador para o leitor
	 **/
	Emprestimo(Livro* lv, Funcionario* fc, Leitor* lt);

	/**
	 * @brief Construtor de Emprestimo
	 *
	 * @param lv apontador para o livro
	 * @param fc apontador para o funcionarios
	 * @param lt apontador para o leitor
	 * @param dt data do emprestimo
	 **/
	Emprestimo(Livro* lv, Funcionario* fc, Leitor* lt, std::time_t dt);

	/**
	 * @brief Destrutor virtual de Emprestimo
	 **/
	virtual ~Emprestimo() {};

	/**
	 * @brief Funcao para obter o livro do emprestimo
	 *
	 * @return apontador para o livro
	 **/
	Livro* get_livro();

	/**
	 * @brief Funcao para obter o funcionario responsavel pelo emprestimo
	 *
	 * @return apontador para o funcionario
	 **/
	Funcionario* get_funcionario();

	/**
	 * @brief Funcao para obter o leitor a quem e feito o emprestimo
	 *
	 * @return apontador para o leitor
	 **/
	Leitor* get_leitor();

	/**
	 * @brief Funcao para obter a data do emprestimo
	 *
	 * @return data do emprestimo
	 **/
	std::time_t get_data();

	/**
	 * @brief Funcao que determina o numero de dias de atraso do emprestimo
	 *
	 * @return numero de dias de atraso (numero de dias depois dos 7 permitidos)
	 **/
	int get_atraso();

	/**
	 * @brief Funcao que determina o valor da multa do emprestimo
	 *
	 * @return valor da multa.
	 **/
	double get_multa();

	/**
	 * @brief Funcao que imprime os atributos do emprestimo
	 *
	 * @return string com o resultado da impressao
	 **/
	virtual std::string imprime();

	/**
	 * @brief Funcao que escreve os atributos do emprestimo num ficheiro
	 *
	 * @param ficheiro contem o caminho do ficheiro onde pretendemos escrever
	 **/
	virtual void escreve(std::string ficheiro, std::string ficheiro_old);

};

#endif /* SRC_EMPRESTIMO_H_ */
