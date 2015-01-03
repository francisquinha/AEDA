
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

/** @file
 *
 * @brief Header das funcoes de Emprestimo.
 *
 * Se uma funcao relacionada com emprestimos nao estiver nos ficheiros biblio, esta aqui.
 **/

/**
 * @brief Classe com toda a informacao de Emprestimo
 **/
class Emprestimo: public Object {

	Livro* livro; /**< @brief apontador para o livro do emprestimo **/
    unsigned long indice;  /**< @brief indice do exemplar do livro do emprestimo **/
	Funcionario* funcionario; /**< @brief apontador para o funcionario que fez o emprestimo **/
	Leitor* leitor; /**< @brief apontador para o leitor do emprestimo **/
	std::time_t data; /**< @brief data do emprestimo **/
	static unsigned long num_emprestimos; /**< @brief contador de emprestimos na biblioteca (atuais e antigos) **/

public:

	/**
	 * @brief Construtor de Emprestimo
	 *
	 * @param lv apontador para o livro
     * @param ind indice do exemplar do livro
	 * @param fc apontador para o funcionario
	 * @param lt apontador para o leitor
	 * @param ct indica se devemos incrementar o contador de emprestimos
     * @param dt data do emprestimo
     * @param id codigo de identificacao do emprestimo
	 **/
	Emprestimo(Livro* lv, unsigned long ind, Funcionario* fc, Leitor* lt, bool ct,
               std::time_t dt = time (0), unsigned long id = num_emprestimos + 1);

	/**
	 * @brief Destrutor virtual de Emprestimo
	 **/
	virtual ~Emprestimo() {};

	/**
	 * @brief Funcao para obter o livro do emprestimo
	 *
	 * @return apontador para o livro
	 **/
	Livro* get_livro() const;

    /**
     * @brief Funcao para obter o indice do exemplar do livro do emprestimo
     *
     * @return unsigned long com o indice do exemplar do livro
     **/
    unsigned long get_indice() const;

	/**
	 * @brief Funcao para obter o funcionario responsavel pelo emprestimo
	 *
	 * @return apontador para o funcionario
	 **/
	Funcionario* get_funcionario() const;

	/**
	 * @brief Funcao para obter o leitor a quem e feito o emprestimo
	 *
	 * @return apontador para o leitor
	 **/
	Leitor* get_leitor() const;

	/**
	 * @brief Funcao para obter a data do emprestimo
	 *
	 * @return data do emprestimo
	 **/
	std::time_t get_data() const;

	/**
	 * @brief Funcao que determina o numero de dias de atraso do emprestimo
	 *
	 * @return numero de dias de atraso (numero de dias depois dos 7 permitidos)
	 **/
	int get_atraso() const;

	/**
	 * @brief Funcao que determina o valor da multa do emprestimo
	 *
	 * @return valor da multa.
	 **/
	double get_multa() const;

	/**
	 * @brief Funcao que imprime os atributos do emprestimo
	 *
	 * @return string com o resultado da impressao
	 **/
	virtual std::string imprime() const;

	/**
	 * @brief Funcao que escreve os atributos do emprestimo num ficheiro
	 *
	 * @param ficheiro contem o caminho do ficheiro onde pretendemos escrever
	 **/
	virtual void escreve(const std::string ficheiro) const;

};

#endif /* SRC_EMPRESTIMO_H_ */
