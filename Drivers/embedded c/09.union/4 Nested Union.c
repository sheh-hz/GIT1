#include<stdio.h>
#include<string.h>
union stu
{
    int data;
    union
    {
        float age;
        char name[20];
    }p;
};
void main()
{
    union stu s1;
    s1.data=10;
    printf("%d\n",s1.data);
    s1.p.age=22.3;
    printf("%f\n",s1.p.age);
    strcpy(s1.p.name,"hello");
    printf("%s",s1.p.name);

}
