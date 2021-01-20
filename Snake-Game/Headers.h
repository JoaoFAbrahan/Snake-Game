#pragma once
#include<iostream>
#include<locale>
#include<string>
#include<conio.h>
#include<Windows.h>


//Struct Jogador
struct Jogador
{
	std::string nome = "";
	int pontuacao = 0;
	int vida = 1;
};


//Variáveis globais
const int LIN = 25;
const int COL = 50;
char worldMap[LIN][COL];

struct Jogador placar[10];


//Protótipo de Funções
void MainMenu();
void NewGame();
void ScoreGame();
