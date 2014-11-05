
#ifndef SRC_ADMINISTRADOR_H_
#define SRC_ADMINISTRADOR_H_

#include "Funcionario.h"

class Funcionario;

/* Administrador do sistema informatico.
 *
 * Funciona como uma especie de gerente da Biblioteca. Tem acesso a todas as funcoes dos outros utilizadores.
 * E o unico que pode adicionar e remover funcionarios, promover e despromover e adicionar utilizadores ao sistema informatico.
 *
 * Tem os mesmos atributos da classe funcionario, isto e, um ID e um nome.
 *
 * Na pratica esta classe apenas e utilizada para criar um administrador com ID = 0 e nome = Administrador. */
class Administrador: public Funcionario {
public:
	/* Construtor de Administrador.
	 * Parametros: long id - codigo de identificacao;
	 * 			   string nom - nome do administrador. */
	Administrador(long id, std::string nom);
	/* Funcao de escrita de Administrador. Nao faz nada, apenas existe para que a funcao virtual escreve na classe funcionario a chame,
	 * em vez de colocar o administrador no ficheiro dos funcionarios
	 * Parametros : string ficheiro_fc - nome do ficheiro dos funcionarios;
	 * 				string ficheiro_sp - nome do ficheiro dos supervisores.*/
	void escreve(std::string ficheiro_fc, std::string ficheiro_sp);
};

#endif /* SRC_ADMINISTRADOR_H_ */
