#ifndef SRC_EXCECAO_H_
#define SRC_EXCECAO_H_

#include "Leitor.h"

class Object;
class Livro;
class Leitor;

/**
 * @brief Excecao Object_nao_existe
 * Subclasse de Object. Sempre que um livro, funcionario, leitor, emprestimo ou utilizador nao exista,
 * esta excecao e utilizada.
 **/
class Object_nao_existe: public Object {

public:

	/**
	 * @brief Construtor de Object_nao_existe
	 * @param long id codigo de identificacao do objecto que nao existe
	 **/
	Object_nao_existe(long id): Object {id} {};

	/**
	 * @brief Destrutor virtual, porque a classe Object e virtual e tem um destrutor virtual
	 **/
	virtual ~Object_nao_existe() {};
};

/**
 * @brief Overload do operador << para imprimir um membro da classe Object_nao_existe
 * @param &out referencia para ostream onde sera colocada a impressao
 * @param &object referencia do objecto que nao existe
 * @return ostream com a impressao
 **/
std::ostream& operator<<(std::ostream &out, Object_nao_existe &object);

/**
 * @brief Excecao Livro_indisponivel
 * Subclasse de Livro. Sempre que se tenta emprestar um livro ja emprestado esta excecao e utilizada.
 **/
class Livro_indisponivel: public Livro {

public:

	/**
	 * @brief Construtor de Livro_indisponivel
	 * @param id codigo de identificacao do livro
	 * @param tit titulo do livro
	 * @param aut vetor com os nomes dos autores do livro
	 * @param tem tema do livro
	 * @param isbn ISBN do livro
	 * @param cot cota do livro na biblioteca
	 * @param np numero de paginas do livro
	 * @param ed numero da edicao do livro
	 * @param ept indicador se o livro se encontra emprestado ou nao
	 * @param id_ep ID do emprestimo do livro, caso exista
	 * @param dt data do emprestimo, caso exista
	 **/
	Livro_indisponivel(long id, std::string tit, std::vector<std::string> aut, std::string tem, long isbn,
			std::string cot, int np, int ed, bool ept, long id_ep, std::time_t dt):
				Livro {id, tit, aut, tem, isbn, cot, np, ed, ept, id_ep, dt} {};
};

/**
 * @brief Overload do operador << para imprimir um membro da classe Livro_indisponivel
 * @param &out referencia para ostream onde sera colocada a impressao
 * @param &livro referencia do livro que nao existe
 * @return ostream com a impressao
 **/
std::ostream& operator<<(std::ostream &out, Livro_indisponivel &livro);

/**
 * @brief Excecao Livro_emprestado
 * Subclasse de Livro. Sempre que se tenta remover um livro emprestado esta excecao e utilizada.
 **/
class Livro_emprestado: public Livro {

public:

	/**
	 * @brief Construtor de Livro_indisponivel
	 * @param id codigo de identificacao do livro
	 * @param tit titulo do livro
	 * @param aut vetor com os nomes dos autores do livro
	 * @param tem tema do livro
	 * @param isbn ISBN do livro
	 * @param cot cota do livro na biblioteca
	 * @param np numero de paginas do livro
	 * @param ed numero da edicao do livro
	 * @param ept indicador se o livro se encontra emprestado ou nao
	 * @param id_ep ID do emprestimo do livro, caso exista
	 * @param dt data do emprestimo, caso exista
	 **/
	Livro_emprestado(long id, std::string tit, std::vector<std::string> aut, std::string tem, long isbn,
			std::string cot, int np, int ed, bool ept, long id_ep, std::time_t dt):
				Livro {id, tit, aut, tem, isbn, cot, np, ed, ept, id_ep, dt} {};
};

/**
 * @brief Overload do operador << para imprimir um membro da classe Livro_emprestado
 * @param &out referencia para ostream onde sera colocada a impressao
 * @param &livro referencia do livro emprestado
 * @return ostream com a impressao
 **/
std::ostream& operator<<(std::ostream &out, Livro_emprestado &livro);

/**
 * @brief Excecao Emprestimos_por_devolver
 * Subclasse de Leitor. Sempre que se tenta remover um leitor com emprestimos esta excecao e utilizada.
 **/
class Emprestimos_por_devolver: public Leitor {

public:

	/**
	 * @brief Construtor de Emprestimos_por_devolver.
	 * @param id codigo de identificacao do leitor;
	 * @param nom nome do leitor;
	 * @param tel telefone do leitor;
	 * @param eml email do leitor;
	 * @param ep_lt vetor com os emprestimos do leitor
	 **/
	Emprestimos_por_devolver(long id, std::string nom, long tel, std::string eml, std::vector<Emprestimo*> ep_lt):
		Leitor {id, nom, tel, eml, ep_lt} {};
};

/**
 * @brief Overload do operador << para imprimir um membro da classe Emprestimos_por_devolver.
 * @param &out referencia para ostream onde sera colocada a impressao;
 * @param &leitor referencia do leitor com emprestimos por devolver.
 * @return ostream com a impressao
 **/
std::ostream& operator<<(std::ostream &out, Emprestimos_por_devolver &leitor);

/**
 * @brief Excecao Maximo_emprestimos
 * Subclasse de Leitor. Sempre que se tenta adicionar um emprestimo a um leitor com 3 emprestimos esta excecao e utilizada.
 **/
class Maximo_emprestimos: public Leitor {

public:

	/**
	 * @brief Construtor de Maximo_emprestimos.
	 * @param id codigo de identificacao do leitor;
	 * @param nom nome do leitor;
	 * @param tel telefone do leitor;
	 * @param eml email do leitor;
	 * @param ep_lt vetor com os emprestimos do leitor
	 **/
	Maximo_emprestimos(long id, std::string nom, int tel, std::string eml, std::vector<Emprestimo*> ep_lt):
		Leitor {id, nom, tel, eml, ep_lt} {};
};

/**
 * @brief Overload do operador << para imprimir um membro da classe Maximo_emprestimos.
 * @param ostream &out referencia para ostream onde sera colocada a impressao;
 * 			   Maximo_emprestimos &leitor referencia do leitor com maximo de emprestimos atingido.
 * @return ostream com a impressao
 **/
std::ostream& operator<<(std::ostream &out, Maximo_emprestimos &leitor);

/**
 * @brief Excecao Ficheiro_indisponivel.
 * Sempre que se tenta aceder (para ler ou para escrever) a um ficheiro inexistente esta excecao e utilizada.
 **/
class Ficheiro_indisponivel {

	std::string ficheiro; /**< caminho para o ficheiro inexistente**/

public:

	/**
	 *  Construtor de Ficheiro_indisponivel.
	 *  @param fch caminho para o ficheiro
	 **/
	Ficheiro_indisponivel(std::string fch): ficheiro {fch} {};

	/** Funcao para obter o caminho do ficherio.
	 * @return string com o caminho
	 **/
	std::string get_ficheiro();
};

/**
 * @brief Overload do operador << para imprimir um membro da classe Ficheiro_indisponivel.
 * @param &out referencia para ostream onde sera colocada a impressao;
 * @param &ficheiro referencia do ficherio indisponivel.
 * @return ostream com a impressao
 **/
std::ostream& operator<<(std::ostream &out, Ficheiro_indisponivel &ficheiro);

#endif /* SRC_EXCECAO_H_ */
