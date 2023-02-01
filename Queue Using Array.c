#include<stdio.h>
#define MAX 4

void insert(int *queue, int *front, int *rear, int data)
{
	if(*rear >= MAX-1)
	{
		printf("Queue OverFlow\n Cannot Insert Elements\n");
	}
	else
	{
		(*rear)++;
		queue[*rear] = data;
		
		if(*front == -1)
		{
			(*front)++;
		}
	}
}

int qdelete(int *queue, int *front, int *rear)
{
	if(*front == -1)
	{
		printf("Queue is UnderFlow\n Cannot Delete Elements");
	}
	else
	{
		int data = queue[*front];
		printf("\nDeleted Data: %i\n",data);
		queue[*front] = NULL;
		
		if(*front == *rear)
		{
			*front = *rear = -1;
			printf("Front: %i\t Rear: %i\n",*front,*rear);
		}
		(*front)++;
		return data;
	}
}

void display(int *queue, int *front, int *rear)
{
	while(*rear > -1)
	{
		printf("Data: %i\t Front: %i\t Rear: %i\n",queue[*rear], *front, *rear);
		(*rear)--;
	}
}

void main()
{
	int queue[MAX], front, rear;
	front = -1;
	rear = -1;
	
	insert(queue, &front, &rear, 10);
	insert(queue, &front, &rear, 20);
	insert(queue, &front, &rear, 30);
	insert(queue, &front, &rear, 40);
	
//	qdelete(queue, &front, &rear);
//	qdelete(queue, &front, &rear);
//	qdelete(queue, &front, &rear);
//	qdelete(queue, &front, &rear);
	
	display(queue, &front, &rear);
}
