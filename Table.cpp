// Table.cpp  Table class implementation

#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>


// listFuncs.h has the definition of Node and its methods. 

#include "listFuncs.h"


Table::Table() {
	hashSize = HASH_SIZE;
	table = new ListType[HASH_SIZE]();
}


Table::Table(unsigned int hSize) {
	hashSize = hSize;
	table = new ListType[hSize]();
}


int * Table::lookup(const string &key) {
	int hCode = hashCode(key);
	return listLookup(table[hCode], key);  
}

bool Table::remove(const string &key) {
  	int hCode = hashCode(key);
  	return listRemove(table[hCode], key);
}

bool Table::insert(const string &key, int value) {
	int hCode = hashCode(key);
  	return listInsert(table[hCode], key, value);
}

int Table::numEntries() const {
	int num = 0;
	for (int i = 0; i < hashSize; i++)
	{
		num += listNumEntries(table[i]);
	}
	return num;
}


void Table::printAll() const {
	for (int i = 0; i < hashSize; i++)
	{
		listPrintAll(table[i]);
	}
	return;

}

void Table::hashStats(ostream &out) const {
	out << "number of buckets: " <<  hashSize << endl;
	out << "number of entries: " <<  numEntries() << endl;
	int numBuck = 0;
  	int longestChain = 0;
  	int length;
  	for(int i = 0;i<hashSize;i++) {
		length = listNumEntries(table[i]);
		if(length>0) {
			numBuck++;
			if(length > longestChain) {
				longestChain = length;
			}
		}
  	}
  	out << "number of non-empty buckets: " << numBuck << endl;
  	out << "longest chain: " << longestChain << endl;
}

