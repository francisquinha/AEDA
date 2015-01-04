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
 * @brief funcao para limpar o ecra
 *
 * o codigo so compila em c++11, mas desde que essa seja a versao utilizada,
 * da forma como esta funcao esta construida, devemos conseguir compilar e correr
 * a aplicacao na maior parte dos sistemas operativos
 **/
void clear_screen();

/**
 * @brief funcao para ler uma password sem a mostrar
 *
 * o codigo so compila em c++11, mas desde que essa seja a versao utilizada,
 * da forma como esta funcao esta construida, devemos conseguir compilar e correr
 * a aplicacao na maior parte dos sistemas operativos
 *
 * @param texto texto que e imprimido quando e pedida a password
 *
 * @return char com a password
 **/
char* ler_password(const char* texto);

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
    Utilizador_online(unsigned long id, int ace);

	/**
	 * @brief Funcao para obter o nivel de acesso do Utilizador_online
	 *
	 * @return string com a password do utilizador
	 **/
    int get_acesso() const;
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
	 * @brief Funcao para determinar se uma string e um numero (inteiro nao negativo) ou nao
	 *
	 * @param num string que pretendemos determinar se e um numero
	 *
	 * @return bool true se e numero, false caso contrario
	 **/
    bool e_numero(const std::string num) const;

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
	Utilizador_online* get_utilizador() const;

	/**
	 * @brief Funcao que efetua login de um novo utilizador
	 *
	 * @param id identificacao do utilizador
	 * @param pass password do utilizador
	 *
	 * @return int com o nivel de acesso se o id e a pass corresponderem a um utilizador existente, -1 caso contrario
	 **/
    int efectuar_login(const unsigned long id, const std::string pass);

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
    void menu_consultas() const;

	/**
	 * @brief Menu emprestimos com as opcoes adicionar, devolver, consultar atrasos, consultar atrasos por leitor,
	 * consultar livros atrasados e consultar antigos
	 *
	 * Este menu aparece se for escolhida a opcao 2 no menu principal.
	 * Todas as opcoes estao disponiveis independentemente do nivel de acesso do utilizador_online.
	 **/
    void menu_emprestimos();
    
    /**
     * @brief Menu pedidos com as opcoes adicionar, devolver e consultar antigos
     *
     * Este menu aparece se for escolhida a opcao 3 no menu principal.
     * Todas as opcoes estao disponiveis independentemente do nivel de acesso do utilizador_online.
     **/
    void menu_pedidos();

	/**
	 * @brief Menu livros com as opcoes consultar disponiveis, consultar emprestados, consultar por tema,
	 * consultar antigos, adicionar e remover
	 *
	 * Este menu aparece se for escolhida a opcao 4 no menu principal.
	 * As opcoes que mostra variam consoante o nivel de acesso do utilizador_online.
	 * 0 e 1 - Todas;
	 * 2 - Consultas.
	 **/
    void menu_livros();

	/**
	 * @brief Menu leitores com as opcoes adicionar, remover, alterar e consultar antigos
	 *
	 * Este menu aparece se for escolhida a opcao 5 no menu principal.
	 * Todas as opcoes estao disponiveis independentemente do nivel de acesso do utilizador_online.
	 **/
    void menu_leitores();

	/**
	 * @brief Menu funcionarios com as opcoes adicionar, remover, promover, despromover e consultar antigos
	 *
	 * Este menu aparece se for escolhida a opcao 6 no menu principal.
	 * So esta disponivel para o utilizador de nivel 0.
	 **/
    void menu_funcionarios();

	/**
	 * @brief Menu utilizadores com as opcoes adicionar e remover
	 *
	 * Este menu aparece se for escolhida a opcao 7 no menu principal.
	 * So esta disponivel para o utilizador de nivel 0.
	 **/
    void menu_utilizadores();

	/**
	 * @brief Imprime no ecra todos os livros atuais da biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 1 no menu consultas (caminho 1->1 do menu principal).
	 * Acessivel a todos os utilizadores.
	 **/
    void consulta_livros() const;

	/**
	 * @brief Imprime no ecra todos os emprestimos atuais da biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 2 no menu consultas (caminho 1->2 do menu principal).
	 * Acessivel a todos os utilizadores.
	 **/
    void consulta_emprestimos() const;
    
    /**
     * @brief Imprime no ecra todos os pedidos atuais da biblioteca
     *
     * Funcao chamada se for escolhida a opcao 3 no menu consultas (caminho 1->3 do menu principal).
     * Acessivel a todos os utilizadores.
     **/
    void consulta_pedidos() const;

	/**
	 * @brief Imprime no ecra todos os emprestimos atuais da biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 4 no menu consultas (caminho 1->4 do menu principal).
	 * Acessivel a todos os utilizadores.
	 **/
    void consulta_leitores() const;

	/**
	 * @brief Imprime no ecra todos os funcionarios atuais da biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 5 no menu consultas (caminho 1->5 do menu principal).
	 * Acessivel a utilizadores de niveis 0 e 1.
	 **/
    void consulta_funcionarios() const;

	/**
	 * @brief Imprime no ecra todos os supervisores atuais da biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 6 no menu consultas (caminho 1->6 do menu principal).
	 * Acessivel a utilizadores de niveis 0 e 1.
	 **/
    void consulta_supervisores() const;

	/**
	 * @brief Imprime no ecra todos os utilizadores da biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 7 no menu consultas (caminho 1->7 do menu principal).
	 * Acessivel apenas ao utilizador de nivel 0.
	 **/
    void consulta_utilizadores() const;

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
    void emprestimos_atrasados() const;

	/**
	 * @brief Imprime no ecra todos os emprestimos atrasados organizados por leitor, do qual imprime a informacao
	 *
	 * Funcao chamada se for escolhida a opcao 4 no menu emprestimos (caminho 2->4 do menu principal).
	 * Acessivel a todos os utilizadores.
	 **/
    void emprestimos_atrasados_leitores() const;

	/**
	 * @brief Imprime no ecra todos os livros de emprestimos atrasados
	 *
	 * Funcao chamada se for escolhida a opcao 5 no menu emprestimos (caminho 2->5 do menu principal).
	 * Acessivel a todos os utilizadores.
	 **/
    void emprestimos_atrasados_livros() const;

	/**
	 * @brief Imprime no ecra todos os emprestimos antigos
	 *
	 * Funcao chamada se for escolhida a opcao 6 no menu emprestimos (caminho 2->6 do menu principal).
	 * Acessivel a todos os utilizadores.
	 **/
    void emprestimos_antigos() const;
    
    /**
     * @brief Permite adicionar um pedido a biblioteca
     *
     * Funcao chamada se for escolhida a opcao 1 no menu pedidos (caminho 3->1 do menu principal).
     * Acessivel a todos os utilizadores.
     * Pede para indicar os ID do livro e do leitor. Determina se e possivel adicionar
     * e se nao for imprime no ecra o motivo.
     **/
    void pedidos_adicionar();
    
    /**
     * @brief Permite remover um pedido na biblioteca
     *
     * Funcao chamada se for escolhida a opcao 2 no menu pedidos (caminho 3->2 do menu principal).
     * Acessivel a todos os utilizadores.
     * Pede para indicar o ID do pedido. Determina se e possivel devolver e se nao for
     * imprime no ecra o motivo.
     **/
    void pedidos_desistir();
    
    /**
     * @brief Imprime no ecra todos os pedidos antigos
     *
     * Funcao chamada se for escolhida a opcao 3 no menu pedidos (caminho 3->3 do menu principal).
     * Acessivel a todos os utilizadores.
     **/
    void pedidos_antigos() const;

    /**
	 * @brief Permite escolher entre imprimir os livros disponíveis por ano, título ou autores
	 *
	 * Funcao chamada se for escolhida a opcao 1 no menu livros (caminho 4->1 do menu principal).
	 * Acessivel a todos os utilizadores.
	 **/
    void livros_disponiveis();
    
    /**
     * @brief Imprime no ecra os livros disponiveis por ano
     *
     * Funcao chamada se for escolhida a opcao 1 no menu livros disponiveis 
     * (caminho 4->1->1 do menu principal).
     * Acessivel a todos os utilizadores.
     **/
    void livros_disponiveis_ano();
    
    /**
     * @brief Imprime no ecra os livros disponiveis por titulo
     *
     * Funcao chamada se for escolhida a opcao 2 no menu livros disponiveis
     * (caminho 4->1->2 do menu principal).
     * Acessivel a todos os utilizadores.
     **/
    void livros_disponiveis_titulo();
    
    /**
     * @brief Imprime no ecra os livros disponiveis por autores
     *
     * Funcao chamada se for escolhida a opcao 3 no menu livros disponiveis
     * (caminho 4->1->3 do menu principal).
     * Acessivel a todos os utilizadores.
     **/
    void livros_disponiveis_autores();

	/**
	 * @brief Imprime no ecra todos os livros emprestados
	 *
	 * Funcao chamada se for escolhida a opcao 2 no menu livros (caminho 4->2 do menu principal).
	 * Acessivel a todos os utilizadores.
	 **/
    void livros_emprestados() const;

	/**
	 * @brief Imprime no ecra todos os livros de um determinado tema
	 *
	 * Funcao chamada se for escolhida a opcao 3 no menu livros (caminho 4->3 do menu principal).
	 * Acessivel a todos os utilizadores.
	 * Imprime os temas disponiveis para o utilizador escolher.
	 **/
    void livros_tema() const;

	/**
	 * @brief Imprime no ecra todos os livros antigos
	 *
	 * Funcao chamada se for escolhida a opcao 4 no menu livros (caminho 4->4 do menu principal).
	 * Acessivel a todos os utilizadores.
	 **/
    void livros_antigos() const;

	/**
	 * @brief Permite escolher entre adicionar novo livro ou exemplar a livro existente
	 *
	 * Funcao chamada se for escolhida a opcao 5 no menu livros (caminho 4->5 do menu principal).
	 * Acessivel apenas a utilizadores de niveis 0 e 1.
	 **/
    void livros_adicionar();

    /**
     * @brief Permite adicionar um livro novo a biblioteca
     *
     * Funcao chamada se for escolhida a opcao 1 no menu Livros->Adicionar (caminho 4->5->1 do menu principal).
     * Acessivel apenas a utilizadores de niveis 0 e 1.
     * Pede para indicar: titulo, autores, tema, ISBN, cota, num. paginas e edicao.
     **/
    void livros_adicionar_novo();
    
    /**
     * @brief Permite adicionar um exemplar a um livro da biblioteca
     *
     * Funcao chamada se for escolhida a opcao 2 no menu Livros->Adicionar (caminho 4->5->2 do menu principal).
     * Acessivel apenas a utilizadores de niveis 0 e 1.
     * Pede para indicar ID do livro a que queremos adicionar emprestimo.
     **/
    void livros_adicionar_exemplar();
    
	/**
	 * @brief Permite remover um livro da biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 6 no menu livros (caminho 4->6 do menu principal).
	 * Acessivel apenas a utilizadores de niveis 0 e 1.
	 * Pede para indicar o ID do livro. Determina se e possivel remover e se nao for
	 * imprime no ecra o motivo.
	 **/
    void livros_remover();
    
    /**
     * @brief Permite alterar um leitor da biblioteca
     *
     * Funcao chamada se for escolhida a opcao 7 no menu leitores (caminho 4->7 do menu principal).
     * Acessivel a utilizadores de niveis 0 e 1.
     * Pede para escolher: nome, telefone, email, morada ou tudo.
     **/
    void livros_alterar();
    
    /**
     * @brief Permite alterar o ano de edicao de um livro da biblioteca
     *
     * Funcao chamada se for escolhida a opcao 1 no menu alterar livros
     * (caminho 4->7->1 do menu principal).
     * Acessivel a utilizadores de niveis 0 e 1.
     * Pede para indicar: ID e Ano Edicao.
     **/
    void livros_alterar_ano();
    
    /**
     * @brief Permite alterar o titulo de um livro da biblioteca
     *
     * Funcao chamada se for escolhida a opcao 2 no menu alterar livros
     * (caminho 4->7->2 do menu principal).
     * Acessivel a utilizadores de niveis 0 e 1.
     * Pede para indicar: ID e Titulo.
     **/
    void livros_alterar_titulo();
    
    /**
     * @brief Permite alterar os autores de um livro da biblioteca
     *
     * Funcao chamada se for escolhida a opcao 3 no menu alterar livros
     * (caminho 4->7->3 do menu principal).
     * Acessivel a utilizadores de niveis 0 e 1.
     * Pede para indicar: ID e Autores.
     **/
    void livros_alterar_autores();
    
    /**
     * @brief Permite alterar o tema de um livro da biblioteca
     *
     * Funcao chamada se for escolhida a opcao 4 no menu alterar livros
     * (caminho 4->7->4 do menu principal).
     * Acessivel a utilizadores de niveis 0 e 1.
     * Pede para indicar: ID e Tema.
     **/
    void livros_alterar_tema();
    
    /**
     * @brief Permite alterar o ISBN de um livro da biblioteca
     *
     * Funcao chamada se for escolhida a opcao 5 no menu alterar livros
     * (caminho 4->7->5 do menu principal).
     * Acessivel a utilizadores de niveis 0 e 1.
     * Pede para indicar: ID e ISBN.
     **/
    void livros_alterar_ISBN();
    
    /**
     * @brief Permite alterar a cota de um livro da biblioteca
     *
     * Funcao chamada se for escolhida a opcao 6 no menu alterar livros
     * (caminho 4->7->6 do menu principal).
     * Acessivel a utilizadores de niveis 0 e 1.
     * Pede para indicar: ID e Cota.
     **/
    void livros_alterar_cota();
    
    /**
     * @brief Permite alterar o numero de paginas de um livro da biblioteca
     *
     * Funcao chamada se for escolhida a opcao 7 no menu alterar livros
     * (caminho 4->7->7 do menu principal).
     * Acessivel a utilizadores de niveis 0 e 1.
     * Pede para indicar: ID e Num. Paginas.
     **/
    void livros_alterar_num_paginas();
    
    /**
     * @brief Permite alterar a edicao de um livro da biblioteca
     *
     * Funcao chamada se for escolhida a opcao 8 no menu alterar livros
     * (caminho 4->7->8 do menu principal).
     * Acessivel a utilizadores de niveis 0 e 1.
     * Pede para indicar: ID e Edicao.
     **/
    void livros_alterar_edicao();
    
    /**
     * @brief Permite alterar toda a informacao de um livro da biblioteca
     *
     * Funcao chamada se for escolhida a opcao 9 no menu alterar livros
     * (caminho 4->7->9 do menu principal).
     * Acessivel a utilizadores de niveis 0 e 1.
     * Pede para indicar: ID, Ano Edicao, Titulo, Autores, Tema, ISBN, Cota, Num. Paginas e Edicao
     **/
    void livros_alterar_tudo();

	/**
	 * @brief Permite adicionar um leitor a biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 1 no menu leitores (caminho 5->1 do menu principal).
	 * Acessivel a todos os utilizadores.
	 * Pede para indicar: nome, telefone e email.
	 **/
    void leitores_adicionar();

	/**
	 * @brief Permite remover um livro da biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 2 no menu leitores (caminho 5->2 do menu principal).
	 * Acessivel a todos os utilizadores
	 * Pede para indicar o ID do leitor. Determina se e possivel remover e se nao for
	 * imprime no ecra o motivo.
	 **/
    void leitores_remover();

	/**
	 * @brief Permite alterar um leitor da biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 3 no menu leitores (caminho 5->3 do menu principal).
	 * Acessivel a todos os utilizadores.
	 * Pede para escolher: nome, telefone, email, morada ou tudo.
	 **/
    void leitores_alterar();
    
    /**
     * @brief Permite alterar o nome de um leitor da biblioteca
     *
     * Funcao chamada se for escolhida a opcao 1 no menu alterar leitores
     * (caminho 5->3->1 do menu principal).
     * Acessivel a todos os utilizadores.
     * Pede para indicar: ID e nome.
     **/
    void leitores_alterar_nome();
    
    /**
     * @brief Permite alterar o tipo de um leitor da biblioteca
     *
     * Funcao chamada se for escolhida a opcao 2 no menu alterar leitores
     * (caminho 5->3->2 do menu principal).
     * Acessivel a todos os utilizadores.
     * Pede para indicar: ID e tipo.
     **/
    void leitores_alterar_tipo();
    
    /**
     * @brief Permite alterar o telefone de um leitor da biblioteca
     *
     * Funcao chamada se for escolhida a opcao 3 no menu alterar leitores
     * (caminho 5->3->3 do menu principal).
     * Acessivel a todos os utilizadores.
     * Pede para indicar: ID e telefone.
     **/
    void leitores_alterar_telefone();
    
    /**
     * @brief Permite alterar o email de um leitor da biblioteca
     *
     * Funcao chamada se for escolhida a opcao 4 no menu alterar leitores
     * (caminho 5->3->4 do menu principal).
     * Acessivel a todos os utilizadores.
     * Pede para indicar: ID e email.
     **/
    void leitores_alterar_email();
    
    /**
     * @brief Permite alterar a morada de um leitor da biblioteca
     *
     * Funcao chamada se for escolhida a opcao 5 no menu alterar leitores
     * (caminho 5->3->5 do menu principal).
     * Acessivel a todos os utilizadores.
     * Pede para indicar: ID e morada.
     **/
    void leitores_alterar_morada();
    
    /**
     * @brief Permite alterar toda a informacao de um leitor da biblioteca
     *
     * Funcao chamada se for escolhida a opcao 6 no menu alterar leitores
     * (caminho 5->3->6 do menu principal).
     * Acessivel a todos os utilizadores.
     * Pede para indicar: ID, nome, tipo, telefone, email e morada.
     **/
    void leitores_alterar_tudo();
    
	/**
	 * @brief Imprime no ecra todos os leitores inativos
	 *
	 * Funcao chamada se for escolhida a opcao 4 no menu leitores (caminho 5->4 do menu principal).
	 * Acessivel a todos os utilizadores.
	 **/
    void leitores_inativos() const;
    
    /**
     * @brief Imprime no ecra todos os leitores antigos
     *
     * Funcao chamada se for escolhida a opcao 5 no menu leitores (caminho 5->5 do menu principal).
     * Acessivel a todos os utilizadores.
     **/
    void leitores_antigos() const;

	/**
	 * @brief Permite adicionar um funcionario a biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 1 no menu funcionarios (caminho 6->1 do menu principal).
	 * Acessivel apenas ao administrador.
	 * Pede para indicar nome.
	 **/
    void funcionarios_adicionar();

	/**
	 * @brief Permite remover um funcionario da biblioteca
	 *
	 * Funcao chamada se for escolhida a opcao 2 no menu funcionarios (caminho 6->2 do menu principal).
	 * Acessivel apenas ao administrador.
	 * Pede para indicar id do funcionario que queremos remover.
	 **/
    void funcionarios_remover();

	/**
	 * @brief Permite promover um funcionario da biblioteca a supervisor
	 *
	 * Funcao chamada se for escolhida a opcao 3 no menu funcionarios (caminho 6->3 do menu principal).
	 * Acessivel apenas ao administrador.
	 * Pede para indicar id do funcionario que queremos promover.
	 **/
    void funcionarios_promover ();

	/**
	 * @brief Permite promover um supervisor da biblioteca a funcionario
	 *
	 * Funcao chamada se for escolhida a opcao 4 no menu funcionarios (caminho 6->4 do menu principal).
	 * Acessivel apenas ao administrador.
	 * Pede para indicar id do funcionario que queremos despromover.
	 **/
    void funcionarios_despromover();

	/**
	 * @brief Imprime no ecra todos os funcionarios antigos
	 *
	 * Funcao chamada se for escolhida a opcao 5 no menu leitores (caminho 6->5 do menu principal).
	 * Acessivel apenas ao administrador.
	 **/
    void funcionarios_antigos() const;

	/**
	 * @brief Permite adicionar um funcionario ao sistema
	 *
	 * Funcao chamada se for escolhida a opcao 1 no menu utilizadores (caminho 7->1 do menu principal).
	 * Acessivel apenas ao administrador.
	 * Pede para indicar: id, password e nivel de acesso.
	 **/
    void utilizadores_adicionar();

	/**
	 * @brief Permite remover um utilizador do sistema
	 *
	 * Funcao chamada se for escolhida a opcao 2 no menu utilizadores (caminho 7->2 do menu principal).
	 * Acessivel apenas ao administrador.
	 * Pede para indicar id do utilizador que queremos remover.
	 **/
    void utilizadores_remover();

};

#endif /* SRC_MENU_H_ */
