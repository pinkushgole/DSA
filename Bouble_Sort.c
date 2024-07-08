#include<stdio.h>
void main()
{
    int a[]={7,19,23,16,9},i,j,temp;

    for(i=0;i<5;i++)
    {
        for(j=1;j<5-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
   printf("After sorting : \n");
   for(i=0;i<5;i++)
   {
    printf("%d\t",a[i]);
   }
}