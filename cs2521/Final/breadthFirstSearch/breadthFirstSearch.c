
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

void breadthFirstSearch(Graph g, int src) {
    int numV = GraphNumVertices(g);
    int visited[numV];
    for (int i = 0; i < numV; i++) {
        visited[i] = 0;
    }
    
    visited[src] = 1;
    Queue q = QueueNew();
    QueueEnqueue(q, src);
    while (!QueueIsEmpty(q)) {
        Vertex v = QueueDequeue(q);
        printf("%d ", v);
        for (int w =0; w< numV; w++) {
            if(GraphIsAdjacent(g, v, w) && !visited[w]) {
                visited[w] = 1;
                QueueEnqueue(q, w);
            }
        
        }
    }
    
    QueueFree(q);
}


/*
    int numV = GraphNumVertices(g);
    int visited[numV];
    for (int i = 0; i < numV; i++) {
        visited[i] = 0;
    }
    
    visited[src] = 1;
    Queue q = QueueNew();    
    QueueEnqueue(q, src);
    
    while (!QueueIsEmpty(q)) {
        Vertex v = QueueDequeue(q);
        printf("%d ", v);
        
        for (int j = 0; j < numV; j++) {
            if (GraphIsAdjacent(g, v, j) && !visited[j]) {
                visited[j] = 1;
                QueueEnqueue(q, j);
            }
        }
    
    }
    
    QueueFree(q);
*/
