#include<stdio.h>
#include<string.h>
union stu
{
    int *data;
    union
    {
        float age;
        char name[20];
    }p;
};
void main()
{
    union stu s1;
    int a=22;
    s1.data=&a;
    printf("%d\n",*s1.data);
    s1.p.age=22.3;
    printf("%f\n",s1.p.age);
    strcpy(s1.p.name,"hello");
    printf("%s",s1.p.name);
    union stu *p=&s1;
    p->data=&a;
    printf("%d\n",*p->data);
    p->p.age = 22.3;
    printf("%f\n",p->p.age);
    strcpy(p->p.name,"hello");
    printf("%s",p->p.name);
}
