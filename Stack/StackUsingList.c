//Linked List Implementation of Stack in C Language
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
    int data;
    struct node *next;
}*head=NULL;

void push();
int pop();
void peek();
int getSize();
void display();

int main(){
    int choice=1;
    while(choice !=6){
        printf("Select your choice:\n");
        printf("1.Push \n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Get the size of the stack\n");
        printf("5.Display the elements in the stack\n");
        printf("6.Exit\n");
        scanf("%d",&choice);
        switch(choice){
        case 1: push();
                break;
        case 2:pop();
                break;
        case 3:peek();
                break;
        case 4:getSize();
                break;
        case 5:display();
                break;
        case 6: printf("Thanks!\n");
                break;
        default:printf("Please enter a valid choice\n");
                break;
    }
    }
    return 0;
}

//Function that inserts an element into the stack
void push(){
    int x;
    printf("Enter the number that you want to push :\n");
    scanf("%d",&x);
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node ));
    newnode->data=x;
    if (head==NULL){
        newnode->next=NULL;
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }

}

//Function that removes the topmost element of the sack
int pop(){
    if(head==NULL){
        printf("The Stack is empty\n");
    }
    else{
        struct node *temp=head;
        head=temp->next;
        printf("The element popped out is :%d\n",temp->data);
        free(temp);
    }
}

//Function that displays the topmost element of the stack
void peek(){
    if (head==NULL){
        printf("The Stack is empty\n");
    }
    else{
        printf("The element at the top of the stack is : %d\n",head->data);
    }
}

//Function that displays the size of the stack and returns the same
int getSize(){
    int size=0;
    struct node *temp=head;
    while(temp!=NULL){
        size++;
        temp=temp->next;
    }

    printf("The size of the stack is : %d\n",size);
    return size;
}

//Function to print the elements of the stack
void display(){
    if(head==NULL){
        printf("The stack is empty\n");
    }
    else{
        printf("The elements of the stack are : ");
        struct node *temp=head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
