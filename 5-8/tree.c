#include <stdio.h>

typedef int ElementType;
typedef struct TreeNode * Tree;

struct TreeNode
{
	ElementType Element;
	Tree left;
	Tree right;
};

Tree MakeEmpty(Tree T)
{
	if(T != NULL)
	{
		MakeEmpty(T->left);
		MakeEmpty(T->right);
		free(T);
	}
	return NULL;
}

Tree find(Tree T,ElementType e)
{
	if(T == NULL)
	    return NULL;
	if(T->Element > e)
	    return find(T->left,e);
	else if(T->Element < e)
	    return find(T->right,e);
	else
	     return T;	    
}

Tree findMin(Tree T)
{
	if(T == NULL)
	    return NULL;
	if(T->left != NULL)
	    return findMin(T->left);
	else
	    return T;	    
}


Tree findMax(Tree T)
{
	if(T == NULL)
	    return NULL;
	if(T->right != NULL)
	    return findMax(T->right);
	else
	    return T;	    
}

Tree insert(Tree T,ElementType e)
{
	if(T == NULL)
	{
		T = (Tree)malloc(sizeof(TreeNode));
		if(T == NULL)
		{
			printf("出错");
			exit(1);
		}
		else
		{
			T->Element = e;
			T->left = T->right = NULL;
		}
	}
	else if(e > T->Element)
	{
		T->right = insert(T->right,e); 
	}
	else if(e < T->Element)
	{
		T->left = insert(T->left,e);
	}
	return T;
}
