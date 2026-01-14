#include <stdio.h> 
#include <stdlib.h> 
 
struct btnode { 
    int value; 
    struct btnode *l; 
    struct btnode *r; 
} *root = NULL, *temp = NULL, *t1 = NULL, *tl = NULL; 
 
 void create() { 
    int data; 
    printf("Enter data of node to be inserted: "); 
    scanf("%d", &data); 
    temp = (struct btnode *)malloc(sizeof(struct btnode)); 
    temp->value = data; 
    temp->l = temp->r = NULL; 
} 
 
 void search(struct btnode *t) { 
    if (temp->value < t->value) { 
        if (t->l == NULL) 
            t->l = temp; 
        else 
            search(t->l); 
    } else if (temp->value > t->value) { 
        if (t->r == NULL) 
            t->r = temp; 
        else 
            search(t->r); 
    } else { 
        printf("Duplicate value not allowed!"); 
    } 
}
 
void insert() { 
    create(); 
    printf("Element inserted!!");
    if (root == NULL) 
        root = temp; 
    else 
        search(root); 
}  
 
void inorder(struct btnode *t) { 
    if (t == NULL) 
        return; 
    inorder(t->l); 
    printf("%d -> ", t->value); 
    inorder(t->r); 
} 

int smallest(struct btnode *t) { 
    if (t->l == NULL) 
        return t->value; 
    else 
        return smallest(t->l); 
}
 
 void search1(struct btnode *t, int data) { 
    if (t == NULL) 
        return; 
 
    if (data < t->value) { 
        tl = t; 
        search1(t->l, data); 
    } else if (data > t->value) { 
        tl = t; 
        search1(t->r, data); 
    } else { 
        t1 = t; // Node found 
    } 
} 

void deletel(struct btnode *t) { 
    int k; 
 
    // Case 1: No child 
    if (t->l == NULL && t->r == NULL) { 
        if (t == root) 
            root = NULL; 
        else if (tl->l == t) 
            tl->l = NULL; 
        else 
            tl->r = NULL; 
        free(t); 
        printf("Element deleted!!");
        return; 
    } 
 
    // Case 2: Only left child 
    if (t->r == NULL) { 
        if (t == root) 
            root = t->l; 
        else if (tl->l == t) 
            tl->l = t->l; 
        else 
            tl->r = t->l; 
        free(t);
        printf("Element deleted!!");
        return; 
    } 
    // Case 3: Only right child 
    if (t->l == NULL) { 
        if (t == root) 
            root = t->r; 
        else if (tl->r == t) 
            tl->r = t->r; 
        else 
            tl->l = t->r; 
        free(t); 
        printf("Element deleted!!");
        return; 
    } 
 
    // Case 4: Two children 
    k = smallest(t->r); 
    t->value = k; 
    t1 = t; 
    search1(t->r, k); 
    deletel(t1); 
} 
 
void delete1() { 
    int data; 
    if (root == NULL) { 
        printf("Underflow!!"); 
        return; 
    } 
 
    printf("Enter the data to be deleted: "); 
    scanf("%d", &data); 
    t1 = NULL; 
    tl = NULL; 
 
    search1(root, data); 
    if (t1 == NULL) 
        printf("Underflow!!"); 
    else 
        deletel(t1); 
} 
 

int main() { 
    int ch; 
    printf("\n Menu \n1. Insertion \n2. Deletion \n3. Inorder Traversal \n4. Exit"); 
 
    while (1) { 
        printf("\nEnter your choice: "); 
        scanf("%d", &ch); 
        switch (ch) { 
        case 1: 
            insert(); 
            break; 
        case 2: 
            delete1(); 
            break; 
        case 3: 
            if (root == NULL) 
                printf("Underflow!!"); 
            else {
                printf("Elements are: ");
                inorder(root); 
            }                 
            break; 
        case 4:
            printf("Thanks for using!!\n");
            exit(0); 
        default: 
            printf("Invalid choice!!"); 
        } 
    } 
    return 0; 
} 
 

