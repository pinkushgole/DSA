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
        printf("\n----------Doubly Linked list-----------\n");
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
    start->ladd = NULL;
    start->radd=NULL;
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
        New->radd = NULL;
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
        if(pos==1)
        {
            New->radd = start;
            start = New;
        }
        else
        {
            temp = start;
            while(temp != NULL)
            {
                temp = temp->radd;
                count++;
            }
           // printf("%d",count);
            if (pos > count+1)
            {
                printf("Invalid Position");
            }
            else if(pos == count+1)
            {
                temp = start;
                while(temp->radd != NULL)
                {
                    temp = temp->radd;
                }
                temp->radd = New;
                New->ladd = temp;
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
        while (temp != NULL)
        {
            printf("%d ",temp->data);
            temp = temp->radd;
        }   
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
                start=start->radd;
                start->ladd=NULL;
            }
            else
            {
                temp=start;
                while (temp != NULL)
                {
                    temp=temp->radd;
                    count++;
                }
                if(pos > count)
                {
                    printf("Invalid Positon ");
                }
                else if(pos==count)
                {
                    temp=start;
                    while (temp->radd != NULL)
                    {
                        temp=temp->radd;
                    }
                    printf("Deleted data is %d",temp->data);
                    temp->ladd->radd=NULL;
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