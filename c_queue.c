#include <stdio.h>

#define maxsize 10

int q[maxsize], rear = -1, front = 0;


void insert();
void Delete();
void display();

void main()
{
    int ch;
    
    do
    {
        printf("\n----------------QUEUE----------------\n");
        printf("Press 1 for Insert the element into Queue\n");
        printf("Press 2 for Delete the element from Queue\n");
        printf("Press 3 for Display all elements from Queue\n");
        printf("Press 4 for EXIT\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
    
        switch(ch)
        {
            case 1:insert();break;
            case 2:Delete(); break;
            case 3:display();break;
            case 4:break;
            default:printf("Invalid Choice, re-enter the choice again: ");
        }
    }
    while(ch!=4);
    
}

void insert()
{
    int n;
    if(rear < maxsize-1)
    {
        printf("\nEnter a value: ");
        scanf("%d",&n);
        rear++;
        q[rear]=n;
    }
    else if((rear+1)%maxsize<front%maxsize && front!=0)
    {
        printf("\nEnter a value: ");
        scanf("%d",&n);
        rear++;
        q[rear%maxsize]=n;
    }
    else
    {
        printf("C-Queue Overflow");
    }
}

void Delete()
{
    if(rear<front)
    {
        printf("\nQueue Underflow\n");
        front = 0;
        rear = -1;
    }
    else
    {
        printf("\nDeleted data = %d\n",q[front%maxsize]);
        front++;
    }
}

void display()
{
    int i;
    if(rear<front)
    {
        printf("\nQueue Underflow\n");
    }
    else
    {
        for (i = front; i <= rear; i++) 
        {
            printf("%d ",q[i%maxsize]);
        }
    }
}
