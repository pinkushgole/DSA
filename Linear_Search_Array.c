// searching in 1-d array using function
#include <stdio.h>
#define size 100
int ls(int x[], int, int);
void main()
{
    int a[size], ch, n, temp;
    printf("enter the array size=");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("value=");
        scanf("%d", &a[i]);
    }
    printf("enter the search element =");
    scanf("%d", &ch);
    temp = ls(a, ch, n);
    if (temp == 1)
    {
        printf("!! element is present !!");
    }
    else
    {
        printf("!! element is not present !!");
    }
}
int ls(int x[], int ch, int n)
{
    int tem = 0;
    for (int i = 0; i < n; i++)
    {
        if (ch == x[i])
        {
            tem = 1;
        }
    }
    return tem;
}