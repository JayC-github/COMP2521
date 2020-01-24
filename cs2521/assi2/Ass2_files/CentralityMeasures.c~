// Centrality Measures ADT implementation
// COMP2521 Assignment 2

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "CentralityMeasures.h"
#include "Dijkstra.h"
#include "PQ.h"
#include "Graph.h"

NodeValues closenessCentrality(Graph g) {
    NodeValues nvs;
    
    // The number of nodes in the graph
    nvs.numNodes = GraphNumVertices(g);
    int numV = GraphNumVertices(g);
    
    // closeness centralirt for each vetex (n-1)^2 / (N-1)* sum of d(u,v)
    double *values = malloc(sizeof(double) * (size_t)numV);
    
    // y = N - 1, N denotes the number of nodes in the graph
    double y = numV - 1;
    
    for (int i = 0; i < numV; i++) {
        values[i] = 0;
    }
    
    // x = n - 1, y = N - 1, closeness = x^2/(y*d(u,v))
    for (int v = 0; v < numV; v++) {
        // n is the number of nodes that v can reach;
        int n;
        
        // sum of the length of the shortest paths 
        // between the node and all other reachable nodes
        double sum = 0;
        
        // 'ShortestPaths' structure with the source vertex v
        ShortestPaths sps = dijkstra(g, v);
        for (int i = 0; i < numV; i++) {
            // distance not equal 0 means reachable
            if (sps.dist[i] != 0) {
                sum = sum + sps.dist[i];
                n++;           
            }
        }        
        
        // x = n - 1, n is the number of nodes that v can reach;
        double x = n - 1;    
        
        values[v] = (x * x) / (y * sum);
    }
    
    nvs.values = values;
    return nvs;
}

NodeValues betweennessCentrality(Graph g) {
	NodeValues nvs = {0};
	return nvs;
}

NodeValues betweennessCentralityNormalised(Graph g) {
	NodeValues nvs = {0};
	return nvs;
}

void showNodeValues(NodeValues nvs) {
    for (i = 0; i < nvs.numNodes; i++) {
        printf("%d: %d", i, nvs.values[i]);
    }
}

void freeNodeValues(NodeValues nvs) {

}
