#include<stdio.h>

int main()

{

    int a[10]={9,6,1,2,3,0,7,5,2};

    int i,j, key;



    for (j=1;j<=8;j++)

    {

    key=a[j];

    i=j-1;



    while(i>=0 && a[i]>key)

    {

        a[i+1]=a[i];

        i=i-1;



    }

    a[i+1]=key;

    }



    for (i=0; i<=8;i++)

    {

        printf("%d\n",a[i]);

    }



}
