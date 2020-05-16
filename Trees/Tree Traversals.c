//Implementation of Tree Traversals in C Language

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <string.h>

struct Node{
    int data;
    struct Node* leftChild;
    struct Node* rightChild;
};

struct Node* getNewNode(int element);
void preorder(struct Node* root);
void inorder(struct Node* root);
void postorder(struct Node* root);

//Driver function
int main(){
    struct Node* root=NULL;//Root node of the BST
    
    root=getNewNode(1);
    root->leftChild=getNewNode(2);
    root->rightChild=getNewNode(3);
    root->leftChild->leftChild=getNewNode(4);
    root->leftChild->rightChild=getNewNode(5);
    root->leftChild->rightChild->leftChild=getNewNode(6);
    root->rightChild->leftChild=getNewNode(7);
    root->rightChild->rightChild=getNewNode(8);
    root->rightChild->rightChild->leftChild=getNewNode(12);
    printf("The Preorder traversal of the tree is: ");
    preorder(root);
    printf("\n"); 
    printf("The Inorder traversal of the tree is: ");
    inorder(root);
    printf("\n");
     printf("The Postorder traversal of the tree is: ");
    postorder(root);
    printf("\n");
}

//Function to create a new node in BST
struct Node* getNewNode(int element){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=element;
    newnode->leftChild=NULL;
    newnode->rightChild=NULL;
    return newnode;
}

//Function for preorder traversal of tree
void preorder(struct Node* root){
    if(root==NULL){
        return;
    }
    printf("%d ",root->data);
    preorder(root->leftChild);
    preorder(root->rightChild);
}

//Function for inorder traversal of tree
void inorder(struct Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->leftChild);
    printf("%d ",root->data);
    inorder(root->rightChild);
}

//Function for postorder traversal of tree
void postorder(struct Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->leftChild);
    postorder(root->rightChild);
    printf("%d ",root->data);
}
