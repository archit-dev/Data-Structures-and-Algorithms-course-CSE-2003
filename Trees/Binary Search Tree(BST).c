//Implementation of Binary Search Tree(BST) in C Language

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
struct Node* insert(struct Node* root, int element);
int search(struct Node* root,int element);
struct Node* delete(struct Node* root, int element);
struct Node* findMin(struct Node* root);

//Driver function
int main(){
    struct Node* root=NULL;//Root node of the BST
    
    root= insert(root,10);//Insert 10 in BST
    root= insert(root,1);//Insert 1 in BST
    root= insert(root,5);//Insert 5 in BST
    root= insert(root,21);//Insert 21 in BST
    root= insert(root,42);//Insert 42 in BST
    
    //Check if 21 is in the BST
    if(search(root,21)){
        printf("The element is found in the BST\n");
    }
    else{
        printf("The element is not found in the BST\n");
    }
   
    root=delete(root,21);//Deletes 21 from the BST
    
    //Check if 21 is in the BST
    if(search(root,21)){
        printf("The element is found in the BST\n");
    }
    else{
        printf("The element is not found in the BST\n");
    }
    
    //Check if 100 is in the BST
    if(search(root,100)){
        printf("The element is found in the BST\n");
    }
    else{
        printf("The element is not found in the BST\n");
    }
    
    return 0;
}

//Function to create a new node in BST
struct Node* getNewNode(int element){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=element;
    newnode->leftChild=NULL;
    newnode->rightChild=NULL;
    return newnode;
}

//Function to insert an element in the BST
struct Node* insert(struct Node* root, int element){
    if(root==NULL){
        root=getNewNode(element);
    }
    else if(element <= root->data){
        root->leftChild=insert(root->leftChild,element);
    }
    else{
        root->rightChild=insert(root->rightChild,element);
    }
    return root;
}

//Function to find the node with the minimum data in BST
struct Node* findMin(struct Node* root){
    if(root==NULL){
        return root;
    }
    struct Node* current=root;
    while(current->leftChild!=NULL){
        current=current->leftChild;
    }
    return current;
}

//Function to delete an element from BST
struct Node* delete(struct Node* root, int element){
    if (root==NULL){
        return root;
    }
    else if(element<root->data){
        delete(root->leftChild,element);
    }
    else  if(element>root->data){
        delete(root->rightChild,element);
    }
    else{
        if(root->leftChild==NULL && root->rightChild==NULL){
            free(root);
            root=NULL;
        }
        else if(root->leftChild!=NULL){
            struct Node* temp=root;
            root=root->rightChild;
            free(temp);
        }
        else if(root->rightChild!=NULL){
            struct Node* temp=root;
            root=root->leftChild;
            free(temp);
        }
        else{
            struct Node* temp=findMin(root->rightChild);
            root->data=temp->data;
            delete(root->rightChild,temp->data);
        }
    }
    return root;
}

//Function to search for an element in the BST
int search(struct Node* root,int element){
    if(root==NULL){
        return 0;
    }
    else if(root->data==element){
        return 1;
    }
    else if(element<root->data){
        search(root->leftChild,element);
    }
    else{
        search(root->rightChild,element);
    }
}

