/*
Input: File name: lines.txt
Output: Line one, Line two, Line three (as array elements)
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
    char arr[100];
    while (!feof(ptr)) {
        fread(arr,sizeof(char),20,ptr);
    }
    printf("%s ",arr);
    fclose(ptr);



}
