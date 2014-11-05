
#ifndef SRC_ADMINISTRADOR_H_
#define SRC_ADMINISTRADOR_H_

#include "Funcionario.h"

class Funcionario;

class Administrador: public Funcionario {
public:
	Administrador(long id, std::string nom);
	void escreve(std::string ficheiro_fc, std::string ficheiro_sp);
};

#endif /* SRC_ADMINISTRADOR_H_ */
