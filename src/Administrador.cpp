#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

#include "Administrador.h"
#include "Excecao.h"

using namespace std;

/** @file
 *
 * @brief Source da classe Administrador.
 *
 * Serve apenas para adicionar um unico administrador quando a aplicacao e iniciada.
 **/

// construtor de Administrador
Administrador::Administrador(long id, string nom): Funcionario {id, nom, true} {}

// escreve Administrador
void Administrador::escreve(string ficheiro) {}



