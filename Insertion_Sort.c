#include<stdio.h>
void main()
{
    int a[]={65,34,23,98,12},i,j,temp;

   for(i=1;i<5;i++)
   {
    j=i-1;
    temp=a[i];
    while (j>=0 && a[j]>temp)
    {
        a[j+1]=a[j];
        j--;
    }
    a[j+1]=temp;
   }

   printf("After Insertion sorting : \n");
   for(i=0;i<5;i++)
   {
    printf("%d\t",a[i]);
   }
}