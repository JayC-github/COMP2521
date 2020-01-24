
#include <stdlib.h>

#include "tree.h"

int TreeSumOdds(Tree t) {
    if (t == NULL) {
        return 0;
    } else if(t->value % 2 == 1) {
        return t->value + TreeSumOdds(t->left) +TreeSumOdds(t->right);
    } else {
        return TreeSumOdds(t->left) +TreeSumOdds(t->right);
    }




















}
// if num of odd return 1 + TreeSumOdds(t->left) + TreeSumOdds(t->right);






/*
// base case 
	if (t == NULL) {
	    return 0;
	} else if (t->value % 2 == 1){
	    return t->value + TreeSumOdds(t->left) + TreeSumOdds(t->right);
	} else {
	    return TreeSumOdds(t->left) + TreeSumOdds(t->right);
	}
*/	
