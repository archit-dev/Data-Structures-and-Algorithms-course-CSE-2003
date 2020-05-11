#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <conio.h>

//Function for Insertion Sort: (accepts an array and length of array as arguments)
void insertionSort(int* array, int lengthOfArray){
    int i,j,value,hole;
    for(i=1;i<lengthOfArray;i++){
        value=array[i];
        hole=i;
        while(hole>0 && array[hole-1]>value){
            array[hole]=array[hole-1];
            hole-=1;
        }
        array[hole]=value;
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
    insertionSort(array,lengthOfArray);
    printf("The array after sorting is: ");
    for(i=0;i<lengthOfArray;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}
