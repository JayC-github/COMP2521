// Graph.c ... implementation of Graph ADT
// Written by John Shepherd, May 2013

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Graph.h"
#include "Queue.h"

// graph representation (adjacency matrix)
typedef struct GraphRep {
	int nV;		 // #vertices
	int nE;		 // #edges
	int **edges; // matrix of weights (0 == no edge)
} GraphRep;

// check validity of Vertex
int validV (Graph g, Vertex v)
{
	return (g != NULL && v >= 0 && v < g->nV);
}

// make an edge
static Edge mkEdge (Graph g, Vertex v, Vertex w)
{
	assert (g != NULL && validV (g, v) && validV (g, w));
	Edge new = {v, w}; // struct assignment
	return new;
}

// insert an Edge
// - sets (v,w) and (w,v)
void insertEdge (Graph g, Vertex v, Vertex w, int wt)
{
	assert (g != NULL && validV (g, v) && validV (g, w));

	if (g->edges[v][w] != 0 && g->edges[w][v] != 0)
		// an edge already exists; do nothing.
		return;

	g->edges[v][w] = wt;
	g->edges[w][v] = wt;
	g->nE++;
}

// remove an Edge
// - unsets (v,w) and (w,v)
void removeEdge (Graph g, Vertex v, Vertex w)
{
	assert (g != NULL && validV (g, v) && validV (g, w));
	if (g->edges[v][w] == 0 && g->edges[w][v] == 0)
		// an edge doesn't exist; do nothing.
		return;

	g->edges[v][w] = 0;
	g->edges[w][v] = 0;
	g->nE--;
}

// create an empty graph
Graph newGraph (int nV)
{
	assert (nV > 0);

	GraphRep *new = malloc (sizeof *new);
	assert (new != NULL);
	*new = (GraphRep){ .nV = nV, .nE = 0 };

	new->edges = calloc ((size_t) nV, sizeof (int *));
	assert (new->edges != NULL);
	for (int v = 0; v < nV; v++) {
		new->edges[v] = calloc ((size_t) nV, sizeof (int));
		assert (new->edges[v] != 0);
	}

	return new;
}

// free memory associated with graph
void dropGraph (Graph g)
{
	assert (g != NULL);
	for (int v = 0; v < g->nV; v++)
		free (g->edges[v]);
	free (g->edges);
	free (g);
}

// display graph, using names for vertices
void showGraph (Graph g, char **names)
{
	assert (g != NULL);
	printf ("#vertices=%d, #edges=%d\n\n", g->nV, g->nE);
	int v, w;
	for (v = 0; v < g->nV; v++) {
		printf ("%d %s\n", v, names[v]);
		for (w = 0; w < g->nV; w++) {
			if (g->edges[v][w]) {
				printf ("\t%s (%d)\n", names[w], g->edges[v][w]);
			}
		}
		printf ("\n");
	}
}

///////////////////////////////////////////////////////////////////////////////
// find a path between two vertices using breadth-first traversal  // queue
// only allow edges whose weight is less than "max"
int findPath (Graph g, Vertex src, Vertex dest, int max, int *path)
{
     
    // todo list for BFS 
    Queue q = newQueue();    
    
    // array of visiting order
    int *visited = malloc((size_t)g->nV * sizeof(int));
    if (visited == NULL) {
        fprintf(stderr, "memory allocated fail.");
        abort();
    }
    
    // for all the verticies in the graph make them non visited
    int i;
    for (i = 0; i < g->nV; i++) {
        visited[i] = -1;
    }
    
    // found = false until the vertex == dest
    int found = 0;
    visited[src] = src;
    QueueJoin (q, src);
    
    // q is not empty && path not found  
    while (!found && !QueueIsEmpty (q)) {
            
        Vertex v = QueueLeave (q);
        if (v == dest) {
            found = 1;
        } else {
            Vertex w = 0;
            while (w < g->nV) {    
                
                if (g->edges[v][w] > 0 
                &&  g->edges[v][w] < max 
                && visited[w] == -1) {
                    visited[w] = v;
                    QueueJoin (q, w); 
                }          
                
                w++;
            }
        }
    
    }
    
    // path not found
    if (!found) { // visited[dest] == -1
        free(visited);
        dropQueue(q);
        return 0;
    } else {
    
    // find the length of the path from src to dest 
    // put the path into the path array;    
        int length = 1;
        int check = dest;
        while (check != src) {
            check = visited[check];
            length++;
        }
        
        int j = length - 1;
        check = dest;
        while (j >= 0) {
            path[j] = check;
            check = visited[check];
            j--;
        }
        
        free(visited);
        dropQueue(q);
        return length;
    
    }
  
}
