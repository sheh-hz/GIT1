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
int palindrom(node *head)
{
    int arr[100];
    int i = 0, j;

    node *temp = head;

    // Store list elements in array
    while (temp != NULL)
    {
        arr[i] = temp->data;
        i++;
        temp = temp->next;
    }

    // Compare from both ends
    for (j = 0; j < i / 2; j++)
    {
        if (arr[j] != arr[i - j - 1])
            return 0;
    }

    return 1;
}
void main()
{
    node *list=createnode(5);
    print(list);
    if(palindrom(list)==1)
        printf("palindrom");
    else
        printf("not palindrom");
}
