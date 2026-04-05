/*Problem: Convert an infix expression to postfix notation using stack.

Input:
- Single line: infix expression (operands are single characters)

Output:
- Print the postfix expression

Example:
Input:
A+B*C

Output:
ABC*+

Explanation:
Operator precedence: * > +
Use stack to handle operator precedence and associativity*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
struct Stack
{
    char arr[MAX];
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
void push(struct Stack *s, char value)
{
    if (isFull(s))
    {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = value;
}
char pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
        return '\0'; // Return null character to indicate stack underflow
    }
    return s->arr[s->top--];
}
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}
int main()
{
    char infix[MAX], postfix[MAX];
    struct Stack s;
    initStack(&s);

    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0'; // Remove newline character

    int j = 0; // Index for postfix
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char token = infix[i];

        if ((token >= 'a' && token <= 'z') || (token >= 'A' && token <= 'Z'))
        {
            postfix[j++] = token; // Append operand to postfix
        }
        else if (token == '(')
        {
            push(&s, token); // Push '(' to stack
        }
        else if (token == ')')
        {
            while (!isEmpty(&s) && s.arr[s.top] != '(')
            {
                postfix[j++] = pop(&s); // Pop until '(' is found
            }
            pop(&s); // Pop the '(' from stack
        }
        else // Operator
        {
            while (!isEmpty(&s) && precedence(s.arr[s.top]) >= precedence(token))
            {
                postfix[j++] = pop(&s); // Pop operators with higher or equal precedence
            }
            push(&s, token); // Push current operator to stack
        }
    }

    while (!isEmpty(&s))
    {
        postfix[j++] = pop(&s); // Pop remaining operators
    }
    postfix[j] = '\0'; // Null-terminate the postfix string

    printf("Postfix expression: %s\n", postfix);
    return 0;
}
