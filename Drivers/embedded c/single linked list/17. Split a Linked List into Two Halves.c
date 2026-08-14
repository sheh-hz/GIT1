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

void splitList(struct Node *head,
               struct Node **first,
               struct Node **second)
{
    if (head == NULL || head->next == NULL)
    {
        *first = head;
        *second = NULL;
        return;
    }

    struct Node *slow = head;
    struct Node *fast = head;

    /*
     * Move fast twice as quickly as slow.
     */
    while (fast->next != NULL &&
           fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    *first = head;
    *second = slow->next;

    // Break the list
    slow->next = NULL;
}

void printList(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

int main()
{
    struct Node *head = NULL;

    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 5);
    insertEnd(&head, 6);

    struct Node *first;
    struct Node *second;

    splitList(head, &first, &second);

    printf("First half: ");
    printList(first);

    printf("Second half: ");
    printList(second);

    return 0;
}
