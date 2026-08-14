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

struct Node* reverseAlternateK(struct Node *head, int k)
{
    struct Node *current = head;
    struct Node *prev = NULL;
    struct Node *next = NULL;

    int count = 0;

    // Reverse first k nodes
    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;

        count++;
    }

    // head becomes the tail of reversed block
    if (head != NULL)
        head->next = current;

    // Skip next k nodes
    count = 0;

    while (current != NULL && count < k - 1)
    {
        current = current->next;
        count++;
    }

    // Recursively reverse the next k nodes
    if (current != NULL)
        current->next = reverseAlternateK(
            current->next, k);

    return prev;
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
    insertEnd(&head, 7);
    insertEnd(&head, 8);

    int k = 2;

    head = reverseAlternateK(head, k);

    printf("Reversed: ");
    printList(head);

    return 0;
}
