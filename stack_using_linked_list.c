#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct Node
{
    int data;
    struct Node *next;
} *top=NULL;

void push(int);
void pop();
void display();

int main()
{
    int choice, value;
    printf("\n Stack using linked list ::\n");
    while(1)
    {
        printf("\n *****MENU *****\n");
        printf("1.Push\n 2.pop\n 3.Display\n 4.exit\n");
        printf("enter your choice :");

        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("enter the value to insert :");
            scanf("%d",&value);
            push(value);
            break;
            case 2:
            pop();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            default :
            printf("\n WRONG SELECTION !!!");
        }        }
    
}
void push(int value)
{
    struct Node *newNode;
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=top;
    top=newNode;
    printf("value inserted succesfully\n");
    
}
void pop()
{
    if(top==NULL)
    {
        printf("stack is empty \n");
    }
    else
    {
        struct Node *temp=top;
        printf("\ndeleted element is %d", temp->data);
        top=top->next;
        free(temp);
    }
}
void display()
{
    if(top==NULL)
    printf("\nsTACK IS EMPTY \n");
    else
    {
        struct Node *temp=top;
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}