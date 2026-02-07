#include<stdio.h>
#include<stdlib.h>
int main()
{
    int arr[20],n,i,pos,ch;
    printf("Enter the Initial Number of Elements :\n");
    scanf("%d",&n);
    printf("Enter the Elements :");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Initial Array :\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n");
    while(1)
    {
        printf("\n---------------Menu---------------");
        printf("\n1.Deletion\n");
        printf("\n2.Display\n");
        printf("\n3.exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the postion the elemnet to be deleted(0-%d) :\n",n-1);
            scanf("%d",&pos);
            for(i=pos;i<n-1;i++)
            {
                arr[i]=arr[i+1];
            } 
            n--;
            break;
            case 2:
            printf("Current Array :\n");
            for(i=0;i<n;i++)
            {
                printf("%d ",arr[i]);       
            }
            break;
            case 3:
            exit(0);
            default :
            printf("\nInvalid Choice\n");
        }


    }
}
