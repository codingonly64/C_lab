#include <stdio.h>
int i, j, choice, size, arr[50];

void display()
{
    printf("\nThe elements in array are: ");
    for (i = 0; i < size; i++)
        printf("\t%d", arr[i]);
    printf("\n");
}

void search()
{
    int num, flag = 0;
    printf("\nEnter the searching value: ");
    scanf("%d", &num);
    for (i = 0; i < size; i++)
    {
        if (arr[i] == num)
        {
            flag = 1;
            printf("\n%d found at position: %d", num, i);
        }
    }
    if (0 == flag)
        printf("\n%d not found", num);
}

int insert()
{
    int arr_size = sizeof(arr);
    if (arr_size == size || size == 0)
    {
        printf("\nThere is no space in the array");
        return 0;
    }
    int loc, num;
    printf("\nEnter the element to insert: ");
    scanf("%d", &num);
    printf("\nEnter the location to insert the element: ");
    scanf("%d", &loc);
    if (loc > size)
    {
        printf("\nlocation out of reach!!");
        return 0;
    }
    for (i = size; i > loc - 1; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[loc - 1] = num;
    size++;
    printf("\nElement inserted !!");
    printf("\nThe new array is ");
    for (i = 0; i < size; i++)
        printf("\t%d", arr[i]);
    printf("\n");
    return 0;
}

int delete()
{
    int loc;
    printf("\nEnter the location to be deleted: ");
    scanf("%d", &loc);
    if (loc < 0 || loc > size)
    {
        printf("\nInvalid location !!");
        return 0;
    }
    for (i = loc; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
    printf("\nElement Deleted");
    return 0;
}

void sort()
{
    printf("\nCurrent array: ");
    for (i = 0; i < size; i++)
        printf("\t%d", arr[i]);
    printf("\n");
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                arr[i] = arr[i] + arr[j];
                arr[j] = arr[i] - arr[j];
                arr[i] = arr[i] - arr[j];
            }
        }
    }
    printf("\nSorted array: ");
    for (i = 0; i < size; i++)
        printf("\t%d", arr[i]);
    printf("\n");
}

int menu()
{
    while (1)
    {
        printf("\n\nChoose your options");
        printf("\n1. Insert \n2. Delete \n3. Sort \n4. Search \n5. Display \n6. Exit ");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
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
            printf("\nThank you for using !!\n");
            return 0;
        default:
            printf("\nInvalid choice !!");
            break;
        }
    }
}

void main()
{
    printf("\nEnter the size of the array: ");
    scanf("%d", &size);
    for (i = 0; i < size; i++)
    {
        printf("Enter the elements of the position %d : ", i);
        scanf("%d", &arr[i]);
    }
    menu();
}
