#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int top=-1; //Global integer variable denoting the top of the stack
char stack1[400]; //Stack to store the operands

void push(char a); //Function to push elements onto the stack
char pop(); //Function to pop elements from the stack
int priority(char a); //Function to set the priority of the operands
char getTop(); //Function to get the topmost element of the stack
void print(char arr[]); //Function to print any array passed as the parameter of this function


int main(){
    int k=0;
	char infix[400]; //Character array to store the infix expression
	printf("Enter the Infix Expression:\n");
	scanf("%s",infix);
	char postfix[400]; //Character array to store the postfix expression
	for(int i=0;infix[i]!='\0';i++){
		if(isalnum(infix[i])==0){
			if(top==-1){
			    	push(infix[i]);
			}
			else{
			    if(infix[i]=='('){
			        push(infix[i]);
			    }
			    else if(infix[i]==')'){
			        while(stack1[top]!='('){
			            postfix[k++]=pop();
			        }
			        top--;
			    }
			    else{
					if(priority(infix[i])>priority(getTop())){
						push(infix[i]);
					}
					else if(priority(infix[i])<=priority(getTop())){
						while(top!=-1){
						postfix[k++]=pop();
						}
						push(infix[i]);
					}
			    }
		}
		}
		else{
		postfix[k++]=infix[i];
	}
	}
	while(top!=-1){
	    if( stack1[top]=='('||stack1[top]==')'){
	        pop();
	    }else{
	    postfix[k++]=pop();
	    }
	}
	printf("The postfix expression is : ");
	print(postfix);
	return 0;
}

//Function to set the priority of the operands
int priority(char a){
	if (a=='+'||a=='-')
		return 1;
	else if (a=='*'||a=='/')
		return 2;
	else if (a=='^')
		return 3;
	else return -1;
}

//Function to push elements onto the stack
void push(char a){
	stack1[++top]=a;
}

//Function to pop elements from the stack
char pop(){
    if(top==-1)
        return '8';
	return stack1[top--];
}

//Function to get the topmost element of the stack
char getTop(){
	return stack1[top];
}

//Function to print any array passed as the parameter of this function
void print(char arr[] ){
	for(int i=0;arr[i]!='\0';i++){
		printf("%c",arr[i]);
	}
	printf("\n");
}
