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

void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(Node *root)
{
    if (!root)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    Node *root = buildTree(arr, n);

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);

    return 0;
}