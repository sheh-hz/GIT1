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
    s1.age=22.3;
    strcpy(s1.name,"hello");
    printf("%d\n",s1.data);
    printf("%s",s1.name);
    printf("%f\n",s1.age);
}
