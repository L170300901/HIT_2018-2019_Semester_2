/* L170300102 XUJUNHE JUDGE COMPLEATE BINARYTREE PROBLEM3 */
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define MAXSIZE 500
#define ERROR -1
typedef int ElemType;
typedef int Status;

typedef struct BiNode{
    ElemType data;
    struct BiNode *lchild;
    struct BiNode *rchild;
} BiNode, *BiTree;

typedef struct queue{
    ElemType qdata[MAXSIZE];
    int front;
    int rear;
} queue;

void CreBT(BiTree *T)
{
    int Bidata;
    scanf("%d", &Bidata);
    if(Bidata == 0)
    {
        *T = NULL;
        return;
    }
    else
    {
        *T = (BiTree)malloc(sizeof(BiNode));
        if(T == NULL)
        {
            printf("error with allocation\n");
            return;
        }
        else
        {
            (*T)->data = Bidata;
            printf("Enter the %d's left node ", Bidata);
            CreBT(&((*T)->lchild));
            printf("Enter the %d's right node ", Bidata);
            CreBT(&((*T)->rchild));
        }
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

Status InitQueue(queue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

Status EnQueue(queue *Q, ElemType e)
{
    if((Q->rear + 1) % MAXSIZE == Q->front)
        return ERROR;
    Q->qdata[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    return OK;
}

Status DeQueue(queue *Q, ElemType *e)
{
    if(Q->rear == Q->front)
        return ERROR;
    *e = Q->qdata[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return OK;
}

Status isCT(BiTree T)
{
    if(T == NULL)
        return TRUE;
    queue Q;
    InitQueue(&Q);
    BiTree p = T;
    int cm = 1;
    int bj = 1;

    if(!p->lchild && p->rchild)
        return FALSE;
    EnQueue(&Q, p);
    while(DeQueue(&Q, &p) == OK && cm)
    {
        if(p->lchild && p->rchild)
        {
            if(bj == 0)
                cm = 0;
            EnQueue(&Q, p->lchild);
            EnQueue(&Q, p->rchild);
        }
        if(p->lchild && !p->rchild)
        {
            if(bj == 0)
                cm = 0;
            EnQueue(&Q, p->lchild);
            bj = 0;
        }
        if(!p->lchild && p->rchild)
        {
            cm = 0;
        }
        if(!p->lchild && !p->rchild)
        {
            bj = 0;
        }
    }
    return cm;
}


int main()
{
    BiTree T = (BiTree)malloc(sizeof(BiNode));
    CreBT(&T);
    levelOrderTra(T);
    printf("\n");
    if(isCT(T) == TRUE)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
