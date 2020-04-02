#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int linearSearch(int array[],int length,int key);//Function for linear search

int main(){
    int length; //variable length stores the size of the array
    
    printf("Enter the numner of elements:\n");
    scanf("%d",&length);
    
    int array[length]; // declaration of the array of input size
    
    //Input the elements of array
    for(int i=0;i<length;i++){
        printf("Enter the element # i of the array:\n",i);
        scanf("%d",&array[i]);
    }
    
    int key; //variable to store the key value to find in the array
    printf("\nEnter the Key Value to search for in the array:\n");
    scanf("%d",&key);
    
    int found=linearSearch(array,length,key); //Variable to store return value of function
    
    if(found==-1){
        printf("The element %d was not found in the array.\n",key);
    }
    else{
        printf("The element %d was found in the array at index %d.\n",key,found);
    }
    
    return 0;
}

/*Function for Linear Search. Takes 3 arguments: array to Search, the length 
of the array and another integer representing the key element to look for in the array.

Function returns the index of the key element if found in the array,otherwise returns -1

Worst case time complexity : O(n).
*/
int linearSearch(int array[],int length,int key){
    for(int i=0;i<length;i++){
        if(array[i]==key){
            return i;
        }
    }
    return -1;
}
