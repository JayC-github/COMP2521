int isAVL (BSTree t) {
    if (t == NULL) {
        return 0;
    } 
    
    int heightL = isAVL(t->left);
    int heightR = isAVL(t->right);
    
    if (heightL == -1 || heightR == -1) {
        return -1
    }

    if (heightL-heightR > 1 || heightR-heightL > 1) {
        return -1;
    }
    
    return 1 + (heightL > heightR ? heightL : heightR);
    
}
