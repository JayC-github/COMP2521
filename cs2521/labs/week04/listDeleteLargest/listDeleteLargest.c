#include "list.h"
int listDeleteLargest(List l) {
    Node curr = l->head;
    Node tmp = NULL;
    int value;
    
    if (curr == NULL) {
        return 0; 
    } else if (curr->next == NULL) {
        tmp = curr;
        value = curr->value;
    }
    
    value = curr->value;
    while (curr != NULL) {
        if (curr->value > value) {
            value = curr->value;
        }
        curr = curr->next;
    }
    
    curr = l->head;
    Node prev = l->head;
    while (curr->next != NULL) {
        if (curr->value == value) {
            break;
        }
        
        prev = curr;
        curr = curr->next;
    }
    
    tmp = curr;
    if (curr->value == l->head->value) {
        l->head = l->head->next;
    } else if (curr->next == NULL) {
        prev->next = NULL;
    } else {
        prev->next = curr->next;
    
    }
    
    
    free(tmp);
    return value;
/*  Node curr =l->head;
    Node tmp = NULL;
    int value;

    
    //no node     
    if (curr == NULL) {
        return 0;
    } 
    
    //one node
    if (curr->next == NULL) {
        tmp = curr;
        value = curr->value;        
    }

    //lots of nodes, find the largest value
    
    value = curr->value;
    while (curr != NULL) {
        if (curr->value > value) {
            value = curr->value;
        }
        curr = curr->next;
    }

    // stop at the largest
    curr = l->head;
    Node prev = l->head;
    while (curr != NULL) {
        if (curr->value == value) {
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    
    tmp = curr;
    if (curr->value == l->head->value) {
        l->head = l->head->next;
    } else if (curr->next == NULL) {
        prev->next = NULL;
    } else {
        prev->next = curr->next;
    }
    


    free(tmp);
    return value;

*/

















/*    Node curr = l->head;
    Node tmp = NULL;
    int value;
    // nothing in the list
    if (curr == NULL) {
        return 0;
    }
    
    // only one node in the list
    if (curr->next == NULL) {
        tmp = curr;
        value = curr->value;
        //curr = NULL;
    }
    
    // find the largest value in the list;
    value = curr->value;
    while (curr != NULL) {
        if (curr->value >= value) {
            value = curr->value;
        }
        curr = curr->next;
    }
    
    Node new_curr = l->head;
    Node prev = NULL;
    // new_curr = node have largest, prev is one node before
    while (new_curr != NULL) {
        if (new_curr->value == value) {
            break;               
        }
        prev = new_curr;
        new_curr = new_curr->next;
    }
    
    tmp = new_curr;
    // LARGEST node is the first one
    if (value == l->head->value) {
        l->head = new_curr->next;
        //new_curr = NULL;
    
    // node in the last
    } else if (new_curr->next == NULL) {
        prev->next = NULL;
    
    // node in the middle
    } else {
        prev->next = new_curr->next;
        //new_curr = NULL;
    }
    
    free(tmp);
    return value;
*/
}

