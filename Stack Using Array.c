#include<stdio.h>
#define MAX 4

void push(int *stack , int *top , int data)
{
	if(*top >= MAX-1)
	{
		printf("Stack OverFlow\n");
		printf("Cannot Push elements\n");
	}
	else
	{
		(*top)++;
		stack[*top] = data;
	}
}

int pop(int *stack , int *top)
{
	if(*top <= -1)
	{
		printf("Stack UnderFlow\n");
		printf("Cannot pop elements\n");
		return NULL;
	}
	else
	{
		int temp;
		temp = stack[*top];
		stack[*top] = NULL;
		(*top)--;
		return temp;
	}
}

int stackTop(int *stack, int top)
{
	return stack[top];
}

int stackBottom(int *stack, int top)
{
	return stack[0];
}

void display(int *stack , int top)
{
	if(top <= -1)
	{
		printf("Stack is Empty");
	}
	while(top > -1)
	{
		printf("Data: %i\tTop: %i\n",stack[top],top);
		top--;
	}
}

void main()
{
	int stack[MAX] , top;
	top = -1;
	
	push(stack , &top , 10);
	push(stack , &top , 20);
	push(stack , &top , 30);
	push(stack , &top , 40);
	push(stack , &top , 50);
	
	pop(stack , &top);
	
	display(stack , top);
	
	printf("\nTop most Value of Stack is: %i",stackTop(stack, top));
	printf("\nBottom most Value of Stack is: %i",stackBottom(stack, top));
}
