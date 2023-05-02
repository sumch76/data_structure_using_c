#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void display() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insert_at_beginning(int value) {
    struct Node *new_node;
    new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = head;
    head = new_node;
    printf("Element inserted at beginning\n");
}

void insert_at_end(int value) {
    struct Node *new_node
    new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    printf("Element inserted at end\n");
}

void delete_from_beginning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    printf("Element deleted from beginning\n");
}

void delete_from_end() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        printf("Element deleted from end\n");
        return;
    }
    struct Node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Element deleted from end\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("1. Display\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at end\n");
        printf("4. Delete from beginning\n");
        printf("5. Delete from end\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display();
                break;
            case 2:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                insert_at_beginning(value);
                break;
            case 3:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                insert_at_end(value);
                break;
            case 4:
                delete_from_beginning();
                break;
            case 5:
                delete_from_end();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
