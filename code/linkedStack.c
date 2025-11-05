#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
} *start;

void push()
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nUnderflow!!");
    }

    int val;
    printf("\nEnter the value: ");
    scanf("%d", &val);
    ptr->val = val;
    ptr->next = start;
    start = ptr;
    printf("\nItem pushed!!");
}

void pop()
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("\nUnderflow!!");
        return;
    }

    ptr = start;
    int item;
    item = start->val;
    start = start->next;
    free(ptr);
    printf("\nItem removed!!");
}

void display()
{
    struct node *ptr;
    ptr = start;

    if (ptr == NULL)
    {
        printf("\nUnderflow!!");
        return;
    }

    printf("\nStack elements are:");
    while (ptr != NULL)
    {
        printf("\t%d", ptr->val);
        ptr = ptr->next;
    }
    printf("\n");
}

void main()
{
    int choice;
    while (1)
    {
        printf("\n  Menu  \n\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("\nEnter the choice:");
        scanf("%d", &choice);
        switch (choice)
        {
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
            printf("\nThanks for using!!\n");
            return;
        default:
            printf("\nInvalid choice!!");
            break;
        }
    }
}