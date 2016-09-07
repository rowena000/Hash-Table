
//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// used by the Table class; not by any Table client code.


#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H
  
using namespace std;

struct Node {
  string key;
  int value;

  Node *next;

  Node(const string &theKey, int theValue);

  Node(const string &theKey, int theValue, Node *n);

  
};


typedef Node * ListType;

// remove an element
// false iff element wasn't present
bool listRemove(ListType &list, string target);

// insert a new Node at the end of the list
// return false iff this key was already present 
//         (and no change made to list)
bool listInsert(ListType &list, const string &theKey, int theValue);

// returns the address of the value or NULL if key is not present
int *listLookup(ListType list, const string &theKey);

// number of entries in the table
int listNumEntries(ListType list);

// print out all the entries in the table, one per line.
// Sample output:
//   joe 32
//   sam 273
//   bob 84
void listPrintAll(ListType list) ;


#endif
