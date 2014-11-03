#ifndef SRC_MENU_H_
#define SRC_MENU_H_

#include <string>
#include <vector>

#include "Biblio.h"

// Utilizador ligado ao sistema no momento
class Utilizador_online: public Object {
    int acesso; // nivel de acesso do utilizador
public:
    int get_acesso(); // obter nivel de acesso do utilizador
};

// Menu, contem todas as funcoes a que os utilizadores podem aceder
class Menu: public Biblioteca{
    Utilizador_online utilizador_online;
    void aguarda_input();
public:
    Menu(Utilizador_online util);

    int fazer_login(); // Menu inicial usado para fazer o login
    void menu_principal(); // Mostra o menu principal

    void menu_consultas(); // Mostra as varias opcpes de consulta (opcao 1 do menu principal)
    void menu_emprestimos(); // Mostra as varias opcoes de gestao de emprestimos (opcao 2 do menu principal)
    void menu_livros();
    void menu_funcionarios();
    void menu_leitores();
    void menu_utilizadores();

    void consulta_livros();
    void consulta_funcionarios();
    void consulta_supervisores();
    void consulta_leitores();
    void consulta_emprestimos();

    void emprestimos_adicionar();
    void emprestimos_remover();
    void emprestimos_atrasados();
    void emprestimos_contactos();

    void livros_adicionar();
    void livros_remover();

    void funcionarios_adicionar();
    void funcionarios_remover();
    void funcionarios_promover ();
    void funcionarios_despromover();

    void leitores_adicionar();
    void leitores_remover();
    void leitores_alterar();

    void utilizadores_adicionar();
    void utilizadores_remover();
    void utilizadores_alterar();
};

#endif /* SRC_MENU_H_ */
