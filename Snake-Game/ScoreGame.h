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
		std::cout << i + 1 << "�  -  " << "JOGADOR: " << placar[i].nome << "\t" << "SCORE: " << placar[i].pontuacao << std::endl;
	}
	
	std::cout << std::endl;
	std::cout << "##################################################" << std::endl;
	system("pause");
}

void AdicionaScore(int score, std::string name)
{
	int aux;
	std::string auxN;

	int aux2;
	std::string auxN2;

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
				aux = placar[i].pontuacao;
				auxN = placar[i].nome;

				placar[i].nome = name;
				placar[i].pontuacao = score;

				i++;

				for (i; i < 10; i++)
				{
					aux2 = placar[i].pontuacao; // pega a pontua��o x
					auxN2 = placar[i].nome;

					placar[i].pontuacao = aux; // escreve a pontua��o
					placar[i].nome = auxN;

					aux = aux2; 
					auxN = auxN2;
				}
			}
		}
	}

}