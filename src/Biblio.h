#ifndef SRC_BIBLIOTECA_H_
#define SRC_BIBLIOTECA_H_

#include <list>
#include <unordered_set>
#include "Administrador.h"
#include "Supervisor.h"
#include "Emprestimo_old.h"
#include "Funcionario_old.h"
#include "Livro_old.h"
#include "Leitor_old.h"
#include "Login.h"
#include "Excecao.h"
#include "Pedido_old.h"
#include "BST.h"

class Livro_old;
class Leitor_old;
class Supervisor;
class Emprestimo_old;
class Pedido_old;
class Utilizadores;
class Login;

/** @file
 *
 * @brief Header das funcoes da Biblioteca.
 *
 * Apos os menus, estas sao as funcoes chamadas pelas varias opcoes da aplicacao.
 **/

/**
 * @brief Estrutura usada para criar tabela de dispersao de leitores
 **/
struct Leitor_Hash {
    
    /**
     * @brief funcao de dispersao
     *
     * @param lt leitor que se vai inserir na tabela
     *
     * @return unsigned long com o indice do leitor na tabela
     **/
    unsigned long operator() (const Leitor& lt) const {
        return lt.get_ID();
    }
    
    /**
     * @brief funcao que determina se dois leitores sao o mesmo
     *
     * @param lt1 primeiro leitor que se vai comparar
     * @param lt2 segundo leitor que se vai comparar
     *
     * @return bool com o resultado da comparacao
     **/
    bool operator() (const Leitor& lt1, const Leitor & lt2) const {
        return (lt1.get_ID() == lt2.get_ID());
    }
};

/**
 * @brief Tabela de dispersao de leitores
 **/
typedef std::unordered_set<Leitor, Leitor_Hash, Leitor_Hash> Hash_Leitores;

/**
 * @brief Classe com a informacao da Biblioteca.
 *
 *	E composta por livros, funcionarios (normais, supervisores ou administrador), leitores, emprestimos e utilizadores.
 *	A excecao dos utilizadores, e guardado historico de todos estes objetos em objetos do tipo _old (subclasses da respetiva
 *	classe). Por exemplo, um leitor removido nao desaparece, e guardado como leitor_old com a data em que foi removido. *
 **/
class Biblioteca {

	std::vector<Livro*> livros; /**< @brief vetor com apontadores para os livros da Biblioteca **/
	std::vector<Funcionario*> funcionarios; /**< @brief vetor com apontadores para os funcionarios da Biblioteca **/
	std::vector<Leitor*> leitores; /**< @brief vetor com apontadores para os leitores da Biblioteca **/
	std::vector<Emprestimo*> emprestimos; /**< @brief vetor com apontadores para os emprestimos da Biblioteca **/
	std::vector<Utilizador*> utilizadores; /**< @brief vetor com apontadores para os utilizadores da Biblioteca **/
    std::vector<Pedido*> pedidos; /**< @brief vetor com os apontadores para todos os pedidos de emprestimo da Biblioteca **/
    Hash_Leitores inativos; /**< @brief tabela de dispersao com os leitores inativos da Biblioteca **/
    BST<Livro> disponiveis; /**< @brief arvore binaria de pesquisa com os livros disponiveis da Biblioteca **/
public:

	/**
	 * @brief Construtor de Biblioteca
	 **/
	Biblioteca();

	/**
	 * @brief Funcao para obter todos os emprestimos atrasados da Biblioteca
	 *
	 * @return vector<Emprestimo*> com os apontadores para os emprestimos atrasados

	 **/
	std::vector<Emprestimo*> get_emprestimos_atrasados() const;

	/**
	 * @brief Funcao que imprime os emprestimos atrasados por leitor para que os leitores posssam ser contactados
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime_emprestimos_atrasados() const;

	/**
	 * @brief Funcao para obter os livros antigos da Biblioteca
	 *
	 * @return vector<Livro_old*> com os apontadores para os livros antigos da biblioteca
	 **/
	std::vector<Livro_old*> get_livros_old() const;

	/**
	 * @brief Funcao para obter os livros da Biblioteca
	 *
	 * @return vector<Livro*> com os apontadores para os livros da biblioteca
	 **/
	std::vector<Livro*> get_livros() const;

	/**
	 * @brief Funcao para obter os emprestimos antigos da Biblioteca
	 *
	 * @return vector<Emprestimo_old*> com os apontadores para os emprestimos antigos
	 **/
	std::vector<Emprestimo_old*> get_emprestimos_old() const;

	/**
	 * @brief Funcao para obter os emprestimos atuais da Biblioteca
	 *
	 * @return vector<Emprestimo*> com os apontadores para os emprestimos atuais
	 **/
	std::vector<Emprestimo*> get_emprestimos() const;

	/**
	 * @brief Funcao para obter os funcionarios antigos da Biblioteca
	 *
	 * @return vector<Fucionario_old*> com os apontadores para os funcionarios antigos
	 **/
	std::vector<Funcionario_old*> get_funcionarios_old() const;

	/**
	 * @brief Funcao para obter os funcionarios da Biblioteca
	 *
	 * @return vector<Fucionario*> com os apontadores para os funcionarios
	 **/
	std::vector<Funcionario*> get_funcionarios_todos() const;

	/**
	 * @brief Funcao para obter os supervisores da Biblioteca
	 *
	 * @return vector<Funcionario*> com os apontadores para os supervisores
	 **/
	std::vector<Funcionario*> get_supervisores() const;

	/**
	 * @brief Funcao para obter os funcionarios nao supervisores da Biblioteca
	 *
	 * @return vector<Funcionario*> com os apontadores para os funcionarios nao supervisores da biblioteca
	 **/
	std::vector<Funcionario*> get_funcionarios() const;

	/**
	 * @brief Funcao para obter os leitores antigos da Biblioteca
	 *
	 * @return vector<Leitor_old*> com os apontadores para os leitores antigos da biblioteca
	 **/
	std::vector<Leitor_old*> get_leitores_old() const;

	/**
	 * @brief Funcao para obter os leitores da Biblioteca
	 *
	 * @return vector<Leitor*> com os apontadores para os leitores da biblioteca
	 **/
	std::vector<Leitor*> get_leitores() const;

	/**
	 * @brief Funcao para obter os utilizadores da Biblioteca
	 *
	 * @return vector<Utilizador*> com os apontadores para os utilizadores da biblioteca
	 **/
	std::vector<Utilizador*> get_utilizadores() const;
    
    /**
     * @brief Funcao para obter os pedidos antigos da Biblioteca
     *
     * @return vector<Pedido*> com os apontadores para os pedidos antigos da biblioteca
     **/
    std::vector<Pedido_old*> get_pedidos_old() const;
    
    /**
     * @brief Funcao para obter os pedidos da Biblioteca
     *
     * @return vector<Pedido*> com os apontadores para os pedidos da biblioteca
     **/
    std::vector<Pedido*> get_pedidos() const;
    
	/**
	 * @brief Funcao para adicionar um livro antigo a Biblioteca
	 *
	 * @param lv apontador para o livro antigo
	 **/
	void adiciona_livro_old(Livro_old* lv);

	/**
	 * @brief Funcao para adicionar um novo livro a Biblioteca
	 *
	 * @param lv apontador para o novo livro
	 **/
	void adiciona_livro(Livro* lv);

    /**
     * @brief Funcao para adicionar um novo exemplar de um livro a Biblioteca
     *
     * @param id ID do livro ao qual queremos adicionar um exemplar
     *
     * @return apontador para o livro ao qual adicionamos um exemplar
     *
     * @exception Object_nao_existe se nao existe nenhum livro com o id fornecido
     **/
    Livro* adiciona_exemplar(const unsigned long id);
    
	/**
	 * @brief Funcao para adicionar um funcionario antigo a Biblioteca
	 *
	 * @param fc apontador para o funcionario antigo
	 **/
	void adiciona_funcionario_old(Funcionario_old* fc);

	/**
	 * @brief Funcao para adicionar um novo funcionario a Biblioteca
	 *
	 * @param fc apontador para o novo funcionario
	 **/
	void adiciona_funcionario(Funcionario* fc);

	/**
	 * @brief Funcao para adicionar um leitor antigo a Biblioteca
	 *
	 * @param lt apontador para o leitor antigo
	 **/
	void adiciona_leitor_old(Leitor_old* lt);

	/**
	 * @brief Funcao para adicionar um novo leitor a Biblioteca
	 *
	 * @param lt apontador para o novo leitor
	 **/
	void adiciona_leitor(Leitor* lt);

	/**
	 * @brief Funcao para adicionar um emprestimo antigo a Biblioteca
	 *
	 * @param ep apontador para o emprestimo antigo
	 **/
	void adiciona_emprestimo_old(Emprestimo_old* ep);

	/**
	 * @brief Funcao para adicionar um novo emprestimo a Biblioteca
	 *
	 * @param ep apontador para o novo emprestimo
     *
     * @exception Maximo_emprestimos se leitor ja tem 3 emprestimos
     * @exception Exemplar_indisponivel se o exemplar ja esta emprestado
     * @exception Exemplar_inexistente se o exemplar nao existe
	 **/
	void adiciona_emprestimo(Emprestimo* ep);

	/**
	 * @brief Funcao para adicionar um novo emprestimo a Biblioteca
	 *
	 * @param id_lv identificacao do livro do emprestimo
	 * @param id_lt identificacao do leitor do emprestimo
	 * @param id_fc identificacao do funcionario do emprestimo
     *
     * @exception Object_nao_existe se nao existe livro com identificacao id_lv
     * @exception Object_nao_existe se nao existe leitor com identificacao id_lt
     * @exception Object_nao_existe se nao existe funcionario com identificacao id_fc
     * @exception Livro_indisponivel se todos os exemplares do livro estao emprestados
     * @exception Exemplar_inexistente se o exemplar nao existe
	 **/
	void adiciona_emprestimo_ids(const unsigned long id_lv, const unsigned long id_lt,
                                 const unsigned long id_fc);

    /**
	 * @brief Funcao para adicionar um novo utilizador a Biblioteca
	 *
	 * @param ut apontador para o novo utilizador
	 **/
	void adiciona_utilizador(Utilizador* ut);
    
    /**
     * @brief Funcao para adicionar um novo pedido a Biblioteca
     *
     * @param pd apontador para o novo pedido
     *
     * @exception Livro_disponivel se existe pelo menos um exemplar disponivel para emprestar
     **/
    void adiciona_pedido(Pedido* pd);
    
    /**
     * @brief Funcao para adicionar um novo pedido a Biblioteca
     *
     * @param id_lv identificacao do livro do pedido
     * @param id_lt identificacao do leitor do pedido
     * @param id_fc identificacao do funcionario do pedido
     *
     * @exception Object_nao_existe se nao existe livro com identificacao id_lv
     * @exception Object_nao_existe se nao existe leitor com identificacao id_lt
     * @exception Object_nao_existe se nao existe funcionario com identificacao id_fc
     * @exception Livro_disponivel se existe pelo menos um exemplar disponivel para emprestar
     **/
    void adiciona_pedido_ids(const unsigned long id_lv, const unsigned long id_lt,
                             const unsigned long id_fc);
    
    /**
     * @brief Funcao para adicionar um pedido antigo a Biblioteca
     *
     * @param pd apontador para o pedido antigo
     **/
    void adiciona_pedido_old(Pedido_old* pd);

	/**
	 * @brief Funcao para remover um exemplar de um livro da Biblioteca
	 *
	 * @param id identificacao do livro cujo exemplar queremos remover
     * @param ind indice do exemplar do livro que queremos remover
	 *
	 * @return true se existe algum livro com o id fornecido
	 *
	 * @exception Object_nao_existe se nao existe nenhum livro com o id fornecido
	 *
	 * Nota: remove o exemplar do primeiro livro com o id indicado.
	 **/
	bool remove_livro(const unsigned long id, const unsigned long ind);

	/**
	 * @brief Funcao para remover um funcionario da Biblioteca
	 *
	 * @param lond id identificacao do funcionario que queremos remover
	 *
	 * @return true se existe algum funcionario com o id fornecido
	 *
	 * @exception Object_nao_existe se nao existe nenhum funcionario com o id fornecido
	 *
	 * Nota: remove o primeiro funcionario com o id indicado.
	 **/
	bool remove_funcionario(const unsigned long id);

	/**
	 * @brief Funcao para remover um leitor da Biblioteca
	 *
	 * @param lond id identificacao do leitor que queremos remover
	 *
	 * @return true se existe algum leitor com o id fornecido
	 *
	 * @exception Object_nao_existe se nao existe nenhum leitor com o id fornecido
	 *
	 * Nota: remove o primeiro leitor com o id indicado.
	 **/
	bool remove_leitor(const unsigned long id);

	/**
	 * @brief Funcao para remover um emprestimo da Biblioteca
	 *
	 * @param lond id identificacao do emprestimo que queremos remover
	 *
	 * @return Apontador para o emprestimo removido se existe algum emprestimo com o id fornecido
	 *
	 * @exception Object_nao_existe se nao existe nenhum emprestimo com o id fornecido
	 *
	 * Nota: remove o primeiro emprestimo com o id indicado.
	 **/
	Emprestimo* remove_emprestimo(const unsigned long id);

	/**
	 * @brief Funcao para remover um utilizador da Biblioteca
	 *
	 * @param lond id identificacao do utilizador que queremos remover
	 *
	 * @return true se existe algum utilizador com o id fornecido
	 *
	 * @exception Object_nao_existe se nao existe nenhum utilizador com o id fornecido
	 *
	 * Nota: remove o primeiro utilizador com o id indicado.
	 **/
	bool remove_utilizador(const unsigned long id);
    
    /**
     * @brief Funcao para remover um pedido da Biblioteca
     *
     * @param lond id identificacao do pedido que queremos remover
     *
     * @return true se existe algum pedido com o id fornecido
     *
     * @exception Object_nao_existe se nao existe nenhum pedido com o id fornecido
     * @exception Pedido_nao_prioritario se o pedido nao e o primeiro da fila do livro
     *
     * Nota: remove o primeiro pedido com o id indicado.
     **/
    bool remove_pedido(const unsigned long id);
    
    /**
     * @brief Funcao para desistir de um pedido da Biblioteca
     *
     * @param lond id identificacao do pedido que queremos remover
     *
     * @return true se existe algum pedido com o id fornecido
     *
     * @exception Object_nao_existe se nao existe nenhum pedido com o id fornecido
     *
     * Nota: remove o primeiro pedido com o id indicado.
     **/
    bool desiste_pedido(const unsigned long id);

	/**
	 * @brief Funcao para distribuir uniformemente os funcionarios pelos supervisores
	 *
	 * No final o numero de funcionarios por supervisor e o mais equilibrado possivel.
	 **/
	void distribui_funcionarios();

	/**
	 * @brief Funcao para promover um funcionario a supervisor
	 *
	 * @param unsigned long id identificacao do funcionario que pretendemos promover
	 *
	 * @return true se existe um funcionario com o id fornecido
	 *
	 * @exception Object_nao_existe se nao existe nenhum funcionario com o id fornecido
	 *
	 * Notas: - promove o primeiro funcionario com o id indicado;
	 * 		  - no final os funcionarios sao redistribuidos, pelo que se mantem o equlibrio
	 *  	  	 entre o numero de funcionarios por supervisor.
	 **/
	bool promove_funcionario_supervisor(const unsigned long id);

	/**
	 * @brief Funcao para despromover um supervisor a funcionario
	 *
	 * @param unsigned long id identificacao do supervisor que pretendemos despromover
	 *
	 * @return true se existe um supervisor com o id fornecido
	 *
	 * @exception Object_nao_existe se nao existe nenhum supervisor com o id fornecido
	 *
	 * Notas: - despromove o primeiro supervisor com o id indicado;
	 * 		   - no final os funcionarios sao redistribuidos, pelo que se mantem o equlibrio
	 *  		 entre o numero de funcionarios por supervisor.
	 **/
	bool despromove_supervisor_funcionorario(const unsigned long id);

	/**
	 * @brief Funcao que imprime todos os livros antigos da Biblioteca
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime_livros_old() const;

	/**
	 * @brief Funcao que imprime todos os livros da Biblioteca
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime_livros() const;

	/**
	 * @brief Funcao que imprime os livros da Biblioteca com um determinado tema
	 *
	 * @param tem tema pretendido
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime_livros_tema(const std::string tem) const;

	/**
	 * @brief Funcao que imprime todos os livros emprestados da Biblioteca
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime_livros_emprestados() const;

	/**
	 * @brief Funcao que imprime todos os livros disponiveis (nao emprestados) da Biblioteca
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime_livros_disponiveis() const;

	/**
	 * @brief Funcao que imprime todos os funcionarios antigos da Biblioteca
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime_funcionarios_old() const;

	/**
	 * @brief Funcao que imprime todos os funcionarios da Biblioteca
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime_funcionarios() const;

	/**
	 * @brief Funcao que imprime todos os supervisores da Biblioteca
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime_supervisores() const;
    
    /**
     * @brief Funcao que imprime todos os leitores inativos da Biblioteca
     *
     * @return string com o resultado da impressao
     **/
    std::string imprime_leitores_inativos() const;

	/**
	 * @brief Funcao que imprime todos os leitores antigos da Biblioteca
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime_leitores_old() const;

	/**
	 * @brief Funcao que imprime todos os leitores da Biblioteca
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime_leitores() const;

	/**
	 * @brief Funcao que imprime todos os emprestimos antigos da Biblioteca
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime_emprestimos_old() const;

	/**
	 * @brief Funcao que imprime todos os emprestimos da Biblioteca
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime_emprestimos() const;

	/**
	 * @brief Funcao que imprime todos os utilizadores da Biblioteca
	 *
	 * @return string com o resultado da impressao
	 *
	 * Nota: nao imprime a password dos utilizadores
	 **/
	std::string imprime_utilizadores() const;
    
    /**
     * @brief Funcao que imprime todos os pedidos antigos da Biblioteca
     *
     * @return string com o resultado da impressao
     **/
    std::string imprime_pedidos_old() const;
    
    /**
     * @brief Funcao que imprime todos os pedidos da Biblioteca
     *
     * @return string com o resultado da impressao
     **/
    std::string imprime_pedidos() const;

	/**
	 * @brief Funcao que imprime todos os livros, funcionarios, supervisores, leitores, emprestimos e
     * pedidos da Biblioteca
	 *
	 * @return string com o resultado da impressao
	 **/
	std::string imprime() const;

	/* codigo desnecessario

	void set_emprestimos(std::vector<Emprestimo*> emp);

	void set_funcionarios(std::vector<Funcionario*> func);

	void set_leitores(std::vector<Leitor*> leit);

	void set_utilizadores(std::vector<Utilizador*> util);

	void set_livros(std::vector<Livro*> livr);

	*/

	/**
	 * @brief Funcao para obter os temas dos livros da Biblioteca
	 *
	 * @return vector<string> com os temas dos livros da Biblioteca
	 **/
	std::vector<std::string> get_temas() const;

	/**
	 * @brief Funcao para obter os livros com um determinado tema da Biblioteca
	 *
	 * @param tem tema escolhido.
	 *
	 * @return vector<Livro*> com os apontadores para os livros com tema tem
	 **/
	std::vector<Livro*> get_livros_tema(const std::string tem) const;

	/**
	 * @brief Funcao para obter os livros disponiveis (nao emprestados) da Biblioteca
	 *
	 * @return vector<Livro*> com os apontadores para os livros disponiveis
	 **/
	std::vector<Livro*> get_livros_disponiveis() const;

	/**
	 * @brief Funcao para obter os livros emprestados da Biblioteca
	 *
	 * @return vector<Livro*> com os apontadores para os livros emprestados
	 **/
	std::vector<Livro*> get_livros_emprestados() const;

	/**
	 * @brief Funcao que escreve todos os livros antigos da Biblioteca para um ficheiro
	 *
	 * @param ficheiro contem o caminho para o ficheiro onde queremos escrever
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void escreve_livros_old(const std::string ficheiro) const;

	/**
	 * @brief Funcao que escreve todos os livros da Biblioteca para um ficheiro
	 *
	 * @param ficheiro contem o caminho para o ficheiro onde queremos escrever
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void escreve_livros(const std::string ficheiro) const;

	/**
	 * @brief Funcao que escreve os funcionarios antigos da Biblioteca para um ficheiro
	 *
	 * @param ficheiro contem o caminho para o ficheiro onde queremos escrever
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void escreve_funcionarios_old(const std::string ficheiro) const;

	/**
	 * @brief Funcao que escreve os funcionarios da Biblioteca
	 *
	 * @param ficheiro contem o caminho para o ficheiro onde queremos escrever
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void escreve_funcionarios(const std::string ficheiro) const;

	/**
	 * @brief Funcao que escreve os supervisores da Biblioteca
	 *
	 * @param ficheiro contem o caminho para o ficheiro onde queremos escrever
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void escreve_supervisores(const std::string ficheiro) const;

	/**
	 * @brief Funcao que escreve todos os leitores antigos da Biblioteca para um ficheiro
	 *
	 * @param string ficheiro contem o caminho para o ficheiro onde queremos escrever
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void escreve_leitores_old(const std::string ficheiro) const;

	/**
	 * @brief Funcao que escreve todos os leitores da Biblioteca para um ficheiro
	 *
	 * @param string ficheiro contem o caminho para o ficheiro onde queremos escrever
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void escreve_leitores(const std::string ficheiro) const;

	/**
	 * @brief Funcao que escreve todos os emprestimos antigos da Biblioteca para um ficheiro
	 *
	 * @param ficheiro contem o caminho para o ficheiro onde queremos escrever
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void escreve_emprestimos_old(const std::string ficheiro) const;

	/**
	 * @brief Funcao que escreve todos os emprestimos da Biblioteca para um ficheiro
	 *
	 * @param ficheiro contem o caminho para o ficheiro onde queremos escrever
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void escreve_emprestimos(const std::string ficheiro) const;

	/**
	 * @brief Funcao que escreve todos os utilizadores da Biblioteca para um ficheiro
	 *
	 * @param ficheiro contem o caminho para o ficheiro onde queremos escrever
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void escreve_utilizadores(const std::string ficheiro) const;
    
    /**
     * @brief Funcao que escreve todos os pedidos antigos da Biblioteca para um ficheiro
     *
     * @param ficheiro contem o caminho para o ficheiro onde queremos escrever
     *
     * @exception Ficheiro_indisponivel se o ficheiro nao existir
     **/
    void escreve_pedidos_old(const std::string ficheiro) const;
    
    /**
     * @brief Funcao que escreve todos os pedidos da Biblioteca para um ficheiro
     *
     * @param ficheiro contem o caminho para o ficheiro onde queremos escrever
     *
     * @exception Ficheiro_indisponivel se o ficheiro nao existir
     **/
    void escreve_pedidos(const std::string ficheiro) const;

	/**
	 * @brief Funcao que escreve toda a informacao da Biblioteca para 12 ficheiros
	 *
	 * @param ficheiro_lvo contem o caminho para o ficheiro onde queremos escrever os livros antigos
	 * @param ficheiro_lv contem o caminho para o ficheiro onde queremos escrever os livros
	 * @param ficheiro_fco contem o caminho para o ficheiro onde queremos escrever os funcionarios antigos
	 * @param ficheiro_fc contem o caminho para o ficheiro onde queremos escrever os funcionarios
	 * @param ficheiro_sp contem o caminho para o ficheiro onde queremos escrever os supervisores
	 * @param ficheiro_lto contem o caminho para o ficheiro onde queremos escrever os leitores antigos
	 * @param ficheiro_lt contem o caminho para o ficheiro onde queremos escrever os leitores
	 * @param ficheiro_epo contem o caminho para o ficheiro onde queremos escrever os emprestimos antigos
	 * @param ficheiro_ep contem o caminho para o ficheiro onde queremos escrever os emprestimos
	 * @param ficheiro_ut contem o caminho para o ficheiro onde queremos escrever os utilizadores
     * @param ficheiro_pdo contem o caminho para o ficheiro onde queremos escrever os pedidos antigos
     * @param ficheiro_pd contem o caminho para o ficheiro onde queremos escrever os pedidos
	 *
	 * @exception Ficheiro_indisponivel se algum ficheiro nao existir
	 **/
	void escreve(const std::string ficheiro_lvo, const std::string ficheiro_lv,
                 const std::string ficheiro_fco, const std::string ficheiro_fc,
                 const std::string ficheiro_sp, const std::string ficheiro_lto,
                 const std::string ficheiro_lt, const std::string ficheiro_epo,
                 const std::string ficheiro_ep, const std::string ficheiro_ut,
                 const std::string ficheiro_pdo, const std::string ficheiro_pd) const;

	/**
	 * @brief Funcao que le todos os livros antigos de um ficheiro e os adiciona a Biblioteca
	 *
	 * @param ficheiro contem o caminho para o ficheiro de onde queremos ler
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void le_livros_old(const std::string ficheiro);

	/**
	 * @brief Funcao que le todos os livros de um ficheiro e os adiciona a Biblioteca
	 *
	 * @param ficheiro contem o caminho para o ficheiro de onde queremos ler
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void le_livros(const std::string ficheiro);

	/**
	 * @brief Funcao que le os funcionarios antigos de um ficheiro e os adiciona a Biblioteca
	 *
	 * @param ficheiro contem o caminho para o ficheiro de onde queremos ler
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void le_funcionarios_old(const std::string ficheiro);

	/**
	 * @brief Funcao que le os funcionarios de um ficheiro e os adiciona a Biblioteca
	 *
	 * @param ficheiro contem o caminho para o ficheiro de onde queremos ler
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void le_funcionarios(const std::string ficheiro);

	/**
	 * @brief Funcao que le os supervisores de um ficheiro e os adiciona a Biblioteca
	 *
	 * @param ficheiro contem o caminho para o ficheiro de onde queremos ler
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void le_supervisores(const std::string ficheiro);

	/**
	 * @brief Funcao que le todos os leitores antigos de um ficheiro e os adiciona a Biblioteca
	 *
	 * @param ficheiro contem o caminho para o ficheiro de onde queremos ler
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void le_leitores_old(const std::string ficheiro);

	/**
	 * @brief Funcao que le todos os leitores de um ficheiro e os adiciona a Biblioteca
	 *
	 * @param ficheiro contem o caminho para o ficheiro de onde queremos ler
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void le_leitores(const std::string ficheiro);

	/**
	 * @brief Funcao que le todos os emprestimos antigos de um ficheiro e os adiciona a Biblioteca
	 *
	 * @param ficheiro contem o caminho para o ficheiro de onde queremos ler
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void le_emprestimos_old(const std::string ficheiro);

	/**
	 * @brief Funcao que le todos os emprestimos de um ficheiro e os adiciona a Biblioteca
	 *
	 * @param ficheiro contem o caminho para o ficheiro de onde queremos ler
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 *
	 * Nota: E atualizada a informacao sobre emprestimos nos leitores e nos livros.
	 **/
	void le_emprestimos(const std::string ficheiro);

	/**
	 * @brief Funcao que le todos os utilizadores de um ficheiro e os adiciona a Biblioteca
	 *
	 * @param string ficheiro contem o caminho para o ficheiro de onde queremos ler
	 *
	 * @exception Ficheiro_indisponivel se o ficheiro nao existir
	 **/
	void le_utilizadores(const std::string ficheiro);
    
    /**
     * @brief Funcao que le todos os pedidos antigos de um ficheiro e os adiciona a Biblioteca
     *
     * @param ficheiro contem o caminho para o ficheiro de onde queremos ler
     *
     * @exception Ficheiro_indisponivel se o ficheiro nao existir
     **/
    void le_pedidos_old(const std::string ficheiro);
    
    /**
     * @brief Funcao que le todos os pedidos de um ficheiro e os adiciona a Biblioteca
     *
     * @param ficheiro contem o caminho para o ficheiro de onde queremos ler
     *
     * @exception Ficheiro_indisponivel se o ficheiro nao existir
     *
     * Nota: E atualizada a informacao sobre pedidos nos livros.
     **/
    void le_pedidos(const std::string ficheiro);

	/**
	 * @brief Funcao que le toda a informacao de 12 ficheiros e adiciona a Biblioteca
	 *
	 * @param ficheiro_lvo contem o caminho para o ficheiro onde queremos ler os livros antigos
	 * @param ficheiro_lv contem o caminho para o ficheiro onde queremos ler os livros
	 * @param ficheiro_fco contem o caminho para o ficheiro onde queremos ler os funcionarios antigos
	 * @param ficheiro_fc contem o caminho para o ficheiro onde queremos ler os funcionarios
	 * @param ficheiro_sp contem o caminho para o ficheiro onde queremos ler os supervisores
	 * @param ficheiro_lto contem o caminho para o ficheiro onde queremos ler os leitores antigos
	 * @param ficheiro_lt contem o caminho para o ficheiro onde queremos ler os leitores
	 * @param ficheiro_epo contem o caminho para o ficheiro onde queremos ler os emprestimos antigos
	 * @param ficheiro_ep contem o caminho para o ficheiro onde queremos ler os emprestimos
	 * @param ficheiro_ut contem o caminho para o ficheiro onde queremos ler os utilizadores
     * @param ficheiro_pdo contem o caminho para o ficheiro onde queremos ler os pedidos antigos
     * @param ficheiro_pd contem o caminho para o ficheiro onde queremos ler os pedidos
	 *
	 * @exception Ficheiro_indisponivel se algum ficheiro nao existir
	 **/
    void le(const std::string ficheiro_lvo, const std::string ficheiro_lv,
            const std::string ficheiro_fco, const std::string ficheiro_fc,
            const std::string ficheiro_sp, const std::string ficheiro_lto,
            const std::string ficheiro_lt, const std::string ficheiro_epo,
            const std::string ficheiro_ep, const std::string ficheiro_ut,
            const std::string ficheiro_pdo, const std::string ficheiro_pd);
    
    /**
     * @brief Funcao que adiciona os leitores inativos a tabela de dispersao da Biblioteca
     *
     * Nota: A tabela e criada de novo e depois sao adicionados os leitores inativos.
     **/
    void adiciona_inativos();
    
    /**
     * @brief Funcao que adiciona um leitor inativo a tabela de dispersao
     *
     * @param lt leitor que pretendemos adicionar
     **/
    void adiciona_inativo(const Leitor& lt);
    
    /**
     * @brief Funcao que remove um leitor da tabela de dispersao de leitores inativos
     *
     * @param id identificacao do leitor que pretendemos remover
     *
     * @return true se encontrar o leitor com o id pretendido e false caso contrario
     **/
    bool remove_inativo(const Leitor& lt);

    /**
     * @brief Funcao que adiciona os livros disponiveis a BST da Biblioteca
     *
     * Nota: A arvore e reinicializada e depois sao adicionados os livros disponiveis.
     **/
    void adiciona_disponiveis();
    
    /**
     * @brief Funcao que adiciona um livro a BST de livros disponiveis
     *
     * @param lv livro que pretendemos adicionar
     **/
    void adiciona_disponivel(const Livro& lv);
    
    /**
     * @brief Funcao que remove um livro da BST de livros disponiveis
     *
     * @param id identificacao do livro que pretendemos remover
     *
     * @return true se encontrar o livro com o id pretendido e false caso contrario
     **/
    void remove_disponivel(const Livro& lv);
};

#endif /* SRC_BIBLIOTECA_H_ */
