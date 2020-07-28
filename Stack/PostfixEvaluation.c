//C program for the evaluation of postfix expressions
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX 100

char stack[MAX];//Global declaration of the stack
int top = -1;

void push(char x);//Function to push the element onto the stack
void pop();//Function to pop the element from the stack
char getTop();//Function to get the top element of the stack
int getSize();//Function to get the size of the stack(number of elements)
int charToIntConverter(char x);//Function to convert character into integer
char intToCharConverter(int x);//Function to convert integer into character

//Main function
int main(){
    char postfix[MAX],infix[MAX];
    printf("Please enter the postfix expression:\n");
    scanf("%s",postfix); //input for the string
    int lengthOfPostfix = strlen(postfix); //stores the length of the string
    int i=0;
    for(i = 0 ; i < lengthOfPostfix ; i++){
        if(isdigit(postfix[i])!=0){
            push(postfix[i]);
        }
        else{
            int b = charToIntConverter(getTop());
            pop();
            int a = charToIntConverter(getTop());
            pop();
            int result;
            if(postfix[i]=='+'){
                result = a+b;
            }
            else if(postfix[i]=='-'){
                result = a - b;
            }
            else if(postfix[i]=='/'){
                result = a / b;
            }
            else if(postfix[i]=='*'){
                result = a * b;
            }
            else{
                result = pow(a,b);
            }
            char toBePushed = intToCharConverter(result);
            push(toBePushed);
        }
    }
    //prints the final value obtained from the postfix expression
    printf("The evaluation of the postfix expression is : %d\n",charToIntConverter(getTop()));
    return 0;
}

//Function to push the element onto the stack
void push(char x){
    stack[++top]=x;
}

//Function to pop the element from the stack
void pop(){
    top--;
}

//Function to get the top element of the stack
char getTop(){
    return stack[top];
}

//Function to get the size of the stack(number of elements)
int getSize(){
    return top+1;
}

//Function to convert character into integer
int charToIntConverter(char x){
    return x-'0';
}

//Function to convert integer into character
char intToCharConverter(int x){
    return x+'0';
}
