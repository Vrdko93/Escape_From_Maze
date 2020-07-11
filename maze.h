#ifndef MAZE_H_  
#define MAZE_H_

class Maze
{
private:
	char grid[6][7]{
		{'+', '+', '+', '+', '+', '+', '+'},   // '+' means blocked
 		{'+', 'O', 'O', '+', 'E', 'O', '+'},   // 'O' means open
		{'+', 'O', '+', 'O', 'O', '+', '+'},   // '*' means visited
		{'+', 'O', 'O', 'O', 'O', '+', '+'},   // 'E' means exit
		{'+', '+', '+', 'O', '+', '+', '+'},
		{'+', '+', '+', '+', '+', '+', '+'}
	};
	bool escaped{ false };
public:
	void findPath();
	void display() const;
	void reset();
};

void findExitPath(char arr[][7], int startRow, int startColumn, bool& freed);

#endif