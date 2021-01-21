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
	int vida = 1;
	int posCabeca[2];
	int posCauda[2];
};


//Variáveis globais
const int LIN = 25;			//Quantidade de Linhas da matriz do worldMap
const int COL = 50;			//Quantidade de Colunas da matriz do worldMap
char worldMap[LIN][COL];	//Mapa do jogo

struct Jogador placar[10];	//Vetor de placar dos jogadores

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); //Cria 

//Protótipo de Funções
void MainMenu();
void NewGame();
void StartMap(struct Jogador* jogadorPos);
void ScoreGame();
void DrawMap(struct Jogador* jogador);
bool LogicGame(struct Jogador* jogador);

void HappyFarm();
void Game0ver(int pontuacao);