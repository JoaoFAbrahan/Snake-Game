#include"Headers.h"


void NewGame()
{
	struct Jogador jogador; //Cria um novo jogador
	std::list<Pos> snakeElements;

	//Pede de entrada um nome para esse novo jogador
	std::cout << "##################################################" << std::endl;
	std::cout << "#            DIGITE O NOME DO JOGADOR:           #" << std::endl;
	std::cout << "##################################################" << std::endl;
	std::cout << "> ";
	std::getline(std::cin, jogador.nome); //Adiciona o nome do jogador na struct jogador

	system("cls");

	//Chama a função StartMap
	StartMap(&jogador, &snakeElements);

	//Game Loop
	while (jogador.GameOver == false)
	{
		system("cls");

		DrawMap(&jogador); //Desenha o Mapa Framehate
		Sleep(150); //Define tempo do Framehate

		LogicGame(&jogador, &snakeElements);
		//std::async();
	}

	Game0ver(jogador.pontuacao);
}

void StartMap(struct Jogador* jogadorPos, std::list<Pos>* snakeElements)
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


	//Adicionando elementos iniciais da snake
	struct Pos posFront;
	struct Pos posBack;

	posFront.x = 11;
	posFront.y = 24;
	snakeElements->push_front(posFront);

	posBack.x = 12;
	posBack.y = 24;
	snakeElements->push_back(posBack);

	//Define posição de desenho do jogador no inicio da partida
	worldMap[snakeElements->front().x][snakeElements->front().y] = '+';
	worldMap[snakeElements->back().x][snakeElements->back().y] = '+';


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


void LogicGame(struct Jogador* jogador, std::list<Pos>* snakeElements)
{
	static char lastKey = NULL;
	struct Pos newPos;

	//Verifica se o jogador deu alguma entrada no teclado
	if (_kbhit())
	{
		char key = tolower(_getch()); //Converte caracter para minúsculo

		//Verifica qual caracter foi digitado e aplica a ação de movimento
		switch (key)
		{
		case 'w':
			newPos.x = snakeElements->front().x - 1;
			newPos.y = snakeElements->front().y;

			if (worldMap[newPos.x][newPos.y] == '#' || worldMap[newPos.x][newPos.y] == '+')
			{
				jogador->GameOver = true;
			}
			else if (worldMap[newPos.x][newPos.y] == '*')
			{
				jogador->pontuacao += 1;
				HappyFarm();

				snakeElements->push_front(newPos);
				worldMap[snakeElements->front().x][snakeElements->front().y] = '+';
			}
			else
			{
				snakeElements->push_front(newPos);
				worldMap[snakeElements->front().x][snakeElements->front().y] = '+';
				worldMap[snakeElements->back().x][snakeElements->back().y] = ' ';
				snakeElements->pop_back();
			}

			break;
		case 's':
			newPos.x = snakeElements->front().x + 1;
			newPos.y = snakeElements->front().y;

			if (worldMap[newPos.x][newPos.y] == '#' || worldMap[newPos.x][newPos.y] == '+')
			{
				jogador->GameOver = true;
			}
			else if (worldMap[newPos.x][newPos.y] == '*')
			{
				jogador->pontuacao += 1;
				HappyFarm();

				snakeElements->push_front(newPos);
				worldMap[snakeElements->front().x][snakeElements->front().y] = '+';
			}
			else
			{
				snakeElements->push_front(newPos);
				worldMap[snakeElements->front().x][snakeElements->front().y] = '+';
				worldMap[snakeElements->back().x][snakeElements->back().y] = ' ';
				snakeElements->pop_back();
			}

			break;
		case 'a':
			newPos.x = snakeElements->front().x;
			newPos.y = snakeElements->front().y - 1;

			if (worldMap[newPos.x][newPos.y] == '#' || worldMap[newPos.x][newPos.y] == '+')
			{
				jogador->GameOver = true;
			}
			else if (worldMap[newPos.x][newPos.y] == '*')
			{
				jogador->pontuacao += 1;
				HappyFarm();

				snakeElements->push_front(newPos);
				worldMap[snakeElements->front().x][snakeElements->front().y] = '+';
			}
			else
			{
				snakeElements->push_front(newPos);
				worldMap[snakeElements->front().x][snakeElements->front().y] = '+';
				worldMap[snakeElements->back().x][snakeElements->back().y] = ' ';
				snakeElements->pop_back();
			}

			break;
		case 'd':
			newPos.x = snakeElements->front().x;
			newPos.y = snakeElements->front().y + 1;

			if (worldMap[newPos.x][newPos.y] == '#' || worldMap[newPos.x][newPos.y] == '+')
			{
				jogador->GameOver = true;
			}
			else if (worldMap[newPos.x][newPos.y] == '*')
			{
				jogador->pontuacao += 1;
				HappyFarm();

				snakeElements->push_front(newPos);
				worldMap[snakeElements->front().x][snakeElements->front().y] = '+';
			}
			else
			{
				snakeElements->push_front(newPos);
				worldMap[snakeElements->front().x][snakeElements->front().y] = '+';
				worldMap[snakeElements->back().x][snakeElements->back().y] = ' ';
				snakeElements->pop_back();
			}

			break;
		}

		lastKey = key; //Define ultima tecla digitada
	}
	else //Caso nenhuma nova tecla tenha sido digitada ele repete a ultima ação
	{
		switch (lastKey)
		{
		case 'w':
			newPos.x = snakeElements->front().x - 1;
			newPos.y = snakeElements->front().y;

			if (worldMap[newPos.x][newPos.y] == '#' || worldMap[newPos.x][newPos.y] == '+')
			{
				jogador->GameOver = true;
			}
			else if (worldMap[newPos.x][newPos.y] == '*')
			{
				jogador->pontuacao += 1;
				HappyFarm();

				snakeElements->push_front(newPos);
				worldMap[snakeElements->front().x][snakeElements->front().y] = '+';
			}
			else
			{
				snakeElements->push_front(newPos);
				worldMap[snakeElements->front().x][snakeElements->front().y] = '+';
				worldMap[snakeElements->back().x][snakeElements->back().y] = ' ';
				snakeElements->pop_back();
			}

			break;
		case 's':
			newPos.x = snakeElements->front().x + 1;
			newPos.y = snakeElements->front().y;

			if (worldMap[newPos.x][newPos.y] == '#' || worldMap[newPos.x][newPos.y] == '+')
			{
				jogador->GameOver = true;
			}
			else if (worldMap[newPos.x][newPos.y] == '*')
			{
				jogador->pontuacao += 1;
				HappyFarm();

				snakeElements->push_front(newPos);
				worldMap[snakeElements->front().x][snakeElements->front().y] = '+';
			}
			else
			{
				snakeElements->push_front(newPos);
				worldMap[snakeElements->front().x][snakeElements->front().y] = '+';
				worldMap[snakeElements->back().x][snakeElements->back().y] = ' ';
				snakeElements->pop_back();
			}

			break;
		case 'a':
			newPos.x = snakeElements->front().x;
			newPos.y = snakeElements->front().y - 1;

			if (worldMap[newPos.x][newPos.y] == '#' || worldMap[newPos.x][newPos.y] == '+')
			{
				jogador->GameOver = true;
			}
			else if (worldMap[newPos.x][newPos.y] == '*')
			{
				jogador->pontuacao += 1;
				HappyFarm();

				snakeElements->push_front(newPos);
				worldMap[snakeElements->front().x][snakeElements->front().y] = '+';
			}
			else
			{
				snakeElements->push_front(newPos);
				worldMap[snakeElements->front().x][snakeElements->front().y] = '+';
				worldMap[snakeElements->back().x][snakeElements->back().y] = ' ';
				snakeElements->pop_back();
			}

			break;
		case 'd':
			newPos.x = snakeElements->front().x;
			newPos.y = snakeElements->front().y + 1;

			if (worldMap[newPos.x][newPos.y] == '#' || worldMap[newPos.x][newPos.y] == '+')
			{
				jogador->GameOver = true;
			}
			else if (worldMap[newPos.x][newPos.y] == '*')
			{
				jogador->pontuacao += 1;
				HappyFarm();

				snakeElements->push_front(newPos);
				worldMap[snakeElements->front().x][snakeElements->front().y] = '+';
			}
			else
			{
				snakeElements->push_front(newPos);
				worldMap[snakeElements->front().x][snakeElements->front().y] = '+';
				worldMap[snakeElements->back().x][snakeElements->back().y] = ' ';
				snakeElements->pop_back();
			}

			break;
		}
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
	std::cout << std::endl;
	std::cout << "##################################################" << std::endl;
	std::cout << "#                   :GAME OVER:                  #" << std::endl;
	std::cout << "##################################################" << std::endl;
	std::cout << "Sua pontuação foi: " << pontuacao << std::endl;
	system("pause");
}