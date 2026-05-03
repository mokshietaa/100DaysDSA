#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_V 1000

// Queue implementation
typedef struct {
    int items[MAX_V];
    int front;
    int rear;
} Queue;

void initQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(Queue* q) {
    return q->front == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_V - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int item = q->items[q->front];
    q->front++;
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return item;
}

// Adjacency list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* adj[], int u, int v) {
    // Add edge u -> v
    Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
    
    // Add edge v -> u (for undirected graph)
    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

int* bfsOfGraph(int V, Node* adj[], int* returnSize) {
    int* vis = (int*)calloc(V, sizeof(int));
    int* bfs = (int*)malloc(V * sizeof(int));
    Queue q;
    initQueue(&q);
    
    vis[0] = 1;
    enqueue(&q, 0);
    int index = 0;
    
    while (!isEmpty(&q)) {
        int node = dequeue(&q);
        bfs[index++] = node;
        
        // Traverse adjacency list of current node
        Node* temp = adj[node];
        while (temp != NULL) {
            if (!vis[temp->data]) {
                vis[temp->data] = 1;
                enqueue(&q, temp->data);
            }
            temp = temp->next;
        }
    }
    
    *returnSize = index;
    free(vis);
    return bfs;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    
    // Create adjacency list
    Node* adj[MAX_V] = {NULL};
    
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }
    
    int resultSize;
    int* ans = bfsOfGraph(V, adj, &resultSize);
    
    for (int i = 0; i < resultSize; i++) {
        printf("%d ", ans[i]);
    }
    
    // Free allocated memory
    free(ans);
    for (int i = 0; i < V; i++) {
        Node* temp = adj[i];
        while (temp != NULL) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    
    return 0;
}