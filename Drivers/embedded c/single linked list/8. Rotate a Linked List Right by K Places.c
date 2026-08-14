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

struct Node* rotateRight(struct Node *head, int k)
{
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    // Find length and last node
    int length = 1;
    struct Node *tail = head;

    while (tail->next != NULL)
    {
        tail = tail->next;
        length++;
    }

    // Avoid unnecessary rotations
    k = k % length;

    if (k == 0)
        return head;

    // Make the list circular
    tail->next = head;

    // Find new tail
    int steps = length - k;

    struct Node *newTail = tail;

    for (int i = 0; i < steps; i++)
        newTail = newTail->next;

    // New head is after new tail
    struct Node *newHead = newTail->next;

    // Break the circular list
    newTail->next = NULL;

    return newHead;
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
    insertEnd(&head, 3);
    insertEnd(&head, 4);
    insertEnd(&head, 7);
    insertEnd(&head, 9);

    int k = 2;

    printf("Original list: ");
    printList(head);

    head = rotateRight(head, k);

    printf("Rotated list: ");
    printList(head);

    return 0;
}
