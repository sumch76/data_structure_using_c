#include<stdio.h>
#include<stdlib.h>
int stack[100],ch,n,top,x,i;
void push();
void pop();
void peek();
void display();
int main()
{
    top=-1;
    printf("enter the size of an stack :");
    scanf("%d",&n);
    while(1)
    {
    printf("\nENTER STACK OPERATIONS USING ARRAY :\n");
    printf("\n\t---------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP \n\t 3.PEEK \n\t 4.DISPLAY\n\t 5.EXIT");
        printf("\n enter the choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            push();
            break;
            
            case 2:
            pop();
            break;
            
            case 3:
            peek();
                break;
            
            case 4:
            display();
            break;
            
            case 5:
             exit(0);
            printf("\n\t EXIT POINT ");
            
            default:
             printf("\n\t please enter a valid choice(1/2/3/4)");
            
        }
    }
}
void push()
{
    if(top==n-1)
    {
        printf("\n\t stack is overflow");
    }
    else
    {
        printf("enter a value to be pushed :");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}
void pop()
{
    if(top==-1)
    {
        printf("\n\t STACK is underflow");
    }
    else
    {
        printf("\n\t the popped element is %d ",stack[top]);
        top--;
    }
}
void peek()
{
    if(top==-1)
    {
       printf("stack is empty");    
    }
    else
    {
        printf("the top element is %d\n",stack[top]);
    }
}
void display()
{
    if(top>=0)
    {
        printf("\n the elements in stack :");
        for(i=top;i>=0;i--)
        printf("\n %d",stack[i]);
    }
    else
    {
        printf("\n the stack is empty");
    }
}
