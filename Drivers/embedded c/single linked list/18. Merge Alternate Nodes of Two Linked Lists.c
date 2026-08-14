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

struct Node* mergeAlternate(struct Node *list1,
                            struct Node *list2)
{
    struct Node *head = NULL;
    struct Node *tail = NULL;

    while (list1 != NULL || list2 != NULL)
    {
        // Take node from List 1
        if (list1 != NULL)
        {
            struct Node *node = list1;
            list1 = list1->next;

            node->next = NULL;

            if (head == NULL)
            {
                head = node;
                tail = node;
            }
            else
            {
                tail->next = node;
                tail = node;
            }
        }

        // Take node from List 2
        if (list2 != NULL)
        {
            struct Node *node = list2;
            list2 = list2->next;

            node->next = NULL;

            if (head == NULL)
            {
                head = node;
                tail = node;
            }
            else
            {
                tail->next = node;
                tail = node;
            }
        }
    }

    return head;
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
    struct Node *list1 = NULL;
    struct Node *list2 = NULL;

    insertEnd(&list1, 9);
    insertEnd(&list1, 7);
    insertEnd(&list1, 5);

    insertEnd(&list2, 10);
    insertEnd(&list2, 8);
    insertEnd(&list2, 6);

    struct Node *result =
        mergeAlternate(list1, list2);

    printf("Merged list: ");
    printList(result);

    return 0;
}
