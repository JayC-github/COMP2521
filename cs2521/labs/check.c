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

int findPath (Graph g, Vertex src, Vertex dest, int max, int *path)
{
    Queue new = newQueue();
    int visited[] = malloc(sizeof(int) * (size_t)nVertices(g));
    if(visited == NULL) {
        fprintf(stderr, "memory malloc fail");
        abort();
    }
    
    int i;
    for (i = 0; i < (size_t)g->nv; i++) {
        visited[i] = -1;
    }
    
    
    QueueJoin (new, src);
    visited[src] = src;
    int found = 0; // found will = 0 until the vertex == dest
    while (!found && !QueueIsEmpty (new)) {
        Vertex v = QueueLeave (new);    
        if (v == dest) {
            found = 1;
        } else {
            Vertex w = 0;
            while (w < g->nv) {
                if(g->edges[v][w] > 0 && g->edges[v][w] < max && visited[w] == -1)
                    visited[w] = v;
                    QueueJoin(new, w)
               
                w++;
            }
        
        }
    }
    
    
}

