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

int main() {
	/* criacao de um Utilizador_online falso so para poder invocar o construtor de Menu
	 * o verdadeiro login sera feito mais tarde, na aplicacao */
	Utilizador_online* util = new Utilizador_online {-1,-1};

	/* criacao de um Menu */
	Menu m {Menu (util)};

	/* criacao do administrador, uma vez que e o unico que nao se encontra nos ficheiros*/
	Administrador* admin = new Administrador {0, "Administrador"};

	/* adicao do administrador aos funcionarios*/
	m.adiciona_funcionario(admin);

	/* caminho para a pasta onde estao os ficheiros e caminhos para cada um dos ficheiros*/
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

	/* leitura dos ficheiros e adicao dos varios objetos a biblioteca */
	m.le(ficheiro_lvo, ficheiro_lv, ficheiro_fco, ficheiro_fc, ficheiro_sp,
			ficheiro_lto, ficheiro_lt, ficheiro_epo, ficheiro_ep, ficheiro_ut);

	/* limpeza do ecra */
	clear_screen();

	/* invocacao do menu principal */
	m.menu_principal();

	/* no final, se sairmos da aplicacao com "s", sao gravadas as alteracoes aos objetos
	 * nos respetivos ficheiros */
	m.escreve(ficheiro_lvo, ficheiro_lv, ficheiro_fco, ficheiro_fc, ficheiro_sp,
			ficheiro_lto, ficheiro_lt, ficheiro_epo, ficheiro_ep, ficheiro_ut);

	return 0;
}


