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

	
	if( *q == NULL)
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
	while( q != NULL)
	{
		printf("DATA: %i\t ADDRESS: %x\n", q->data , q->link);
		q = q->link;
	}
}

int count(struct Node *q)
{
	int i = 0;
	while( q != NULL)
	{
		q = q->link;
		i++;
	}
	return i;
}

void main()
{
	struct Node *p = NULL;
	int n , i , d;
	
	printf("Enter Number of Nodes: ");
	scanf("%i",&n);
	for(i = 1 ; i <= n ; i++)
	{
		printf("\nEnter Data in Node: ");
		scanf("%i",&d);
		appends(&p,d);
	}
	printf("ELEMENTS: %i\n",count(p));
	display(p);
}




