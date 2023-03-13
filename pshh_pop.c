#include<stdio.h>
int stack[100],ch,n,top,x,i;
void push();
void pop();
void display();
int main()
{
    top=-1;
    printf("enter the size of an stack :");
    scanf("%d",&n);
    printf("\nENTER STACK OPERATIONS USING ARRAY :");
    printf("\n\t---------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP \n\t 3.DISPLAY\n\t4.EXIT");
    do
    {
        printf("\n enter the choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
            push();
            break;
            }
            case 2:
            {
            pop();
            break;
            }
            case 3:
            {
            display();
            break;
            }
            case 4:
            {
            printf("\n\t EXIT POINT ");
            break;
            }
            default:
            {
                printf("\n\t please enter a valid choice(1/2/3/4)");
            }
        }
    }
    while(ch!=4);
    return 0;
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
        printf("\n\t the popped elements is %d ",stack[top]);
        top--;
    }
}
void display()
{
    if(top>=0)
    {
        printf("\n the elements in stack \n");
        for(i=top;i>=0;i--)
        printf("\n %d",stack[i]);
        printf("\n press next choice ");
    }
    else
    {
        printf("\n the stack is empty");
    }
}
