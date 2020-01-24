// testList.c - testing DLList data type
// Written by John Shepherd, March 2013

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "DLList.h"

int main (void)
{
	/*DLList myList = getDLList (stdin);
	putDLList (stdout, myList);
	assert (validDLList (myList));*/

	
	printf("\nWelcome to the COMP2521 DLList Tests!\n");

    printf("\n==================== DLList Tests ====================\n");
	
    printf("\n>> Testing newDLList\n");
    
    printf("    ... Creating a newDLList\n");
	DLList myList = newDLList();
	
	printf("       --> Checking that the DLList is valid\n");
    assert(validDLList(myList));
	assert(DLListLength(myList) == 0);
	assert(DLListCurrent (myList) == NULL);
    
    printf(">> Passed newDLList tests!\n");
	
	printf("\n==================== Test 1 ====================\n");
	printf("\n>> Testing DLListBefore\n");
	printf("\n======= Test 1.1 empty list =======\n");
    printf("    ... Insert \"This is the first line.\" before the current.\n");
	DLListBefore(myList,"This is the first line.");
	
    printf("       --> Checking the number of lists and the current list.\n");
    assert(validDLList(myList));
	assert(DLListLength(myList) == 1);
	assert(strcmp(DLListCurrent (myList),"This is the first line.")== 0);
    printf(">> Passed Test 1.1!\n");
    
    printf("\n======= Test 1.2 current item is the first node =======\n");
    printf("    ... Insert \"This is the new line.\" before the current.\n");
	DLListBefore(myList,"This is the new line.");
    
    printf("       --> Checking the number of lists and the current list.\n");
    assert(validDLList(myList));
	assert(DLListLength(myList) == 2);
	assert(strcmp(DLListCurrent (myList),"This is the new line.")== 0);
    
    printf("       --> Moving the current list point to the 2nd line.\n");
    DLListMoveTo (myList, 2);
    assert(strcmp(DLListCurrent (myList),"This is the first line.")== 0);
    printf(">> Passed Test 1.2!\n");
    
    printf("\n======= Test 1.3 current item in the other place =======\n");
    printf("    ... Insert \"This is the last line.\" before the current.\n");
    DLListBefore(myList,"This is the last line.");
    
    printf("       --> Checking the number of lists and the current list.\n");
	assert(validDLList(myList));
    assert(DLListLength(myList) == 3);
    assert(strcmp(DLListCurrent (myList),"This is the last line.")== 0);  
    printf(">> Passed Test 1.3!\n");
    
    printf(">> Passed DLListBefore Tests!\n");
    
    
    
    printf("\n==================== Test 2 ====================\n");
    printf("    ... Creating the second newDLList\n");
	DLList newList = newDLList();
	
	printf("       --> Checking that the DLList is valid\n");
    assert(validDLList(newList));
	assert(DLListLength(newList) == 0);
	assert(DLListCurrent (newList) == NULL);
    
    printf(">> Passed newDLList tests!\n");

	printf("\n>> Testing DLListAfter\n");
	printf("\n======= Test 2.1 empty list =======\n");
    printf("    ... Insert \"EMPTYEMPTYEMPTY!!!\" after the current\n");
	DLListAfter(newList,"EMPTYEMPTYEMPTY!!!");
	
    printf("       --> Checking the number of lists and the current list.\n");
    assert(validDLList(newList));
	assert(DLListLength(newList) == 1);
	assert(strcmp(DLListCurrent (newList),"EMPTYEMPTYEMPTY!!!")== 0);
    printf(">> Passed Test 2.1!\n");
    
    printf("\n======= Test 2.2 current item is the last node =======\n");
    printf("    ... Insert \"LASTLASTLAST!!!\" after the current.\n");
	DLListAfter(newList,"LASTLASTLAST!!!");
    
    printf("       --> Checking the number of lists and the current list.\n");
    assert(validDLList(newList));
	assert(DLListLength(newList) == 2);
	assert(strcmp(DLListCurrent (newList),"LASTLASTLAST!!!")== 0);
    
    printf("       --> Moving the current list point to the 1st line.\n");
    DLListMoveTo (newList, 1);
    assert(strcmp(DLListCurrent (newList),"EMPTYEMPTYEMPTY!!!")== 0);
    printf(">> Passed Test 2.2!\n");
    
    printf("\n======= Test 2.3 current item in the other place =======\n");
    printf("    ... Insert \"MIDDLEMIDDLEMIDDLE!!!\" after the current.\n");
    DLListAfter(newList,"MIDDLEMIDDLEMIDDLE!!!");
    
    printf("       --> Checking the number of lists and the current list.\n");
	assert(validDLList(newList));
    assert(DLListLength(newList) == 3);
    assert(strcmp(DLListCurrent (newList),"MIDDLEMIDDLEMIDDLE!!!")== 0);  
    printf(">> Passed Test 2.3!\n");
    
    printf(">> Passed DLListAfter Tests!\n");
    
    
    printf("\n==================== Test 3 ====================\n");
	printf("\n>> Testing DLListDelete\n");
	printf("\n======= Test 3.1 delete the middle item =======\n");
	DLListDelete(myList);
	
    printf("       --> Checking the number of lists and the current list.\n");
    assert(validDLList(myList));
	assert(DLListLength(myList) == 2);
	assert(strcmp(DLListCurrent (myList),"This is the first line.")== 0);
    printf(">> Passed Test 3.1!\n");
    
    printf("\n======= Test 3.2 delete the last item =======\n");
	DLListDelete(myList);
    
    printf("       --> Checking the number of lists and the current list.\n");
    assert(validDLList(myList));
	assert(DLListLength(myList) == 1);
	assert(strcmp(DLListCurrent (myList),"This is the new line.")== 0);
    printf(">> Passed Test 3.2!\n");
    
    printf("\n======= Test 3.3 delete the first/only item =======\n");
    DLListDelete(myList);
    
    printf("       --> Checking the number of lists and the current list.\n");
	assert(validDLList(myList));
    assert(DLListLength(myList) == 0);
    assert(DLListCurrent (myList) == NULL);  
    printf(">> Passed Test 3.3!\n");
    
    printf(">> Passed DLListDelete Tests!\n");
    
    printf("All tests passed, Jay is so smart!\n");
	printf("=============J================A=================Y============\n");
	freeDLList (myList);
	freeDLList (newList);
	return EXIT_SUCCESS;
}
