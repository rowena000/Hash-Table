// listFuncs.cpp  
// Node class and listFuncs implementation

#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
  key = theKey;
  value = theValue;
  next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
  key = theKey;
  value = theValue;
  next = n;
}


//*************************************************************************
// put the function definitions for your list functions below

bool listRemove(ListType &list, string target){
	// empty list
	if ( list == NULL ) {
		return false;
	}

	// fisrt Node is the target
	if ( list -> key == target ) {
		ListType deadNode = list;
		list = list -> next;
		delete deadNode;
		return true;
	}
	
	// fisrt Node isn't the target
	ListType p1 = list;
	while ( p1 -> next != NULL) {
		ListType p2 = p1 -> next;
		if ( p2 -> key == target){
			p1 -> next = p2 -> next;
			delete p2;
			return true;
		} else {
			p1 = p2;
		}

	}
	return false;
}

bool listInsert(ListType &list, const string &theKey, int theValue){
	
	// if list is empty, add a new Node
	if ( list == NULL) {
		list = new Node (theKey, theValue);
		return true;
	}

	ListType p = list;

	// traverse the list, return false iff theKey was already present
	while ( p != NULL ) {
		if ( p->key == theKey ){
			return false;
		} 
		p = p->next;
	}
	ListType newNode = new Node (theKey, theValue);
	newNode->next = list;
	list = newNode;
	return true;
}

int *listLookup(ListType list, const string &theKey){
	if ( list == NULL ) {
		return NULL;
	}
	ListType p = list;
	while ( p != NULL ){
		if ( p->key == theKey) {
			//cout << "DEBUG: Found value: " << p->value <<endl;
			return &(p->value);
		} else {
			p = p->next;
		}
	}
	//cout << "DEBUG: Not found. "<< endl;
	return NULL;
}

void listPrintAll(ListType list) {
	if ( list == NULL ) {
		return;
	}
	ListType p = list;
	while ( p != NULL ){
		cout << p->key << " " << p->value << endl;
		p = p -> next;
	}
}

int listNumEntries(ListType list){
	
	if ( list == NULL) {
		return 0;
	}
	int num = 0;
	ListType p = list;
	while ( p != NULL) {
		num ++;
		p = p->next;
	}
	return num;

}








