
#include <stdlib.h>
#include <math.h>

#include "tree.h"

int TreeHeight(Tree t) {
    if (t == NULL) {
        return -1;
    } else {
        int l = TreeHeight(t->left);
        int r = TreeHeight(t->right);
        return (l > r) ? l+1 : r+1;
    }
}

bool TreeIsPerfectlyBalanced(Tree t) {
    if (t == NULL) {
        return true;
    } else if (t->left == NULL && t->right == NULL) {
        return true;
    } else {
        int l = TreeHeight(t->left);
        int r = TreeHeight(t->right);
        if (abs(l-r) <= 1 && TreeIsPerfectlyBalanced(t->left) && TreeIsPerfectlyBalanced(t->right)) {
            return true;
        }
    
    }
	
	return false;
}


/*
int TreeHeight(Tree t) {
    // base
    if(t == NULL) {
        return -1;
    } else {
        int left = TreeHeight(t->left);
        int right = TreeHeight(t->right);
        
        return left > right ? left + 1 : right + 1; 
    
    } 
}

bool TreeIsPerfectlyBalanced(Tree t) {
	if (t == NULL) {
	    return true;
	} 
	
	int left = TreeHeight(t->left);
	int right = TreeHeight(t->right);
	
	if (abs(left-right) <= 1 && TreeIsPerfectlyBalanced(t->left) && TreeIsPerfectlyBalanced(t->right)) {
	    return true;
	}
*/	
	

