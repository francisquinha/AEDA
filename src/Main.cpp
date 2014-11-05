#include <string>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Menu.h"

using namespace std;

int main()
{
	Utilizador_online* util = new Utilizador_online {-1,-1};
	Menu m {Menu (util)};
	Administrador* admin = new Administrador {0, "Administrador"};
	m.adiciona_funcionario(admin);
	string path{"/Users/Angie/Documents/MIEIC/2A1S/AEDA/trabalhos/biblioteca/"};
	m.le(path + "Livro.txt", path + "Funcionario.txt", path + "Supervisor.txt", path + "Leitor.txt", path + "Emprestimo.txt", path + "Utilizador.txt");
	system("clear");
	m.menu_principal();
	m.escreve(path + "Livro.txt", path + "Funcionario.txt", path + "Supervisor.txt", path + "Leitor.txt", path + "Emprestimo.txt", path + "Utilizador.txt");
    return 0;
}


