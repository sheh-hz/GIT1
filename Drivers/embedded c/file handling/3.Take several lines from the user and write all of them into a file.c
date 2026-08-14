/*
Input: File name: test.txt
Text: Hello, this is my first file!
Output: File 'test.txt' created and saved.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
    int line=3,i=0;
    FILE *ptr=NULL;
    ptr=fopen("test.txt","r");
    if(ptr==NULL)
    {
        printf("file is not created");
        exit(1);
    }
    char arr[100][100];
    while (fgets(arr[i], 100, ptr)) {
        i++;
    }

    fclose(ptr);

    for (int j = 0; j < i; j++) {
        printf("%s", arr[j]);
    }

}
