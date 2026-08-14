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

struct Node* merge(struct Node *a, struct Node *b)
{
    if (a == NULL)
        return b;

    if (b == NULL)
        return a;

    struct Node *result;

    if (a->data <= b->data)
    {
        result = a;
        result->next = merge(a->next, b);
    }
    else
    {
        result = b;
        result->next = merge(a, b->next);
    }

    return result;
}

void split(struct Node *head,
           struct Node **front,
           struct Node **back)
{
    struct Node *slow = head;
    struct Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;

        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = head;
    *back = slow->next;

    slow->next = NULL;
}

struct Node* mergeSort(struct Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    struct Node *front;
    struct Node *back;

    // Split list into two halves
    split(head, &front, &back);

    // Sort both halves
    front = mergeSort(front);
    back = mergeSort(back);

    // Merge sorted halves
    return merge(front, back);
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

    insertEnd(&head, 2);
    insertEnd(&head, 3);
    insertEnd(&head, 1);
    insertEnd(&head, 7);
    insertEnd(&head, 5);

    printf("Original list: ");
    printList(head);

    head = mergeSort(head);

    printf("Sorted list: ");
    printList(head);

    return 0;
}
