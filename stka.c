/*Problem: Implement a stack data structure using an array with the following operations: push, pop, and display.

Input:
- First line: integer n (number of operations)
- Next n lines: operation type and value (if applicable)
  - 1 value: push value
  - 2: pop
  - 3: display

Output:
- For display: print stack elements from top to bottom
- For pop: print popped element or 'Stack Underflow'

Example:
Input:
5
1 10
1 20
3
2
3

Output:
20 10
20
10*/
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
        return -1; // Return -1 to indicate stack underflow
    }
    return s->arr[s->top--];
}
void display(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty\n");
        return;
    }
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}
int main()
{
    struct Stack s;
    initStack(&s);
    int n, operation, value;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &operation);
        if (operation == 1)
        {
            scanf("%d", &value);
            push(&s, value);
        }
        else if (operation == 2)
        {
            int poppedValue = pop(&s);
            if (poppedValue != -1)
                printf("%d\n", poppedValue);
        }
        else if (operation == 3)
        {
            display(&s);
        }
    }
    return 0;
}
