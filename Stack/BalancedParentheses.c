//Code for Balanced Parenthesis using Stack in C language

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 400

int top=-1; //Global integer variable denoting the top of the stack
char stack1[MAX]; //Stack to store the operands

void push (char a); //Function to push an element onto the stack
char pop(); //Function to pop an element from the stack
char getTop(); //Function that returns the element at the top of the stack
void print(char arr[]); //Function that prints any character array that is passed as an argument
int balancedParen(char a); /*Function returns 1 if the parentheses at the top of the stack and 
the one passed as argument match and -1 otherwise*/

int main(){
    int flag=1; //variable is 1 initially and becomes 0 in case of parentheses mismatch
    char expression[MAX]; //Character array to store the expression
    printf("Enter the expression to check the balanced parentheses of:\n");
    scanf("%s",expression);
    for(int i=0;expression[i]!='\0';i++){
        if(expression[i]=='('||expression[i]=='{'||expression[i]=='['){
            push(expression[i]);
        }
        if(expression[i]==')'||expression[i]=='}'||expression[i]==']'){
            if (balancedParen(expression[i])==-1){
                flag=0;
                break;
            }
            else{
                pop();
            }
        }
        
    }
    if(top!=-1){
        flag=0;
    }
    if(flag==0){
        printf("Mismatch: Parentheses do not match.\n");
    }
    else if(flag==1){
        printf("Matching Parentheses!\n");
    }
    return 0;
}

//Function to push an element onto the stack
void push (char a){
    if (top==MAX-1){
        return;
    }
    else{
        stack[++top]=a;
    }
}

//Function to pop an element from the stack
char pop(){
    if (top==-1){
        return '0';
    }
    else {
        return stack[top--];
    }
}

//Function that returns the element at the top of the stack
char getTop(){
    return stack[top];
}

//Function that prints any character array that is passed as an argument
void print(char arr[]){
    for(int i=0;arr[i]!='\0';i++){
        printf("%c",arr[i]);
    }
    printf("\n");
}

/*Function returns 1 if the parentheses at the top of the stack and 
the one passed as argument match and -1 otherwise*/
int balancedParen(char a){
    if(a==')'&&getTop()=='('){
        return 1;
    }
    else if(a=='}'&&getTop()=='{'){
        return 1;
    }
    else if(a==']'&&getTop()=='['){
        return 1;
    }
    else return -1;
}
