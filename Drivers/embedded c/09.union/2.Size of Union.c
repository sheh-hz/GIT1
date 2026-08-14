
#include<stdio.h>
#include<string.h>
union stu
{
    int data;
    float age;
    char name[20];
};
struct s
{
    int data;
    float age;
    char name[20];
};
void main()
{
    union stu s1;
    struct s s2;
    printf("union %d\n",sizeof(s1));
    printf("struct %d\n",sizeof(s2));
}
