#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    // Create array of pointers for each vertex (1-based indexing)
    Node** adj = (Node**)malloc((n + 1) * sizeof(Node*));
    for (int i = 1; i <= n; i++) {
        adj[i] = NULL;
    }
    
    // Read edges and build adjacency list
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        
        // Add v to u's list
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->vertex = v;
        newNode->next = adj[u];
        adj[u] = newNode;
        
        // Add u to v's list (for undirected graph)
        newNode = (Node*)malloc(sizeof(Node));
        newNode->vertex = u;
        newNode->next = adj[v];
        adj[v] = newNode;
    }
    
    // Print adjacency list
    for (int i = 1; i <= n; i++) {
        printf("Vertex %d: ", i);
        Node* current = adj[i];
        while (current != NULL) {
            printf("%d ", current->vertex);
            current = current->next;
        }
        printf("\n");
    }
    
    // Free memory
    for (int i = 1; i <= n; i++) {
        Node* current = adj[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(adj);
    
    return 0;
}