#include<stdio.h>
#define MAX 5

void insert(int *queue, int *front, int *rear, int data)
{
	if((*rear >= MAX-1 && *front == 0) || (*rear + 1 == *front))
	{
		printf("\nQueue OverFlow\n");
		return;
	}
	else
	{
		*rear = (*rear + 1) % MAX;
		queue[*rear] = data;
		
		if(*front == -1)
		{
			(*front)++;
		}
	}
}

int delq(int *queue, int *front, int *rear)
{
	if(*front == -1)
	{
		printf("\nQueue underFlow\n");
		return;
	}
	else
	{
		int data = queue[*front];
		printf("Deleted Data: %i\n",data);
		queue[*front] = NULL;
		
		if(*front == *rear)
		{
			*front = *rear = -1;
			printf("\nFront: %i\tRear: %i\n",*front,*rear);
		}
		else
		{
			*front = (*front + 1) % MAX;
		}
		return data;
	}
}

void display(int *queue, int front, int rear)
{
	while(rear > -1)
	{
		printf("\nData: %i\tFront: %i\tRear: %i\n",queue[rear],front,rear);
		rear--;
	}
}

void main()
{
	int queue[MAX], front, rear;
	front = rear = -1;
	
	insert(queue, &front, &rear, 10);
	insert(queue, &front, &rear, 20);
	insert(queue, &front, &rear, 30);
	insert(queue, &front, &rear, 40);
	insert(queue, &front, &rear, 50);
	
	delq(queue, &front, &rear);
//	delq(queue, &front, &rear);
//	delq(queue, &front, &rear);
//	delq(queue, &front, &rear);
//	delq(queue, &front, &rear);
//	delq(queue, &front, &rear);

	display(queue, front, rear);
	
	insert(queue, &front, &rear, 60);
	insert(queue, &front, &rear, 70);
	
	display(queue, front, rear);	
}
