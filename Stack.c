#include<stdio.h>
#define maxsize 10
int stack[maxsize],top=-1;
void push();
void pop();
void display();

int main()
{
    int ch;
    do
    {
        printf("\n\n...Stack...\n");
        printf("\nPress 1 for push operation \n");
        printf("\nPress 2 for pop operation\n");
        printf("\nPress 3 for display all element\n");
        printf("\nPress 4 for exit\n");

        printf("\nenter your choice : ");
        scanf("%d",&ch);

        switch (ch)
        {
        case 1:push();break;
        case 2:pop();break;
        case 3:display();break;
        case 4: break;
        default:printf("invaid choice!!!");
        }
    } 
    while (ch!=4);
    return 0;
}

void push()
{
  if (top==maxsize-1)
  {
    printf("\nStack is full\n");
  }
  else{
    top++;
    printf("\nENter the values : ");
    scanf("%d",&stack[top]);
  }
  
}
void pop()
{
  if (top==-1)
  {
    printf("\nStack underflow\n");
  }
  else
  {
    printf("Delete data = %d",stack[top]);
    top--;
  }
  
}
void display()
{
  if (top==-1)
  {
    printf("\nStact underflow\n");
  }
  else
  {
    for (int i = 0; i <= top; i++)
    {
        printf("%d\t",stack[i]);
    }
  }
}