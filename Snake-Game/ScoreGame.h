#include"Headers.h"

void ScoreGame()
{
	std::cout << "##################################################" << std::endl;
	std::cout << "#          PLACAR 10 MELHORES JOGADORES:         #" << std::endl;
	std::cout << "##################################################" << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
	{
		std::cout << i + 1 << "º  -  " << "JOGADOR: " << placar[i].nome << "\t" << "SCORE: " << placar[i].pontuacao << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "##################################################" << std::endl;
	system("pause");
}