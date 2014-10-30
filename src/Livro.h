
#ifndef SRC_LIVRO_H_
#define SRC_LIVRO_H_

#include "tem_id.h"

class tem_id;

class Livro: public tem_id{
	std::string titulo;
	std::vector<std::string> autores;
	long ISBN;
	std::string cota;
	int num_paginas;
	int edicao;
	bool emprestado;
	int dias_indisponivel;
	static long num_livros;
public:
	Livro(long id, std::string tit, std::vector<std::string> aut, long isbn, std::string cot, int np, int ed,
			bool ept, int di);
	Livro(std::string tit, std::vector<std::string> aut, long isbn, std::string cot, int np, int ed,
			bool ept, int di);
	std::string imprime();
	std::string get_titulo();
	void set_titulo(std::string tit);
	std::vector<std::string> get_autores();
	void set_autores(std::vector<std::string> aut);
	long get_ISBN();
	void set_ISBN(long isbn);
	std::string get_cota();
	void set_cota(std::string cot);
	int get_num_paginas();
	void set_num_paginas(int np);
	int get_edicao();
	void set_edicao(int ed);
	bool get_emprestado();
	void set_emprestado(bool ept);
	int get_dias_indisponivel();
	void set_dias_indisponivel(int di);
	void escreve();
};

#endif /* SRC_LIVRO_H_ */
