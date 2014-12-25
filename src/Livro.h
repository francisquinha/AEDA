/* 
 * Alterar a classe Livro:
 * - acrescentar exemplares e ex_disponiveis;
 * - retirar emprestado, ID_ep, data_emp;
 * - acrescentar lista (ou vetor) ID_ep e lista (ou vetor) data_emp com referencias aos emprestimos dos varios exemplares;
 * - acrescentar ano_edicao;
 * - acrescentar funcoes para alterar dados do livro;
 * - acrescentar funcao para incrementar exemplares do livro (ou alterar funcao que adiciona livro a biblioteca).
 */


#ifndef SRC_LIVRO_H_
#define SRC_LIVRO_H_

#include <string>
#include <list>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <cmath>

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

    int ano_edicao; /**< @brief ano de edicao do livro **/
    std::string titulo; /**< @brief titulo do livro **/
	std::vector<std::string> autores;  /**< @brief vetor com os nomes dos autores do livro **/
	std::string tema; /**< @brief tema do livro **/
	long ISBN; /**< @brief ISBN do livro **/
	std::string cota; /**< @brief cota do livro na biblioteca **/
	int num_paginas; /**< @brief numero de paginas do livro **/
	int edicao; /**< @brief numero da edicao do livro **/
    int exemplares; /**< @brief numero total de exemplares do livro na biblioteca **/
    int ex_disponiveis; /**< @brief numero de exemplares do livro disponiveis (nao emprestados) **/
    std::vector<unsigned long> ID_ep; /**< @brief lista com a identificacao do emprestimo de cada exemplar do livro, se existir, 0 caso contrario **/
    std::vector<std::time_t> data_emp; /**< @brief lista com a data do emprestimo de cada exemplar do livro, se existir, 0 caso contrario **/
	static unsigned long num_livros; /**< @brief contador de livros na biblioteca (livros distintos, nao exemplares) **/

public:

	/**
	 * @brief Construtor de Livro
	 *
	 * @param ano ano de edicao do livro
     * @param tit titulo do livro
	 * @param aut vetor com os nomes dos autores
	 * @param tem tema do livro
	 * @param isbn ISBN do livro
	 * @param cot cota do livro na biblioteca
	 * @param np numero de paginas do livro
	 * @param ed numero da edicao do livro
     * @param ct indica se devemos incrementar o contador de livros
     * @param id codigo de identificacao do livro
     * @param ex numero total de exemplares do livro
     * @param exd numero de exemplares disponiveis do livro
	 * @param id_ep lista com os IDs dos emprestimos de cada exemplar do livro
	 * @param dt lista com as datas de emprestimo de cada exemplar do livro
	 **/
    Livro(int ano, std::string tit, std::vector<std::string> aut, std::string tem, long isbn,
          std::string cot, int np, int ed, bool ct, unsigned long id = num_livros + 1, int ex = 1,
          int exd = 1, std::vector<unsigned long> id_ep = {0}, std::vector<time_t> dt = {0});

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
     * @brief Funcao para obter o ano de edicao do livro
     *
     * @return int com o ano de edicao do livro
     **/
    int get_ano_edicao();

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
     * @brief Funcao para obter o numero total de exemplares do livro
     *
     * @return int com o numero total de exemplares do livro
     **/
    int get_exemplares();
    
    /**
     * @brief Funcao para incrementar o numero total de exemplares do livro
     **/
    void inc_exemplares();
    
    /**
     * @brief Funcao para decrementar o numero total de exemplares do livro
     **/
    void dec_exemplares();
    
    /**
     * @brief Funcao para obter o numero de exemplares disponiveis do livro
     *
     * @return int com o numero de exemplares disponiveis do livro
     **/
    int get_ex_disponiveis();
    
    /**
     * @brief Funcao para incrementar o numero de exemplares disponiveis do livro
     **/
    void inc_ex_disponiveis();
    
    /**
     * @brief Funcao para decrementar o numero de exemplares disponiveis do livro
     **/
    void dec_ex_disponiveis();

	/**
	 * @brief Funcao para obter a lista de IDs de emprestimos dos exemplares do livro
	 *
	 * @return list<long> com os IDs de emprestimos de exemplares do livro
	 **/
    std::vector<unsigned long> get_ID_ep();

	/**
	 * @brief Funcao para determinar o ID de emprestimo de um exemplar do livro
	 *
	 * @param ind indice do exemplar do livro para o qual queremos alterar o ID do emprestimo
     * @param id_ep ID do emprestimo do exemplar do livro, se existir, 0 caso contrario
	 **/
	void set_ID_ep(unsigned long ind, unsigned long id_ep);

    /**
     * @brief Funcao para incrementar o numero de IDs de emprestimo de exemplares do livro
     **/
    void inc_ID_ep();

    /**
     * @brief Funcao para remover o ID de emprestimo de um exemplare do livro
     *
     * @param ind indice do exemplar do livro cujo ID queremos remover do vetor
     **/
    void del_ID_ep(unsigned long ind);
    
	/**
	 * @brief Funcao para obter a lista de datas de emprestimos de exemplares do livro
	 *
	 * @return list<time_t> com as datas de emprestimos de exemplares do livro
	 **/
    std::vector<std::time_t> get_data_emp();

	/**
	 * @brief Funcao para determinar a data de emprestimo de um exemplar do livro
	 *
     * @param ind indice do exemplar do livro para o qual queremos alterar a data de emprestimo
	 * @param dt data de emprestimo do exemplar do livro, se existir, 0 caso contrario
	 **/
	void set_data_emp(unsigned long ind, std::time_t dt);
    
    /**
     * @brief Funcao para incrementar o numero de datas de emprestimo de exemplares do livro
     **/
    void inc_data_emp();
    
    /**
     * @brief Funcao para remover a data de emprestimo de um exemplare do livro
     *
     * @param ind indice do exemplar do livro cuja data queremos remover do vetor
     **/
    void del_data_emp(unsigned long ind);

	/**
	 * @brief Funcao para obter o numero de dias desde o emprestimo de um exemplar do livro
     *
     * @param ind indice do exemplar do livro
	 * @return double com o numero de dias desde que o livro foi emprestado
	 *
	 * Nota: se o livro nao foi emprestado o resultado serao os dias todos desde 1970/01/01.
	 **/
	double get_dias_emp(unsigned long ind);

	/**
	 * @brief Funcao que escreve os atributos do livro
	 *
	 * @param ficheiro contem o caminho do ficheiro onde pretendemos escrever
	 **/
	virtual void escreve(std::string ficheiro);
};


#endif /* SRC_LIVRO_H_ */
