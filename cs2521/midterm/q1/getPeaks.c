// getPeaks.c 
// Written by Ashesh Mahidadia, August 2017

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "DLList.h"


/* 
    You will submit only this one file.

    Implement the function "getPeaks" below. Read the exam paper for 
    detailed specification and description of your task.  

    - DO NOT modify code in the file DLList.h . 
    - You can add helper functions in this file.  
    - DO NOT add "main" function in this file. 
    
    typedef struct DLListNode {
	    int   value;  // value of this list item (int)
	    struct DLListNode *prev;
	                   // pointer previous node in list
	    struct DLListNode *next;
	                   // pointer to next node in list
    } DLListNode;

    typedef struct DLListNode *DLListNodeP;

    typedef struct DLListRep {
	    int  nitems;      // count of items in list
	    DLListNode *first; // first node in list
	    DLListNode *curr;  // current node in list
	    DLListNode *last;  // last node in list
    } DLListRep;

    typedef struct DLListRep *DLList;

*/

DLList getPeaks(DLList L) {
    assert(L != NULL);
    
    DLList newL = malloc(sizeof(struct DLListRep));
    
    if (L->first == NULL || L->nitems < 3) {
        return newL;
    }

    DLListNodeP curr = L->first->next;
    DLListNodeP new = NULL;
    while(curr->next != NULL) {
        if (curr->prev->value < curr->value 
        && curr->value > curr->next->value) {
            new = malloc(sizeof(struct DLListNode));
            new->value = curr->value;
            
            if (newL->first == NULL) {
                newL->first = newL->last = newL->curr = new;
            } else {
                DLListNodeP tmp = newL->last;
                tmp->next = new;
                new->prev = tmp;
                newL->last = new;
                newL->curr = new;
            }
            
            newL->nitems++;
        }
        
        curr = curr->next;
    }
    
    return newL;

/*    DLList newL = malloc(sizeof(struct DLListRep));
    
    if (L->nitems < 3 || L->first == NULL) {
        return newL;
    } 

    DLListNodeP curr = L->first->next;
    while (curr->next != NULL) {
        if (curr->prev->value < curr->value 
        && curr->next->value < curr->value) {
            DLListNodeP new = newDLListNode(curr->value);
            if (newL->first == NULL) {
                newL->first = newL->last = newL->curr = new;  
            } else {
                DLListNodeP tmp = newL->last;
                tmp->next = new;
                new->prev = tmp;
                newL->last = new; 
            }
            newL->nitems++;
        }
        curr = curr->next;
    }


    return newL;

*/







/*	DLList newL = newDLList();
	if(newL == NULL) {
	    fprintf(stderr, "malloc fail.\n");
	    abort();
	}
	
	if (L == NULL) {
	    fprintf(stderr, "DLList non exit.\n");
	    abort();
	}
	
	// only three item in the list
    if (L->nitems < 3) {
        newL->first = newL->last = newL->curr = NULL;
        newL->nitems = 0;
        return newL;
    }   
    
    DLListNodeP curr = L->first->next;
    while (curr->next != NULL) {
        if (curr->value > curr->prev->value 
        && curr->value > curr->next->value) {
            // make a new node include peak
            DLListNodeP new = newDLListNode(curr->value);
            // List is empty, add node
            if (newL->first == NULL) {
                newL->first = newL->last = newL->curr =new;
                newL->nitems++; 
            // List have nodes, add more
            } else {
                DLListNode *tmp = newL->last;
                tmp->next = new;
                new->prev = tmp;
                newL->curr = new;
                newL->last = new;
                newL->nitems++;
            }     
            
        }    
        
        curr = curr->next;
    }    
	
	
	
	return newL;
*/
}

