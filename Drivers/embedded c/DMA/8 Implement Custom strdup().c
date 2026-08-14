#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *strdupp(char *p,int l)
{
    static char *q=NULL;
    int i;
    q=malloc(sizeof(char)*(l+1));
    if(q==NULL)
    {
        printf("memory not allocated");
        exit(1);
    }
    for(i=0;i<l;i++)
    {
        *(q+i)=*(p+i);
    }
    *(q+i)='\0';
    return q;
}
void main()
{
    char a[10];
    scanf(" %s",a);
    printf("%s\n",a);
    int l=strlen(a);
    char *p=strdupp(a,l);
    printf("%s",p);
    free(p);

}


