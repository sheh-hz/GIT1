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

struct Node* reversePairs(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct Node *first = head;
    struct Node *second = head->next;

    // Reverse first pair
    first->next = reversePairs(second->next);
    second->next = first;

    // Second node becomes new head
    return second;
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

    printf("Original list: ");
    printList(head);

    head = reversePairs(head);

    printf("Reversed in pairs: ");
    printList(head);

    return 0;
}
