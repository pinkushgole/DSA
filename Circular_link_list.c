#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *add;
};
struct node *start = NULL, *New = NULL, *prev = NULL, *next = NULL, *temp = NULL;
void create();
void insert();
void display();
void Delete();

int main()
{
    int f;
    do
    {
        printf("\n----------Circular linked list---------------\n");
        printf("press 1 for create\n");
        printf("press 2 for insert\n");
        printf("press 3 for display\n");
        printf("press 4 for Delete\n");
        printf("press 5 for exit\n");

        scanf("%d", &f);

        switch (f)
        {
        case 1:
            create();
            break;
        case 2:
            insert();
            break;
        case 3:
            display();
            break;
        case 4:
            Delete();

            break;
        case 5:
            break;
        default:
            printf("Invalid choice");
        }
    } while (f != 5);
}
void create()
{
    int n;
    char ch;
    printf("Enter the value");
    scanf("%d", &n);
    start = (struct node *)malloc(sizeof(struct node));
    start->data = n;
    start->add = start;
    temp = start;
    printf("To add more elements press y");
    scanf(" %c", &ch);
    while (ch == 'y' || ch == 'Y')
    {
        printf("\nEnter next  value\n");
        scanf("%d", &n);
        New = (struct node *)malloc(sizeof(struct node));
        New->data = n;
        New->add = start;
        temp->add = New;
        temp = New;
        printf("\nTo add more elements press y\n");
        scanf(" %c", &ch);
    }
}
void insert()
{
    int pos, n, count = 0, i = 1;
    printf("Enter the no");
    scanf("%d", &n);
    New = (struct node *)malloc(sizeof(struct node));
    New->data = n;
    New->add = start;

    printf("Enter the position");
    scanf("%d", &pos);

    if (pos == 1)
    {
        temp = start;
        while (temp->add != start)
        {
            temp = temp->add;
        }
        temp->add = New;
        start = New;
    }
    else
    {
        temp = start;
        do
        {
            count++;
            temp = temp->add;
        } while (temp != start);

        if (pos > (count + 1))
        {
            printf("Invalid position ,it should be less than or equal to %d", count + 1);
        }
        else if (pos == count + 1)
        {
            temp = start;
            while (temp->add != start)
            {
                temp = temp->add;
            }
            temp->add = New;
            New->add = start;
        }
        else
        {
            next = start;
            while (i < pos)
            {
                prev = next;
                next = next->add;
                i++;
            }
            prev->add = New;
            New->add = next;
        }
    }
}
void Delete()
{
    int pos, i = 1, count = 0;
    printf("Enter the position ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        temp = start;

        printf("Deleted data = %d", temp->data);
        while (temp->add != start)
        {
            temp = temp->add;
        }
        temp->add = start->add;
        temp = start;
        start = start->add;
        free(temp);
    }
    else
    {
        temp = start;
        do
        {
            count++;
            temp = temp->add;
        } while (temp != start);

        if (pos > count + 1)
        {
            printf("Invalid position it should be greater equal or less than %d", count);
        }
        else if (pos == count)
        {
            next = start;
            while (next->add != start)
            {
                prev = next;
                next = next->add;
            }
            prev->add = start;
            printf("Deleted data =%d", next->data);

            free(next);
        }
        else
        {
            next = start;
            while (i < pos)
            {
                prev = next;
                next = next->add;
                i++;
            }
            temp = next;
            next = next->add;
            printf("%d", temp->data);
            free(temp);
            prev->add = next;
        }
    }
}
void display()
{
    if (start == NULL)
    {
        printf("list not created");
    }
    else
    {
        temp = start;
        do
        {
            printf("%d \t ", temp->data);
            temp = temp->add;
        } while (temp != start);
    }
}