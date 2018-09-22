#pragma once
#include <stdio.h>
#include <assert.h>
#define N 6
static int _maze[N][N] = {
	{0, 0, 0, 0, 0, 0 },
	{0, 0, 1, 1, 1, 1 },
	{0, 0, 1, 0, 1, 0 },
	{0, 0, 1, 1, 1, 0 },
	{0, 0, 1, 1, 1, 1 },
	{0, 0, 1, 0, 0, 0 },
};
typedef struct Pos
{
	size_t _row;       //��
	size_t _col;	   //��
}Pos;

void MazePrint();
int MazeGetPath(Pos entry, Pos exit); //
int MazeCheckAccess(Pos pos);		//����Ƿ��߹�
int MazeShortPath(Pos entry);		//���·��