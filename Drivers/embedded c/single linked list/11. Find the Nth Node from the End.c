#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int data)
{
    struct Node *node = malloc(sizeof(struct Node));

    node->data = data;
    node->next = NULL;

    return node;
}

void insertEnd(struct Node **head, int data)
{
    struct Node *node = createNode(data);

    if (*head == NULL)
    {
        *head = node;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = node;
}

struct Node* nthFromEnd(struct Node *head, int n)
{
    struct Node *fast = head;
    struct Node *slow = head;

    // Move fast pointer n positions ahead
    for (int i = 0; i < n; i++)
    {
        if (fast == NULL)
            return NULL;

        fast = fast->next;
    }

    // Move both pointers
    while (fast != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

int main()
{
    struct Node *head = NULL;

    insertEnd(&head, 1);
    insertEnd(&head, 3);
    insertEnd(&head, 5);
    insertEnd(&head, 11);

    int n = 3;

    struct Node *result = nthFromEnd(head, n);

    if (result != NULL)
        printf("Result: %d\n", result->data);
    else
        printf("Invalid n\n");

    return 0;
}
