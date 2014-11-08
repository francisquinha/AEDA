
#ifndef SRC_LIVRO_OLD_H_
#define SRC_LIVRO_OLD_H_

#include <ctime>
#include "Livro.h"

class Livro;

/**
 * @brief Classe com toda a informacao de Livro antigo
 **/
class Livro_old: public Livro {

	std::time_t data_fim;

public:

	Livro_old(long id, std::string tit, std::vector<std::string> aut, std::string tem, long isbn, std::string cot,
			int np, int ed, bool ept, long id_ep, std::time_t dt, std::time_t dtf, bool ct);

	Livro_old(long id, std::string tit, std::vector<std::string> aut, std::string tem, long isbn, std::string cot,
			int np, int ed, bool ept, long id_ep, std::time_t dt, bool ct);

	std::string imprime();

	void escreve(std::string ficheiro);
};

#endif /* SRC_LIVRO_OLD_H_ */
