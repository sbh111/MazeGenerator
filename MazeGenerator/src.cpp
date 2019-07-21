/*
	Contributors: Saad Bhatti, Abdusammad Quadri
	
	Description: 
	This program demonstrates various Maze generation and solution algorithms with
	the use of the SFML library for visuals.

	DELETE THIS COMMENT LATER

	Brainstorming:
	info about managing screens: https://github.com/SFML/SFML/wiki/Tutorial:-Manage-different-Screens

	create a grid of n x m cells, and initialize all of them to be unconnected.
	prompt the user for a maze generation routine from a list. just implement 1 for now.
	prompt the user for a path finding routine that finds the path from entrance to exit.

	each of these "routines" can be implemented as a screen, check the link above

	pass the window into the chosen Maze Generating Routine, and have it update each frame.
	after its finsished, prompt user to select entrance and exit for the maze.
	then pass the window or grid in to the chosen pathfinding routine and have it update each frame.
	finally, crash and burn the computer.
*/

#include "SFML/Graphics.hpp"
#include "Screens.h"
#include "Grid.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Maze Generator!");	//this window will be passed around from screen to screen

	std::vector<BasicScreen*> Screens(100);	//vector of available screens, can switch from screen to screen by returning its index			
	
	//initializing the screens
	Test testScreen;
	TestGrid testGrid;
	RecursiveBacktracker backtracker;
	DFS dfs;

	Screens[TEST_GRID_SCREEN] = &testGrid;
	Screens[RECURSIVE_BACKTRACKER_SCREEN] = &backtracker;
	Screens[DFS_SCREEN] = &dfs;



	int m = 20;				//get these from user
	int n = 20;

	int screenSize = (window.getSize().x < window.getSize().y) ? window.getSize().x : window.getSize().y;
	int gridSize = (m > n) ? m: n;

	Grid *maze;
	maze = new Grid(m, n, screenSize/gridSize); //instantiate a 20 x 20 grid with Cell sizes of 50 x 50


	//FIXME: Only For Testing
	backtracker.Run(window, *maze);
	backtracker.Run(window, *maze);
	dfs.Run(window, *maze);
	dfs.Run(window, *maze);
	window.close();
	delete maze;
	return 0;




	int screen = RECURSIVE_BACKTRACKER_SCREEN;
	while (screen >= 0)
	{
		screen = Screens[screen]->Run(window, *maze);
	}
	window.close();

	delete maze;
	return (0);
}