#include <vector>

#ifndef SRC_FUNCIONARIO_H_
#define SRC_FUNCIONARIO_H_

#include "Object.h"

class Object;

class Funcionario: public Object {
	std::string nome;
	static long num_funcionarios;
public:
	Funcionario(long id, std::string nom);
	Funcionario(std::string nom);
	virtual ~Funcionario() {};
	virtual std::string imprime();
	std::string get_nome();
	void set_nome(std::string nom);
	virtual void escreve(std::string ficheiro_fc, std::string ficheiro_sp);
	virtual void set_func_sup(std::vector<Funcionario*> func_sup) {};
	virtual std::vector<Funcionario*> get_func_sup() {
		std::vector<Funcionario*> v {};
		return v;
	};
	virtual void adiciona_func_sup(Funcionario* fc) {};
};

#endif /* SRC_FUNCIONARIO_H_ */
