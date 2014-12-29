
#ifndef Biblioteca_Pedido_old_h
#define Biblioteca_Pedido_old_h

#include "Pedido.h"
#include <ctime>

class Pedido;

/** @file
 *
 * @brief Header das funcoes de Pedido_old.
 *
 * Se uma funcao relacionada com pedidos antigos nao estiver nos ficheiros biblio, esta aqui.
 **/

/**
 * @brief Classe com toda a informacao de Pedido_old
 *
 * Na Biblioteca, os pedidos antigos sao guardados no mesmo vetor dos pedidos atuais.
 **/
class Pedido_old: public Pedido {
    
    std::time_t data_fim; /**< @brief data de fim do pedido **/
    
public:
    
    /**
     * @brief Construtor de Pedido
     *
     * @param id codigo de identificacao do pedido
     * @param lv apontador para o livro
     * @param fc apontador para o funcionarios
     * @param lt apontador para o leitor
     * @param dt data de inicio pedido
     * @param dt_f data de fim do pedido
     **/
    Pedido_old(Livro* lv, Funcionario* fc, Leitor* lt, bool ct,
                   std::time_t dt, unsigned long id, std::time_t dt_f = time(0));
    
    /**
     * @brief Funcao que imprime os atributos do emprestimo antigo
     *
     * @return string com o resultado da impressao
     **/
    std::string imprime();
    
    /**
     * @brief Funcao que escreve os atributos do emprestimo antigo num ficheiro
     *
     * @param ficheiro contem o caminho do ficheiro onde pretendemos escrever
     **/
    void escreve(std::string ficheiro);
};

#endif
