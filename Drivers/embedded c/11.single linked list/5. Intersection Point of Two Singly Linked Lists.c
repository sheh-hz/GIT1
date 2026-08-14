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

int getLength(struct Node *head)
{
    int count = 0;

    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}

struct Node* findIntersection(struct Node *headA,
                              struct Node *headB)
{
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    int diff;

    if (lenA > lenB)
    {
        diff = lenA - lenB;

        while (diff--)
            headA = headA->next;
    }
    else
    {
        diff = lenB - lenA;

        while (diff--)
            headB = headB->next;
    }

    while (headA != NULL && headB != NULL)
    {
        if (headA == headB)
            return headA;

        headA = headA->next;
        headB = headB->next;
    }

    return NULL;
}

int main()
{
    struct Node *common1 = newNode(3);
    struct Node *common2 = newNode(4);

    common1->next = common2;

    struct Node *headA = newNode(1);
    headA->next = newNode(2);
    headA->next->next = common1;

    struct Node *headB = newNode(5);
    headB->next = common1;

    struct Node *result = findIntersection(headA, headB);

    if (result != NULL)
        printf("Intersection found at node with data: %d\n",
               result->data);
    else
        printf("No intersection\n");

    return 0;
}
