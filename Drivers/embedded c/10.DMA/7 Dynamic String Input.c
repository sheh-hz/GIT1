#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
    char a[10];
    scanf(" %s",a);
    printf("%s\n",a);
    int l=strlen(a);
    char *p=malloc(sizeof(char)*l);
    for(int i=0;i<l;i++)
    {
        *(p+i)=a[i];
    }
    printf("%s",p);
    free(p);

}

