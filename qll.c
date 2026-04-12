/*Problem Statement : Implement a Queue using a linked list supporting enqueue and dequeue operations.
Input Format : -First line contains integer N -
Next N lines contain queue operations
Output Format : -Print dequeued elements -
Print - 1 if dequeue is attempted on an empty queue*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *front, *rear;
} Queue;

void init(Queue *q)
{
    q->front = q->rear = NULL;
}

void enqueue(Queue *q, int x)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;

    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(Queue *q)
{
    if (q->front == NULL)
        return -1;

    Node *temp = q->front;
    int val = temp->data;

    q->front = q->front->next;
    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return val;
}

int main()
{
    int n, x;
    char op[20];

    Queue q;
    init(&q);

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%s", op);

        if (strcmp(op, "enqueue") == 0)
        {
            scanf("%d", &x);
            enqueue(&q, x);
        }
        else if (strcmp(op, "dequeue") == 0)
        {
            printf("%d\n", dequeue(&q));
        }
    }

    return 0;
}
