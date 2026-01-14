#include <stdio.h>
#include <stdlib.h>

int size, choice, item, top = -1, stack[20];

void push() {
    if (top == size-1) {
        printf("Overflow!!");
        return;
    }
    printf("Enter the element to be pushed: ");
    scanf("%d", &item);
    stack[++top] = item;
    printf("Inserted successfully");
}

void pop() {
    if (top == -1) {
        printf("Underflow!!");
        return;
    }
    item = stack[top];
    printf("Deleted element: %d", item);
    top = top-1;
}

void peek() {
    if (top == -1) {
        printf("Underflow!!");
        return;
    }
    printf("The top most element is: %d", stack[top]);
}

void display() {
    
    if (top == -1) {
        printf("Underflow!!");
        return;
    }
    printf("Stack elements are: ");
    for (int i = top; i >= 0; i--)
        printf("\t%d", stack[i]);
}

int main() {
    printf("\nEnter the size of the stack: ");
    scanf("%d", &size);
        printf("\n Menu\n1. push \n2. pop \n3. display \n4. peek \n5. exit");
    while (1) {
        printf("\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                printf("\nThanks for using!!\n");
                return 0;
            default:
                printf("\nInvaid choice!!");
        }
    } 
}
