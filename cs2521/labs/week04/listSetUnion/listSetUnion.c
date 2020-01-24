
#include "list.h"
#include<stdlib.h>

List listSetUnion(List s1, List s2) {
    List newlist = malloc(sizeof(struct list));
    newlist->head = NULL;
    Node h1 = s1->head;
    Node h2 = s2->head;
    if (h1 == NULL && h2 == NULL) {
        return newlist;
    } else if (h1 == NULL && h2 != NULL) {
        Node prev = NULL;
        while (h2 != NULL) {
            Node new = malloc(sizeof(struct node));
            new->value = h2->value;
            new->next = prev;
            prev = new;
            
            h2 = h2->next;
        }
        
        newList->head = prev;
        return newList;
    } else if (h2 == NULL && h1 != NULL) {
        Node prev = NULL;
        while (h1 != NULL) {
            Node new = malloc(sizeof(struct node));
            new->value = h1->value;
            new->next = prev;        
            prev = new;
            h1 = h1->next;
        }
        
        newList->head = prev;
        return newList;
    } else {
        Node prev = NULL;
        while (h1 != NULL) {
            Node new = malloc(sizeof(struct node));
            new->value = h1->value;
            new->next = prev;        
            prev = new;
            h1 = h1->next;
        }
        
        Node tmp = prev;
        while (h2 != NULL) {
            int match = 0;        
            Node hh1 = s1->head;
            while (hh1 != NULL) {
                if (hh1->value == h2->value) {
                    match = 1;
                }
                hh1 = hh1->next;
            }
            
            if (!match) {
                Node new = malloc(sizeof(struct node));
                new->next = tmp;
                tmp = new;
            }
            
            
            h2 = h2->next;        
        }
       
        newList->head = tmp;
        return newList;
    }

/*   List newList = malloc(sizeof(struct list));
    newList->head = NULL;
    
    Node h1 = s1->head;
	Node h2 = s2->head;
	
	// both are null
	if (h1 == NULL && h2 == NULL) {
	    return newList;
    // 1st list is null
	} else if (h1 == NULL && h2 != NULL) {
        Node prev = NULL;
        while (h2 != NULL) {
            Node new = malloc(sizeof(struct node));
	        new->value = h2->value;
	        new->next = prev;
	        prev = new;
	        
	        h2 = h2->next;
	    } 
	    
	    newList->head = prev;
	    return newList;
	// 2nd list is null
	} else if (h2 == NULL && h1 != NULL) {
        Node prev = NULL;
        while (h1 != NULL) {
            Node new = malloc(sizeof(struct node));
	        new->value = h1->value;
	        new->next = prev;
	        prev = new;
	        
	        h1 = h1->next;
	    } 
	    
	    newList->head = prev;
	    return newList;
	// both are non null list
	} else {
	// get s1 first;
	    Node prev = NULL;
	    while (h1 != NULL) {
	        Node new = malloc(sizeof(struct node));
	        new->value = h1->value;
	        new->next = prev;
	        prev = new;
	        h1 = h1->next;
	    }
	
	// compare list s2 with the new list;    
	    Node tmp = prev;
	    Node h1 = s1->head;
	    Node h2 = s2->head;
	    while (h2 != NULL) {
	        int match = 0;
	        h1 = s1->head;
	        while (h1 != NULL) {
	            if (h2->value == h1->value) {
	                match = 1;
	            }
	            h1 = h1->next;
	        } 
	        
	        if (match == 0) {
	            Node new = malloc(sizeof(struct node));
	            new->value = h2->value;
	            new->next = tmp;
	            tmp = new;  
	        }
	        
	        h2 = h2->next;
	    }
	
	    newList->head = tmp;
	    return newList;
	}
*/	
}

