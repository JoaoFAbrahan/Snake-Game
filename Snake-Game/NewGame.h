#include"Headers.h"


void NewGame()
{
	struct Jogador jogador; //Cria um novo jogador
	//std::list<char> snakeElements =

	//Pede de entrada um nome para esse novo jogador
	std::cout << "##################################################" << std::endl;
	std::cout << "#            DIGITE O NOME DO JOGADOR:           #" << std::endl;
	std::cout << "##################################################" << std::endl;
	std::cout << "> ";
	std::getline(std::cin, jogador.nome); //Adiciona o nome do jogador na struct jogador

	system("cls");

	//Chama a função StartMap
	StartMap(&jogador);

	//Game Loop
	bool GameOver = false;
	while (!GameOver)
	{
		system("cls");

		DrawMap(&jogador); //Desenha o Mapa Framehate
		Sleep(150); //Define tempo do Framehate


		if (LogicGame(&jogador)) //verifica a ação do jogador)
		{
			GameOver = true;
		}
		//std::async();
	}

	Game0ver(jogador.pontuacao);
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


	//Randomiza posição inicial da fruta
	HappyFarm();
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


bool LogicGame(struct Jogador* jogador)
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
			jogador->posCabeca[0] -= 1; //Move para Cima

			if (worldMap[jogador->posCabeca[0]][jogador->posCabeca[1]] == '+' || worldMap[jogador->posCabeca[0]][jogador->posCabeca[1]] == '#')
			{
				return true;
			}
			else if (worldMap[jogador->posCabeca[0]][jogador->posCabeca[1]] == '*')
			{
				//Adiciona na lista
				HappyFarm();
			}

			break;
		case 's':
			jogador->posCabeca[0] += 1; //Move para Baixo

			if (worldMap[jogador->posCabeca[0]][jogador->posCabeca[1]] == '+' || worldMap[jogador->posCabeca[0]][jogador->posCabeca[1]] == '#')
			{
				return true;
			}
			else if (worldMap[jogador->posCabeca[0]][jogador->posCabeca[1]] == '*')
			{
				//Adiciona na lista
				HappyFarm();
			}

			break;
		case 'a':
			jogador->posCabeca[1] -= 1; //Move para Esquerda

			if (worldMap[jogador->posCabeca[0]][jogador->posCabeca[1]] == '+' || worldMap[jogador->posCabeca[0]][jogador->posCabeca[1]] == '#')
			{
				return true;
			}
			else if (worldMap[jogador->posCabeca[0]][jogador->posCabeca[1]] == '*')
			{
				//Adiciona na lista
				HappyFarm();
			}

			break;
		case 'd':
			jogador->posCabeca[1] += 1; //Move para Direita

			if (worldMap[jogador->posCabeca[0]][jogador->posCabeca[1]] == '+' || worldMap[jogador->posCabeca[0]][jogador->posCabeca[1]] == '#')
			{
				return true;
			}
			else if (worldMap[jogador->posCabeca[0]][jogador->posCabeca[1]] == '*')
			{
				//Adiciona na lista
				HappyFarm();
			}

			break;
		}

		worldMap[jogador->posCabeca[0]][jogador->posCabeca[1]] = '+';
		//worldMap[jogador->posCauda[0]][jogador->posCauda[1]] = ' ';

		return false;
	}
}


//Spawna frutas e vegetais de maneira aleatoria evitanto gargalos infinitos
void HappyFarm()
{
	int aux1;
	char aux2;
	int posX;
	int posY;
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
	if (usedLines[posX] == 1)
	{
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
	if (aux1 == 0) 
	{
		usedLines[posX] = 1;
		goto label01;
	}
	//espaço
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
	label02:
		posY = rand() % 48;
		posY++;
	}
	if (worldMap[posX][posY] == ' ')
	{
		worldMap[posX][posY] = '*';
	}
}



//acabou é o fim, se lascou
void Game0ver(int pontuacao)
{
	SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_INTENSITY); //Define uma cor no texto do console
	std::cout << "##################################################" << std::endl;
	std::cout << "#                  :GAMEOVER:                    #" << std::endl;
	std::cout << "##################################################" << std::endl;
	std::cout << "Sua pontuação foi:";
	std::cout << pontuacao << std::endl;
	//pontuacao -> pontuação
	system("pause");
}