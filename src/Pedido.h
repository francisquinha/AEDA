
#ifndef SRC_PEDIDO_H_
#define SRC_PEDIDO_H_

#include "Livro.h"
#include "Leitor.h"
#include "Funcionario.h"
#include "Object.h"
#include <ctime>

class Livro;
class Leitor;
class Funcionario;
class Object;

/** @file
 *
 * @brief Header das funcoes de Pedido.
 *
 * Se uma funcao relacionada com pedidos em espera de leitores nao estiver nos ficheiros biblio, esta aqui.
 **/

/**
 * @brief Classe com toda a informacao de Pedido
 **/
class Pedido: public Object {

    Livro* livro; /**< @brief apontador para o livro do pedido **/
    Funcionario* funcionario; /**< @brief apontador para o funcionario que fez o pedido **/
	Leitor* leitor; /**< @brief apontador para o leitor do pedido **/
	std::time_t data; /**< @brief data do pedido **/
	static unsigned long num_pedidos; /**< @brief contador de pedidos atuais na biblioteca **/

public:

	/**
	 * @brief Construtor de Pedido
	 *
	 * @param lv apontador para o livro
	 * @param fc apontador para o funcionario
	 * @param lt apontador para o leitor
     * @param ct indica se devemos incrementar o contador de pedidos
	 * @param dt data do pedido
     * @param id codigo de identificacao do pedido
	 **/
	Pedido(Livro* lv, Funcionario* fc, Leitor* lt, bool ct, std::time_t dt = time(0),
           unsigned long id = num_pedidos + 1);

	/**
	 * @brief Destrutor virtual de Pedido (isto nao deve ser necessario)
	 **/
	virtual ~Pedido() {};
    
    bool operator <(Pedido pd);

	/**
	 * @brief Funcao para obter o livro do pedido
	 *
	 * @return apontador para o livro
	 **/
	Livro* get_livro() const;

	/**
	 * @brief Funcao para obter o funcionario responsavel pelo pedido
	 *
	 * @return apontador para o funcionario
	 **/
	Funcionario* get_funcionario() const;

	/**
	 * @brief Funcao para obter o leitor a quem e feito o pedido
	 *
	 * @return apontador para o leitor
	 **/
	Leitor* get_leitor() const;

	/**
	 * @brief Funcao para obter a data do pedido
	 *
	 * @return data do pedido
	 **/
	std::time_t get_data() const;

	/**
	 * @brief Funcao que imprime os atributos do pedido
	 *
	 * @return string com o resultado da impressao
	 **/
	virtual std::string imprime();

	/**
	 * @brief Funcao que escreve os atributos do pedido num ficheiro
	 *
	 * @param ficheiro contem o caminho do ficheiro onde pretendemos escrever
	 **/
	virtual void escreve(std::string ficheiro);
};


#endif /* SRC_PEDIDO_H_ */
