/*
	############################################
	#############    SNAKE GAME    #############
	############################################

	Jogo Snake desenvolvido com o objetivo de estudar o desenvolvimento de sistemas de game loop
	e lógica de programação utilizando o C++.

	Desenvolvedores:		João Felipe Abrahan,
							Jorge Calligopoulo.

	Data Desenvolvimento:	20/01/2021 até 22/01/2021. 
	Versão da Linguagem:	C++17.
	Tipo de Licença:		MIT.
*/
#include"Headers.h"
#include"NewGame.h"
#include"ScoreGame.h"


int main()
{
	setlocale(LC_ALL, "Portuguese");

	MainMenu();
}

///Menu inicial do jogo
void MainMenu()
{
	char opcao;

	bool loop = true;
	do
	{
		system("cls");

		//Menu inicial do jogo
		SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_INTENSITY); //Define uma cor no texto do console

		std::cout << "##################################################" << std::endl;
		std::cout << "#                   MAIN MENU                    #" << std::endl;
		std::cout << "##################################################" << std::endl;
		std::cout << "#                                                #" << std::endl;
		std::cout << "#               1 - Novo Jogo.                   #" << std::endl;
		std::cout << "#               2 - Placar.                      #" << std::endl;
		std::cout << "#               3 - Sair.                        #" << std::endl;
		std::cout << "#                                                #" << std::endl;
		std::cout << "##################################################" << std::endl;
		std::cout << "> ";
		std::cin >> opcao;

		system("cls");

		switch (opcao)
		{
		case '1':
			std::cin.ignore();
			NewGame(); //Executa uma nova partida

			break;
		case '2':
			ScoreGame(); //Apresenta o placar atual do jogo

			break;
		case '3':
			loop = false;

			//Encerra o programa
			std::cout << "##################################################" << std::endl;
			std::cout << "#                 Até a Próxima!                 #" << std::endl;
			std::cout << "##################################################" << std::endl;
			system("pause");

			break;
		default:
			//Caso um número fora dos definidos seja informado pelo usuário.
			std::cout << "##################################################" << std::endl;
			std::cout << "#                Opção Inválida!                 #" << std::endl;
			std::cout << "##################################################" << std::endl;
			system("pause");

			break;
		}
	} while (loop == true);
}