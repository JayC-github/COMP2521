
#include "list.h"

int numDupesInOrderedList(List l) {
    Node curr = l->head;
    if (curr == NULL || curr->next == NULL) return 0;
    int counter = 0;
    while (curr != NULL) {
        Node tmp = curr->next;
        while (tmp != NULL) {
            if(tmp->value == curr->value) {
                counter++;
                break;
            }
            tmp = tmp->next;
        }
        curr = curr->next;
    }
    
    return counter;
    
    







/*	Node curr = l->head;
	if (curr == NULL || curr->next == NULL) {
	    return 0;
	}

    int count = 0;
    while (curr != NULL) {
        Node tmp = curr->next;
        while (tmp != NULL) {
            if (curr->value == tmp->value) {
                count ++;
                break;
            }
            tmp = tmp->next;
        }
        curr = curr->next;
    }

    return count;
*/

/*	
    int count = 0;
    while (curr->next != NULL) {
        Node tmp = curr->next;    
        while (tmp != NULL) {
            if (curr->value == tmp->value) {
                count++;
                break;
            }
            tmp = tmp->next;
        }
        curr = curr->next;
    }

	return count;
*/
}
                              
