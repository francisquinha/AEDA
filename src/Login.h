#ifndef SRC_LOGIN_H_
#define SRC_LOGIN_H_

#include <string>
#include <vector>
#include "Object.h"

class Object;

// Utilizador do sistema informatico, com login, password e nivel de acesso
class Utilizador: public Object {
    std::string password; // Password do utilizador
    int acesso; // Tipo de acesso do utilizador: 0 - Admin (Gerente da Biblioteca); 1 - Supervisor; 2 - Funcionario
public:
    Utilizador(long id, std::string pass, int acess); // construtor; parametros: id, password e acesso
    std::string get_password(); // obter password do utilizador; retorno: password
    void set_password(std::string pass); // determinar password do utilizador; parametros: password
    int get_acesso(); // obter tipo de acesso do utilizador
    void set_acesso(int acess); // determinar tipo de acesso do utilizador; parametro: acesso
    void escreve(std::string ficheiro); // escreve utilizador num ficheiro; parametros: string com nome do ficheiro
};

#endif // SRC_LOGIN_H_
