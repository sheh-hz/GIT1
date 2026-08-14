
#include <stdio.h>
#include<stdlib.h>

int main()
{
    int limit,i;
    int *p=NULL;
    p=malloc(2*sizeof(int));

    if(p==NULL)
    {
        printf("memory not allocated");
        exit(1);
    }
    for(i=0;i<2;i++)
    {
        scanf("%d",p+i);
    }
    for(i=0;i<2;i++)
    {
        printf("%d\t",*(p+i));
    }
    p=realloc(p,5);
    if(p==NULL)
    {
        printf("memory not allocated");
        exit(1);
    }
    for(i=2;i<5;i++)
    {
        scanf("%d",p+i);
    }
    for(i=0;i<5;i++)
    {
        printf("%d\t",*(p+i));
    }
    free(p);
    return 0;
}
