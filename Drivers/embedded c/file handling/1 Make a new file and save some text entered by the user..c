/*
Input: File name: test.txt
Text: Hello, this is my first file!
Output: File 'test.txt' created and saved.
*/
#include<stdio.h>
#include<stdlib.h>
void main()
{
    FILE *ptr=NULL;
    ptr=fopen("test.txt","w");
    if(ptr==NULL)
    {
        printf("file is not created");
        exit(1);
    }

    fwrite("Hello, this is my first file!", sizeof(char), 15, ptr);
    fclose(ptr);
}
