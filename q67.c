#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_V 1000
#define MAX_STACK 1000

// Stack implementation
typedef struct {
    int items[MAX_STACK];
    int top;
} Stack;

void initStack(Stack* s) {
    s->top = -1;
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

bool isFull(Stack* s) {
    return s->top == MAX_STACK - 1;
}

void push(Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack is full!\n");
        return;
    }
    s->items[++(s->top)] = value;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return s->items[(s->top)--];
}

int peek(Stack* s) {
    if (isEmpty(s)) {
        return -1;
    }
    return s->items[s->top];
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
    // Add directed edge u -> v
    Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dfs(int node, Node* adj[], int vis[], Stack* st) {
    vis[node] = 1;
    
    // Traverse all adjacent nodes
    Node* temp = adj[node];
    while (temp != NULL) {
        if (!vis[temp->data]) {
            dfs(temp->data, adj, vis, st);
        }
        temp = temp->next;
    }
    
    // Push current node to stack after all descendants are processed
    push(st, node);
}

int* topologicalSort(int V, Node* adj[], int* returnSize) {
    int* vis = (int*)calloc(V, sizeof(int));
    Stack st;
    initStack(&st);
    
    // Perform DFS from each unvisited node
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs(i, adj, vis, &st);
        }
    }
    
    // Extract topological order from stack
    int* topo = (int*)malloc(V * sizeof(int));
    int index = 0;
    while (!isEmpty(&st)) {
        topo[index++] = pop(&st);
    }
    
    *returnSize = index;
    free(vis);
    return topo;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    
    // Create adjacency list
    Node* adj[MAX_V] = {NULL};
    
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);  // Directed edge u -> v
    }
    
    int resultSize;
    int* ans = topologicalSort(V, adj, &resultSize);
    
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