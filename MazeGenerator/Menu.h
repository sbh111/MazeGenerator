#ifndef MENU_H
#define MENU_H
#pragma once

#include "SFML/Graphics.hpp"
#include "Screens.h"
#include <iostream>

const int NUM_GENERATION_ALG = 3;	// these const variables are the number of generation/solution algorithms + 1 (to account 
const int NUM_SOLUTION_ALG = 2;    //     for a back/exit menu option)

class Menu : public BasicScreen
{
public:
	Menu(float width, float height);
	~Menu();

	int Run(sf::RenderWindow &window, Grid &grid);
	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int getPressedItem() { return menuIndex; }

private:
	sf::Font font;
	int menuIndex;
	sf::Text title;
	sf::Text genMenu[NUM_GENERATION_ALG];
	sf::Text solveMenu[NUM_SOLUTION_ALG];
};

	// Menu.cpp

	Menu::Menu(float width, float height) 
	{

		if (!font.loadFromFile("Gamegirl.ttf")) {
			std::cout << "oh no\n";
		}

		title.setFont(font);
		title.setFillColor(sf::Color::White);
		title.setCharacterSize(45);
		title.setString("MAZE GENERATOR");
		title.setPosition(sf::Vector2f(width / 4, 20));

		genMenu[0].setFont(font);
		genMenu[0].setFillColor(sf::Color::Blue);
		genMenu[0].setString("Recursive Backtracker");
		genMenu[0].setPosition(sf::Vector2f(width / 4, height / (NUM_GENERATION_ALG + 1) * 1));

		genMenu[1].setFont(font);
		genMenu[1].setFillColor(sf::Color::White);
		genMenu[1].setString("Options");
		genMenu[1].setPosition(sf::Vector2f(width / 4, height / (NUM_GENERATION_ALG + 1) * 2));

		genMenu[2].setFont(font);
		genMenu[2].setFillColor(sf::Color::White);
		genMenu[2].setString("Exit");
		genMenu[2].setPosition(sf::Vector2f(width / 4, height / (NUM_GENERATION_ALG + 1) * 3));

		solveMenu[0].setFont(font);
		solveMenu[0].setFillColor(sf::Color::Blue);
		solveMenu[0].setString("Depth First Search");
		solveMenu[0].setPosition(sf::Vector2f(width / 4, height / (NUM_SOLUTION_ALG + 1) * 3));

		solveMenu[1].setFont(font);
		solveMenu[1].setFillColor(sf::Color::White);
		solveMenu[1].setString("Back");
		solveMenu[1].setPosition(sf::Vector2f(width / 4, height / (NUM_SOLUTION_ALG + 1) * 3));


		menuIndex = 0;

	}

	void Menu::draw(sf::RenderWindow &window)
	{
		window.draw(title);

		for (int i = 0; i < NUM_GENERATION_ALG; i++)
		{
			window.draw(genMenu[i]);
		}
	}

	void Menu::MoveUp()
	{
		if (menuIndex - 1 >= 0)
		{
			genMenu[menuIndex].setFillColor(sf::Color::White);
			menuIndex--;
			genMenu[menuIndex].setFillColor(sf::Color::Blue);
		}
	}

	void Menu::MoveDown()
	{
		if (menuIndex + 1 < NUM_GENERATION_ALG)
		{
			genMenu[menuIndex].setFillColor(sf::Color::White);
			menuIndex++;
			genMenu[menuIndex].setFillColor(sf::Color::Blue);
		}
	}

	int Menu::Run(sf::RenderWindow &window, Grid &grid)
	{
		while (window.isOpen()) {
			sf::Event event;

			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::KeyReleased:
					switch (event.key.code)
					{
					case sf::Keyboard::Up:
						this->MoveUp();
						break;

					case sf::Keyboard::Down:
						this->MoveDown();
						break;

					case sf::Keyboard::Return:
						switch (this->getPressedItem())
						{
						case 0:
							return RECURSIVE_BACKTRACKER_SCREEN;
							break;
						case 1:
							std::cout << "Options" << std::endl;
							break;
						case 2:
							window.close();
							break;
						}

						break;
					}

					break;
				case sf::Event::Closed:
					window.close();

					break;

				}
			}

			window.clear();
			this->draw(window);
			window.display();
		}

		return 1;
		}
		
	


	Menu::~Menu()
	{
	}













#endif