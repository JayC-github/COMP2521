
#include <stdlib.h>

#include "tree.h"

int TreeHeight(Tree t) {
    if (t == NULL) {
        return -1;
    } else {
        int l = TreeHeight(t->left);
        int r = TreeHeight(t->right);
        return (l > r) ? l + 1: r+1;
    }
} 
 
/* 
     // base case
    if (t == NULL) {
        return -1;
    } else {
        int left = TreeHeight(t->left);
        int right = TreeHeight(t->right);
    
        return left > right ? left + 1 : right + 1;
    }
 
*/ 
 
 
 
 
 
 
 
 
 
 
 
/* 
 
 
    // base
    if(t == NULL) {
        return -1;
    } else {
        int left = TreeHeight(t->left);
        int right = TreeHeight(t->right);
        
        return left > right ? left + 1 : right + 1; 
    
    } 
}

*/


/*//////////////////////////////////
int numNode(BSTree t) {
    if (t == NULL) {
        return 0;
    } 

    return 1 + numNode(t->left) + numNode(t->right);
}


/////////////////////////////////////
int countInternal(BSTree t) {
    if (t == NULL) {
        return 0;
    } else if (t->left == NULL && t->right == NULL) {
        return 0;
    }
    
    return 1 + countInternal(t->left) + countInternal(t->right);
}

///////////////////////////////////
int countleaf(BSTree t) {
    if (t == NULL) {
        return 0;
    } else if (t->left == NULL && t->right == NULL) {
        return 1;
    }

    return countInternal(t->left) + countInternal(t->right);
}

////////////////////////////////////*/
