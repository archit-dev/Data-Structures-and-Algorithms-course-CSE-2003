#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <conio.h>

//Function to partition the array,
//returns the index of the pivot in the array
int partition(int* array,int start,int end){
    int pivot=array[end];
    int partitionIndex=start;
    for(int i=start;i<end;i++){
        if(array[i]<pivot){
            int temp=array[i];
            array[i]=array[partitionIndex];
            array[partitionIndex]=temp;
            partitionIndex+=1;
        }
    }
    int temp=array[end];
    array[end]=array[partitionIndex];
    array[partitionIndex]=temp;
    return partitionIndex;
}

//Function for Quicksort
void quickSort(int* array,int start, int end){
    if(start<end){
        int partitionIndex=partition(array,start,end);
        quickSort(array,start,partitionIndex-1);
        quickSort(array,partitionIndex+1,end);
    }
}

int main(){
    int lengthOfArray,i;
    printf("Enter the length of the array :\n");
    scanf("%d",&lengthOfArray);
    int array[lengthOfArray];
    for(i=0;i<lengthOfArray;i++){
        printf("Enter the element %d of the array: ",i+1);
        scanf("%d",&array[i]);
    }
    printf("\n");
    printf("The array before sorting is: ");
    for(i=0;i<lengthOfArray;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    quickSort(array,0,lengthOfArray-1);
    printf("The array after sorting is: ");
    for(i=0;i<lengthOfArray;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}
