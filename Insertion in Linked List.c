#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *link;
};

void appends(struct Node **q , int d);

void appends(struct Node **q , int d)	//Appends Function is also use to Insert at End;
{
	struct Node *temp , *r;
	temp = *q;
	r = (struct Node *)malloc(sizeof(struct Node));
	r->data = d;
	r->link = NULL;
	
	if(*q == NULL)
	{
		*q = r;
	}
	else		//(*q != NULL)
	{
		for(; temp->link !=NULL ; temp=temp->link);
		{
			temp->link = r;
		}
	}
}

void display(struct Node *q)
{
	while(q != NULL)
	{
		printf("Data: %i\n",q->data);
		q = q->link;
	}
}

int count(struct Node *q)
{
	int i = 0;
	while(q != NULL)
	{
		q = q->link;
		i++;
	}
	return i;
}
struct Node * insertAtBeginning(struct Node *q , int d)
{
	struct Node *r;
	r = (struct Node *) malloc(sizeof(struct Node));
	r->data = d;
	r->link = q;
	return r;
}
struct Node * insertAtIndex(struct Node *p , int d , int index)
{
	struct Node *r , *q;
	r = (struct Node *) malloc(sizeof(struct Node));
	q = p;	//To save First Node
	r->data = d;
	
	int i = 0;
	while(i != index-1)
	{
		q = q->link;
		i++;
	}
	r->link = q->link;
	q->link = r;
	return p;
}

void delFromBeg(struct Node **q)
{
	struct Node *temp = *q;
	*q = temp->link;
	free(temp);
}

void main()
{
	struct Node *p = NULL;
	appends(&p,10);
	appends(&p,20);
	appends(&p,30);
	appends(&p,40);
	appends(&p,50);
	appends(&p,60);
	p = insertAtBeginning(p,70);
	p = insertAtIndex(p,80,2);
	delFromBeg(&p);
	appends(&p,90);
	printf("Elements: %i\n",count(p));
	display(p); 
}
