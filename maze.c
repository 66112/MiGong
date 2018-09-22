#include "maze.h"
#include "Stack.h"

int MazeCheckAccess(Pos pos)            //检查是否走过
{
	return _maze[pos._row][pos._col];
}

int MazeGetPath(Pos entry,Pos exit)
{
	Stack s;
	int flag = 0;
	size_t size = 0;
	StackInit(&s);
	StackPush(&s, entry);             //将入口点坐标压入栈中
	MazePrint();
	while (StackEmpty(&s))
	{
		Pos cur = StackTop(&s);       //当前位置在栈顶
		_maze[cur._row][cur._col] = StackSize(&s)+1;     
		if (cur._col == 5)    //出口条件
		{
			if (flag == 0)    //表示第一次到达出口条件
			{
				size = StackSize(&s);
				flag++;
			}
			else
			{
				if (StackSize(&s) < size)
				{
					size = StackSize(&s);
				}
			}
			//return size;               //出口
		}
		Pos next;                   //下一个坐标
	/////////////////////////////////////////////////////////////////////////////
		//	上
		next._row = cur._row - 1;
		next._col = cur._col;
		if (MazeCheckAccess(next) - _maze[cur._row][cur._col] > 1 || MazeCheckAccess(next) == 1)
		{
			StackPush(&s, next);
			continue;
		}
		/////////////////////////////////////////////////////////////////////////////
		//	下
		next._row = cur._row + 1;
		next._col = cur._col;
		if (MazeCheckAccess(next) - _maze[cur._row][cur._col] > 1 || MazeCheckAccess(next) == 1)
		{
			StackPush(&s, next);
			continue;
		}/////////////////////////////////////////////////////////////////////////////
		//	左
		next._row = cur._row;
		next._col = cur._col - 1;
		if (MazeCheckAccess(next) - _maze[cur._row][cur._col] > 1 || MazeCheckAccess(next) == 1)
		{
			StackPush(&s, next);
			continue;
		}/////////////////////////////////////////////////////////////////////////////
		//	右
		next._row = cur._row;
		next._col = cur._col + 1;
		if (MazeCheckAccess(next) - _maze[cur._row][cur._col] > 1 || MazeCheckAccess(next) == 1)
		{
			StackPush(&s, next);
			continue;
		}
		StackPop(&s);                //如果程序走到这里，说明以无路可走，回溯
	}
	return size;
}

void MazePrint()
{
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf(" %d ", _maze[i][j]);
		}
		printf("\n");
	}
}
void TestMazeShortPath()
{
	Pos entry;
	entry._row = 5;
	entry._col = 2;
	Pos exit;
	exit._row = 4;
	exit._col = 5;
	printf("原始迷宫：\n");
	MazePrint();
	int a=MazeGetPath(entry, exit);
	printf("走后迷宫：\n");
	MazePrint();
	if (a == 0)
		printf("无通路\n");
	else
	{
		printf("有通路\n");
		printf("最短通路为: %d 步 \n", a);
	}
}

int main()
{
	TestMazeShortPath();
	return 0;
}