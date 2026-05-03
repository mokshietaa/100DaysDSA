#include <stdio.h>
#include <stdlib.h>

// Structure for adjacency list node
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// Structure for adjacency list
struct AdjList {
    struct AdjListNode* head;
};

// Structure for graph
struct Graph {
    int V;
    struct AdjList* array;
};

// Create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    
    for (int i = 0; i < V; i++) {
        graph->array[i].head = NULL;
    }
    
    return graph;
}

// Add edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

// Queue implementation
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

int dequeue(struct Queue* queue) {
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

// Topological sort function
int* topoSort(struct Graph* graph, int V) {
    int* indegree = (int*)calloc(V, sizeof(int));
    int* topo = (int*)malloc(V * sizeof(int));
    int topoIndex = 0;
    
    // Calculate indegree for all vertices
    for (int i = 0; i < V; i++) {
        struct AdjListNode* current = graph->array[i].head;
        while (current != NULL) {
            indegree[current->dest]++;
            current = current->next;
        }
    }
    
    // Create a queue and enqueue all vertices with indegree 0
    struct Queue* q = createQueue(V);
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            enqueue(q, i);
        }
    }
    
    // Process the queue
    while (!isEmpty(q)) {
        int node = dequeue(q);
        topo[topoIndex++] = node;
        
        struct AdjListNode* current = graph->array[node].head;
        while (current != NULL) {
            indegree[current->dest]--;
            if (indegree[current->dest] == 0) {
                enqueue(q, current->dest);
            }
            current = current->next;
        }
    }
    
    free(indegree);
    free(q->array);
    free(q);
    
    return topo;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);
    
    struct Graph* graph = createGraph(V);
    
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }
    
    int* res = topoSort(graph, V);
    
    for (int i = 0; i < V; i++) {
        printf("%d ", res[i]);
    }
    
    // Free allocated memory
    free(res);
    for (int i = 0; i < V; i++) {
        struct AdjListNode* current = graph->array[i].head;
        while (current != NULL) {
            struct AdjListNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);
    
    return 0;
}