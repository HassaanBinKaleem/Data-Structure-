#include<stdio.h>
#include<stdlib.h>

struct BTNode
{
	struct BTNode *Left_Child;
	int Data;
	struct BTNode *Right_Child;	
};

struct BTNode * create(struct BTNode *root, int data)
{
	struct BTNode *r;
	
	if(root == NULL)
	{
		r = (struct BTNode *)malloc(sizeof(struct BTNode));
		r->Left_Child = NULL;
		r->Data = data;
		r->Right_Child = NULL;
		
		return r;
	}
	else if(data < root->Data)
	{
		root->Left_Child = create(root->Left_Child, data);	
	}
	else
	{
		root->Right_Child = create(root->Right_Child, data);
	}
	
	return root;
}

void insert(struct BTNode *root, int key)
{
	struct BTNode *prev = root;
	while(root != NULL)
	{
		if(key == root->Data)
		{
			printf("Cannot Insert Data %i already exists in BST",key);
			return;
		}
		else if(key < root->Data)
		{
			root = root->Left_Child;
		}
		else
		{
			root = root->Right_Child;
		}
	}
	struct BTNode *r;
	r = (struct BTNode *)malloc(sizeof(struct BTNode));
	r->Data = key;
	if(key < prev->Data)
		{
			prev->Left_Child = r;
		}
		else
		{
			prev->Right_Child = r;
		}
}

void inOrder(struct BTNode *root)
{
	if(root != NULL)
	{
		inOrder(root->Left_Child);
		printf("%i\t",root->Data);
		inOrder(root->Right_Child);
	}
}

void preOrder(struct BTNode *root)
{
	if(root != NULL)
	{
		printf("%i\t",root->Data);
		preOrder(root->Left_Child);
		preOrder(root->Right_Child);
	}
}

void postOrder(struct BTNode *root)
{
	if(root != NULL)
	{
		postOrder(root->Left_Child);
		postOrder(root->Right_Child);
		printf("%i\t",root->Data);
	}
}

struct BTNode * search(struct BTNode *root, int key)
{
	if(root == NULL)
	{
		return NULL;
	}
	if(root->Data == key)
	{
		return root;
	}
	else if(root->Data > key)
	{
		return search(root->Left_Child, key);
	}
	else
	{
		return search(root->Right_Child, key);
	}
}

struct BTNode * iterativeSearch(struct BTNode *root, int key)
{
	while(root != NULL)
	{
		if(key == root->Data)
		{
			return root;
		}
		else if(key < root->Data)
		{
			root = root->Left_Child;
		}
		else
		{
			root = root->Right_Child;
		}
	}
	return NULL;
}

struct BTNode *inOrderPredecessor(struct BTNode *root)
{
	//In-Order Predecessor is Left sub tree's right most child
	root = root->Left_Child;
	while(root->Right_Child != NULL)
	{
		root = root->Right_Child;
	}
	return root;
}

struct BTNode * deletion(struct BTNode *root, int key)
{
	struct BTNode *iPre;
	if(root == NULL)
	{
		return NULL;
	}
	if(root->Left_Child == NULL && root->Right_Child == NULL)
	{
		free(root);
		return NULL;
	}
	if(key < root->Data)
	{
		root->Left_Child = deletion(root->Left_Child, key);
	}
	else if(key > root->Data)
	{
		root->Right_Child = deletion(root->Right_Child, key);
	}
	else
	{
		iPre = inOrderPredecessor(root);
		root->Data = iPre->Data;
		root->Left_Child = deletion(root->Left_Child, iPre->Data);
	}
	return root;
}

void main()
{
	struct BTNode *root = NULL;
	int n, i, s, is, a, d;
	
	printf("Enter Number of Items for Insertion: ");
	scanf("%i",&n);
	
	for(i = 0; i < n; i++)
	{
		int data;
		printf("\nEnter Data: ");
		scanf("%i",&data);
		root = create(root, data);	
	}	
	
	printf("\nInOrder Traversal:\n");
	inOrder(root);
	
//	printf("\nPreOrder Traversal:\n");
//	preOrder(root);
//	
//	printf("\nPostOrder Traversal:\n");
//	postOrder(root); 
	
//	printf("\nEnter new Number you want to Insert: ");
//	scanf("%i",&a);
//	insert(root, a);

	printf("\nEnter Data to be Deleted: ");
	scanf("%i",&d);	
	root = deletion(root,d);
	
	printf("\nInOrder Traversal after Deletion:\n");
	inOrder(root);
	
//	printf("\n\nEnter Number to Search and search through Recursive Search: ");
//	scanf("%i",&s);
//	root = search(root, s);
//	if(root != NULL)
//	{
//		printf("\nSearched Number Found thorught Recursive Search: %i",root->Data);
//	}
//	else
//	{
//		printf("\nSearched Number Not Found thorught Recursive Search\n");	
//	}
//	
//	printf("\n\nEnter Number to Search and search through Iterative Search: ");
//	scanf("%i",&is);
//	root = iterativeSearch(root, is);
//	if(root != NULL)
//	{
//		printf("\nSearched Number Found thorught Iteractive Search: %i",root->Data);
//	}
//	else
//	{
//		printf("\nSearched Number Not Found thorught Iterative Search\n");	
//	}
}
