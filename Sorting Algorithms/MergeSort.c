#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <conio.h>

//Function to merge 2 subarrays(left & right) into another array 
void merge(int* array,int* left , int* right,int lengthOfLeft,int lengthOfRight){
    int i=0,j=0,k=0;
    while(i<lengthOfLeft && j<lengthOfRight){
        if(left[i]<=right[j]){
            array[k]=left[i];
            k+=1;
            i+=1;
        }
        else{
            array[k]=right[j];
            k+=1;
            j+=1;
        }
    }
    while(i<lengthOfLeft){
        array[k]=left[i];
        k+=1;
        i+=1;
    }
    while(j<lengthOfRight){
        array[k]=right[j];
        k+=1;
        j+=1;
    }
}

//MergeSort Function:
void mergeSort(int* array,int lengthOfArray){
    if(lengthOfArray<2){
        return;
    }
    else{
        int i,mid=lengthOfArray/2;
        int left[mid],right[lengthOfArray-mid];
        for(i=0;i<mid;i++){
            left[i]=array[i];
        }
        for(i=mid;i<lengthOfArray;i++){
            right[i-mid]=array[i];
        }
        mergeSort(left,mid);
        mergeSort(right,lengthOfArray-mid);
        merge(array,left,right,mid,lengthOfArray-mid);
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
    mergeSort(array,lengthOfArray);
    printf("The array after sorting is: ");
    for(i=0;i<lengthOfArray;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    return 0;
}
