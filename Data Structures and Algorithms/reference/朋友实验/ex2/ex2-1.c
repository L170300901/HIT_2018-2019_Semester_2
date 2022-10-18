/* L170300102 XUJUNHE BINARY TREE PROBLEM1*/
#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;

typedef struct BiTreeNode
{
    ElementType data;
    struct BiTreeNode *lchild;
    struct BiTreeNode *rchild;
} BiTreeNode, *BiTree;

void CreatePreBiTree(BiTree *T)
{
    int data;
    scanf("%d", &data);

    if (data == 0)
    {
        *T = NULL;
        return;
    }
    else
    {
        *T = (BiTree)malloc(sizeof(BiTreeNode));
        if (T == NULL)
        {
            printf("error with allocation\n");
            return ;
        }
        else
        {
            (*T)->data = data;
            printf("Enter the %d's left node ",data);
            CreatePreBiTree(&((*T)->lchild));
            printf("Enter the %d's right node ",data);
            CreatePreBiTree((&(*T)->rchild));
        }
    }
}

void PreOrderBiTree(BiTree T)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        printf("data = %d\t", T->data);
        PreOrderBiTree(T->lchild);
        PreOrderBiTree(T->rchild);
    }
}

int main(int argc, const char * argv[])
{
    BiTree T = (BiTree)malloc(sizeof(BiTreeNode));
    CreatePreBiTree(&T);
    PreOrderBiTree(T);

    return 0;
}

