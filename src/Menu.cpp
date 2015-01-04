
#include <iostream>
#include <sstream>
#include <cstdlib>
#if defined(__APPLE__) || defined(__unix__)
#else /* Assume Windows */
	#include <conio.h>
#endif

#include "Menu.h"

using namespace std;

/** @file
 *
 * @brief Header das classes relacionadas com o Menu da aplicacao.
 *
 * Toda a interacao do utilizador com o programa e feita atraves destes menus.
 **/

void clear_screen() {
	#if defined(__APPLE__) || defined(__unix__)
		system("clear");
	#else /* Assume Windows */
    	system("cls");
	#endif
}

char* ler_password(const char* texto) {
	#if defined(__APPLE__) || defined(__unix__)
		char* pass {getpass(texto)};
	#else /* Assume Windows */
		cout << texto;
		char* pass {getchar()};
	#endif
	return pass;
}

Utilizador_online::Utilizador_online(unsigned long id, int ace): Object {id}, acesso {ace} {}

int Utilizador_online::get_acesso() const {
	return acesso;
}

Menu::Menu(Utilizador_online* util): utilizador_online {util} {}

bool Menu::e_numero(const string num) const {
    for (string::size_type i = 0; i != num.size(); i++) {
        if (!isdigit(num[i]))
            return false; /* existe pelo menos um caracter que nao e um numero */
    }
    return true; /* a string num e constituida exclusivamente por numeros */
}

void Menu::set_utilizador(Utilizador_online* util) {
	utilizador_online = util;
}

Utilizador_online* Menu::get_utilizador() const {
	return utilizador_online;
}

int Menu::efectuar_login(const unsigned long id, const ::string pass) {
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
        	unsigned long id = atol(ids.c_str());
        	char *pass=ler_password("Password do utilizador: ");
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
        			cout << "Bem vindo administrador " << id << "."
        					<< endl << endl; // nao esta a ser usado, porque o ecra e limpo logo de seguida
        			continuar = true;
        			return 0;
        		}
        		else if (login == 1) {
        			cout << "Bem vindo supervisor " << id << "."
        					<< endl << endl; // nao esta a ser usado, porque o ecra e limpo logo de seguida
        			continuar = true;
        			return 1;
        		}
        		else {
        			cout << "Bem vindo funcionario " << id << "."
        					<< endl << endl; // nao esta a ser usado, porque o ecra e limpo logo de seguida
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
                     << "3) Pedidos" << endl
					 << "4) Livros" << endl
            		 << "5) Leitores" << endl;
            	if (login == 0) {
            		cout << "6) Funcionarios" << endl
            			 << "7) Utilizadores" << endl;
            	}
            	if (login == 0) cout << endl << "Escolha uma opcao [1-7] (s para sair): ";
            	else cout << endl << "Escolha uma opcao [1-5] (s para sair): ";
            	string opcaos {};
            	int opcao{};
                getline(cin, opcaos);
                clear_screen();
            	if (opcaos == "s") {
            		cout << endl << "Ate a proxima." << endl << endl;
            		continuar=false;
            	}
            	else if (!e_numero(opcaos)) cout
            			<< "Opcao indisponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
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
                        menu_pedidos();
                        break;
                    case 4:
            			menu_livros();
            			break;
            		case 5:
            			menu_leitores();
            			break;
            		case 6:
            			if (login == 0) menu_funcionarios();
            			else cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)."
            					<< endl << endl;
            			break;
            		case 7:
            			if (login == 0) menu_utilizadores();
            			else cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)."
            					<< endl << endl;
            			break;
            		default:
            			cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)."
						<< endl << endl;
            			break;
            		}
            	}
            }
        }
    }
}

void Menu::menu_consultas() const {
	int login {utilizador_online->get_acesso()};
	bool continuar {true};
    while (continuar) {
    	cout << "MENU CONSULTAS" << endl << endl;
    	cout << "1) Livros" << endl
    		 << "2) Emprestimos" << endl
             << "3) Pedidos" << endl
			 << "4) Leitores" << endl;
    	if (login == 1) {
    		cout << "5) Funcionarios" << endl
    			 << "6) Supervisores" << endl;
    	}
    	if (login == 0) {
    		cout << "5) Funcionarios" << endl
    			 << "6) Supervisores" << endl
    			 << "7) Utilizadores" << endl;
    	}
    	if (login == 0) cout << endl << "Escolha uma opcao [1-7] (s para sair): ";
    	else if (login == 1) cout << endl << "Escolha uma opcao [1-6] (s para sair): ";
    	else cout << endl << "Escolha uma opcao [1-4] (s para sair): ";
    	string opcaos {};
    	int opcao{};
        getline(cin, opcaos);
    	clear_screen();
    	if (opcaos == "s") continuar=false;
    	else if (!e_numero(opcaos)) cout
    			<< "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
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
                consulta_pedidos();
                break;
    		case 4:
    			consulta_leitores();
    			break;
   			case 5:
   				if (login != 2) consulta_funcionarios();
   				else cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)."
   						<< endl << endl;
   				break;
   			case 6:
   				if (login != 2) consulta_supervisores();
   				else cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)."
   						<< endl << endl;
   				break;
   			case 7:
   				if (login == 0) consulta_utilizadores();
   				else cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para  sair)."
   						<< endl << endl;
   				break;
   			default:
   				cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)."
				<< endl << endl;
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
    	else if (!e_numero(opcaos)) cout <<
    			"Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
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

void Menu::menu_pedidos() {
    bool continuar {true};
    while (continuar) {
        cout << "MENU PEDIDOS" << endl << endl;
        cout << "1) Adicionar" << endl
             << "2) Desistir" << endl
             << "3) Consultar pedidos antigos" << endl;
        cout << endl << "Escolha uma opcao [1-3] (s para sair): ";
        string opcaos {};
        int opcao{};
        getline(cin, opcaos);
        clear_screen();
        if (opcaos == "s") continuar=false;
        else if (!e_numero(opcaos)) cout <<
            "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
        else {
            opcao = atoi(opcaos.c_str());
            switch (opcao) {
                case 1:
                    pedidos_adicionar();
                    break;
                case 2:
                    pedidos_desistir();
                    break;
                case 3:
                    pedidos_antigos();
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
    			 << "6) Remover" << endl
                 << "7) Alterar" << endl;
        }
    	if (login != 2) cout << endl << "Escolha uma opcao [1-7] (s para sair): ";
    	else cout << endl << "Escolha uma opcao [1-4] (s para sair): ";
    	string opcaos {};
    	int opcao{};
        getline(cin, opcaos);
    	clear_screen();
    	if (opcaos == "s") continuar=false;
    	else if (!e_numero(opcaos)) cout
    			<< "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
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
   				else cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)."
   						<< endl << endl;
   				break;
    		case 6:
   				if (login != 2) livros_remover();
   				else cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)."
   						<< endl << endl;
   				break;
            case 7:
                if (login != 2) livros_alterar();
                else cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
                break;
   			default:
   				cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)."
				<< endl << endl;
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
		 	 << "4) Inativos" << endl
             << "5) Antigos" << endl;
        cout << endl << "Escolha uma opcao [1-5] (s para sair): ";
    	string opcaos {};
    	int opcao{};
        getline(cin, opcaos);
    	clear_screen();
    	if (opcaos == "s") continuar=false;
    	else if (!e_numero(opcaos)) cout
    			<< "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
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
                leitores_inativos();
                break;
    		case 5:
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
    	else if (!e_numero(opcaos)) cout
    			<< "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
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
    	else if (!e_numero(opcaos)) cout
    			<< "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
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

void Menu::consulta_livros() const {
	cout << imprime_livros();
}

void Menu::consulta_emprestimos() const {
	cout << imprime_emprestimos();
}

void Menu::consulta_pedidos() const {
    cout << imprime_pedidos();
}

void Menu::consulta_leitores() const {
	cout << imprime_leitores();
}

void Menu::consulta_funcionarios() const {
	cout << imprime_funcionarios();
}

void Menu::consulta_supervisores() const {
	cout << imprime_supervisores();
}

void Menu::consulta_utilizadores() const {
	cout << imprime_utilizadores();
}

void Menu::emprestimos_adicionar() {
	bool continuar {true};
    while (continuar) {
    	cout << "Adicionar Emprestimo (s para sair)" << endl << endl;
    	cout << "ID do livro: ";
    	string id_lv_s {};
    	unsigned long id_lv{};
        getline(cin, id_lv_s);
    	if (id_lv_s == "s") {
			clear_screen();
			continuar = false;
    	}
    	else if (!e_numero(id_lv_s)) cout << endl << "Por favor insira um numero." << endl << endl;
    	else {
    		id_lv = atol (id_lv_s.c_str());
            cout << "ID do leitor: ";
            string id_lt_s {};
            unsigned long id_lt{};
            getline(cin, id_lt_s);
            if (id_lt_s == "s") {
                clear_screen();
                continuar = false;
            }
            else if (!e_numero(id_lt_s)) cout << endl << "Por favor insira um numero."
                << endl << endl;
            else {
                cout << endl;
                id_lt = atol(id_lt_s.c_str());
                try {
                    adiciona_emprestimo_ids(id_lv, id_lt, utilizador_online->get_ID());
                }
                catch (Object_nao_existe &ob) {
                    ostringstream ostr{};
                    ostr << ob;
                    cout << ostr.str();
                    cout << "Por favor escolha outro." << endl;
                }
                catch (Livro_indisponivel &liv) {
                    ostringstream ostr{};
                    ostr << liv;
                    cout << ostr.str();
                    cout << "Deseja deixar pedido em espera? (s - sim, n - nao)" << endl << endl;
                    string rpt {};
                    getline(cin, rpt);
                    if (rpt == "s") {
                        cout << endl;
                        try {
                            adiciona_pedido_ids(id_lv, id_lt, utilizador_online->get_ID());
                        }
                        catch (Object_nao_existe &ob) {
                            ostringstream ostr{};
                            ostr << ob;
                            cout << ostr.str();
                        }
                    }
                }
    		}
            cout << endl;
    	}
   	}
}

void Menu::emprestimos_remover() {
	bool continuar {true};
    while (continuar) {
    	cout << "Devolver Emprestimo (s para sair)" << endl << endl;
    	cout << "ID do Emprestimo: ";
    	string id_ep_s {};
    	unsigned long id_ep{};
        getline(cin, id_ep_s);
    	if (id_ep_s == "s") {
			clear_screen();
			continuar=false;
    	}
    	else if (!e_numero(id_ep_s)) cout << endl << "Por favor insira um numero." << endl << endl;
    	else {
    		id_ep = atol(id_ep_s.c_str());
            Emprestimo* ep {};
    		try {
    			ep = remove_emprestimo(id_ep);
    		}
    		catch(Object_nao_existe &ob) {
                ostringstream ostr{};
                ostr << ob;
                cout << ostr.str();
                cout << "Por favor insira o ID de um emprestimo existente." << endl;
    		}
            cout << endl;
            while ((ep->get_livro())->get_pedidos().size()>0 and
                    (ep->get_livro())->get_ex_disponiveis()>0) {
                Pedido pd {(ep->get_livro())->get_pedidos().top()};
                cout << "Existe um pedido em espera para este livro: " << endl << endl;
                cout << "LEITOR" << endl;
                cout << (pd.get_leitor())->imprime() << endl;
                cout << "Deseja fazer emprestimo? (s - sim, n - nao)" << endl << endl;
                string rpt {};
                getline(cin, rpt);
                if (rpt == "s") {
                    cout << endl;
                    try {
                        adiciona_emprestimo_ids(pd.get_livro()->get_ID(),
                                                pd.get_leitor()->get_ID(),
                                                utilizador_online->get_ID());
                    }
                    catch (Object_nao_existe &ob) {
                        ostringstream ostr {};
                        ostr << ob;
                        cout << ostr.str();
                    }
                    catch (Livro_indisponivel &liv) {
                        ostringstream ostr {};
                        ostr << liv;
                        cout << ostr.str();
                    }
                }
                try {
                    remove_pedido(pd.get_ID());
                }
                catch (Object_nao_existe &ob) {
                    ostringstream ostr {};
                    ostr << ob;
                    cout << ostr.str();
                }
                catch (Pedido_nao_prioritario &pd) {
                    ostringstream ostr {};
                    ostr << pd;
                    cout << ostr.str();
                }
                cout << endl;
            }
    	}
    }
}

void Menu::emprestimos_atrasados() const {
	vector<Emprestimo*> emprestimos_atrasados {get_emprestimos_atrasados()};
	stringstream out {};
	out << "EMPRESTIMOS ATRASADOS" << endl << endl;
	for (vector<Emprestimo*>::const_iterator it = emprestimos_atrasados.begin();
			it != emprestimos_atrasados.end(); it++) {
		out << (*it)->imprime() << endl;
	}
	cout << out.str();
}

void Menu::emprestimos_atrasados_leitores() const {
	cout << imprime_emprestimos_atrasados();
}

void Menu::emprestimos_atrasados_livros() const {
	vector<Emprestimo*> emprestimos_atrasados {get_emprestimos_atrasados()};
	stringstream out {};
	out << "LIVROS ATRASADOS" << endl << endl;
	for (vector<Emprestimo*>::const_iterator it = emprestimos_atrasados.begin();
			it != emprestimos_atrasados.end(); it++) {
		out << ((*it)->get_livro())->imprime() << endl;
	}
	cout << out.str();
}

void Menu::emprestimos_antigos() const {
	cout << imprime_emprestimos_old();
}

void Menu::pedidos_adicionar() {
    bool continuar {true};
    while (continuar) {
        cout << "Adicionar Pedido (s para sair)" << endl << endl;
        cout << "ID do livro: ";
        string id_lv_s {};
        unsigned long id_lv{};
        getline(cin, id_lv_s);
        if (id_lv_s == "s") {
            clear_screen();
            continuar = false;
        }
        else if (!e_numero(id_lv_s)) cout << endl << "Por favor insira um numero." << endl << endl;
        else {
            id_lv = atol (id_lv_s.c_str());
            cout << "ID do leitor: ";
            string id_lt_s {};
            unsigned long id_lt{};
            getline(cin, id_lt_s);
            if (id_lt_s == "s") {
                clear_screen();
                continuar = false;
            }
            else if (!e_numero(id_lt_s)) cout << endl << "Por favor insira um numero."
                << endl << endl;
            else {
                id_lt = atol(id_lt_s.c_str());
                cout << endl;
                try {
                    adiciona_pedido_ids(id_lv, id_lt, utilizador_online->get_ID());
                }
                catch (Object_nao_existe &ob) {
                    ostringstream ostr{};
                    ostr << ob;
                    cout << ostr.str();
                    cout << "Por favor escolha outro." << endl;
                }
                catch (Livro_disponivel &liv) {
                    ostringstream ostr{};
                    ostr << liv;
                    cout << ostr.str();
                    cout << "Deseja fazer o emprestimo? (s - sim, n - nao)" << endl << endl;
                    string rpt {};
                    getline(cin, rpt);
                    if (rpt == "s") {
                        cout << endl;
                        try {
                            adiciona_emprestimo_ids(id_lv, id_lt, utilizador_online->get_ID());
                        }
                        catch (Object_nao_existe &ob) {
                            ostringstream ostr{};
                            ostr << ob;
                            cout << ostr.str();
                        }
                        catch (Livro_indisponivel &liv) {
                            ostringstream ostr {};
                            ostr << liv;
                            cout << ostr.str();
                        }
                    }
                }
            }
            cout << endl;
        }
   	}
}

void Menu::pedidos_desistir() {
    bool continuar {true};
    while (continuar) {
        cout << "Remover Pedido (s para sair)" << endl << endl;
        cout << "ID do Pedido: ";
        string id_pd_s {};
        unsigned long id_pd{};
        getline(cin, id_pd_s);
        if (id_pd_s == "s") {
            clear_screen();
            continuar=false;
        }
        else if (!e_numero(id_pd_s)) cout << endl << "Por favor insira um numero." << endl << endl;
        else {
            id_pd = atol(id_pd_s.c_str());
            try {
                desiste_pedido(id_pd);
            }
            catch(Object_nao_existe &ob) {
                ostringstream ostr{};
                ostr << ob;
                cout << ostr.str();
                cout << "Por favor insira o ID de um pedido existente." << endl;
            }
            cout << endl;
        }
    }
}

void Menu::pedidos_antigos() const {
    cout << imprime_pedidos_old();
}

void Menu::livros_disponiveis() {
    bool continuar {true};
    while (continuar) {
        cout << "LIVROS DISPONIVEIS" << endl << endl;
        cout << "1) Ano Edicao" << endl
        << "2) Titulo" << endl
        << "3) Autores" << endl;
        cout << endl << "Escolha uma opcao [1-3] (s para sair): ";
        string opcaos {};
        int opcao{};
        getline(cin, opcaos);
        clear_screen();
        if (opcaos == "s") continuar=false;
        else if (!e_numero(opcaos)) cout
            << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)."
            << endl << endl;
        else {
            opcao = atoi(opcaos.c_str());
            switch (opcao) {
                case 1:
                    livros_disponiveis_ano();
                    break;
                case 2:
                    livros_disponiveis_titulo();
                    break;
                case 3:
                    livros_disponiveis_autores();
                    break;

                default:
                    cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
                    break;
            }
        }
   	}
}

void Menu::livros_disponiveis_ano() {
    set_ordem(0);
    adiciona_disponiveis();
    cout << imprime_livros_disponiveis();
}

void Menu::livros_disponiveis_titulo() {
    set_ordem(1);
    adiciona_disponiveis();
    cout << imprime_livros_disponiveis();
}

void Menu::livros_disponiveis_autores() {
    set_ordem(2);
    adiciona_disponiveis();
    cout << imprime_livros_disponiveis();
}

void Menu::livros_emprestados() const {
	cout << imprime_livros_emprestados();
}

void Menu::livros_tema() const {
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

void Menu::livros_antigos() const {
	cout << imprime_livros_old();
}

void Menu::livros_adicionar() {
    bool continuar {true};
    while (continuar) {
        cout << "ADICIONAR LIVRO" << endl << endl;
        cout << "1) Novo livro (nunca existiu na biblioteca)" << endl
             << "2) Exemplar (existe ou ja existiu na biblioteca)" << endl;
        cout << endl << "Escolha uma opcao [1-2] (s para sair): ";
        string opcaos {};
        int opcao{};
        getline(cin, opcaos);
        clear_screen();
        if (opcaos == "s") continuar=false;
        else if (!e_numero(opcaos)) cout
            << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)."
            << endl << endl;
        else {
            opcao = atoi(opcaos.c_str());
            switch (opcao) {
                case 1:
                    livros_adicionar_novo();
                    break;
                case 2:
                    livros_adicionar_exemplar();
                    break;
                default:
                    cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)."
                    << endl << endl;
                    break;
            }
        }
   	}
}

void Menu::livros_adicionar_novo() {
	bool continuar {true};
    while (continuar) {
    	cout << "Adicionar Livro (s para sair)" << endl << endl;
        string anos {};
        cout << "Ano Edicao: ";
        getline (cin, anos);
        if (anos == "s") {
            clear_screen();
            continuar = false;
        }
        else if (!e_numero(anos)) cout << endl << "Por favor insira um numero no Ano Edicao."
            << endl << endl;
        else {
            int ano {atoi (anos.c_str())};
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
                        else if (!e_numero(isbns)) cout << endl <<
                            "Por favor insira um numero no ISBN." << endl << endl;
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
                                else if (!e_numero(num_pags)) cout << endl
                                    << "Por favor insira um numero no Num. Paginas."
                                    << endl << endl;
                                else {
                                    int num_pag = atoi(num_pags.c_str());
                                    string edis {};
                                    cout << "Edicao: ";
                                    getline (cin, edis);
                                    if (edis == "s") {
                                        clear_screen();
                                        continuar = false;
                                    }
                                    else if (!e_numero(edis)) cout << endl
                                        << "Por favor insira um numero na Edicao."
                                        << endl << endl;
                                    else {
                                        int edi = atoi(edis.c_str());
                                        Livro* lv = new Livro{ano, tit, aut, tem, isbn, cot, num_pag, edi, true};
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
}

void Menu::livros_adicionar_exemplar() {
    bool continuar {true};
    while (continuar) {
        cout << "Adicionar Exemplar (s para sair)" << endl << endl;
        string ids {};
        unsigned long id {};
        cout << "ID do Livro: ";
        getline (cin, ids);
        if (ids == "s") {
            clear_screen();
            continuar = false;
        }
        else if (!e_numero(ids)) cout << endl << "Por favor insira um numero."
            << endl << endl;
        else {
            id = atol(ids.c_str());
            Livro* lv {};
            try {
                lv = adiciona_exemplar(id);
            }
            catch(Object_nao_existe &ob) {
                ostringstream ostr{};
                ostr << ob;
                cout << ostr.str();
                cout << "Por favor insira o ID de um livro atual ou antigo." << endl;
            }
            cout << endl;
            while (lv->get_pedidos().size()>0 and
                   lv->get_ex_disponiveis()>0) {
                Pedido pd {lv->get_pedidos().top()};
                cout << "Existe um pedido em espera para este livro: " << endl << endl;
                cout << "LEITOR" << endl;
                cout << (pd.get_leitor())->imprime() << endl;
                cout << "Deseja fazer emprestimo? (s - sim, n - nao)" << endl << endl;
                string rpt {};
                getline(cin, rpt);
                if (rpt == "s") {
                    cout << endl;
                    try {
                        adiciona_emprestimo_ids(pd.get_livro()->get_ID(),
                                                pd.get_leitor()->get_ID(),
                                                utilizador_online->get_ID());
                    }
                    catch (Object_nao_existe &ob) {
                        ostringstream ostr {};
                        ostr << ob;
                        cout << ostr.str();
                    }
                    catch (Livro_indisponivel &liv) {
                        ostringstream ostr {};
                        ostr << liv;
                        cout << ostr.str();
                    }
                }
                try {
                    remove_pedido(pd.get_ID());
                }
                catch (Object_nao_existe &ob) {
                    ostringstream ostr {};
                    ostr << ob;
                    cout << ostr.str();
                }
                catch (Pedido_nao_prioritario &pd) {
                    ostringstream ostr {};
                    ostr << pd;
                    cout << ostr.str();
                }
                cout << endl;
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
    	unsigned long id{};
        getline(cin, ids);
    	if (ids == "s") {
			clear_screen();
			continuar=false;
    	}
    	else if (!e_numero(ids)) cout << endl << "Por favor insira um numero no ID."
            << endl << endl;
    	else {
    		id = atol(ids.c_str());
            cout << "Indice do exemplar: ";
            string inds {};
            getline (cin, inds);
            if (inds == "s") {
                clear_screen();
                continuar = false;
            }
            else if (!e_numero(inds)) cout << endl << "Por favor insira um numero no indice."
                << endl << endl;
            else {
                unsigned long ind = atol(inds.c_str());
                try {
                    remove_livro(id, ind);
                }
                catch(Livro_emprestado &lv) {
                    ostringstream ostr{};
					ostr << lv;
					cout << ostr.str();
    				cout << "Por favor devolva o emprestimo antes de remover o exemplar." << endl;
                }
                catch(Exemplar_inexistente &lv) {
                    ostringstream ostr{};
                    ostr << lv;
                    cout << ostr.str();
                    cout << "Por favor escolha o indice de um exemplar existente." << endl;
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
}

void Menu::livros_alterar() {
    bool continuar {true};
    while (continuar) {
        cout << "ALTERAR LIVROS" << endl << endl;
        cout << "1) Ano Edicao" << endl
        << "2) Titulo" << endl
        << "3) Autores" << endl
        << "4) Tema" << endl
        << "5) ISBN" << endl
        << "6) Cota" << endl
        << "7) Num. Paginas" << endl
        << "8) Edicao" << endl
        << "9) Tudo" << endl;
        cout << endl << "Escolha uma opcao [1-9] (s para sair): ";
        string opcaos {};
        int opcao{};
        getline(cin, opcaos);
        clear_screen();
        if (opcaos == "s") continuar=false;
        else if (!e_numero(opcaos)) cout
            << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)."
            << endl << endl;
        else {
            opcao = atoi(opcaos.c_str());
            switch (opcao) {
                case 1:
                    livros_alterar_ano();
                    break;
                case 2:
                    livros_alterar_titulo();
                    break;
                case 3:
                    livros_alterar_autores();
                    break;
                case 4:
                    livros_alterar_tema();
                    break;
                case 5:
                    livros_alterar_ISBN();
                    break;
                case 6:
                    livros_alterar_cota();
                    break;
                case 7:
                    livros_alterar_num_paginas();
                    break;
                case 8:
                    livros_alterar_edicao();
                    break;
                case 9:
                    livros_alterar_tudo();
                    break;
                default:
                    cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
                    break;
            }
        }
   	}
}

void Menu::livros_alterar_ano() {
    bool continuar {true};
    while (continuar) {
        cout << "Alterar Ano Edicao Livro (s para sair)" << endl << endl;
        cout << "ID do Livro: ";
        string ids {};
        getline(cin, ids);
        if (ids == "s") {
            clear_screen();
            continuar=false;
        }
        else if (!e_numero(ids)) cout << endl << "Por favor insira um numero." << endl << endl;
        else {
            unsigned long id = atol (ids.c_str());
            string anos {};
            cout << "Ano Edicao: ";
            getline (cin, anos);
            if (anos == "s") {
                clear_screen();
                continuar = false;
            }
            else if (!e_numero(anos)) cout << endl
                << "Por favor insira um numero no Ano Edicao." << endl << endl;
            else {
                int ano = atoi(anos.c_str());
                vector<Livro*> livrs {get_livros()};
                bool encontrado{false};
                for (vector<Livro*>::iterator it = livrs.begin(); it != livrs.end(); it++) {
                    if ((*it)->get_ID() == id) {
                        encontrado = true;
                        remove_disponivel(**it);
                        (*it)->set_ano_edicao(ano);
                        if ((*it)->get_ex_disponiveis() > 0)
                            adiciona_disponivel(**it);
                    }
                }
                if (encontrado) cout << endl << "Ano Edicao do livro alterado." << endl << endl;
                else cout << endl << "Por favor insira o ID de um livro existente."
                    << endl << endl;
            }
        }
   	}
}

void Menu::livros_alterar_titulo() {
    bool continuar {true};
    while (continuar) {
        cout << "Alterar Titulo Livro (s para sair)" << endl << endl;
        cout << "ID do Livro: ";
        string ids {};
        getline(cin, ids);
        if (ids == "s") {
            clear_screen();
            continuar=false;
        }
        else if (!e_numero(ids)) cout << endl << "Por favor insira um numero." << endl << endl;
        else {
            unsigned long id = atol (ids.c_str());
            string tit {};
            cout << "Titulo: ";
            getline (cin, tit);
            if (tit == "s") {
                clear_screen();
                continuar = false;
            }
            else {
                vector<Livro*> livrs {get_livros()};
                bool encontrado{false};
                for (vector<Livro*>::iterator it = livrs.begin(); it != livrs.end(); it++) {
                    if ((*it)->get_ID() == id) {
                        encontrado = true;
                        remove_disponivel(**it);
                        (*it)->set_titulo(tit);
                        if ((*it)->get_ex_disponiveis() > 0)
                            adiciona_disponivel(**it);
                    }
                }
                if (encontrado) cout << endl << "Titulo do livro alterado." << endl << endl;
                else cout << endl << "Por favor insira o ID de um livro existente."
                    << endl << endl;
            }
        }
   	}
}

void Menu::livros_alterar_autores() {
    bool continuar {true};
    while (continuar) {
        cout << "Alterar Autores Livro (s para sair)" << endl << endl;
        cout << "ID do Livro: ";
        string ids {};
        getline(cin, ids);
        if (ids == "s") {
            clear_screen();
            continuar=false;
        }
        else if (!e_numero(ids)) cout << endl << "Por favor insira um numero." << endl << endl;
        else {
            unsigned long id = atol (ids.c_str());
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
                vector<Livro*> livrs {get_livros()};
                bool encontrado{false};
                for (vector<Livro*>::iterator it = livrs.begin(); it != livrs.end(); it++) {
                    if ((*it)->get_ID() == id) {
                        encontrado = true;
                        remove_disponivel(**it);
                        (*it)->set_autores(aut);
                        if ((*it)->get_ex_disponiveis() > 0)
                            adiciona_disponivel(**it);
                    }
                }
                if (encontrado) cout << endl << "Autores do livro alterados." << endl << endl;
                else cout << endl << "Por favor insira o ID de um livro existente."
                    << endl << endl;
            }
        }
   	}
}

void Menu::livros_alterar_tema() {
    bool continuar {true};
    while (continuar) {
        cout << "Alterar Tema Livro (s para sair)" << endl << endl;
        cout << "ID do Livro: ";
        string ids {};
        getline(cin, ids);
        if (ids == "s") {
            clear_screen();
            continuar=false;
        }
        else if (!e_numero(ids)) cout << endl << "Por favor insira um numero." << endl << endl;
        else {
            unsigned long id = atol (ids.c_str());
            string tem {};
            cout << "Tema: ";
            getline (cin, tem);
            if (tem == "s") {
                clear_screen();
                continuar = false;
            }
            else {
                vector<Livro*> livrs {get_livros()};
                bool encontrado{false};
                for (vector<Livro*>::iterator it = livrs.begin(); it != livrs.end(); it++) {
                    if ((*it)->get_ID() == id) {
                        encontrado = true;
                        remove_disponivel(**it);
                        (*it)->set_tema(tem);
                        if ((*it)->get_ex_disponiveis() > 0)
                            adiciona_disponivel(**it);
                    }
                }
                if (encontrado) cout << endl << "Tema do livro alterado." << endl << endl;
                else cout << endl << "Por favor insira o ID de um livro existente."
                    << endl << endl;
            }
        }
   	}
}

void Menu::livros_alterar_ISBN() {
    bool continuar {true};
    while (continuar) {
        cout << "Alterar ISBN Livro (s para sair)" << endl << endl;
        cout << "ID do Livro: ";
        string ids {};
        getline(cin, ids);
        if (ids == "s") {
            clear_screen();
            continuar=false;
        }
        else if (!e_numero(ids)) cout << endl << "Por favor insira um numero." << endl << endl;
        else {
            unsigned long id = atol (ids.c_str());
            string isbns {};
            cout << "ISBN: ";
            getline (cin, isbns);
            if (isbns == "s") {
                clear_screen();
                continuar = false;
            }
            else if (!e_numero(isbns)) cout << endl
                << "Por favor insira um numero no ISBN." << endl << endl;
            else {
                long isbn = atol(isbns.c_str());
                vector<Livro*> livrs {get_livros()};
                bool encontrado{false};
                for (vector<Livro*>::iterator it = livrs.begin(); it != livrs.end(); it++) {
                    if ((*it)->get_ID() == id) {
                        encontrado = true;
                        remove_disponivel(**it);
                        (*it)->set_ISBN(isbn);
                        if ((*it)->get_ex_disponiveis() > 0)
                            adiciona_disponivel(**it);
                    }
                }
                if (encontrado) cout << endl << "ISBN do livro alterado." << endl << endl;
                else cout << endl << "Por favor insira o ID de um livro existente."
                    << endl << endl;
            }
        }
   	}
}

void Menu::livros_alterar_cota() {
    bool continuar {true};
    while (continuar) {
        cout << "Alterar Cota Livro (s para sair)" << endl << endl;
        cout << "ID do Livro: ";
        string ids {};
        getline(cin, ids);
        if (ids == "s") {
            clear_screen();
            continuar=false;
        }
        else if (!e_numero(ids)) cout << endl << "Por favor insira um numero." << endl << endl;
        else {
            unsigned long id = atol (ids.c_str());
            string cot {};
            cout << "Cota: ";
            getline (cin, cot);
            if (cot == "s") {
                clear_screen();
                continuar = false;
            }
            else {
                vector<Livro*> livrs {get_livros()};
                bool encontrado{false};
                for (vector<Livro*>::iterator it = livrs.begin(); it != livrs.end(); it++) {
                    if ((*it)->get_ID() == id) {
                        encontrado = true;
                        remove_disponivel(**it);
                        (*it)->set_cota(cot);
                        if ((*it)->get_ex_disponiveis() > 0)
                            adiciona_disponivel(**it);
                    }
                }
                if (encontrado) cout << endl << "Cota do livro alterada." << endl << endl;
                else cout << endl << "Por favor insira o ID de um livro existente."
                    << endl << endl;
            }
        }
   	}
}

void Menu::livros_alterar_num_paginas() {
    bool continuar {true};
    while (continuar) {
        cout << "Alterar Num. Paginas Livro (s para sair)" << endl << endl;
        cout << "ID do Livro: ";
        string ids {};
        getline(cin, ids);
        if (ids == "s") {
            clear_screen();
            continuar=false;
        }
        else if (!e_numero(ids)) cout << endl << "Por favor insira um numero." << endl << endl;
        else {
            unsigned long id = atol (ids.c_str());
            string nps {};
            cout << "Num. Paginas: ";
            getline (cin, nps);
            if (nps == "s") {
                clear_screen();
                continuar = false;
            }
            else if (!e_numero(nps)) cout << endl
                << "Por favor insira um numero no Ano Edicao." << endl << endl;
            else {
                int np = atoi(nps.c_str());
                vector<Livro*> livrs {get_livros()};
                bool encontrado{false};
                for (vector<Livro*>::iterator it = livrs.begin(); it != livrs.end(); it++) {
                    if ((*it)->get_ID() == id) {
                        encontrado = true;
                        remove_disponivel(**it);
                        (*it)->set_num_paginas(np);
                        if ((*it)->get_ex_disponiveis() > 0)
                            adiciona_disponivel(**it);
                    }
                }
                if (encontrado) cout << endl << "Num. Paginas do livro alterado." << endl << endl;
                else cout << endl << "Por favor insira o ID de um livro existente."
                    << endl << endl;
            }
        }
   	}
}

void Menu::livros_alterar_edicao() {
    bool continuar {true};
    while (continuar) {
        cout << "Alterar Edicao Livro (s para sair)" << endl << endl;
        cout << "ID do Livro: ";
        string ids {};
        getline(cin, ids);
        if (ids == "s") {
            clear_screen();
            continuar=false;
        }
        else if (!e_numero(ids)) cout << endl << "Por favor insira um numero." << endl << endl;
        else {
            unsigned long id = atol (ids.c_str());
            string eds {};
            cout << "Edicao: ";
            getline (cin, eds);
            if (eds == "s") {
                clear_screen();
                continuar = false;
            }
            else if (!e_numero(eds)) cout << endl
                << "Por favor insira um numero no Ano Edicao." << endl << endl;
            else {
                int ed = atoi(eds.c_str());
                vector<Livro*> livrs {get_livros()};
                bool encontrado{false};
                for (vector<Livro*>::iterator it = livrs.begin(); it != livrs.end(); it++) {
                    if ((*it)->get_ID() == id) {
                        encontrado = true;
                        remove_disponivel(**it);
                        (*it)->set_edicao(ed);
                        if ((*it)->get_ex_disponiveis() > 0)
                            adiciona_disponivel(**it);
                    }
                }
                if (encontrado) cout << endl << "Edicao do livro alterada." << endl << endl;
                else cout << endl << "Por favor insira o ID de um livro existente."
                    << endl << endl;
            }
        }
   	}
}

void Menu::livros_alterar_tudo() {
    bool continuar {true};
    while (continuar) {
        cout << "Alterar Livro (s para sair)" << endl << endl;
        cout << "ID do Livro: ";
        string ids {};
        getline(cin, ids);
        if (ids == "s") {
            clear_screen();
            continuar=false;
        }
        else if (!e_numero(ids)) cout << endl << "Por favor insira um numero." << endl << endl;
        else {
            unsigned long id = atol (ids.c_str());
            cout << "Ano Edicao: ";
            string anos {};
            getline(cin, anos);
            if (anos == "s") {
                clear_screen();
                continuar=false;
            }
            else if (!e_numero(anos)) cout << endl << "Por favor insira um numero no Ano Edicao." << endl << endl;
            else {
                int ano = atoi (anos.c_str());
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
                            cout << "ISBN : ";
                            getline (cin, isbns);
                            if (isbns == "s") {
                                clear_screen();
                                continuar = false;
                            }
                            else if (!e_numero(isbns)) cout << endl
                                << "Por favor insira um numero no ISBN." << endl << endl;
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
                                    string nps {};
                                    cout << "Num. Paginas : ";
                                    getline (cin, nps);
                                    if (nps == "s") {
                                        clear_screen();
                                        continuar = false;
                                    }
                                    else if (!e_numero(nps)) cout << endl
                                        << "Por favor insira um numero no Num. Paginas." << endl << endl;
                                    else {
                                        int np = atoi(nps.c_str());
                                        string eds {};
                                        cout << "Edicao : ";
                                        getline (cin, eds);
                                        if (eds == "s") {
                                            clear_screen();
                                            continuar = false;
                                        }
                                        else if (!e_numero(eds)) cout << endl
                                            << "Por favor insira um numero no ISBN." << endl << endl;
                                        else {
                                            int ed = atoi(eds.c_str());
                                            vector<Livro*> livrs {get_livros()};
                                            bool encontrado{false};
                                            for (vector<Livro*>::iterator it = livrs.begin();
                                                 it != livrs.end(); it++) {
                                                if ((*it)->get_ID() == id) {
                                                    encontrado = true;
                                                    remove_disponivel(**it);
                                                    (*it)->set_ano_edicao(ano);
                                                    (*it)->set_titulo(tit);
                                                    (*it)->set_autores(aut);
                                                    (*it)->set_tema(tem);
                                                    (*it)->set_ISBN(isbn);
                                                    (*it)->set_cota(cot);
                                                    (*it)->set_num_paginas(np);
                                                    (*it)->set_edicao(ed);
                                                    if ((*it)->get_ex_disponiveis() > 0)
                                                        adiciona_disponivel(**it);
                                                }
                                            }
                                            if (encontrado) cout << endl << "Livro alterado."
                                                << endl << endl;
                                            else cout << endl
                                                << "Por favor insira o ID de um livro existente."
                                                << endl << endl;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
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
        	string tips {};
        	cout << "Tipo (0 - Estudante, 1 - Crianca, 2 - Adulto): ";
        	getline (cin, tips);
        	if (tips == "s") {
        		clear_screen();
        		continuar = false;
        	}
        	else if (tips != "0" and tips != "1" and tips != "2") cout << endl
        			<< "Por favor insira um numero entre 0 e 2 no Tipo." << endl << endl;
        	else {
				int tip = atoi(tips.c_str());
				string tels {};
				cout << "Telefone: ";
				getline (cin, tels);
				if (tels == "s") {
					clear_screen();
					continuar = false;
				}
				else if (!e_numero(tels)) cout << endl << "Por favor insira um numero no Telefone." << endl << endl;
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
                        string mrd {};
                        cout << "Morada: ";
                        getline (cin, mrd);
                        if (mrd == "s") {
                            clear_screen();
                            continuar = false;
                        }
                        else {
                            Leitor* lt = new Leitor{nom, tip, tel, eml, mrd, time(0), true};
                            cout << endl;
                            adiciona_leitor(lt);
                            cout << endl;
                        }
					}
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
    	unsigned long id{};
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
        cout << "ALTERAR LEITORES" << endl << endl;
        cout << "1) Nome" << endl
        << "2) Tipo" << endl
        << "3) Telefone" << endl
        << "4) Email" << endl
        << "5) Morada" << endl
        << "6) Tudo" << endl;
        cout << endl << "Escolha uma opcao [1-6] (s para sair): ";
        string opcaos {};
        int opcao{};
        getline(cin, opcaos);
        clear_screen();
        if (opcaos == "s") continuar=false;
        else if (!e_numero(opcaos)) cout
            << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)."
            << endl << endl;
        else {
            opcao = atoi(opcaos.c_str());
            switch (opcao) {
                case 1:
                    leitores_alterar_nome();
                    break;
                case 2:
                    leitores_alterar_tipo();
                    break;
                case 3:
                    leitores_alterar_telefone();
                    break;
                case 4:
                    leitores_alterar_email();
                    break;
                case 5:
                    leitores_alterar_morada();
                    break;
                case 6:
                    leitores_alterar_tudo();
                    break;
                default:
                    cout << "Opcao nao esta disponivel. Por favor escolha outra opcao (s para sair)." << endl << endl;
                    break;
            }
        }
   	}
}

void Menu::leitores_alterar_nome() {
    bool continuar {true};
    while (continuar) {
        cout << "Alterar Nome Leitor (s para sair)" << endl << endl;
        cout << "ID do Leitor: ";
        string ids {};
        getline(cin, ids);
        if (ids == "s") {
            clear_screen();
            continuar=false;
        }
        else if (!e_numero(ids)) cout << endl << "Por favor insira um numero." << endl << endl;
        else {
            unsigned long id = atol (ids.c_str());
            string nom {};
            cout << "Nome: ";
            getline (cin, nom);
            if (nom == "s") {
                clear_screen();
                continuar = false;
            }
            else {
                vector<Leitor*> leitors {get_leitores()};
                bool encontrado{false};
                for (vector<Leitor*>::iterator it = leitors.begin(); it != leitors.end(); it++) {
                    if ((*it)->get_ID() == id) {
                        encontrado = true;
                        remove_inativo(**it);
                        (*it)->set_nome(nom);
                        double tempo_dias {floor(difftime(time(0), (*it)->get_data_ult_emp())/86400)};
                        if (tempo_dias > 365) adiciona_inativo(**it);
                    }
                }
                if (encontrado) cout << endl << "Nome do leitor alterado." << endl << endl;
                else cout << endl << "Por favor insira o ID de um leitor existente."
                    << endl << endl;
            }
        }
   	}
}

void Menu::leitores_alterar_tipo() {
    bool continuar {true};
    while (continuar) {
        cout << "Alterar Tipo Leitor (s para sair)" << endl << endl;
        cout << "ID do Leitor: ";
        string ids {};
        getline(cin, ids);
        if (ids == "s") {
            clear_screen();
            continuar=false;
        }
        else if (!e_numero(ids)) cout << endl << "Por favor insira um numero." << endl << endl;
        else {
            unsigned long id = atol (ids.c_str());
            string tips {};
            cout << "Tipo (0 - Estudante, 1 - Crianca, 2 - Adulto): ";
            getline (cin, tips);
            if (tips == "s") {
                clear_screen();
                continuar = false;
            }
            else if (tips != "0" and tips != "1" and tips != "2") cout << endl
                << "Por favor insira um numero entre 0 e 2 no Tipo." << endl << endl;
            else {
                int tip = atoi(tips.c_str());
                vector<Leitor*> leitors {get_leitores()};
                bool encontrado{false};
                for (vector<Leitor*>::iterator it = leitors.begin(); it != leitors.end(); it++) {
                    if ((*it)->get_ID() == id) {
                        encontrado = true;
                        remove_inativo(**it);
                        (*it)->set_tipo(tip);
                        double tempo_dias {floor(difftime(time(0), (*it)->get_data_ult_emp())/86400)};
                        if (tempo_dias > 365) adiciona_inativo(**it);
                    }
                }
                if (encontrado) cout << endl << "Tipo do leitor alterado." << endl << endl;
                else cout << endl << "Por favor insira o ID de um leitor existente."
                    << endl << endl;
            }
        }
   	}
}

void Menu::leitores_alterar_telefone() {
    bool continuar {true};
    while (continuar) {
        cout << "Alterar Telefone Leitor (s para sair)" << endl << endl;
        cout << "ID do Leitor: ";
        string ids {};
        getline(cin, ids);
        if (ids == "s") {
            clear_screen();
            continuar=false;
        }
        else if (!e_numero(ids)) cout << endl << "Por favor insira um numero." << endl << endl;
        else {
            unsigned long id = atol (ids.c_str());
            string tels {};
            cout << "Telefone : ";
            getline (cin, tels);
            if (tels == "s") {
                clear_screen();
                continuar = false;
            }
            else if (!e_numero(tels)) cout << endl
                << "Por favor insira um numero no telefone." << endl << endl;
            else {
                long tel = atol(tels.c_str());
                vector<Leitor*> leitors {get_leitores()};
                bool encontrado{false};
                for (vector<Leitor*>::iterator it = leitors.begin(); it != leitors.end(); it++) {
                    if ((*it)->get_ID() == id) {
                        encontrado = true;
                        remove_inativo(**it);
                        (*it)->set_telefone(tel);
                        double tempo_dias {floor(difftime(time(0), (*it)->get_data_ult_emp())/86400)};
                        if (tempo_dias > 365) adiciona_inativo(**it);
                    }
                }
                if (encontrado) cout << endl << "Telefone do leitor alterado." << endl << endl;
                else cout << endl << "Por favor insira o ID de um leitor existente."
                    << endl << endl;
            }
        }
   	}
}

void Menu::leitores_alterar_email() {
    bool continuar {true};
    while (continuar) {
        cout << "Alterar Email Leitor (s para sair)" << endl << endl;
        cout << "ID do Leitor: ";
        string ids {};
        getline(cin, ids);
        if (ids == "s") {
            clear_screen();
            continuar=false;
        }
        else if (!e_numero(ids)) cout << endl << "Por favor insira um numero." << endl << endl;
        else {
            unsigned long id = atol (ids.c_str());
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
                for (vector<Leitor*>::iterator it = leitors.begin(); it != leitors.end(); it++) {
                    if ((*it)->get_ID() == id) {
                        encontrado = true;
                        remove_inativo(**it);
                        (*it)->set_email(eml);
                        double tempo_dias {floor(difftime(time(0), (*it)->get_data_ult_emp())/86400)};
                        if (tempo_dias > 365) adiciona_inativo(**it);
                    }
                }
                if (encontrado) cout << endl << "Email do leitor alterado." << endl << endl;
                else cout << endl << "Por favor insira o ID de um leitor existente."
                    << endl << endl;
            }
        }
   	}
}

void Menu::leitores_alterar_morada() {
    bool continuar {true};
    while (continuar) {
        cout << "Alterar Morada Leitor (s para sair)" << endl << endl;
        cout << "ID do Leitor: ";
        string ids {};
        getline(cin, ids);
        if (ids == "s") {
            clear_screen();
            continuar=false;
        }
        else if (!e_numero(ids)) cout << endl << "Por favor insira um numero." << endl << endl;
        else {
            unsigned long id = atol (ids.c_str());
            string mrd {};
            cout << "Morada: ";
            getline (cin, mrd);
            if (mrd == "s") {
                clear_screen();
                continuar = false;
            }
            else {
                vector<Leitor*> leitors {get_leitores()};
                bool encontrado{false};
                for (vector<Leitor*>::iterator it = leitors.begin(); it != leitors.end(); it++) {
                    if ((*it)->get_ID() == id) {
                        encontrado = true;
                        remove_inativo(**it);
                        (*it)->set_morada(mrd);
                        double tempo_dias {floor(difftime(time(0), (*it)->get_data_ult_emp())/86400)};
                        if (tempo_dias > 365) adiciona_inativo(**it);
                    }
                }
                if (encontrado) cout << endl << "Morada do leitor alterada." << endl << endl;
                else cout << endl << "Por favor insira o ID de um leitor existente."
                    << endl << endl;
            }
        }
   	}
}

void Menu::leitores_alterar_tudo() {
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
    		unsigned long id = atol (ids.c_str());
    		string nom {};
    		cout << "Nome: ";
    		getline (cin, nom);
    		if (nom == "s") {
    			clear_screen();
    			continuar = false;
    		}
    		else {
                string tips {};
                cout << "Tipo (0 - Estudante, 1 - Crianca, 2 - Adulto): ";
                getline (cin, tips);
                if (tips == "s") {
                    clear_screen();
                    continuar = false;
                }
                else if (tips != "0" and tips != "1" and tips != "2") cout << endl
                    << "Por favor insira um numero entre 0 e 2 no Tipo." << endl << endl;
                else {
                    int tip = atoi(tips.c_str());
                    string tels {};
                    cout << "Telefone : ";
                    getline (cin, tels);
                    if (tels == "s") {
                        clear_screen();
                        continuar = false;
                    }
                    else if (!e_numero(tels)) cout << endl
    					<< "Por favor insira um numero no telefone." << endl << endl;
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
                            string mrd {};
                            cout << "Morada: ";
                            getline (cin, mrd);
                            if (mrd == "s") {
                                clear_screen();
                                continuar = false;
                            }
                            else {
                                vector<Leitor*> leitors {get_leitores()};
                                bool encontrado{false};
                                for (vector<Leitor*>::iterator it = leitors.begin();
                                     it != leitors.end(); it++) {
                                    if ((*it)->get_ID() == id) {
                                        encontrado = true;
                                        remove_inativo(**it);
                                        (*it)->set_nome(nom);
                                        (*it)->set_tipo(tip);
                                        (*it)->set_telefone(tel);
                                        (*it)->set_email(eml);
                                        (*it)->set_morada(mrd);
                                        double tempo_dias
                                            {floor(difftime(time(0), (*it)->get_data_ult_emp())/86400)};
                                        if (tempo_dias > 365) adiciona_inativo(**it);
                                    }
                                }
                                if (encontrado) cout << endl << "Leitor alterado."
                                    << endl << endl;
                                else cout << endl
                                    << "Por favor insira o ID de um leitor existente."
                                    << endl << endl;
                            }
                        }
    				}
            	}
    		}
    	}
   	}
}

void Menu::leitores_inativos() const {
    cout << imprime_leitores_inativos();
}

void Menu::leitores_antigos() const {
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
    	unsigned long id{};
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
    	unsigned long id{};
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
    	unsigned long id{};
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

void Menu::funcionarios_antigos() const {
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
    		unsigned long id = atol(ids.c_str());
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
				char *pass=ler_password("Password: ");
				char *pass_c=ler_password("Repetir Password: ");
				if (pass != pass_c) {
					cout << endl << "As passwords que introduziu nao coincidem. Por favor tente novamente."
							<< endl << endl;
				}
				else {
			    	string aces{};
					cout << "Nivel de acesso (0, 1, 2): ";
			    	getline (cin, aces);
			    	if (ids == "s") {
						clear_screen();
						continuar = false;
			    	}
			    	else if (!e_numero(aces)) cout << endl << "Por favor insira um numero entre 0 e 2."
			    			<< endl << endl;
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
    	unsigned long id{};
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



