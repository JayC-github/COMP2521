#include "list.h"

void listReverse(List l) {
    Node curr = l->head;
    Node prev = NULL;
    Node next = NULL;
    
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }


    l->head = prev;







 
/*    Node curr = l->head;
    Node prev = NULL;
    Node next = NULL;
    
    while (curr != NULL) {
        next = curr->next;    
        curr->next = prev;
        prev = curr;
        curr = next;       
    }

    l->head = prev;

*/








/*  Node curr = l->head;
    Node prev = NULL;
    Node next = NULL;
    
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }


    l->head = prev;



*/



















/*    Node curr = l->head;
    Node prev = NULL;
    Node next = NULL;
    // stop at the last node 
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next; 
    }

    l->head = prev;
*/
}
