/*
#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include <fstream>
#include <iostream>
#include <fstream>
#include "time.h"
#include "Biblio.h"

using namespace std;

void test_a_criar_livros() {
	//ID, titulo, autores, ISBN, cota, num_paginas, edicao, emprestado, dias_indisponivel
	vector<string> a1 {"Saramago, Jose"};
	Livro* l1=new Livro {1,"O Evangelho Segundo Jesus Cristo",a1,"Romance",9722105248,
		"821.134.3 SARj/EVA 13", 445, 13, false, 0};
	vector<string> a2 {"Couto, Mia"};
	Livro* l2=new Livro {2,"A chuva pasmada",a2,"Romance",9722116541,
		"821.134.3(679) /COUm/CHU", 74, 1, false, 0};
	vector<string> a3 {"Hopcroft, John E.", "Motwani, Rajeev", "Ullman, Jeffrey D."};
	Livro* l3=new Livro {3,"Introduction to automata theory, languages, and computation",a3,"Matematica",201441241,
		"519.6 /HOPj/INT 2", 521, 2, false, 0};
	ASSERT_EQUAL("O Evangelho Segundo Jesus Cristo", l1->get_titulo());
	ASSERT_EQUAL(2, l2->get_ID());
	ASSERT_EQUAL(201441241,l3->get_ISBN());
	ASSERT_EQUAL("519.6 /HOPj/INT 2",l3->get_cota());
	ASSERT_EQUAL(74, l2->get_num_paginas());
	ASSERT_EQUAL(13, l1->get_edicao());
	ASSERT_EQUAL("Motwani, Rajeev", l3->get_autores()[1]);
	ASSERT_EQUAL(false, l2->get_emprestado());
	ASSERT_EQUAL(0,l1->get_data_emp());
}

void test_b_adicionar_livros() {
	Biblioteca b1 {};
	vector<string> a1 {"Pacheco, Helder"};
	Livro* l1=new Livro {1,"Porto em Azul e Branco",a1,"Futebol",9789723611199,
		"29.90", 192, 1, false, 0};
	vector<string> a2 {"Saramago, Jose"};
	Livro* l2=new Livro {2,"O Evangelho Segundo Jesus Cristo",a2,"Romance",9722105248,
		"821.134.3 SARj/EVA 13", 445, 13, false, 0};
	vector<string> a3 {"Couto, Mia"};
	Livro* l3=new Livro {3,"A chuva pasmada",a3,"Romance",9722116541,
		"821.134.3(679) /COUm/CHU", 74, 1, false, 0};
	vector<string> a4 {"Hopcroft, John E.", "Motwani, Rajeev", "Ullman, Jeffrey D."};
	Livro* l4=new Livro {4,"Introduction to automata theory, languages, and computation",a4,"Matematica",201441241,
		"519.6 /HOPj/INT 2", 521, 2, false, 0};
	b1.adiciona_livro(l1);
	b1.adiciona_livro(l2);
	b1.adiciona_livro(l3);
	b1.adiciona_livro(l4);
	ASSERT_EQUAL(4, b1.get_livros().size());
}

void test_c_imprimir_livros() {
	vector<string> a3 {"Hopcroft, John E.", "Motwani, Rajeev", "Ullman, Jeffrey D."};
	Livro* l3=new Livro {3,"Introduction to automata theory, languages, and computation",a3,"Matematica",201441241,
		"519.6 /HOPj/INT 2", 521, 2, false, 0};
	stringstream ss {};
	ss << "ID: 3\n"
			<< "Titulo: Introduction to automata theory, languages, and computation\n"
			<< "Autores: Hopcroft, John E.; Motwani, Rajeev; Ullman, Jeffrey D.; \n"
			<< "Tema: Matematica\n"
			<< "ISBN: 201441241\n"
			<< "Cota: 519.6 /HOPj/INT 2\n"
			<< "Num. Paginas: 521\n"
			<< "Edicao: 2\n"
			<< "Emprestado: 0\n"
			<< "Data Emprestado: 0\n";
	//cout << l3->imprime();
	ASSERT_EQUAL(ss.str(), l3->imprime());
}

void test_d_criar_funcionarios() {
	//ID, nome
	Funcionario* f1=new Funcionario {1,"Miguel Bacelar"};
	Funcionario* f2=new Funcionario {2,"Jose Oliveira"};
	Funcionario* f3=new Funcionario {3,"Carlos Alvim"};
	Funcionario* f4=new Funcionario {4,"Fatima Bordonhos"};
	ASSERT_EQUAL(1, f1->get_ID());
	ASSERT_EQUAL(2, f2->get_ID());
	ASSERT_EQUAL("Carlos Alvim",f3->get_nome());
	ASSERT_EQUAL("Fatima Bordonhos",f4->get_nome());
}

void test_e_adicionar_funcionarios() {
	Biblioteca b3 {};
	Funcionario* f1=new Funcionario {1,"Miguel Bacelar"};
	Funcionario* f2=new Funcionario {2,"Jose Oliveira"};
	Funcionario* f3=new Funcionario {3,"Carlos Alvim"};
	Funcionario* f4=new Funcionario {4,"Fatima Bordonhos"};
	Funcionario* f5=new Funcionario {5,"Margarida Soares"};
	Funcionario* f6=new Funcionario {6,"Joana Rocha"};
	Funcionario* f7=new Funcionario {7,"Alexandra Lameira"};
	Funcionario* f8=new Funcionario {8,"Luis Barros"};
	Funcionario* f9=new Funcionario {9,"Angela Monteiro"};
	b3.adiciona_funcionario(f1);
	b3.adiciona_funcionario(f2);
	b3.adiciona_funcionario(f3);
	b3.adiciona_funcionario(f4);
	b3.adiciona_funcionario(f5);
	b3.adiciona_funcionario(f6);
	b3.adiciona_funcionario(f7);
	b3.adiciona_funcionario(f8);
	b3.adiciona_funcionario(f9);
	ASSERT_EQUAL(9, b3.get_funcionarios().size());
}

void test_f_imprimir_funcionarios() {
	Funcionario* f8=new Funcionario {8,"Luis Barros"};
	stringstream ss {};
	ss << "ID: 8\n"
			<< "Nome: Luis Barros\n";
	//cout << f8->imprime();
	ASSERT_EQUAL(ss.str(), f8->imprime());
}

void test_g_promover_funcionarios() {
	Biblioteca b4 {};
	Funcionario* f1=new Funcionario {1,"Miguel Bacelar"};
	Funcionario* f2=new Funcionario {2,"Jose Oliveira"};
	Funcionario* f3=new Funcionario {3,"Carlos Alvim"};
	Funcionario* f4=new Funcionario {4,"Fatima Bordonhos"};
	Funcionario* f5=new Funcionario {5,"Margarida Soares"};
	Funcionario* f6=new Funcionario {6,"Joana Rocha"};
	Funcionario* f7=new Funcionario {7,"Alexandra Lameira"};
	Funcionario* f8=new Funcionario {8,"Luis Barros"};
	Funcionario* f9=new Funcionario {9,"Angela Monteiro"};
	Funcionario* f10=new Funcionario {10,"Andre Martins"};
	Funcionario* f11=new Funcionario {11,"Celia Ferreira"};
	Funcionario* f12=new Funcionario {12,"Hortensia Costa"};
	Funcionario* f13=new Funcionario {13,"Helia Costa"};
	Funcionario* f14=new Funcionario {14,"Maria Sousa"};
	Funcionario* f15=new Funcionario {15,"Sergio Dias"};
	Funcionario* f16=new Funcionario {16,"Isabel Pinto"};
	Funcionario* f17=new Funcionario {17,"Lara Lacerda"};
	b4.adiciona_funcionario(f1);
	b4.adiciona_funcionario(f2);
	b4.adiciona_funcionario(f3);
	b4.adiciona_funcionario(f4);
	b4.adiciona_funcionario(f5);
	b4.adiciona_funcionario(f6);
	b4.adiciona_funcionario(f7);
	b4.adiciona_funcionario(f8);
	b4.adiciona_funcionario(f9);
	b4.adiciona_funcionario(f10);
	b4.adiciona_funcionario(f11);
	b4.adiciona_funcionario(f12);
	b4.adiciona_funcionario(f13);
	b4.adiciona_funcionario(f14);
	b4.adiciona_funcionario(f15);
	b4.adiciona_funcionario(f16);
	b4.adiciona_funcionario(f17);
	ASSERT_EQUAL(b4.promove_funcionario_supervisor(3), true);
	ASSERT_EQUAL(b4.promove_funcionario_supervisor(5), true);
	ASSERT_EQUAL(b4.promove_funcionario_supervisor(10), true);
	ASSERT_EQUAL(b4.promove_funcionario_supervisor(20), false);
	ASSERT_EQUAL(5, (b4.get_supervisores()[0])->get_func_sup().size());
	ASSERT_EQUAL(5, (b4.get_supervisores()[1])->get_func_sup().size());
	ASSERT_EQUAL(4, (b4.get_supervisores()[2])->get_func_sup().size());
	stringstream ss {};
	ss << "ID: 5\n"
			<< "Nome: Margarida Soares\n"
			<< "ID Funcionarios: 2; 7; 11; 14; 17; \n";
	ASSERT_EQUAL(ss.str(), b4.get_supervisores()[1]->imprime());
}

void test_h_criar_adicionar_imprimir_escrever_leitor() {
	Biblioteca b5 {};
	Funcionario* f1=new Funcionario {1,"Miguel Bacelar"};
	Funcionario* f2=new Funcionario {2,"Jose Oliveira"};
	Funcionario* f3=new Funcionario {3,"Carlos Alvim"};
	Funcionario* f4=new Funcionario {4,"Fatima Bordonhos"};
	Funcionario* f5=new Funcionario {5,"Margarida Soares"};
	Funcionario* f6=new Funcionario {6,"Joana Rocha"};
	Funcionario* f7=new Funcionario {7,"Alexandra Lameira"};
	Funcionario* f8=new Funcionario {8,"Luis Barros"};
	Funcionario* f9=new Funcionario {9,"Angela Monteiro"};
	Funcionario* f10=new Funcionario {10,"Andre Martins"};
	Funcionario* f11=new Funcionario {11,"Celia Ferreira"};
	Funcionario* f12=new Funcionario {12,"Hortensia Costa"};
	Funcionario* f13=new Funcionario {13,"Helia Costa"};
	Funcionario* f14=new Funcionario {14,"Maria Sousa"};
	Funcionario* f15=new Funcionario {15,"Sergio Dias"};
	Funcionario* f16=new Funcionario {16,"Isabel Pinto"};
	Funcionario* f17=new Funcionario {17,"Lara Lacerda"};
	b5.adiciona_funcionario(f1);
	b5.adiciona_funcionario(f2);
	b5.adiciona_funcionario(f3);
	b5.adiciona_funcionario(f4);
	b5.adiciona_funcionario(f5);
	b5.adiciona_funcionario(f6);
	b5.adiciona_funcionario(f7);
	b5.adiciona_funcionario(f8);
	b5.adiciona_funcionario(f9);
	b5.adiciona_funcionario(f10);
	b5.adiciona_funcionario(f11);
	b5.adiciona_funcionario(f12);
	b5.adiciona_funcionario(f13);
	b5.adiciona_funcionario(f14);
	b5.adiciona_funcionario(f15);
	b5.adiciona_funcionario(f16);
	b5.adiciona_funcionario(f17);
	b5.promove_funcionario_supervisor(3);
	b5.promove_funcionario_supervisor(5);
	b5.promove_funcionario_supervisor(10);
	vector<string> a1 {"Pacheco, Helder"};
	Livro* lv1=new Livro {1,"Porto em Azul e Branco",a1,"Futebol",9789723611199,
		"29.90", 192, 1, false, 0};
	vector<string> a2 {"Saramago, Jose"};
	Livro* lv2=new Livro {2,"O Evangelho Segundo Jesus Cristo",a2,"Romance",9722105248,
		"821.134.3 SARj/EVA 13", 445, 13, false, 0};
	vector<string> a3 {"Couto, Mia"};
	Livro* lv3=new Livro {3,"A chuva pasmada",a3,"Romance",9722116541,
		"821.134.3(679) /COUm/CHU", 74, 1, false, 0};
	vector<string> a4 {"Hopcroft, John E.", "Motwani, Rajeev", "Ullman, Jeffrey D."};
	Livro* lv4=new Livro {4,"Introduction to automata theory, languages, and computation",a4,"Matematica",201441241,
		"519.6 /HOPj/INT 2", 521, 2, false, 0};
	b5.adiciona_livro(lv1);
	b5.adiciona_livro(lv2);
	b5.adiciona_livro(lv3);
	b5.adiciona_livro(lv4);
	Leitor* l1=new Leitor {1,"Ines Cunha", 912233444, "inescunha@fe.up.pt"};
	Leitor* l2=new Leitor {2,"Maria Fonseca", 962345444, "mariafonseca@fe.up.pt"};
	Leitor* l3=new Leitor {3,"Ana Moura", 912231234, "anamoura@fe.up.pt"};
	Leitor* l4=new Leitor {4,"Davide Azevedo", 962234244, "davideazevedo@fe.up.pt"};
	Leitor* l5=new Leitor {5,"Pedro Nunes", 912212324, "pedronunes@fe.up.pt"};
	Leitor* l6=new Leitor {6,"Joao Meireles", 962232354, "joaomeireles@fe.up.pt"};
	Leitor* l7=new Leitor {7,"Alexandre Cunha", 963453442, "alexandrecunha@fe.up.pt"};
	Leitor* l8=new Leitor {8,"Andreia Teixeira", 9135634553, "andreiateixeira@fe.up.pt"};
	Leitor* l9=new Leitor {9,"Margarida Carvalho", 912234242, "margaridacarvalho@fe.up.pt"};
	Leitor* l10=new Leitor {10,"Daniel Pereira", 932233244, "danielpereira@fe.up.pt"};
	Leitor* l11=new Leitor {11,"Susana Costa", 912932342, "susanacosta@fe.up.pt"};
	Leitor* l12=new Leitor {12,"Jose Leal", 918475657, "joseleal@fe.up.pt"};
	Leitor* l13=new Leitor {13,"Roberto Silva", 928374644, "robertosilva@fe.up.pt"};
	Leitor* l14=new Leitor {14,"Patricia Ribeiro", 932345994, "patriciaribeiro@fe.up.pt"};
	Leitor* l15=new Leitor {15,"Diana Goncalves", 922989898, "dianagoncalves@fe.up.pt"};
	Leitor* l16=new Leitor {16,"Vanessa Oliveira", 962233434, "vanessaoliveira@fe.up.pt"};
	Leitor* l17=new Leitor {17,"Pedro Almeida", 962253574, "pedroalmeida@fe.up.pt"};
	Leitor* l18=new Leitor {18,"Lino Amorim", 912865432, "linoamorim@fe.up.pt"};
	Leitor* l19=new Leitor {19,"Jorge Almeida", 912678990, "jorgealmeida@fe.up.pt"};
	Leitor* l20=new Leitor {20,"Antonio Vieira", 962256989, "antoniovieira@fe.up.pt"};
	Leitor* l21=new Leitor {21,"Sandra Vieira", 962254354, "sandravieira@fe.up.pt"};
	Leitor* l22=new Leitor {22,"Bruno Rocha", 937654324, "brunorocha@fe.up.pt"};
	Leitor* l23=new Leitor {23,"Viriato Sousa", 928534982, "viriatosousa@fe.up.pt"};
	Leitor* l24=new Leitor {24,"Alzira Pinto", 910934899, "alzirapinto@fe.up.pt"};
	Leitor* l25=new Leitor {25,"Edmundo Santos", 910998768, "edmundosantos@fe.up.pt"};
	Leitor* l26=new Leitor {26,"Maria Mendes", 968748347, "mariamendes@fe.up.pt"};
	Leitor* l27=new Leitor {27,"Catarina Pereira", 939838488, "catarinapereira@fe.up.pt"};
	Leitor* l28=new Leitor {28,"Luisa Pereira", 928787879, "luisapereira@fe.up.pt"};
	Leitor* l29=new Leitor {29,"Nuno Cardoso", 969898239, "nunocardoso@fe.up.pt"};
	Leitor* l30=new Leitor {30,"Rita Rio", 919888388, "ritario@fe.up.pt"};
	Leitor* l31=new Leitor {31,"Mario Almeida", 932309922, "marioalmeida@fe.up.pt"};
	Leitor* l32=new Leitor {32,"Rogerio Cunha", 939999982, "rogeriocunha@fe.up.pt"};
	Leitor* l33=new Leitor {33,"Leonor Moreira", 932233444, "leonormoreira@fe.up.pt"};
	Leitor* l34=new Leitor {34,"Barbara Furtado", 962233444, "barbarafurtado@fe.up.pt"};
	Leitor* l35=new Leitor {35,"Gil Sousa", 962237744, "gilsousa@fe.up.pt"};
	Leitor* l36=new Leitor {36,"Manuela Azevedo", 912987689, "manuelaazevedo@fe.up.pt"};
	Leitor* l37=new Leitor {37,"Joana Franco", 912382999, "joanafranco@fe.up.pt"};
	Leitor* l38=new Leitor {38,"Marco Marques", 968264009, "marcomarques@fe.up.pt"};
	Leitor* l39=new Leitor {39,"Filipe Pedro", 938899989, "filipepedro@fe.up.pt"};
	b5.adiciona_leitor(l1);
	b5.adiciona_leitor(l2);
	b5.adiciona_leitor(l3);
	b5.adiciona_leitor(l4);
	b5.adiciona_leitor(l5);
	b5.adiciona_leitor(l6);
	b5.adiciona_leitor(l7);
	b5.adiciona_leitor(l8);
	b5.adiciona_leitor(l9);
	b5.adiciona_leitor(l10);
	b5.adiciona_leitor(l11);
	b5.adiciona_leitor(l12);
	b5.adiciona_leitor(l13);
	b5.adiciona_leitor(l14);
	b5.adiciona_leitor(l15);
	b5.adiciona_leitor(l16);
	b5.adiciona_leitor(l17);
	b5.adiciona_leitor(l18);
	b5.adiciona_leitor(l19);
	b5.adiciona_leitor(l20);
	b5.adiciona_leitor(l21);
	b5.adiciona_leitor(l22);
	b5.adiciona_leitor(l23);
	b5.adiciona_leitor(l24);
	b5.adiciona_leitor(l25);
	b5.adiciona_leitor(l26);
	b5.adiciona_leitor(l27);
	b5.adiciona_leitor(l28);
	b5.adiciona_leitor(l29);
	b5.adiciona_leitor(l30);
	b5.adiciona_leitor(l31);
	b5.adiciona_leitor(l32);
	b5.adiciona_leitor(l33);
	b5.adiciona_leitor(l34);
	b5.adiciona_leitor(l35);
	b5.adiciona_leitor(l36);
	b5.adiciona_leitor(l37);
	b5.adiciona_leitor(l38);
	b5.adiciona_leitor(l39);
	ASSERT_EQUAL(39, b5.get_leitores().size());
	//cout << b5.imprime();
	//b5.escreve("Livro.txt","Funcionario.txt","Supervisor.txt","Leitor.txt","Emprestimo.txt");
}

void test_i_remover() {
	Biblioteca b2 {};
	Funcionario* f1=new Funcionario {"Miguel Bacelar"};
	Funcionario* f2=new Funcionario {"Jose Oliveira"};
	Funcionario* f3=new Funcionario {"Carlos Alvim"};
	Funcionario* f4=new Funcionario {"Fatima Bordonhos"};
	Funcionario* f5=new Funcionario {"Margarida Soares"};
	Funcionario* f6=new Funcionario {"Joana Rocha"};
	Funcionario* f7=new Funcionario {"Alexandra Lameira"};
	Funcionario* f8=new Funcionario {"Luis Barros"};
	Funcionario* f9=new Funcionario {"Angela Monteiro"};
	Funcionario* f10=new Funcionario {"Andre Martins"};
	Funcionario* f11=new Funcionario {"Celia Ferreira"};
	Funcionario* f12=new Funcionario {"Hortensia Costa"};
	Funcionario* f13=new Funcionario {"Helia Costa"};
	Funcionario* f14=new Funcionario {"Maria Sousa"};
	Funcionario* f15=new Funcionario {"Sergio Dias"};
	Funcionario* f16=new Funcionario {"Isabel Pinto"};
	Funcionario* f17=new Funcionario {"Lara Lacerda"};
	b2.adiciona_funcionario(f1);
	b2.adiciona_funcionario(f2);
	b2.adiciona_funcionario(f3);
	b2.adiciona_funcionario(f4);
	b2.adiciona_funcionario(f5);
	b2.adiciona_funcionario(f6);
	b2.adiciona_funcionario(f7);
	b2.adiciona_funcionario(f8);
	b2.adiciona_funcionario(f9);
	b2.adiciona_funcionario(f10);
	b2.adiciona_funcionario(f11);
	b2.adiciona_funcionario(f12);
	b2.adiciona_funcionario(f13);
	b2.adiciona_funcionario(f14);
	b2.adiciona_funcionario(f15);
	b2.adiciona_funcionario(f16);
	b2.adiciona_funcionario(f17);
	b2.promove_funcionario_supervisor(3);
	b2.promove_funcionario_supervisor(5);
	b2.promove_funcionario_supervisor(10);
	vector<string> a1 {"Pacheco, Helder"};
	Livro* lv1=new Livro {"Porto em Azul e Branco",a1,"Futebol",9789723611199,
		"29.90", 192, 1, false, 0};
	vector<string> a2 {"Saramago, Jose"};
	Livro* lv2=new Livro {"O Evangelho Segundo Jesus Cristo",a2,"Romance",9722105248,
		"821.134.3 SARj/EVA 13", 445, 13, false, 0};
	vector<string> a3 {"Couto, Mia"};
	Livro* lv3=new Livro {"A chuva pasmada",a3,"Romance",9722116541,
		"821.134.3(679) /COUm/CHU", 74, 1, false, 0};
	vector<string> a4 {"Hopcroft, John E.", "Motwani, Rajeev", "Ullman, Jeffrey D."};
	Livro* lv4=new Livro {"Introduction to automata theory, languages, and computation",a4,"Matematica",201441241,
		"519.6 /HOPj/INT 2", 521, 2, false, 0};
	vector<string> a5 {"Horstmann, Cay", "Budd, Timothy A."};
	Livro* lv5=new Livro {"Big C++",a5,"Programacao",9780470383285,
		"004.43 C++ /HORc/BIG 2", 1056, 2, false, 0};
	vector<string> a6 {"Murakami, Haruki"};
	Livro* lv6=new Livro {"A Sul da fronteira, a Oeste do Sol",a6,"Romance",9789724618623,
		"82 /MURh/SUL", 241, 1, false, 0};
	vector<string> a7 {"Zusak, Markus"};
	Livro* lv7=new Livro {"A rapariga que roubava livros",a7,"Romance",9789722339070,
		"82 /ZUZm/RAP", 463, 4, false, 0};
	vector<string> a8 {"Huff, Darrell"};
	Livro* lv8=new Livro {"Como mentir com a estatistica",a8,"Matematica",9789896165369,
		"5 /CA 201", 175, 1, false, 0};
	vector<string> a9 {"Buescu, Jorge"};
	Livro* lv9=new Livro {"Casamentos e outros desencontros",a9,"Matematica",9789896164515,
		"5 CA 191", 169, 1, false, 0};
	vector<string> a10 {"Downey, Allen B."};
	Livro* lv10=new Livro {"Think Python",a10,"Programacao",9781449330729,
		"004.43 PYT /DOWa/THI", 277, 1, false, 0};
	vector<string> a11 {"Neruda, Pablo"};
	Livro* lv11=new Livro {"Antologia de Pablo Neruda",a11,"Poesia",9727085148,
		"82/NERp/ANT", 457, 1, false, 0};
	b2.adiciona_livro(lv1);
	b2.adiciona_livro(lv2);
	b2.adiciona_livro(lv3);
	b2.adiciona_livro(lv4);
	b2.adiciona_livro(lv5);
	b2.adiciona_livro(lv6);
	b2.adiciona_livro(lv7);
	b2.adiciona_livro(lv8);
	b2.adiciona_livro(lv9);
	b2.adiciona_livro(lv10);
	b2.adiciona_livro(lv11);
	Leitor* l1=new Leitor {"Ines Cunha", 912233444, "inescunha@fe.up.pt"};
	Leitor* l2=new Leitor {"Maria Fonseca", 962345444, "mariafonseca@fe.up.pt"};
	Leitor* l3=new Leitor {"Ana Moura", 912231234, "anamoura@fe.up.pt"};
	Leitor* l4=new Leitor {"Davide Azevedo", 962234244, "davideazevedo@fe.up.pt"};
	Leitor* l5=new Leitor {"Pedro Nunes", 912212324, "pedronunes@fe.up.pt"};
	Leitor* l6=new Leitor {"Joao Meireles", 962232354, "joaomeireles@fe.up.pt"};
	Leitor* l7=new Leitor {"Alexandre Cunha", 963453442, "alexandrecunha@fe.up.pt"};
	Leitor* l8=new Leitor {"Andreia Teixeira", 913563455, "andreiateixeira@fe.up.pt"};
	Leitor* l9=new Leitor {"Margarida Carvalho", 912234242, "margaridacarvalho@fe.up.pt"};
	Leitor* l10=new Leitor {"Daniel Pereira", 932233244, "danielpereira@fe.up.pt"};
	Leitor* l11=new Leitor {"Susana Costa", 912932342, "susanacosta@fe.up.pt"};
	Leitor* l12=new Leitor {"Jose Leal", 918475657, "joseleal@fe.up.pt"};
	Leitor* l13=new Leitor {"Roberto Silva", 928374644, "robertosilva@fe.up.pt"};
	Leitor* l14=new Leitor {"Patricia Ribeiro", 932345994, "patriciaribeiro@fe.up.pt"};
	Leitor* l15=new Leitor {"Diana Goncalves", 922989898, "dianagoncalves@fe.up.pt"};
	Leitor* l16=new Leitor {"Vanessa Oliveira", 962233434, "vanessaoliveira@fe.up.pt"};
	Leitor* l17=new Leitor {"Pedro Almeida", 962253574, "pedroalmeida@fe.up.pt"};
	Leitor* l18=new Leitor {"Lino Amorim", 912865432, "linoamorim@fe.up.pt"};
	Leitor* l19=new Leitor {"Jorge Almeida", 912678990, "jorgealmeida@fe.up.pt"};
	Leitor* l20=new Leitor {"Antonio Vieira", 962256989, "antoniovieira@fe.up.pt"};
	Leitor* l21=new Leitor {"Sandra Vieira", 962254354, "sandravieira@fe.up.pt"};
	Leitor* l22=new Leitor {"Bruno Rocha", 937654324, "brunorocha@fe.up.pt"};
	Leitor* l23=new Leitor {"Viriato Sousa", 928534982, "viriatosousa@fe.up.pt"};
	Leitor* l24=new Leitor {"Alzira Pinto", 910934899, "alzirapinto@fe.up.pt"};
	Leitor* l25=new Leitor {"Edmundo Santos", 910998768, "edmundosantos@fe.up.pt"};
	Leitor* l26=new Leitor {"Maria Mendes", 968748347, "mariamendes@fe.up.pt"};
	Leitor* l27=new Leitor {"Catarina Pereira", 939838488, "catarinapereira@fe.up.pt"};
	Leitor* l28=new Leitor {"Luisa Pereira", 928787879, "luisapereira@fe.up.pt"};
	Leitor* l29=new Leitor {"Nuno Cardoso", 969898239, "nunocardoso@fe.up.pt"};
	Leitor* l30=new Leitor {"Rita Rio", 919888388, "ritario@fe.up.pt"};
	Leitor* l31=new Leitor {"Mario Almeida", 932309922, "marioalmeida@fe.up.pt"};
	Leitor* l32=new Leitor {"Rogerio Cunha", 939999982, "rogeriocunha@fe.up.pt"};
	Leitor* l33=new Leitor {"Leonor Moreira", 932233444, "leonormoreira@fe.up.pt"};
	Leitor* l34=new Leitor {"Barbara Furtado", 962233444, "barbarafurtado@fe.up.pt"};
	Leitor* l35=new Leitor {"Gil Sousa", 962237744, "gilsousa@fe.up.pt"};
	Leitor* l36=new Leitor {"Manuela Azevedo", 912987689, "manuelaazevedo@fe.up.pt"};
	Leitor* l37=new Leitor {"Joana Franco", 912382999, "joanafranco@fe.up.pt"};
	Leitor* l38=new Leitor {"Marco Marques", 968264009, "marcomarques@fe.up.pt"};
	Leitor* l39=new Leitor {"Filipe Pedro", 938899989, "filipepedro@fe.up.pt"};
	b2.adiciona_leitor(l1);
	b2.adiciona_leitor(l2);
	b2.adiciona_leitor(l3);
	b2.adiciona_leitor(l4);
	b2.adiciona_leitor(l5);
	b2.adiciona_leitor(l6);
	b2.adiciona_leitor(l7);
	b2.adiciona_leitor(l8);
	b2.adiciona_leitor(l9);
	b2.adiciona_leitor(l10);
	b2.adiciona_leitor(l11);
	b2.adiciona_leitor(l12);
	b2.adiciona_leitor(l13);
	b2.adiciona_leitor(l14);
	b2.adiciona_leitor(l15);
	b2.adiciona_leitor(l16);
	b2.adiciona_leitor(l17);
	b2.adiciona_leitor(l18);
	b2.adiciona_leitor(l19);
	b2.adiciona_leitor(l20);
	b2.adiciona_leitor(l21);
	b2.adiciona_leitor(l22);
	b2.adiciona_leitor(l23);
	b2.adiciona_leitor(l24);
	b2.adiciona_leitor(l25);
	b2.adiciona_leitor(l26);
	b2.adiciona_leitor(l27);
	b2.adiciona_leitor(l28);
	b2.adiciona_leitor(l29);
	b2.adiciona_leitor(l30);
	b2.adiciona_leitor(l31);
	b2.adiciona_leitor(l32);
	b2.adiciona_leitor(l33);
	b2.adiciona_leitor(l34);
	b2.adiciona_leitor(l35);
	b2.adiciona_leitor(l36);
	b2.adiciona_leitor(l37);
	b2.adiciona_leitor(l38);
	b2.adiciona_leitor(l39);
//	b2.escreve("Livro.txt","Funcionario.txt","Supervisor.txt","Leitor.txt","Emprestimo.txt");
	ASSERT_EQUAL(3,lv3->get_ID());
	ASSERT_EQUAL(7,f7->get_ID());
	ASSERT_EQUAL(5,l5->get_ID());
	ASSERT_EQUAL(true, b2.remove_livro(2));
	ASSERT_EQUAL(true, b2.remove_leitor(3));
	ASSERT_EQUAL(true, b2.remove_funcionario(1));
	ASSERT_EQUAL(10, b2.get_livros().size());
	ASSERT_EQUAL(38, b2.get_leitores().size());
	ASSERT_EQUAL(16, b2.get_funcionarios().size());
	ASSERT_THROWS(b2.remove_livro(20), Object_nao_existe);
		try {
			b2.remove_livro(20);
		}
		catch (Object_nao_existe &lv) {
			std::cout << "Excecao. Nao existe Livro com ID " << lv.get_ID() << "." << std::endl;
			ASSERT_EQUAL(20, lv.get_ID());
		}
	ASSERT_THROWS(b2.remove_leitor(55), Object_nao_existe);
		try {
			b2.remove_leitor(55);
		}
		catch (Object_nao_existe &lt) {
			std::cout << "Excecao. Nao existe Leitor com ID " << lt.get_ID() << "." << std::endl;
			ASSERT_EQUAL(55, lt.get_ID());
		}
	ASSERT_THROWS(b2.remove_funcionario(24), Object_nao_existe);
		try {
			b2.remove_funcionario(24);
		}
		catch (Object_nao_existe &fc) {
			std::cout << "Excecao. Nao existe Funcionario com ID " << fc.get_ID() << "." << std::endl;
			ASSERT_EQUAL(24, fc.get_ID());
		}
	#ifdef __APPLE__

	#elif __MING32__ __WIN32__
	blabla
	#endif
}

void test_j_ler() {
	Biblioteca b6 {};
	b6.le_livros("Livro.txt");
	b6.le_funcionarios("Funcionario.txt", "Supervisor.txt");
	b6.le_leitores("Leitor.txt");
	ASSERT_EQUAL(17, b6.get_livros().size());
	ASSERT_EQUAL(17, b6.get_funcionarios().size());
	ASSERT_EQUAL(39, b6.get_leitores().size());
//	cout << b6.imprime();
}

void test_k_emprestar() {
	Biblioteca b7 {};
	b7.le_livros("Livro.txt");
	b7.le_funcionarios("Funcionario.txt", "Supervisor.txt");
	b7.le_leitores("Leitor.txt");
	vector<Livro*> livrs {b7.get_livros()};
	vector<Leitor*> leitors {b7.get_leitores()};
	for (vector<Livro*>::const_iterator it = livrs.begin(); it != livrs.end(); it++) {
		(*it)->set_emprestado(false);
		(*it)->set_data_emp(0);
	}
	for (vector<Leitor*>::const_iterator itl = leitors.begin(); itl != leitors.end(); itl++) {
		(*itl)->set_emp_leit( {});
	}
	time_t dt {};
	long year {}, month {}, day {};
	struct tm* dtinfo {};
	year = 2014;
	month = 10;
	day = 2;
	time (&dt);
	dtinfo = localtime ( &dt );
	dtinfo->tm_year = year - 1900;
	dtinfo->tm_mon = month - 1;
	dtinfo->tm_mday = day;
	dt = mktime (dtinfo);
	time_t hj = std::time(0);
	double tempo_dias {floor(difftime(hj,dt)/86400)};
	Emprestimo* e1 = new Emprestimo {b7.get_livros()[1], b7.get_funcionarios()[2], b7.get_leitores()[24], dt};
	year = 2014;
	month = 10;
	day = 16;
	time (&dt);
	dtinfo = localtime ( &dt );
	dtinfo->tm_year = year - 1900;
	dtinfo->tm_mon = month - 1;
	dtinfo->tm_mday = day;
	dt = mktime (dtinfo);
	Emprestimo* e2 = new Emprestimo {b7.get_livros()[0], b7.get_funcionarios()[5], b7.get_leitores()[10], dt};
	year = 2014;
	month = 10;
	day = 23;
	time (&dt);
	dtinfo = localtime ( &dt );
	dtinfo->tm_year = year - 1900;
	dtinfo->tm_mon = month - 1;
	dtinfo->tm_mday = day;
	dt = mktime (dtinfo);
	Emprestimo* e3 = new Emprestimo {b7.get_livros()[4], b7.get_funcionarios()[9], b7.get_leitores()[24], dt};
	year = 2014;
	month = 11;
	day = 1;
	time (&dt);
	dtinfo = localtime ( &dt );
	dtinfo->tm_year = year - 1900;
	dtinfo->tm_mon = month - 1;
	dtinfo->tm_mday = day;
	dt = mktime (dtinfo);
	Emprestimo* e4 = new Emprestimo {b7.get_livros()[8], b7.get_funcionarios()[11], b7.get_leitores()[7], dt};
	Emprestimo* e5 = new Emprestimo {b7.get_livros()[6], b7.get_funcionarios()[16], b7.get_leitores()[24]};
	cout << "cria emprestimos ok\n";
	b7.adiciona_emprestimo(e1);
	b7.adiciona_emprestimo(e2);
	b7.adiciona_emprestimo(e3);
	b7.adiciona_emprestimo(e4);
	b7.adiciona_emprestimo(e5);
	cout << "adiciona emprestimos ok\n";
	ASSERT_EQUAL(5,b7.get_emprestimos().size());
	ASSERT_EQUAL(2,e1->get_livro()->get_ID());
	ASSERT_EQUAL("Luis Barros",e2->get_funcionario()->get_nome());
	ASSERT_EQUAL(3,e3->get_ID());
	ASSERT_EQUAL(913563455,e4->get_leitor()->get_telefone());
	long data = e4->get_data();
	tm *ldata = localtime(&data);
	long ymd {(1900 + ldata->tm_year) * 10000 + (1 + ldata->tm_mon) * 100 + ldata->tm_mday};
	ASSERT_EQUAL(20141101,ymd);
	ASSERT_EQUAL(3,b7.get_leitores()[24]->get_emp_leit().size());
	Emprestimo* e6 = new Emprestimo {b7.get_livros()[1], b7.get_funcionarios()[3], b7.get_leitores()[5]};
	Emprestimo* e7 = new Emprestimo {b7.get_livros()[2], b7.get_funcionarios()[15], b7.get_leitores()[24]};
	cout << "cria emprestimos ok\n";
	ASSERT_THROWS(b7.adiciona_emprestimo(e6);, Livro_indisponivel);
		try {
			b7.adiciona_emprestimo(e6);
		}
		catch (Livro_indisponivel &lv) {
			std::cout <<  "Excecao. Livro com ID " << lv.get_ID() << " nao esta disponivel para emprestar. Foi emprestado ha " << lv.get_dias_emp() << " dia(s)." << std::endl;
			ASSERT_EQUAL(tempo_dias, lv.get_dias_emp());
			ASSERT_EQUAL(2,lv.get_ID());
		}
	ASSERT_THROWS(b7.adiciona_emprestimo(e7);, Maximo_emprestimos);
		try {
			b7.adiciona_emprestimo(e7);
		}
		catch (Maximo_emprestimos &lt) {
			std::cout <<  "Excecao. Leitor ja tem 3 emprestimos feitos." << std::endl;
		}
	b7.escreve("Livro.txt", "Funcionario.txt", "Supervisor.txt", "Leitor.txt", "Emprestimo.txt", "Utilizador.txt");
}

void test_l_emprestimos_ler_atrasos() {
	Biblioteca b8 {};
	b8.le("Livro.txt", "Funcionario.txt", "Supervisor.txt", "Leitor.txt", "Emprestimo.txt", "Utilizador.txt");
	ASSERT_EQUAL(17, b8.get_livros().size());
	ASSERT_EQUAL(17, b8.get_funcionarios().size());
	ASSERT_EQUAL(39, b8.get_leitores().size());
	ASSERT_EQUAL(5, b8.get_emprestimos().size());
	ASSERT_EQUAL(1, b8.get_leitores()[7]->get_emp_leit().size());
	ASSERT_EQUAL(3, b8.get_emprestimos_atrasados().size());
//	cout << b8.imprime();
	cout << b8.imprime_emprestimos_atrasados();
}

void test_m_login() {
	Biblioteca b9 {};
	b9.le("Livro.txt", "Funcionario.txt", "Supervisor.txt", "Leitor.txt", "Emprestimo.txt", "Utilizador.txt");
	vector<Funcionario*> funcios {b9.get_funcionarios()};
	Utilizador* admin = new Utilizador {0,"0",0};
	Utilizador* ut {};
	Supervisor* sp {};
	b9.adiciona_utilizador(admin);
	for (vector<Funcionario*>::const_iterator it = funcios.begin(); it != funcios.end(); it++) {
		sp = dynamic_cast<Supervisor*>(*it);
		if (sp == 0) {
			ut = new Utilizador {(*it)->get_ID(), to_string((*it)->get_ID()), 2};
			b9.adiciona_utilizador(ut);
		}
		else {
			ut = new Utilizador {(*it)->get_ID(), to_string((*it)->get_ID()), 1};
			b9.adiciona_utilizador(ut);
		}
	}
	ASSERT_EQUAL(18, b9.get_utilizadores().size());
	b9.escreve("Livro.txt", "Funcionario.txt", "Supervisor.txt", "Leitor.txt", "Emprestimo.txt", "Utilizador.txt");
	cout << b9.imprime();
}

void runSuite() {
	cute::suite s {};
	//TODO add your test here
	s.push_back(CUTE(test_a_criar_livros));
	s.push_back(CUTE(test_b_adicionar_livros));
	s.push_back(CUTE(test_c_imprimir_livros));
	s.push_back(CUTE(test_d_criar_funcionarios));
	s.push_back(CUTE(test_e_adicionar_funcionarios));
	s.push_back(CUTE(test_f_imprimir_funcionarios));
	s.push_back(CUTE(test_g_promover_funcionarios));
	s.push_back(CUTE(test_h_criar_adicionar_imprimir_escrever_leitor));
	s.push_back(CUTE(test_i_remover));
	s.push_back(CUTE(test_j_ler));
	s.push_back(CUTE(test_k_emprestar));
	s.push_back(CUTE(test_l_emprestimos_ler_atrasos));
	s.push_back(CUTE(test_m_login));
	cute::ide_listener lis {};
	cute::makeRunner(lis)(s, "AEDA 2014/2015 - Biblioteca");
}

int main() {
    runSuite();
    return 0;
}


*/

