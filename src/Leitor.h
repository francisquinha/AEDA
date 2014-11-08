
#ifndef SRC_LEITOR_H_
#define SRC_LEITOR_H_

#include "Emprestimo.h"
#include "Object.h"

class Emprestimo;
class Object;

/**
 * @brief Classe com toda a informacao de Leitor
 **/
class Leitor: public Object {

	std::string nome; /**< @brief nome do leitor **/
	long telefone; /**< @brief telefone do leitor **/
	std::string email; /**< @brief email do leitor **/
	std::vector<Emprestimo*> emprestimos_leitor; /**< @brief vetor com apontadores para os emprestimos do leitor **/
	static long num_leitores; /**< @brief contador de leitores na biblioteca **/

public:

	/**
	 * @brief Construtor de Leitor
	 *
	 * @param id codigo de identificacao do leitor
	 * @param nom nome do leitor
	 * @param tel telefone do leitor
	 * @param eml email do leitor
	 * @param ep_lt vetor de apontadores para os emprestimos do leitor
	 * @param ct indica se devemos incrementar o contador de leitores
	 **/
	Leitor(long id, std::string nom, long tel, std::string eml, std::vector<Emprestimo*> ep_lt, bool ct);

	/**
	 * @brief Construtor de Leitor
	 *
	 * @param nom nome do leitor
	 * @param tel telefone do leitor
	 * @param eml email do leitor
	 * @param ep_lt vetor de apontadores para os emprestimos do leitor
	 * @param ct indica se devemos incrementar o contador de leitores
	 **/
	Leitor(std::string nom, long tel, std::string eml, std::vector<Emprestimo*> ep_lt, bool ct);

	/**
	 * @brief Construtor de Leitor
	 *
	 * @param id codigo de identificacao do leitor
	 * @param nom nome do leitor
	 * @param tel telefone do leitor
	 * @param eml email do leitor
	 * @param ct indica se devemos incrementar o contador de leitores
	 **/
	Leitor(long id, std::string nom, long tel, std::string eml, bool ct);

	/**
	 * @brief Construtor de Leitor
	 *
	 * @param nom nome do leitor
	 * @param tel telefone do leitor
	 * @param eml email do leitor
	 * @param ct indica se devemos incrementar o contador de leitores
	 **/
	Leitor(std::string nom, long tel, std::string eml, bool ct);

	/**
	 * @brief Destrutor virtual de Leitor
	 **/
	virtual ~Leitor() {};

	/**
	 * @brief Funcao que imprime os atributos do leitor
	 *
	 * @return string com o resultado da impressao
	 **/
	virtual std::string imprime();

	/**
	 * @brief Funcao para obter o nome do leitor
	 *
	 * @return string com o nome do leitor
	 **/
	std::string get_nome();

	/**
	 * @brief Funcao para determinar o nome do leitor
	 *
	 * @param nom nome do leitor
	 **/
	void set_nome(std::string nom);

	/**
	 * @brief Funcao para obter o telefone do leitor
	 *
	 * @return long com o telefone do leitor
	 **/
	long get_telefone();

	/**
	 * @brief Funcao para determinar o telefone do leitor
	 *
	 * @param tel telefone do leitor
	 **/
	void set_telefone(long tel);

	/**
	 * @brief Funcao para obter o email do leitor
	 *
	 * @return string com o email do leitor
	 **/
	std::string get_email();

	/**
	 * @brief Funcao para determinar o email do leitor
	 *
	 * @return eml email do leitor
	 **/
	void set_email(std::string eml);

	/**
	 * @brief Funcao para adicionar emprestimo ao leitor
	 *
	 * @param ep apontador para o emprestimo que pretendemos adicionar
	 **/
	void adiciona_emp_leit(Emprestimo* ep);

	/**
	 * @brief Funcao para remover emprestimo do leitor
	 *
	 * @param id identificacao do emprestimo a remover
	 *
	 * @return true se o leitor tem algum emprestimo com o id fornecido
	 *
	 * @exception Object_nao_existe se o leitor nao tem nenhum emprestimo com o id fornecido
	 **/
	bool remove_emp_leit(long id);

	/**
	 * @brief Funcao para obter emprestimos do leitor
	 *
	 * @return vector<Emprestimo*> de apontadores para os emprestimos do leitor
	 **/
	std::vector<Emprestimo*> get_emp_leit();

	/**
	 * @brief Funcao que imprime os emprestimos do leitor
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime_emp_leit();

	/**
	 * @brief Funcao para obter os emprestimos atrasados do leitor
	 *
	 * @return vector<Emprestimo*> de apontadores para os emprestimos atrasados
	 **/
	std::vector<Emprestimo*> get_emprestimos_atrasados();

	/**
	 * @brief Funcao que escreve os atributos do leitor num ficheiro
	 *
	 * @param ficheiro caminho para o ficheiro que pretendemos usar
	 **/
	virtual void escreve(std::string ficheiro);
};

#endif /* SRC_LEITOR_H_ */
