#pragma once
#include<iostream>
#include<locale>
#include<string>
#include<conio.h>
#include<Windows.h>
#include<future>
#include<list>


//Struct Jogador
struct Jogador
{
	std::string nome = "";
	int pontuacao = 0;
	bool GameOver = false;
};

struct Pos
{
	int x;
	int y;
};


//Variáveis globais
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //Cria um handle para definir cor em caracteres do console

const int LIN = 25;			//Quantidade de Linhas da matriz do worldMap.
const int COL = 50;			//Quantidade de Colunas da matriz do worldMap.
char worldMap[LIN][COL];	//Matriz do Mapa do Jogo.

struct Jogador placar[10];	//Vetor de placar dos jogadores


//Protótipo de Funções
void MainMenu();
void ScoreGame();

void NewGame();
void StartMap(struct Jogador* jogadorPos, std::list<Pos>* snakeElements);
void DrawMap(struct Jogador* jogador);
void LogicGame(struct Jogador* jogador, std::list<Pos>* snakeElements);
void HappyFarm();
void adicionarScore(int score, std::string name);

void Game0ver(int pontuacao);