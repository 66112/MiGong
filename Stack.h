#ifndef __STACK_H__
#define __STACK_H__
#include "maze.h"
#include <stdio.h>
#include <assert.h>
#define MAX_SIZE 100
typedef Pos DataType;
typedef struct Stack
{
	DataType _array[MAX_SIZE];
	size_t _top;       //Õ»¶¥
	size_t _size;	   //ÔªËØ¸öÊý
}Stack;
void StackInit(Stack* ps);
void StackPush(Stack* ps, DataType x);
void StackPop(Stack* ps);
DataType StackTop(Stack* ps);
size_t StackSize(Stack* ps);
int StackEmpty(Stack* ps);
void StackDestroy(Stack* ps);
#endif  __STACK_H__