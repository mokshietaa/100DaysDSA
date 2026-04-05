#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;
typedef struct
{
    Node *front;
    Node *rear;
    int size;
} Deque;
Deque *createDeque()
{
    Deque *dq = (Deque *)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    dq->size = 0;
    return dq;
}
void push_front(Deque *dq, int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = val;
    node->prev = NULL;
    node->next = dq->front;

    if (dq->front != NULL)
        dq->front->prev = node;
    else
        dq->rear = node;

    dq->front = node;
    dq->size++;
}

void push_back(Deque *dq, int val)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    node->prev = dq->rear;

    if (dq->rear != NULL)
        dq->rear->next = node;
    else
        dq->front = node;

    dq->rear = node;
    dq->size++;
}

void pop_front(Deque *dq)
{
    if (dq->front == NULL)
        return;

    Node *temp = dq->front;
    dq->front = dq->front->next;

    if (dq->front != NULL)
        dq->front->prev = NULL;
    else
        dq->rear = NULL;

    free(temp);
    dq->size--;
}

void pop_back(Deque *dq)
{
    if (dq->rear == NULL)
        return;

    Node *temp = dq->rear;
    dq->rear = dq->rear->prev;

    if (dq->rear != NULL)
        dq->rear->next = NULL;
    else
        dq->front = NULL;

    free(temp);
    dq->size--;
}

int front(Deque *dq)
{
    if (dq->front == NULL)
        return -1;
    return dq->front->data;
}

int back(Deque *dq)
{
    if (dq->rear == NULL)
        return -1;
    return dq->rear->data;
}

bool empty(Deque *dq)
{
    return dq->size == 0;
}

int size(Deque *dq)
{
    return dq->size;
}

void clear(Deque *dq)
{
    while (!empty(dq))
    {
        pop_front(dq);
    }
}

void reverse(Deque *dq)
{
    Node *curr = dq->front;
    Node *temp = NULL;

    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }

    if (temp != NULL)
    {
        dq->rear = dq->front;
        dq->front = temp->prev;
    }
}

void printDeque(Deque *dq)
{
    Node *temp = dq->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    Deque *dq = createDeque();

    push_back(dq, 10);
    push_front(dq, 20);
    push_back(dq, 30);

    printDeque(dq); // 20 10 30
    printf("\n");

    pop_front(dq);
    printDeque(dq); // 10 30
    printf("\n");

    printf("%d\n", front(dq)); // 10
    printf("%d\n", back(dq));  // 30
    printf("%d\n", size(dq));  // 2

    clear(dq);
    printf("%d\n", empty(dq)); // 1

    return 0;
}