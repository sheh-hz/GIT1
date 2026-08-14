#include<stdio.h>
#include<string.h>
union stu
{
    int data;
    float age;
    char name[20];
};
void main()
{
    union stu s1;
    s1.data=10;
    printf("%d\n",s1.data);
    s1.age=22.3;
    printf("%f\n",s1.age);
    strcpy(s1.name,"hello");
    printf("%s",s1.name);
}
