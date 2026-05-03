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
    // Add edge u -> v (directed)
    Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

bool dfsCheck(int node, Node* adj[], int vis[], int pathVis[]) {
    vis[node] = 1;
    pathVis[node] = 1;
    
    // Traverse all adjacent nodes
    Node* temp = adj[node];
    while (temp != NULL) {
        int it = temp->data;
        
        if (!vis[it]) {
            if (dfsCheck(it, adj, vis, pathVis))
                return true;
        }
        else if (pathVis[it]) {
            return true;
        }
        
        temp = temp->next;
    }
    
    pathVis[node] = 0;
    return false;
}

bool isCyclic(int V, Node* adj[]) {
    int* vis = (int*)calloc(V, sizeof(int));
    int* pathVis = (int*)calloc(V, sizeof(int));
    
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfsCheck(i, adj, vis, pathVis)) {
                free(vis);
                free(pathVis);
                return true;
            }
        }
    }
    
    free(vis);
    free(pathVis);
    return false;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    
    // Create adjacency list
    Node* adj[MAX_V] = {NULL};
    
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);  // Note: Only one direction added for directed graph
    }
    
    bool ans = isCyclic(V, adj);
    
    if (ans) 
        printf("True");
    else 
        printf("False");
    
    // Free allocated memory
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