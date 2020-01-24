
#include "list.h"

List listSetIntersection(List s1, List s2) {
    List newList = malloc(sizeof(struct list));
    newList->head = NULL;
    
    Node h1 = s1->head;
	Node h2 = s2->head;
	
	// either of them are null
	if (h1 == NULL || h2 == NULL) {
	    return newList;
	// both are non null list
	} else {
	    Node prev = NULL;
	// compare list s1 with the list s2;    
	    while (h1 != NULL) {
	        int match = 0;
	        h2 = s2->head;
	        while (h2 != NULL) {
	            if (h1->value == h2->value) {
	                match = 1;
	            }
	            h2 = h2->next;
	        } 
	        
	        if (match == 1) {
	            Node new = malloc(sizeof(struct node));
	            new->value = h1->value;
	            new->next = prev;
	            prev = new;  
	        }
	        
	        h1 = h1->next;
	    }
	
	    newList->head = prev;
	    return newList;
	}
}

