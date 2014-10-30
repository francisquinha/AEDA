
#ifndef SRC_FUNCIONARIO_H_
#define SRC_FUNCIONARIO_H_

#include "tem_id.h"

class tem_id;

class Funcionario: public tem_id {
	std::string nome;
	static long num_funcionarios;
public:
	Funcionario(long id, std::string nom);
	Funcionario(std::string nom);
	virtual ~Funcionario(){};
	virtual std::string imprime();
	std::string get_nome();
	void set_nome(std::string nom);
	void escreve();
};

#endif /* SRC_FUNCIONARIO_H_ */
