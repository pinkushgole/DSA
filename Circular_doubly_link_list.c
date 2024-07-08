#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node * ladd, * radd;
};
struct node *start=NULL, *New, *temp;

void create();
void insert();
void display();
void Delete();
int main()
{    
    int ch;  
    do
    {
        printf("\n----------Circular Doubly Linked list-----------\n");
        printf("Press 1 for Create\nPress 2 for Insert\nPress 3 for Delete\nPress 4 for Display\nPress 5 to Exit\n");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1: create();break;
            case 2: insert();break;
            case 3: Delete();break;
            case 4: display();break;
            case 5: break;
            default : printf("invalid input try again");
        }
    }while(ch != 5);
    return 0;
}
void create()
{
    int n;
    char ch;
    printf("Enter a value : ");
    scanf("%d",&n);
    start = (struct node*) malloc (sizeof(struct node));
    start->data = n;
    start->ladd = start;
    start->radd=start;
    temp = start;
    printf("To add more elements press 'Y' ");
    scanf("  %c",&ch);
    while(ch == 'y' || ch == 'Y')
    {
        printf("Enter next value : ");
        scanf("%d",&n);
        New = (struct node *) malloc (sizeof(struct node));
        New->data = n;
        New->ladd = temp;
        New->radd = start;
        start->ladd = New;
        temp->radd = New;
        temp = New;
        printf("To add more elements press 'Y' ");
        scanf("  %c",&ch);
    }
}
void insert()
{
    int n,pos,count=0;
    if(start == NULL)
    {
        printf("List Not created first create list ");
    }
    else
    {
        printf("Enter a value : ");
        scanf("%d",&n);
        New = (struct node *) malloc(sizeof(struct node));
        New->data = n;
        New->ladd = NULL;
        New->radd = NULL;
        printf("Enter Position : ");
        scanf("%d",&pos);
        temp = start;
        do
        {
            temp = temp->radd;
            count++;
        }
        while(temp != start);
        if (pos > count+1)
        {
            printf("Invalid Position");
        }
        else
        {  
            // printf("%d",count);
            if(pos==1)
            {
                temp = start;
                do
                {
                    temp = temp->radd;
                }
                while(temp->radd != start);
                New->ladd = temp;
                New->radd = start;
                start = New;
                temp->radd = start;
            }
            else if(pos == count+1)
            {
                temp = start;
                do
                {
                    temp = temp->radd;
                }
                while(temp->radd != start);
                temp->radd = New;
                New->ladd = temp;
                start->ladd = New;
                New->radd = start;
            }
            else
            {
                temp = start;
                for (int i = 1; i < pos; i++)
                {
                    temp = temp->radd;
                }
                New->radd = temp;
                New->ladd = temp->ladd;
                temp->ladd->radd = New;
                temp->ladd = New;
            }
        }
    }
}
void display()
{
    if(start == NULL)
    {
        printf("List Not Created ");
    }
    else
    {
        temp = start;
        do
        {
            printf("%d ",temp->data);
            temp = temp->radd;
        }   
        while (temp != start);
    }
}
void Delete()
{
    int pos,count=0;
        if(start==NULL)
        {
            printf("List Not Created ");
        }
        else
        {
            printf("Enter position to Delete ");
            scanf("%d",&pos);
            if(pos==1)
            {
                printf("Deleted data is %d",start->data);
                temp=start;
                do
                {
                    temp=temp->radd;
                }
                while (temp->radd != start);
                start=start->radd;
                start->ladd=temp;  
            }
            else
            {
                temp=start;
                do
                {
                    temp=temp->radd;
                    count++;
                }
                while (temp != start);
                if(pos > count)
                {
                    printf("Invalid Positon ");
                }
                else if(pos==count)
                {
                    temp=start;
                    do
                    {
                        temp=temp->radd;
                    }
                    while (temp->radd != start);
                    printf("Deleted data is %d",temp->data);
                    temp->ladd->radd=start;
                    free(temp);
                }
                else
                {
                    temp=start;
                    for (int i = 1; i < pos; i++)
                    {
                        temp=temp->radd;
                    }
                    printf("Deleted data is %d",temp->data);
                    temp->ladd->radd=temp->radd;
                    temp->radd->ladd=temp->ladd;
                }
                
            }
        }
}