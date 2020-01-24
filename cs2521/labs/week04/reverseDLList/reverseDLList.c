#include "list.h"
void reverseDLList(List l) {
    Node curr = l->first;
    Node prev = NULL;
    Node next = NULL;
    
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }

    Node tmp = l->first;
    l->first = l->last;
    l->last = tmp;


 



/*    
    Node curr = l->first;
    Node prev = NULL;
    Node next = NULL;
    
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;    
    }

    Node tmp = l->first;
    l->first = l->last;
    l->last = tmp;

*/
}


/*typedef struct node *Node;
struct node {
	int value;
	Node next;
	Node prev;
};

typedef struct list *List;
struct list {
	Node first;
	Node last;
	int size;
};
*/
