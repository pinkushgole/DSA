#include<stdio.h>
void main()
{
    int a[]={98,76,55,99,45},i,j,temp;

    for(i=0;i<4;i++)
    {
        for(j=(i+1);j<5;j++)
        {
            if(a[i]>a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }

    printf("After selectio sorting : \n");
   for(i=0;i<5;i++)
   {
    printf("%d\t",a[i]);
   }
}