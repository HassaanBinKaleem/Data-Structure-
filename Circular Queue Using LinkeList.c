#include<stdio.h>
#include<stdlib.h>

struct Queue
{
	int data;
	struct Queue *link;
};

void insert(struct Queue **front, struct Queue **rear, int d)
{
	struct Queue *r;
	r = (struct Queue *)malloc(sizeof(struct Queue));
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

void display(struct Queue *front, struct Queue *rear)
{
	struct Queue *temp = front;
	while(temp != NULL)
	{
		printf("Data: %i\t Address: %x\t Front: %x\t Rear: %x\n",temp->data,temp->link,front,rear);
		temp = temp->link;
	}
}

void main()
{
	struct Queue *front, *rear;
	front = rear = NULL;
	int size,i;
	printf("Enter the Size of Linked List: ");
	scanf("%i",&size);
	
	for(i=1 ; i<=size ; i++)
	{
		int data;
		printf("\nEnter Data: ");
		scanf("%i",&data);
		insert(&front, &rear, data);	
	}
	
	display(front, rear);
}
