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
        printf("\nOverflow!!");
        return NULL;
    }
    return nptr;
}

void display()
{
    node1 *ptr = start;
    if (ptr == NULL)
    {
        printf("\nUnderflow!!");
        return;
    }
    printf("\nElements are ");
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
        printf("\nOverflow!!");
        return;
    }
    printf("\nEnter the element to be inserted: ");
    scanf("%d", &val);
    nptr->data = val;
    nptr->link = start;
    start = nptr;
    printf("\nElement inserted!!");
}

void insertAtEnd()
{
    node1 *nptr = create(), *temp;
    if (nptr == NULL)
    {
        printf("\nOverflow!!");
        return;
    }
    int val;
    printf("\nEnter the element to be inserted: ");
    scanf("%d", &val);
    nptr->data = val;
    nptr->link = NULL;
    temp = start;
    while (temp->link != NULL)
        temp = temp->link;
    temp->link = nptr;
    printf("\nElement inserted!!");
}

void insertAtBtw()
{
    node1 *temp, *nptr = create();
    int val, pos, i;
    if (nptr == NULL)
    {
        printf("\nOverflow!!");
        return;
    }
    printf("\nEnter the element: ");
    scanf("%d", &val);
    printf("\nEnter the position to inserted: ");
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
            printf("\nOverflow!!");
            free(nptr);
            return;
        }
        nptr->link = temp->link;
        temp->link = nptr;
    }
    printf("\nElement inserted!!");
}

void deleteAtBegin()
{
    node1 *temp;
    if (start == NULL)
    {
        printf("\nUnderflow!!");
        return;
    }
    temp = start;
    start = start->link;
    free(temp);
    printf("\nElement deleted!!");
}

void deleteAtEnd()
{
    node1 *temp, *prev;
    if (start == NULL)
    {
        printf("\nUnderflow!!");
        return;
    }
    temp = start;
    if (temp->link == NULL) // Only one element in the list
    {
        start = NULL;
        free(temp);
        printf("\nElement deleted!!");
        return;
    }

    while (temp->link != NULL)
    {
        prev = temp;
        temp = temp->link;
    }
    prev->link = NULL;
    free(temp);
    printf("\nElement deleted!!");
}

void deleteAtBtw()
{
    node1 *temp, *prev;
    int pos, i;
    printf("\nEnter the position to delete: ");
    scanf("%d", &pos);
    if (start == NULL)
    {
        printf("\nUnderflow!!");
        return;
    }
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
    printf("\nElement deleted\n");
}

int menu()
{
    int choice;
    while (1)
    {
        printf("\n\n  Menu  \n1. Display \n2. Insert at begin \n3. Insert at end \n4. Insert in between \n5. Delete at begin \n6. Delete at end \n7. Delete in between \n8. Exit\n");
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
            printf("\nThank you for using!!\n");
            return 0;
        default:
            printf("\nInvalid Choice!!");
            break;
        }
    }
}

void main()
{
    menu();
}
