#include<stdio.h>
#include<stdlib.h>

struct Node
{
	struct Node *prevNode;
	int data;
	struct node *link;
};

void appends(struct Node **q , int d)
{
	struct Node *temp , *r ;
	temp = *q;
	r = (struct Node *) malloc(sizeof(struct Node));
	r->data = d;
	r->link = NULL;
	
	if(*q == NULL)
	{
		*q = r;
		r->prevNode = NULL;
	}
	else
	{
		while(temp->link != NULL)
		{
			temp = temp->link;
		}
		r->prevNode = temp;
		temp->link = r;
	}
}

void display(struct Node *q)
{
	while(q != NULL)
	{
		printf("Address: %x\t ||\tData: %i\t||\tAddress: %x\n", q->prevNode , q->data , q->link);
		q = q->link;
	}
}

struct Node * insertAtBeg(struct Node *q , int d)
{
	struct Node *r;
	r = (struct Node *) malloc(sizeof(struct Node));
	r->data = d;
	r->prevNode = NULL;
	r->link = q;
	q->prevNode = r;
	q = r;
	return q;
}

struct Node * insertAtIndex(struct Node *q , int d , int index)
{
	
	struct Node *temp , *r , *t;
	temp = q;
	r = (struct Node *) malloc(sizeof(struct Node));
	r->data = d;
	int i = 0;
	while(i != index-1)
	{
		temp = temp->link;
		i++;
	}
	r->link = temp->link;
	r->prevNode = temp;
	temp->link = r;
	t = r->link;
	t->prevNode = r;
	return q;
}

struct Node * deleteFromBeg(struct Node *q)
{
	struct Node *temp , *r;
	temp = q;
	r = temp->link;
	r->prevNode = NULL;
	q = r;
	free(temp);
	return q;
}

struct Node * deleteFromIndex(struct Node *q , int index)
{
	struct Node *temp , *r , *t;
	temp = q;
	int i = 1;
	while(i != index)
	{
		r = temp;
		temp = temp->link;
		i++;
	}
	temp = r->link;
	r->link = temp->link;
	t = temp->link;
	t->prevNode = r;
	free(temp);
	return q;
}

void main()
{
	struct Node *p = NULL;
	appends(&p,10);
	appends(&p,20);
	appends(&p,30);
	appends(&p,40);
	appends(&p,50);
	//p = insertAtBeg(p,40);
	//p = insertAtIndex(p,40,2);
	//p = deleteFromBeg(p);
	p = deleteFromIndex(p,3);
	display(p);
}
