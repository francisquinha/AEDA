#ifndef SRC_EXCECAO_H_
#define SRC_EXCECAO_H_

class Ficheiro_indisponivel{
	std::string ficheiro;
public:
	Ficheiro_indisponivel(std::string fch): ficheiro{fch}{};
	std::string get_ficheiro();
};

#endif /* SRC_EXCECAO_H_ */
