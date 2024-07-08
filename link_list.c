

#include <stdio.h>

struct node
{
    int data;
    struct node *add;
};
struct node *start=NULL,*temp=NULL,*New=NULL,*prev=NULL,*next=NULL;

void create();
void insert();
void Delete();
void display();

int main()
{
    int ch;
    
    do
    {
        printf("\n----------------Link List----------------\n");
        printf("Press 1 to Create a Link List\n");
        printf("Press 2 to Insert the element into Link List\n");
        printf("Press 3 to Delete the element from Link List\n");
        printf("Press 4 to Display all elements from Link List\n");
        printf("Press 5 for EXIT\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
    
        switch(ch)
        {
            case 1:create();break;
            case 2:insert();break;
            case 3:Delete(); break;
            case 4:display();break;
            case 5:break;
            default:printf("Invalid Choice, re-enter the choice again: ");
        }
    }
    while(ch!=5);
    
    return 0;
}

void create()
{
    int n;
    char ch;
    printf("\nEnter a Value: ");
    scanf("%d",&n);                                                     // temp = 1111
    start = (struct node *)malloc(sizeof(struct node));                 // start = 2011
    start->data = n;                                                    // n = 40
    start->add = NULL;
    temp = start;
    printf("To add more elemtns, Press 'Y': ");
    scanf(" %c",&ch);
    while(ch=='y' || ch == 'Y')
    {
        printf("\nEnter next Value: ");
        scanf("%d",&n);
        New = (struct node *)malloc(sizeof(struct node));                 // New = 1111
        New->data = n;
        New->add = NULL;
        temp->add = New;
        temp = New;
        printf("To add more elemtns, Press 'Y': ");
        scanf(" %c",&ch);
    }
}
void insert()
{
    int n,position,count=0,i=1;

    if(start == NULL)
    {
        printf("List Not Created, Create a list first");
    }
    else
    {
        printf("Enter a Value: ");
        scanf("%d",&n);
        
        New = (struct node *) malloc(sizeof(struct node));          // New = 2222
        New->data = n;
        New->add = NULL;
        
        printf("Enter a position for node insertion: ");
        scanf("%d",&position);
        
        if(position == 1)
        {
            New->add=start;
            start = New;
        }
        else
        {
            temp = start;
            
            while(temp!=NULL)                               // temp = NULL
            {                                               // count = 4
                count++;
                temp = temp->add;
            }
            if(position > count+1)
            {
                printf("\nInvalid Position, it can't be more than %d\n",(count+1));
            }
            else if(position == count+1)
            {
                temp = start;                   
                while(temp->add != NULL)                    // temp = 1111
                {
                    temp = temp->add;
                }
                temp->add = New;                            // New = 2222
            }
            else
            {
                next = start;                               // position = 3
                while(i<position)                           // i = 3
                {                                           // next = 1234
                    prev = next;                            // prev = 1011
                    next = next->add;
                    i++;
                }
                prev-> add = New;
                New->add = next;
            }
        }
    }
}
void Delete()
{
    int count=0,i=1,position;

    if(start == NULL)
    {
        printf("List Not Created, Create a list first");
    }    
    else
    {
        printf("Enter a Posiotion for Deletion: ");
        scanf("%d",&position);
        
        if(position == 1)
        {                                                                   // temp = 2011
            temp = start;                                                   // start = 1011
            start = start->add;
            printf("Deleted Element = %d: \n",temp->data);
            free(temp);
        }
        else
        {
            temp = start;
            
            while(temp!=NULL)                               // temp = NULL
            {                                               // count = 4
                count++;
                temp = temp->add;
            }
            if(position > count)
            {
                printf("\nInvalid Position, it can't be more than %d\n",count);
            }
            else if(position == count)      // Last Position
            {
                next = start;                               // next = 1111
                while(next->add!=NULL)                      // prev = 1234
                {
                    prev=next;
                    next = next->add;
                }
                printf("\n Deleted Element = %d\n",next->data);
                free(next);
                prev->add = NULL;
            }
            else
            {
                next = start;                               // i = 3
                while(i<position)                           // next = 1111
                {                                           // prev = 1011
                    prev = next;                            // temp = 1234
                    next = next->add;
                    i++;
                }
                temp = next;
                next = next->add;
                printf("\nDeleted Element = %d\n",temp->data);
                free(temp);
                prev->add=next;
            }
        }
    }
    
}
void display()
{
    if(start == NULL)
    {
        printf("List Not Created, Create a list first");
    }
    else
    {
        temp = start;                           // start = 2011
        
        while(temp!=NULL)                       // temp = NULL
        {
            printf("%d ",temp->data);
            temp = temp->add;
        }
    }
}