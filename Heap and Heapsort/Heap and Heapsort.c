//Implementation of Heap and HeapSort in C Language

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void swap(int*a, int*b);
void heapify(int* heap,int size,int node);
void buildHeap(int* heap,int size);
void printHeap(int* heap,int size);
void heapSort(int* heap,int size);

int main(){
    printf("Please enter the number of elements that you want to add in the heap:\n");
    int size,i;
    scanf("%d",&size);
    int* heap=(int*)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++){
        printf("Enter the element %d in the heap:\n",i+1);
        scanf("%d",&heap[i]);
    }
    buildHeap(heap,size);
    printf("The elements in the heap are: ");
    printHeap(heap,size);
    heapSort(heap,size);
    printf("The elements after applying HeapSort are as follows: ");
    printHeap(heap,size);
    free(heap);
    return 0;
}

//Function swaps the values of 2 integers it takes as arguments
void swap(int*a, int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

//Function to make sure that the parent element has a value greater than the value of its children
void heapify(int* heap,int size,int node){
    int largest=node,leftChild=2*node+1,rightChild=2*node+2;
    if(leftChild<size && heap[leftChild]>heap[largest]){
        largest=leftChild;
    }
    if(rightChild<size && heap[rightChild]>heap[largest]){
        largest=rightChild;
    }
    if(largest!=node){
        swap(&heap[largest],&heap[node]);
        heapify(heap,size,largest);
    }
}

//Starts from the last non leaf node and calls heapify function for every parent node
void buildHeap(int* heap,int size){
    int startIndex=size/2-1,i;
    for(i=startIndex;i>=0;i--){
        heapify(heap,size,i);
    }
}

//Function to sort the array
void heapSort(int* heap,int size){
    int i;
    for(i=size-1;i>=0;i--){
        swap(&heap[i],&heap[0]);
        heapify(heap,i,0);
    }
}

void printHeap(int* heap,int size){
    int i=0;
    for(i=0;i<size;i++){
        printf("%d ",heap[i]);
    }
    printf("\n");
}
