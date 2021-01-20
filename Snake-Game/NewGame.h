#include"Headers.h"


void NewGame()
{
	struct Jogador jogador; //Cria um novo jogador

	//Pede de entrada um nome para esse novo jogador
	std::cout << "##################################################" << std::endl;
	std::cout << "#            DIGITE O NOME DO JOGADOR:           #" << std::endl;
	std::cout << "##################################################" << std::endl;
	std::cout << "> ";
	std::getline(std::cin, jogador.nome); //Adiciona o nome do jogador na struct jogador

	system("cls");
	std::cin.ignore();

	//Chama a função StartMap
	StartMap(&jogador);

	//Game Loop
	bool GameOver = false;
	while (!GameOver)
	{
		system("cls");

		DrawMap(&jogador);
		Sleep(250);

		LogicGame(&jogador);
		//std::async();
	}

}

void StartMap(struct Jogador* jogadorPos)
{
	//Define o mapa
	for (int i = 0; i < LIN; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (i == 0 || i == LIN - 1 || j == 0 || j == COL - 1)
			{
				worldMap[i][j] = '#';
			}
			else
			{
				worldMap[i][j] = ' ';
			}
		}
	}


	//Adicionando o player no mapa
	//Define posição inicial da cabeça e da cauda
	jogadorPos->posCabeca[0] = 11, jogadorPos->posCabeca[1] = 24;
	jogadorPos->posCauda[0] = 12, jogadorPos->posCauda[1] = 24;

	//Define posição de desenho do jogador no inicio da partida
	worldMap[jogadorPos->posCabeca[0]][jogadorPos->posCabeca[1]] = '+';
	//worldMap[jogadorPos->posCauda[0]][jogadorPos->posCauda[1]] = '+';


	//Randomiza posição inicial da fruta

}

void DrawMap(struct Jogador* jogador)
{
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_INTENSITY); //Define uma cor no texto do console
	std::cout << "##################################################" << std::endl;
	std::cout << "JOGADOR: " << jogador->nome << "\t\t" << "SCORE: " << jogador->pontuacao << std::endl;
	for (int i = 0; i < LIN; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (worldMap[i][j] == '*')
			{
				SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_INTENSITY); //Define uma cor no texto do console
				std::cout << worldMap[i][j];
			}
			else if (worldMap[i][j] == '+')
			{
				SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_INTENSITY); //Define uma cor no texto do console
				std::cout << worldMap[i][j];
			}
			else
			{
				SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_INTENSITY); //Define uma cor no texto do console
				std::cout << worldMap[i][j];
			}
		}
		std::cout << std::endl;
	}
}


void LogicGame(struct Jogador* jogador)
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
			jogador->posCabeca[0] -= 1; //Move para Cima
			break;
		case 's':
			jogador->posCabeca[0] += 1; //Move para Baixo
			break;
		case 'a':
			jogador->posCabeca[1] -= 1; //Move para Esquerda
			break;
		case 'd':
			jogador->posCabeca[1] += 1; //Move para Direita
			break;
		}

		worldMap[jogador->posCabeca[0]][jogador->posCabeca[1]] = '+';
		//worldMap[jogador->posCauda[0]][jogador->posCauda[1]] = ' ';
	}
}


// função auxiliar
int GenN(int limite)
{
	srand(time(NULL));
	int num = rand() % limite;
	return(num);
}

//usavel para o early instavel para o late game
void Spawn(char tipo)
{
gen:
	int xpos = GenN(25);
	int ypos = GenN(50);
	if (worldMap[xpos][ypos] == ' ')
	{
		worldMap[xpos][ypos] = tipo;
	}
	else
	{
		goto gen;
	}
}
//overenginering
void FreeSpaces()
{
	int aux1;
	char aux2;
	int posX;
	int posY;
	bool aux3;
	int usedLines[23];

	for (int i = 0; i < 23; i++)
	{
		usedLines[i] = 0;
	}

label01:
	srand(time(NULL));
	posX = rand() % 23;
	posX++;
	aux1 = 0;
	if (usedLines[posX] == 1) {
		goto label01;
	}
	for (int i = 1; i < 48; i++)
	{
		aux2 = worldMap[posX][i];
		if (aux2 == ' ')
		{
			aux1++;
		}

	}
	if (aux1 == 0) {
		goto label01;
	}
label02:
	if (aux1 < 10)
	{
		for (int i = 1; i < 48; i++)
		{
			aux2 = worldMap[posX][i];
			if (aux2 != ' ')
			{
				worldMap[posX][i] = '*';
			}
		}
	}
	else
	{
	posY = rand() % 48;
	}
}
