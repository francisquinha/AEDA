
#ifndef SRC_LIVRO_H_
#define SRC_LIVRO_H_

#include <string>
#include <list>
#include <vector>
#include <queue>
#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <cmath>

#include "Object.h"
#include "Pedido.h"
#include "Emprestimo.h"

class Object;
class Pedido;
class Emprestimo;

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
    std::vector<Emprestimo*> emprestimos_livro; /**< @brief vetor com apontadores (eventualmente nulos) para os emprestimos de cada exemplar do livro **/
    std::priority_queue<Pedido> pedidos; /**< @brief fila de prioridade com os pedidos de emprestimo do livro **/
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
	 * @param ep vetor com os apontadores para os emprestimos de cada exemplar do livro
     * @param pd fila de prioridade com os pedidos de emprestimo do livro
	 **/
    Livro(int ano, std::string tit, std::vector<std::string> aut, std::string tem, long isbn,
          std::string cot, int np, int ed, bool ct, unsigned long id = num_livros + 1,
          int ex = 1, int exd = 1, std::vector<Emprestimo*> ep = {NULL},
          std::priority_queue<Pedido> pd = {});

	/**
	 * @brief Destrutor virtual de Livro
	 **/
	virtual ~Livro() {};
    
    /**
     * @brief Funcao para obter o ano de edicao do livro
     *
     * @return int com o ano de edicao do livro
     **/
    int get_ano_edicao() const;

	/**
	 * @brief Funcao para obter o titulo do livro
	 *
	 * @return string com o titulo do livro
	 **/
	std::string get_titulo() const;

	/**
	 * @brief Funcao para obter os autores do livro
	 *
	 * @return vector<string> com os nomes dos autores do livro
	 **/
	std::vector<std::string> get_autores() const;

	/**
	 * @brief Funcao para obter o tema do livro
	 *
	 * @return string com o tema do livro
	 **/
	std::string get_tema() const;

	/**
	 * @brief Funcao para obter o ISBN do livro
	 *
	 * @return long com o ISBN do livro
	 **/
	long get_ISBN() const;

	/**
	 * @brief Funcao para obter a cota do livro
	 *
	 * @return string com a cota do livro
	 **/
	std::string get_cota() const;

	/**
	 * @brief Funcao para obter o numero de paginas do livro
	 *
	 * @return int com o numero de paginas do livro
	 **/
	int get_num_paginas() const;

	/**
	 * @brief Funcao para obter a edicao do livro
	 *
	 * @return int com o numero da edicao do livro
	 **/
	int get_edicao() const;
    
    /**
     * @brief Funcao para obter o numero total de exemplares do livro
     *
     * @return int com o numero total de exemplares do livro
     **/
    int get_exemplares() const;
    
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
    int get_ex_disponiveis() const;
    
    /**
     * @brief Funcao para incrementar o numero de exemplares disponiveis do livro
     **/
    void inc_ex_disponiveis();
    
    /**
     * @brief Funcao para decrementar o numero de exemplares disponiveis do livro
     **/
    void dec_ex_disponiveis();

	/**
	 * @brief Funcao para obter o vetor de apontadores de emprestimos dos exemplares do livro
	 *
	 * @return vector<Emprestimo*> com os apontadores de emprestimos de exemplares do livro
	 **/
    std::vector<Emprestimo*> get_emp_livro() const;

	/**
	 * @brief Funcao para determinar o apontador de emprestimo de um exemplar do livro
	 *
	 * @param ind indice do exemplar do livro para o qual queremos alterar o ID do emprestimo
     * @param Emprestimo* ep apontador do emprestimo, se existir, NULL caso contrario
	 **/
    void set_emp_livro(unsigned long ind, Emprestimo* ep);

    /**
     * @brief Funcao para incrementar o tamanho do vetor de emprestimos do livro
     **/
    void inc_emp_livro();

    /**
     * @brief Funcao para remover o apontador de emprestimo de um exemplare do livro
     *
     * @param ind indice do exemplar do livro cujo apontador queremos remover do vetor
     **/
    void del_emp_livro(unsigned long ind);
    
	/**
	 * @brief Funcao para obter o numero de dias desde o emprestimo de um exemplar do livro
     *
     * @param ind indice do exemplar do livro
	 * @return double com o numero de dias desde que o livro foi emprestado
	 *
	 * Nota: se o livro nao foi emprestado o resultado serao os dias todos desde 1970/01/01.
	 **/
	double get_dias_emp(unsigned long ind) const;
    
    /**
     * @brief Funcao para obter a fila de prioridade de apontadores de pedidos do livro
     *
     * @return priority_queue<Pedido*> com os apontadores de pedidos do livro
     **/
    std::priority_queue<Pedido> get_pedidos() const;
    
    /**
     * @brief Funcao para adicionar um pedido a fila de prioridade do livro
     *
     * @param pd apontador para o pedido que queremos adicionar
     **/
    void adiciona_ped_livro(Pedido pd);
    
    /**
     * @brief Funcao para remover o pedido mais prioritario da fila de prioridade do livro
     **/
    void remove_ped_livro();
    
    /**
     * @brief Funcao para determinar a da fila de prioridade de pedidos do livro
     **/
    void set_pedidos(std::priority_queue<Pedido> pds);
    
    /**
     * @brief Funcao que imprime os atributos do livro
     *
     * @return string com o resultado da impressao
     **/
    virtual std::string imprime();

	/**
	 * @brief Funcao que escreve os atributos do livro
	 *
	 * @param ficheiro contem o caminho do ficheiro onde pretendemos escrever
	 **/
	virtual void escreve(std::string ficheiro);
};


#endif /* SRC_LIVRO_H_ */
