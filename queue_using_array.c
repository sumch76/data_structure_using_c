#include<stdio.h>
#include<stdlib.h>
int queue[100],i,n,ch,x;
int front=-1;
int rear=-1;
void enqueue(int x);
void dequeue();
void display();
int main()
{
    printf("enter the size of queue :");
    scanf("%d",&n);
    while(1)
    {
        printf("QUUEUE OPERATION USING ARRAY :\n");
        printf("-----------------------");
        printf("\n\t1.INSERTION\n\t2.DELETION\n\t3.DISPLAY\n\t4.EXIT");
        printf("\nenter thr choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
             printf("enter the value to insert : ");
        scanf("%d",&x);
            enqueue(x);
            break;
            case 2:
            dequeue();
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            printf("\n\tEXIT POINT");
            default :
            printf("enter a valid option");
        }
    }
}
void enqueue(int x)
{
    if(rear==n-1)
    {
        printf("queue is overflow\n");
    }
    else 
    {
        if(front==-1)
    
        front=0;
    }
        rear++;
        queue[rear]=x;
       

    }  

void dequeue()
{
    if(front==-1)
    {
        printf("****queue is underflow*****\n");
    }
    else {
        printf("the deleted elemnt is %d\n",queue[front]);
        front++;
        if(front>rear)//only happens when the last element was dequeued
        {
        front=rear=-1;
        }

    }
}

void display()
{
    if(rear==-1)
    {
        printf("stack is empty\n");
    }
    else
    {
        printf("list of queue :\n");
        for(i=front;i<=rear;i++)
            printf("%d\n",queue[i]);
    }
}