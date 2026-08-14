#include<stdio.h>
#include<stdlib.h>

int main()
{
	char a[]="hello world";
	char *token;
	token=strtok(a," ");
	while(token!=NULL)
	{
		printf("%s\n",token);
		token=strtok(NULL,",");
	}
	return 0;
}
