
#ifndef SRC_LEITOR_H_
#define SRC_LEITOR_H_

#include "Emprestimo.h"
#include "Object.h"

class Emprestimo;
class Object;

/** @file
 *
 * @brief Header das funcoes de Leitor.
 *
 * Se uma funcao relacionada com leitores nao estiver nos ficheiros biblio, esta aqui.
 **/

/**
 * @brief Classe com toda a informacao de Leitor
 **/
class Leitor: public Object {

	std::string nome; /**< @brief nome do leitor **/
	int tipo; /**< @brief tipo de leitor (0 - estudante, 1 - crianca ate 12 anos, 2 - adulto) **/
	long telefone; /**< @brief telefone do leitor **/
	std::string email; /**< @brief email do leitor **/
	std::string morada; /**< @brief morada do leitor **/
	std::vector<Emprestimo*> emprestimos_leitor; /**< @brief vetor com apontadores para os emprestimos do leitor **/
	static unsigned long num_leitores; /**< @brief contador de leitores na biblioteca **/

public:

	/**
	 * @brief Construtor de Leitor
	 *
	 * @param id codigo de identificacao do leitor
	 * @param nom nome do leitor
	 * @param tip tipo do leitor
	 * @param tel telefone do leitor
	 * @param eml email do leitor
	 * @param mrd morada do leitor
	 * @param ep_lt vetor de apontadores para os emprestimos do leitor
	 * @param ct indica se devemos incrementar o contador de leitores
	 **/
    Leitor(std::string nom, int tip, long tel, std::string eml, std::string mrd, bool ct,
           unsigned long id = num_leitores + 1, std::vector<Emprestimo*> ep_lt = {});
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
	 * @brief Funcao para obter o tipo do leitor
	 *
	 * @return int com o tipo do leitor
	 **/
	int get_tipo();

	/**
	 * @brief Funcao para determinar o tipo do leitor
	 *
	 * @param tip tipo do leitor
	 **/
	void set_tipo(int tip);

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
	 * @brief Funcao para obter a morada do leitor
	 *
	 * @return string com a morada do leitor
	 **/
	std::string get_morada();

	/**
	 * @brief Funcao para determinar o email do leitor
	 *
	 * @param eml email do leitor
	 **/
	void set_email(std::string eml);

	/**
	 * @brief Funcao para determinar a morada do leitor
	 *
     * @param mrd morada do leitor
	 **/
	void set_morada(std::string mrd);



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
	bool remove_emp_leit(unsigned long id);

	/**
	 * @brief Funcao para obter emprestimos do leitor
	 *
	 * @return vector<Emprestimo*> de apontadores para os emprestimos do leitor
	 **/
	std::vector<Emprestimo*> get_emp_leit();

    /**
     * @brief Funcao para obter data do ultimo emprestimo do leitor
     *
     * @return time_t com a data do ultimo emprestimo do leitor
     **/
    time_t get_data_ult_emp();
    
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
