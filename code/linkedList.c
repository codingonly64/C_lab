#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
typedef struct node node1;
node1 *start = NULL;

struct node *create()
{
    node1 *nptr = ((node1 *)malloc(sizeof(node1)));
    if (nptr == NULL)
    {
        printf("Overflow!!");
        return NULL;
    }
    return nptr;
}

void display()
{
    node1 *ptr = start;
    if (ptr == NULL)
    {
        printf("Underflow!!");
        return;
    }
    printf("Elements are ");
    while (ptr != NULL)
    {
        printf("\t%d", ptr->data);
        ptr = ptr->link;
    }
}

void insertAtBegin()
{
    int val;
    node1 *nptr = create();
    if (nptr == NULL)
    {
        printf("Overflow!!");
        return;
    }
    printf("Enter the element to be inserted: ");
    scanf("%d", &val);
    nptr->data = val;
    nptr->link = start;
    start = nptr;
    printf("Element inserted!!");
}

void insertAtEnd()
{
    node1 *nptr = create(), *temp;
    if (nptr == NULL)
    {
        printf("Overflow!!");
        return;
    }
    int val;
    printf("Enter the element to be inserted: ");
    scanf("%d", &val);
    nptr->data = val;
    nptr->link = NULL;
    temp = start;
    while (temp->link != NULL)
        temp = temp->link;
    temp->link = nptr;
    printf("Element inserted!!");
}

void insertAtBtw()
{
    node1 *temp, *nptr = create();
    int val, pos, i;
    if (nptr == NULL)
    {
        printf("Overflow!!");
        return;
    }
    printf("Enter the element: ");
    scanf("%d", &val);
    printf("Enter the position to inserted: ");
    scanf("%d", &pos);
    nptr->data = val;
    nptr->link = NULL;

    if (1 == pos)
    {
        nptr->link = start;
        start = nptr;
    }
    else
    {
        temp = start;
        for (i = 1; i < pos && temp != NULL; i++)
        {
            temp = temp->link;
        }
        if (temp == NULL)
        {
            printf("Overflow!!");
            free(nptr);
            return;
        }
        nptr->link = temp->link;
        temp->link = nptr;
    }
    printf("Element inserted!!");
}

void deleteAtBegin()
{
    node1 *temp;
    if (start == NULL)
    {
        printf("Underflow!!");
        return;
    }
    temp = start;
    start = start->link;
    free(temp);
    printf("Element deleted!!");
}

void deleteAtEnd()
{
    node1 *temp, *prev;
    if (start == NULL)
    {
        printf("Underflow!!");
        return;
    }
    temp = start;
    if (temp->link == NULL) 
    {
        start = NULL;
        free(temp);
        printf("Element deleted!!");
        return;
    }

    while (temp->link != NULL)
    {
        prev = temp;
        temp = temp->link;
    }
    prev->link = NULL;
    free(temp);
    printf("Element deleted!!");
}

void deleteAtBtw()
{
    node1 *temp, *prev;
        if (start == NULL)
    {
        printf("Underflow!!");
        return;
    }
    int pos, i;
    printf("Enter the position to delete: ");
    scanf("%d", &pos);

    temp = start;
    if (pos == 1)
    {
        start = temp->link;
    }
    else
    {
        for (i = 1; i < pos; i++)
        {
            prev = temp;
            temp = temp->link;
            prev->link = temp->link;
        }
    }
    free(temp);
    printf("Element deleted");
}

int menu()
{
    int choice;
        printf("\n  Menu  \n1. Display \n2. Insert at begin \n3. Insert at end \n4. Insert in between \n5. Delete at begin \n6. Delete at end \n7. Delete in between \n8. Exit");
    while (1)
    {
        printf("\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display();
            break;
        case 2:
            insertAtBegin();
            break;
        case 3:
            insertAtEnd();
            break;
        case 4:
            insertAtBtw();
            break;
        case 5:
            deleteAtBegin();
            break;
        case 6:
            deleteAtEnd();
            break;
        case 7:
            deleteAtBtw();
            break;
        case 8:
            printf("Thank you for using!!\n");
            return 0;
        default:
            printf("Invalid Choice!!");
            break;
        }
    }
}

void main()
{
    menu();
}
