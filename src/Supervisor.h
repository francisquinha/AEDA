
#ifndef SRC_SUPERVISOR_H_
#define SRC_SUPERVISOR_H_

#include "Funcionario.h"

class Funcionario;

class Supervisor: public Funcionario {
	std::vector<Funcionario*> funcionarios_sup;
public:
	Supervisor(long id, std::string nom, std::vector<Funcionario*> func_sup);
	void adiciona_func_sup(Funcionario* fc);
	void set_func_sup(std::vector<Funcionario*> func_sup);
	std::vector<Funcionario*> get_func_sup();
	std::string imprime();
	void escreve(std::string ficheiro_fc, std::string ficheiro_sp);
};

#endif /* SRC_SUPERVISOR_H_ */
