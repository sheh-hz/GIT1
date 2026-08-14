/*Add more lines to the end of a file without erasing its current content.
Input: File name: lines.txt
Number of new lines: 2
New lines: Line four, Line five
Output: File now contains: Line one, Line two, Line three, Line four, Line five
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
    int line=3,i=0;
    FILE *ptr=NULL;
    ptr=fopen("test.txt","a");
    if(ptr==NULL)
    {
        printf("file is not created");
        exit(1);
    }
    fwrite("\nline 4\n", sizeof(char), strlen("\nline 4\n"), ptr);
    fwrite("line 5\n", sizeof(char), strlen("line 5\n"), ptr);
    fclose(ptr);



}
