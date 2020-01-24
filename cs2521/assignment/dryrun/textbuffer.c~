
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "textbuffer.h"

typedef struct textbuffer {
    struct node *first;
    struct node *last;
    int numLine;
        
} textbuffer;

typedef struct node {
    struct node *prev;
    struct node *next;
    char *text;
    int line;
} Node;

// create a new textbuffer 
TB makeTB(void) {
    TB new = malloc(sizeof(struct textbuffer));   
    if (new == NULL) {
        printf("allocate fail");
        abort();
    }
       
    new->first = new->last = NULL;
    new->numLine = 0;
    return new;    
}

// create a new node include the text
Node *newNode(char *string) {
    Node *new = malloc(sizeof(struct node));
    if (new == NULL) {
        printf("allocate fail");
        abort();
    }

    new->prev = new->next = NULL;
    new->text = string;
    return new;
}

// add new node in the end of the list
void addNode(TB tb, Node *node) {
    // textbuffer is empty
    if (tb->first == NULL) {
        tb->first = tb->last = node;
    // nodes inside already
    } else {
        Node *tmp = tb->last;
        tmp->next = node;
        node->prev = tmp;
        tb->last = node;
    }
    
    tb->numLine++;
}

// free node
void freeNode(Node *node) {
    free(node->text);
    free(node);
}

// copy a whole given textbuffer into a new textbuffer
TB copyTB(TB tb) {
    TB copy = makeTB();
    Node *curr = tb->first;
    while (curr != NULL) {
        Node *newnode = newNode(curr->text);
        newnode->line = curr->line;
        addNode(copy, newnode);
        curr = curr->next;
    } 
    
    return copy;
}


// Check if one string is the substring of another
// Returns true if s1 is substring of s2 
int subcheck(char *s1, char *s2) { 
    // length of the search string
    int search = strlen(s1); 
    
    // length of each text in the node;
    int text = strlen(s2);
  
    // i is the counter for the position of substring
    int i = 0;
    while (i <= text - search) { 
        
        int j = 0; 
        while (j < search) {
            if (s2[i + j] != s1[j]) { 
                break; 
            }
            
            j++;
        }
        
        // No breaking means it's a substring,return pos
        if (j == search) { 
            return i; 
        }
        
        i++;
    } 
  
    // return -1 means s1 is not a substring of s2; 
    return -1; 
} 



/**
 * Allocate a new textbuffer whose contents is initialised with the text
 * in the given string.
 */
TB newTB(char *text) {
    // make a new textbuffer;
    TB newtb = makeTB();
    
    int i = 0; // the end of a string
    int j = 0; // the new start of next string
    int line = 1; // the position of each line
    // loop through the whole string;
    while (text[i] != '\0') {
        // find the '\n' in the string
        if (text[i] == '\n') {
            // create a string include the 'text' + '\n' + '\0'
            char *string = malloc(sizeof(char)*(i-j) + 2);
            int k = 0;
            while (j < i) {
                string[k] = text[j];
                k++;
                j++;              
            }
            
            string[k] = '\n';
            string[k+1] = '\0';
            
            // put the string in a Node, and give postion line
            Node *new = newNode(string);
            new->line = line;
            line++;
            // add the Node in the textbuffer;
            addNode(newtb, new);
            // put the start one position after the '\n' (new start)
            j = i + 1;
        }
        
        i++;
    }
    
    return newtb;
}

/**
 * Free  the  memory occupied by the given textbuffer. It is an error to
 * access the buffer afterwards.
 */
void releaseTB(TB tb) {
    if (tb == NULL) {
        fprintf(stderr,"Textbuffer is NULL.\n");
        abort();
    }
    
    // free all the nodes in the textbuffer
    Node *curr = tb->first;
    while (curr != NULL) {
        Node *tmp = curr;
        curr = curr->next;
        freeNode(tmp);
    }
    
    // free textbuffer;
    free(tb);
}

/**
 * Allocate  and return a string containing all of the text in the given
 * textbuffer. If showLineNumbers is true, add a prefix corresponding to
 * the line number.
 */
char *dumpTB(TB tb, bool showLineNumbers) {
    if (tb == NULL) {
        fprintf(stderr,"Textbuffer is NULL.\n");
        abort();
    } 
    
    char *dump = malloc(1);
    dump[0] = '\0';
    // empty string
    if (tb->first == NULL) {
        return dump;
    }
    
    Node *curr = tb->first;
    while(curr != NULL) {
        char *add = malloc(1);
        int size;
        add[0] = '\0';
        // showLineNumbers == true
        if (showLineNumbers == true) {
            // size of the #
            size = snprintf(NULL, 0, "%d. ", curr->line);
            add = realloc(add, strlen(curr->text) 
            + size + 1);                        
            // eg. 1. xxxxxx
            sprintf(add, "%d. %s", curr->line, curr->text);
            dump = realloc(dump, strlen(dump) + strlen(add) + 1);
            strcat(dump, add);
        
        // showLineNumbers == false    
        } else {
            add = realloc(add, strlen(curr->text) + 1);            
            strcat(add, curr->text);
            dump = realloc(dump, strlen(dump) + strlen(add) + 1);
            strcat (dump, add);     
        } 
        
        free(add);
        curr = curr->next;    
    }

    return dump;
}

/**
 * Return the number of lines of the given textbuffer.
 */
int linesTB(TB tb) {
    if (tb == NULL) {
        fprintf(stderr,"Textbuffer is NULL.\n");
        abort();
    } 
    
    return tb->numLine;
}

/**
 * Add a given prefix to all lines between 'from' and 'to', inclusive.
 * - The  program  should abort() wih an error message if 'from' or 'to'
 *   is out of range. The first line of a textbuffer is at position 1.
 */
void addPrefixTB(TB tb, int from, int to, char *prefix) {
    if (tb == NULL) {
        fprintf(stderr,"Textbuffer is NULL.\n");
        abort();
    } 
    // out of range
    if (from < tb->first->line || to > tb->last->line || from > to) {
        fprintf(stderr,"Out of range.\n");
        abort();
    }
    
    // textbuffer is null
    if (tb == NULL) {
        fprintf(stderr,"Textbuffer is NULL.\n");
        abort();
    } 
    
    Node *curr = tb->first;
    while (curr != NULL) {
        if (curr->line >= from && curr->line <= to) {
            char *new = malloc(1);
            new[0] = '\0';
            new = realloc(new, strlen(prefix) + strlen(curr->text) + 1);
            strcat(new, prefix);
            strcat(new, curr->text);
            char *tmp = curr->text;
            curr->text = new;
            free(tmp);
        }
        
        curr = curr->next;
    } 
}

/**
 * Merge 'tb2' into 'tb1' at line 'pos'.
 * - After this operation:
 *   - What was at line 1 of 'tb2' will now be at line 'pos' of 'tb1'.
 *   - Line  'pos' of 'tb1' will moved to line ('pos' + linesTB('tb2')),
 *     after the merged-in lines from 'tb2'.
 *   - 'tb2' can't be used anymore (as if we had used releaseTB() on it)
 * - The program should abort() with an error message if 'pos' is out of
 *   range.
 */
void mergeTB(TB tb1, int pos, TB tb2) {
    if (tb1 == NULL || tb2 == NULL) {
        fprintf(stderr,"Textbuffer is NULL.\n");
        abort();
    }
    
    if (pos < 1 || pos > tb1->last->line + 1) {
        fprintf(stderr,"Out of range.\n");
        abort();
    }
    
    // Nothing in tb2, unchanged
    if (tb2->first == NULL) {
        free(tb2);
        return;
    }
   
   //Insert tb2 before the start of tb1
    if (pos == 1) {
        Node *tmp = tb1->first;
        tb1->first = tb2->first;
        Node *curr = tb1->first;
        // while loop till the end of new tb1 (tb2);
        while (curr->next != NULL) {
            curr =curr->next; 
        }
        
        // linked tb1 in the end of tb2
        curr->next = tmp;
        
        // reset the position number of each line in the tb1;
        curr = tb1->first;
        int line = 1;
        while (curr != NULL) {
            curr->line = line;
            line++;
            curr = curr->next;
        }
        
        tb1->numLine = tb1->numLine + tb2->numLine;
        free(tb2);
        return;  
    }
    
    // Insert tb2 after the end of tb1
    if (pos == (tb1->numLine + 1)) {
        Node *curr = tb1->first;
        Node *head = tb2->first;
        while (curr->next != NULL) {
            curr = curr->next;
        }
            
        curr->next = head;
        
        // reset the position number of each line in the tb1;
        curr = tb1->first;
        int line = 1;
        while (curr != NULL) {
            curr->line = line;
            line++;
            curr = curr->next;
        }
        
        
        tb1->numLine = tb1->numLine + tb2->numLine;
        free(tb2);
        return;
    }
        
    // Insert tb1 in the middle
    Node *curr = tb1->first;
    Node *head = tb2->first;
    
    // curr will stop at one position before the line 'pos'
    while (curr->line < pos - 1) {
        curr = curr->next;
    }
    
    // back up the rest linked list start from 'pos' of tb1; 
    Node *tmp = curr->next;
    
    // link the tb2 at the 'pos' line
    curr->next = head;
    
    // loop tb2 till the end of the linked list
    while(head->next != NULL) {
        head = head->next;
    }
    
    // link the rest part of tb1 into the linked list 
    head->next = tmp;

    // reset the position number of each line in the tb1;
    curr = tb1->first;
    int line = 1;
    while (curr != NULL) {
        curr->line = line;
        line++;
        curr = curr->next;
    }
        
    tb1->numLine = tb1->numLine + tb2->numLine;
    free(tb2);
}

/**
 * Copy 'tb2' into 'tb1' at line 'pos'.
 * - After this operation:
 *   - What was at line 1 of 'tb2' will now be at line 'pos' of 'tb1'.
 *   - Line  'pos' of 'tb1' will moved to line ('pos' + linesTB('tb2')),
 *     after the pasted-in lines from 'tb2'.
 *   - 'tb2' is unmodified and remains usable independent of tb1.
 * - The program should abort() with an error message if 'pos' is out of
 *   range.
 */
void pasteTB(TB tb1, int pos, TB tb2) {
    // TB tb3 = copyTB(tb2);
    char *copy = dumpTB(tb2, false);
    TB tb3 = newTB(copy);       
    mergeTB(tb1, pos, tb3);
    free(copy);
}

/**
 * Cut  the lines between and including 'from' and 'to' out of the given
 * textbuffer 'tb' into a new textbuffer.
 * - The result is a new textbuffer (much as one created with newTB()).
 * - The cut lines will be deleted from 'tb'.
 * - The  program should abort() with an error message if 'from' or 'to'
 *   is out of range.
 */
TB cutTB(TB tb, int from, int to) {
    TB cut = makeTB();
    // textbuffer is null
    if (tb == NULL) {
        fprintf(stderr,"Textbuffer is NULL.\n");
        abort();
    } 
    // out of range
    if (from < tb->first->line || to > tb->last->line || from > to) {
        fprintf(stderr,"Out of range.\n");
        abort();
    }
    
    // before the position of 'from'
    Node *before = NULL;
    // after the position of 'to'
    Node *after = NULL;
    // node at the position of 'from'
    Node *head = NULL;
    // node at the position of 'to'
    Node *tail = NULL;
    
    Node *curr = tb->first;
    while (curr != NULL) {
        if (curr->line == from - 1) {
            before = curr;
        } else if (curr->line == from) {
            head = curr;
        } else if (curr->line == to) {
            tail = curr;
        } else if (curr->line == to + 1) {
            after = curr;
        }
               
        curr = curr->next;
    }
    
      
    // cut from middle to middle
    if (before != NULL) {
        before->next = after;
    // cut from head to middle/tail
    } else {
        tb->first = after;
    }

    // cut from middle to middle
    if (after != NULL) {
        after->prev = before;
    // cut from head/middle to tail
    } else {
        tb->last = before;
    }
    
    tb->numLine = tb->numLine - (to - from + 1);
    
    
    // the new textbuffer include the nodes have been cut from tb
    cut->first = head;
    cut->last = tail;
    cut->first->prev = cut->last->next = NULL;
    cut->numLine = to - from + 1;
    
    
    return cut;
}

/**
 * Return  a  linked list of match nodes containing the positions of all
 * of the matches of string 'search' in 'tb'.
 * - The textbuffer 'tb' should remain unmodified.
 * - The user is responsible for 
 freeing the returned list.
 */
Match searchTB(TB tb, char *search) {
    // textbuffer is null
    if (tb == NULL || tb->first == NULL) {
        return NULL; 
    } 
    
    Match head = NULL;
    Match current = NULL;
    Node *curr = tb->first;
    while (curr != NULL) {
        char *tmp = curr->text;
        // subchcheck return the position of search in tmp
        // if not in the tmp, return -1
        int sub = subcheck(search, tmp);
        if (sub != -1) {
            Match new = malloc(sizeof(struct _matchNode));
            new->lineNumber = curr->line;
            new->columnNumber = sub + 1;
            new->next= NULL;
            
            if (head == NULL) {
                head = new;
                current = head; 
            } else {
                current->next = new;
                current = current->next; 
            }
        
        }
        
        curr = curr->next;
    }        
    
    return head;
    
}

/**
 * Remove  the  lines between 'from' and 'to' (inclusive) from the given
 * textbuffer 'tb'.
 * - The  program should abort() with an error message if 'from' or 'to'
 *   is out of range.
 */
void deleteTB(TB tb, int from, int to) {
    // textbuffer is null
    if (tb == NULL) {
        fprintf(stderr,"Textbuffer is NULL.\n");
        abort();
    } 
    // out of range
    if (from < tb->first->line || to > tb->last->line || from > to) {
        fprintf(stderr,"Out of range.\n");
        abort();
    }
    
    // before the position of 'from'
    Node *before = NULL;
    // after the position of 'to'
    Node *after = NULL;
    Node *curr = tb->first;
    while (curr != NULL) {
        if (curr->line == from - 1) {
            before = curr;
        } else if (curr->line == to + 1) {
            after = curr;
        }
        
        Node *tmp = curr->next;
        // free the nodes between from and to
        if (curr->line >= from && curr->line <= to) {
            freeNode(curr);    
        }
    
        curr = tmp;
    }
    
    // cut from middle to middle
    if (before != NULL) {
        before->next = after;
    // cut from head to middle/tail
    } else {
        tb->first = after;
    }

    // cut from middle to middle
    if (after != NULL) {
        after->prev = before;
    // cut from head/middle to tail
    } else {
        tb->last = before;
    }
    
    tb->numLine = tb->numLine - (to - from + 1);
}

/**
 * Search  every  line of the given textbuffer for every occurrence of a
 * set of specified substitutions and alter them accordingly.
 * - Refer to the spec for details.
 */
void formRichText(TB tb) {

}

////////////////////////////////////////////////////////////////////////
// Bonus challenges

char *diffTB(TB tb1, TB tb2) {
	return NULL;
}

void undoTB(TB tb) {

}

void redoTB(TB tb) {

}

