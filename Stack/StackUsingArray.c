//Array Implementation of Stack in C Language
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define N 5 //Macro to set the size of the stack

int top=-1; //Global variable to denote the top of the stack
int stack[N];//Array functioning as a stack created globally

void push();
int pop();
int peek();
int isFull();
int isEmpty();
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

/*Function to push an element to the top of the stack, displays a message
in case of overflow*/
void push(){
    if (isFull()==1){
        printf("Stack overflows\n");
    }
    else{
        int x;
        printf("Enter the number that you want to insert:\n");
        scanf("%d",&x);
        stack[++top]=x;
    }
}

/*Function to pop an element from the top of the stack,
displays a message and returns -1 in case of underflow*/
int pop(){
    if (isEmpty()==1){
        printf("Stack underflows\n");
        return -1;
    }
    else{
        printf("The popped out element is : %d\n",stack[top--]);
        return stack[top];
    }

}

/*Function to return the element at the top of the stack ,
displays a message in case of no element in stack*/
int peek(){
    if(isEmpty()==1){
        printf("No element present in the stack\n");
    }
    else{
        printf("The element at the top of the stack is : %d\n",stack[top]);
        return stack[top];
    }
}

//Function returns 1 if stack is full, 0 otherwise
int isFull(){
    if( top==N-1){
        return 1;
    }
    else return 0;
}

//Function returns 1 if stack is empty, 0 otherwise
int isEmpty(){
    if(top==-1){
        return 1;
    }
    else return 0;
}

//Function returns the current size of the stack
int getSize(){
    printf("The size of the stack is : %d\n",top+1);
}

//Function to print the elements of the stack
void display(){
    if(top==-1){
        printf("Stack is empty\n");
    }
    else{
        int i=0;
        printf("The elements of the stack are: ");
        for(i=0;i<=top;i++){
            printf("%d ",stack[i]);
        }
        printf("\n");
    }
}
