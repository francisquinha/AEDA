#ifndef SRC_MENU_H_
#define SRC_MENU_H_

#include <string>
#include <vector>
#include <unistd.h>

#include "Biblio.h"


// Utilizador ligado ao sistema no momento
class Utilizador_online: public Object  {
    int acesso; // nivel de acesso do utilizador
public:
    bool online{false};
    Utilizador_online(long id, int ace);
    int get_acesso(); // obter nivel de acesso do utilizador
};

// Menu, contem todas as funcoes a que os utilizadores podem aceder
class Menu: public Biblioteca {
    Utilizador_online* utilizador_online;
    bool e_numero(std::string num);
public:
    Menu(Utilizador_online* util);

    void set_utilizador(Utilizador_online* util);
	Utilizador_online* get_utilizador();

    int efectuar_login(long id, std::string pass); // faz login do utilizador e devolve o nivel de acesso se o login estiver correto ou -1 se estiver errado
    int menu_login(); // Menu inicial usado para fazer o login
    void menu_principal(); // Mostra as opcoes do menu principal

    void menu_consultas(); // Mostra as opcpes de consulta (opcao 1 do menu principal)
    void menu_emprestimos(); // Mostra as opcoes de gestao de emprestimos (opcao 2 do menu principal)
    void menu_livros(); // Mostra as opcoes de gestao de livros (opcao 3 do menu principal)
    void menu_leitores(); // Mostra as opcoes de gestao de leitores (opcao 4 do menu principal)
    void menu_funcionarios(); // Mostra as opces de gestao de funcionarios (opcao 5 do menu principal)
    void menu_utilizadores(); // Mostra as opcoes de gestao de utilizadores (opcao 6 do menu principal)

    void consulta_livros();
    void consulta_emprestimos();
    void consulta_leitores();
    void consulta_funcionarios();
    void consulta_supervisores();
    void consulta_utilizadores();

    void emprestimos_adicionar();
    void emprestimos_remover();
    void emprestimos_atrasados();
    void emprestimos_atrasados_leitores();
    void emprestimos_atrasados_livros();

    void livros_disponiveis();
    void livros_emprestados();
    void livros_tema();
    void livros_adicionar();
    void livros_remover();

    void leitores_adicionar();
    void leitores_remover();
    void leitores_alterar();

    void funcionarios_adicionar();
    void funcionarios_remover();
    void funcionarios_promover ();
    void funcionarios_despromover();

    void utilizadores_adicionar();
    void utilizadores_remover();
};

#endif /* SRC_MENU_H_ */
