#ifndef SRC_EXCECAO_H_
#define SRC_EXCECAO_H_

#include "Leitor.h"

class Object;
class Livro;
class Leitor;

/** @file
 *
 * @brief Header das classes e dos operadores << de Excecao.
 *
 * Todas as excessoes estao aqui.
 **/

/**
 * @brief Excecao Object_nao_existe
 *
 * Sempre que um livro, funcionario, leitor, emprestimo ou utilizador nao exista,
 * esta excecao e utilizada.
 **/
class Object_nao_existe: public Object {

	/** @brief tipo de objeto que nao existe (livro, leitor, funcionario, supervisor, emprestimo, utilizador) **/
	std::string tipo;

public:

	/**
	 * @brief Construtor de Object_nao_existe
	 *
	 * @param id codigo de identificacao do objecto que nao existe
	 **/
	Object_nao_existe(unsigned long id, std::string tp): Object {id}, tipo {tp} {};

	/**
	 * @brief Destrutor virtual, porque a classe Object e virtual e tem um destrutor virtual
	 **/
	virtual ~Object_nao_existe() {};

	/**
	 * @brief Funcao para obter o tipo do objeto inexistente
	 *
	 * @return string com o tipo de objeto.
	 **/
	std::string get_tipo();
};

/**
 * @brief Overload do operador << para imprimir um membro da classe Object_nao_existe
 *
 * @param &out referencia para ostream onde sera colocada a impressao
 * @param &object referencia do objecto que nao existe
 *
 * @return ostream com a impressao
 **/
std::ostream& operator<<(std::ostream &out, Object_nao_existe &object);

/**
 * @brief Excecao Livro_indisponivel
 *
 * Sempre que se tenta emprestar um livro ja emprestado esta excecao e utilizada.
 **/
class Livro_indisponivel: public Livro {

public:

	/**
	 * @brief Construtor de Livro_indisponivel
	 *
     * @param ano ano de edicao do livro
	 * @param tit titulo do livro
	 * @param aut vetor com os nomes dos autores do livro
	 * @param tem tema do livro
	 * @param isbn ISBN do livro
	 * @param cot cota do livro na biblioteca
	 * @param np numero de paginas do livro
	 * @param ed numero da edicao do livro
     * @param id codigo de identificacao do livro
	 * @param ex numero total de exemplares do livro
	 * @param exd numero de exemmplares disponiveis do livro
     * @param ep vetor com os apontadores de emprestimo dos exemplares do livro
	 * @param pd fila de prioridade com os apontadores dos pedidos de emprestimo do livro
	 **/
    Livro_indisponivel(int ano, std::string tit, std::vector<std::string> aut, std::string tem,
                       long isbn, std::string cot, int np, int ed, unsigned long id, int ex,
                       int exd, std::vector<Emprestimo*> ep, std::priority_queue<Pedido*> pd):
    Livro {ano, tit, aut, tem, isbn, cot, np, ed, false, id, ex, exd, ep, pd} {};
};

/**
 * @brief Overload do operador << para imprimir um membro da classe Livro_indisponivel
 *
 * @param &out referencia para ostream onde sera colocada a impressao
 * @param &livro referencia do exemplar inexistente
 *
 * @return ostream com a impressao
 **/
std::ostream& operator<<(std::ostream &out, Livro_indisponivel &livro);

class Exemplar_indisponivel: public Livro {
    
    unsigned long indice; /**< @brief indice do exemplar do livro **/
    
public:
    
    /**
     * @brief Construtor de Exemplar_indisponivel
     *
     * @param ind indice do exemplar do livro
     * @param ano ano de edicao do livro
     * @param tit titulo do livro
     * @param aut vetor com os nomes dos autores do livro
     * @param tem tema do livro
     * @param isbn ISBN do livro
     * @param cot cota do livro na biblioteca
     * @param np numero de paginas do livro
     * @param ed numero da edicao do livro
     * @param id codigo de identificacao do livro
     * @param ex numero total de exemplares do livro
     * @param exd numero de exemplares disponiveis do livro
     * @param id_ep vetor com os IDs de emprestimo dos exemplares do livro
     * @param dt vetor com as datas de emprestimo dos exemplares do livro
     **/
    Exemplar_indisponivel(unsigned long ind, int ano, std::string tit,
                          std::vector<std::string> aut, std::string tem,
                          long isbn, std::string cot, int np, int ed, unsigned long id, int ex,
                          int exd, std::vector<Emprestimo*> ep,
                          std::priority_queue<Pedido*> pd):
    Livro {ano, tit, aut, tem, isbn, cot, np, ed, false, id, ex, exd, ep, pd}, indice {ind} {};
    
    /**
     * @brief Funcao para obter o indice do exemplar
     *
     * @return unsigned long com o indice do exemplar.
     **/
    unsigned long get_indice();
};

/**
 * @brief Overload do operador << para imprimir um membro da classe Exemplar_indisponivel
 *
 * @param &out referencia para ostream onde sera colocada a impressao
 * @param &livro referencia do exemplar indisponivel
 *
 * @return ostream com a impressao
 **/
std::ostream& operator<<(std::ostream &out, Exemplar_indisponivel &livro);

class Exemplar_inexistente: public Livro {
   
    unsigned long indice; /**< @brief indice do exemplar do livro **/
    
public:
    
    /**
     * @brief Construtor de Exemplar_inexistente
     *
     * @param ind indice do exemplar do livro
     * @param ano ano de edicao do livro
     * @param tit titulo do livro
     * @param aut vetor com os nomes dos autores do livro
     * @param tem tema do livro
     * @param isbn ISBN do livro
     * @param cot cota do livro na biblioteca
     * @param np numero de paginas do livro
     * @param ed numero da edicao do livro
     * @param id codigo de identificacao do livro
     * @param ex numero total de exemplares do livro
     * @param exd numero de exemplares disponiveis do livro
     * @param id_ep vetor com os IDs de emprestimo dos exemplares do livro
     * @param dt vetor com as datas de emprestimo dos exemplares do livro
     **/
    Exemplar_inexistente(unsigned long ind, int ano, std::string tit,
                         std::vector<std::string> aut, std::string tem,
                         long isbn, std::string cot, int np, int ed, unsigned long id, int ex,
                         int exd, std::vector<Emprestimo*> ep,
                         std::priority_queue<Pedido*> pd):
    Livro {ano, tit, aut, tem, isbn, cot, np, ed, false, id, ex, exd, ep, pd}, indice {ind} {};
    
    /**
     * @brief Funcao para obter o indice do exemplar
     *
     * @return unsigned long com o indice do exemplar.
     **/
    unsigned long get_indice();
};

/**
 * @brief Overload do operador << para imprimir um membro da classe Exemplar_inexistente
 *
 * @param &out referencia para ostream onde sera colocada a impressao
 * @param &livro referencia do exemplar inexistente
 *
 * @return ostream com a impressao
 **/
std::ostream& operator<<(std::ostream &out, Exemplar_inexistente &livro);

/**
 * @brief Excecao Livro_emprestado
 *
 * Sempre que se tenta remover um exemplar emprestado de um livro esta excecao e utilizada.
 **/
class Livro_emprestado: public Livro {
    
    unsigned long indice; /**< @brief indice do exemplar do livro **/

public:

	/**
	 * @brief Construtor de Livro_emprestado
	 *
     * @param ind indice do exemplar do livro
     * @param ano ano de edicao do livro
     * @param tit titulo do livro
     * @param aut vetor com os nomes dos autores do livro
     * @param tem tema do livro
     * @param isbn ISBN do livro
     * @param cot cota do livro na biblioteca
     * @param np numero de paginas do livro
     * @param ed numero da edicao do livro
     * @param id codigo de identificacao do livro
     * @param ex numero total de exemplares do livro
     * @param exd numero de exemplares disponiveis do livro
     * @param id_ep vetor com os IDs de emprestimo dos exemplares do livro
     * @param dt vetor com as datas de emprestimo dos exemplares do livro
	 **/
    Livro_emprestado(unsigned long ind, int ano, std::string tit,
                     std::vector<std::string> aut, std::string tem,
                     long isbn, std::string cot, int np, int ed, unsigned long id, int ex,
                     int exd, std::vector<Emprestimo*> ep,
                     std::priority_queue<Pedido*> pd):
    Livro {ano, tit, aut, tem, isbn, cot, np, ed, false, id, ex, exd, ep, pd}, indice {ind} {};
    
    /**
     * @brief Funcao para obter o indice do exemplar
     *
     * @return unsigned long com o indice do exemplar.
     **/
    unsigned long get_indice();
};

/**
 * @brief Overload do operador << para imprimir um membro da classe Livro_emprestado
 *
 * @param &out referencia para ostream onde sera colocada a impressao
 * @param &livro referencia do livro emprestado
 *
 * @return ostream com a impressao
 **/
std::ostream& operator<<(std::ostream &out, Livro_emprestado &livro);

/**
 * @brief Excecao Emprestimos_por_devolver
 *
 * Sempre que se tenta remover um leitor com emprestimos esta excecao e utilizada.
 **/
class Emprestimos_por_devolver: public Leitor {

public:

	/**
	 * @brief Construtor de Emprestimos_por_devolver.
	 *
	 * @param id codigo de identificacao do leitor;
	 * @param nom nome do leitor;
	 * @param tel telefone do leitor;
	 * @param eml email do leitor;
	 * @param ep_lt vetor com os emprestimos do leitor
	 **/
	Emprestimos_por_devolver(unsigned long id, std::string nom, int tip, long tel, std::string eml, std::vector<Emprestimo*> ep_lt):
		Leitor {nom, tip, tel, eml, false, id, ep_lt} {};
};

/**
 * @brief Overload do operador << para imprimir um membro da classe Emprestimos_por_devolver.
 *
 * @param &out referencia para ostream onde sera colocada a impressao;
 * @param &leitor referencia do leitor com emprestimos por devolver.
 *
 * @return ostream com a impressao
 **/
std::ostream& operator<<(std::ostream &out, Emprestimos_por_devolver &leitor);

/**
 * @brief Excecao Maximo_emprestimos
 *
 * Sempre que se tenta adicionar um emprestimo a um leitor com 3 emprestimos esta excecao e utilizada.
 **/
class Maximo_emprestimos: public Leitor {

public:

	/**
	 * @brief Construtor de Maximo_emprestimos.
	 *
	 * @param id codigo de identificacao do leitor;
	 * @param nom nome do leitor;
	 * @param tel telefone do leitor;
	 * @param eml email do leitor;
	 * @param ep_lt vetor com os emprestimos do leitor
	 **/
	Maximo_emprestimos(unsigned long id, std::string nom, int tip, long tel, std::string eml, std::vector<Emprestimo*> ep_lt):
		Leitor {nom, tip, tel, eml, false, id, ep_lt} {};
};

/**
 * @brief Overload do operador << para imprimir um membro da classe Maximo_emprestimos.
 *
 * @param ostream &out referencia para ostream onde sera colocada a impressao;
 * 			   Maximo_emprestimos &leitor referencia do leitor com maximo de emprestimos atingido.
 *
 * @return ostream com a impressao
 **/
std::ostream& operator<<(std::ostream &out, Maximo_emprestimos &leitor);

/**
 * @brief Excecao Ficheiro_indisponivel.
 *
 * Sempre que se tenta aceder (para ler ou para escrever) a um ficheiro inexistente esta excecao e utilizada.
 **/
class Ficheiro_indisponivel {

	std::string ficheiro; /**< caminho para o ficheiro inexistente**/

public:

	/**
	 * @brief Construtor de Ficheiro_indisponivel.
	 *
	 * @param fch caminho para o ficheiro
	 **/
	Ficheiro_indisponivel(std::string fch): ficheiro {fch} {};

	/**
	 * @brief Funcao para obter o caminho do ficherio.
	 *
	 * @return string com o caminho
	 **/
	std::string get_ficheiro();
};

/**
 * @brief Overload do operador << para imprimir um membro da classe Ficheiro_indisponivel.
 *
 * @param &out referencia para ostream onde sera colocada a impressao;
 * @param &ficheiro referencia do ficherio indisponivel.
 *
 * @return ostream com a impressao
 **/
std::ostream& operator<<(std::ostream &out, Ficheiro_indisponivel &ficheiro);

#endif /* SRC_EXCECAO_H_ */
