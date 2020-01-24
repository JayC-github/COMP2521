
#include "BSTree.h"

#include <stdlib.h>

BSTree BSTreeGetSmallest(BSTree t) {
    if (t == NULL) {
        return NULL;
    } else {
        while (t->left != NULL) {
            t = t->left;
        }
        return t;
    }
/*
    // base case
    if(t == NULL) {
        return t;
    }  
    while(t->left != NULL) {
        t = t->left;
    }
    
    return t;
*/
}

