#include"Headers.h"
#include"NewGame.h"
#include"ScoreGame.h"


int main()
{
	setlocale(LC_ALL, "Portuguese");

	MainMenu();
}

void MainMenu()
{
	char opcao;

	bool loop = true;
	do
	{
		system("cls");

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
			NewGame();

			break;
		case '2':
			ScoreGame();

			break;
		case '3':
			loop = false;

			std::cout << "##################################################" << std::endl;
			std::cout << "#                 Até a Próxima!                 #" << std::endl;
			std::cout << "##################################################" << std::endl;
			system("pause");

			break;
		default:
			std::cout << "##################################################" << std::endl;
			std::cout << "#                Opção Inválida!                 #" << std::endl;
			std::cout << "##################################################" << std::endl;
			system("pause");

			break;
		}
	} while (loop == true);
}