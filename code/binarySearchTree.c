#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *l;
    struct node *r;
} *root = NULL, *temp = NULL;

// Function to create a new node
void create()
{
    int val;
    printf("\nEnter the value to insert: ");
    scanf("%d", &val);
    temp = (struct node *)malloc(1 * sizeof(struct node));
    temp->value = val;
    temp->l = temp->r = NULL;
}

// Function to search for the correct position for a new node
void search(struct node *t)
{
    if (t == NULL)
    {
        return; // Null node, should not happen here if you call this correctly
    }

    if (temp->value > t->value)
    {
        if (t->r != NULL)
            search(t->r);
        else
            t->r = temp; // Insert here
    }
    else if (temp->value < t->value)
    {
        if (t->l != NULL)
            search(t->l);
        else
            t->l = temp; // Insert here
    }
}

// Function to find the smallest node (for deletion)
int smallest(struct node *t)
{
    while (t && t->l != NULL)
    {
        t = t->l;
    }
    return (t ? t->value : -1);
}

// Function to insert a new node
void insert()
{
    create();
    if (root == NULL)
    {
        root = temp; // If tree is empty, the new node becomes the root
    }
    else
    {
        search(root);
    }
}

// Function to remove a node from the tree
void remove_node(struct node *parent, struct node *t, int deleting_node) {
    if (t == NULL)
        return;

    // Case 1: Leaf node (no children)
    if (t->l == NULL && t->r == NULL) {
        if (parent != NULL) {
            if (deleting_node)
                parent->l = NULL;
            else
                parent->r = NULL;
        } else {
            root = NULL;  // If root is being removed, update root
        }
        free(t);
        return;
    }

    // Case 2: Node with one child
    else if (t->l == NULL || t->r == NULL) {
        struct node *child = (t->l != NULL) ? t->l : t->r;
        if (parent != NULL) {
            if (deleting_node)
                parent->l = child;
            else
                parent->r = child;
        } else {
            root = child;  // If root is being removed, update root
        }
        free(t);
        return;
    }

    // Case 3: Node with two children
    else {
        int val = smallest(t->r);  // Find the smallest value in the right subtree
        t->value = val;            // Replace the current node's value with the smallest value
        remove_node(t, t->r, 0);      // Remove the in-order successor (smallest value)
    }
}

// Function to search for a node with a given value and its parent
void element_search(struct node *t, int val, struct node **parent, int *deleting_node) {
    if (t == NULL) {
        *parent = NULL;
        return;
    }

    if (val > t->value) {
        *parent = t;
        *deleting_node = 0;
        element_search(t->r, val, parent, deleting_node);
    } else if (val < t->value) {
        *parent = t;
        *deleting_node = 1;
        element_search(t->l, val, parent, deleting_node);
    } else if (val == t->value) {
        *parent = t;  // Found the node
    } else {
        *parent = NULL;
    }
}

// Function to delete a node from the tree
void delete() {
    if (root == NULL) {
        printf("\nUnderflow!!");
        return;
    }

    int val;
    printf("\nEnter the value to delete: ");
    scanf("%d", &val);

    struct node *parent = NULL;
    int deleting_node = 0;
    element_search(root, val, &parent, &deleting_node);

    if (parent == NULL) {
        printf("\nNode not found!");
        return;
    }

    // If parent is the root node (delete the root)
    if (parent == root && root->value == val) {
        remove_node(NULL, root, 0);  // Remove the root node
    } else {
        remove_node(parent, parent->l, deleting_node);  // Otherwise, delete the node by reference
    }
}

// In-order Traversal
void display(struct node *t)
{
    if (t == NULL)
        return;

    display(t->l);               // Traverse left subtree
    printf("\t%d ->", t->value); // Visit node
    display(t->r);               // Traverse right subtree
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n  Menu  \n\n1. Insertion \n2. Deletion \n3. Inorder Traversal \n4. Exit\n");
        printf("\nEnter the choice: ");
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
            display(root);
            break;
        case 4:
            printf("\nThank you for using!!\n");
            return 0;
        default:
            printf("\nInvalid choice!!");
        }
    }
}

