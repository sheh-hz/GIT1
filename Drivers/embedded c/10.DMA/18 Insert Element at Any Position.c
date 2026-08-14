#include<stdio.h>
#include<stdlib.h>
void main()
{
    int s=5,pos,val,i;
    int *p=NULL;
    p=malloc(sizeof(int)*s);
    if(p==NULL)
    {
        exit(1);
    }
    for(i=0;i<s;i++)
    {
        scanf("%d",p+i);
    }
    printf("enter pos and value : ");
    scanf("%d%d",&pos,&val);
    p=realloc(p,sizeof(int)*(s+1));
    if(p==NULL)
    {
        exit(1);
    }
    for(i=s;i>=pos-1;i--)
    {
        *(p+i+1)=*(p+i);
    }
    *(p+i+1)=val;
    for(i=0;i<=s;i++)
    {
        printf("%d",*(p+i));
    }
    free(p);
}
