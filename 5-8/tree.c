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
