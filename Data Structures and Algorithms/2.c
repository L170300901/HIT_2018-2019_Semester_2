
#include <stdio.h>
#include <stdlib.h>



int number = 50;

typedef struct node *treePointer;
typedef struct node {
      int data;
      treePointer leftChild, rightChild;
} node;

void preorder(treePointer ptr){
    if(ptr){

         printf("%d ",ptr->data);
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}

void inorder(treePointer ptr){
    if(ptr){

        inorder(ptr->leftChild);
         printf("%d ",ptr->data);
        inorder(ptr->rightChild);
    }
}

void postorder(treePointer ptr){
    if(ptr){

        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        printf("%d ",ptr->data);
    }
}

int main(void)
{
    int k;
    node nodes[number +1];

    for(int i =1 ;i<=number; i++){

        nodes[i].data = i;
        nodes[i].leftChild = NULL;
        nodes[i].rightChild = NULL;

    }
    for(int i = 1; i<= number; i++){
        if(i % 2 ==0){
        nodes[i/2].leftChild = &nodes[i];
        }

    else{
        nodes[i/2].rightChild = &nodes[i];
    }

    }
    for(int n=1;n<4;n++){

    printf("1.preorder tree\n2.postorder tree\n3.inorder tree\n");
    scanf("%d",&k);

    if(k==1){
      preorder(&nodes[1]);
    }
    if(k==2){
      postorder(&nodes[1]);
    }
    if(k==3){
        inorder(&nodes[1]);
    }
    printf("\n");
    }

    return 0;
}
