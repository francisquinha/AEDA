
#ifndef SRC_LIVRO_H_
#define SRC_LIVRO_H_

#include <ctime>
#include "Object.h"

class Object;

/** @file
 *
 * @brief Header das funcoes de Livro.
 *
 * Se uma funcao relacionada com livros antigos nao estiver nos ficheiros biblio, esta aqui.
 **/

/**
 * @brief Classe com toda a informacao de Livro
 **/
class Livro: public Object {

	std::string titulo; /**< @brief titulo do livro **/
	std::vector<std::string> autores;  /**< @brief vetor com os nomes dos autores do livro **/
	std::string tema; /**< @brief tema do livro **/
	long ISBN; /**< @brief ISBN do livro **/
	std::string cota; /**< @brief cota do livro na biblioteca **/
	int num_paginas; /**< @brief numero de paginas do livro **/
	int edicao; /**< @brief edicao do livro **/
	bool emprestado; /**< @brief true se o livro esta emprestado, false caso contrario **/
	long ID_ep; /**< @brief identificacao do emprestimo do livro, se existir **/
	std::time_t data_emp; /**< @brief data do emprestimo do livro, se existir **/
	static long num_livros; /**< @brief contador de livros na biblioteca **/

public:

	/**
	 * @brief Construtor de Livro
	 *
	 * @param id codigo de identificacao do livro
	 * @param tit titulo do livro
	 * @param aut vetor com os nomes dos autores
	 * @param tem tema do livro
	 * @param isbn ISBN do livro
	 * @param cot cota do livro na biblioteca
	 * @param np numero de paginas do livro
	 * @param ed numero da edicao do livro
	 * @param ept indica se o livro esta emprestado (sempre false)
	 * @param id_ep ID do emprestimo do livro (sempre 0)
	 * @param dt data de emprestimo do livro (sempre 0)
	 * @param ct indica se devemos incrementar o contador de livros
	 **/
	Livro(long id, std::string tit, std::vector<std::string> aut, std::string tem, long isbn, std::string cot,
			int np, int ed, bool ept, long id_ep, std::time_t dt, bool ct);

	/**
	 * @brief Construtor de Livro
	 *
	 * @param tit titulo do livro
	 * @param aut vetor com os nomes dos autores
	 * @param tem tema do livro
	 * @param isbn ISBN do livro
	 * @param cot cota do livro na biblioteca
	 * @param np numero de paginas do livro
	 * @param ed numero da edicao do livro
	 * @param ept indica se o livro esta emprestado (sempre false)
	 * @param id_ep ID do emprestimo do livro (sempre 0)
	 * @param dt data de emprestimo do livro (sempre 0)
	 * @param ct indica se devemos incrementar o contador de livros
	 **/
	Livro(std::string tit, std::vector<std::string> aut, std::string tem, long isbn, std::string cot,
			int np, int ed, bool ept, long id_ep, std::time_t dt, bool ct);

	/**
	 * @brief Destrutor virtual de Livro
	 **/
	virtual ~Livro() {};

	/**
	 * @brief Funcao que imprime os atributos do livro
	 *
	 * @return string com o resultado da impressao
	 **/
	virtual std::string imprime();

	/**
	 * @brief Funcao para obter o titulo do livro
	 *
	 * @return string com o titulo do livro
	 **/
	std::string get_titulo();

	/**
	 * @brief Funcao para obter os autores do livro
	 *
	 * @return vector<string> com os nomes dos autores do livro
	 **/
	std::vector<std::string> get_autores();

	/**
	 * @brief Funcao para obter o tema do livro
	 *
	 * @return string com o tema do livro
	 **/
	std::string get_tema();

	/**
	 * @brief Funcao para obter o ISBN do livro
	 *
	 * @return long com o ISBN do livro
	 **/
	long get_ISBN();

	/**
	 * @brief Funcao para obter a cota do livro
	 *
	 * @return string com a cota do livro
	 **/
	std::string get_cota();

	/**
	 * @brief Funcao para obter o numero de paginas do livro
	 *
	 * @return int com o numero de paginas do livro
	 **/
	int get_num_paginas();

	/**
	 * @brief Funcao para obter a edicao do livro
	 *
	 * @return int com o numero da edicao do livro
	 **/
	int get_edicao();

	/**
	 * @brief Funcao para obter o estado emprestado do livro
	 *
	 * @return bool true se esta emprestado e false caso contrario
	 **/
	bool get_emprestado();

	/**
	 * @brief Funcao para determinar o estado emprestado do livro
	 *
	 * @param ept true se queremos colocar como emprestado e false caso contrario
	 **/
	void set_emprestado(bool ept);

	/**
	 * @brief Funcao para obter o ID do emprestimo do livro, caso exista
	 *
	 * @return long com o ID do emprestimo do livro, se existir, 0 caso contrario
	 **/
	long get_ID_ep();

	/**
	 * @brief Funcao para determinar o ID do emprestimo do livro, caso exista
	 *
	 * @return id_ep ID do emprestimo do livro, se existir, 0 caso contrario
	 **/
	void set_ID_ep(long id_ep);

	/**
	 * @brief Funcao para obter a data de emprestimo do livro, caso exista
	 *
	 * @return time_t com o a data de emprestimo do livro, se existir, 0 caso contrario
	 **/
	std::time_t get_data_emp();

	/**
	 * @brief Funcao para determinar a data de emprestimo do livro, caso exista
	 *
	 * @return dt data de emprestimo do livro, se existir, 0 caso contrario
	 **/
	void set_data_emp(std::time_t dt);

	/**
	 * @brief Funcao para obter o numero de dias que passou desde o emprestimo do livro, caso exista
	 *
	 * @return double com o numero de dias desde que o livro foi emprestado
	 *
	 * Nota: se o livro nao foi emprestado o resultado serao os dias todos desde 1970/01/01.
	 **/
	double get_dias_emp();

	/**
	 * @brief Funcao que escreve os atributos do livro
	 *
	 * @param ficheiro contem o caminho do ficheiro onde pretendemos escrever
	 **/
	virtual void escreve(std::string ficheiro);
};


#endif /* SRC_LIVRO_H_ */
