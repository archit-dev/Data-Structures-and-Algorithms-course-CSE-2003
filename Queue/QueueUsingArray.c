//Array Implementation of Queue in C Language

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 5 //Macro to set the size of the stack

int front=-1,rear=-1; //Global variables denoting the front and the rear of the queue
int queue[N];

void enqueue();
void dequeue();
void getFront();
void getRear();
int isEmpty();
int isFull();
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
    if(isFull()==1){
        printf("The queue is full\n");
    }

    else {
        int x;
        printf("Enter the number that you want to enqueue :\n");
        scanf("%d",&x);
        if(front==-1&&rear==-1){
            queue[++rear]=x;
            front=0;
        }
        else{
            queue[++rear]=x;
        }
    }
}

//Function to remove an element from the queue
void dequeue(){
    if(isEmpty()==1){
        printf("The queue is empty\n");
    }
    else if(front == rear){
            printf("The dequeued element is : %d\n",queue[front]);
            front=rear=-1;
         }
         else{
            printf("The dequeued element is : %d\n",queue[front++]);
         }
    }


//Function to display the element at the front of the queue
void getFront(){
    if(isEmpty()==1){
        printf("The queue is empty\n");
    }
    else{
        printf("The element at the front of the queue is %d\n",queue[front]);
    }
}

//Function to display the element at the end of the queue
void getRear(){
    if(isEmpty()==1){
        printf("The queue is empty\n");
    }
    else{
        printf("The element at the back of the queue is %d\n",queue[rear]);
    }
}

//Function returns 1 if the queue is empty, 0 otherwise
int isEmpty(){
    if(front==-1 && rear==-1){
        return 1;
    }
    else return 0;
}

//Function returns 1 if the queue is full, 0 otherwise
int isFull(){
    if(rear==N-1){
        return 1;
    }
    else return 0;
}

//Function that displays the size of the queue and also returns the same
int getSize(){
        int size=0,i;
        if(front==-1){
            printf("The size of the queue is : %d\n",size);
            return size;
        }
        else{
            for(i=front;i<=rear;i++){
                size++;
            }
            printf("The size of the queue is : %d\n",size);
            return size;
        }
}

//Function to display the contents of the queue
void display(){
    if(isEmpty()==1){
        printf("The queue is empty\n");
    }
    else{
        int i=0;
        printf("The elements of the queue are : ");
        for(i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
