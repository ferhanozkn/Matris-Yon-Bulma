#include <stdio.h>
#include <stdlib.h>


#define ROW_NUM 6
#define COL_NUM 12
 
int solveMazeUtil(int maze[ROW_NUM][COL_NUM], int x, int y, int sol[ROW_NUM][COL_NUM]);
 

void printSolution(int sol[ROW_NUM][COL_NUM])
{
	int i, j;
	
	int counter = 0;
	
    for (i = 0; i < ROW_NUM; i++) {
        for (j = 0; j < COL_NUM; j++)
        {
        	printf(" %d ", sol[i][j]);
        	if (sol[i][j] == 1)
        	{
        		counter++;
			}
		}
        printf("\n");
    }
    printf("\nYol Uzunlugu: %d\n", counter);
}
 

int isSafe(int maze[ROW_NUM][COL_NUM], int x, int y)
{

    if (x >= 0 && x < ROW_NUM && y >= 0 && y < COL_NUM && maze[x][y] == 1)
        return 1;
 
    return 0;
}
 
int solveMaze(int maze[ROW_NUM][COL_NUM])
{
    int sol[ROW_NUM][COL_NUM] = { { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 } };
 
    if (solveMazeUtil(maze, 0, 0, sol) == 0) {
        printf("Cozum Bulunamadi.\n");
        return 0;
    }
 
    printSolution(sol);
    return 1;
}
 

int solveMazeUtil(int maze[ROW_NUM][COL_NUM], int x, int y, int sol[ROW_NUM][COL_NUM])
{

    if (x == ROW_NUM - 1 && y == COL_NUM - 1) {
        sol[x][y] = 1;
        return 1;
    }
 

    if (isSafe(maze, x, y) == 1) {

        sol[x][y] = 1;
 
        if (solveMazeUtil(maze, x + 1, y, sol) == 1)
            return 1;
 
        if (solveMazeUtil(maze, x, y + 1, sol) == 1)
            return 1;
 
        sol[x][y] = 0;
        return 0;
    }
 
    return 0;
}
 
int main()
{
	int maze[ROW_NUM][COL_NUM] =
        {
            { 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0 },
            { 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0 },
            { 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0 },
            { 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1 },
            { 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1 },
            { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 }
        };

    solveMaze(maze);
    return 0;
}

