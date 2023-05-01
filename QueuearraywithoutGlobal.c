#include<stdio.h>
#include<stdlib.h>
#define MAX 5
void enqueue(int queue[],int *front ,int *rear);
void dequeue(int queue[],int *front,int *rear);
void display(int queue[],int *front,int *rear);
int main()
{
    int n,ch;
    int front=-1;
    int rear=-1;
    int queue[MAX];
    while(1)
    {
        printf("QUEUE OPERATION USING ARRAY :\n");
        printf("-----------------------");
        printf("\n\t1.INSERTION\n\t2.DELETION\n\t3.DISPLAY\n\t4.EXIT");
        printf("\nenter the choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                enqueue(queue, &front, &rear);
                break;
            case 2:
                dequeue(queue, &front, &rear);
                break;
            case 3:
                display(queue, &front, &rear);
                break;
            case 4:
                printf("\nEXIT POINT\n");
                exit(0);
            default :
                printf("enter a valid option\n");
        }
    }
}

void enqueue(int queue[],int *front,int *rear)
{
    if(*rear==MAX-1)
{
    printf("queue is overflow\n");
    return;
}
else
{
    if(*front==-1)
    {
        *front=0;
    }
    int  x;
    printf("enter the value to insert :");
    scanf("%d",&x);
    (*rear)++;
    queue[*rear]=x;
}
}
void dequeue(int queue[],int *front, int *rear)
{
    if(*front==-1 || *front>*rear)
    {
        printf("queue is underflow");
    }
    else
    {
        printf("the popped element is %d",queue[*front]);
        (*front)++;
    }
}
void display(int queue[],int *front,int *rear)
{
    if(*front==-1)
    {
        printf("queue is underflow \n");
        return;
    }
    else
    {
        printf("list of queue is :");
        for(int i=*front;i<=*rear;i++)
        {
            printf("%d\n",queue[i]);
        }

    }
}