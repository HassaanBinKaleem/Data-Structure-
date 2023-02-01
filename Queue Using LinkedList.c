#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *link;
};

void insert(struct Node **front, struct Node **rear, int d)
{
	struct Node *r;
	r = (struct Node *)malloc(sizeof(struct Node));
	r->data = d;
	r->link = NULL;
	
	if(*rear == NULL)
	{
		*front = *rear = r;
	}
	else
	{
		(*rear)->link = r;
		*rear = r;
	}
}

int delq(struct Node **front, struct Node **rear)
{
	if(*front == NULL)
	{
		printf("Queue UnderFlow\n");
	}
	else
	{
		struct Node *temp = *front;
		int data = temp->data;
		if(*front == *rear)
		{
			*front = *rear = NULL;
			printf("Front: %i\t Rear: %i\n",*front,*rear);
		}
		*front = temp->link;
		free(temp);
		return data;
	}
}

void display(struct Node *front, struct Node *rear)
{
	struct Node *temp = front;
	while(temp != NULL)
	{
		printf("Data: %i\t Address: %x\t Front: %x\t Rear: %x\n",temp->data,temp->link,front,rear);
		temp = temp->link;
	}
}

void main()
{
	struct Node *front = NULL, *rear = NULL;
	
	insert(&front, &rear, 10);
	insert(&front, &rear, 20);
	insert(&front, &rear, 30);
	
//	delq(&front, &rear);
//	delq(&front, &rear);
//	delq(&front, &rear);
	
	display(front, rear);
}
