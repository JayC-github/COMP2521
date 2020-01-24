
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Graph.h"
#include "Queue.h"


int furthestReachable(Graph g, int src) {
    int numV = GraphNumVertices(g);
    int *visited = malloc(sizeof(int) * numV);
    int *dist = malloc(sizeof(int) * numV);
    
    for (int i = 0; i < numV; i++) {
        visited[i] = 0;
        dist[i] = INT_MAX;
    }
    
    visited[src] = 1;
    dist[src] = 0;
    Queue q = QueueNew();
    QueueEnqueue(q, src);
    while (!QueueIsEmpty(q)) {
        Vertex v = QueueDequeue(q);
        visited[v] = 1;
        for (int w = 0; w < numV; w++) {
            if (GraphIsAdjacent(g, v, w) && !visited[w]) {
                if (dist[v] + 1 <  dist[w]) {
                    dist[w] = 1 + dist[v];
                    QueueEnqueue(q, w);
                }
            }
        }
    }
    
    int max = 0;
    for (int i = numV - 1; i >= 0; i--) {
        if (dist[i] > max && dist[i] != INT_MAX) {
            max = dist[i];
        }
    }
    
    int index = 0;
    for (int i = numV - 1; i >= 0; i--) {
        if (dist[I] == max) {
            index = i;
            break;
        }
    }
    
    free(visited);
    free(dist);
    QueueFree(q);
    return index;
    
}


/*
int shortestDistance(Graph g, int src) {
    int numV = GraphNumVertices(g);
    int *visited = malloc(sizeof(int) * numV);
    int *dist = malloc(sizeof(int) * numV);
    
    // intialize the visited and array
    for (int i = 0; i < numV; i++) {
        visited[i] = 0; 
        dist[i] = INT_MAX;
    }
    
    visited[src] = 1;
    dist[src] = 0;
    Queue q = QueueNew();
    QueueEnqueue(q, src);
    
    while(!QueueIsEmpty(q)) {
        Vertex v = QueueDequeue(q);
        visited[v] = 1;
        for (int w = 0; w < numV; w++) {
            if (GraphIsAdjacent(g, v, w) && !visited[w]) {
                if (dist[v] + 1 < dist[w]) {
                    dist[w] = 1 + dist[v];
                }
                QueueEnqueue(q, w);
            }
        }
    }
    
    QueueFree(q);
    free(visited);
    
    int max = 0;
    for (int i = numV - 1; i >= 0; i--) {
        if (dist[i] > max && dist[i] != INT_MAX) {
            max = dist[i];
        }
    }
    
    int index;
    for (int i = numV - 1; i >= 0; i--) {
        if (dist[i] == max) {
            index = i;
            break;
        }
    }
    
    free(dist); 
    return index;
}
*/
