
#include <iostream>
#include <sstream>
#include <cstdlib>

#include "Menu.h"

using namespace std;

/** @file
 *
 * @brief Header das classes relacionadas com o Menu da aplicacao.
 *
 * Toda a interacao do utilizador com o programa e feita atraves destes menus.
 **/

void clear_screen() {
	#ifdef WINDOWS
    	system("cls");
	#else /* Assume POSIX */
    	system("clear");
	#endif
}

Utilizador_online::Utilizador_online(long id, int ace): Object {id}, acesso {ace} {}

int Utilizador_online::get_acesso() {
	return acesso;
}

Menu::Menu(Utilizador_online* util): utilizador_online {util} {}

bool Menu::e_numero(string num) {
    for (string::size_type i = 0; i != num.size(); i++) {
        if (!isdigit(num[i]))
            return false; /* existe pelo menos um caracter que nao e um numero */
    }
    return true; /* a string num e constituida exclusivamente por numeros */
}

void Menu::set_utilizador(Utilizador_online* util) {
	utilizador_online = util;
}

Utilizador_online* Menu::get_utilizador() {
	return utilizador_online;
}

int Menu::efectuar_login(long id, std::string pass) {
	vector<Utilizador*> utilizadores {get_utilizadores()};
	for (vector<Utilizador*>::const_iterator it = utilizadores.begin(); it!= utilizadores.end(); it++) {
		if ((*it)->get_ID() == id and (*it)->get_password() == pass) {
			return (*it)->get_acesso();
		}
	}
	return -1;
}

int Menu::menu_login() {
    cout << "Acesso ao sistema informatico da Biblioteca" << endl
         << endl;
    bool continuar {false};
    int tentativas {3}; /* utilizador tem 3 tentativas para fazer login corretamente */
    while (!continuar) {
        cout << "ID do utilizador (tentativas restantes " << tentativas << ", s para sair): ";
        string ids {};
        getline(cin, ids);
        if (ids == "s")
            return -1;
        else if (!e_numero(ids)){
            cout << "Username errado." << endl;
            tentativas--; // atualizar numero de tentativas disponiveis
            if (tentativas == 0) {
            	cout << "Numero de tentativas esgotado." << endl;
            	return -1;
            }
            else cout << "Por fazer tente novamente." << endl<<endl;
        }
        else {
        	long id = atol(ids.c_str());
        	char *pass=getpass("Password do utilizador: ");
        	int login {efectuar_login(id, pass)};
        	if (login == -1) {
        		cout << "Username e/ou password errados." << endl;
        		tentativas--; // atualizar numero de tentativas disponiveis
        		if (tentativas == 0) {
        			cout << "Numero de tentativas esgotado." << endl;
        			return -1;
        		}
        		else cout << "Por fazer tente novamente." << endl<<endl;
        	}
        	else {
        		Utilizador_online* util = new Utilizador_online {id, login};
        		util->online=true;
        		set_utilizador (util);
        		if (login == 0) {
        			cout << "Bem vindo administrador " << id << "." << endl << endl; // nao esta a ser usado, porque o ecra e limpo logo de seguida
        			continuar = true;
        			return 0;
        		}
        		else if (login == 1) {
        			cout << "Bem vindo supervisor " << id << "." << endl << endl; // nao esta a ser usado, porque o ecra e limpo logo de seguida
        			continuar = true;
        			return 1;
        		}
        		else {
        			cout << "Bem vindo funcionario " << id << "." << endl << endl; // nao esta a ser usado, porque o ecra e limpo logo de seguida
        			continuar = true;
        			return 2;
        		}
        	}
        }
    }
    return -2; /* nunca deve ser usado */
}

void Menu::menu_principal() {
    if (!utilizador_online->online) {
        int login {menu_login()};
        if (login == -1) {
        	cout << endl << "Ate a proxima." << endl << endl;
        }
        else {
            bool continuar {true};
            clear_screen();
            while (continuar) {
            	cout << "MENU PRINCIPAL" << endl << endl;
            	if (login == 0) cout << "ID do Administrador: " << utilizador_online->get_ID() << endl << endl;
            	else if (login == 1) cout << "ID do Supervisor: " << utilizador_online->get_ID() << endl << endl;
            	else cout << "ID do Funcionario: " << utilizador_online->get_ID() << endl << endl;
            	cout << "1) Consultas" << endl
            		 << "2) Emprestimos" << endl
					 << "3) Livros" << endl
            		 << "4) Leitores" << endl;
            	if (login == 0) {
            		cout << "5) Funcionarios" << endl
            			 << "6) Utilizadores" << endl;
            	}
            	if (login == 0) cout << endl << "Escolha uma opcao [1-6] (s para sair): ";
            	else cout << endl << "Escolha uma opcao [1-4] (s para sair): ";
            	string opcaos {};
            	int opcao{};
                getline(cin, opcaos);
                clear_screen();
            	if (opcaos == "s") {
            		cout << endl << "Ate a proxima." << endl << endl;
            		continuar=false;
            	}
            	else if (!e_numero(opcaos)) cout << "Opcao indisponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
            	else {
            		opcao = atoi(opcaos.c_str());
            		switch (opcao) {
            		case 1:
            			menu_consultas();
            			break;
            		case 2:
            			menu_emprestimos();
            			break;
            		case 3:
            			menu_livros();
            			break;
            		case 4:
            			menu_leitores();
            			break;
            		case 5:
            			if (login == 0) menu_funcionarios();
            			else cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
            			break;
            		case 6:
            			if (login == 0) menu_utilizadores();
            			else cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
            			break;
            		default:
            			cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
            			break;
            		}
            	}
            }
        }
    }
}

void Menu::menu_consultas() {
	int login {utilizador_online->get_acesso()};
	bool continuar {true};
    while (continuar) {
    	cout << "MENU CONSULTAS" << endl << endl;
    	cout << "1) Livros" << endl
    		 << "2) Emprestimos" << endl
			 << "3) Leitores" << endl;
    	if (login == 1) {
    		cout << "4) Funcionarios" << endl
    			 << "5) Supervisores" << endl;
    	}
    	if (login == 0) {
    		cout << "4) Funcionarios" << endl
    			 << "5) Supervisores" << endl
    			 << "6) Utilizadores" << endl;
    	}
    	if (login == 0) cout << endl << "Escolha uma opcao [1-6] (s para sair): ";
    	else if (login == 1) cout << endl << "Escolha uma opcao [1-5] (s para sair): ";
    	else cout << endl << "Escolha uma opcao [1-3] (s para sair): ";
    	string opcaos {};
    	int opcao{};
        getline(cin, opcaos);
    	clear_screen();
    	if (opcaos == "s") continuar=false;
    	else if (!e_numero(opcaos)) cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
    	else {
    		opcao = atoi(opcaos.c_str());
    		switch (opcao) {
    		case 1:
    			consulta_livros();
    			break;
    		case 2:
    			consulta_emprestimos();
    			break;
    		case 3:
    			consulta_leitores();
    			break;
   			case 4:
   				if (login != 2) consulta_funcionarios();
   				else cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
   				break;
   			case 5:
   				if (login != 2) consulta_supervisores();
   				else cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
   				break;
   			case 6:
   				if (login == 0) consulta_utilizadores();
   				else cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
   				break;
   			default:
   				cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
   				break;
  			}
   		}
   	}
}

void Menu::menu_emprestimos() {
	bool continuar {true};
    while (continuar) {
    	cout << "MENU EMPRESTIMOS" << endl << endl;
    	cout << "1) Adicionar" << endl
    		 << "2) Devolver" << endl
			 << "3) Consultar atrasos" << endl
		 	 << "4) Consultar atrasos por leitor" << endl
    		 << "5) Consultar livros atrasados" << endl
			 << "6) Consultar emprestimos antigos" << endl;
    	cout << endl << "Escolha uma opcao [1-6] (s para sair): ";
    	string opcaos {};
    	int opcao{};
        getline(cin, opcaos);
    	clear_screen();
    	if (opcaos == "s") continuar=false;
    	else if (!e_numero(opcaos)) cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
    	else {
    		opcao = atoi(opcaos.c_str());
    		switch (opcao) {
    		case 1:
    			emprestimos_adicionar();
    			break;
    		case 2:
    			emprestimos_remover();
    			break;
    		case 3:
    			emprestimos_atrasados();
    			break;
   			case 4:
   				emprestimos_atrasados_leitores();
    			break;
   			case 5:
   				emprestimos_atrasados_livros();
    			break;
   			case 6:
   				emprestimos_antigos();
    			break;
   			default:
   				cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
   				break;
  			}
   		}
   	}
}

void Menu::menu_livros() {
	int login {utilizador_online->get_acesso()};
	bool continuar {true};
    while (continuar) {
    	cout << "MENU LIVROS" << endl << endl;
    	cout << "1) Disponiveis" << endl
    		 << "2) Emprestados" << endl
    		 << "3) Por tema" << endl
			 << "4) Antigos" << endl;
    	if (login != 2) {
    		cout << "5) Adicionar" << endl
    			 << "6) Remover" << endl;
    	}
    	if (login != 2) cout << endl << "Escolha uma opcao [1-6] (s para sair): ";
    	else cout << endl << "Escolha uma opcao [1-4] (s para sair): ";
    	string opcaos {};
    	int opcao{};
        getline(cin, opcaos);
    	clear_screen();
    	if (opcaos == "s") continuar=false;
    	else if (!e_numero(opcaos)) cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
    	else {
    		opcao = atoi(opcaos.c_str());
    		switch (opcao) {
    		case 1:
    			livros_disponiveis();
    			break;
    		case 2:
    			livros_emprestados();
    			break;
    		case 3:
    			livros_tema();
    			break;
    		case 4:
    			livros_antigos();
    			break;
    		case 5:
   				if (login != 2) livros_adicionar();
   				else cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
   				break;
    		case 6:
   				if (login != 2) livros_remover();
   				else cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
   				break;
   			default:
   				cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
   				break;
  			}
   		}
   	}
}

void Menu::menu_leitores() {
	bool continuar {true};
    while (continuar) {
    	cout << "MENU LEITORES" << endl << endl;
    	cout << "1) Adicionar" << endl
    		 << "2) Remover" << endl
			 << "3) Alterar" << endl
		 	 << "4) Antigos" << endl;
    	cout << endl << "Escolha uma opcao [1-4] (s para sair): ";
    	string opcaos {};
    	int opcao{};
        getline(cin, opcaos);
    	clear_screen();
    	if (opcaos == "s") continuar=false;
    	else if (!e_numero(opcaos)) cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
    	else {
    		opcao = atoi(opcaos.c_str());
    		switch (opcao) {
    		case 1:
    			leitores_adicionar();
    			break;
    		case 2:
    			leitores_remover();
    			break;
    		case 3:
    			leitores_alterar();
    			break;
    		case 4:
    			leitores_antigos();
    			break;
   			default:
   				cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
   				break;
  			}
   		}
   	}
}

void Menu::menu_funcionarios() {
	bool continuar {true};
    while (continuar) {
    	cout << "MENU FUNCIONARIOS" << endl << endl;
    	cout << "1) Adicionar" << endl
    		 << "2) Remover" << endl
			 << "3) Promover" << endl
		 	 << "4) Despromover" << endl
    		 << "5) Antigos" << endl;
    	cout << endl << "Escolha uma opcao [1-5] (s para sair): ";
    	string opcaos {};
    	int opcao{};
        getline(cin, opcaos);
    	clear_screen();
    	if (opcaos == "s") continuar=false;
    	else if (!e_numero(opcaos)) cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
    	else {
    		opcao = atoi(opcaos.c_str());
    		switch (opcao) {
    		case 1:
    			funcionarios_adicionar();
    			break;
    		case 2:
    			funcionarios_remover();
    			break;
    		case 3:
    			funcionarios_promover();
    			break;
   			case 4:
    			funcionarios_despromover();
    			break;
   			case 5:
    			funcionarios_antigos();
    			break;
   			default:
   				cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
   				break;
  			}
   		}
   	}
}

void Menu::menu_utilizadores(){
	bool continuar {true};
    while (continuar) {
    	cout << "MENU UTILIZADORES" << endl << endl;
    	cout << "1) Adicionar" << endl
    		 << "2) Remover" << endl;
    	cout << endl << "Escolha uma opcao [1-2] (s para sair): ";
    	string opcaos {};
    	int opcao{};
        getline(cin, opcaos);
    	clear_screen();
    	if (opcaos == "s") continuar=false;
    	else if (!e_numero(opcaos)) cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
    	else {
    		opcao = atoi(opcaos.c_str());
    		switch (opcao) {
    		case 1:
    			utilizadores_adicionar();
    			break;
    		case 2:
    			utilizadores_remover();
    			break;
   			default:
   				cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
   				break;
  			}
   		}
   	}
}

void Menu::consulta_livros() {
	cout << imprime_livros();
}

void Menu::consulta_emprestimos() {
	cout << imprime_emprestimos();
}

void Menu::consulta_leitores() {
	cout << imprime_leitores();
}

void Menu::consulta_funcionarios() {
	cout << imprime_funcionarios();
}

void Menu::consulta_supervisores() {
	cout << imprime_supervisores();
}

void Menu::consulta_utilizadores() {
	cout << imprime_utilizadores();
}

void Menu::emprestimos_adicionar() {
	bool continuar {true};
    while (continuar) {
    	cout << "Adicionar Emprestimo (s para sair)" << endl << endl;
    	cout << "ID do livro: ";
    	string id_lv_s {};
    	long id_lv{};
        getline(cin, id_lv_s);
    	if (id_lv_s == "s") {
			clear_screen();
			continuar = false;
    	}
    	else if (!e_numero(id_lv_s)) cout << endl << "Por favor insira um numero." << endl << endl;
    	else {
    		id_lv = atol(id_lv_s.c_str());
    		Livro* lv{};
    		vector<Livro*> livros = get_livros();
    		for (vector<Livro*>::const_iterator it = livros.begin(); it != livros.end(); it++){
    			if ((*it)->get_ID() == id_lv) lv = (*it);
    		}
    		cout << "ID do leitor: ";
    		string id_lt_s {};
    		long id_lt{};
            getline(cin, id_lt_s);
			Leitor* lt{};
    		if (id_lt_s == "s") {
    			clear_screen();
    			continuar = false;
    		}
    		else if (!e_numero(id_lt_s)) cout << endl << "Por favor insira um numero." << endl << endl;
    		else {
    			id_lt = atol(id_lt_s.c_str());
    			vector<Leitor*> leitores = get_leitores();
    			for (vector<Leitor*>::const_iterator it = leitores.begin(); it != leitores.end(); it++){
    				if ((*it)->get_ID() == id_lt) lt = (*it);
    			}
    			Funcionario* fc{};
    			vector<Funcionario*> funcionarios = get_funcionarios_todos();
    			for (vector<Funcionario*>::const_iterator it = funcionarios.begin(); it != funcionarios.end(); it++){
    				if ((*it)->get_ID() == utilizador_online->get_ID()) fc = (*it);
    			}
    			Emprestimo* ep = new Emprestimo{lv, fc, lt, true};
    			cout << endl;
    			try {
    				adiciona_emprestimo(ep);
    			}
    			catch (Livro_indisponivel &liv) {
    				ostringstream ostr{};
    				ostr << liv;
    				cout << ostr.str();
    				cout << "Por favor escolha um livro disponivel." << endl;
    			}
    			catch(Maximo_emprestimos &lei ) {
    				ostringstream ostr{};
    				ostr << lei;
    				cout << ostr.str();
    				cout << "Por favor escolha um leitor com menos de 3 emprestimos." << endl;
    			}
    			cout << endl;
    		}
    	}
   	}
}

void Menu::emprestimos_remover() {
	bool continuar {true};
    while (continuar) {
    	cout << "Devolver Emprestimo (s para sair)" << endl << endl;
    	cout << "ID do Emprestimo: ";
    	string id_ep_s {};
    	long id_ep{};
        getline(cin, id_ep_s);
    	if (id_ep_s == "s") {
			clear_screen();
			continuar=false;
    	}
    	else if (!e_numero(id_ep_s)) cout << endl << "Por favor insira um numero." << endl << endl;
    	else {
    		id_ep = atol(id_ep_s.c_str());
    		try {
    			remove_emprestimo(id_ep);
    		}
    		catch(Object_nao_existe &ob) {
					ostringstream ostr{};
					ostr << ob;
					cout << ostr.str();
    				cout << "Por favor insira o ID de um emprestimo existente." << endl;
    		}
    		cout << endl;
    	}
    }
}

void Menu::emprestimos_atrasados() {
	vector<Emprestimo*> emprestimos_atrasados {get_emprestimos_atrasados()};
	stringstream out {};
	out << "EMPRESTIMOS ATRASADOS" << endl << endl;
	for (vector<Emprestimo*>::const_iterator it = emprestimos_atrasados.begin(); it != emprestimos_atrasados.end(); it++) {
		out << (*it)->imprime() << endl;
	}
	cout << out.str();
}

void Menu::emprestimos_atrasados_leitores() {
	cout << imprime_emprestimos_atrasados();
}

void Menu::emprestimos_atrasados_livros() {
	vector<Emprestimo*> emprestimos_atrasados {get_emprestimos_atrasados()};
	stringstream out {};
	out << "LIVROS ATRASADOS" << endl << endl;
	for (vector<Emprestimo*>::const_iterator it = emprestimos_atrasados.begin(); it != emprestimos_atrasados.end(); it++) {
		out << ((*it)->get_livro())->imprime() << endl;
	}
	cout << out.str();
}

void Menu::emprestimos_antigos() {
	cout << imprime_emprestimos_old();
}

void Menu::livros_disponiveis(){
	cout << imprime_livros_disponiveis();
}

void Menu::livros_emprestados(){
	cout << imprime_livros_emprestados();
}

void Menu::livros_tema(){
	cout << "Escolha um tema (s para sair)" << endl << endl;
	cout << "Temas possiveis: ";
	vector<string> temas {get_temas()};
	for (int i = 0; i < temas.size() - 1; i++){
		cout << temas[i] << "; ";
	}
	cout << temas[temas.size()-1] << "." << endl << endl;
	string tem {};
	cout << "Tema: ";
	getline (cin, tem);
	if (tem == "s") {
		clear_screen();
	}
	else {
		clear_screen();
		cout << imprime_livros_tema(tem);
	}
}

void Menu::livros_antigos() {
	cout << imprime_livros_old();
}

void Menu::livros_adicionar() {
	bool continuar {true};
    while (continuar) {
    	cout << "Adicionar Livro (s para sair)" << endl << endl;
    	string tit {};
    	cout << "Titulo: ";
    	getline (cin, tit);
    	if (tit == "s") {
			clear_screen();
			continuar = false;
    	}
    	else {
        	string auts {};
        	cout << "Nome(s) do(s) autor(es) (separados por ;) : ";
        	getline (cin, auts);
        	if (auts == "s") {
        		clear_screen();
        		continuar = false;
        	}
        	else {
        		vector<string>aut {};
        		string autor {};
        		stringstream autss(auts);
        		while (getline(autss, autor, ';')) {
        			aut.push_back(autor);
        		}
            	string tem {};
            	cout << "Tema: ";
            	getline (cin, tem);
            	if (tem == "s") {
        			clear_screen();
        			continuar = false;
            	}
            	else {
                	string isbns {};
                	cout << "ISBN: ";
                	getline (cin, isbns);
                	if (isbns == "s") {
            			clear_screen();
            			continuar = false;
                	}
                	else if (!e_numero(isbns)) cout << endl << "Por favor insira um numero no ISBN." << endl << endl;
                	else {
                		long isbn = atol(isbns.c_str());
                    	string cot {};
                    	cout << "Cota: ";
                    	getline (cin, cot);
                    	if (cot == "s") {
                			clear_screen();
                			continuar = false;
                    	}
                    	else {
                        	string num_pags {};
                        	cout << "Num. Paginas: ";
                        	getline (cin, num_pags);
                        	if (num_pags == "s") {
                    			clear_screen();
                    			continuar = false;
                        	}
                        	else if (!e_numero(num_pags)) cout << endl << "Por favor insira um numero no Num. Paginas." << endl << endl;
                        	else {
                        		int num_pag = atol(num_pags.c_str());
                            	string edis {};
                            	cout << "Edicao: ";
                            	getline (cin, edis);
                            	if (edis == "s") {
                        			clear_screen();
                        			continuar = false;
                            	}
                            	else if (!e_numero(edis)) cout << endl << "Por favor insira um numero na Edicao." << endl << endl;
                            	else {
                            		int edi = atol(edis.c_str());
                            		Livro* lv = new Livro{tit, aut, tem, isbn, cot, num_pag, edi, false, 0, 0, true};
                            		cout << endl;
                            		adiciona_livro(lv);
                        			cout << endl;
                            	}
                        	}
                    	}
                	}
            	}
    		}
    	}
   	}
}

void Menu::livros_remover() {
	bool continuar {true};
    while (continuar) {
    	cout << "Remover Livro (s para sair)" << endl << endl;
    	cout << "ID do Livro: ";
    	string ids {};
    	long id{};
        getline(cin, ids);
    	if (ids == "s") {
			clear_screen();
			continuar=false;
    	}
    	else if (!e_numero(ids)) cout << endl << "Por favor insira um numero." << endl << endl;
    	else {
    		id = atol(ids.c_str());
    		try {
    			remove_livro(id);
    		}
    		catch(Livro_emprestado &lv) {
					ostringstream ostr{};
					ostr << lv;
					cout << ostr.str();
    				cout << "Por favor devolva o emprestimo antes de remover o livro." << endl;
    		}
    		catch(Object_nao_existe &ob) {
					ostringstream ostr{};
					ostr << ob;
					cout << ostr.str();
    				cout << "Por favor insira o ID de um livro existente." << endl;
    		}
    		cout << endl;
    	}
    }
}

void Menu::leitores_adicionar() {
	bool continuar {true};
    while (continuar) {
    	cout << "Adicionar Leitor (s para sair)" << endl << endl;
    	string nom {};
    	cout << "Nome: ";
    	getline (cin, nom);
    	if (nom == "s") {
			clear_screen();
			continuar = false;
    	}
    	else {
        	string tels {};
        	cout << "Telefone: ";
        	getline (cin, tels);
        	if (tels == "s") {
        		clear_screen();
        		continuar = false;
        	}
        	else if (!e_numero(tels)) cout << endl << "Por favor insira um numero no ISBN." << endl << endl;
        	else {
        		long tel = atol(tels.c_str());
            	string eml {};
            	cout << "Email: ";
            	getline (cin, eml);
            	if (eml == "s") {
        			clear_screen();
        			continuar = false;
            	}
            	else {
            		Leitor* lt = new Leitor{nom, tel, eml, true};
                    cout << endl;
                    adiciona_leitor(lt);
                    cout << endl;
            	}
    		}
    	}
   	}
}

void Menu::leitores_remover() {
	bool continuar {true};
    while (continuar) {
    	cout << "Remover Leitor (s para sair)" << endl << endl;
    	cout << "ID do Leitor: ";
    	string ids {};
    	long id{};
        getline(cin, ids);
    	if (ids == "s") {
			clear_screen();
			continuar=false;
    	}
    	else if (!e_numero(ids)) cout << endl << "Por favor insira um numero." << endl << endl;
    	else {
    		id = atol(ids.c_str());
    		try {
    			remove_leitor(id);
    			}
    		catch(Emprestimos_por_devolver &ep) {
					ostringstream ostr{};
					ostr << ep;
					cout << ostr.str();
    				cout << "Por favor remova o(s) emprestimo(s) antes." << endl;
    			}
    		catch(Object_nao_existe &ob) {
					ostringstream ostr{};
					ostr << ob;
					cout << ostr.str();
    				cout << "Por favor insira o ID de um leitor existente." << endl;
    			}
    		cout << endl;
    	}
    }
}

void Menu::leitores_alterar() {
	bool continuar {true};
    while (continuar) {
    	cout << "Alterar Leitor (s para sair)" << endl << endl;
    	cout << "ID do Leitor: ";
    	string ids {};
        getline(cin, ids);
    	if (ids == "s") {
			clear_screen();
			continuar=false;
    	}
    	else if (!e_numero(ids)) cout << endl << "Por favor insira um numero." << endl << endl;
    	else {
    		long id = atol (ids.c_str());
    		string nom {};
    		cout << "Nome: ";
    		getline (cin, nom);
    		if (nom == "s") {
    			clear_screen();
    			continuar = false;
    		}
    		else {
    			string tels {};
    			cout << "Telefone : ";
    			getline (cin, tels);
    			if (tels == "s") {
    				clear_screen();
    				continuar = false;
    			}
    			else if (!e_numero(tels)) cout << endl << "Por favor insira um numero no telefone." << endl << endl;
    			else {
    				long tel = atol(tels.c_str());
    				string eml {};
    				cout << "Email: ";
    				getline (cin, eml);
    				if (eml == "s") {
    					clear_screen();
    					continuar = false;
    				}
    				else {
    					vector<Leitor*> leitors {get_leitores()};
    					bool encontrado{false};
    					for (vector<Leitor*>::const_iterator it = leitors.begin(); it != leitors.end(); it++) {
    						if ((*it)->get_ID() == id) {
    							encontrado = true;
    							(*it)->set_nome(nom);
    							(*it)->set_telefone(tel);
    							(*it)->set_email(eml);
    						}
    					}
    					if (encontrado) {
							cout << endl << "Leitor alterado." << endl << endl;
    					}
    					else {
    	    				cout << endl << "Por favor insira o ID de um leitor existente." << endl << endl;
    					}
    				}
            	}
    		}
    	}
   	}
}

void Menu::leitores_antigos() {
	cout << imprime_leitores_old();
}

void Menu::funcionarios_adicionar() {
	bool continuar {true};
    while (continuar) {
    	cout << "Adicionar Funcionario (s para sair)" << endl << endl;
    	string nom {};
    	cout << "Nome: ";
    	getline (cin, nom);
    	if (nom == "s") {
			clear_screen();
			continuar = false;
    	}
    	else {
            Funcionario* fc = new Funcionario{nom, true};
            cout << endl;
            adiciona_funcionario(fc);
            cout << endl;
    	}
   	}
}

void Menu::funcionarios_remover() {
	bool continuar {true};
    while (continuar) {
    	cout << "Remover Funcionario (s para sair)" << endl << endl;
    	cout << "ID do Funcionario: ";
    	string ids {};
    	long id{};
        getline(cin, ids);
    	if (ids == "s") {
			clear_screen();
			continuar=false;
    	}
    	else if (!e_numero(ids)) cout << endl << "Por favor insira um numero." << endl << endl;
    	else {
    		id = atol(ids.c_str());
    		try {
    			remove_funcionario(id);
    			}
    		catch(Object_nao_existe &ob) {
					ostringstream ostr{};
					ostr << ob;
					cout << ostr.str();
    				cout << "Por favor insira o ID de um funcionario existente." << endl;
    			}
    		cout << endl;
    	}
    }
}

void Menu::funcionarios_promover () {
	bool continuar {true};
    while (continuar) {
    	cout << "Promover Funcionario (s para sair)" << endl << endl;
    	cout << "ID do Funcionario: ";
    	string ids {};
    	long id{};
        getline(cin, ids);
    	if (ids == "s") {
			clear_screen();
			continuar=false;
    	}
    	else if (!e_numero(ids)) cout << endl << "Por favor insira um numero." << endl << endl;
    	else {
    		id = atol(ids.c_str());
    		try {
    			promove_funcionario_supervisor(id);
    			}
    		catch(Object_nao_existe &ob) {
					ostringstream ostr{};
					ostr << ob;
					cout << ostr.str();
    				cout << "Por favor insira o ID de um funcionario existente." << endl;
    			}
    		cout << endl;
    	}
    }
}

void Menu::funcionarios_despromover() {
	bool continuar {true};
    while (continuar) {
    	cout << "Despromover Supervisor (s para sair)" << endl << endl;
    	cout << "ID do Supervisor: ";
    	string ids {};
    	long id{};
        getline(cin, ids);
    	if (ids == "s") {
			clear_screen();
			continuar=false;
    	}
    	else if (!e_numero(ids)) cout << endl << "Por favor insira um numero." << endl << endl;
    	else {
    		id = atol(ids.c_str());
    		try {
    			despromove_supervisor_funcionorario(id);
    			}
    		catch(Object_nao_existe &ob) {
					ostringstream ostr{};
					ostr << ob;
					cout << ostr.str();
    				cout << "Por favor insira o ID de um supervisor existente." << endl;
    			}
    		cout << endl;
    	}
    }
}

void Menu::funcionarios_antigos() {
	cout << imprime_funcionarios_old();
}

void Menu::utilizadores_adicionar() {
	bool continuar {true};
    while (continuar) {
    	cout << "Adicionar Utilizador (s para sair)" << endl << endl;
    	string ids {};
    	cout << "ID: ";
    	getline (cin, ids);
    	if (ids == "s") {
			clear_screen();
			continuar = false;
    	}
    	else if (!e_numero(ids)) cout << endl << "Por favor insira um numero." << endl << endl;
    	else {
    		long id = atol(ids.c_str());
			vector<Funcionario*> funcios {get_funcionarios_todos()};
			bool encontrado{false};
			for (vector<Funcionario*>::const_iterator it = funcios.begin(); it != funcios.end(); it++) {
				if ((*it)->get_ID() == id) {
					encontrado = true;
				}
			}
			if (!encontrado) {
				cout << endl << "Por favor insira o ID de um funcionario existente." << endl << endl;
			}
			else {
				char *pass=getpass("Password: ");
				char *pass_c=getpass("Repetir Password: ");
				if (pass != pass_c) {
					cout << endl << "As passwords que introduziu nao coincidem. Por favor tente novamente." << endl << endl;
				}
				else {
			    	string aces{};
					cout << "Nivel de acesso (0, 1, 2): ";
			    	getline (cin, aces);
			    	if (ids == "s") {
						clear_screen();
						continuar = false;
			    	}
			    	else if (!e_numero(aces)) cout << endl << "Por favor insira um numero entre 0 e 2." << endl << endl;
			    	else {
			    		int ace = atoi(aces.c_str());
			    		if (ace == 0 or ace == 1 or ace == 2) {
			    			Utilizador* ut = new Utilizador{id, pass, ace};
			    			cout << endl;
			    			adiciona_utilizador (ut);
			    			cout << endl;
			    		}
			    		else cout << endl << "Por favor insira um numero entre 0 e 2." << endl << endl;
			    	}
				}
			}
    	}
   	}

}

void Menu::utilizadores_remover() {
	bool continuar {true};
    while (continuar) {
    	cout << "Remover Utilizador (s para sair)" << endl << endl;
    	cout << "ID do Utilizador: ";
    	string ids {};
    	long id{};
        getline(cin, ids);
    	if (ids == "s") {
			clear_screen();
			continuar=false;
    	}
    	else if (!e_numero(ids)) cout << endl << "Por favor insira um numero." << endl << endl;
    	else {
    		id = atol(ids.c_str());
    		try {
    			remove_utilizador(id);
    			}
    		catch(Object_nao_existe &ob) {
					ostringstream ostr{};
					ostr << ob;
					cout << ostr.str();
    				cout << "Por favor insira o ID de um utilizador existente." << endl;
    			}
    		cout << endl;
    	}
    }
}



