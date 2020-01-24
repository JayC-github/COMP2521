
#include <stdlib.h>

#include "BSTree.h"

int BSTreeNodeDepth(BSTree t, int key) {
    if(t== NULL) {
        return -1;
    } else if (t->value == key) {
        return 0;
    } else if (t->value > key) {
        int l = BSTreeNodeDepth(t->left, int key);
        if (l == -1) {
            return -1;
        }
        return l + 1;
    } else {
        int r = BSTreeNodeDepth(t->right, int key);
        if (r == -1) {
            return -1;
        }
        return r + 1;
    
    }

























/*    if (t == NULL) {
        return -1;
    }
    
    if (key == t->value) {
        return 0;
    } else if (key < t->value) {
        int left = BSTreeNodeDepth(t->left, key);
        if (left == -1) {
            return -1;
        }   
        return left + 1;
    } else {
         int right = BSTreeNodeDepth(t->right, key);
         if (right == -1) {
            return -1;
         }   
         
         return right + 1;
    }
*/
}

