#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    // 1-based indexing for vertices
    int** adj = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; i++) {
        adj[i] = (int*)calloc((n + 1), sizeof(int));
    }
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // For undirected graph
    }
    
    // Free allocated memory
    for (int i = 0; i <= n; i++) {
        free(adj[i]);
    }
    free(adj);
    
    return 0;
}
