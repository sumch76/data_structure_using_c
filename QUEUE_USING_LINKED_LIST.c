#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* next;
};//defining linked list to implement queue

struct node *front = NULL;
struct node *rear = NULL;
void enqueue(int);
void dequeue();
void display();
int main()
{
    int choice, d;
    printf("\n queue using linked list ::\n");
    while(1)
    {
        printf("\n *****MENU *****\n");
        printf("1.insert\n 2.delete\n 3.Display\n 4.exit\n");
        printf("enter your choice :");

        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("enter the value to insert :");
            scanf("%d",&d);
            enqueue(d);
            break;
            case 2:
            dequeue();
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
  

void enqueue(int d)//function to insert a node in queue
{
	struct node* newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = d;
	newnode->next = NULL;
	if(front == NULL){
		front = rear = newnode;
	}
	else{
		rear->next = newnode;
		rear = newnode;
	}
	
}
void dequeue()//function to delete an element from a queue
{
	struct node *temp;
	temp = front;
	if(front == NULL){
		printf("\nQueue is Empty");
	}
	else{
        printf("deleted element is %d ",front->data);
		front = front->next;
		free(temp);
		if(front==NULL)
		{
			rear=NULL;
		}
	}
}
void display()//function to display the queue
{
	struct node* temp;
	if(front == NULL && rear==NULL){
		printf("\nQueue is Empty");
	}
	else{
		temp = front;
		while(temp!=NULL){
			printf(" %d ",temp->data);
			temp = temp->next;
		}
	}
}



 