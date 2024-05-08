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

