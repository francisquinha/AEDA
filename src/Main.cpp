#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Menu.h"

using namespace std;

/** @mainpage
 *
 * Sistema informatico para uma Biblioteca.
 *
 * Permite gerir os livros, os emprestimos, os leitores e os funcionarios.
 *
 * Uma vez feito o login no sistema, escolhendo as opcoes apropriadas nos varios menus,
 * e possivel realizar todas as operacoes de CRUD relacionadas com a manutencao da biblioteca.
 *
 **/

/** @file
 *
 * @brief Codigo Main
 *
 * O lancamento da aplicacao comeca aqui. Aqui e chamada a classe Menu, que por sua vez usa as funcoes de Biblioteca,
 * sendo que essas acedem as restantes classes.
 **/

int main()
{
	Utilizador_online* util = new Utilizador_online {-1,-1};
	Menu m {Menu (util)};
	Administrador* admin = new Administrador {0, "Administrador"};
	m.adiciona_funcionario(admin);
	string path{"/Users/Angie/Documents/MIEIC/2A1S/AEDA/trabalhos/biblioteca/txt/"};
	string ficheiro_lvo {path + "Livro_old.txt"};
	string ficheiro_lv {path + "Livro.txt"};
	string ficheiro_fco {path + "Funcionario_old.txt"};
	string ficheiro_fc {path + "Funcionario.txt"};
	string ficheiro_sp {path + "Supervisor.txt"};
	string ficheiro_lto {path + "Leitor_old.txt"};
	string ficheiro_lt {path + "Leitor.txt"};
	string ficheiro_epo {path + "Emprestimo_old.txt"};
	string ficheiro_ep {path + "Emprestimo.txt"};
	string ficheiro_ut {path + "Utilizador.txt"};

	m.le(ficheiro_lvo, ficheiro_lv, ficheiro_fco, ficheiro_fc, ficheiro_sp,
			ficheiro_lto, ficheiro_lt, ficheiro_epo, ficheiro_ep, ficheiro_ut);
	system("clear");
	m.menu_principal();
	m.escreve(ficheiro_lvo, ficheiro_lv, ficheiro_fco, ficheiro_fc, ficheiro_sp,
			ficheiro_lto, ficheiro_lt, ficheiro_epo, ficheiro_ep, ficheiro_ut);
    return 0;
}


