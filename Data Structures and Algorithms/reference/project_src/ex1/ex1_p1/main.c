#include <stdio.h>
#include <stdlib.h>
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode;
int num1 = 0,num2 = 0;

LNode *open()
{
    LNode *head, *tail, *p;
    head = (LNode*)malloc(sizeof(LNode));
    tail = head;
    char c;
    FILE *fp;
    if((fp = fopen("input.txt", "r")) == NULL)
    {
        printf("cannot open this file\n");
        return 0;
    }

    while((c = fgetc(fp)) != EOF)
    {
        p = (LNode*)malloc(sizeof(LNode));
        fscanf(fp, "%d", &p->data);
        tail->next = p;
        tail = p;
        tail->next = NULL;
    }
    fclose(fp);
    return head;
}

/*
LNode *input(int n)
{
    LNode *head, *tail, *p;
    head = (LNode*)malloc(sizeof(LNode));
    tail = head;
    for(int i=0; i<n; i++)
    {
        p = (LNode*)malloc(sizeof(LNode));
        scanf("%d",&p->data);
        tail->next = p;
        tail = p;
        tail->next = NULL;
    }
    return head;
}
*/

void order(LNode *head)
{
    LNode *p, *q;
    int m;
    p = head->next;
    while(p)
    {
        q = p->next;
        while(q)
        {
            if(q->data < p->data)
            {
                m= q->data;
                q->data = p->data;
                p->data = m;
            }
            q = q->next;
        }
        p = p->next;
    }
}
void output(LNode *head)
{
    LNode *p;
    p = head->next;
    while(p)
    {
        printf("%d",p->data);
        p = p->next;
        if(p)
            printf(" ");
        else
            printf("\n");
    }
}

LNode Getelem(LNode *head, int i, int *e)
{
    int j;
    LNode *p;
    p = head->next;
    j = 1;
    while(p&&j < i)
    {
        p = p->next;
        ++j;
    }
    if(!p || j > i)
        return;
    *e = p->data;

}

void insertItem(LNode *head, int j)
{
    LNode *p = head;
    int i = 0;
    while(p && i < j - 1)
    {
        i++;
        p = p->next;
    }
    if(!p || i > j - 1)
        printf("error!\n");
    else
    {
        LNode *q = (LNode*)malloc(sizeof(LNode));
        printf("enter the data want input: ");
        scanf("%d", &(q->data));
        q->next = p->next;
        p->next = q;
    }
}
LNode *deletenode(LNode *head, int m)
{
    LNode *p, *q, *s;
    p = head;
    q = head->next;
    while(q)
    {
        if(q->data == m)
        {
            p->next = q->next;
            s = q;
            q = q->next;
            free(s);
        }
        else
        {
            p = p->next;
            q = q->next;
        }
    }
    return head;
}

void length(LNode *head)
{
    int num = 0;
    LNode *p;
    p = head->next;
    while(p)
    {
        num++;
        p = p->next;
    }
    printf("length:%d\n", num);
}

void desorder(LNode *head)
{
    LNode *p, *q;
    int m;
    p = head->next;
    while(p)
    {
        q = p->next;
        while(q)
        {
            if(q->data > p->data)
            {
                m= q->data;
                q->data = p->data;
                p->data = m;
            }
            q = q->next;
        }
        p = p->next;
    }
}

int main()
{
    LNode *head;
    int pos = 0;
    int e;
    // int n;
    int a;
    // printf("please enter the length you want\n");
    // scanf("%d",&n);     // n is list length
    head = open();
    order(head);
    output(head);

    printf("scan data position: ");
    scanf("%d", &pos);
    Getelem(head, pos, &e);
    printf("position:%d data:%d\n", pos, e);

    insertItem(head, 4);    // int j is jth. data
    output(head);

    printf("the data you want delete is: ");
    scanf("%d", &a);
    head = deletenode(head, a);
    output(head);

    length(head);

    desorder(head);
    output(head);

    return 0;
}
