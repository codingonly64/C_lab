#include <stdio.h>
#include <stdlib.h>
int queue[50], size, front = -1, rear = -1, choice, item;

void enqueue()
{
    if (front == rear + 1 || (front == 0 && rear == size - 1))
    {
        printf("\nQueue is full!!");
        return;
    }
    if (-1 == front)
        front = 0;
    rear = (rear + 1) % size;
    printf("\nEnter the element to be inserted: ");
    scanf("%d", &item);
    queue[rear] = item;
    printf("\nElement Inserted!!");
}

void dequeue()
{
    if (front == -1)
    {
        printf("\nQueue is empty!!");
        return;
    }
    item = queue[front];
    if (front == rear)
        front = rear - 1;
    else
        front = (front + 1) % size;
    printf("\nDeleted element is %d", item);
}

void display()
{
    int i;
    if (front == -1)
    {
        printf("\nQueue is empty!!");
        return;
    }
    printf("\nQueue elements are: ");
    for (i = front; i != rear; i = (i + 1) % size)
        printf("\t%d", queue[i]);
    printf("\t%d", queue[i]);
    printf("\n");
}

void menu()
{
    while (1)
    {
        printf("\n\n  Menu  \n\n1.Enqueue \n2. Dequeue \n3. Display \n4.Exit \n");
        printf("\nEnter the choice: ");
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
            printf("\nThank you for using!!\n");
            return;
        default:
            printf("\nInvalid choice!!");
            break;
        }
    }
}

void main()
{
    printf("\nEnter the size of the queue: ");
    scanf("%d", &size);
    menu();
}