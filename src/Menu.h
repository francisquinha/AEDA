#ifndef SRC_MENU_H_
#define SRC_MENU_H_

#include <string>
#include <vector>
#include <unistd.h>

#include "Biblio.h"

/** @file
 *
 * @brief Header das classes relacionadas com o Menu da aplicacao.
 *
 * Toda a interacao do utilizador com o programa e feita atraves destes menus.
 **/

/**
 * @brief Classe com o nivel de acesso e o ID do utilizador ligado ao sistema
 *
 * Quando um utilizador faz login, fica registado aqui o seu ID e o seu nivel de acesso.
 * E ainda registado que esta alguem ligado no booleano online que fica true.
 **/
class Utilizador_online: public Object  {

    int acesso; /**< @brief nivel de acesso do utilizador **/

public:

    bool online {false}; /**< @brief indica se esta algum utilizador ligado **/

	/**
	 * @brief Construtor de Utilizador_online
	 *
	 * @param id codigo de identificacao do utilizador
	 * @param acess nivel de acesso do utilizador
	 **/
    Utilizador_online(long id, int ace);

	/**
	 * @brief Funcao para obter o nivel de acesso do Utilizador_online
	 *
	 * @return string com a password do utilizador
	 **/
    int get_acesso();
};

/**
 * @brief Classe todas as funcoes a que os utilizadores podem aceder
 *
 * Mantem o registo do utilizador_online no momento. Consoante a sequencia de opcoes do utilizador
 * mostra a informacao solicitada ou adiciona, remove ou altera o objeto escolhido.
 **/
class Menu: public Biblioteca {

    Utilizador_online* utilizador_online; /**< @brief utilizador ligado ao sistema no momento **/

	/**
	 * @brief Funcao para determinar se uma determinada string e um numero ou nao
	 *
	 * @param num string que pretendemos determinar se e um numero
	 *
	 * @return bool true se e numero, false caso contrario
	 **/
    bool e_numero(std::string num);

public:

	/**
	 * @brief Construtor de Menu
	 *
	 * @param util utilizador online no momento
	 **/
    Menu(Utilizador_online* util);

	/**
	 * @brief Funcao para determinar o utilizador_online
	 *
	 * @param util apontador para o utilizador_online que pretendemos colocar
	 **/
    void set_utilizador(Utilizador_online* util);

	/**
	 * @brief Funcao obter o utilizador_online
	 *
	 * @return Utilizador_online* com o apontador para o utilizador do momento
	 **/
	Utilizador_online* get_utilizador();

	/**
	 * @brief Funcao que efetua login de um novo utilizador
	 *
	 * @param id identificacao do utilizador
	 * @param pass password do utilizador
	 *
	 * @return int com o nivel de acesso se o id e a pass corresponderem a um utilizador existente, -1 caso contrario
	 **/
    int efectuar_login(long id, std::string pass);

	/**
	 * @brief Menu inicial usado para fazer login
	 *
	 * @return int com o nivel de acesso se o login for efetuado corretamente em 3 tentativas, -1 caso contrario
	 **/
    int menu_login();

	/**
	 * @brief Menu principal com as opcoes de consulta, emprestimos, livros, leitores, funcionarios e utilizadores
	 *
	 * As opcoes que mostra variam consoante o nivel de acesso do utilizador_online:
	 * 0 - todas;
	 * 1 e 2 - consulta, emprestimos, livros, leitores.
	 **/
    void menu_principal();

	/**
	 * @brief Menu consultas com as opcoes livros, emprestimos, leitores, funcionarios, supervisores e utilizadores
	 *
	 * Este menu aparece se for escolhida a opcao 1 no menu principal.
	 * Todas as opcoes estao disponiveis independentemente do nivel de acesso do utilizador_online.
	 **/
    void menu_consultas();

	/**
	 * @brief Menu emprestimos com as opcoes adicionar, devolver, consultar atrasos, consultar atrasos por leitor,
	 * consultar livros atrasados e consultar antigos
	 *
	 * Este menu aparece se for escolhida a opcao 2 no menu principal.
	 * Todas as opcoes estao disponiveis independentemente do nivel de acesso do utilizador_online.
	 **/
    void menu_emprestimos();

	/**
	 * @brief Menu livros com as opcoes consultar disponiveis, consultar emprestados, consultar por tema,
	 * consultar antigos, adicionar e remover
	 *
	 * Este menu aparece se for escolhida a opcao 3 no menu principal.
	 * As opcoes que mostra variam consoante o nivel de acesso do utilizador_online.
	 * 0 e 1 - Todas;
	 * 2 - Consultas.
	 **/
    void menu_livros();

	/**
	 * @brief Menu leitores com as opcoes adicionar, remover, alterar e consultar antigos
	 *
	 * Este menu aparece se for escolhida a opcao 4 no menu principal.
	 * Todas as opcoes estao disponiveis independentemente do nivel de acesso do utilizador_online.
	 **/
    void menu_leitores();

	/**
	 * @brief Menu funcionarios com as opcoes adicionar, remover, promover, despromover e consultar antigos
	 *
	 * Este menu aparece se for escolhida a opcao 5 no menu principal.
	 * So esta disponivel para o utilizador de nivel 0.
	 **/
    void menu_funcionarios();

	/**
	 * @brief Menu utilizadores com as opcoes adicionar e remover
	 *
	 * Este menu aparece se for escolhida a opcao 6 no menu principal.
	 * So esta disponivel para o utilizador de nivel 0.
	 **/
    void menu_utilizadores();

	/**
	 * @brief Imprime no ecra todos os livros atuais da biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 1 no menu consultas (caminho 1->1 do menu principal).
	 * Acessivel a todos os utilizadores.
	 **/
    void consulta_livros();

	/**
	 * @brief Imprime no ecra todos os emprestimos atuais da biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 2 no menu consultas (caminho 1->2 do menu principal).
	 * Acessivel a todos os utilizadores.
	 **/
    void consulta_emprestimos();

	/**
	 * @brief Imprime no ecra todos os emprestimos atuais da biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 3 no menu consultas (caminho 1->3 do menu principal).
	 * Acessivel a todos os utilizadores.
	 **/
    void consulta_leitores();

	/**
	 * @brief Imprime no ecra todos os funcionarios atuais da biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 4 no menu consultas (caminho 1->4 do menu principal).
	 * Acessivel a utilizadores de niveis 0 e 1.
	 **/
    void consulta_funcionarios();

	/**
	 * @brief Imprime no ecra todos os supervisores atuais da biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 5 no menu consultas (caminho 1->5 do menu principal).
	 * Acessivel a utilizadores de niveis 0 e 1.
	 **/
    void consulta_supervisores();

	/**
	 * @brief Imprime no ecra todos os utilizadores da biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 6 no menu consultas (caminho 1->6 do menu principal).
	 * Acessivel apenas ao utilizador de nivel 0.
	 **/
    void consulta_utilizadores();

	/**
	 * @brief Permite adicionar um emprestimo a biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 1 no menu emprestimos (caminho 2->1 do menu principal).
	 * Acessivel a todos os utilizadores.
	 * Pede para indicar os ID do livro e do leitor. Determina se e possivel adicionar e se nao for
	 * imprime no ecra o motivo.
	 **/
    void emprestimos_adicionar();

	/**
	 * @brief Permite devolver um emprestimo na biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 2 no menu emprestimos (caminho 2->2 do menu principal).
	 * Acessivel a todos os utilizadores.
	 * Pede para indicar o ID do emprestimo. Determina se e possivel devolver e se nao for
	 * imprime no ecra o motivo.
	 **/
    void emprestimos_remover();

	/**
	 * @brief Imprime no ecra todos os emprestimos atrasados da biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 3 no menu emprestimos (caminho 2->3 do menu principal).
	 * Acessivel a todos os utilizadores.
	 **/
    void emprestimos_atrasados();

	/**
	 * @brief Imprime no ecra todos os emprestimos atrasados organizados por leitor, do qual imprime a informacao
	 *
	 * Funcao chamada se for escolhida a opcao 4 no menu emprestimos (caminho 2->4 do menu principal).
	 * Acessivel a todos os utilizadores.
	 **/
    void emprestimos_atrasados_leitores();

	/**
	 * @brief Imprime no ecra todos os livros de emprestimos atrasados
	 *
	 * Funcao chamada se for escolhida a opcao 5 no menu emprestimos (caminho 2->5 do menu principal).
	 * Acessivel a todos os utilizadores.
	 **/
    void emprestimos_atrasados_livros();

	/**
	 * @brief Imprime no ecra todos os emprestimos antigos
	 *
	 * Funcao chamada se for escolhida a opcao 6 no menu emprestimos (caminho 2->6 do menu principal).
	 * Acessivel a todos os utilizadores.
	 **/
    void emprestimos_antigos();

	/**
	 * @brief Imprime no ecra todos os livros disponiveis
	 *
	 * Funcao chamada se for escolhida a opcao 1 no menu livros (caminho 3->1 do menu principal).
	 * Acessivel a todos os utilizadores.
	 **/
    void livros_disponiveis();

	/**
	 * @brief Imprime no ecra todos os livros emprestados
	 *
	 * Funcao chamada se for escolhida a opcao 2 no menu livros (caminho 3->2 do menu principal).
	 * Acessivel a todos os utilizadores.
	 **/
    void livros_emprestados();

	/**
	 * @brief Imprime no ecra todos os livros de um determinado tema
	 *
	 * Funcao chamada se for escolhida a opcao 3 no menu livros (caminho 3->3 do menu principal).
	 * Acessivel a todos os utilizadores.
	 * Imprime os temas disponiveis para o utilizador escolher.
	 **/
    void livros_tema();

	/**
	 * @brief Imprime no ecra todos os livros antigos
	 *
	 * Funcao chamada se for escolhida a opcao 4 no menu livros (caminho 3->4 do menu principal).
	 * Acessivel a todos os utilizadores.
	 **/
    void livros_antigos();

	/**
	 * @brief Permite adicionar um livro a biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 5 no menu emprestimos (caminho 3->5 do menu principal).
	 * Acessivel apenas a utilizadores de niveis 0 e 1.
	 * Pede para indicar: titulo, autores, tema, ISBN, cota, num. paginas e edicao.
	 **/
    void livros_adicionar();

	/**
	 * @brief Permite remover um livro da biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 6 no menu livros (caminho 3->6 do menu principal).
	 * Acessivel apenas a utilizadores de niveis 0 e 1.
	 * Pede para indicar o ID do livro. Determina se e possivel remover e se nao for
	 * imprime no ecra o motivo.
	 **/
    void livros_remover();

	/**
	 * @brief Permite adicionar um leitor a biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 1 no menu leitores (caminho 4->1 do menu principal).
	 * Acessivel a todos os utilizadores.
	 * Pede para indicar: nome, telefone e email.
	 **/
    void leitores_adicionar();

	/**
	 * @brief Permite remover um livro da biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 2 no menu leitores (caminho 4->2 do menu principal).
	 * Acessivel a todos os utilizadores
	 * Pede para indicar o ID do leitor. Determina se e possivel remover e se nao for
	 * imprime no ecra o motivo.
	 **/
    void leitores_remover();

	/**
	 * @brief Permite alterar um leitor da biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 3 no menu leitores (caminho 4->3 do menu principal).
	 * Acessivel a todos os utilizadores.
	 * Pede para indicar: nome, telefone e email.
	 **/
    void leitores_alterar();

	/**
	 * @brief Imprime no ecra todos os leitores antigos
	 *
	 * Funcao chamada se for escolhida a opcao 4 no menu leitores (caminho 4->4 do menu principal).
	 * Acessivel a todos os utilizadores.
	 **/
    void leitores_antigos();

	/**
	 * @brief Permite adicionar um funcionario a biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 1 no menu funcionarios (caminho 5->1 do menu principal).
	 * Acessivel apenas ao administrador.
	 * Pede para indicar nome.
	 **/
    void funcionarios_adicionar();

	/**
	 * @brief Permite remover um funcionario da biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 2 no menu funcionarios (caminho 5->2 do menu principal).
	 * Acessivel apenas ao administrador.
	 * Pede para indicar id do funcionario que queremos remover.
	 **/
    void funcionarios_remover();

	/**
	 * @brief Permite promover um funcionario da biblioteca a supervisor
	 *
	 * Funcao chamada se for escolhida a opcao 3 no menu funcionarios (caminho 5->3 do menu principal).
	 * Acessivel apenas ao administrador.
	 * Pede para indicar id do funcionario que queremos promover.
	 **/
    void funcionarios_promover ();

	/**
	 * @brief Permite promover um supervisor da biblioteca a funcionario
	 *
	 * Funcao chamada se for escolhida a opcao 4 no menu funcionarios (caminho 5->4 do menu principal).
	 * Acessivel apenas ao administrador.
	 * Pede para indicar id do funcionario que queremos despromover.
	 **/
    void funcionarios_despromover();

	/**
	 * @brief Imprime no ecra todos os funcionarios antigos
	 *
	 * Funcao chamada se for escolhida a opcao 5 no menu leitores (caminho 4->5 do menu principal).
	 * Acessivel apenas ao administrador.
	 **/
    void funcionarios_antigos();

	/**
	 * @brief Permite adicionar um funcionario ao sistema
	 *
	 * Funcao chamada se for escolhida a opcao 1 no menu utilizadores (caminho 6->1 do menu principal).
	 * Acessivel apenas ao administrador.
	 * Pede para indicar: id, password e nivel de acesso.
	 **/
    void utilizadores_adicionar();

	/**
	 * @brief Permite remover um utilizador do sistema
	 *
	 * Funcao chamada se for escolhida a opcao 2 no menu utilizadores (caminho 6->2 do menu principal).
	 * Acessivel apenas ao administrador.
	 * Pede para indicar id do utilizador que queremos remover.
	 **/
    void utilizadores_remover();

};

#endif /* SRC_MENU_H_ */
