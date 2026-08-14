#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* newNode(int data)
{
    struct Node *node = malloc(sizeof(struct Node));

    node->data = data;
    node->next = NULL;

    return node;
}

struct Node* partition(struct Node *head, int x)
{
    struct Node *lessHead = NULL;
    struct Node *lessTail = NULL;

    struct Node *greaterHead = NULL;
    struct Node *greaterTail = NULL;

    struct Node *current = head;

    while (current != NULL)
    {
        struct Node *next = current->next;

        current->next = NULL;

        if (current->data < x)
        {
            if (lessHead == NULL)
            {
                lessHead = current;
                lessTail = current;
            }
            else
            {
                lessTail->next = current;
                lessTail = current;
            }
        }
        else
        {
            if (greaterHead == NULL)
            {
                greaterHead = current;
                greaterTail = current;
            }
            else
            {
                greaterTail->next = current;
                greaterTail = current;
            }
        }

        current = next;
    }

    if (lessHead == NULL)
        return greaterHead;

    lessTail->next = greaterHead;

    return lessHead;
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
    struct Node *head = newNode(3);

    head->next = newNode(5);
    head->next->next = newNode(7);
    head->next->next->next = newNode(5);
    head->next->next->next->next = newNode(9);
    head->next->next->next->next->next = newNode(2);
    head->next->next->next->next->next->next = newNode(1);

    int x = 5;

    printf("Original list: ");
    printList(head);

    head = partition(head, x);

    printf("Reordered list: ");
    printList(head);

    return 0;
}
