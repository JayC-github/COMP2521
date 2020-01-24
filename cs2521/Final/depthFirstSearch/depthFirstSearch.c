
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"


int visited[20] = {0};
void depthFirstSearch(Graph g, int src) {
    int numV = GraphNumVertices(g);
    printf("%d ", src);
    visited[src] = 1;
    for (int i = 0; i < numV; i++) {
        if (GraphIsAdjacent(g, src, i) && !visited[i]) {
            depthFirstSearch(g, i);
        }
    }
} 


















/*
    int numV = GraphNumVertices(g);
    visited[src] = 1;
    printf("%d ", src);         
    
    for (int i = 0; i < numV; i++) {
        if (GraphIsAdjacent(g, src, i) && !visited[i]) {
            depthFirstSearch(g, i);
        }
    }
*/    



/*
    int numV = GraphNumVertices(g);
    visited[src] = 1;
    if(visited == NULL) {
        return;
    }
    printf("%d ", src);
    for (int i = 0; i < numV; i++) {
        if (GraphIsAdjacent(g, src, i) && visited[i] == 0) {
            visited[i] = 1;
            depthFirstSearch(g, i);
        }
    }
*/    
