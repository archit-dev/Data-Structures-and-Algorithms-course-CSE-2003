//Circular Queue Implementation in C Language

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 10

int queue[N];
int front=-1,rear=-1;

void enqueue(int x);    //Function to enqueue an element into the queue
void dequeue();         //Function to dequeue an element from the queue
int getFront();            //Function to get the element at the front of the queue
int getRear();             //Function to get the element at the back of the queue
void display();         //Function to display the queue

int main(){
    
    int s,x;
    while(1){
        printf("Select your choice:\n");
        printf("1>Enqueue\n");
        printf("2>Dequeue\n");
        printf("3>Get the element at the front of the queue\n");
        printf("4>Get the element at the rear of the queue\n");
        printf("5>Display the queue\n");
        printf("6>Exit\n");
        scanf("%d",&s);
        switch(s){
            case 1:printf("Enter the element that you want to enqueue\n");
                    scanf("%d",&x);
                    enqueue(x);
                    break;
            case 2:dequeue();
                    break;
            case 3:x=getFront();
                    printf("The element at the front of the queue is %d\n",x);
                    break;
            case 4: x=getRear();
                    printf("The element at the rear of the queue is %d\n",x);
                    break;
            case 5:display();
                    break;
            case 6:exit(1);
        }
        
    }
    return 0;
}

//Function to enqueue an element into the queue
void enqueue(int x){
    //condition if there is no element in queue
    if(front==-1&&rear==-1){
        front=0;
        rear=0;
        queue[rear]=x;
    }
    
    //condition if the queue is full
    else if((rear+1)%N==front){
        printf("The queue is full\n");
    }
    
    else{
        rear=(rear+1)%N;
        queue[rear]=x;
    }
}

//Function to dequeue an element from the queue
void dequeue(){
    //condition if the queue is empty 
    if(front==-1&&rear==-1){
        printf("The queue is empty\n");
    }
    
    //condition if there is only one element in the queue
    else if(front==rear){
        printf("The dequeued element is %d\n",queue[front]);
        front=-1;
        rear=-1;
    }
    
    else{
        printf("The dequeued element is %d\n",queue[front]);
        front=(front+1)%N;
    }
    
}

//Function to get the element at the front of the queue
int getFront(){
    return queue[front];
}

//Function to get the element at the back of the queue
int getRear(){
    return queue[rear];
}

//Function to display the queue
void display(){
    if(front==-1&&rear==-1){
        printf("The queue is empty\n");
    }
    else{
        int i=front;
    printf("The elements of the queue are: ");
    while(i!=rear){
        printf("%d ",queue[i]);
        i=(i+1)%N;
    }
    printf("%d \n",queue[i]);
    printf("\n");
    }
}
