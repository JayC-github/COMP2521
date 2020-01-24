Week01

char *a = "I love Mercy 1314"
char b[20], char c[20], char d[20], int i 
// extraction of data values from a string instead of file
sscanf(a, "%s %s %s %d", b, c, d, &i);

int N = 0;
sscanf(argv[1], "%d", &N);
==>
N = atoi(argv[1]);

void swap(int arryay[], int i, int j) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
    
}


Week02

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef Node *List;

int sum(List L) {
    Node *curr = L;
    int sum = 0;
    while (curr != NULL) {
        sum += curr->value;
        curr = curr->next;
    }

}

#include<stdbool.h>
#include<string.h>
bool isP(char A[], int len) {
    int i = 0;
    int j = len - 1;
    
    printf("%c--------------", A[i]);
    printf("%cxxxxxxxxxxxxxx", A[j]);
    
    while (i < j) {
        if (A[i] != A[j]) {
            return false;     
        }
        
        i++;
        j--;
    }
    
    return true;
}

Week03 BSTree (O(log n)) suffix tree(O(n^2))
typedef struct BSTNode *BSTree
typedef struct BSTNode {
    int value;
    BSTree left;
    BSTree right;
} BSTNode;

prefix: ROOT-LEFT-RIGHT

infix: LEFT-ROOT-RIGHT

postfix: LEFT-RIGHT-ROOT

int counteInternal(BSTree t) {
    if (t == NULL) {
        return 0;
    } else if (t->left == NULL && t->right == NULL) {
        return 0;
    } else {
        return counteInternal(t->left) + counteInternal(t->right) + 1;
    }


}

int nodeDepth(BSTree t, int key) {
    if (t == NULL) {
        return -1;   
    } else if (t->value == key) {
        return 0;
    } else if (key < t->value) {
        int left = nodeDepth(t->left, key);
        if (left == -1) {
            return -1;
        }
        
        return left + 1;
    } else if (key > t->value) {
        int right = nodeDepth(t->right, key);
        if (right == -1) {
            return -1;
        }
    
        return right + 1;    
    }     
}

int BSTreeMaxBranchLen(BSTree t) {
    if (t == NULL) {
        return 0;
    } else if (t->left == NULL && t->right == NULL) {
        return 1;
    } else {
        int left = BSTreeMaxBranchLen(t->left);
        int right = BSTreeMaxBanchLen(t->right);
        
        return 1 + ((left > right) ? left : right);
    }

}


// print values in level-order
void BSTreeLevelOrder (BSTree t)
{
    if (t == NULL) {
        return;
    } 
    
    Queue new = newQueue();
    QueueJoin (new, t);
    while (!QueueIsEmpty(new)) {
        t = QueueLeave(new);
        printf("%d", t->value);
        if (t->left != NULL) QueueJoin(new, t->left);
        if (t->right != NULL) QueueJoin(new, t->right);
    }
}

Week04

int printHeightDiff(BSTree t) {
    if (t == NULL) {
        printf("diff is 0.\n");
        return 0;
    }
    
    if (t->left == NULL && t->right == NULL) {
        printf("diff is 0.\n");
        return 0;
    }
    
    int l = printHeightDiff(t->left);
    int r = printHeightDiff(t->right);
    printf("diff is %d", l-r);
    
    if (l > r) {
        return 1 + l;
    } else {
        return 1 + r;
    }
}

int BSTWidth(BSTree t) {
    if (t == NULL) {
        return 0;
    } else if (t->left == NULL && t->right == NULL) {
        return 3;
    } else {
        return 3 + BSTWidth(t->left) + BSTWidth(t->right);
    }
}

Week05 Splay/AVL/234 tree

1. splay
not very self-balanced
everytime instert a node rotate ==> find the most "important" node
rotation-in-search

rote left left child/ right right child/ left right child/ left right child
     rotateR, rotateR/ rotateL rotaeL / rotateL rotateR

2. AVL
check self-balanced (abs(height(L)- height(R) <= 1))
1. left subtree too deep, rotate right
2. right subtree too deep, rotate left

3. 234

2-nodes, one value with two children
3-nodes, two value with three children
4-notes, three values with four children

any nodes who have above 3 values wil promote the middles node upstairs

Week06 Graphs

1. adjacency matrix
2. adjacency list represnetation
3. connected-> all graphs are reachable, 
   all vertices are connected to each other
4. bridges -->remove will cuz connected decrease
5. Euler paths ==> edges all cross through exactly once except the starting point
6. Euler tour ==> a cycle pass through all edges excatly once ends at the same vertex 
7. Hamilton paths ==> pass through each vertice in the graph exactly once 
8. Hamilton tour ==> cycle pass through all vertices


Week07 Graphs

Pime's

1. prime's -->always maintains a tree, select the minimum edge could be connected.
   Initially select the smallest one, then always select connected smallest one.
2. cant find out minimum spanning tree for non connected graph
                                      
Kruskal's

1. always select the minimum cost edge
2. finf the minimum spanning tree for each non conntected graph
