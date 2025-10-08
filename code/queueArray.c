#include <stdio.h>
#include <stdlib.h>

int queue[50], i, size, choice, item, front = -1, rear = -1;

void enqueue()
{
    if (rear == size - 1)
    {
        printf("\nQueue is full!!");
        return;
    }
    printf("\nEnter the element to be inserted: ");
    scanf("%d", &item);
    front = 0;
    rear++;
    queue[rear] = item;
    printf("Inserted successfully!!");
}

void dequeue()
{
    if (-1 == front || front > rear)
    {
        printf("\nQueue is empty!!");
        return;
    }
    item = queue[front];
    printf("\nDeleted element is %d", item);
    if (front == rear)
        front = rear - 1;
    else
        front++;
}

void display()
{
    if (rear == -1)
    {
        printf("\nQueue is empty!!");
        return;
    }
    printf("\nQueue elements are: ");
    for (i = front; i <= rear; i++)
        printf("\t%d", queue[i]);
    printf("\n");
}

void peek()
{
    if (-1 == front)
    {
        printf("\nQueue is empty!!");
        return;
    }
    printf("\nPeek element is %d", queue[front]);
}

void menu()
{
    while (1)
    {
        printf("\n\n\n  Menu  \n1. Enqueue \n2. Dequeue \n3. Display \n4. Peek \n5. Exit\n");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            printf("\n Thank you for using!!\n");
            return;
        default:
            printf("\nInvalid choice!!");
            break;
        }
    }
}

void main()
{
    printf("\n Enter the size of the queue: ");
    scanf("%d", &size);
    menu();
}