#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>



typedef struct Node
{
    int Key;
    struct Node *LNode;
    struct Node *RNode;

}Node;

typedef struct Tree
{
    Node *Root;
}Tree;

int Front =0;
int Rear = 0;
struct Node *Queue[100];

void init(Tree *T)
{
    T ->Root = NULL;
}

bool Exist(Tree *T,int Data)
{
    Node *Current = T -> Root;
    while(1)
    {
        if(Current ->Key == Data)
        {

            return 1;
        }
        if(Current ->Key<Data)
            {
            if(Current ->RNode ==NULL)
            {
                return 0;
            }
            Current= Current->RNode;
            }
        if(Current ->Key>Data)
        {
            if(Current ->LNode ==NULL)
            {
                return 0;
            }
            Current =Current->LNode;
        }
    }
}

void Add(Tree *T,int Data)
{
    Node *New =(Node*)malloc(sizeof(Node));

    if(T->Root==NULL)
    {
        T ->Root=New;
        New ->LNode = NULL;
        New ->RNode = NULL;
        New ->Key = Data;
        return;
    }
    if(Exist(T,Data))
    {

        return;
    }
        New ->LNode = NULL;
        New ->RNode = NULL;
        New ->Key = Data;
        Node *Current = T ->Root;
        while(1)
        {
            if(Current ->Key<Data)
            {
                if(Current->RNode ==NULL)
                {
                    Current ->RNode =New;
                    return;
                }
                Current=Current ->RNode;
            }
            else{
                if(Current ->LNode ==NULL)
                {
                    Current ->LNode = New;
                    return;
                }
                Current =Current ->LNode;
            }
        }

}

int Delete(Tree *T,int Data)
{
    Node *Current = T ->Root;
    Node *TempCurrent = NULL;
    Node *Parent = NULL;
    Node *Child = NULL;
    Node *Temp = NULL;
    int Key =0;
    if(!Exist(T,Data)){
        return 0;

    }
    while(Current ->Key !=Data)
    {
        if(Data > Current ->Key)
        {
            Parent = Current;
            Current =  Current->RNode;
        }
        else{
            Parent=Current;
            Current = Current ->LNode;
        }
    }
    if(Current ->LNode ==NULL && Current->RNode ==NULL)
    {
        Key =Current->Key;
        if(Parent->LNode ==Current){
            Parent->LNode=NULL;
        }
        if(Parent->RNode ==Current)
        {
            Parent->RNode=NULL;

        }
        free(Current);
        return Key;
    }
    if(Current->LNode ==NULL||Current ->RNode ==NULL)
    {

        Key =Current -> Key;
        if(Current-> LNode !=NULL)
            Child = Current ->LNode;
        else
            Child = Current -> RNode;
        if(Parent ->LNode ==Current)
            Parent->LNode =Child;
        else
            Parent->RNode =Child;

        Key = Current ->Key;
        free(Current);
        return Key;
    }
    if(Current->LNode !=NULL && Current ->RNode !=NULL)
    {
        TempCurrent =Current;
        TempCurrent =  TempCurrent->RNode;

        if(TempCurrent-> LNode ==NULL)
            {
                Temp = Current ->LNode;
                Child = TempCurrent;
                if(Parent->RNode ==Current)
                {
                    Parent->RNode=Child;
                    Child ->LNode=Temp;
                }
                else{
                    Parent ->LNode =Child;
                    Child ->LNode = Temp;
                }
                Key=Current->Key;
                free(Current);
                return Key;
            }
            while(TempCurrent ->LNode !=NULL)
            {
                Parent=TempCurrent;
                TempCurrent=TempCurrent->LNode;
            }
            Parent ->LNode =NULL;
            Current ->Key=TempCurrent->Key;
            free(TempCurrent);



    }
    return 0;


}

void AddQueue(Node *N)
{
    Queue[Front++] =N;
}

Node* DeleteQueue()
{
    return Queue[Rear++];
}

void LevelOrder(Node *N)
{

    Node *Temp = N;
    if(!Temp){
        return;
    }
    AddQueue(Temp);
    while(1)
    {
        Temp = DeleteQueue();
        if(Temp)
        {
            printf("%d ",Temp->Key);
            if(Temp ->LNode){
                AddQueue(Temp ->LNode);
            }
            if(Temp ->RNode){
                AddQueue(Temp ->RNode);
            }

        }
        else break;

    }
}
int main()
{
    Tree MyTree;
    init(&MyTree);
    Add(&MyTree,5);
    Add(&MyTree,7);
    Add(&MyTree,10);
    Add(&MyTree,9);
    Add(&MyTree,8);
    Add(&MyTree,3);

    LevelOrder(MyTree.Root);
}
