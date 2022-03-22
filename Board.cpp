#include "Board.h"


void Board::ConnectTiles()
{
	for (int i = 0; i < height * width; i++)
	{

		if (i == 0)
		{

			Tiles[i].neighbors[3] = &Tiles[i + 1];

			Tiles[i].neighbors[4] = &Tiles[i + width + 1];

			Tiles[i].neighbors[5] = &Tiles[i + width];
		}
		else if (i == width - 1)
		{
			Tiles[i].neighbors[5] = &Tiles[i + width];

			Tiles[i].neighbors[6] = &Tiles[i + width - 1];

			Tiles[i].neighbors[7] = &Tiles[i - 1];

		}
		else if (i == (height * width) - width)
		{
			Tiles[i].neighbors[1] = &Tiles[i - width];

			Tiles[i].neighbors[2] = &Tiles[i - width + 1];

			Tiles[i].neighbors[3] = &Tiles[i + 1];
		}
		else if (i == (height * width) - 1)
		{
			Tiles[i].neighbors[7] = &Tiles[i - 1];
			Tiles[i].neighbors[0] = &Tiles[i - width - 1];
			Tiles[i].neighbors[1] = &Tiles[i - width];
		}
		else if ((0) < i && i < (width - 1))
		{
			Tiles[i].neighbors[3] = &Tiles[i + 1];

			Tiles[i].neighbors[4] = &Tiles[i + width + 1];

			Tiles[i].neighbors[5] = &Tiles[i + width];

			Tiles[i].neighbors[6] = &Tiles[i + width - 1];

			Tiles[i].neighbors[7] = &Tiles[i - 1];

		}
		else if (((height * width) - width) < i && i < ((height * width) - 1))
		{
			Tiles[i].neighbors[0] = &Tiles[i - width - 1];
			Tiles[i].neighbors[1] = &Tiles[i - width];
			Tiles[i].neighbors[2] = &Tiles[i - width + 1];
			Tiles[i].neighbors[3] = &Tiles[i + 1];
			Tiles[i].neighbors[7] = &Tiles[i - 1];
		}
		else if (i != 0 && i != ((height * width) - width) && (i % width == 0))
		{

			Tiles[i].neighbors[1] = &Tiles[i - width];
			Tiles[i].neighbors[2] = &Tiles[i - width + 1];
			Tiles[i].neighbors[3] = &Tiles[i + 1];
			Tiles[i].neighbors[4] = &Tiles[i + width + 1];
			Tiles[i].neighbors[5] = &Tiles[i + width];

		}
		else if (i != width - 1 && i != (height * width) - 1 && (i % width == width - 1))
		{
			Tiles[i].neighbors[5] = &Tiles[i + width];
			Tiles[i].neighbors[6] = &Tiles[i + width - 1];
			Tiles[i].neighbors[7] = &Tiles[i - 1];
			Tiles[i].neighbors[0] = &Tiles[i - width - 1];
			Tiles[i].neighbors[1] = &Tiles[i - width];
		}
		else
		{
			Tiles[i].neighbors[0] = &Tiles[i - width - 1];
			Tiles[i].neighbors[1] = &Tiles[i - width];
			Tiles[i].neighbors[2] = &Tiles[i - width + 1];
			Tiles[i].neighbors[3] = &Tiles[i + 1];
			Tiles[i].neighbors[4] = &Tiles[i + width + 1];
			Tiles[i].neighbors[5] = &Tiles[i + width];
			Tiles[i].neighbors[6] = &Tiles[i + width - 1];
			Tiles[i].neighbors[7] = &Tiles[i - 1];

		}
	}
}

void Board::SetMines()
{
	for (int i = 0; i < numberMines; i++)
	{
		int temp = Random::Number(0, ((height * width) - 1));
		if (Tiles[temp].Mine == false)
		{
			Tiles[temp].Mine = true;
		}
		else if (Tiles[temp].Mine == true)
		{
			i--;
		}
	}
}

void Board::CreateTiles()
{
	Tiles.clear();
	for (int i = 0; i < height * width; i++)
	{
			Tile temp;
			Tiles.push_back(temp);
	}
}

void Board::SetNumberofNeighborMines()
{
	for (int i = 0; i < height * width; i++)
	{
		Tiles[i].NumberofNeighborMines();
	}
}

void Board::Create(int x, int y, int z)
{
	width = x;
	height = y;
	numberMines = z;
	MineCounter = z;
	Lose = false;
	Win = false;
	CreateTiles();
	ConnectTiles();
	SetMines();
	SetNumberofNeighborMines();
}

void Board::CreateTest1(int x, int y, string z)
{
	width = x;
	height = y;
	numberMines = 0;
	MineCounter = 0;
	Lose = false;
	Win = false;
	CreateTiles();
	ConnectTiles();
	for (int i = 0; i < height * width; i++)
	{
		if ((z[i]) == '1')
		{
			Tiles[i].Mine = true;
			MineCounter++;
			numberMines++;
		}
		else if (z[i] == '0')
		{
			Tiles[i].Mine = false;
		}
	}
	SetNumberofNeighborMines();
}

void Board::CreateTest2(int x, int y, string z)
{
	width = x;
	height = y;
	numberMines = 0;
	MineCounter = 0;
	Lose = false;
	Win = false;
	CreateTiles();
	ConnectTiles();
	for (int i = 0; i < height * width; i++)
	{
		if ((z[i]) == '1')
		{
			Tiles[i].Mine = true;
			MineCounter++;
			numberMines++;
		}
		else if (z[i] == '0')
		{
			Tiles[i].Mine = false;
		}
	}
	SetNumberofNeighborMines();
}

void Board::CreateTest3(int x, int y, string z)
{
	width = x;
	height = y;
	numberMines = 0;
	MineCounter = 0;
	Lose = false;
	Win = false;
	CreateTiles();
	ConnectTiles();
	for (int i = 0; i < height * width; i++)
	{
		if ((z[i]) == '1')
		{
			Tiles[i].Mine = true;
			MineCounter++;
			numberMines++;
		}
		else if (z[i] == '0')
		{
			Tiles[i].Mine = false;
		}
	}
	SetNumberofNeighborMines();
}

void Board::RevealRecursive(Tile& _tile)
{
	_tile.Clicked = true;
	if (_tile.Mine == true) 
	{
	}
	else if (_tile.neighborMines > 0)
	{
	}
	else if (_tile.neighborMines == 0)
	{
		for (int i = 0; i < 8; i++)
		{
			if (_tile.neighbors[i] != nullptr && _tile.neighbors[i]->Clicked == false && _tile.neighbors[i]->Flag == false)
			{
				RevealRecursive(*(_tile.neighbors[i]));
			}
		}

		//_tile.Clicked = true;
		//if (i == 0)
		//{
		//	RevealRecursive(Tiles[i + 1], i + 1);
		//	RevealRecursive(Tiles[i + width + 1], i + width + 1);
		//	RevealRecursive(Tiles[i + width], i + width);
		//}
		//else if (i == width - 1)
		//{
		//	RevealRecursive(Tiles[i + width], i + width);
		//	RevealRecursive(Tiles[i + width - 1], i + width - 1);
		//	RevealRecursive(Tiles[i - 1], i - 1);
		//}
		//else if (i == (height * width) - width)
		//{
		//	RevealRecursive(Tiles[i - width], i - width);
		//	RevealRecursive(Tiles[i - width + 1], i - width + 1);
		//	RevealRecursive(Tiles[i + 1], i + 1);
		//}
		//else if (i == (height * width) - 1)
		//{
		//	RevealRecursive(Tiles[i - 1], i - 1);
		//	RevealRecursive(Tiles[i - width - 1], i - width - 1);
		//	RevealRecursive(Tiles[i - width], i - width);
		//}
		//else if ((0) < i && i < (width - 1))
		//{
		//	RevealRecursive(Tiles[i + 1], i + 1);
		//	RevealRecursive(Tiles[i + width + 1], i + width + 1);
		//	RevealRecursive(Tiles[i + width], i + width);
		//	RevealRecursive(Tiles[i + width - 1], i + width - 1);
		//	RevealRecursive(Tiles[i - 1], i - 1);
		//}
		//else if (((height * width) - width) < i && i < ((height * width) - 1))
		//{
		//	RevealRecursive(Tiles[i - width - 1], i - width - 1);
		//	RevealRecursive(Tiles[i - width], i - width);
		//	RevealRecursive(Tiles[i - width + 1], i - width + 1);
		//	RevealRecursive(Tiles[i + 1], i + 1);
		//	RevealRecursive(Tiles[i - 1], i - 1);
		//}
		//else if (i != 0 && i != ((height * width) - width) && (i % width == 0))
		//{
		//	RevealRecursive(Tiles[i - width], i - width);
		//	RevealRecursive(Tiles[i - width + 1], i - width + 1);
		//	RevealRecursive(Tiles[i + 1], i + 1);
		//	RevealRecursive(Tiles[i + width + 1], i + width + 1);
		//	RevealRecursive(Tiles[i + width], i + width);
		//}
		//else if (i != width - 1 && i != (height * width) - 1 && (i % width == width - 1))
		//{
		//	RevealRecursive(Tiles[i + width], i + width);
		//	RevealRecursive(Tiles[i + width - 1], i + width - 1);
		//	RevealRecursive(Tiles[i - 1], i - 1);
		//	RevealRecursive(Tiles[i - width - 1], i - width - 1);
		//	RevealRecursive(Tiles[i - width], i - width);
		//}
		//else
		//{
		//	RevealRecursive(Tiles[i - width - 1], i - width - 1);
		//	RevealRecursive(Tiles[i - width], i - width);
		//	RevealRecursive(Tiles[i - width + 1], i - width + 1);
		//	RevealRecursive(Tiles[i + 1], i + 1);
		//	RevealRecursive(Tiles[i + width + 1], i + width + 1);
		//	RevealRecursive(Tiles[i + width], i + width);
		//	RevealRecursive(Tiles[i + width - 1], i + width - 1);
		//	RevealRecursive(Tiles[i - 1], i - 1);
		//}
		//RevealRecursive(Tiles[x - width - 1], x - width - 1);
		//RevealRecursive(Tiles[x - width], x - width);
		//RevealRecursive(Tiles[x - width + 1], x - width + 1);
		//RevealRecursive(Tiles[x + 1], x + 1);
		//RevealRecursive(Tiles[x + width + 1], x + width + 1);
		//RevealRecursive(Tiles[x + width], x + width);
		//RevealRecursive(Tiles[x + width - 1], x + width - 1);
		//RevealRecursive(Tiles[x - 1], x - 1);
	}
}

void Board::DrawFace(int x, int y, sf::RenderWindow& window) 
{
	if (Win == false && Lose == false)
	{
		Face.background.setTexture(TextureManager::GetTexture("face_happy"));
		Face.background.setPosition(x, y);
		window.draw(Face.background);
	}
	else if (Lose == true)
	{
		Face.background.setTexture(TextureManager::GetTexture("face_lose"));
		Face.background.setPosition(x, y);
		window.draw(Face.background);
	}
	else if (Win == true)
	{
		Face.background.setTexture(TextureManager::GetTexture("face_win"));
		Face.background.setPosition(x, y);
		window.draw(Face.background);
	}
}

void Board::DrawDebug(int x, int y, sf::RenderWindow& window)
{
	Debug.background.setTexture(TextureManager::GetTexture("debug"));
	Debug.background.setPosition(x, y);
	window.draw(Debug.background);
}

void Board::DrawMineCounter(int x, int y, sf::RenderWindow& window)
{
	if (MineCounter >= 0 && MineCounter < 10)
	{
		One.background.setTexture(TextureManager::GetTexture("digits", (MineCounter % 10) * 21, 0, 21, 32));
		One.background.setPosition(x + 63, y);
		window.draw(One.background);
		Ten.background.setTexture(TextureManager::GetTexture("digits", 0, 0, 21, 32));
		Ten.background.setPosition(x + 42, y);
		window.draw(Ten.background);
		Hundred.background.setTexture(TextureManager::GetTexture("digits", 0, 0, 21, 32));
		Hundred.background.setPosition(x + 21, y);
		window.draw(Hundred.background);
	}
	else if (MineCounter > 9 && MineCounter < 100)
	{
		Hundred.background.setTexture(TextureManager::GetTexture("digits", 0, 0, 21, 32));
		Hundred.background.setPosition(x + 21, y);
		window.draw(Hundred.background);
		One.background.setTexture(TextureManager::GetTexture("digits", (MineCounter % 10) * 21, 0, 21, 32));
		One.background.setPosition(x + 63, y);
		window.draw(One.background);
		Ten.background.setTexture(TextureManager::GetTexture("digits", (MineCounter / 10) * 21, 0, 21, 32));
		Ten.background.setPosition(x + 42, y);
		window.draw(Ten.background);
	}
	else if (MineCounter > 99 && MineCounter < 1000)
	{
		Hundred.background.setTexture(TextureManager::GetTexture("digits", (MineCounter / 100) * 21, 0, 21, 32));
		Hundred.background.setPosition(x + 21, y);
		window.draw(Hundred.background);
		One.background.setTexture(TextureManager::GetTexture("digits", (MineCounter % 10) * 21, 0, 21, 32));
		One.background.setPosition(x + 63, y);
		window.draw(One.background);
		Ten.background.setTexture(TextureManager::GetTexture("digits", ((MineCounter / 10) % 10) * 21, 0, 21, 32));
		Ten.background.setPosition(x + 42, y);
		window.draw(Ten.background);
	}
	else if (MineCounter < 0 && MineCounter > -10)
	{
		One.background.setTexture(TextureManager::GetTexture("digits", ((MineCounter * -1) % 10) * 21, 0, 21, 32));
		One.background.setPosition(x + 63, y);
		window.draw(One.background);
		Ten.background.setTexture(TextureManager::GetTexture("digits", 0, 0, 21, 32));
		Ten.background.setPosition(x + 42, y);
		window.draw(Ten.background);
		Hundred.background.setTexture(TextureManager::GetTexture("digits", 0, 0, 21, 32));
		Hundred.background.setPosition(x + 21, y);
		window.draw(Hundred.background);
		Negative.background.setTexture(TextureManager::GetTexture("digits", 210, 0, 21, 32));
		Negative.background.setPosition(x, y);
		window.draw(Negative.background);
	}
	else if (MineCounter < -9 && MineCounter > -100)
	{
		Negative.background.setTexture(TextureManager::GetTexture("digits", 210, 0, 21, 32));
		Negative.background.setPosition(x, y);
		window.draw(Negative.background);
		Hundred.background.setTexture(TextureManager::GetTexture("digits", 0, 0, 21, 32));
		Hundred.background.setPosition(x + 21, y);
		window.draw(Hundred.background);
		One.background.setTexture(TextureManager::GetTexture("digits", ((MineCounter * -1) % 10) * 21, 0, 21, 32));
		One.background.setPosition(x + 63, y);
		window.draw(One.background);
		Ten.background.setTexture(TextureManager::GetTexture("digits", ((MineCounter * -1) / 10) * 21, 0, 21, 32));
		Ten.background.setPosition(x + 42, y);
		window.draw(Ten.background);
	}
	else if (MineCounter < -99 && MineCounter > -1000)
	{
		Negative.background.setTexture(TextureManager::GetTexture("digits", 210, 0, 21, 32));
		Negative.background.setPosition(x, y);
		window.draw(Negative.background);
		Hundred.background.setTexture(TextureManager::GetTexture("digits", ((MineCounter * -1) / 100) * 21, 0, 21, 32));
		Hundred.background.setPosition(x + 21, y);
		window.draw(Hundred.background);
		One.background.setTexture(TextureManager::GetTexture("digits", ((MineCounter * -1) % 10) * 21, 0, 21, 32));
		One.background.setPosition(x + 63, y);
		window.draw(One.background);
		Ten.background.setTexture(TextureManager::GetTexture("digits", (((MineCounter * -1) / 10) % 10) * 21, 0, 21, 32));
		Ten.background.setPosition(x + 42, y);
		window.draw(Ten.background);
	}
}

void Board::DrawTests(int x, int y, sf::RenderWindow& window)
{
	Test1.background.setTexture(TextureManager::GetTexture("test_1"));
	Test1.background.setPosition(x, y);
	window.draw(Test1.background);
	Test2.background.setTexture(TextureManager::GetTexture("test_2"));
	Test2.background.setPosition(x + 64, y);
	window.draw(Test2.background);
	Test3.background.setTexture(TextureManager::GetTexture("test_3"));
	Test3.background.setPosition(x + 128, y);
	window.draw(Test3.background);
}