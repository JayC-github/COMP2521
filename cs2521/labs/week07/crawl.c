// crawl.c ... build a graph of part of the web
// Written by John Shepherd, September 2015
// Uses the cURL library and functions by Vincent Sanders
// <vince@kyllikki.org>

#include <ctype.h>
#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "graph.h"
#include "html.h"
#include "set.h"
#include "stack.h"
#include "url_file.h"
#include "queue.h"

#define BUFSIZE 1024

static void setFirstURL (char *, char *);

int main (int argc, char **argv)
{
	URL_FILE *handle;
	char buffer[BUFSIZE];
	char baseURL[BUFSIZE];
	char firstURL[BUFSIZE];
	char next[BUFSIZE];
	int maxURLs;

	if (argc > 2) {
		strcpy (baseURL, argv[1]);
		setFirstURL (baseURL, firstURL);
		maxURLs = atoi (argv[2]);
		if (maxURLs < 40)
			maxURLs = 40;
	} else {
		fprintf (stderr, "Usage: %s BaseURL MaxURLs\n", argv[0]);
		exit (1);
	}

	// You need to modify the code below to implement:
	//
	// add firstURL to the ToDo list
	// initialise Graph to hold up to maxURLs
	// initialise set of Seen URLs
	// while (ToDo list not empty and Graph not filled) {
	//    grab Next URL from ToDo list
	//    if (not allowed) continue
	//    foreach line in the opened URL {
	//       foreach URL on that line {
	//          if (Graph not filled or both URLs in Graph)
	//             add an edge from Next to this URL
	//          if (this URL not Seen already) {
	//             add it to the Seen set
	//             add it to the ToDo list
	//          }
	//       }
	//    }
	//    close the opened URL
	//    sleep(1)
	// }
	
	
	// url_fopen return a pointer to URL_FILE or NUll
	// if return NULL, handle == NULL --> 0  !0 == 1-->into the if statement  
	if (!(handle = url_fopen (firstURL, "r"))) {
		fprintf (stderr, "Couldn't open %s\n", next);
		exit (1);
	}
	
	// create a ToDo list
	Stack ToDoList = newStack (); // Queue ToDoList = newQueue ();
	
	// add first URL to the ToDo list
	pushOnto (ToDoList, firstURL); // enterQueue (ToDoList, firstURL);
	
	// initialise Graph to hold up to maxURLs
	Graph g = newGraph ((size_t)maxURLs);
	
	// initialise set of Seen URLs
	Set seenSet = newSet ();
	insertInto (seenSet, firstURL);
	
	// while (ToDo list not empty and Graph not filled) {
	while (emptyStack (ToDoList) == 0 
	&& nVertices (g) < (size_t)maxURLs) {
        
        // grab Next URL from ToDo list  'A'
        // check adjacent URL of 'Next URL'   'A1' 'A2'
	    // if (not allowed) continue 
        char *nextURL = popFrom (ToDoList); // char *nextURL = leaveQueue (TDL);
        
        // url_fopen return a pointer to URL_FILE or NUll
	    // if return NULL, handle == NULL --> 0  !0 == 1-->into the if statement  
	    if (!(handle = url_fopen (nextURL, "r"))) {
		    fprintf (stderr, "Couldn't open %s\n", next);
		    exit (1);
	    }
        
            
  
	    // for each line in the opened URL {
	    while (!url_feof (handle)) {
		    // to get the URL from each line 
		    url_fgets (buffer, sizeof (buffer), handle);
		    
		    // fputs(buffer,stdout);
		    int pos = 0;
		    char result[BUFSIZE];
		    memset (result, 0, BUFSIZE);	    
		    
		    // for each URL on that line {
		    while ((pos = GetNextURL (buffer, nextURL, result, pos)) > 0) {
                printf ("Found: '%s'\n", result);
                
                // if (Graph not filled or both URLs in Graph)	       
		        if (nVertices (g) < (size_t)maxURLs 
		        || (isElem (seenSet, nextURL) == 0 
		        && isElem(seenSet, result) == 0)) {
		            // add an edge from Next to this URL
		            addEdge (g, nextURL, result);
		        }
		        
		        // if (this URL not Seen already) {
                if (isElem (seenSet, result) == 0) {
                    // add it to the Seen set
                    insertInto (seenSet, result);
                    // add it to the ToDo list
                    pushOnto(ToDoList, result); // enterQueue (ToDoList, result);
                }
   
			    memset (result, 0, BUFSIZE);
		    }

	    }
	
	    // close the opened URL
	    url_fclose (handle);
	    free(nextURL);
	    sleep (1);

    }
    
    showGraph(g, 1);
    showGraph(g, 0);
    dropStack (ToDoList);  // dropQueue(ToDoList);
    dropSet(seenSet);
    dropGraph (g);
    
    return 0;
}

// setFirstURL(Base,First)
// - sets a "normalised" version of Base as First
// - modifies Base to a "normalised" version of itself
static void setFirstURL (char *base, char *first)
{
	char *c;
	if ((c = strstr (base, "/index.html")) != NULL) {
		strcpy (first, base);
		*c = '\0';
	} else if (base[strlen (base) - 1] == '/') {
		strcpy (first, base);
		strcat (first, "index.html");
		base[strlen (base) - 1] = '\0';
	} else {
		strcpy (first, base);
		strcat (first, "/index.html");
	}
}
