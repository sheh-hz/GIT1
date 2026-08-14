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

void swapKth(struct Node *head, int k)
{
    if (head == NULL)
        return;

    int length = 0;
    struct Node *temp = head;

    // Find length
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }

    // Invalid k
    if (k <= 0 || k > length)
        return;

    // Kth node from beginning
    struct Node *first = head;

    for (int i = 1; i < k; i++)
        first = first->next;

    // Kth node from end
    struct Node *second = head;

    for (int i = 1; i < length - k + 1; i++)
        second = second->next;

    // Swap data
    int tempData = first->data;
    first->data = second->data;
    second->data = tempData;
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

    int k = 2;

    printf("Original list: ");
    printList(head);

    swapKth(head, k);

    printf("Swapped list: ");
    printList(head);

    return 0;
}
