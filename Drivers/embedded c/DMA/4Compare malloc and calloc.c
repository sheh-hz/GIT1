
#include <stdio.h>
#include<stdlib.h>

int main()
{
    int limit,i;
    printf("enter the limit : ");
    scanf("%d",&limit);
    int *p=NULL,*q=NULL;
    p=calloc(limit,sizeof(int));
    q=malloc(sizeof(int)*limit);
    if(p==NULL || q==NULL)
    {
        printf("memory not allocated");
        exit(1);
    }
    for(i=0;i<limit;i++)
    {
        printf("%d %d\t",*(p+i),*(q+i));
    }
    for(i=0;i<limit;i++)
    {
        scanf("%d",p+i);
    }
    for(i=0;i<limit;i++)
    {
        scanf("%d",q+i);
    }
    for(i=0;i<limit;i++)
    {
        printf("%d %d\t",*(p+i),*(q+i));
    }
    free(p);
    free(q);
    return 0;
}
