#ifndef SRC_EXCECAO_H_
#define SRC_EXCECAO_H_

#include "Leitor.h"

class Object;
class Livro;
class Leitor;

class Object_nao_existe: public Object {
public:
	Object_nao_existe(long id): Object {id} {};
	virtual ~Object_nao_existe() {};
};

class Livro_indisponivel: public Livro {
public:
	Livro_indisponivel(long id, std::string tit, std::vector<std::string> aut, std::string tem, long isbn,
			std::string cot, int np, int ed, bool ept, std::time_t dt):
				Livro {id, tit, aut, tem, isbn, cot, np, ed, ept, dt} {};
};

class Emprestimos_por_devolver: public Leitor {
public:
	Emprestimos_por_devolver(long id, std::string nom, int tel, std::string eml, std::vector<Emprestimo*> ep_lt): Leitor {id, nom, tel, eml, ep_lt} {};
};

class Maximo_emprestimos: public Leitor {
public:
	Maximo_emprestimos(long id, std::string nom, int tel, std::string eml, std::vector<Emprestimo*> ep_lt): Leitor {id, nom, tel, eml, ep_lt} {};
};

class Ficheiro_indisponivel {
	std::string ficheiro;
public:
	Ficheiro_indisponivel(std::string fch): ficheiro {fch} {};
	std::string get_ficheiro();
};


std::ostream& operator<<(std::ostream &out, Object_nao_existe &object);

std::ostream& operator<<(std::ostream &out, Livro_indisponivel &livro);

std::ostream& operator<<(std::ostream &out, Emprestimos_por_devolver &leitor);

std::ostream& operator<<(std::ostream &out, Maximo_emprestimos &leitor);

std::ostream& operator<<(std::ostream &out, Ficheiro_indisponivel &ficheiro);

#endif /* SRC_EXCECAO_H_ */
