#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void insertEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);

    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

struct Node* reverse(struct Node *head)
{
    struct Node *prev = NULL;
    struct Node *current = head;
    struct Node *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

struct Node* addLists(struct Node *head1, struct Node *head2)
{
    // Reverse both lists so addition starts from least significant digit
    head1 = reverse(head1);
    head2 = reverse(head2);

    struct Node *result = NULL;
    struct Node *tail = NULL;

    int carry = 0;

    while (head1 != NULL || head2 != NULL || carry != 0)
    {
        int sum = carry;

        if (head1 != NULL)
        {
            sum += head1->data;
            head1 = head1->next;
        }

        if (head2 != NULL)
        {
            sum += head2->data;
            head2 = head2->next;
        }

        int digit = sum % 10;
        carry = sum / 10;

        struct Node *node = createNode(digit);

        if (result == NULL)
        {
            result = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }

    // Result was created in reverse order
    result = reverse(result);

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

    insertEnd(&list1, 8);
    insertEnd(&list1, 7);
    insertEnd(&list1, 9);
    insertEnd(&list1, 2);

    insertEnd(&list2, 2);
    insertEnd(&list2, 1);
    insertEnd(&list2, 2);
    insertEnd(&list2, 3);

    struct Node *result = addLists(list1, list2);

    printf("Result: ");
    printList(result);

    return 0;
}
