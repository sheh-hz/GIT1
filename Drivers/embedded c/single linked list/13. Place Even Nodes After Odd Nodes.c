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

struct Node* reorderByParity(struct Node *head)
{
    struct Node *oddHead = NULL;
    struct Node *oddTail = NULL;

    struct Node *evenHead = NULL;
    struct Node *evenTail = NULL;

    struct Node *current = head;

    while (current != NULL)
    {
        struct Node *next = current->next;

        current->next = NULL;

        if (current->data % 2 != 0)
        {
            // Odd node
            if (oddHead == NULL)
            {
                oddHead = current;
                oddTail = current;
            }
            else
            {
                oddTail->next = current;
                oddTail = current;
            }
        }
        else
        {
            // Even node
            if (evenHead == NULL)
            {
                evenHead = current;
                evenTail = current;
            }
            else
            {
                evenTail->next = current;
                evenTail = current;
            }
        }

        current = next;
    }

    // No odd nodes
    if (oddHead == NULL)
        return evenHead;

    // Connect odd list with even list
    oddTail->next = evenHead;

    return oddHead;
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

    printf("Original list: ");
    printList(head);

    head = reorderByParity(head);

    printf("Reordered list: ");
    printList(head);

    return 0;
}
