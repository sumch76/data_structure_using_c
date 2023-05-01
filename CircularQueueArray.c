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
        printf("\nQUUEUE OPERATION USING ARRAY :\n");
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
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else if((rear+1)%n==front)
    {
    printf("queue is full.\n");
       
    }
    else
    {
        rear=(rear+1)%n;
        queue[rear]=x;
    }

    }  

void dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("****queue is underflow*****\n");
    }
    else if(front==rear)
    {
        printf("deleted element is %d\n",queue[front]);
       front=rear=-1;
    }
    else
    {
        printf("deleted element is %d\n",queue[front]);
        front=(front+1)%n;
    }
}

void display()
{
    if(front==-1 && rear==-1)
    {
        printf("queue is empty");
    }
    else
    {
        int i=front;
        printf("queue is :\n");
        while(i!=rear)
        {
            printf("%d ",queue[i]);
            i=(i+1)%n;
        }
        printf("%d \n",queue[rear]);
    }
}