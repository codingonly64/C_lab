#include <stdio.h>
#include <stdlib.h>

char i;
int y, n;
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
        return;
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

int insertAtBegin()
{
    int val;

}

int menu()
{
    int choice;
    while (1)
    {
        printf("\n\n  Menu  \n1. Display \n2.Insert at begin \n3. Insert at end \n4. Insert in between \n5. Delete at begin \n6. Delete at end \n7. Delete in between \n8. Exit");
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
            return;
        default:
            printf("\nInvalid Choice");
            break;
        }
    }
}

int main()
{
    menu();
}
