#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define key(A) (A)
#define less(A,B) (key(A) < key(B))
#define swap(A,B) {Item t; t = A; A = B; B = t;}
#define swil(A,B) {if (less(A,B)) swap(A,B);}


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

int main(void) {
    int A[] = {2,3,5,7,4,1};
    InsertionSort(A, 6);
    for (int i = 0; i < 6; i++) {
        printf("%d\n", A[i]);
    }
}
