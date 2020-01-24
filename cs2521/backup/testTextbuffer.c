// A stub file for you to test your textbuffer implementation.
// Note that you will NOT be submitting this - this is simply for you to
// test  your  functions as you go. We will have our own testTexbuffer.c
// for testing your submission.

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "textbuffer.h"

static void testNewTB(void);
static void testaddPrefixTB(void);
static void testmergeTB(void);
static void testsearchTB(void);
static void testpasteTB(void);
static void testcutTB(void);
static void testdeleteTB(void);
static void testformRichText(void);
// TODO: Add more function prototypes


int main(void) {
testNewTB();
testaddPrefixTB();
testmergeTB();
testpasteTB();
testsearchTB();
testcutTB();
testdeleteTB();
testformRichText();
// TODO: Call more test functions
printf("All tests passed! You are awesome!\n");
}

static void testNewTB(void) {
printf("-----------------------------------------\n"
       "               newTB tests               \n"
       "-----------------------------------------\n");

// Calling dumpTB immediately after newTB, without modifying the TB
TB tb1 = newTB("hello there,\nhow\nare\nthings\n");
assert(linesTB(tb1) == 4);
    // Test normal text with prefix added
char *text1 = dumpTB(tb1, true);
assert(strcmp("1. hello there,\n2. how\n3. are\n4. things\n", text1) == 0);
free(text1);
releaseTB(tb1);
printf("test 1 - passed\n");
// Test normal text without prefix added
TB tb2 = newTB("hello there,\nhow\nare\nthings\n");
assert(linesTB(tb2) == 4);
char *text2 = dumpTB(tb2, false);
assert(strcmp("hello there,\nhow\nare\nthings\n", text2) == 0);
free(text2);
releaseTB(tb2);
printf("test 2 - passed\n");
// Test empty text without prefix added
TB tb3 = newTB("");
assert(linesTB(tb3) == 0);
char *text3 = dumpTB(tb3, false);
assert(strcmp("", text3) == 0);
free(text3);
releaseTB(tb3);
printf("test 3 - passed\n");
// Test empty text with prefix added
TB tb4 = newTB("");
assert(linesTB(tb4) == 0);
char *text4 = dumpTB(tb4, true);
assert(strcmp("", text4) == 0);
free(text4);
releaseTB(tb4);
printf("test 4 - passed\n");
// Test only one word in the string
TB tb5 = newTB("\n");
assert(linesTB(tb5) == 1);
char *text5 = dumpTB(tb5, false);
assert(strcmp("\n", text5) == 0);
free(text5);
releaseTB(tb5);
printf("test 5 - passed\n");
// Test only one word in the string with prefix
TB tb6 = newTB("\n");
assert(linesTB(tb6) == 1);
char *text6 = dumpTB(tb6, true);
assert(strcmp("1. \n", text6) == 0);
free(text6);
releaseTB(tb6);
printf("test 6 - passed\n");
// Test continuous \n
TB tb7 = newTB("\n\n\n\njoe\n");
assert(linesTB(tb7) == 5);
char *text7 = dumpTB(tb7, false);
assert(strcmp("\n\n\n\njoe\n", text7) == 0);
free(text7);
releaseTB(tb7);
printf("test 7 - passed\n");
// Test continuous \n with prefix
TB tb8 = newTB("\n\n\n\njoe\n");
assert(linesTB(tb8) == 5);
char *text8 = dumpTB(tb8, true);
assert(strcmp("1. \n2. \n3. \n4. \n5. joe\n", text8) == 0);
free(text8);
releaseTB(tb8);
printf("test 8 - passed\n");
// Test long text with prefix
TB tb9 = newTB("\n\n\n\njoe\n\n\n\n\n\n\n");
assert(linesTB(tb9) == 11);
char *text9 = dumpTB(tb9, true);
assert(strcmp("1. \n2. \n3. \n4. \n5. joe\n6. \n7. \n8. \n9. \n10. \n11. \n", text9) == 0);
free(text9);
releaseTB(tb9);
printf("test 9 - passed\n");
printf("All newTb, linesTB, dumpTB passed!\n");
}

// TODO: Add more test functions
static void testaddPrefixTB(void) {
    printf("-----------------------------------------\n"
       "            addPrefixTB tests            \n"
       "-----------------------------------------\n");

    // normal + empty
    TB tb3 = newTB("normal\n");
    addPrefixTB(tb3, 1, 1, "");
    assert(linesTB(tb3) == 1);
    char *text3 = dumpTB(tb3, false);
    assert(strcmp("normal\n", text3) == 0);
    free(text3);
    releaseTB(tb3);
    printf("test 3 - passed\n");
   
    // normal + normal
    TB tb4 = newTB("normal string\nanother normal string\nend\n");
    addPrefixTB(tb4, 2, 3, "normal prefix with ");
    assert(linesTB(tb4) == 3);
    char *text4 = dumpTB(tb4, true);
    assert(strcmp("1. normal string\n2. normal prefix with another normal string\n3. normal prefix with end\n", text4) == 0);
    free(text4);
    releaseTB(tb4);
    printf("test 4 - passed\n");
   
    printf("all addPrefixTB passed!\n");
}

static void testmergeTB(void) {
    printf("-----------------------------------------\n"
       "              mergeTB tests              \n"
       "-----------------------------------------\n");
    // normal merge
    TB tb1 = newTB("hello there,\nhow\nare\nthings\n");
    TB tb2 = newTB("I am\njoe\n");
    mergeTB(tb1, 2, tb2);
char *text1 = dumpTB(tb1, false);
assert(linesTB(tb1) == 6);
assert(strcmp("hello there,\nI am\njoe\nhow\nare\nthings\n", text1) == 0);
free(text1);
releaseTB(tb1);
printf("test 1 - passed\n");
    // normal merge from the first
    TB tb3 = newTB("hello there,\nhow\nare\nthings\n");
    TB tb4 = newTB("I am\njoe\n");
    mergeTB(tb3, 1, tb4);
char *text2 = dumpTB(tb3, false);
assert(linesTB(tb3) == 6);
assert(strcmp("I am\njoe\nhello there,\nhow\nare\nthings\n", text2) == 0);
free(text2);
releaseTB(tb3);
printf("test 2 - passed\n");
   
    // normal merge from the second last
    TB tb5 = newTB("hello there,\nhow\nare\nthings\n!\n");
    TB tb6 = newTB("I am\njoe\n");
    mergeTB(tb5, 5, tb6);
char *text3 = dumpTB(tb5, false);
assert(linesTB(tb5) == 7);
assert(strcmp("hello there,\nhow\nare\nthings\nI am\njoe\n!\n", text3) == 0);
free(text3);
releaseTB(tb5);
printf("test 3 - passed\n");

/*   
// merge empty to normal
    TB tb7 = newTB("hello there,\nhow\nare\nthings\n");
    TB tb8 = newTB("");
    printf("******\n");
    mergeTB(tb7, 2, tb8);
char *text4 = dumpTB(tb7, false);
assert(linesTB(tb7) == 4);
assert(strcmp("hello there,\nhow\nare\nthings\n", text4) == 0);
free(text4);
releaseTB(tb7);
printf("test 4 - passed\n");
*/
/*
 merge normal to empty ??
    TB tb9 = newTB("");
    TB tb10 = newTB("hello there,\nhow\nare\nthings\n");
    mergeTB(tb9, 1, tb10);
char *text5 = dumpTB(tb9, false);
assert(linesTB(tb9) == 1);
assert(strcmp("hello there,\nhow\nare\nthings\n", text5) == 0);
free(text5);
releaseTB(tb9);
printf("test 5 - passed\n");
    // merge empty to empty
*/
}

static void testsearchTB(void) {
    printf("-----------------------------------------\n"
       "             searchTB tests              \n"
       "-----------------------------------------\n");
    // one match in the string
    TB tb1 = newTB("normal string\nanother normal string\nend\n");
    Match n1 = searchTB(tb1, "another");
    assert(n1->lineNumber == 2);
    assert(n1->columnNumber == 1);
    for (Match curr = n1; curr != NULL;) {
        Match prev = n1;
        curr = curr->next;
        free(prev);
    }
    releaseTB(tb1);
    printf("test 1 - passed\n");
   
    // multiple matches in the same line
    TB tb2 = newTB("normal string\nanother normal but normal string\n");
    Match n2 = searchTB(tb2, "normal");
    assert(n2->lineNumber == 1);
    assert(n2->columnNumber == 1);
    assert(n2->next->lineNumber == 2);
    assert(n2->next->columnNumber == 9);
    assert(n2->next->next->lineNumber == 2);
    assert(n2->next->next->columnNumber == 20);
   
    for (Match curr = n2; curr != NULL;) {
        Match prev = curr;
        curr = curr->next;
        free(prev);
    }
    releaseTB(tb2);
    printf("test 2 - passed\n");
   
    // recursion string
    TB tb3 = newTB("abracadabracadabracadabracadabra\n");
    Match n3 = searchTB(tb3, "abracadabra");
    assert(n3->lineNumber == 1);
    assert(n3->columnNumber == 1);
    assert(n3->next->lineNumber == 1);
    assert(n3->next->columnNumber == 15);
    for (Match curr = n3; curr != NULL;) {
        Match prev = curr;
        curr = curr->next;
        free(prev);
    }
    releaseTB(tb3);
    printf("test 3 - passed\n");
}

static void testpasteTB(void) {
    printf("-----------------------------------------\n"
       "              pasteTB tests              \n"
       "-----------------------------------------\n");
    // normal paste
    TB tb1 = newTB("hello there,\nhow\nare\nthings\n");
    TB tb2 = newTB("I am\njoe\n");
    pasteTB(tb1, 2, tb2);
char *text1 = dumpTB(tb1, false);
char *text2 = dumpTB(tb2, false);
assert(linesTB(tb1) == 6);
assert(strcmp("hello there,\nI am\njoe\nhow\nare\nthings\n", text1) == 0);
assert(strcmp("I am\njoe\n", text2) == 0);
free(text1);
free(text2);
releaseTB(tb1);
releaseTB(tb2);
printf("test 1 - passed\n");
    // normal paste from the second last
    TB tb5 = newTB("hello there,\nhow\nare\nthings\n!\n");
    TB tb6 = newTB("I am\njoe\n");
    pasteTB(tb5, 5, tb6);
char *text5 = dumpTB(tb5, false);
char *text6 = dumpTB(tb6, false);
assert(linesTB(tb5) == 7);
assert(strcmp("hello there,\nhow\nare\nthings\nI am\njoe\n!\n", text5) == 0);
assert(strcmp("I am\njoe\n", text6) == 0);
free(text5);
free(text6);
releaseTB(tb5);
releaseTB(tb6);
printf("test 3 - passed\n");
/*    // normal paste from the first
    TB tb3 = newTB("hello there,\nhow\nare\nthings\n");
    TB tb4 = newTB("I am\njoe\n");
    pasteTB(tb3, 1, tb4);
char *text3 = dumpTB(tb3, false);
    printf("here\n");
char *text4 = dumpTB(tb4, false);
assert(linesTB(tb3) == 6);
assert(strcmp("I am\njoe\nhello there,\nhow\nare\nthings\n", text3) == 0);
assert(strcmp("I am\njoe\n", text4) == 0);
free(text3);
free(text4);
releaseTB(tb3);
releaseTB(tb4);
printf("test 2 - passed\n");
  
    // paste empty to normal
    TB tb7 = newTB("hello there,\nhow\nare\nthings\n");
    TB tb8 = newTB("");
   
    pasteTB(tb7, 2, tb8);
char *text7 = dumpTB(tb7, false);
char *text8 = dumpTB(tb8, false);
assert(linesTB(tb7) == 4);
assert(strcmp("hello there,\nhow\nare\nthings\n", text7) == 0);
assert(strcmp("", text8) == 0);
free(text7);
free(text8);
releaseTB(tb8);
releaseTB(tb7);
printf("test 4 - passed\n");
*/
}

static void testcutTB(void) {
    printf("-----------------------------------------\n"
       "               cutTB tests               \n"
       "-----------------------------------------\n");
    // normal cut
    TB tb1 = newTB("hello there,\nhow\nare\nthings\n");
    TB cut_tb1 = cutTB(tb1, 2 , 3);
    char *cut_text1 = dumpTB(cut_tb1, true);
    char *new_text1 = dumpTB(tb1, true);
    assert(strcmp(new_text1,"1. hello there,\n2. things\n") == 0);
    assert(strcmp(cut_text1, "1. how\n2. are\n") == 0);
    free(cut_text1);
    free(new_text1);
    releaseTB(tb1);
    releaseTB(cut_tb1);
    printf("test 1 - passed\n");
   
    // cut from head to middle
    TB tb2 = newTB("hello there,\nhow\nare\nthings\n");
    TB cut_tb2 = cutTB(tb2, 1 , 2);
    char *cut_text2 = dumpTB(cut_tb2, true);
    char *new_text2 = dumpTB(tb2, true);
    assert(strcmp(new_text2,"1. are\n2. things\n") == 0);
    assert(strcmp(cut_text2, "1. hello there,\n2. how\n") == 0);
    free(cut_text2);
    free(new_text2);
    releaseTB(tb2);
    releaseTB(cut_tb2);
    printf("test 2 -passed\n");
   
    // cut from middle to tail
    TB tb3 = newTB("hello there,\nhow\nare\nthings\n");
    TB cut_tb3 = cutTB(tb3, 3 , 4);
    char *cut_text3 = dumpTB(cut_tb3, true);
    char *new_text3 = dumpTB(tb3, true);
    assert(strcmp(new_text3,"1. hello there,\n2. how\n") == 0);
    assert(strcmp(cut_text3, "1. are\n2. things\n") == 0);
    free(cut_text3);
    free(new_text3);
    releaseTB(tb3);
    releaseTB(cut_tb3);
    printf("test 3 -passed\n");
   
    // cut from head to tail
    TB tb4 = newTB("hello there,\nhow\nare\nthings\n");
    TB cut_tb4 = cutTB(tb4, 1 , 4);
    char *cut_text4 = dumpTB(cut_tb4, true);
    char *new_text4 = dumpTB(tb4, true);
    assert(strcmp(new_text4,"") == 0);
    assert(strcmp(cut_text4, "1. hello there,\n2. how\n3. are\n4. things\n") == 0);
    free(cut_text4);
    free(new_text4);
    releaseTB(tb4);
    releaseTB(cut_tb4);
    printf("test 4 -passed\n");
}

static void testdeleteTB() {
    printf("-----------------------------------------\n"
       "             deleteTB tests              \n"
       "-----------------------------------------\n");
    // normal delete
    TB tb1 = newTB("hello there,\nhow\nare\nthings\n");
    deleteTB(tb1, 2 , 3);
    char *new_text1 = dumpTB(tb1, true);
    assert(strcmp(new_text1,"1. hello there,\n2. things\n") == 0);
    free(new_text1);
    releaseTB(tb1);
    printf("test 1 - passed\n");
   
    // delete from head to middle
    TB tb2 = newTB("hello there,\nhow\nare\nthings\n");
    deleteTB(tb2, 1 , 2);
    char *new_text2 = dumpTB(tb2, true);
    assert(strcmp(new_text2,"1. are\n2. things\n") == 0);
    free(new_text2);
    releaseTB(tb2);
    printf("test 2 -passed\n");
   
    // delete from middle to tail
    TB tb3 = newTB("hello there,\nhow\nare\nthings\n");
    deleteTB(tb3, 3 , 4);
    char *new_text3 = dumpTB(tb3, true);
    assert(strcmp(new_text3,"1. hello there,\n2. how\n") == 0);
    free(new_text3);
    releaseTB(tb3);
    printf("test 3 -passed\n");
   
    // delete from head to tail
    TB tb4 = newTB("hello there,\nhow\nare\nthings\n");
    deleteTB(tb4, 1 , 4);
    char *new_text4 = dumpTB(tb4, true);
    assert(strcmp(new_text4,"") == 0);
    free(new_text4);
    releaseTB(tb4);
    printf("test 4 -passed\n");
}

static void testformRichText() {
    printf("-----------------------------------------\n"
       "           formRichText tests            \n"
       "-----------------------------------------\n");
   
    TB tb1 = newTB("*some string*\n_some string_\n#some string\n");
    formRichText(tb1);
    char *text1 = dumpTB(tb1, false);
    assert(strcmp(text1, "<b>some string</b>\n<i>some string</i>\n<h1>some string</h1>\n") == 0);
    free(text1);
    releaseTB(tb1);
    printf("test 1 - passed\n");
   
    TB tb2 = newTB("*some string\n");
    formRichText(tb2);
    char *text2 = dumpTB(tb2, false);
    assert(strcmp(text2, "*some string\n") == 0);
    free(text2);
    releaseTB(tb2);
    printf("test 2 - passed\n");
   
    TB tb3 = newTB("*some string*lol*\n");
    formRichText(tb3);
    char *text3 = dumpTB(tb3, false);
    assert(strcmp(text3, "<b>some string</b>lol*\n") == 0);
    free(text3);
    releaseTB(tb3);
    printf("test 3 - passed\n");
   
    TB tb4 = newTB("*some_string*again_\n");
    formRichText(tb4);
    char *text4 = dumpTB(tb4, false);
    assert(strcmp(text4, "<b>some_string</b>again_\n") == 0);
    free(text4);
    releaseTB(tb4);
    printf("test 4 - passed\n");
   
    TB tb5 = newTB("*some* _string_\n");
    formRichText(tb5);
    char *text5 = dumpTB(tb5, false);
    assert(strcmp(text5, "<b>some</b> <i>string</i>\n") == 0);
    free(text5);
    releaseTB(tb5);
    printf("test 5 - passed\n");
   
    TB tb6 = newTB("some *string_again_\n");
    formRichText(tb6);
    char *text6 = dumpTB(tb6, false);
    assert(strcmp(text6, "some *string<i>again</i>\n") == 0);
    free(text6);
    releaseTB(tb6);
    printf("test 6 -passed\n");
   
    TB tb7 = newTB("some#string*once_again*\n");
    formRichText(tb7);
    char *text7 = dumpTB(tb7, false);
    assert(strcmp(text7, "some#string<b>once_again</b>\n") == 0);
    free(text7);
    releaseTB(tb7);
    printf("test 7 -passed\n");
   
    TB tb8 = newTB("#string_stuff_\n");
    formRichText(tb8);
    char *text8 = dumpTB(tb8, false);
    assert(strcmp(text8, "<h1>string_stuff_</h1>\n") == 0);
    free(text8);
    releaseTB(tb8);
    printf("test 8 -passed\n");
   
    TB tb9 = newTB("#\n");
    formRichText(tb9);
    char *text9 = dumpTB(tb9, false);
    assert(strcmp(text9, "#\n") == 0);
    free(text9);
    releaseTB(tb9);
    printf("test 9 -passed\n");
   
    TB tb10 = newTB("hello ** world\n");
    formRichText(tb10);
    char *text10 = dumpTB(tb10, false);
    assert(strcmp(text10, "hello ** world\n") == 0);
    free(text10);
    releaseTB(tb10);
    printf("test 10 -passed\n");
   
    TB tb11 = newTB("hello **world*\n");
    formRichText(tb11);
    char *text11 = dumpTB(tb11, false);
    assert(strcmp(text11, "hello *<b>world</b>\n") == 0);
    free(text11);
    releaseTB(tb11);
    printf("test 11 -passed\n");
   
    TB tb12 = newTB("hello **world**\n");
    formRichText(tb12);
    char *text12 = dumpTB(tb12, false);
    assert(strcmp(text12, "hello *<b>world</b>*\n") == 0);
    free(text12);
    releaseTB(tb12);
    printf("test 12 -passed\n");
   
    TB tb13 = newTB("**hello***world**\n");
    formRichText(tb13);
    char *text13 = dumpTB(tb13, false);
    assert(strcmp(text13, "*<b>hello</b>*<b>world</b>*\n") == 0);
    free(text13);
    releaseTB(tb13);
    printf("test 13 -passed\n");
   
    TB tb14 = newTB("***hello*\n");
    formRichText(tb14);
    char *text14 = dumpTB(tb14, false);
    assert(strcmp(text14, "**<b>hello</b>\n") == 0);
    free(text14);
    releaseTB(tb14);
    printf("test 14 -passed\n");
}
