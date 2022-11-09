#include<stdio.h>

struct Node
{
	int data;
	struct Node *link;
};

void main()
{
	int *p;
	struct Node *temp , *lastNode;
	
	temp = (struct Node *) malloc(sizeof(struct Node));
	temp->data = 10;
	temp->link = NULL;
	p = temp;
	lastNode = temp;
	
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = 20;
	temp->link = NULL;
	lastNode->link = temp;
	lastNode = temp;
	
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = 30;
	temp->link = NULL;
	lastNode->link = temp;
	lastNode = temp;
	
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = 40;
	temp->link = NULL;
	lastNode->link = temp;
	lastNode = temp;
	
	//Creating new Node and placing it to the first place.
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = 50;
	temp->link = p;
	p = temp;
	
	temp = p;
	printf("Linked List Elements are: \n\n");
	int count = 0;
	while(temp != NULL)
	{
		printf("\nData: %i\t Address: %i",temp->data,temp->link);
		temp = temp->link;
		count++;
	}
	printf("\n\nTotal counts are: %i",count);
}
