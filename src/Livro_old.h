
#ifndef SRC_LIVRO_OLD_H_
#define SRC_LIVRO_OLD_H_

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <cmath>

#include "Livro.h"

class Livro;

/** @file
 *
 * @brief Header das funcoes dos Livro_old.
 *
 * Se uma funcao relacionada com livros antigos nao estiver nos ficheiros biblio, esta aqui.
 **/

/**
 * @brief Classe com toda a informacao de Livro antigo
 *
 * Na Biblioteca, os livros antigos sao guardados no mesmo vetor dos livros atuais.
 *
 **/
class Livro_old: public Livro {

	std::time_t data_fim;

public:

	/**
	 * @brief Construtor de Livro antigo
	 *
     * @param ano ano de edicao do livro
     * @param tit titulo do livro
     * @param aut vetor com os nomes dos autores
     * @param tem tema do livro
     * @param isbn ISBN do livro
     * @param cot cota do livro na biblioteca
     * @param np numero de paginas do livro
     * @param ed numero da edicao do livro
     * @param dtf lista com as datas de emprestimo de cada exemplar do livro, tudo 0
     * @param ct indica se devemos incrementar o contador de livros
     * @param id codigo de identificacao do livro
     * @param ex numero total de exemplares do livro
     * @param exd numero de exemplares disponiveis do livro
	 **/
    Livro_old(int ano, std::string tit, std::vector<std::string> aut, std::string tem, long isbn,
              std::string cot, int np, int ed, bool ct, time_t dtf, unsigned long id, int ex = 1,
              int exd = 1);

	/**
	 * @brief Funcao que imprime os atributos do livro antigo
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime();

	/**
	 * @brief Funcao que escreve os atributos do livro antigo
	 *
	 * @param ficheiro contem o caminho do ficheiro onde pretendemos escrever
	 **/
	void escreve(std::string ficheiro);
};

#endif /* SRC_LIVRO_OLD_H_ */
