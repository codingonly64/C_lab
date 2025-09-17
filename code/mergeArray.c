#include <stdio.h>

void merge(int size1, int size2, int arr1[], int arr2[]){
    int size3 = size1 + size2;
    int i, j, k, arr3[size3];
    i = j = k = 0;
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]){
            arr3[k] = arr1[i];
            k++;
            i++;
        }
        else {
            arr3[k] = arr2[j];
            k++;
            j++;
        }
    }
    printf("\n The merged sorted array is :");
    for (i=0; i<size3;i++)
        printf("\t %d",arr3[i]);
}

int main() {
    int size1, size2, i;
    // Array 1
    printf("\nEnter the size of first array: ");
    scanf("%d", &size1);
    int arr1[size1];
    for (i = 0;i < size1;i++){
        printf("\nEnter the elements at position %d: ",i+1);
        scanf("%d", &arr1[i]);
    }
    
    // Array 2
    printf("\nEnter the size of second array: ");
    scanf("%d", &size2);
    int arr2[size2];
    for (i = 0; i < size2; i++){
        printf("\nEnter the elements at position %d: ", i+1);
        scanf("%d", &arr2[i]);
    }
    
    merge(size1, size2, arr1, arr2);
    return 0;
}

