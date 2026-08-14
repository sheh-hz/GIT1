#include<stdio.h>
#include<stdlib.h>
void main()
{
    int row=3,column=3,i,j;
    int **p=(int**)malloc(row*sizeof(int*));
    if(p==NULL)
    {
        printf("memory not allocated");
        exit(1);
    }
    for(i=0;i<row;i++)
    {
        p[i]=malloc(column*sizeof(int));
        if(p[i]==NULL)
        {
            printf("memory not allocated");
            exit(1);
        }
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            scanf("%d",&p[i][j]);
        }
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            printf("%d\t",p[i][j]);
        }
        printf("\n");
    }
}
