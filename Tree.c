#include<stdio.h>
#include<stdlib.h>

struct Tree
{
	struct Tree *Left_Child;
	int Data;
	struct Tree *Right_Child;
};

struct Tree * create()
{
	int data;
	printf("\nEnter the value of Data: ");
	scanf("\n%i",&data);
	
	if(data == -1)
	{
		return NULL;
	}
	
	struct Tree *r;
	r = (struct Tree *)malloc(sizeof(struct Tree));
	r->Data = data;
	
	printf("\nEnter Data in Left Child of %i: ",data);
	r->Left_Child = create();
	
	printf("\nEnter Data in Right Child of %i: ",data);
	r->Right_Child = create();
	
	return r;
}

void inOrder(struct Tree *root)
{
	if(root != NULL)
	{
		inOrder(root->Left_Child);
		printf("%i\t",root->Data);
		inOrder(root->Right_Child);
	}
}

void preOrder(struct Tree *root)
{
	if(root != NULL)
	{
		printf("%i\t",root->Data);
		preOrder(root->Left_Child);
		preOrder(root->Right_Child);
	}
}

void postOrder(struct Tree *root)
{
	if(root != NULL)
	{
		postOrder(root->Left_Child);
		postOrder(root->Right_Child);
		printf("%i\t",root->Data);
	}
}

void main()
{
	struct Tree *root;
	root = NULL;
	
	root = create();
	
	printf("\nInOrder Traversal\n");
	inOrder(root);
	
	printf("\nPreOrder Traversal\n");
	preOrder(root);
	
	printf("\nPostOrder Traversal\n");
	postOrder(root);
}
