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
    ptr=fopen("test.txt","r");
    if(ptr==NULL)
    {
        printf("file is not created");
        exit(1);
    }
    char arr[15];
    fread(arr, sizeof(char), 10, ptr);
    arr[10] = '\0';
    printf("%s",arr);
    fclose(ptr);
}
