
#ifndef SRC_LIVRO_H_
#define SRC_LIVRO_H_

#include <ctime>
#include "Object.h"

class Object;

/**
 * @brief Classe com toda a informacao de Livro
 *
 * Subclasse de Object.
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

	Livro(long id, std::string tit, std::vector<std::string> aut, std::string tem, long isbn, std::string cot,
			int np, int ed, bool ept, long id_ep, std::time_t dt);

	Livro(std::string tit, std::vector<std::string> aut, std::string tem, long isbn, std::string cot,
			int np, int ed, bool ept, long id_ep, std::time_t dt);

	std::string imprime();

	std::string get_titulo();

	std::vector<std::string> get_autores();

	std::string get_tema();

	long get_ISBN();

	std::string get_cota();

	int get_num_paginas();

	int get_edicao();

	bool get_emprestado();

	void set_emprestado(bool ept);

	long get_ID_ep();

	void set_ID_ep(long id_ep);

	std::time_t get_data_emp();

	void set_data_emp(std::time_t dt);

	double get_dias_emp();

	void escreve(std::string ficheiro);
};


#endif /* SRC_LIVRO_H_ */
