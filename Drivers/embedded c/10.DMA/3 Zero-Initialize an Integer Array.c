#include <stdio.h>
#include<stdlib.h>

int main()
{
    int limit,i;
    printf("enter the limit : ");
    scanf("%d",&limit);
    int *p=NULL;
    p=calloc(limit,sizeof(int));
    if(p==NULL)
    {
        printf("memory not allocated");
        exit(1);
    }
    for(i=0;i<limit;i++)
    {
        printf("%d\t",*(p+i));
    }
    for(i=0;i<limit;i++)
    {
        scanf("%d",p+i);
    }
    for(i=0;i<limit;i++)
    {
        printf("%d\t",*(p+i));
    }
    free(p);
    return 0;
}
