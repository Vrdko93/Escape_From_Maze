#include <iostream>
#include "maze.h"
using namespace std;

void Maze::findPath()
{
	int row, col;
	cout << "\nEscape From A Maze" << endl;
	cout << endl;
	display();
	cout << "Pick a start position from one of the open positions by typing a row number between 1-6 and column number between 1-7: ";
	if (cin >> row >> col)
	{
		grid[row - 1][col - 1] = 'S';
		cout << "\nBefore The Escape" << endl;
		cout << endl;
		display();
		grid[row - 1][col - 1] = 'O';
		findExitPath(grid, row - 1, col - 1, escaped);
	}
	grid[row - 1][col - 1] = 'S';
	if (escaped)
	{
		cout << "\nAfter The Escape" << endl;
		cout << endl;
		display();
		cout << "Path found" << endl;
		cout << "\nDo you want to try a different start location?" << endl;
		cout << "Type 'y' for yes or 'n' for no: ";

		char str;
		if (cin >> str && str == 'y')
		{
			reset();
			findPath();
		}

	}
	else
	{
		display();
		cout << "No path" << endl;
		cout << "\nDo you want to try a different start location?" << endl;
		cout << "Type 'y' for yes or 'n' for no: ";

		char str;
		if (cin >> str && str == 'y')
		{
			reset();
			findPath();
		}
	}
}

void Maze::display() const
{
	for (int i = 0; i < 6; i++)
	{
		for (int k = 0; k < 7; k++)
		{
			cout << grid[i][k] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	cout << "+ means blocked" << endl;
	cout << "O means open" << endl;
	cout << "S means start" << endl;
	cout << "E means exit" << endl;
	cout << "X means visited" << endl;
	cout << endl;
}

void Maze::reset()
{
	for (int i = 0; i < 6; i++)
		for (int k = 0; k < 7; k++)
			if (grid[i][k] == 'X' || grid[i][k] == 'S')
				grid[i][k] = 'O';

	escaped = false;
}

void findExitPath(char arr[][7], int startRow, int startColumn, bool& freed)
{
	if (!freed)
	{
		if (arr[startRow][startColumn] == 'O')
		{
			arr[startRow][startColumn] = 'X';
			findExitPath(arr, startRow + 1, startColumn, freed);
			if (!freed)
				findExitPath(arr, startRow, startColumn + 1, freed);
			if (!freed)
				findExitPath(arr, startRow, startColumn - 1, freed);
			if (!freed)
				findExitPath(arr, startRow - 1, startColumn, freed);
		}
		else if (arr[startRow][startColumn] == 'E')
			freed = true;
	}
}



