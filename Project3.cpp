#include <SFML/Graphics.hpp>
#include <iostream> 
using namespace std;
#include <fstream>
#include <string>
#include "Tile.h"
#include "Board.h"


int main()
{
    string x, y, z;
    int Width, Height, Mines;
    ifstream infile("boards/config.cfg");
    getline(infile, x);
    getline(infile, y);
    getline(infile, z);
    Width = stoi(x);
    Height = stoi(y);
    Mines = stoi(z);
    Board board;
    board.Create(Width, Height, Mines);
    infile.close();

    string test1;
    infile.open("boards/testboard1.brd");
  
    while (getline(infile, x))
    {
        test1 += x;
    }
    infile.close();
    
    string test2;
    infile.open("boards/testboard2.brd");
    while (getline(infile, x))
    {
        test2 += x;
    }
    infile.close();

    string test3;
    infile.open("boards/testboard3.brd");
    while (getline(infile, x))
    {
        test3 += x;
    }

    sf::RenderWindow window(sf::VideoMode(Width * 32, (Height * 32) + 88), "Minesweeper");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    auto mousePosition = sf::Mouse::getPosition();
                    mousePosition = sf::Mouse::getPosition(window);
                    sf::FloatRect rectangle;
                    for (int i = 0; i < board.width * board.height; i++)
                    {
                        rectangle = board.Tiles[i].background.getGlobalBounds();
                        sf::Vector2f mousePosFloat(mousePosition.x, mousePosition.y);
                        if (rectangle.contains(mousePosFloat) && board.Tiles[i].Flag == false && board.Win == false && board.Lose == false)
                        {
                            //board.Tiles[i].Clicked = true;
                            board.RevealRecursive(board.Tiles[i]);
                            if (board.Tiles[i].Mine == true)
                            {
                                for (int j = 0; j < board.width * board.height; j++)
                                {
                                    if (board.Tiles[j].Mine == true)
                                    {
                                        board.Tiles[j].Clicked = true;
                                    }
                                }
                                board.Lose = true;
                            }
                        }
                    }
                    rectangle = board.Face.background.getGlobalBounds();
                    sf::Vector2f mousePosFloat(mousePosition.x, mousePosition.y);
                    if (rectangle.contains(mousePosFloat))
                    {
                        bool p = false;
                        for (int i = 0; i < board.width * board.height; i++)
                        {
                            if (board.Tiles[i].Debug == true)
                            {
                                p = true;
                            }
                        }
                        if (p == true)
                        {
                            board.Create(Width, Height, Mines);
                            for (int i = 0; i < Width * Height; i++)
                            {
                                if (board.Tiles[i].Mine == true)
                                {
                                    board.Tiles[i].Debug = true;
                                }
                            }
                        }
                        else if (p == false)
                        {
                            board.Create(Width, Height, Mines);
                        }
                    }
                    rectangle = board.Test1.background.getGlobalBounds();
                    if (rectangle.contains(mousePosFloat))
                    {
                        bool q = false;
                        for (int i = 0; i < Width * Height; i++)
                        {
                            if (board.Tiles[i].Debug == true)
                            {
                                q = true;
                            }
                        }
                        if (q == true)
                        {
                            board.CreateTest1(Width, Height, test1);
                            for (int i = 0; i < Width * Height; i++)
                            {
                                if (board.Tiles[i].Mine == true)
                                {
                                    board.Tiles[i].Debug = true;
                                }
                            }
                        }
                        else if (q == false)
                        {
                            board.CreateTest1(Width, Height, test1);
                        }
                    }
                    rectangle = board.Test2.background.getGlobalBounds();
                    if (rectangle.contains(mousePosFloat))
                    {
                        bool z = false;
                        for (int i = 0; i < Width * Height; i++)
                        {
                            if (board.Tiles[i].Debug == true)
                            {
                                z = true;
                            }
                        }
                        if (z == true)
                        {
                            board.CreateTest2(Width, Height, test2);
                            for (int i = 0; i < Width * Height; i++)
                            {
                                if (board.Tiles[i].Mine == true)
                                {
                                    board.Tiles[i].Debug = true;
                                }
                            }
                        }
                        else if (z == false)
                        {
                            board.CreateTest2(Width, Height, test2);
                        }
                    }
                    rectangle = board.Test3.background.getGlobalBounds();
                    if (rectangle.contains(mousePosFloat))
                    {
                        bool b = false;
                        for (int i = 0; i < Width * Height; i++)
                        {
                            if (board.Tiles[i].Debug == true)
                            {
                                b = true;
                            }
                        }
                        if (b == true)
                        {
                            board.CreateTest3(Width, Height, test3);
                            for (int i = 0; i < Width * Height; i++)
                            {
                                if (board.Tiles[i].Mine == true)
                                {
                                    board.Tiles[i].Debug = true;
                                }
                            }
                        }
                        else if (b == false)
                        {
                            board.CreateTest3(Width, Height, test3);
                        }
                    }
                    rectangle = board.Debug.background.getGlobalBounds();
                    if (rectangle.contains(mousePosFloat) && board.Win == false && board.Lose == false)
                    {
                        for (int i = 0; i < board.width * board.height; i++)
                        {
                            if (board.Tiles[i].Mine == true && board.Tiles[i].Debug == false)
                            {
                                board.Tiles[i].Debug = true;
                            }
                            else if (board.Tiles[i].Mine == true && board.Tiles[i].Debug == true)
                            {
                                board.Tiles[i].Debug = false;
                            }
                               
                        }
                    }
                }
                else if (event.mouseButton.button == sf::Mouse::Right)
                {
                    auto mousePosition = sf::Mouse::getPosition();
                    mousePosition = sf::Mouse::getPosition(window);
                    sf::Vector2f mousePosFloat(mousePosition.x, mousePosition.y);
                    sf::FloatRect rectangle;
                    for (int i = 0; i < board.width * board.height; i++)
                    {
                        rectangle = board.Tiles[i].background.getGlobalBounds();
                        if (rectangle.contains(mousePosFloat))
                        {
                            if (board.Tiles[i].Flag == false)
                            {
                                board.Tiles[i].Flag = true;
                                board.MineCounter--;

                            }
                            else if (board.Tiles[i].Flag == true)
                            {
                                board.Tiles[i].Flag = false;
                                board.MineCounter++;
                            }
                        }
                    }
                }
            }
        }
        board.Win = true;
        for (int i = 0; i < board.width * board.height; i++)
        {
            if (board.Tiles[i].Clicked == false && board.Tiles[i].Mine == false)
            {
                board.Win = false;
            }
        }
        if (board.Win == true)
        {
            for (int i = 0; i < board.height * board.width; i++)
            {
                if (board.Tiles[i].Mine == true)
                {
                    board.Tiles[i].Flag = true;
                }
            }
            board.MineCounter = 0;
        }
        window.clear();
        for (int i = 0; i < board.width * board.height; i++)
        {
            board.Tiles[i].DrawTile((i % board.width) * 32, (i / board.width) * 32, window);
        }
        board.DrawFace((board.width * 16 - 32), board.height * 32, window);
        board.DrawDebug((board.width * 16 + 96), board.height * 32, window);
        board.DrawMineCounter(0, board.height * 32, window);
        board.DrawTests((board.width * 16 + 160), board.height * 32, window);
    
        window.display();
    }
    
    TextureManager::Clear();
    return 0;
}