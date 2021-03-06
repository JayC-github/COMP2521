#include "list.h"

bool listIsOrdered(List l) {
    Node curr = l->head;
    if (curr == NULL || curr->next == NULL) {
        return true;
    }
    
    while (curr->value == curr->next->value) {
        curr = curr->next;
        if (curr->next == NULL) {
            return true;
        }
    }
    
    if (curr->value < curr->next->value) {
        while (curr->next != NULL) {
            if (curr->value > curr->next->value) {
                return false;
            }
            curr = curr->next;
        }
    
    } else {
        while (curr->next != NULL) {
            if (curr->value < curr->next->value) {
                return false;
            }
            curr = curr->next;
        }
    
    }
    
    return true;    
     

/*    Node curr = l->head;
    if (curr == NULL || curr->next == NULL) {
        return true;
    } 
    
    // loop till the first node difference
    while (curr->value == curr->next->value) {
        curr = curr->next;
        if (curr->next == NULL) {
            return true;
        }
    }
    
    // ascending order
    if (curr->value > curr->next->value) {
        while (curr->next != NULL) {
            if (curr->value < curr->next->value) {
                return false;
            }
            curr = curr->next;
        }    
    // descending order
    } else {
         while (curr->next != NULL) {
            if (curr->value > curr->next->value) {
                return false;
            }
            curr = curr->next;
        }    
    }
    
    
    return true;

*/



/*    if (l->head == NULL || l->head->next == NULL) {
        return 1;
    }

    Node prev = l->head;
    Node curr = l->head->next;
    
    while (prev->value == curr->value) { 
        prev = curr;         
        curr = curr->next;
    }
    
    
    if (prev->value < curr->value) {
        while (curr != NULL) {
            if (prev->value > curr->value) {
                return 0;
            }
            prev = curr;
            curr = curr->next;
        }
    } else if (prev->value > curr->value) {
        while (curr != NULL) {
            if (prev->value < curr->value) {
                return 0;
            }
            prev = curr;
            curr = curr->next;
        }
   
    }     

    return 1;    
    
*/    
     
}

