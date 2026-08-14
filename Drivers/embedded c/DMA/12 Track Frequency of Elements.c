
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int *freq,n,num;
	freq=(int*)calloc(100,sizeof(int));
	if(freq==NULL)
	{
		printf("Memory allocation failed");
		return 1;
	}
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter %d numbers (0-99):\n",n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num);
		if(num>=0&&num<=99)
			freq[num]++;
		else
			printf("Invalid number: %d\n",num);
	}
	printf("Frequencies:\n");
	for(int i=0;i<100;i++)
	{
		if(freq[i]!=0)
			printf("%d -> %d\n",i,freq[i]);
	}
	free(freq);
	return 0;
}
