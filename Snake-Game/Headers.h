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


//Vari�veis globais
const int LIN = 25;
const int COL = 50;
char worldMap[LIN][COL];

struct Jogador placar[10];


//Prot�tipo de Fun��es
void MainMenu();
void NewGame();
void ScoreGame();
