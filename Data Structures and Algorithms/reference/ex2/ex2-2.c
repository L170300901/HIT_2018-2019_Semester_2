/* L170300102 XUJUNHE 3CASES TRAVERSAL PROBLEM2 */
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
typedef int ElementType;
typedef int Status;


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

void PreorderTraversal(BiTree T)    // Use recursive (XIANXU)
{
    if(T!=NULL)
    {
        printf("%d\t", T->data);
        PreorderTraversal(T->lchild);
        PreorderTraversal(T->rchild);
    }
}

void PostorderTraversal(BiTree T)   // Use recursive (HOUXU)
{
    if(T!=NULL)
    {
        PostorderTraversal(T->lchild);
        PostorderTraversal(T->rchild);
        printf("%d\t", T->data);
    }
}

void InorderTraversal(BiTree T)     // Use recursive (ZHONGXU)
{
    if(T!=NULL)
    {
        InorderTraversal(T->lchild);
        printf("%d\t", T->data);
        InorderTraversal(T->rchild);
    }
}

void levelOrderTra(BiTree T)
{
	if(!T)
		return;

	BiTree queue[50];
	int rear = 0, front = 0;

	queue[rear++] = T;

	while(front != rear)
	{
		BiTree dt = queue[front++];

		printf("%d\t",dt->data);

		if(dt->lchild != NULL)
			queue[rear++] = dt->lchild;

		if(dt->rchild != NULL)
			queue[rear++] = dt->rchild;

	}
}

void PreorderNR(BiTree T)   // Not Use recursive (XIANXU)
{
    BiTree Seqstack[MAXSIZE];
    int top = -1;
    BiTree p;

    if(T != NULL)
    {
        top++;
        Seqstack[top] = T;
        while(top > -1)
        {
            p = Seqstack[top];
            top --;
            printf("%d\t", p->data);
            if(p->rchild != NULL)
            {
                top ++;
                Seqstack[top] = p->rchild;
            }
            if(p->lchild != NULL)
            {
                top ++;
                Seqstack[top] = p->lchild;
            }
        }
    }
}

void InorderNR(BiTree T)
{
    int i=0;
    BiTree p,a[100];
    p=T;
    while (i!=0 || p!=NULL)
    {
        while (p!=NULL)
        {
            i++;
            a[i]=p;
            p=p->lchild;
        }
        if (i!=0)
        {
            p=a[i];
            i--;
            printf("%d\t",p->data);
            p=p->rchild;
        }
    }
}

void PostorderNR(BiTree T)
{
    BiTree p,a[100];
    int i=0,b[100];
    p=T;
    a[0]=NULL;
    while (i!=0 || p!=NULL)
    {
        while (p!=NULL)
        {
            if (b[i]==2)
                break;
            i++;
            a[i]=p;
            b[i]=0;
            p=p->lchild;
        }
        if (i!=0)
        {
            if (p==NULL)
            {
                b[i]++;
                p=a[i];
            }
            if (b[i]==2)
            {
                printf("%d\t",p->data);
                b[i]=0;
                i--;
                p=a[i];
                b[i]++;
            }
            if (i==0)
            {
                p=NULL;
                break;
            }
            if (b[i]==1)
                p=p->rchild;
        }
    }
}

int main(int argc, const char * argv[])
{
    BiTree T = (BiTree)malloc(sizeof(BiTreeNode));
    CreatePreBiTree(&T);

    PreorderTraversal(T);
    printf("\n");
    InorderTraversal(T);
    printf("\n");
    PostorderTraversal(T);
    printf("\n");
    levelOrderTra(T);
    printf("\n");

    PreorderNR(T);
    printf("\n");
    InorderNR(T);
    printf("\n");
    PostorderNR(T);
    printf("\n");

    return 0;
}
