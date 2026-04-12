#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

Node *newNode(int val)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

typedef struct
{
    Node *arr[100000];
    int front, rear;
} Queue;

void initQueue(Queue *q)
{
    q->front = 0;
    q->rear = -1;
}

int isEmpty(Queue *q)
{
    return q->front > q->rear;
}

void enqueue(Queue *q, Node *node)
{
    q->arr[++q->rear] = node;
}

Node *dequeue(Queue *q)
{
    return q->arr[q->front++];
}

Node *buildTree(int arr[], int n)
{
    if (n == 0 || arr[0] == -1)
        return NULL;

    Queue q;
    initQueue(&q);

    Node *root = newNode(arr[0]);
    enqueue(&q, root);

    int i = 1;

    while (!isEmpty(&q) && i < n)
    {
        Node *curr = dequeue(&q);

        if (i < n && arr[i] != -1)
        {
            curr->left = newNode(arr[i]);
            enqueue(&q, curr->left);
        }
        i++;

        if (i < n && arr[i] != -1)
        {
            curr->right = newNode(arr[i]);
            enqueue(&q, curr->right);
        }
        i++;
    }

    return root;
}

int height(Node *root)
{
    if (!root)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return (left > right ? left : right) + 1;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node *root = buildTree(arr, n);

    printf("%d", height(root));

    return 0;
}