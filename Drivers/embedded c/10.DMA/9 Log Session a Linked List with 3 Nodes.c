#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
void main()
{
    node *one,*two,*three,*head;
    one=malloc(sizeof(node));
    two=malloc(sizeof(node));
    three=malloc(sizeof(node));
    one->data=10;
    two->data=20;
    three->data=30;
    one->next=two;
    two->next=three;
    three->next=NULL;
    head=one;
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    free(head);

}


