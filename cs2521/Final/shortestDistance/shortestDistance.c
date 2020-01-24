#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"
#include <limits.h>

int shortestDistance(Graph g, int src, int dest) {
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
    
    int d = dist[dest];
    free(visited);
    free(dist);
    QueueFree(q);
    
    if (d == INT_MAX) {
        return -1;
    } else {
        return d;
    }
    
}

















/*
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
    int dista = dist[dest];
    free(visited);
    free(dist);
    
    if (dista == INT_MAX) {
        return -1;
    }
    
    return dista;
*/

