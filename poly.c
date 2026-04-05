/*Problem: Polynomial Using Linked List - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n (number of terms)
- Next n lines: two integers (coefficient and exponent)

Output:
- Print polynomial in standard form, e.g., 10x^4 + 20x^3 + 30x^2 + 40x + 50

Example:
Input:
5
10 4
20 3
30 2
40 1
50 0

Output:
10x^4 + 20x^3 + 30x^2 + 40x + 50

Explanation:
Each node stores coefficient and exponent. Traverse nodes to print polynomial in decreasing exponent order.*/
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int coeff;
    int exp;
    struct Node *next;
};
struct Node *createNode(int coeff, int exp)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}
struct Node *insertTerm(struct Node *head, int coeff, int exp)
{
    struct Node *newNode = createNode(coeff, exp);

    if (head == NULL || head->exp < exp)
    {
        newNode->next = head;
        return newNode;
    }

    struct Node *temp = head;
    while (temp->next != NULL && temp->next->exp > exp)
    {
        temp = temp->next;
    }

    if (temp->exp == exp)
    {
        temp->coeff += coeff;
        free(newNode);
    }
    else
    {
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
}
void printPolynomial(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    struct Node *head = NULL;
    int n, coeff, exp;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        head = insertTerm(head, coeff, exp);
    }

    printf("Polynomial: ");
    printPolynomial(head);

    return 0;
}
