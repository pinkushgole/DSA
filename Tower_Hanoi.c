#include<stdio.h>
void hanoi(int n,char init,char final,char temp);
void main()
{
    int n;
    printf("Enter the nimber of dick : ");
    scanf("%d",&n);

    hanoi(n,'A','C','B');

}

void hanoi(int n,char init,char final,char temp)
{
    if(n==1)
    {
        printf("move dick 1 from %c to %c \n",init,final);
        return;
    }
    hanoi(n-1,init,temp,final);
    printf("move dick %d from %c to %c \n",n,init,final);
    hanoi(n-1,temp ,final,init);
}