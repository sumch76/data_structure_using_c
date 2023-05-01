#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void push(int stack[], int *top);
int pop(int stack[], int *top);
void display(int stack[], int *top);

int main() {
    int stack[MAX_SIZE];
    int top = -1;
    int choice;
    
    do {
        printf("\nMENU\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                push(stack, &top);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                display(stack, &top);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (1);
    
    return 0;
}

void push(int stack[], int *top) {
    int data;
    
    if (*top == MAX_SIZE - 1) {
        printf("Stack overflow. Cannot push more elements.\n");
        return;
    }
    
    printf("Enter data to be pushed: ");
    scanf("%d", &data);
    
    (*top)++;
    stack[*top] = data;
    
    printf("Pushed %d onto the stack.\n", data);
}

int pop(int stack[], int *top) {
    int data;
    
    if (*top == -1) {
        printf("Stack underflow. Cannot pop more elements.\n");
        return -1;
    }
    
    data = stack[*top];
    (*top)--;
    
    printf("Popped %d from the stack.\n", data);
    
    return data;
}

void display(int stack[], int *top) {
    int i;
    
    if (*top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    
    printf("Stack elements:\n");
    for (i = *top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}
