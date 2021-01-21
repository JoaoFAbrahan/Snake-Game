#include"Headers.h"

//Apresenta o score atual do jogo
void ScoreGame()
{
	std::cout << "##################################################" << std::endl;
	std::cout << "#          PLACAR 10 MELHORES JOGADORES:         #" << std::endl;
	std::cout << "##################################################" << std::endl;
	std::cout << std::endl;

	//Percorre o vetor de jogadores, apresentando o nome e o score
	for (int i = 0; i < 10; i++)
	{
		std::cout << i + 1 << "º  -  " << "JOGADOR: " << placar[i].nome << "\t" << "SCORE: " << placar[i].pontuacao << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "##################################################" << std::endl;
	system("pause");
}

void adicionarScore(int score, std::string name)
{
	int aux;
	std::string aux2;

	for (int i = 0; i < 10; i++)
	{
		if (placar[i].pontuacao < score)
		{
			if (placar[i].pontuacao == 0)
			{
				placar[i].pontuacao = score;
				placar[i].nome = name;
				break;
			}
			else
			{

			}
		}
	}

}