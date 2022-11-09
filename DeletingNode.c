#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *link;
};

void appends(struct Node **q , int d);

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
	}
	else
	{
		for( ; temp->link != NULL ; temp = temp->link);
		{
			temp->link = r;
		}
	}
}

void display(struct Node *q)
{
	while(q != NULL)
	{
		printf("DATA: %i\n",q->data);
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

void deleteFromBeg(struct Node **q)
{
	struct Node *temp = *q;
	*q = temp->link;
	free(temp);
}

void deleteFromIndex(struct Node **q , int index)
{
	struct Node *temp , *r;
	temp = *q;
	int i = 0;
	while(i != index-1)
	{
		temp = temp->link;
		i++;
	}
	r = temp->link;
	temp->link = r->link;
	free(r);
}

void deleteFromEnd(struct Node **q)
{
	struct Node *temp , *r;
	temp = *q;
	while(temp->link != NULL)
	{
		r = temp;
		temp = temp->link;
	}
	r->link = NULL;
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
	appends(&p,70);
	appends(&p,80);
	appends(&p,90);
	deleteFromBeg(&p);
	deleteFromIndex(&p,2);
	deleteFromEnd(&p);
	printf("ELEMENTS: %i\n",count(p));
	display(p);
}
