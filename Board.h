#pragma once
#include <vector>
using namespace std;
#include "Tile.h"
#include "Random.h"
#include "TextureManager.h"
#include <iostream>

struct Board
{
	vector<Tile> Tiles;
	int height, width;
	int numberMines;
	int MineCounter;
	void ConnectTiles();
	void SetMines();
	void CreateTiles();
	void SetNumberofNeighborMines();
	bool Reset;
	bool Lose, Win;
	void Create(int x, int y, int z);
	void CreateTest1(int x, int y, string z);
	void CreateTest2(int x, int y, string z);
	void CreateTest3(int x, int y, string z);
	void RevealRecursive(Tile& tile);
	Tile Face, Debug, Negative, Hundred, Ten, One;
	Tile Test1, Test2, Test3;
	void DrawFace(int x, int y, sf::RenderWindow& window);
	void DrawDebug(int x, int y, sf::RenderWindow& window);
	void DrawMineCounter(int x, int y, sf::RenderWindow& window);
	void DrawTests(int x, int y, sf::RenderWindow& window);
};

