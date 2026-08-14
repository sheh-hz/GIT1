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
void detectloop(node *head)
{
    node *fast=head;
    node *slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if (slow == fast)
        {
            printf("Loop detected and removed.\n");
            slow = head;
            while(slow->next != fast->next)
            {
                slow = slow->next;
                fast = fast->next;
            }
            fast->next = NULL;
            return;
        }
    }

    printf("No loop found.\n");
}
void main()
{
    node *list=createnode(5);
    print(list);
    detectloop(list);
}
