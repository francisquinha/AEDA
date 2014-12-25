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

/* construtor de Administrador
 * nao incrementa o contador de funcionarios, porque o administrador tem id 0 */
Administrador::Administrador(unsigned long id, string nom): Funcionario {nom, false, id} {}

void Administrador::escreve(string ficheiro) {}



