/*Problem: Implement push and pop operations on a stack and verify stack operations.

Input:
- First line: integer n
- Second line: n integers to push
- Third line: integer m (number of pops)

Output:
- Print remaining stack elements from top to bottom

Example:
Input:
5
10 20 30 40 50
2

Output:
30 20 10*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct Stack
{
    int arr[MAX];
    int top;
};

void initStack(struct Stack *s)
{
    s->top = -1;
}

int isFull(struct Stack *s)
{
    return s->top == MAX - 1;
}

int isEmpty(struct Stack *s)
{
    return s->top == -1;
}

void push(struct Stack *s, int value)
{
    if (isFull(s))
    {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = value;
}

int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->arr[s->top--];
}

int main()
{
    struct Stack s;
    initStack(&s);
    int n, m, value;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &value);
        push(&s, value);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        pop(&s);
    }
    if (isEmpty(&s))
    {
        printf("Stack is empty\n");
    }
    else
    {
        for (int i = s.top; i >= 0; i--)
        {
            printf("%d ", s.arr[i]);
        }
        printf("\n");
    }
    return 0;
}