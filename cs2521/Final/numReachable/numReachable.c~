#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

void depthFirstSearch(Graph g, int src, int visited[]) {
    int numV = GraphNumVertices(g);
    visited[src] = 1;
    for (int i = 0; i < numV; i++) {
        if (GraphIsAdjacent(g, src, i) && !visited[i]) {
            depthFirstSearch(g, i, visited);
        }
    }
}

int numReachable(Graph g, int src) {
    int numV = GraphNumVertices(g);
    int visited[numV];
    for (int i = 0; i < numV; i++) {
        visited[i] = 0;
    }
    
    depthFirstSearch(g, src, visited);
    
    int counter = 0;
    for (int i = 0; i <numV; i++) {
        if (visited[i]) {
            counter++;
        }
    }
    
    return counter;
} 


/*
void dfs(Graph g, int src, int visited[]) {
    int numV = GraphNumVertices(g);
    visited[src] = 1;
    for (int i = 0; i < numV; i++) {
        if (GraphIsAdjacent(g, src, i) && !visited[i]) {
            dfs(g, i, visited);    
        }
    }        
}

int numReachable(Graph g, int src) {
    int visited[20] = {0};
    int numV = GraphNumVertices(g);
    dfs(g, src, visited);
    int counter = 0;
    for (int i = 0; i < numV; i++) {
        if(visited[i]) {
            counter++;
        }
    }

    return counter;
}

*/

