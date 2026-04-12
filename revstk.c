/*Problem Statement:
Given a queue of integers, reverse the queue using a stack.
Input Format:
- First line contains integer N
- Second line contains N space-separated integers
Output Format:
- Print the reversed queue
Example:
Input:
5
10 20 30 40 50
Output:
50 40 30 20 10*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

// Queue
typedef struct
{
    int arr[MAX];
    int front, rear;
} Queue;

// Stack
typedef struct
{
    int arr[MAX];
    int top;
} Stack;

void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
}

int isQueueEmpty(Queue *q)
{
    return q->front > q->rear;
}

void enqueue(Queue *q, int x)
{
    q->arr[++q->rear] = x;
}

int dequeue(Queue *q)
{
    if (isQueueEmpty(q))
        return -1;
    return q->arr[q->front++];
}

// Stack functions
void initStack(Stack *s)
{
    s->top = -1;
}

int isStackEmpty(Stack *s)
{
    return s->top == -1;
}

void push(Stack *s, int x)
{
    s->arr[++s->top] = x;
}

int pop(Stack *s)
{
    if (isStackEmpty(s))
        return -1;
    return s->arr[s->top--];
}

int main()
{
    int n, x;
    scanf("%d", &n);

    Queue q;
    Stack s;

    initQueue(&q);
    initStack(&s);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(&q, x);
    }

    // Queue → Stack
    while (!isQueueEmpty(&q))
    {
        push(&s, dequeue(&q));
    }

    // Stack → Queue
    while (!isStackEmpty(&s))
    {
        enqueue(&q, pop(&s));
    }

    // Print reversed queue
    while (!isQueueEmpty(&q))
    {
        printf("%d ", dequeue(&q));
    }

    return 0;
}