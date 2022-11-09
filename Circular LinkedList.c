#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node *link;
};

void appends(struct Node **q , int d)
{
	struct Node *temp , *r;
	temp = *q;
	r = (struct Node *) malloc(sizeof(struct Node));
	r->data = d;
	r->link = NULL;
	
	if(*q == NULL)
	{
		*q = r;
		r->link = *q;
	}
	else
	{
		for( ; temp->link != *q; temp = temp->link);
		{
			temp->link = r;
			r->link = *q;	
		}		
	}
}

void circularLinkedList(struct Node *q)
{
	struct Node *temp = NULL;
	temp = q;
	while(temp->link != q)
	{
		printf("Data: %i\t Address: %x\n",temp->data,temp->link);
		temp = temp->link;
	}
	printf("Data: %i\t Address: %x\n",temp->data,temp->link);
	temp->link = q;
}

struct Node * insertAtBeg(struct Node *q , int d)
{
	struct Node *temp , *r;
	r = (struct Node *) malloc(sizeof(struct Node));
	r->data = d;
	temp = q;
	while(temp->link != q)
	{
		temp = temp->link;
	}
	temp->link = r;
	r->link = q;
	q = r;
	return q;
}

struct Node * insertAtIndex(struct Node *q , int d , int index)
{
	struct Node *temp , *r;
	r = (struct Node *) malloc(sizeof(struct Node));
	r->data = d;
	temp = q;
	int i = 0;
	while(i != index-1)
	{
		temp = temp->link;
		i++;
	}
	r->link = temp->link;
	temp->link = r;
	return q;
}

struct Node * deleteFromBeg(struct Node *q)
{
	struct Node *temp = q;
	while(temp->link != q)
	{
		temp = temp->link;
	}
	temp->link = q->link;
	q = temp->link;
	return q;
}

 struct Node * deleteFromIndex(struct Node *q , int index)
{
	struct Node *temp , *r;
	temp = q;
	int i = 0;
	while(i != index-1) 
	{
		temp = temp->link;
		i++;	
	}
	r = temp->link;
	temp->link = r->link;
	return q;	
}

struct Node * deleteFromEnd(struct Node *q)
{
	struct Node *temp , *r;
	temp = q;
	while(temp->link != q)
	{
		r = temp;
		temp = temp->link;
	}
	r->link = q;
	return q;
}

void main()
{
	struct Node *p = NULL;
	appends(&p,1);
	appends(&p,2);
	appends(&p,4);
	appends(&p,5);
	appends(&p,6);
	p = insertAtBeg(p,0);
	p = insertAtIndex(p,3,3);
	p = deleteFromBeg(p);
	p = deleteFromIndex(p,3);
	p = deleteFromEnd(p);
	circularLinkedList(p);
}
