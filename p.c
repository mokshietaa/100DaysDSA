/*Problem: Evaluate Postfix Expression - Implement using linked list with dynamic memory allocation.

Input:
- Postfix expression with operands and operators

Output:
- Print the integer result

Example:
Input:
2 3 1 * + 9 -

Output:
-4

Explanation:
Use stack to store operands, apply operators by popping operands, push result back. Final stack top is result.*/
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
struct Node *push(struct Node *top, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = top;
    return newNode;
}
int pop(struct Node **top)
{
    if (*top == NULL)
    {
        printf("Stack Underflow\n");
        return -1; // Return -1 to indicate stack underflow
    }
    struct Node *temp = *top;
    int data = temp->data;
    *top = (*top)->next;
    free(temp);
    return data;
}
int evaluatePostfix(char *expression)
{
    struct Node *stack = NULL;
    for (int i = 0; expression[i] != '\0'; i++)
    {
        char ch = expression[i];
        if (ch >= '0' && ch <= '9')
        {
            int operand = ch - '0';
            stack = push(stack, operand);
        }
        else
        {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result;
            switch (ch)
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            default:
                printf("Invalid operator: %c\n", ch);
                return -1; // Return -1 to indicate invalid operator
            }
            stack = push(stack, result);
        }
    }
    return pop(&stack); // Final result
}
int main()
{
    char expression[100];
    printf("Enter postfix expression: ");
    fgets(expression, sizeof(expression), stdin);
    int result = evaluatePostfix(expression);
    if (result != -1)
    {
        printf("Result: %d\n", result);
    }
    return 0;
}
