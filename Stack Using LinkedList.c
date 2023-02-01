#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *link;
};

void push(struct Node **top, int d)
{
	struct Node *r;
	r = (struct Node *)malloc(sizeof(struct Node));
	r->data = d;
	r->link = NULL;
	
	if(*top == NULL)
	{
		*top = r;
	}
	else
	{
		r->link = *top;
		*top = r;
	}
}

struct Node * pop(struct Node **top)
{
	struct Node *temp;
	temp = *top;
	*top = temp->link;
	printf("Deleted Data is: %i\n",temp->data);
	free(temp);
	return *top;
}

void display(struct Node *top)
{
	while(top != NULL)
	{
		printf("Data: %i\t Address: %x\t Top: %i\n",top->data,top->link,top);
		top = top->link;
	}
}

void main()
{
	struct Node *top = NULL;
	
	push(&top, 10);
	push(&top, 20);
	push(&top, 30);
	push(&top, 40);
	
	top = pop(&top);
	//top = pop(&top);
	//top = pop(&top);
		
	display(top);
}
