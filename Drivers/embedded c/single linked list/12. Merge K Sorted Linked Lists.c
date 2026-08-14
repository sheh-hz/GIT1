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

struct Node* mergeTwoLists(struct Node *a,
                           struct Node *b)
{
    if (a == NULL)
        return b;

    if (b == NULL)
        return a;

    struct Node *result;

    if (a->data <= b->data)
    {
        result = a;
        result->next = mergeTwoLists(a->next, b);
    }
    else
    {
        result = b;
        result->next = mergeTwoLists(a, b->next);
    }

    return result;
}

struct Node* mergeKLists(struct Node *lists[], int k)
{
    if (k == 0)
        return NULL;

    struct Node *result = lists[0];

    for (int i = 1; i < k; i++)
    {
        result = mergeTwoLists(result, lists[i]);
    }

    return result;
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
    struct Node *list3 = NULL;

    insertEnd(&list1, 10);
    insertEnd(&list1, 20);
    insertEnd(&list1, 50);

    insertEnd(&list2, 30);
    insertEnd(&list2, 40);
    insertEnd(&list2, 60);

    insertEnd(&list3, 10);
    insertEnd(&list3, 70);
    insertEnd(&list3, 100);

    struct Node *lists[] =
    {
        list1,
        list2,
        list3
    };

    int k = 3;

    struct Node *result = mergeKLists(lists, k);

    printf("Merged list: ");
    printList(result);

    return 0;
}
