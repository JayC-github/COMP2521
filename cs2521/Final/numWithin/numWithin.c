
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Graph.h"
#include "Queue.h"

int numWithin(Graph g, int src, int dist) {
    int numV = GraphNumVertices(g);
    int *visited = malloc(sizeof(int) * numV);
    int *dista = malloc(sizeof(int) * numV);
    
    // intialize the visited and array
    for (int i = 0; i < numV; i++) {
        visited[i] = 0; 
        dista[i] = INT_MAX;
    }
    
    visited[src] = 1;
    dista[src] = 0;
    Queue q = QueueNew();
    QueueEnqueue(q, src);
    
    while(!QueueIsEmpty(q)) {
        Vertex v = QueueDequeue(q);
        visited[v] = 1;
        for (int w = 0; w < numV; w++) {
            if (GraphIsAdjacent(g, v, w) && !visited[w]) {
                if (dista[v] + 1 < dista[w]) {
                    dista[w] = 1 + dista[v];
                }
                QueueEnqueue(q, w);
            }
        }
    }
    
    int total = 0;
    for (int i = 0; i < numV; i++) {
        if(dista[i] <= dist) {
            total++;
        }
    }
    
    QueueFree(q);
    free(visited);
    free(dista);
    
    
    return total;
}

