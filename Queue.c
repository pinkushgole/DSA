#include<stdio.h>
#define maxsize 10
int queue[maxsize],rear=-1,front=0;

void insert();
void Delete();
void display();

int main()
{
    int ch;
    do
    {
        printf("\n\n...Stack...\n");
        printf("\nPress 1 for insert operation \n");
        printf("\nPress 2 for Delete operation\n");
        printf("\nPress 3 for display all element\n");
        printf("\nPress 4 for exit\n");

        printf("\nenter your choice : ");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:insert();break;
        case 2:Delete();break;
        case 3:display();break;
        case 4: break;
        default:printf("invaid choice!!!");
        }
    } 
    while (ch!=4);
    return 0;
}
void insert()
{
    int n;
    if(rear==(maxsize-1))
    {
        printf("Queue overflow");
    }
    else{
        printf("\nEnter the data:");
        rear++;
        scanf("%d",&queue[rear]);
    }
}

void Delete()
{
    if(front>rear)
    {
        printf("Queue underflow");
    }
    else{
        printf("\nDelete data:%d",queue[front]);
        front++;
       
    }
}
void display()
{
     if(front>rear)
    {
        printf("Queue underflow");
    }
    else{
        for(int i=front;i<=rear;i++)
         {    printf("\n%d\t",queue[i]);
    }
    }
}