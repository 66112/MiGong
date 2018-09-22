#include "maze.h"
#include "Stack.h"

int MazeCheckAccess(Pos pos)            //����Ƿ��߹�
{
	return _maze[pos._row][pos._col];
}

int MazeGetPath(Pos entry,Pos exit)
{
	Stack s;
	int flag = 0;
	size_t size = 0;
	StackInit(&s);
	StackPush(&s, entry);             //����ڵ�����ѹ��ջ��
	MazePrint();
	while (StackEmpty(&s))
	{
		Pos cur = StackTop(&s);       //��ǰλ����ջ��
		_maze[cur._row][cur._col] = StackSize(&s)+1;     
		if (cur._col == 5)    //��������
		{
			if (flag == 0)    //��ʾ��һ�ε����������
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
			//return size;               //����
		}
		Pos next;                   //��һ������
	/////////////////////////////////////////////////////////////////////////////
		//	��
		next._row = cur._row - 1;
		next._col = cur._col;
		if (MazeCheckAccess(next) - _maze[cur._row][cur._col] > 1 || MazeCheckAccess(next) == 1)
		{
			StackPush(&s, next);
			continue;
		}
		/////////////////////////////////////////////////////////////////////////////
		//	��
		next._row = cur._row + 1;
		next._col = cur._col;
		if (MazeCheckAccess(next) - _maze[cur._row][cur._col] > 1 || MazeCheckAccess(next) == 1)
		{
			StackPush(&s, next);
			continue;
		}/////////////////////////////////////////////////////////////////////////////
		//	��
		next._row = cur._row;
		next._col = cur._col - 1;
		if (MazeCheckAccess(next) - _maze[cur._row][cur._col] > 1 || MazeCheckAccess(next) == 1)
		{
			StackPush(&s, next);
			continue;
		}/////////////////////////////////////////////////////////////////////////////
		//	��
		next._row = cur._row;
		next._col = cur._col + 1;
		if (MazeCheckAccess(next) - _maze[cur._row][cur._col] > 1 || MazeCheckAccess(next) == 1)
		{
			StackPush(&s, next);
			continue;
		}
		StackPop(&s);                //��������ߵ����˵������·���ߣ�����
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
	printf("ԭʼ�Թ���\n");
	MazePrint();
	int a=MazeGetPath(entry, exit);
	printf("�ߺ��Թ���\n");
	MazePrint();
	if (a == 0)
		printf("��ͨ·\n");
	else
	{
		printf("��ͨ·\n");
		printf("���ͨ·Ϊ: %d �� \n", a);
	}
}

int main()
{
	TestMazeShortPath();
	return 0;
}