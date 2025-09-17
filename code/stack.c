#include <stdio.h>
#include <stdlib.h>

int size, choice, item, top = -1, stack[20];

void push() {
    if (top == size-1) {
        printf("\nThe stack is full!!");
        return;
    }
    printf("\nEnter the element to be pushed: ");
    scanf("%d", &item);
    top++;
    stack[top] = item;
    printf("\nInserted successfully");
}

void pop() {
    if (top == -1) {
        printf("\nStack is empty!!");
        return;
    }
    item = stack[top];
    printf("\nDeleted element: %d", item);
    top = top-1;
}

void peek() {
    if (top == -1) {
        printf("\nStack is empty!!");
        return;
    }
    printf("\nThe top most element is: %d", stack[top]);
}

void display() {
    
    if (top == -1) {
        printf("\nStack is empty!!");
        return;
    }
    printf("\nStack elements are: ");
    for (int i = top; i >= 0; i--)
        printf("\t%d", stack[i]);
}

int main() {
    printf("\nEnter the size of the stack: ");
    scanf("%d", &size);
    while (1) {
        printf("\n Menu ");    
        printf("\n1. push \n2. pop \n3. display \n4. peek \n5.exit ");
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
