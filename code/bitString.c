#include <stdio.h>

int a[] = {0, 0, 0, 0, 0, 0, 0, 0, 0}, b[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

void input()
{
    int size, val, i;
    printf("\nEnter the size of 1st set:");
    scanf("%d", &size);
    for (i = 0; i < size; i++)
    {
        printf("\nEnter the elements of %d: ", i + 1);
        scanf("%d", &val);
        a[val - 1] = 1;
    }

    printf("\nEnter the size of 2st set:");
    scanf("%d", &size);
    for (i = 0; i < size; i++)
    {
        printf("\nEnter the elements of %d: ", i + 1);
        scanf("%d", &val);
        b[val - 1] = 1;
    }

    // print the elements
    printf("\n1st set :");
    for (i = 0; i < 9; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n2nd set :");
    for (i = 0; i < 9; i++)
    {
        printf("%d\t", b[i]);
    }
}

void output(int c[])
{
    int i;
    printf("\n Set is ");
    for (i = 0; i < 9; i++)
    {
        if (c[i] != 0)
            printf("%d\t", i + 1);
    }
}

void setUnion()
{
    int i, c[10];
    for (i = 0; i < 9; i++)
    {
        if (a[i] != b[i])
            c[i] = 1;
        else
            c[i] = a[i];
    }
    for (i = 0; i < 9; i++)
    {
        printf("%d\t", c[i]);
    }
    output(c);
}

void intersection()
{
    int i, c[10];
    for (i = 0; i < 9; i++)
    {
        if (a[i] == b[i])
            c[i] = a[i];
        else
            c[i] = 0;
    }
    for (i = 0; i < 9; i++)
    {
        printf("%d\t", c[i]);
    }
    output(c);
}

void difference()
{
    int i, c[10];
    for (i = 0; i < 9; i++)
    {
        if (a[i] == 1 && b[i] == 0)
            c[i] = 1;
        else
            c[i] = 0;
    }
    for (i = 0; i < 9; i++)
    {
        printf("%d\t", c[i]);
    }
    output(c);
}

int main()
{
    int choice;
    do
    {
        printf("\n\n  MENU  \n1.Input\n2. Union\n3. Intersection\n4. Difference\n5. Exit\n");
        printf("\nEnter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            input();
            break;
        case 2:
            setUnion();
            break;
        case 3:
            intersection();
            break;
        case 4:
            difference();
            break;
        case 5:
            printf("\nThanks for using!!\n");
            return 0;
        default:
            printf("\nInvalid choice!!");
            break;
        }
    } while (1);
}
