#ifndef TABLE_H
#define TABLE_H

// Table class
//    stores a collection of (string, int) entries
//    such that each key (the string) is unique
//    with efficient (O(1)) lookup, insert, and removal
//

#include <iostream>
#include <string>
#include <tr1/functional>



using namespace std;

class Node;
typedef Node * ListType;

class Table {
public:

  static const int HASH_SIZE = 9973;  // a prime number

   // create an empty table, i.e., one where numEntries() is 0
   // (Underlying hash table is HASH_SIZE.)
   Table();

   // create an empty table, i.e., one where numEntries() is 0
   // such that the underlying hash table is hSize
   Table(unsigned int hSize);

   // insert a new pair into the table
   // return false iff this key was already present 
   //         (and no change made to table)
   bool insert(const string &key, int value);

   // returns the address of the value or NULL if key is not present
   int *lookup(const string &key);

   // remove an element
   // false iff element wasn't present
   bool remove(const string &key);

   // print out all the entries in the table, one per line.
   // Sample output:
   //   joe 32
   //   sam 273
   //   bob 84
   void printAll() const;

   int numEntries() const;      // number of entries in the table

   // hashStats: for diagnostic purposes only
   // prints out info to let us know if we're getting a good distribution
   // of values in the hash table.
   // Sample output from this function
   //   number of buckets: 997
   //   number of entries: 10
   //   number of non-empty buckets: 9
   //   longest chain: 2
   void hashStats(ostream &out) const;


private:

   Table &operator =(const Table &);
   Table(const Table &);

   // hash function for a string
   // (we defined it for you)
   // returns a value in the range [0, hashSize)
  unsigned int hashCode(const string &word) const {

    return tr1::hash<string>()(word) % hashSize;
   //return std::hash<string>()(word) % hashSize;
  }

  unsigned int hashSize;      // size of the hash table
                              // (used in hashCode method above)
  ListType * table;  // a dynamic array of Node *

};

#endif

