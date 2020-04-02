#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void bubbleSort(int arr[],int n,int ch);//Function to sort the array

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
    
    int choice; //variable to store choice of user
    
    //Choice to sort the array in ascending or descending order
    printf("\nSelect your choice:\n");
    printf("1.Sort the array elements in ascending order\n");
    printf("2.Sort the array elements in descending order\n");
    scanf("%d",&choice);
    
    //Prints the unsorted array
    printf("\nThe unsorted array was: ");
    for(int i=0;i<length;i++){
        printf("%d ",array[i]);
    }
    
    bubbleSort(array,length,choice); //Function call to sort the array
    
    //Print the sorted array
    printf("\nThe sorted array is: " );
    for(int i =0;i<length;i++){
        printf("%d ",array[i]);
    }
    printf("\n");
    
    return 0;
}

/*Function for bubble sort. Takes 3 arguments: array to be sorted, the length 
of the array and another integer representing the choice to sort the array
in ascending order(if ch==1) or descending order(if ch==2).

Average case time complexity : O(n^2).

This function can be optimised to have a time complexity O(n) if the array is sorted.
*/
void bubbleSort(int arr[],int n,int ch){
    if(ch==2){
        for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j+1]>arr[j]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    }
    else {
        for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }
    }
}
