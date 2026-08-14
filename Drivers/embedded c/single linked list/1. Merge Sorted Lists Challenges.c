/*Write a C program to merge two sorted singly linked lists into a single sorted linked list.

Sample data:
List 1: 1 3 5 7
List 2: 2 4 6*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node *head=NULL,*temp=NULL,*newnode=NULL;
node* createnode(int num)
{
    int i=0;
    head=NULL;
    while(i<num)
    {
        newnode=malloc(sizeof(node));
        if(newnode==NULL)
        {
            printf("node not created");
            exit(1);
        }
        printf("enter data : ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
            head=temp=newnode;
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
            i++;
    }
    return head;
}
void print(node * head)
{
    while(head!=NULL)
    {
        printf("%d\t",head->data);
        head=head->next;
    }
}
node* merge(node *first, node *second)
{
    node *head3 = NULL;
    node *temp3 = NULL;

    while(first != NULL && second != NULL)
    {
        newnode = malloc(sizeof(node));

        if(first->data <= second->data)
        {
            newnode->data = first->data;
            first = first->next;
        }
        else
        {
            newnode->data = second->data;
            second = second->next;
        }

        newnode->next = NULL;

        if(head3 == NULL)
        {
            head3 = temp3 = newnode;
        }
        else
        {
            temp3->next = newnode;
            temp3 = newnode;
        }
    }

    // Add remaining nodes
    while(first != NULL)
    {
        newnode = malloc(sizeof(node));
        newnode->data = first->data;
        newnode->next = NULL;

        temp3->next = newnode;
        temp3 = newnode;
        first = first->next;
    }

    while(second != NULL)
    {
        newnode = malloc(sizeof(node));
        newnode->data = second->data;
        newnode->next = NULL;

        temp3->next = newnode;
        temp3 = newnode;
        second = second->next;
    }

    return head3;
}
void main()
{
    node *first=createnode(3);
    print(first);
    node *second=createnode(4);
    print(second);
    node *third=merge(first,second);
    print(third);
}
