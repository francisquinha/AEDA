
#ifndef SRC_LIVRO_H_
#define SRC_LIVRO_H_

#include <ctime>
#include "Object.h"

class Object;

class Livro: public Object {
	std::string titulo;
	std::vector<std::string> autores;
	std::string tema;
	long ISBN;
	std::string cota;
	int num_paginas;
	int edicao;
	bool emprestado;
	std::time_t data_emp;
	static long num_livros;
public:
	Livro(long id, std::string tit, std::vector<std::string> aut, std::string tem, long isbn, std::string cot,
			int np, int ed, bool ept, std::time_t dt);
	Livro(std::string tit, std::vector<std::string> aut, std::string tem, long isbn, std::string cot,
			int np, int ed, bool ept, std::time_t dt);
	std::string imprime();
	std::string get_titulo();
	void set_titulo(std::string tit);
	std::vector<std::string> get_autores();
	void set_autores(std::vector<std::string> aut);
	std::string get_tema();
	void set_tema();
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
	std::time_t get_data_emp();
	void set_data_emp(std::time_t dt);
	double get_dias_emp();
	void escreve(std::string ficheiro);
};

#endif /* SRC_LIVRO_H_ */
