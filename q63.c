#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_V 1000

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

void dfs(int node, Node* adj[], int vis[], int* ls, int* index) {
    vis[node] = 1;
    ls[(*index)++] = node;
    
    // Traverse adjacency list of current node
    Node* temp = adj[node];
    while (temp != NULL) {
        if (!vis[temp->data]) {
            dfs(temp->data, adj, vis, ls, index);
        }
        temp = temp->next;
    }
}

int* dfsOfGraph(int V, Node* adj[], int* returnSize) {
    int* vis = (int*)calloc(V, sizeof(int));
    int* ls = (int*)malloc(V * sizeof(int));
    int index = 0;
    int start = 0;
    
    dfs(start, adj, vis, ls, &index);
    
    *returnSize = index;
    free(vis);
    return ls;
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
    int* ans = dfsOfGraph(V, adj, &resultSize);
    
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