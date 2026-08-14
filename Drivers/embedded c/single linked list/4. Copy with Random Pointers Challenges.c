#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    struct node *random;
} node;

node *head = NULL, *temp = NULL, *newnode = NULL;

// Create Linked List
node* createnode(int num)
{
    int i = 0;
    head = NULL;

    while(i < num)
    {
        newnode = (node *)malloc(sizeof(node));

        if(newnode == NULL)
        {
            printf("Node not created");
            exit(1);
        }

        printf("Enter data : ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;
        newnode->random = NULL;

        if(head == NULL)
            head = temp = newnode;
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        i++;
    }

    return head;
}

// Print list with random pointers
void print(node *head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);

        if(head->random != NULL)
            printf("(Random->%d)", head->random->data);
        else
            printf("(Random->NULL)");

        printf("\n");

        head = head->next;
    }
}

// Deep Copy
node* copyList(node *head)
{
    node *curr = head;

    // Step 1: Insert copied nodes
    while(curr != NULL)
    {
        node *copy = (node *)malloc(sizeof(node));

        copy->data = curr->data;
        copy->next = curr->next;
        copy->random = NULL;

        curr->next = copy;
        curr = copy->next;
    }

    // Step 2: Copy random pointers
    curr = head;

    while(curr != NULL)
    {
        if(curr->random != NULL)
            curr->next->random = curr->random->next;

        curr = curr->next->next;
    }

    // Step 3: Separate copied list
    curr = head;

    node *copyHead = head->next;
    node *copy = copyHead;

    while(curr != NULL)
    {
        curr->next = copy->next;

        if(copy->next != NULL)
            copy->next = copy->next->next;

        curr = curr->next;
        copy = copy->next;
    }

    return copyHead;
}

int main()
{
    node *first, *copy;

    printf("Enter 5 sorted values:\n");
    first = createnode(5);

    // Assign random pointers
    first->random = first->next->next;                         // 1 -> 3
    first->next->random = first->next->next->next;             // 2 -> 5
    first->next->next->random = first->next->next->next->next; // 3 -> 7
    first->next->next->next->random = first;                   // 5 -> 1
    first->next->next->next->next->random = first->next->next; // 7 -> 3

    printf("\nOriginal List:\n");
    print(first);

    copy = copyList(first);

    printf("\nCopied List:\n");
    print(copy);

    return 0;
}
