Week08
//////////////////////////////hashing

typedef struct HashTabRep {
    int N;
    Item **items;
} HashTabRep

HashTable newHashTable(int N) {
    HashTable new = malloc(sizeof(HashTabRep));
    new->items = malloc(N*sizeof(Item *));
    new->N = N;
    for (int i = 0; i < N; i++) {
        new->items[i] = NULL;
    }
    
    return new;
}

problem hash function relies on size of array(-> can't expand)
collision resolution

1. linear hashing --> increase the size of the array
2. probing --> find a free slot   

Separate chaining
--> solve collisions by having multiple items per array entry
#include "Item.h"

Item *search(HashTable ht, key k) {
    int i= hash(k, ht->nslots);
    return ListSearch(ht->lists[i], k);
}

int hash(Key key, int N) {
    int val  = convert key to int;
    return val % N;
}

// if the keys are string eg. "COMP1927" "123456"
int hash(char *key, int N) {
    int h = 0; char *c;
    for (c = key; *c != '\0', c++) {
        h = h + *c;
    } 
    return h % N;
}

/////////////////////////////
#include "Item.h"
typedef struct HashTabRep {
    Item *items // array of Items
    int nslots; // #elements in array (was called N)
    int  nitems; // # items stored in array
} HashTabRep;

typedef HashTabRep *HashTable;

HashTable newHash(int N) {
   HashTabRep *new = malloc(sizeof(HashTabRep));
   new->items  = malloc(sizeof(Item) * N);
   for (int i = 0; i < N; i++) {
      new->items[i] = Noitem;
   }
   new->nslots = N;
   new->nitems = 0;
    
   return new; 
}

//////////////////////////////////Seperate chaining
1. allow multiple Items in a single array location
2. solve collision by having multiple items per array entry

typedef struct HashTabRep {
    List *lists; // array of Items
    int nslots; // # elements in array
    int nitems; // # items stored in array

} HashTabRep;

HashTable newHashTable(int N) {
    HashTabRep *new = malloc(sizeof(HashTabRep));
    assert(new != NULL);
    new->lists = malloc(N*sizeof(List));
    assert(new->lists != NULL);
    for (i = 0; i < N; i++) {
        new->lists[i] = newlist();
    }
    
    new->nslots = N;
    new->nitems = 0;
    
    return new;   
}

// linear probing
1. hash indicates slot i which is alreayd used
2. try new slot, then next, until we find a free slot
3. insert item in available slot

// inster function for linear probing
void insert(HashTable ht, Item it) {
    assert(ht->nitems < ht->nslots);
    int N = ht->nslots;
    Item *a = ht->items;
    Key k = key(it);
    int i, j, h = hash(k,N);
    for (j = 0; j < N; j++) {
        i = (h + j) % N;
        if (a[i] == Noitem) break; 
     // if (eq(k, key(a[i]))) break;  
    }    
    
    if (a[i] == NoItem) ht->nitems++;
    a[i] = it;
}

typedef struct HashTabRep {
    Item *items;
    int nslots;
    int nitems;
    int nhash2;
} HashTabRep

#define hash2(k, N2) ((k)%N2 + 1)
HashTable newHashTable(int N) {
    HashTable *new = malloc(sizeof(HashTabRep));
    new->items = malloc(N*sizeof(Item));
    for (int i = 0; i < N; i++) {
        new->items[i] = NoItem;
    }
    new->nslots = N;
    new->nitems = 0;
    new->nhash2 = findSuitablePrime(N);
    return new;
}

WEEK09
typedef sturct HeapRep {
    Item *items; // array of items
    int nitems;  // #items in array
    int nslots;  // #elements in array
} HeapRep;

a node at index i
left child == 2i
right child == 2i + 1
parent is at i/2


Heap newheap(int N) {
    Heap new = malloc(sizeof(HeapRep)); 
    Item *a = malloc((N+1) *sizeof(Item));
    assert(new != NULL && a!= NULL);
    new->items = a; // no initialisation needed
    new->nitems = 0; // counter 1..N
    new->nslots = N; // index range 1..N
}

/////////////////////////
void insert(Heap h, Item it) {
    assert(h->nitems < h->nslots);
    h->nitems++;
    h->items[h->nitems] = it;
    fixup(h->nitems, h->nitems);
    
}

void fixup(Item a[], int i) {
    while (i > 1 && less(a[i/2],a[i])) {// i  = nitems and  parent less than the child
        swap(a, i, i/2);                // i start from 1
        i = i/2;
    }
}

void swap(Item a[], int i, int j) {
    Item tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;

}

///////////////////////////////////////
Deletion with heaps
Item delete(Heap h) {
    Item top = h->items[1];
    h->items[1] = h->items[h->nitems];
    h->nitems--;
    fixDown(h->nitems,1,h->nitems);
    return top;
}

// i is index, N is gives max index and # items
void fixDown(Item a[], int i, int N) {
    // left child
    while (2*i <= N) {
        int j = 2*i;
        if (j < N && less(a[j], a[j+1])) {
            j++;
        }
    
    }

}






// Function pointers
typeofRerunVlue (*fp)(typeofArguments)

// function  
// int square(int x)  (return x^2)
// int timesTwo(int x) (return x*2)

int (*fp)(int);
fp = &square; // fp points to the square function
int n = (*fp)(10);

int n = (*fp)(10) // call the square function with input10
fp = timesTwo

n = (*fp) (2) // call the time two function with input2
==> 
n = timeTwo(2);
// High-order functions ==> take another function argument

Week09 Sorting
Sorting algorithm 
// selection sort
1. fint the smallest element in the array
2. select it and put it into the first array slot
3. find second smallest element, put it into second array slot
4. repeat until all elements are in correct position
5. O(n^2)
void selectionSort(int Array[], int n) {
    for (int i = 0; i < n; i++) {
        int min = i; // minimum element
        for (int j = i + 1; j < n; j++) {
            if (Array[j] < Array[min]) {
                min = j;
            }
        }
        
        int temp = Array[i];
        Array[i] = Array[min];
        Array[min] = temp;   
    }

}

// bubble sort
1. make multiple passes from N to i
2. on each pass, swap any out-of-order adjacent pairs
3. O(n^2)

void BubbleSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int flag = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (A[j] > A[j + 1]) {
                int tmp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = tmp;
                flag = 1;
            }
        }
        
        if (flag == 0) break;        
    }
}

// insertion sort
1. simple adaptive method
2. take first element and treat as sorted array
3. take next element and insert into sorted part of array so that order is 
   preserved
4. above increased length of sorted part by one

void InsertionSort(int A[], int n) {
    int key;
    for (int i = 1; i < n; i++){
        key = A[i];
        int j = i - 1;
    
        while (j >= 0 && A[j] > key) { // means there is an element before i
            A[j + 1] = A[j];           // and it is greater than i 
            j--;
        }
        
        A[j + 1] = key;
    }
}




// merge sort O(nlogn) --> O(n)
1. split the array into two equal size paritions
2. sort each of the partitions
3. merge the two partitions into a new sorted array
4. copy back to original array
Merge(L, R, A) {
    int nL = length(L);
    int nR = length(R);
    int i = 0;
    int j = 0;
    int k = 0;
    
    while (i < nL && j < nR) {
        if(L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

}

MergeSort(A) {
    int n = length(A);
    if (n < 2) return;
    int mid = n/2; 
    left = array(mid);
    right = array(n-mid);
    
    for int i = 0; i < mid - 1; i++;
    left[i] = A[i]
    for int i = 0; i < n - 1; i++;
    Mergesort(left);  // recursive
    Mergesort(right); // recursive
    Merge(left, right, A); // recursive

}





1. divide and conquer
2. recursive
3. stable
4. not in-place 

// quick sort O(nlogn)
int Partition(int A[], int start, int end) {
    int pivot = A[end];
    int pIndex = start; // set partition index as start
    for(int i = start; i < end; i++) {
        if (A[i] <= pivot) {         
            int tmp = A[i];
            A[i] = A[pIndex];
            A[pIndex] = tmp;
            pIndex++;
        }
    }

    int tmp = A[pIndex];
    A[pIndex] = A[end];
    A[end] = tmp;
    return pIndex; 
}

void QuickSort(int A[],int start, int end) {
    if (start < end) {
        int pIndex = Partition(A,start,end);
        QuickSort(A, start, pIndex-1);
        QuickSort(A, pIndex + 1, end);
    
    }    
}

// string
Knuth-Morris-Patt string Maching algorithm
pattern: abcdabc
prefix: a,ab,abc,abcd
suffix: c,bc,abc,dabc

p1: a b c d a b e a b f
    0 0 0 0 1 2 0 1 2 0 
p2: a b c d e a b f a b c
    0 0 0 0 0 1 2 0 1 2 3
p3: a a a a b a a c d
    0 1 2 3 0 1 2 0 0     
// huffman coding
ASCII - 8 bits     

eg. Message BCCABBDDAECCBBAEDDCC
            000010010000001001011011000100010010001001,,,,
character/frequency/code 0/1 bit
A. 3 3/20   000      5x8bits for characters  5*3bits codes == 55 bits
B. 5 5/20   001   
C. 6 6/20   010
D. 4 4/20   011
E. 2 2/20   100

Huffman coding -optimal mash pattern

/*
argc: is an integer argument to the main() function that indicates how many arguments were typed on the command line that invoked the program. Since it includes the name of the command, it always has a value that is at least 1.

argv: is an array of strings, argument to the main() function that contains the strings for the arguments that were typed on the command line that invoked the program. argv[0] is always the name of the executable file of the program.

stdin: is an input stream (type FILE *) that is open when the program starts and can be used to read program input. By default, it is connected to the keyboard, but can be redirected to come from a file.

stdout: is an output stream (type FILE *) that is open when the program starts and can be used as a destination for program output. By default, it is connected to the screen, but can be redirected so that the output is sent to a file.

stderr: is an output stream (type FILE *) that is open when the program starts and can be used as a destination for program output. By default, it is connected to the screen, but can be redirected so that the output is sent to a file. Note that redirection of stderr and stdout are independent, so you can redirect one without redirecting the other.

exit(): is a function that can be called to terminate execution of the program. It takes a single integer argument which is used as the exit status of the program. The exit status can be used by the program's environment to determine whether the program completed successfully (exit status of zero) or whether there was an error (exit status non-zero).
*/



