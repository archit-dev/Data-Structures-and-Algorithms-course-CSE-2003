#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <conio.h>

//Function for Selection Sort: (accepts an array and length of array as arguments)
void selectionSort(int* array, int lengthOfArray){
    int i,j,min_index;
    for(i=0;i<lengthOfArray-1;i++){
        min_index=i;
        for(j=i+1;j<lengthOfArray;j++){
            if(array[j]<array[min_index]){
                min_index=j;
            }
        }
        //swapping the minimum element with the element at index i, 
        // if the minimum element is not at index i
        if(min_index!=i){
            int temp=array[i];
            array[i]=array[min_index];
            array[min_index]=temp;
        }
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
    selectionSort(array,lengthOfArray);
    printf("The array after sorting is: ");
    for(i=0;i<lengthOfArray;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}
