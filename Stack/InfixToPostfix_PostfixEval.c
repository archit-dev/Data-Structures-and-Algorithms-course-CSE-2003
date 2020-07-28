//C program for infix to postfix and postfix evaluation
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
int priority(char a);//Function to set the priority of the operands
void print(char* s, int n);//Function to print a character array upto the required limit

//Main function
int main(){
    char postfix[MAX],infix[MAX];
    printf("Please enter the infix expression:\n");
    scanf("%s",infix);
    int lengthOfInfix = strlen(infix);
    int i=0,ptrPostfix=0;
    for(i = 0 ; i < lengthOfInfix ; i++){
        if(isdigit(infix[i])!=0){
            postfix[ptrPostfix++] = infix[i];
        }
        else{
            if(infix[i]=='('){
                push(infix[i]);
            }
            else if(infix[i] == ')'){
                while(getTop()!='(' && top >=0){
                    postfix[ptrPostfix++] = getTop();
                    pop();
                }
                pop();
            }
            else{
                if(getSize()==0){
                    push(infix[i]);
                }
                else{
                    if(priority(infix[i]) <= priority(getTop()) && getTop()!='('){
                        while(priority(infix[i]) <= priority(getTop()) && top>=0){
                            if(getTop()=='('){
                                break;
                            }
                            else{
                                postfix[ptrPostfix++] = getTop();
                                pop();
                            }
                        }
                        push(infix[i]);
                    }
                    else{
                        push(infix[i]);
                    }
                }
            }
        }
    }
    while(top!=-1){
        postfix[ptrPostfix++]=getTop();
        pop();
    }
    printf("The postfix expression is : ");
    print(postfix,ptrPostfix);
    int lengthOfPostfix = ptrPostfix; //stores the length of the string
    // int i=0;
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

//Function to print a character array upto the required limit
void print(char* s, int n){
    int i=0;
    for(i=0;i<n;i++){
        printf("%c",s[i]);
    }
    printf("\n");
}

//Function to set the priority of the operands
int priority(char a){
	if (a=='+'||a=='-')
		return 1;
	else if (a=='*'||a=='/')
		return 2;
	else if (a=='^')
		return 3;
	else return 4;
}
