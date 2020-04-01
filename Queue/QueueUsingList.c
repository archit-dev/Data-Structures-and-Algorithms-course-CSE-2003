//Linked List Implementation of Queue in C Language

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
    int data;
    struct node *next;
}*front=NULL,*rear=NULL;

void enqueue();
void dequeue();
void getFront();
void getRear();
int getSize();
void display();

int main(){
    int choice=1;
    while(choice !=7){
        printf("Select your choice:\n");
        printf("1.Enqueue \n");
        printf("2.Dequeue\n");
        printf("3.Get the element at the front of the queue\n");
        printf("4.Get the element at the rear of the queue\n");
        printf("5.Get the size of the queue\n");
        printf("6.Display the elements in the stack\n");
        printf("7.Exit\n");
        scanf("%d",&choice);
        switch(choice){
        case 1: enqueue();
                break;
        case 2:dequeue();
                break;
        case 3:getFront();
                break;
        case 4:getRear();
                break;
        case 5:getSize();
                break;
        case 6:display();
                break;
        case 7: printf("Thanks!\n");
                break;
        default:printf("Please enter a valid choice\n");
                break;
    }
    }
    return 0;
}

//Function to insert data into the queue
void enqueue(){
    int x;
    printf("Enter the number that you want to enqueue :\n");
    scanf("%d",&x);
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node ));
    newnode->data=x;
    newnode->next=NULL;
    if(front==NULL){
        front=newnode;
        rear=newnode;
    }
    else{
        rear->next=newnode;
        rear=newnode;
    }
}

//Function to remove an element from the queue
void dequeue(){
    if(front==NULL){
        printf("The queue is empty\n");
    }
    else{
         struct node *temp=front;
         if(front==rear){
            printf("The dequeued element is : %d\n",temp->data);
            front=rear=NULL;
            free(temp);
         }
         else{
            front=temp->next;
            printf("The dequeued element is : %d\n",temp->data);
            free(temp);
         }
    }
}

//Function to display the element at the front of the queue
void getFront(){
    if(front==NULL){
        printf("The queue is empty\n");
    }
    else{
        printf("The element at the front of the queue is %d\n",front->data);
    }
}

//Function to display the element at the end of the queue
void getRear(){
    if(front==NULL){
        printf("The queue is empty\n");
    }
    else{
        printf("The element at the back of the queue is %d\n",rear->data);
    }
}

//Function that displays the size of the queue and also returns the same
int getSize(){
    int size=0;
    struct node *temp=front;
    while(temp!=NULL){
        size++;
        temp=temp->next;
        }
    printf("The size of the queue is : %d\n",size);
    return size;
}

//Function to display the contents of the queue
void display(){
    if(front==NULL){
        printf("The queue is empty\n");
    }
    else{
        struct node *temp=front;
        printf("The elements of the queue are: ");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
