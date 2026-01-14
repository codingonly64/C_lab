#include <stdio.h>

int i, j, choice, size, arr[50];

void display() {
    printf("\nThe elements in array are: ");
    for (i = 0; i < size; i++)
        printf("\t%d", arr[i]);
}

void search() {
    int num, flag = 0;
    printf("Enter the searching value: ");
    scanf("%d", &num);
    for (i = 0; i < size; i++) {
        if (arr[i] == num) {
            flag = 1;
            printf("%d found at position: %d", num, i + 1); 
            break;
        }
    }
    if (flag == 0)
        printf("%d not found", num);
}

int insert() {
    if (size == 50) {
        printf("\nOverflow!!");
        return 0;
    }
    
    int loc, num;
    printf("Enter the element to insert: ");
    scanf("%d", &num);
    printf("Enter the location to insert the element (1 to %d): ", size + 1);
    scanf("%d", &loc);
    
    if (loc < 1 || loc > size + 1) {
        printf("Invalid location!");
        return 0;
    }
    

    for (i = size; i >= loc; i--) {
        arr[i] = arr[i - 1];
    }
    arr[loc - 1] = num; 
    size++;
    printf("Element inserted!");
    display();
    return 0;
}

int delete() {
    if (size == 0) {
        printf("Underflow!");
        return 0;
    }

    int loc;
    printf("Enter the location to be deleted (1 to %d): ", size);
    scanf("%d", &loc);
    
    if (loc < 1 || loc > size) {
        printf("Invalid location!");
        return 0;
    }


    for (i = loc - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("Element deleted!");
    display();
    return 0;
}

void sort() {
    printf("Current array: ");
    display();
    
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                arr[i] = arr[i] + arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];
            }
        }
    }
    printf("\nSorted array: ");
    display();
}

int menu() {
        printf("\nChoose your option:");
        printf("\n1. Insert \n2. Delete \n3. Sort \n4. Search \n5. Display \n6. Exit ");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                sort();
                break;
            case 4:
                search();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Thank you for using !!\n");
                return 0;
            default:
                printf("\nInvalid choice!");
                break;
        }
    }
}

int main() {
    printf("\nEnter the size of the array (max 50): ");
    scanf("%d", &size);

    if (size < 1 || size > 50) {
        printf("\nInvalid size!");
        return 0;
    }

    for (i = 0; i < size; i++) {
        printf("Enter the element for position %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    menu();
    return 0;
}	
