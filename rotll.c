/*Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.
Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k
Output:
- Print the linked list elements after rotation, space-separated
Example:
Input:
5
10 20 30 40 50
2
Output:
40 50 10 20 30
Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.*/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Node *insertion(struct Node *head, int data)
{
    struct Node *newNode = createNode(data);

    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }

    struct Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;

    return head;
}
struct Node *rotateRight(struct Node *head, int k)
{
    if (head == NULL || head->next == head || k == 0)
        return head;

    struct Node *temp = head;
    int length = 1;

    while (temp->next != head)
    {
        temp = temp->next;
        length++;
    }

    temp->next = head; // Connect last node to head

    k = k % length; // Handle cases where k >= length
    int stepsToNewHead = length - k;

    temp = head;
    for (int i = 0; i < stepsToNewHead - 1; i++)
    {
        temp = temp->next;
    }

    struct Node *newHead = temp->next; // New head after rotation
    temp->next = NULL; // Break the circular link

    return newHead;
}
void traverse(struct Node *head)
{
    if (head == NULL)
        return;

    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    int n, x, k;
    struct Node *head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        head = insertion(head, x);
    }

    scanf("%d", &k);

    head = rotateRight(head, k);
    traverse(head);

    return 0;
}