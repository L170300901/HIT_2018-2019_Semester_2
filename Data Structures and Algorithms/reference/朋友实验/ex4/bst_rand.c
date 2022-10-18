/* L170300102 XUJUNHE BINARY SEARCH TREE COMPARE PROBLEM2 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
typedef struct TreeNode
{
    int key;
    struct TreeNode *left, *right;
} TreeNode;

void display(TreeNode *p)
{
    if( p != NULL )
    {
        printf("(");
        display(p->left);
        printf("%d", p->key);
        display(p->right);
        printf(")");
    }
}
/* Repeated search func */
TreeNode *search(TreeNode *node, int key)
{
    int count=0;

    while(node!=NULL)
    {
        if(key==node->key)
        {
            /* search success;
                The node pointed to by *node contains the record with the key */
            count++;
            printf("(key==node->key)count: %d\n", count);
            return node;
        }
        else if(key<node->key)      /* search *node point node's left child */
        {
            count++;
            printf("(key<node->key)count: %d\n", count);
            node=node->left;
        }
        else                     /* search right child */
        {
            count++;
            printf("(key>node->key)count: %d\n", count);
            node=node->right;
        }
    }
    //printf("%d",count);
    return NULL;        /* search failed */
}

/* Insert the key into the binary search tree root.
If key is already in root, it is not inserted. */
void insert_node(TreeNode **root, int key)
{
    TreeNode *p,*q;
    TreeNode *n;
    p=*root;
    q=NULL;
    while(p!=NULL)
    {
        if(key==p->key)     /* if already exist, return */
            return;
        q=p;
        if(key<p->key)
            p=p->left;
        else
            p=p->right;
    }
    n= (TreeNode*)malloc(sizeof(TreeNode));
    if(n==NULL)
        return;
    n->key = key;
    n->left=n->right=NULL;
    if(q!=NULL)
        if(key<q->key)
            q->left=n;
        else
            q->right=n;
    else *root =n;
}

/* If the deleted node is a leaf node, it can be deleted directly.
Otherwise This requires proper scheduling of its tree nodes to
maintain its structural properties.*/
void delete_node(TreeNode *node, int key)
{
    TreeNode *p,*child,*succ,*succ_p,*t;
    p=NULL;
    t=node;
    while(t!=NULL&&t->key!=key)
    {
        p=t;
        t=(key<t->key)?t->left:t->right;
    }
    if(t==NULL)
    {
        printf("key is not int the tree");
        return;
    }
    if((t->left==NULL)&&(t->right==NULL))       /* l and r empty all */
    {
        if(p->left==t)
            p->left=NULL;
        else
            p->right=NULL;
    }
    else if((t->left==NULL)||(t->right==NULL))
    {
        child=(t->left!=NULL)?t->left:t->right;
        if(p->left==t)
            p->left=child;
        else
            p->right=child;
    }
    else                    /* two child not empty neither */
    {
        succ = t->right;
        while(succ->left!=NULL)
        {
            succ_p=succ;
            succ=succ->left;
        }
        if(succ_p->left==succ)
            succ_p->left=succ->right;
        else
            succ_p->right=succ->right;
        t->key=succ->key;
        t=succ;

    }
    free(t);
}

void help()
{
    printf("**************\n");
    printf("i: Create(Insert)\n");
    printf("d: Delete\n");
    printf("s: Search\n");
    printf("p: Print\n");
    printf("q: Quit\n");
    printf("**************\n");
}

void main()
{
    char command;
    int key;
    TreeNode *root=NULL;
    TreeNode *tmp;
    int i;


    do
    {
        help();
        command = getchar();
        switch(command)
        {
        case 'i':
            srand(time(NULL));
            for(i = 1; i<2048; i=i+2)
            {
                insert_node(&root, rand()%2048);
            }
            break;
        case 'd':
            printf("Number want to delete :");
            scanf("%d", &key);
            delete_node(root, key);
            break;
        case 'p':
            display(root);
            printf("\n");
            break;
        case 's':
            printf("Number want to search :");
            scanf("%d", &key);
            tmp=search(root, key);
            if( tmp != NULL )
                printf("Search success :%d\n", tmp->key);
            break;
        }
        fflush(stdin);

    }
    while(command != 'q');

}
