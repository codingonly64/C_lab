#include <stdio.h>
struct disjointSet
{
    int parent[10];
    int rank[10];
    int num;
} dis;

void makeSet()
{
    for (int i = 0; i < dis.num; i++)
    {
        dis.parent[i] = i;
        dis.rank[i] = 0;
    }
}

void display()
{
    int i;
    printf("Parent Array: ");
    for (i = 0; i < dis.num; i++)
        printf("\t%d", dis.parent[i]);
    printf("\nRank Array: ");
    for (i = 0; i < dis.num; i++)
        printf("\t%d", dis.rank[i]);
}

int find(int val)
{
    if (dis.parent[val] != val)
        dis.parent[val] = find(dis.parent[val]);
    return dis.parent[val];
}

void unionSet(int val1, int val2)
{
    int xset = find(val1), yset = find(val2);
    if (xset == yset)
        return;

    if (dis.rank[xset] < dis.rank[yset])
    {
        dis.parent[xset] = yset;
        dis.rank[xset] = -1;
    }
    else
    {
        dis.parent[yset] = xset;
        dis.rank[xset]++;
        dis.rank[yset] = -1;
    }
}

int main()
{
    int n, x, y;
    printf("\nHow many elements:");
    scanf("%d", &dis.num);
    makeSet();
    char wish;
    int ch;
    printf("\nMENU\n1. Union\n2. Find\n3. Display\n");
    do
    {
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter elements to perform union:");
            scanf("%d %d", &x, &y);
            unionSet(x, y);
            break;
        case 2:
            printf("Enter elements to check if connected components:");
            scanf("%d %d", &x, &y);
            if (find(x) == find(y))
                printf("Connected components");
            else
                printf("Not connected components");
            break;
        case 3:
            display();
            break;
        }
        printf("\nPress y to continue / Press any button to exit: ");
        scanf(" %c", &wish);
    } while (wish == 'y' || wish == 'Y');
    return 0;
}
