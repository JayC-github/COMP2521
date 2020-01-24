
#include "list.h"

bool listIsPalindromic(List l) {
    Node n1 = l->first;
    Node n2 = l->last;
    
    if (n1 == NULL) {
        return true;
    }

    int count = 0;
    while (count <= l->size/2) {
        if (n1->value != n2->value) {
            return false;
        }    
    
        n1 = n1->next;
        n2 = n2->prev;
        count++;
    }

    return true;

}
/*  Node n1 = l->first;
    Node n2 = l->last;

    
    if (n1 == NULL) {
        return true;
    }
    
    int count = 0;
           while (count < l->size/2) {
            if (n1->value != n2->value) {
                return false;
            }
        
            n1 = n1->next;
            n2 = n2->prev;
            count++;
            }
    
        return true;
    }

*/






















/*    if (l->first == NULL) {
        return true;
    }
    
    Node first = l->first;
    Node last = l->last;
    int count = 0;
    // num of nodes is even
    if ((l->size)%2 == 0) {
        while (count < (l->size)/2) {
            if (first->value != last->value) {
                return false;
            }    
            first = first->next;
            last = last->prev;
            count++;    
        }
    } else {
        while (count < (l->size-1)/2) {
            if (first->value != last->value) {
                return false;
            }    
            first = first->next;
            last = last->prev; 
            count++;
        }
    }

    return true;
}
*/


