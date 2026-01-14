#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
    printf("Element inserted!!");
}

void insertAtEnd(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Element inserted!!");
}


void insertAtPosition(struct Node **head, int data, int position) {
    if (position <= 0) {
        printf("Invalid position!!");
        return;
    }
    struct Node *newNode = createNode(data);
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node *temp = *head;
    int count = 1;
    while (temp != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Position out of range!!");
        return;
    }
    newNode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
    printf("Element inserted!!");
}

void deleteFromBeginning(struct Node **head) {
    if (*head == NULL) {
        printf("Underflow!!");
        return;
    }
    struct Node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
    printf("Element deleted!!");
}

void deleteFromEnd(struct Node **head) {
    if (*head == NULL) {
        printf("Underflow!!");
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL; 
    }
    free(temp);
    printf("Element deleted!!");
}


void deleteFromPosition(struct Node **head, int position) {

    if (position <= 0) {
        printf("Invalid position!\n");
        return;
    }
    struct Node *temp = *head;
    int count = 1;
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }
    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;  
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("Element deleted!!");
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("Underflow!!");
        return;
    }

    struct Node *temp = head;
    printf("Elements are: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct Node *head = NULL; 

    int choice, data, position;

        printf("\nMenu:\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Delete from Beginning\n5. Delete from End\n6. Delete from Position\n7. Display\n8. Exit");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                deleteFromBeginning(&head);
                break;
            case 5:
                deleteFromEnd(&head);
                break;
            case 6:
                if (head == NULL) 
                    printf("Underflow!!");
                else {                
                    printf("Enter position to delete: ");
                    scanf("%d", &position);
                    deleteFromPosition(&head, position);
                }
                break;
            case 7:
                display(head);
                break;
            case 8:
                printf("Exiting...!!\n");
                return 0;
            default:
                printf("Invalid choice! ");
        }
    }

    return 0;
}
