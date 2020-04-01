//SINGLY LINKED LIST IMPLEMENTATION IN C LANGUAGE:

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{

    int data;
    struct node * next;

}*head=NULL;

void insertbegin(int x);
void insertmid(int x);
void insertlast(int x);

int deletebegin();
int deletelast( );
int deletemid();

int getsize();
void displaylist();

int main(){
    int pos,x,s=1;
    while(s!=9){
    printf("Select your choice:\n");
    printf("1.Insert at the beginning of the list\n");
    printf("2.Insert at the middle of the list\n");
    printf("3.Insert at the end of the list\n");
    printf("4.Delete at the beginning of the list\n");
    printf("5.Delete at the middle of the list\n");
    printf("6.Delete at the end of the list\n");
    printf("7.Get the length of the list\n");
    printf("8.Display the list\n");
    printf("9.Exit\n");
    scanf("%d",&s);
    switch(s){
        case 1: printf("Enter the number that you want to insert:\n");
                scanf("%d",&x);
                insertbegin(x);
                break;
        case 2:printf("Enter the number that you want to insert:\n");
                scanf("%d",&x);
                insertmid(x);
                break;
        case 3:printf("Enter the number that you want to insert:\n");
                scanf("%d",&x);
                insertlast(x);
                break;
        case 4:deletebegin();
                break;
        case 5:deletemid();
               break;
        case 6:deletelast();
                break;
        case 7:printf("The size of the list is %d\n",getlength());
                break;
        case 8:displaylist();
                break;
        case 9: printf("Thanks!\n");
                break;
        default:printf("Please enter a valid choice\n");
                break;
    }
    }
    return 0;
}

//FUNCTION TO INSERT AN ELEMENT IN THE BEGINNING OF THE LIST
void insertbegin(int x){

    struct node *newnode;
    newnode = (struct node * )malloc(sizeof(struct node));
    newnode->data=x;
    if(head==NULL){
        newnode->next=NULL;
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
}

//FUNCTION TO INSERT AN ELEMENT IN THE MIDDLE OF THE LIST
void insertmid(int x){
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    if(head==NULL){
        printf("The linked list is empty so the element will be added at the beginning\n");
        newnode->next=NULL;
        head=newnode;
    }
    else{
        int pos;
        printf("Enter the position at which you want to insert your number:\n");
        scanf("%d",&pos);
        if (pos==1){
            newnode->next=head;
            head=newnode;
        }
        else{
            struct node *traverser=head;
            int i=0;
            for(i=0;i<pos-2;i++){
                traverser=traverser->next;
            }
            newnode->next=traverser->next;
            traverser->next=newnode;
    }
    }
}

//FUNCTION TO INSERT AN ELEMENT AT THE LAST OF THE LIST
void insertlast(int x){

    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node ));
    newnode->data=x;
    if(head==NULL){
        newnode->next=NULL;
        head=newnode;
    }
    else{
    struct node *traverser=head;
    while(traverser->next!=NULL){
        traverser=traverser->next;
    }
    traverser->next=newnode;
    newnode->next=NULL;
    }
}

//FUNCTION TO DELETE THE FIRST ELEMENT FROM THE LIST
int deletebegin(){

    if(head==NULL){
        printf("The linked list is empty\n");
    }
    else{
        struct node *temp=head;
    head=temp->next;
    printf("The removed element is :%d\n",temp->data);
    free(temp);
    }

}

//FUNCTION TO DELETE THE LAST ELEMENT OF THE LIST
int deletelast(){

    if(head==NULL){
        printf("The linked list is empty\n");
    }
    else if(getlength()==1){
            struct node *temp=head;
            head=temp->next;
            printf("The removed element is :%d\n",temp->data);
            free(temp);
    }
    else{
        struct node *traverser=head;
        struct node *temp;
    while(traverser->next->next!=NULL){
        traverser=traverser->next;

    }
    temp=traverser->next;
    traverser->next=NULL;
    printf("The removed element is :%d\n",temp->data);
    free(temp);
    }
}

//FUNCTION TO DELETE AN ELEMENT FROM THE LIST WHICH IS IN THE MIDDLE
int deletemid(){
    if(head==NULL){
        printf("The linked list is empty\n");
    }
    else{
        int pos;
        printf("Enter the position at which you want the element to be deleted:\n");
        scanf("%d",&pos);
        if(pos==1){
            struct node *temp=head;
            head=temp->next;
            printf("The removed element is :%d\n",temp->data);
            free(temp);
        }
        else{
            struct node *temp=head;
            int i=0;
            for(i=0;i<pos-2;i++){
                temp=temp->next;
            }
            struct node *temp2=temp->next;
            temp->next=temp2->next;
            printf("The removed element is :%d\n",temp2->data);
            free(temp2);
        }
    }
}

//FUNCTION TO GET THE LENGTH OF THE LINKED LIST
int getlength(){
    int size=0;  //VARIABLE TO STORE THE SIZE OF THE LIST
    struct node *traverser=head;
    while(traverser!=NULL){
        traverser=traverser->next;
        size++;
    }
    return size;
}

//FUNCTION TO DISPLAY THE LIST
void displaylist(){
    if(head==NULL){
        printf("The linked list is empty\n");
    }
    else{
    printf("The linked list is : ");
    struct node *traverser=head;
    while(traverser!=NULL){
        printf("%d ",traverser->data);
        traverser=traverser->next;
    }
    printf("\n");
    }
}
