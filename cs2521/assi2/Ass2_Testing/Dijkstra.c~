// Dijkstra ADT implementation
// COMP2521 Assignment 2
// Some part learn from the COMP2521 slide

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#include "Dijkstra.h"
#include "PQ.h"
#include "Graph.h"

//#define INFINITY ~(1<<31)
// Helper function

// create a preNode include vertex V
static PredNode *newNode(Vertex v) {
    PredNode *new = malloc(sizeof(struct PredNode));
    new->v = v;
    new->next = NULL;
    return new;
}


// add the preNode to the end of a specific predecessor list
static void addNode(PredNode **pred, Vertex w, PredNode *new) {
    if (pred[w] == NULL) {
        pred[w] = new;    
    
    } else {
      
        PredNode *curr = pred[w];
        // loop till the end of a specific predecessor  lists
        while (curr->next != NULL) {    
            curr = curr->next;
        }
    
        curr->next = new;
    }
}

// delete predecessor list since find new pred which has shorter distance
static void deletelist(PredNode **pred, Vertex v) {
    // no predNode in the list
    if (pred[v] == NULL) {
        return;     
    // only one predNode in the list
    } else if (pred[v]->next == NULL) {
        PredNode *tmp = pred[v]; 
        free(tmp);
    // more than two preNodes in the list
    } else {
        // loop till the end of a specific predecessor  lists
        PredNode *curr = pred[v];
        PredNode *prev = pred[v];
        while (curr != NULL) {    
            curr = curr->next;
            free(prev);
            prev = curr;
        }
    }     
    pred[v] = NULL;
}


/////////////////////////////////////////////////////////////////////////////
ShortestPaths dijkstra(Graph g, Vertex src) {
	ShortestPaths sps;
	
	// the number of vertices in the graph
	sps.numNodes = GraphNumVertices(g);
	int numV = GraphNumVertices(g);
	
	// the source vertex
	sps.src = src;    
    
    // array of cost of shortest path from src
    int *dist = malloc((size_t)numV * sizeof(int));
       
    // array of predecessor in shortest path from src
    PredNode **pred = malloc((size_t)numV * sizeof(PredNode *));
    
    if (dist == NULL || pred == NULL) {
        fprintf(stderr, "memory allocated fail.");
        abort();
    }
    
    // create a priority queue pq for all unvisited vertices of G
    PQ pq = PQNew();
    
    // check if the vertex in the pq has been visited or not 
    // 0->not, 1->visited  
    int visited[numV];
    
    
    // initialise dist[] to all infinity, except dist[source] = 0
    dist[src] = 0;
    
    // for each vertex in the graph
    int i;
    for (i = 0; i < numV; i++) {
        if (i != src) {
            dist[i] = INT_MAX;
        }
        
        // initialise pred[] to all undefined; (-1)
        pred[i] = NULL;
        
        // initialise visited[] to all unvisited; (0)
        visited[i] = 0;
        
        // put all the vertices into the pq
        // creat an item with key is the vertex itself 
        // and value is the distance from src to this vertex  
        ItemPQ item;
        item.key = i;
        item.value = dist[i];
      
        PQAdd(pq, item);
    }
    
    // while the priority queue is not empty(still have unvisited vertex)
    while (!PQIsEmpty(pq)) {
        
        // find the vertices in the queue which has minimum 'value' (distance)  
        ItemPQ curr = PQDequeue(pq);    
        
        Vertex currV = curr.key; 
        int distV = curr.value; // dist[currV];
        
        // The vertex is moved from the priority queue, change to visited
        visited[currV] = 1;
        
        // Returns a list containing (destination vertex, weight) pairs for each
        // * outgoing  edge  from  vertex  'v'
        
        AdjList head = GraphOutIncident(g, currV);
        
        // for each neighbour adjacent to vertex currV;
        for (AdjList adj = head; adj != NULL; adj = adj->next) {
            // and also only v that are still in pq (visited[v] = 0)
            if (visited[adj->v] == 0) {
                Vertex w = adj->v;
                int weight = adj->weight;
                
                if ((distV + weight) < dist[w]) {
                    // dist[w] replace by the new shorter distance
                    dist[w] = distV + weight;
                    
                    // delete all the preNodes in the predecessor list of w
                    deletelist(pred, w);
                    
                    // creat a new preNode include current vertex v
                    PredNode *new = newNode(currV);
                    
                    // then add this node to the predecessor list of w
                    addNode(pred, w, new);
                    
                    // update a new item w with lower value(distance) replace
                    // the old one 
                    ItemPQ newItem;
                    newItem.key = w;
                    newItem.value = dist[w];
                    PQUpdate(pq, newItem);
                
                // the distance from v same with another path to Vertex w
                } else if ((distV + weight) == dist[w]) {
                    // creat a new preNode include vertex v
                    PredNode *new = newNode(currV);
                    
                    // then add this node to the predecessor list of w
                    addNode(pred, w, new);
                }              
            }
        }
    }
    
    // for vertex still have infinity distance, change to 0 (not connected)
    for (i = 0; i < numV; i++) {
        if (dist[i] == INT_MAX) {
            dist[i] = 0;
        }
    }
	
	sps.dist = dist;
	sps.pred = pred;
	PQFree(pq);
	
	return sps;
}

void showShortestPaths(ShortestPaths sps) {

}

void freeShortestPaths(ShortestPaths sps) {
    free(sps.dist);
    for (int i = 0; i < sps.numNodes; i++) {
        deletelist(sps.pred, i);
    }
    free(sps.pred);
}




